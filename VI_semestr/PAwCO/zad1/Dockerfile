# Dockerfile jest podzielony na dwa etapy bo jest to wspomniane w instrukcji,
# nie jest to konieczne. W teorii mozna zrobić w jednym etapie i zastosować
# inne polecenie pip które również nie pozostawiłoby zbędnych plików.

# Etap 1: Budowanie
FROM python:3.12-slim AS builder

# Kopiowanie pliku z zależnościami i instalacja zależności
WORKDIR /app
COPY requirements.txt .
# --user instaluje do katalagou /root/.local z którego potem pliki są kopiowane na drugi etap
RUN pip install --user -r requirements.txt


# Etap 2: Uruchomienie
FROM python:3.12-slim

# Oznaczenie autora
LABEL org.opencontainers.image.authors="Jan Kowalski"

# Dodanie to $PATH ścieżki do miejsca instalacji pip --user
ENV PATH=/root/.local/bin:$PATH
WORKDIR /app
# Kopiowanie zależności z poprzedniego etapu
COPY --from=builder /root/.local /root/.local

# Kopiowanie plików źródłowych
COPY app.py .
COPY static/ ./static/

# Otwieranie portu
EXPOSE 5000

# Healthcheck, po 10 sekundach od uruchomienia kontenera,
# co 30 sekund sprawdza czy aplikacja działa,
# jeśli nie otrzyma odpowiedzi w 5 sekund to kończy kontener z kodem 1
HEALTHCHECK --interval=30s --timeout=5s --start-period=10s CMD curl -f http://localhost:5000/ || exit 1

# Uruchomienie aplikacji
CMD ["python", "app.py"]
