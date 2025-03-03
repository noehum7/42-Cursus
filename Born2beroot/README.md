# Born2beroot 🖥️

## 📝 Descripción
Born2beroot es un proyecto de administración de sistemas que consiste en la creación y configuración de un servidor virtual basado en Linux. El proyecto se centra en la implementación de políticas de seguridad estrictas y la gestión eficiente de servicios del sistema.

## ✨ Características principales
- ✅ Instalación y configuración de Debian/CentOS
- ✅ Implementación de política de contraseñas robusta
- ✅ Configuración de sudo con reglas estrictas
- ✅ Configuración de UFW (Uncomplicated Firewall)
- ✅ Implementación de SSH con puerto personalizado
- ✅ Creación de script de monitorización del sistema
- ✅ Gestión de usuarios y grupos
- ✅ Configuración de particiones con LVM

## 🛠️ Tecnologías utilizadas
- Sistema operativo Debian/CentOS
- Virtualización con VirtualBox
- Shell scripting (Bash)
- Servicios: SSH, UFW, sudo
- LVM para gestión de particiones

## 📋 Requisitos previos
- Oracle VirtualBox o software de virtualización similar
- Imagen ISO de Debian/CentOS
- Mínimo 8GB de espacio en disco
- 1GB+ de RAM disponible

## 🔧 Configuración del sistema
1. Instalación del sistema operativo
2. Configuración de particiones con LVM
3. Instalación de paquetes necesarios
4. Configuración de usuarios y grupos
5. Implementación de políticas de seguridad
6. Configuración de servicios (SSH, UFW)
7. Implementación del script de monitorización

## 📊 Script de monitorización
El script muestra información del sistema cada 10 minutos:
- Arquitectura del sistema operativo
- Núcleos físicos y virtuales
- Memoria RAM disponible y en uso
- Espacio en disco disponible y en uso
- Porcentaje de uso de CPU
- Última fecha de reinicio
- Estado de conexiones LVM
- Conexiones TCP activas
- Usuarios activos en el sistema
- Red (dirección IP y MAC)
- Número de comandos ejecutados con sudo

## 🔐 Medidas de seguridad implementadas
- Política de contraseñas robusta
- Acceso root limitado
- Configuración específica de sudo
- Puerto SSH personalizado
- Firewall activo y configurado
- Actualizaciones automáticas

## 📚 Documentación adicional
- [Guía de instalación de Debian](https://www.debian.org/doc/)
- [Manual de UFW](https://help.ubuntu.com/community/UFW)
- [Documentación de SSH](https://www.ssh.com/academy/ssh/protocol)

## ⚠️ Aviso
Este proyecto forma parte del currículum de 42. Si eres estudiante de 42, te animo a desarrollar tus propias soluciones.

<div align="center">
    <p>Desarrollado con ❤️ como parte del currículum de 42</p>
    <br>
    <img src="https://img.shields.io/badge/Debian-A81D33?style=for-the-badge&logo=debian&logoColor=white" alt="Debian"/>
    <img src="https://img.shields.io/badge/Shell_Script-121011?style=for-the-badge&logo=gnu-bash&logoColor=white" alt="Shell"/>
    <img src="https://img.shields.io/badge/VirtualBox-183A61?style=for-the-badge&logo=virtualbox&logoColor=white" alt="VirtualBox"/>
</div>
