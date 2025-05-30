name: Build and Push Docker Image

on:
  push:
    branches:
      - main
  pull_request:

jobs:
  build-and-push:
    name: Build and Push Docker Image
    runs-on: ubuntu-latest

    permissions:
      contents: read
      packages: write

    steps:
   
      - name: Checkout code
        uses: actions/checkout@v3

      - name: Log in to DockerHub
        uses: docker/login-action@v2
        with:
          username: ${{ secrets.DOCKERHUB_USERNAME }}
          password: ${{ secrets.DOCKERHUB_TOKEN }}

      - name: Log in to GitHub Container Registry
        uses: docker/login-action@v2
        with:
          registry: ghcr.io
          username: ${{ github.actor }}
          password: ${{ secrets.GHCR_TOKEN }}

      - name: Set up QEMU
        uses: docker/setup-qemu-action@v2
        with:
          platforms: linux/amd64,linux/arm64

      - name: Set up Docker Buildx
        uses: docker/setup-buildx-action@v2

      - name: Build and Push Docker Image
        uses: docker/build-push-action@v5
        with:
          context: .
          file: ./Dockerfile
          platforms: linux/amd64,linux/arm64
          push: true
          tags: |
            ghcr.io/nyctovir/pawco2:latest
            ghcr.io/nyctovir/pawco2:${{ github.sha }}
          cache-from: type=registry,ref=docker.io/${{ secrets.DOCKERHUB_USERNAME }}/cache:latest
          cache-to: type=registry,ref=docker.io/${{ secrets.DOCKERHUB_USERNAME }}/cache:latest,mode=max

  scan:
    name: Scan Docker Image for CVEs
    runs-on: ubuntu-latest
    needs: build-and-push

    steps:
      - name: Log in to GitHub Container Registry
        uses: docker/login-action@v2
        with:
          registry: ghcr.io
          username: ${{ github.actor }}
          password: ${{ secrets.GHCR_TOKEN }}

      - name: Pull Docker Image
        run: docker pull ghcr.io/nyctovir/pawco2:latest

      - name: Scan Docker Image for CVEs
        uses: aquasecurity/trivy-action@0.30.0
        with:
          image-ref: ghcr.io/nyctovir/pawco2:latest
          severity: CRITICAL,HIGH
          ignore-unfixed: true
          
      - name: Check scan results
        run: |
          if grep -q "CRITICAL\|HIGH" trivy-results.txt; then
            echo "Critical or high vulnerabilities found. Failing the job."
            exit 1
          fi
