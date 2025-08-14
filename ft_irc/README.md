# ft_irc 💬

## 📝 Descripción
ft_irc es una implementación completa de un servidor IRC (Internet Relay Chat) desarrollado en C++, que permite la comunicación en tiempo real entre múltiples clientes a través de canales y mensajes privados. Este proyecto explora los fundamentos de la programación de redes, protocolos de comunicación y arquitectura cliente-servidor.

## ✨ Características principales
- ✅ Servidor IRC completo compatible con RFC 1459
- ✅ Soporte para múltiples clientes simultáneos
- ✅ Sistema de canales con moderación
- ✅ Mensajes privados entre usuarios
- ✅ Autenticación con contraseña
- ✅ Comandos IRC estándar implementados
- ✅ Gestión de operadores de canal
- ✅ Sistema de modos de canal y usuario
- ✅ Bot IRC funcional (bonus)

## 🎯 Características bonus implementadas
- **IRC Bot**: Bot inteligente que responde a comandos específicos y proporciona funcionalidades adicionales al servidor

## 🛠️ Tecnologías utilizadas
- Lenguaje C++98
- Sockets TCP/IP
- Programación orientada a objetos
- Protocolos de red (IRC RFC 1459)
- Multiplexing con select/poll
- Parsing de comandos IRC
- Makefile para compilación
- Git para control de versiones

## 📋 Requisitos previos
- Sistema operativo Unix/Linux o macOS
- Compilador G++ con soporte C++98
- Make
- Cliente IRC compatible (irssi, HexChat, etc.)
- Conocimientos básicos de redes TCP/IP

## ⚙️ Compilación y uso
```bash
# Compilar el servidor
make

# Compilar el bot (bonus)
make bonus

# Limpiar archivos objeto
make clean

# Limpiar todos los archivos generados
make fclean

# Recompilar
make re

# Ejecutar el servidor IRC
./ircserv <puerto> <contraseña>

# Ejecutar el bot (desde la carpeta bonus_irc)
cd bonus_irc && ./bot
```

## 🌐 Conexión al servidor
```bash
# Usando un cliente IRC (ejemplo con nc)
nc localhost <puerto>

# Comandos de conexión
PASS <contraseña>
NICK <nickname>
USER <username> 0 * :<realname>
```

## 📡 Comandos IRC implementados

### Comandos de autenticación
- **PASS**: Establecer contraseña del servidor
- **NICK**: Establecer/cambiar nickname
- **USER**: Registrar información de usuario
- **QUIT**: Desconectar del servidor

### Comandos de canal
- **JOIN**: Unirse a un canal
- **PART**: Salir de un canal
- **PRIVMSG**: Enviar mensaje a canal o usuario
- **KICK**: Expulsar usuario del canal (operador)
- **INVITE**: Invitar usuario a canal
- **TOPIC**: Ver/cambiar tema del canal

### Comandos de modo
- **MODE**: Gestionar modos de canal y usuario
  - `+i`: Canal solo por invitación
  - `+t`: Solo operadores pueden cambiar topic
  - `+k`: Canal con contraseña
  - `+o`: Otorgar privilegios de operador
  - `+l`: Límite de usuarios en canal

## 🤖 Bot IRC (Bonus)
El bot incluye funcionalidades como:
- Respuestas automáticas a comandos específicos
- Moderación básica de canales
- Comandos de utilidad para usuarios
- Integración transparente con el servidor

## 🏗️ Arquitectura del servidor

### Componentes principales
```cpp
class Server {
    // Gestión de conexiones y sockets
    // Multiplexing con select/poll
    // Distribución de mensajes
};

class Client {
    // Información de usuario
    // Estado de autenticación
    // Canales suscritos
};

class Channel {
    // Lista de miembros
    // Modos del canal
    // Topic y configuración
};
```

### Flujo de datos
1. **Conexión**: Cliente se conecta al socket del servidor
2. **Autenticación**: PASS, NICK, USER
3. **Comandos**: Parsing y ejecución de comandos IRC
4. **Distribución**: Envío de mensajes a destinatarios
5. **Desconexión**: Limpieza y notificación

## 🔧 Funciones implementadas
- **Parser de comandos**: Análisis de mensajes IRC según RFC
- **Gestión de sockets**: Conexiones no bloqueantes con select/poll
- **Sistema de canales**: Creación, moderación y gestión
- **Autenticación**: Validación de usuarios y contraseñas
- **Modos IRC**: Implementación de modos estándar
- **Gestión de memoria**: Limpieza automática de recursos
- **Logging**: Sistema de logs para debugging

## 🌐 Protocolo IRC implementado
Basado en RFC 1459:
```
:<prefix> <command> <params> :<trailing>

Ejemplos:
:nick!user@host PRIVMSG #channel :Hello world
:server 001 nick :Welcome to the IRC Network
```

## 🧪 Testing
El proyecto ha sido probado con:
- Múltiples clientes IRC estándar (irssi, HexChat)
- Conexiones simultáneas masivas
- Comandos malformados y casos límite
- Gestión de memoria con valgrind
- Compatibilidad con clientes reales
- Funcionalidad del bot en diferentes escenarios
- Modos de canal complejos

## 🎯 Ejemplos de uso
```bash
# Iniciar servidor en puerto 6667
./ircserv 6667 password123

# Conectar con irssi
irssi -c localhost -p 6667 -w password123

# Comandos básicos en el cliente
/join #general
/msg #general Hello everyone!
/mode #general +t
/kick annoying_user
```

## 🔍 Casos de uso comunes
```bash
# Crear canal privado
/join #private
/mode #private +i +k secret123

# Dar privilegios de operador
/mode #channel +o username

# Bot commands (si está activo)
!help
!hello
!info
!quit
```

## ⚠️ Aviso
Este proyecto forma parte del currículum de 42. Si eres estudiante de 42, te animo a desarrollar tus propias soluciones.

<div align="center">
    <p>Desarrollado con ❤️ como parte del currículum de 42</p>
    <br>
    <img src="https://img.shields.io/badge/C++-00599C?style=for-the-badge&logo=cplusplus&logoColor=white" alt="C++"/>
    <img src="https://img.shields.io/badge/IRC-Protocol-purple?style=for-the-badge&logo=irc&logoColor=white" alt="IRC"/>
    <img src="https://img.shields.io/badge/Networking-TCP/IP-blue?style=for-the-badge&logo=cisco&logoColor=white" alt="Networking"/>
    <img src="https://img.shields.io/badge/Bot-Implemented-gold?style=for-the-badge&logo=robot&logoColor=white" alt="Bot"/>
    <img src="https://img.shields.io/badge/Norminette-42-00babc?style=for-the-badge&logo=42&logoColor=white" alt="Norminette"/>
</div>
