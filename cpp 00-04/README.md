# CPP Modules 00-04 ⚡

## 📝 Descripción
Los módulos de C++ (00-04) son una introducción completa al lenguaje C++ y la programación orientada a objetos. Esta serie de ejercicios progresivos cubre desde los conceptos básicos del lenguaje hasta temas avanzados como herencia, polimorfismo y manejo de excepciones, proporcionando una base sólida en programación moderna con C++.

## ✨ Características principales
- ✅ Introducción a la sintaxis de C++
- ✅ Programación orientada a objetos (POO)
- ✅ Gestión de memoria en C++
- ✅ Herencia y polimorfismo
- ✅ Sobrecarga de operadores
- ✅ Clases abstractas y interfaces
- ✅ Manejo de excepciones
- ✅ Templates básicos

## 🛠️ Tecnologías utilizadas
- Lenguaje C++98
- Programación orientada a objetos
- STL (Standard Template Library)
- Makefile para compilación
- Git para control de versiones
- Norminette adaptada para C++

## 📋 Requisitos previos
- Sistema operativo Unix/Linux
- Compilador g++ con soporte C++98
- Make
- Conocimientos básicos de programación en C

## ⚙️ Compilación y uso
```bash
# Navegar a cualquier ejercicio
cd module0X/exXX

# Compilar el ejercicio
make

# Limpiar archivos objeto
make clean

# Limpiar todos los archivos generados
make fclean

# Recompilar
make re

# Ejecutar (el nombre varía según el ejercicio)
./programa
```

## 📚 Módulos incluidos

### Module 00 - Introducción a C++
- **ex00 (Megaphone)**: Primer programa en C++, manejo de argumentos
- **ex01 (PhoneBook)**: Clases básicas, encapsulación y arrays
- **ex02 (Account)**: Métodos estáticos, constructores y destructores

### Module 01 - Gestión de memoria
- **ex00 (Zombie)**: Asignación de memoria en stack vs heap
- **ex01 (Zombie Horde)**: Arrays dinámicos y new[]
- **ex02 (HI THIS IS BRAIN)**: Referencias y punteros
- **ex03 (Unnecessary Violence)**: Composición de clases
- **ex04 (Sed is for losers)**: Manipulación de archivos y strings
- **ex05 (Harl 2.0)**: Punteros a funciones miembro
- **ex06 (Harl filter)**: Switch statements y filtrado

### Module 02 - Forma canónica ortodoxa
- **ex00 (Fixed Point)**: Números de punto fijo
- **ex01 (Fixed Point Extended)**: Constructores de conversión
- **ex02 (Fixed Point Advanced)**: Sobrecarga de operadores
- **ex03 (BSP)**: Algoritmos geométricos con clases

### Module 03 - Herencia
- **ex00 (ClapTrap)**: Clase base simple
- **ex01 (ScavTrap)**: Herencia básica
- **ex02 (FragTrap)**: Herencia múltiple
- **ex03 (DiamondTrap)**: Problema del diamante y herencia virtual

### Module 04 - Polimorfismo
- **ex00 (Animal)**: Clases base y derivadas
- **ex01 (Brain)**: Composición y deep copy
- **ex02 (Abstract Animal)**: Clases abstractas
- **ex03 (Interface)**: Interfaces y clases puras

## 🔍 Conceptos clave aprendidos

### Programación Orientada a Objetos
- Encapsulación y ocultación de datos
- Constructores y destructores
- Métodos públicos, privados y protegidos
- Composición vs herencia

### Gestión de memoria en C++
- Stack vs Heap allocation
- RAII (Resource Acquisition Is Initialization)
- Deep copy vs shallow copy
- Manejo de punteros y referencias

### Herencia y Polimorfismo
- Herencia simple y múltiple
- Funciones virtuales
- Clases abstractas
- Interfaces y clases puras
- Problema del diamante

### Sobrecarga de operadores
- Operadores aritméticos
- Operadores de comparación
- Operadores de asignación
- Operadores de inserción/extracción

## 🧪 Ejemplos de uso

### Module 00 - PhoneBook
```cpp
PhoneBook book;
Contact contact;
contact.setFirstName("John");
contact.setLastName("Doe");
book.addContact(contact);
book.displayContacts();
```

### Module 02 - Fixed Point
```cpp
Fixed a(10);
Fixed b(5.5f);
Fixed result = a + b;
std::cout << result << std::endl;
```

### Module 03 - Inheritance
```cpp
ClapTrap clap("Clappy");
ScavTrap scav("Scavvy");
scav.guardGate();
```

### Module 04 - Polymorphism
```cpp
Animal* animals[2];
animals[0] = new Dog();
animals[1] = new Cat();
for (int i = 0; i < 2; i++)
    animals[i]->makeSound();
```

## 🧪 Testing
Cada módulo incluye:
- Tests unitarios para verificar funcionalidad
- Verificación de gestión de memoria
- Comprobación de comportamiento polimórfico
- Validación de la forma canónica ortodoxa
- Tests de casos límite y errores

## 📋 Forma canónica ortodoxa
Todas las clases siguen la regla de los "Big Four":
```cpp
class MyClass {
public:
    MyClass();                          // Constructor por defecto
    MyClass(const MyClass& other);      // Constructor de copia
    MyClass& operator=(const MyClass& other); // Operador de asignación
    ~MyClass();                         // Destructor
};
```

## ⚠️ Aviso
Este proyecto forma parte del currículum de 42. Si eres estudiante de 42, te animo a desarrollar tus propias soluciones.

<div align="center">
    <p>Desarrollado con ❤️ como parte del currículum de 42</p>
    <br>
    <img src="https://img.shields.io/badge/C++-00599C?style=for-the-badge&logo=cplusplus&logoColor=white" alt="C++"/>
    <img src="https://img.shields.io/badge/OOP-005090?style=for-the-badge&logo=cplusplus&logoColor=white" alt="OOP"/>
    <img src="https://img.shields.io/badge/C++98-blue?style=for-the-badge&logo=cplusplus&logoColor=white" alt="C++98"/>
</div>
