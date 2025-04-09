# Philosophers 🍽️

## 📝 Descripción
Philosophers es una implementación de la solución al clásico problema de sincronización de los filósofos cenando. Este proyecto explora los conceptos de multithreading, concurrencia y el manejo de recursos compartidos, implementando técnicas para evitar deadlocks y conditions de carrera.

## ✨ Características principales
- ✅ Creación y manejo de threads
- ✅ Sincronización con mutex
- ✅ Prevención de deadlocks
- ✅ Gestión de recursos compartidos
- ✅ Monitoreo de estado de filósofos
- ✅ Control preciso de tiempos
- ✅ Manejo robusto de errores

## 🛠️ Tecnologías utilizadas
- Lenguaje C
- POSIX Threads (pthread)
- Mutex para sincronización
- Funciones de temporización precisas
- Makefile para compilación
- Git para control de versiones
- Norminette para estilo de código

## 📋 Requisitos previos
- Sistema operativo Unix/Linux
- GCC compiler
- Make
- Biblioteca pthread

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
./philo 5 800 200 200 [7]
# [número_de_filósofos] [tiempo_para_morir] [tiempo_para_comer] [tiempo_para_dormir] [número_de_comidas]
```

## 🔍 Parámetros del programa
- **número_de_filósofos**: Número de filósofos y tenedores
- **tiempo_para_morir**: Tiempo en milisegundos que un filósofo puede estar sin comer antes de morir
- **tiempo_para_comer**: Tiempo en milisegundos que un filósofo tarda en comer
- **tiempo_para_dormir**: Tiempo en milisegundos que un filósofo pasa durmiendo
- **número_de_comidas** (opcional): Número de veces que cada filósofo debe comer antes de terminar

## 📚 Funciones implementadas
- Gestión de hilos:
  - pthread_create(): Creación de hilos para cada filósofo
  - pthread_join(): Espera de finalización de hilos
  - pthread_mutex_init/lock/unlock/destroy: Control de acceso a recursos
- Control de tiempos:
  - gettimeofday(): Obtención del tiempo actual
  - usleep(): Pausar la ejecución con precisión
- Monitoreo y supervisión:
  - Comprobación de estados para detectar muertes
  - Registro de actividades con timestamps

## 🧪 Testing
El proyecto ha sido probado con:
- Diferentes cantidades de filósofos (1, 2, 5, 100, 200)
- Tiempos variados para controlar los casos límite
- Ejecuciones prolongadas para verificar estabilidad
- Comprobación de fugas de memoria (valgrind)
- Verificación de deadlocks y conditions de carrera

## ⚠️ Aviso
Este proyecto forma parte del currículum de 42. Si eres estudiante de 42, te animo a desarrollar tus propias soluciones.

<div align="center">
    <p>Desarrollado con ❤️ como parte del currículum de 42</p>
    <br>
    <img src="https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white" alt="C"/>
    <img src="https://img.shields.io/badge/Threads-005090?style=for-the-badge&logo=c&logoColor=white" alt="Threads"/>
    <img src="https://img.shields.io/badge/norminette-42-white?style=for-the-badge" alt="Norminette"/>
</div>
