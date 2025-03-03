# Libft 📚

## 📝 Descripción
Libft es una biblioteca personalizada en C que recrea funciones estándar de la librería stdlib.h. Este proyecto fundamental sirve como base para futuros desarrollos, implementando funciones esenciales para la manipulación de strings, memoria y listas enlazadas.

## ✨ Características principales
- ✅ Funciones de manipulación de memoria (memset, memcpy, etc.)
- ✅ Funciones de manejo de strings (strlen, strcpy, strjoin, etc.)
- ✅ Funciones de conversión (atoi, itoa)
- ✅ Funciones de caracteres (isalpha, isdigit, etc.)
- ✅ Gestión de listas enlazadas (bonus)
- ✅ Funciones adicionales útiles

## 🛠️ Tecnologías utilizadas
- Lenguaje C
- Makefile para compilación
- Git para control de versiones
- Norminette para estilo de código
- Biblioteca estándar de C como referencia

## 📋 Funciones implementadas

### Funciones de libc
- isalpha, isdigit, isalnum, isascii, isprint
- strlen, memset, bzero, memcpy, memmove
- strlcpy, strlcat, toupper, tolower
- strchr, strrchr, strncmp, memchr, memcmp
- strnstr, atoi

### Funciones adicionales
- ft_substr: Extrae una subcadena
- ft_strjoin: Une dos strings
- ft_strtrim: Elimina caracteres específicos
- ft_split: Divide una string en array
- ft_itoa: Convierte int a string
- ft_strmapi: Aplica función a cada carácter
- ft_putchar_fd: Escribe un carácter
- ft_putstr_fd: Escribe una string
- ft_putendl_fd: Escribe string con salto de línea
- ft_putnbr_fd: Escribe un número

### Funciones bonus (Listas enlazadas)
- ft_lstnew: Crea nuevo nodo
- ft_lstadd_front: Añade nodo al principio
- ft_lstsize: Cuenta elementos
- ft_lstlast: Obtiene último nodo
- ft_lstadd_back: Añade nodo al final
- ft_lstdelone: Elimina un nodo
- ft_lstclear: Elimina y libera lista
- ft_lstiter: Itera y aplica función
- ft_lstmap: Crea nueva lista aplicando función

## ⚙️ Compilación y uso
```bash
# Compilar la biblioteca
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
```c
#include "libft.h"

int main(void)
{
    char *str = "Hello, World!";
    char *substr = ft_substr(str, 0, 5);
    ft_putendl_fd(substr, 1);
    free(substr);
    return (0);
}
```

## 🧪 Testing
El proyecto incluye pruebas para verificar:
- Funcionamiento correcto de cada función
- Gestión de memoria
- Casos límite y errores
- Comportamiento con inputs inválidos

## ⚠️ Aviso
Este proyecto forma parte del currículum de 42. Si eres estudiante de 42, te animo a desarrollar tus propias soluciones.

<div align="center">
    <p>Desarrollado con ❤️ como parte del currículum de 42</p>
    <br>
    <img src="https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white" alt="C"/>
    <img src="https://img.shields.io/badge/Makefile-003366?style=for-the-badge&logo=gnu&logoColor=white" alt="Makefile"/>
    <img src="https://img.shields.io/badge/norminette-42-white?style=for-the-badge" alt="Norminette"/>
</div>
