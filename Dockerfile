FROM ubuntu:24.04

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update && apt-get install -y \
    build-essential \
    libx11-dev \
    libxext-dev \
    libbsd-dev \
    libxi-dev \
    libgl1-mesa-dev \
    x11-apps \
    git \
    cmake \
    pkg-config \
    libxrandr-dev \
    libxinerama-dev \
    libxcursor-dev \
    libxrender-dev \
    && apt-get clean

# Crear usuario antes de chown
RUN useradd -ms /bin/bash devuser

WORKDIR /home/devuser/app

# Cambiar propiedad (en caso se copie contenido)
RUN chown -R devuser:devuser /home/devuser/app

USER devuser

CMD ["/bin/bash"]

