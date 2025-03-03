# Get Next Line 📜

## 📝 Descripción
Get Next Line (GNL) es una función en C que lee y retorna líneas completas desde un descriptor de archivo. El proyecto se centra en la gestión eficiente de memoria y la manipulación de archivos, permitiendo leer desde múltiples descriptores de archivo simultáneamente.

## ✨ Características principales
- ✅ Lectura línea por línea desde archivos
- ✅ Gestión de múltiples descriptores de archivo
- ✅ Manejo eficiente de memoria dinámica
- ✅ Soporte para diferentes tamaños de buffer
- ✅ Gestión de EOF (End of File)
- ✅ Manejo de errores robusto

## 🛠️ Tecnologías utilizadas
- Lenguaje C
- Makefile para compilación
- Git para control de versiones
- Norminette para estilo de código

## 📋 Requisitos previos
- GCC compiler
- Make
- Biblioteca C estándar
- Norminette (para verificar el estilo de código)

## ⚙️ Compilación y uso
```bash
# Compilar la biblioteca
make

# Compilar con bonus (si están implementados)
make bonus

# Limpiar archivos objeto
make clean

# Limpiar todos los archivos generados
make fclean

# Recompilar
make re
```

## 🔍 Ejemplos de uso
```c
#include "get_next_line.h"

int main(void)
{
    int     fd;
    char    *line;

    fd = open("ejemplo.txt", O_RDONLY);
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}
```

## 📚 Funciones implementadas
- `get_next_line`: Función principal que lee y retorna una línea
- `ft_strlen`: Calcula la longitud de una cadena
- `ft_strchr`: Busca un carácter en una cadena
- `ft_strjoin`: Une dos cadenas
- `ft_substr`: Extrae una subcadena
- Funciones auxiliares para la gestión de memoria

## 🧪 Testing
El proyecto ha sido probado con:
- Diferentes tamaños de BUFFER_SIZE
- Múltiples descriptores de archivo
- Archivos de diversos tamaños
- Casos límite y errores
- Pruebas de fugas de memoria

## ⚠️ Aviso
Este proyecto forma parte del currículum de 42. Si eres estudiante de 42, te animo a desarrollar tus propias soluciones.

<div align="center">
    <p>Desarrollado con ❤️ como parte del currículum de 42</p>
    <br>
    <img src="https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white" alt="C"/>
    <img src="https://img.shields.io/badge/Makefile-003366?style=for-the-badge&logo=gnu&logoColor=white" alt="Makefile"/>
    <img src="https://img.shields.io/badge/norminette-42-white?style=for-the-badge" alt="Norminette"/>
</div>
