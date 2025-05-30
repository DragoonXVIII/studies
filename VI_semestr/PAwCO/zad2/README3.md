# Sprawozdanie - Konfiguracja GitHub Actions do budowy i publikacji obrazu Docker

## Opis zadania
Celem zadania było opracowanie łańcucha CI/CD w usłudze GitHub Actions, który:
1. Buduje obraz kontenera na podstawie pliku `Dockerfile` oraz kodów źródłowych aplikacji.
2. Wspiera dwie architektury: `linux/amd64` oraz `linux/arm64`.
3. Wykorzystuje cache do optymalizacji procesu budowania obrazu.
4. Przeprowadza skanowanie obrazu pod kątem podatności (CVE) i przesyła go do publicznego repozytorium na **GitHub Container Registry (GHCR)** tylko wtedy, gdy nie zawiera krytycznych lub wysokich podatności.

---

## Konfiguracja i realizacja

### 1. Przygotowanie repozytorium
- Repozytorium zostało utworzone na GitHub i zawiera:
  - Plik `Dockerfile` definiujący obraz kontenera.
  - Plik `.github/workflows/docker-build.yml` z konfiguracją GitHub Actions.
  - Kod źródłowy aplikacji.

### 2. Konfiguracja GitHub Actions
W pliku `.github/workflows/docker-build.yml` skonfigurowano dwa główne zadania:
1. **Build and Push Docker Image**:
   - Buduje obraz Docker z wykorzystaniem `docker/build-push-action`.
   - Wspiera architektury `linux/amd64` oraz `linux/arm64` dzięki `docker/setup-qemu-action`.
   - Wykorzystuje cache z publicznego repozytorium na DockerHub, aby przyspieszyć proces budowania.
   - Publikuje obraz do **GitHub Container Registry (GHCR)** pod tagami:
     - `latest` (najnowsza wersja obrazu).
     - Commit SHA (unikalny identyfikator wersji obrazu).

2. **Scan Docker Image for CVEs**:
   - Pobiera zbudowany obraz z GHCR.
   - Skanuje obraz pod kątem podatności (CVE) za pomocą narzędzia **Trivy**.
   - W przypadku wykrycia krytycznych lub wysokich podatności proces zostaje przerwany.

### 3. Cache
- Cache został skonfigurowany z wykorzystaniem `docker/build-push-action`:
  - Dane cache są przechowywane w publicznym repozytorium na DockerHub.
  - Eksporter cache działa w trybie `max`, co zapewnia maksymalne wykorzystanie danych cache.

### 4. Publiczny dostęp do obrazu
- Obraz został opublikowany w **GitHub Container Registry (GHCR)**.
- Ustawiono widoczność obrazu jako publiczną, aby umożliwić jego pobieranie bez autoryzacji.

---

## Kroki realizacji

1. **Budowa i publikacja obrazu**:
   - Po wykonaniu push do gałęzi `main`, GitHub Actions automatycznie uruchamia proces budowy obrazu.
   - Obraz jest publikowany w GHCR pod adresem:
     ```
     ghcr.io/nyctovir/pawco2:latest
     ```

2. **Skanowanie obrazu**:
   - Po zbudowaniu obrazu, narzędzie Trivy skanuje go pod kątem podatności.
   - Jeśli nie wykryto krytycznych lub wysokich podatności, obraz zostaje opublikowany.

3. **Testowanie**:
   - Łańcuch został uruchomiony i przetestowany. Obraz został poprawnie zbudowany, przesłany do GHCR i przeszedł skanowanie CVE.

---

## Jak uruchomić pipeline?

1. **Klonowanie repozytorium**:
   ```bash
   git clone https://github.com/nyctovir/pawco.git
   cd pawco
   ```

2. **Wykonanie push**:
Po wykonaniu push, pipeline zostanie automatycznie uruchomiony.

3. **Pobranie obrazu Docker:**:
   ```bash
   docker pull ghcr.io/nyctovir/pawco2:latest
   ```
   