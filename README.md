# Лабораторная работа № 2. Введение в профессиональную деятельность

**ФИО:** Трифонова Маргарита Сергеевна  
**Группа:** МЗО-111БВ-26  

В проекте представлены задания в отдельных папках (ex04, ex05_and_ex06, ex07, ex09, ex10_and_ex12, ex11, ex13, ex14, ex15).

Сборка возможна тремя способами: вручную (через gcc), с помощью Makefile или с помощью CMake.

## 1. Ручная сборка
Для C-файлов:
```bash
gcc -Wall -Wextra -Wpedantic -O0 ex04/main.c -o ex04/app.exe
```

Для C++ файлов: 
```bash
g++ -Wall -Wextra -Wpedantic -O0 ex11/main.cpp -o ex11/app.exe
```

Для задания 13 (несколько файлов в одной программе):
```bash
gcc -Wall -Wextra -Wpedantic -O0 -std=gnu2x ex13/main.c ex13/device.c -o ex13/app.exe
```

## 2. Сборка через Make
В корне проекта есть Makefile. Для Windows используется mingw32-make.
Собрать все задания сразу:
```bash
mingw32-make
```

Собрать конкретное задание:
```bash
mingw32-make ex09
```

Очистить проект от собранных файлов:
```bash
mingw32-make clean
```

## 3. Сборка через CMake
В корне проекта есть CMakeLists.txt. CMake создаст папку build и соберет все .exe файлы туда. 
Шаг 1. Сгенерировать файлы сборки:
```bash
cmake -S . -B build -G "MinGW Makefiles"
```
Шаг 2. Собрать проект:
```bash
cmake --build build
```
Шаг 3. Запуск собранной программы:
```bash
.\build\ex04.exe
```
Полная очистка:
```bash
Remove-Item -Recurse -Force build
```