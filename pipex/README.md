# Pipex 🔄

## 📝 Descripción
Pipex es una implementación en C que simula el comportamiento de tuberías (pipes) en sistemas Unix. El programa permite la ejecución de comandos en secuencia, redirigiendo la salida de un comando como entrada del siguiente, similar al operador '|' en shells Unix.

## ✨ Características principales
- ✅ Simulación de tuberías Unix
- ✅ Ejecución de comandos secuenciales
- ✅ Redirección de entrada/salida
- ✅ Gestión de procesos hijos
- ✅ Manejo de errores robusto
- ✅ Soporte para múltiples comandos (bonus)

## 🛠️ Tecnologías utilizadas
- Lenguaje C
- Funciones del sistema Unix
- Makefile para compilación
- Git para control de versiones
- Norminette para estilo de código

## 📋 Requisitos previos
- Sistema operativo Unix/Linux
- GCC compiler
- Make
- Shell de comando (bash)

## ⚙️ Compilación y uso
```bash
# Compilar el programa
make

# Compilar con bonus
make bonus

# Limpiar archivos objeto
make clean

# Limpiar todos los archivos generados
make fclean

# Recompilar
make re
```

## 🔍 Ejemplo de uso
```bash
# Uso básico
./pipex infile "ls -l" "wc -l" outfile

# Equivalente en shell
< infile ls -l | wc -l > outfile
```

## 📚 Funciones implementadas
- Manejo de procesos:
  - fork(): Creación de procesos hijos
  - pipe(): Creación de tuberías
  - execve(): Ejecución de comandos
  - wait(): Sincronización de procesos
- Redirección de E/S:
  - dup2(): Duplicación de descriptores
  - open(): Apertura de archivos
  - close(): Cierre de descriptores
- Gestión de errores y memoria

## 🧪 Testing
El proyecto ha sido probado con:
- Diferentes combinaciones de comandos
- Archivos de entrada/salida variados
- Casos de error (archivos inexistentes, permisos)
- Pruebas de memoria (valgrind)
- Comprobación de fugas de memoria

## ⚠️ Aviso
Este proyecto forma parte del currículum de 42. Si eres estudiante de 42, te animo a desarrollar tus propias soluciones.

<div align="center">
    <p>Desarrollado con ❤️ como parte del currículum de 42</p>
    <br>
    <img src="https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white" alt="C"/>
    <img src="https://img.shields.io/badge/Shell-121011?style=for-the-badge&logo=gnu-bash&logoColor=white" alt="Shell"/>
    <img src="https://img.shields.io/badge/norminette-42-white?style=for-the-badge" alt="Norminette"/>
</div>
