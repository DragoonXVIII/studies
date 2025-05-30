# Multi-Architecture Docker Build and Push

## Prerequisites
- Docker Desktop with BuildKit enabled
- DockerHub account
- Existing Dockerfile

## Steps

### 1. Create a new builder instance
```bash
docker buildx create --name multiarch --use
```

### 2. Build for multiple architectures
```bash
docker buildx build --platform linux/amd64,linux/arm64 -t your-username/your-image:tag --push .
```
**Important:** Replace `your-username/your-image:tag` with your actual values:
- `your-username`: Your DockerHub username
- `your-image`: Your desired image name
- `tag`: Your desired tag (e.g., `latest`, `v1.0`, etc.)

Example:
```bash
docker buildx build --platform linux/amd64,linux/arm64 -t johndoe/myapp:latest --push .
```

### 3. Verify the build
```bash
docker buildx imagetools inspect your-username/your-image:tag
```

## Notes
- Replace `your-username/your-image:tag` with your actual DockerHub repository
- Ensure you're logged in to DockerHub: `docker login`
- The `--push` flag uploads directly to the registry


## GitHub Actions Pipeline for Multi-Architecture Build

### Pipeline Configuration

Create `.github/workflows/docker-build.yml`:

```yaml
name: Build and Push Multi-Architecture Docker Image

on:
    push:
        branches: [ main, develop ]
        tags: [ 'v*' ]
    pull_request:
        branches: [ main ]

env:
    REGISTRY: ghcr.io
    IMAGE_NAME: ${{ github.repository }}
    DOCKERHUB_CACHE_REPO: dragoonxviii/cache

jobs:
    build-and-push:
        runs-on: ubuntu-latest
        permissions:
            contents: read
            packages: write
            security-events: write

        steps:
        - name: Checkout
            uses: actions/checkout@v4

        - name: Set up Docker Buildx
            uses: docker/setup-buildx-action@v3

        - name: Log in to GitHub Container Registry
            uses: docker/login-action@v3
            with:
                registry: ${{ env.REGISTRY }}
                username: ${{ github.actor }}
                password: ${{ secrets.GITHUB_TOKEN }}

        - name: Log in to DockerHub (for cache)
            uses: docker/login-action@v3
            with:
                username: ${{ secrets.DOCKERHUB_USERNAME }}
                password: ${{ secrets.DOCKERHUB_TOKEN }}

        - name: Extract metadata
            id: meta
            uses: docker/metadata-action@v5
            with:
                images: ${{ env.REGISTRY }}/${{ env.IMAGE_NAME }}
                tags: |
                    type=ref,event=branch
                    type=ref,event=pr
                    type=semver,pattern={{version}}
                    type=semver,pattern={{major}}.{{minor}}
                    type=sha,prefix={{branch}}-

        - name: Build and push
            uses: docker/build-push-action@v5
            with:
                context: .
                platforms: linux/amd64,linux/arm64
                push: true
                tags: ${{ steps.meta.outputs.tags }}
                labels: ${{ steps.meta.outputs.labels }}
                cache-from: type=registry,ref=${{ env.DOCKERHUB_CACHE_REPO }}:cache
                cache-to: type=registry,ref=${{ env.DOCKERHUB_CACHE_REPO }}:cache,mode=max

        - name: Run CVE scan
            uses: aquasecurity/trivy-action@master
            with:
                image-ref: ${{ env.REGISTRY }}/${{ env.IMAGE_NAME }}:${{ steps.meta.outputs.version }}
                format: 'sarif'
                output: 'trivy-results.sarif'
                severity: 'CRITICAL,HIGH'
                exit-code: '1'

        - name: Upload Trivy scan results
            uses: github/codeql-action/upload-sarif@v2
            if: always()
            with:
                sarif_file: 'trivy-results.sarif'
```

### Required Secrets

Configure in GitHub repository settings:
- `DOCKERHUB_USERNAME`: Your DockerHub username
- `DOCKERHUB_TOKEN`: DockerHub access token

### Tagging Strategy

**Image Tags:**
- `main` branch → `latest` + `main`
- `develop` branch → `develop`
- Version tags (`v1.0.0`) → `1.0.0` + `1.0` + `v1.0.0`
- Pull requests → `pr-<number>`
- Commits → `<branch>-<sha>`

**Cache Tags:**
- Single cache tag `cache` with `mode=max` for optimal layer reuse across architectures

### Security Considerations

- CVE scanning with Trivy blocks deployment of images with CRITICAL/HIGH vulnerabilities
- Registry cache stored in public DockerHub repository (separate from main images)
- SARIF results uploaded to GitHub Security tab for vulnerability tracking

This approach ensures efficient multi-architecture builds while maintaining security standards and optimal cache utilization.