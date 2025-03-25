# Push_swap 🔄

## 📝 Descripción
Push_swap es un proyecto de algoritmia que consiste en ordenar datos utilizando dos pilas (stacks) y un conjunto limitado de operaciones. El objetivo es desarrollar un programa en C que calcule y muestre la secuencia más corta de instrucciones para ordenar un conjunto de números enteros.

## ✨ Características principales
- ✅ Algoritmo de ordenación optimizado
- ✅ Manejo eficiente de dos pilas (A y B)
- ✅ Implementación de diferentes estrategias según el tamaño del input
- ✅ Cálculo de costes para minimizar operaciones
- ✅ Indexación normalizada de valores
- ✅ Validación robusta de argumentos

## 🛠️ Tecnologías utilizadas
- Lenguaje C
- Estructuras de datos (listas enlazadas)
- Algoritmos de ordenación
- Makefile para compilación
- Git para control de versiones
- Norminette para estilo de código

## 📋 Requisitos previos
- Sistema operativo Unix/Linux
- GCC compiler
- Make
- Checker (para verificar la solución)

## ⚙️ Compilación y uso
```bash
# Compilar el programa
make

# Limpiar archivos objeto
make clean

# Limpiar todos los archivos generados
make fclean

# Recompilar
make re

# Ejecutar con argumentos
./push_swap 4 2 8 5 1

# Contar operaciones
./push_swap 4 2 8 5 1 | wc -l

# Verificar solución
./push_swap 4 2 8 5 1 | ./checker_linux 4 2 8 5 1
```

## 🔍 Operaciones permitidas
- **sa**: Intercambia los dos primeros elementos de la pila A
- **sb**: Intercambia los dos primeros elementos de la pila B
- **ss**: Ejecuta sa y sb simultáneamente
- **pa**: Toma el primer elemento de B y lo coloca en la cima de A
- **pb**: Toma el primer elemento de A y lo coloca en la cima de B
- **ra**: Desplaza hacia arriba todos los elementos de A (el primero se convierte en el último)
- **rb**: Desplaza hacia arriba todos los elementos de B (el primero se convierte en el último)
- **rr**: Ejecuta ra y rb simultáneamente
- **rra**: Desplaza hacia abajo todos los elementos de A (el último se convierte en el primero)
- **rrb**: Desplaza hacia abajo todos los elementos de B (el último se convierte en el primero)
- **rrr**: Ejecuta rra y rrb simultáneamente

## 📚 Algoritmos implementados
- **Ordenación para 2-3 números**: Algoritmos específicos optimizados
- **Ordenación para 4-5 números**: Estrategia de mover mínimos a B
- **Ordenación para +5 números**: Algoritmo basado en costes que:
  - Indexa los números según su posición ordenada
  - Mueve elementos eficientemente entre pilas
  - Calcula el coste óptimo de cada movimiento
  - Ejecuta siempre la operación más eficiente

## 🧪 Rendimiento
El algoritmo logra ordenar:
- 3 números en máximo 2 operaciones
- 5 números en máximo 12 operaciones
- 100 números en menos de 700 operaciones
- 500 números en menos de 5500 operaciones

## ⚠️ Aviso
Este proyecto forma parte del currículum de 42. Si eres estudiante de 42, te animo a desarrollar tus propias soluciones.

<div align="center">
    <p>Desarrollado con ❤️ como parte del currículum de 42</p>
    <br>
    <img src="https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white" alt="C"/>
    <img src="https://img.shields.io/badge/Algoritmos-00325c?style=for-the-badge&logo=c&logoColor=white" alt="Algoritmos"/>
    <img src="https://img.shields.io/badge/norminette-42-white?style=for-the-badge" alt="Norminette"/>
</div>
