# 42 Cursus - Proyectos Common Core 🚀

## 📝 Descripción
Este repositorio contiene una colección de proyectos desarrollados durante mi formación en 42. Cada carpeta representa un proyecto individual que aborda diferentes conceptos de programación en C y C++, desde operaciones básicas con listas enlazadas hasta proyectos más complejos como la implementación de una shell funcional (Minishell), la redirección de tuberías, la programación concurrente y la programación orientada a objetos.

## 📂 Proyectos incluidos

### Libft
Biblioteca de funciones en C que recrea varias funciones estándar de libc, además de incluir funciones útiles para el manejo de listas enlazadas.

### get_next_line
Función que lee una línea de un descriptor de archivo, permitiendo llamadas sucesivas para leer el archivo completo.

### ft_printf
Reimplementación de la función printf de la biblioteca estándar de C.

### Born2beroot
Guía de configuración para crear y configurar una máquina virtual con reglas de seguridad específicas.

### pipex
Programa que simula el comportamiento de tuberías en la shell, permitiendo ejecutar comandos y redireccionar su entrada/salida.

### so_long
Pequeño juego 2D desarrollado utilizando la biblioteca gráfica MinilibX.

### push_swap
Algoritmo de ordenación que manipula dos pilas con un conjunto limitado de operaciones para ordenar datos con el menor número de movimientos posible.

### Philosophers
Solución al problema clásico de sincronización de los filósofos cenando, implementando multithreading y manejo de recursos compartidos para evitar condiciones de carrera y deadlocks.

### Minishell
Implementación de una shell básica que simula el comportamiento de bash, incluyendo manejo de comandos, pipes, redirecciones, variables de entorno y built-ins.

### NetPractice
Ejercicios prácticos de configuración de redes TCP/IP, subnetting, y configuración de direcciones IP para comprender los fundamentos de networking.

### CPP Modules 00-04
Introducción completa al lenguaje C++ y la programación orientada a objetos, cubriendo desde conceptos básicos hasta herencia, polimorfismo y clases abstractas.

### cub3D
Motor gráfico 3D tipo raycasting que simula un entorno tridimensional estilo Wolfenstein 3D, utilizando técnicas de renderizado en tiempo real y manejo avanzado de gráficos.

## 🔧 Tecnologías utilizadas
- Lenguaje C para todos los proyectos
- Makefile para la compilación
- MinilibX y MLX42 para proyectos gráficos
- Conceptos de sistemas UNIX
- Algoritmos y estructuras de datos
- Multithreading y sincronización
- Redes TCP/IP y protocolos de red
- Programación orientada a objetos (POO)
- Raycasting y renderizado 3D

## 📋 Requisitos
- Compilador GCC
- Compilador G++ (para proyectos C++)
- Make
- Entorno UNIX/Linux (para la mayoría de proyectos)
- Biblioteca MinilibX y MLX42 (para proyectos gráficos)
- Biblioteca pthread para multithreading

## ⚙️ Compilación y ejecución
Cada proyecto contiene su propio Makefile con las siguientes reglas estándar:
```bash
make        # Compilar el proyecto
make clean  # Eliminar archivos objeto
make fclean # Eliminar archivos objeto y ejecutable
make re     # Recompilar el proyecto
```

## 📚 Documentación
Cada carpeta de proyecto incluye su propio README.md con información detallada sobre:
- Objetivos específicos del proyecto
- Funciones implementadas
- Ejemplos de uso
- Referencias a recursos adicionales

## 🧪 Testing
Los proyectos han sido testeados utilizando diversas herramientas y casos de prueba para garantizar su correcto funcionamiento según los requisitos especificados.

## 📄 Licencia
Este proyecto está bajo la Licencia MIT - vea el archivo [LICENSE](LICENSE) para más detalles.

## ⚠️ Aviso importante
Este repositorio contiene soluciones para proyectos de 42. Si eres estudiante de 42:
- El código se comparte solo con fines educativos y de consulta.
- No copies el código - la política de 42 prohíbe el plagio.
- Intenta resolver los proyectos por ti mismo.
- Utiliza este recurso solo como referencia después de haber completado los proyectos.

> ⚠️ Los enunciados y requisitos específicos de los proyectos son propiedad intelectual de 42 Network.

<div align="center">
    <p>Desarrollado con ❤️ durante mi formación en el campus 42 Málaga</p>
    <br>
    <img src="https://img.shields.io/badge/C-blue?style=for-the-badge&logo=c&logoColor=white" alt="C"/>
    <img src="https://img.shields.io/badge/C++-00599C?style=for-the-badge&logo=cplusplus&logoColor=white" alt="C++"/>
    <img src="https://img.shields.io/badge/42-Málaga-008000?style=for-the-badge&logo=42&logoColor=white&labelColor=8A2BE2" alt="42 Málaga"/>
    <img src="https://img.shields.io/badge/Norminette-42-00babc?style=for-the-badge&logo=42&logoColor=white" alt="Norminette"/>
    <img src="https://img.shields.io/badge/Licencia-MIT-yellow?style=for-the-badge" alt="Licencia"/>
</div>
