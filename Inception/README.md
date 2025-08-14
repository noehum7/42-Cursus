# Inception 🐳

## 📝 Descripción
Inception es un proyecto de administración de sistemas que implica la virtualización de varias imágenes de Docker dentro de una máquina virtual personal. El objetivo es crear una infraestructura completa usando Docker Compose para orquestar múltiples servicios containerizados que trabajen en conjunto, implementando buenas prácticas de DevOps y administración de sistemas.

## ✨ Características principales
- ✅ Infraestructura completa con Docker Compose
- ✅ Servidor web NGINX con TLS v1.2/v1.3
- ✅ Base de datos MariaDB
- ✅ WordPress con PHP-FPM
- ✅ Volúmenes persistentes para datos
- ✅ Red personalizada de Docker
- ✅ Variables de entorno para configuración
- ✅ Imágenes Docker personalizadas (no oficiales)
- ✅ Configuración automatizada con scripts

## 🏗️ Arquitectura del sistema
```
┌─────────────────┐    ┌─────────────────┐    ┌─────────────────┐
│     NGINX       │    │   WordPress     │    │    MariaDB      │
│   (Servidor     │────│   (PHP-FPM)     │────│   (Base de      │
│    Web + SSL)   │    │                 │    │    Datos)       │
└─────────────────┘    └─────────────────┘    └─────────────────┘
         │                       │                       │
         └───────────────────────┼───────────────────────┘
                                 │
                         ┌───────────────┐
                         │  Docker       │
                         │  Network      │
                         └───────────────┘
```

## 🛠️ Tecnologías utilizadas
- Docker y Docker Compose
- NGINX como servidor web
- WordPress con PHP-FPM
- MariaDB como base de datos
- OpenSSL para certificados SSL/TLS
- Shell scripting para automatización
- Debian/Alpine Linux como base
- Makefile para gestión del proyecto

## 📋 Requisitos previos
- Máquina virtual (VirtualBox, VMware, etc.)
- Docker Engine instalado
- Docker Compose instalado
- Make
- Sistema operativo Unix/Linux
- Al menos 2GB de RAM disponible

## ⚙️ Compilación y uso
```bash
# Construir e iniciar toda la infraestructura
make

# Parar todos los servicios
make down

# Limpiar contenedores y volúmenes
make clean

# Limpieza completa (incluye imágenes)
make fclean

# Reconstruir desde cero
make re

# Ver logs de los servicios
make logs

# Ver estado de los contenedores
make status
```

## 🐳 Servicios implementados

### NGINX (Servidor Web)
- **Puerto**: 443 (HTTPS)
- **Características**:
  - Certificado SSL/TLS autofirmado
  - Configuración personalizada
  - Proxy reverso para WordPress
  - Compresión gzip habilitada

### WordPress (CMS)
- **Puerto**: 9000 (interno)
- **Características**:
  - PHP-FPM para procesamiento
  - Conexión con MariaDB
  - Configuración automática
  - Volúmenes persistentes

### MariaDB (Base de Datos)
- **Puerto**: 3306 (interno)
- **Características**:
  - Base de datos para WordPress
  - Usuario y contraseñas configurables
  - Datos persistentes en volumen
  - Inicialización automática

## 📁 Estructura del proyecto
```
Inception/
├── Makefile
└── srcs/
    ├── docker-compose.yml      # Orquestación de servicios
    ├── requirements/
    │   ├── nginx/
    │   │   ├── Dockerfile      # Imagen personalizada NGINX
    │   │   ├── conf/nginx.conf # Configuración NGINX
    │   │   └── tools/          # Scripts de configuración
    │   ├── wordpress/
    │   │   ├── Dockerfile      # Imagen personalizada WordPress
    │   │   └── tools/          # Scripts de instalación
    │   └── mariadb/
    │       ├── Dockerfile      # Imagen personalizada MariaDB
    │       └── tools/          # Scripts de base de datos
    └── tools/
        └── init-config.sh      # Script de inicialización global
```

## 🔐 Configuración de seguridad
- **SSL/TLS**: Certificados para comunicación segura
- **Variables de entorno**: Credenciales no hardcodeadas
- **Usuarios no privilegiados**: Contenedores sin root
- **Red aislada**: Comunicación interna segura
- **Volúmenes**: Datos persistentes y seguros

## 📝 Variables de entorno
Configurables en archivo `.env`:
```bash
# MariaDB
MYSQL_ROOT_PASSWORD=strongpassword
MYSQL_DATABASE=wordpress
MYSQL_USER=wpuser
MYSQL_PASSWORD=wppassword

# WordPress
WP_ADMIN_USER=admin
WP_ADMIN_PASSWORD=adminpass
WP_ADMIN_EMAIL=admin@example.com
WP_TITLE="My WordPress Site"

# Dominio
DOMAIN_NAME=login.42.fr
```

## 🌐 Acceso a los servicios
```bash
# Acceso web (HTTPS)
https://login.42.fr

# Verificar certificado SSL
openssl s_client -connect login.42.fr:443

# Acceso a logs
docker-compose -f srcs/docker-compose.yml logs -f [servicio]
```

## 🛠️ Scripts de configuración

### init_mariadb.sh
- Inicialización de la base de datos
- Creación de usuario WordPress
- Configuración de permisos

### wordpress-config.sh
- Descarga e instalación de WordPress
- Configuración de wp-config.php
- Conexión con base de datos

### nginx-config.sh
- Generación de certificados SSL
- Configuración de virtual hosts
- Optimizaciones de rendimiento

## 🔧 Comandos útiles
```bash
# Inspeccionar volúmenes
docker volume ls
docker volume inspect inception_wordpress
docker volume inspect inception_mariadb

# Acceder a contenedores
docker exec -it nginx bash
docker exec -it wordpress bash
docker exec -it mariadb bash

# Ver redes Docker
docker network ls
docker network inspect inception_network
```

## 🧪 Testing y validación
```bash
# Verificar que todos los servicios están corriendo
docker-compose -f srcs/docker-compose.yml ps

# Test de conectividad
curl -k https://login.42.fr

# Verificar base de datos
docker exec -it mariadb mysql -u root -p

# Verificar logs sin errores
docker-compose -f srcs/docker-compose.yml logs
```

## 🐛 Troubleshooting
```bash
# Verificar puertos en uso
netstat -tlnp | grep :443

# Limpiar todo y reiniciar
make fclean && make

# Verificar espacio en disco
df -h
docker system df

# Ver recursos de contenedores
docker stats
```

## 📊 Monitoreo
```bash
# Estado de servicios
make status

# Logs en tiempo real
make logs

# Uso de recursos
docker stats inception_nginx inception_wordpress inception_mariadb
```

## ⚠️ Aviso
Este proyecto forma parte del currículum de 42. Si eres estudiante de 42, te animo a desarrollar tus propias soluciones.

<div align="center">
    <p>Desarrollado con ❤️ como parte del currículum de 42</p>
    <br>
    <img src="https://img.shields.io/badge/Docker-2496ED?style=for-the-badge&logo=docker&logoColor=white" alt="Docker"/>
    <img src="https://img.shields.io/badge/NGINX-009639?style=for-the-badge&logo=nginx&logoColor=white" alt="NGINX"/>
    <img src="https://img.shields.io/badge/WordPress-21759B?style=for-the-badge&logo=wordpress&logoColor=white" alt="WordPress"/>
    <img src="https://img.shields.io/badge/MariaDB-003545?style=for-the-badge&logo=mariadb&logoColor=white" alt="MariaDB"/>
    <img src="https://img.shields.io/badge/SSL/TLS-Secure-green?style=for-the-badge&logo=letsencrypt&logoColor=white" alt="SSL"/>
</div>
