# Minishell 🐚

## 📝 Descripción
Minishell es una implementación de una shell básica que simula el comportamiento de bash. Este proyecto explora la creación de un intérprete de comandos funcional que maneja la ejecución de programas, redirecciones, pipes, variables de entorno y comandos built-in, proporcionando una comprensión profunda del funcionamiento interno de las shells de Unix.

## ✨ Características principales
- ✅ Ejecución de comandos del sistema
- ✅ Implementación de pipes (|)
- ✅ Redirecciones de entrada y salida (<, >, <<, >>)
- ✅ Variables de entorno y expansión
- ✅ Manejo de comillas simples y dobles
- ✅ Comandos built-in (echo, cd, pwd, export, unset, env, exit)
- ✅ Manejo de señales (Ctrl+C, Ctrl+D, Ctrl+\)
- ✅ Historial de comandos
- ✅ Expansión de tilde (~) al directorio home
- ✅ Validación de sintaxis de comandos

## 🛠️ Tecnologías utilizadas
- Lenguaje C
- Funciones del sistema Unix
- Parsing y tokenización
- Gestión de procesos (fork, execve, wait)
- Manejo de pipes y redirecciones
- Readline library para entrada interactiva
- Makefile para compilación
- Git para control de versiones
- Norminette para estilo de código

## 📋 Requisitos previos
- Sistema operativo Unix/Linux
- GCC compiler
- Make
- Biblioteca readline
- Biblioteca libft (incluida en el proyecto)

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

# Ejecutar minishell
./minishell
```

## 🔍 Comandos built-in implementados
- **echo**: Imprime argumentos con opción -n
- **cd**: Cambia el directorio actual (con soporte para ~, -, rutas relativas/absolutas)
- **pwd**: Muestra el directorio de trabajo actual
- **export**: Establece variables de entorno (muestra formato declare -x sin argumentos)
- **unset**: Elimina variables de entorno
- **env**: Muestra las variables de entorno
- **exit**: Sale de la shell con código de estado

## 🏗️ Arquitectura del proyecto

### Parser
- **Tokenización**: División de la entrada en tokens significativos
- **Análisis sintáctico**: Validación de la sintaxis de comandos
- **Expansión de variables**: Procesamiento de $VAR, $?, y ~ 
- **Manejo de comillas**: Gestión de comillas simples y dobles
- **Gestión de memoria**: Liberación segura de estructuras

### Executor
- **Ejecución simple**: Comandos individuales y built-ins
- **Pipes**: Comunicación entre múltiples comandos
- **Redirecciones**: Manejo de entrada/salida y heredoc
- **Búsqueda de comandos**: Resolución de rutas en PATH
- **Gestión de procesos**: Fork, execve y wait

### Manejo de señales
- **SIGINT (Ctrl+C)**: Nuevo prompt en modo interactivo
- **SIGQUIT (Ctrl+\)**: Ignorada en modo interactivo
- **EOF (Ctrl+D)**: Terminación limpia del shell

## 📚 Funcionalidades implementadas
- **Parsing**: Análisis léxico y sintáctico de comandos
- **Expansión**: Variables de entorno ($VAR, ${VAR}), códigos de salida ($?) y tilde (~)
- **Pipes**: Comunicación entre comandos múltiples con gestión automática de descriptores
- **Redirecciones**: 
  - `<` : Redirección de entrada
  - `>` : Redirección de salida (sobrescribe)
  - `>>` : Redirección de salida (append)
  - `<<` : Here document con delimitador
- **Manejo de comillas**: 
  - Comillas simples: preservan contenido literal
  - Comillas dobles: permiten expansión de variables
- **Gestión de errores**: Manejo robusto de errores y casos edge
- **Variables de entorno**: Sistema completo de gestión con validación de nombres

## 🔧 Estructuras principales
```c
// Comando con argumentos y redirecciones
typedef struct s_command {
    char **args;             // Argumentos del comando
    t_redir *redirs;         // Lista de redirecciones
    struct s_command *next;  // Siguiente comando en pipeline
} t_command;

// Variable de entorno
typedef struct s_env {
    char *key;               // Nombre de la variable
    char *value;             // Valor de la variable
    struct s_env *next;      // Siguiente variable
} t_env;

// Estado del shell
typedef struct s_shell {
    t_env *env_list;         // Lista de variables de entorno
    char **env_array;        // Array para execve
    int exit_status;         // Código de salida ($?)
} t_shell;
```

## 🧪 Testing
El proyecto ha sido probado con:
- Comandos simples y complejos
- Múltiples pipes encadenados
- Diversas combinaciones de redirecciones
- Variables de entorno y expansiones
- Casos límite y manejo de errores
- Comparación de comportamiento con bash
- Pruebas de memoria (valgrind)
- Validación de sintaxis incorrecta
- Manejo de señales en diferentes contextos

## 🎯 Ejemplos de uso
```bash
# Comandos básicos
minishell$ ls -la
minishell$ pwd

# Pipes múltiples
minishell$ ls | grep ".c" | wc -l

# Redirecciones combinadas
minishell$ echo "Hello World" > output.txt
minishell$ cat < input.txt | grep "pattern" >> results.txt

# Variables de entorno
minishell$ export MY_VAR="test"
minishell$ echo $MY_VAR
minishell$ echo "Variable: $MY_VAR y código: $?"

# Here document
minishell$ cat << EOF
> Esta es una línea
> Esta es otra línea
> EOF

# Navegación con cd
minishell$ cd ~
minishell$ cd -
minishell$ cd ../parent_dir

# Expansión de tilde
minishell$ ls ~/Documents
```

## 📋 Códigos de salida
- `0`: Ejecución exitosa
- `1`: Error general
- `126`: Comando no ejecutable
- `127`: Comando no encontrado

## ⚠️ Aviso
Este proyecto forma parte del currículum de 42. Si eres estudiante de 42, te animo a desarrollar tus propias soluciones.

<div align="center">
    <p>Desarrollado con ❤️ como parte del currículum de 42</p>
    <br>
    <img src="https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white" alt="C"/>
    <img src="https://img.shields.io/badge/Shell-121011?style=for-the-badge&logo=gnu-bash&logoColor=white" alt="Shell"/>
    <img src="https://img.shields.io/badge/norminette-42-white?style=for-the-badge" alt="Norminette"/>
</div>
