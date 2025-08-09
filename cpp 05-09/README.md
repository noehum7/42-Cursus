# CPP Modules 05-09 ⚡

## 📝 Descripción
Los módulos de C++ (05-09) constituyen la continuación avanzada del aprendizaje de C++, enfocándose en conceptos más complejos como manejo de excepciones, casting, templates avanzados, contenedores STL y algoritmos. Esta serie profundiza en técnicas de programación moderna y patrones de diseño esenciales para el desarrollo profesional en C++.

## ✨ Características principales
- ✅ Manejo avanzado de excepciones
- ✅ Sistema de casting en C++
- ✅ Templates y programación genérica
- ✅ Contenedores STL avanzados
- ✅ Algoritmos y iteradores
- ✅ Patrones de diseño
- ✅ Serialización de datos
- ✅ Programación funcional en C++

## 🛠️ Tecnologías utilizadas
- Lenguaje C++98
- Templates y programación genérica
- STL (Standard Template Library)
- Manejo de excepciones
- Casting operators
- Algoritmos STL
- Makefile para compilación
- Git para control de versiones
- Norminette adaptada para C++

## 📋 Requisitos previos
- Sistema operativo Unix/Linux
- Compilador g++ con soporte C++98
- Make
- Conocimientos sólidos de C++ básico (módulos 00-04)
- Comprensión de POO avanzada

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

### Module 05 - Excepciones
- **ex00 (Bureaucrat)**: Clases con excepciones básicas
- **ex01 (Form)**: Formularios y validación con excepciones
- **ex02 (Concrete Forms)**: Herencia y formularios específicos
- **ex03 (Intern)**: Patrón Factory y creación dinámica

### Module 06 - Casting
- **ex00 (Scalar Converter)**: Conversiones entre tipos escalares
- **ex01 (Serialization)**: Serialización de punteros
- **ex02 (Base)**: Identificación de tipos dinámicos

### Module 07 - Templates
- **ex00 (Start with templates)**: Templates de funciones básicos
- **ex01 (Iter)**: Templates con iteradores
- **ex02 (Array)**: Templates de clases - contenedor array

### Module 08 - Contenedores STL
- **ex00 (Easy find)**: Algoritmos de búsqueda en contenedores
- **ex01 (Span)**: Contenedor personalizado con algoritmos
- **ex02 (Mutant Stack)**: Herencia de contenedores STL

### Module 09 - Algoritmos avanzados
- **ex00 (Bitcoin Exchange)**: Parsing y gestión de datos
- **ex01 (RPN)**: Calculadora de notación polaca reversa
- **ex02 (PmergeMe)**: Algoritmos de ordenación avanzados

## 🔍 Conceptos clave aprendidos

### Manejo de excepciones
- Try-catch blocks
- Jerarquía de excepciones personalizadas
- RAII y gestión segura de recursos
- Propagación de excepciones

### Casting en C++
- static_cast: Conversiones explícitas seguras
- dynamic_cast: Casting con verificación en tiempo de ejecución
- const_cast: Modificación de calificadores const
- reinterpret_cast: Conversiones de bajo nivel

### Templates avanzados
- Templates de funciones genéricas
- Templates de clases
- Especialización de templates
- SFINAE (Substitution Failure Is Not An Error)

### STL y algoritmos
- Contenedores secuenciales y asociativos
- Iteradores y sus categorías
- Algoritmos de búsqueda y ordenación
- Functors y predicados

## 🧪 Ejemplos de uso

### Module 05 - Excepciones
```cpp
try {
    Bureaucrat bob("Bob", 1);
    Form form("Secret", 1, 1);
    bob.signForm(form);
} catch (std::exception& e) {
    std::cout << e.what() << std::endl;
}
```

### Module 06 - Casting
```cpp
// Static cast
float f = 42.42f;
int i = static_cast<int>(f);

// Dynamic cast
Base* base = new Derived();
Derived* derived = dynamic_cast<Derived*>(base);
```

### Module 07 - Templates
```cpp
template<typename T>
void swap(T& a, T& b) {
    T tmp = a;
    a = b;
    b = tmp;
}

Array<int> arr(10);
arr[0] = 42;
```

### Module 08 - STL
```cpp
std::vector<int> vec;
vec.push_back(1);
vec.push_back(2);

std::vector<int>::iterator it = easyfind(vec, 2);
if (it != vec.end())
    std::cout << "Found: " << *it << std::endl;
```

### Module 09 - Algoritmos
```cpp
// RPN Calculator
RPN calculator;
std::cout << calculator.evaluate("8 9 * 9 - 9 - 9 - 4 - 1 +") << std::endl;

// Bitcoin Exchange
BitcoinExchange btc("data.csv");
std::cout << btc.getExchangeRate("2011-01-03", 3) << std::endl;
```

## 🧪 Testing
Cada módulo incluye:
- Tests exhaustivos de casos límite
- Verificación de manejo de excepciones
- Validación de templates con diferentes tipos
- Comprobación de eficiencia de algoritmos
- Tests de memoria y rendimiento
- Verificación de comportamiento STL

## 📋 Conceptos avanzados implementados

### Exception Safety
```cpp
class SafeClass {
    // Basic guarantee: no resource leaks
    // Strong guarantee: rollback on exception
    // No-throw guarantee: never throws
};
```

### Template Metaprogramming
```cpp
template<typename T>
class Array {
    T* _array;
    unsigned int _size;
public:
    class OutOfBoundsException : public std::exception {};
    T& operator[](unsigned int i);
};
```

### STL Compatibility
```cpp
class MutantStack : public std::stack<T> {
public:
    typedef typename std::stack<T>::container_type::iterator iterator;
    iterator begin() { return this->c.begin(); }
    iterator end() { return this->c.end(); }
};
```

## 🎯 Algoritmos implementados
- **Merge-Insert Sort**: Optimización híbrida para diferentes tamaños
- **RPN Evaluation**: Stack-based expression evaluation
- **Binary Search**: Búsqueda en datos ordenados
- **Container Adapters**: Personalización de comportamiento STL

## ⚠️ Aviso
Este proyecto forma parte del currículum de 42. Si eres estudiante de 42, te animo a desarrollar tus propias soluciones.

<div align="center">
    <p>Desarrollado con ❤️ como parte del currículum de 42</p>
    <br>
    <img src="https://img.shields.io/badge/C++-00599C?style=for-the-badge&logo=cplusplus&logoColor=white" alt="C++"/>
    <img src="https://img.shields.io/badge/OOP-005090?style=for-the-badge&logo=cplusplus&logoColor=white" alt="OOP"/>
    <img src="https://img.shields.io/badge/C++98-blue?style=for-the-badge&logo=cplusplus&logoColor=white" alt="C++98"/>
    <img src="https://img.shields.io/badge/STL-Advanced-red?style=for-the-badge&logo=cplusplus&logoColor=white" alt="STL"/>
    <img src="https://img.shields.io/badge/Templates-Generic-green?style=for-the-badge&logo=cplusplus&logoColor=white" alt="Templates"/>
    <img src="https://img.shields.io/badge/Exceptions-Handling-orange?style=for-the-badge&logo=cplusplus&logoColor=white" alt="Exceptions"/>
</div>
