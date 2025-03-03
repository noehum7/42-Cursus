# ft_printf 🖨️

## 📝 Descripción
Reimplementación de la función printf de la biblioteca estándar de C. Este proyecto se centra en el manejo de formato de salida, gestión de parámetros variables y conversión de tipos, proporcionando una comprensión profunda de la manipulación de cadenas y la salida formateada en C.

## ✨ Características principales
- ✅ Manejo de conversiones: %c, %s, %p, %d, %i, %u, %x, %X
- ✅ Gestión de parámetros variables (variadic functions)
- ✅ Manipulación de diferentes tipos de datos
- ✅ Salida formateada personalizable
- ✅ Manejo de diferentes file descriptors
- ✅ Compatible con la librería estándar de C

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
#include "ft_printf.h"

int main(void)
{
    ft_printf("Cadena: %s\n", "Hola Mundo");
    ft_printf("Carácter: %c\n", 'A');
    ft_printf("Número: %d\n", 42);
    ft_printf("Hexadecimal: %x\n", 255);
    return (0);
}
```

## 📚 Funciones implementadas
- `ft_printf`: Función principal que emula printf
- `ft_putchar`: Imprime un carácter
- `ft_putstr`: Imprime una cadena
- `ft_putnbr`: Imprime un número
- `ft_puthex`: Imprime un número en hexadecimal
- Funciones auxiliares para el manejo de conversiones

## 🧪 Testing
El proyecto incluye tests para verificar:
- Manejo correcto de diferentes tipos de datos
- Gestión de errores
- Retorno de valores apropiado
- Comportamiento con casos límite

## ⚠️ Aviso
Este proyecto forma parte del currículum de 42. Si eres estudiante de 42, te animo a desarrollar tus propias soluciones.

<div align="center">
    <p>Desarrollado con ❤️ como parte del currículum de 42</p>
    <br>
    <img src="https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white" alt="C"/>
    <img src="https://img.shields.io/badge/Makefile-003366?style=for-the-badge&logo=gnu&logoColor=white" alt="Makefile"/>
    <img src="https://img.shields.io/badge/norminette-42-white?style=for-the-badge" alt="Norminette"/>
</div>
