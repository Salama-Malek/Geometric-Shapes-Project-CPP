# Geometric Shapes Project

A C++20 console application that models geometric shapes and renders them on an ASCII board.

## Overview

This project implements a small object-oriented shape library in C++20. Four shape classes — `Rectangle`, `Triangle`, `Window`, and `Hexagram` — each expose a consistent interface for drawing, scaling, and querying geometric properties (perimeter, area, center, bounding rectangle). A `Board` class renders shapes as ASCII art to the console, and `main.cpp` drives an interactive demo: it prompts for vertex coordinates, draws the resulting shape (with and without its bounding rectangle), prints its computed properties, and then repeats the process after scaling the shape by a factor of 2.

## Features

- **Rectangle** — defined by its bottom-left and top-right vertices.
- **Triangle** — an equilateral triangle defined by three vertices, with side length and area derived geometrically.
- **Window** — a frame shape composed of an outer and inner `Rectangle`, with computed horizontal/vertical thickness.
- **Hexagram** — a Star-of-David shape composed of two overlapping `Triangle` instances.
- **Board** — an ASCII drawing surface (70 columns x 50 rows) that renders lines between vertices and prints them to the console.
- Every shape supports `draw`, `scale`, `getBoundingRectangle`, `getPerimeter`, `getArea`, and `getCenter`.
- Interactive console workflow: reads shape vertices from stdin, displays the shape before and after a 2x scale.

## Tech stack

- C++20
- CMake 3.26+ (with CMake Presets)
- AddressSanitizer enabled automatically in Debug builds

## Getting started

### Prerequisites

- A C++20 compiler (MSVC, Clang, or GCC)
- CMake 3.26 or newer

### Build

Using the provided CMake presets:

```bash
cmake --preset x64-Debug
cmake --build --preset x64-Debug
```

Or with a plain CMake configure/build (any generator):

```bash
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
cmake --build build
```

### Run

```bash
./build/oop1_ex01
```

The active shape is selected at compile time via the `RECTANGLE` / `TRIANGLE` / `WINDOW` / `HEXAGRAM` preprocessor switches at the top of `src/main.cpp` (only one is enabled at a time by default). Set the desired switch to `1` and the others to `0`, then rebuild to try a different shape.

## Project structure

```
.
├── CMakeLists.txt
├── CMakePresets.json
├── cmake/
│   ├── CompilerSettings.cmake
│   └── Zip.cmake
├── include/
│   ├── Board.h
│   ├── Rectangle.h
│   ├── Triangle.h
│   ├── Window.h
│   ├── Hexagram.h
│   ├── Vertex.h
│   └── macros.h
└── src/
    ├── Board.cpp
    ├── Rectangle.cpp
    ├── Triangle.cpp
    ├── Window.cpp
    ├── Hexagram.cpp
    ├── Vertex.cpp
    └── main.cpp
```
