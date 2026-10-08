# ⚡ Advanced C++ Programming Module

![C++ Version](https://img.shields.io/badge/C%2B%2B-20-blue.svg?style=for-the-badge&logo=cplusplus)
![Build System](https://img.shields.io/badge/CMake-3.20+-064F8C?style=for-the-badge&logo=cmake&logoColor=white)
![License](https://img.shields.io/badge/License-MIT-green.svg?style=for-the-badge)

A comprehensive coursework and project repository for the **Advanced C++ Programming** module. This repository covers modern C++ standards (C++17/C++20), memory management, object-oriented software design patterns, generic programming, and concurrent systems programming.

---

## 📸 System Overview & Visuals

| Architecture Overview | Memory Profile & Performance |
| :---: | :---: |
| ![Architecture Diagram](https://raw.githubusercontent.com/placeholder/repo/main/docs/images/architecture.png) | ![Performance Profiling](https://raw.githubusercontent.com/placeholder/repo/main/docs/images/profiling.png) |
| *High-level system component diagram* | *Memory management & CPU profiling metrics* |

---

## 🎯 Module Objectives & Core Concepts

- **Modern C++ Standards:** Idiomatic C++11 through C++20 features (Concepts, Ranges, Coroutines, `std::optional`, `std::variant`).
- **Low-Level Memory Management:** Custom allocators, RAII (Resource Acquisition Is Initialization), smart pointers (`std::unique_ptr`, `std::shared_ptr`), and cache-aware data structures.
- **Concurrency & Multithreading:** Thread synchronization, mutexes, condition variables, atomic operations, and lock-free data structures using `std::thread` and `std::async`.
- **Advanced OOP & Design Patterns:** Behavioral, creational, and structural patterns implemented with zero-cost abstractions.
- **Template Metaprogramming:** SFINAE, `std::enable_if`, compile-time evaluation using `constexpr` and C++20 concepts.

---

## 🗂️ Module Directory Structure

```
.
├── docs/                   # Diagrams, architectural documentation, and images
│   └── images/
├── include/                # Header files (.hpp)
│   ├── memory/             # Custom allocators and smart pointers
│   ├── concurrency/        # Thread pools and synchronization primitives
│   └── templates/          # Metaprogramming and generic utilities
├── src/                    # Source implementations (.cpp)
├── tests/                  # Unit tests using GoogleTest
├── benchmarks/             # Microbenchmarks using Google Benchmark
├── CMakeLists.txt          # Root CMake configuration
└── README.md
```

---

## 🛠️ Requirements & Tools

- **Compiler:** `GCC 11+` or `Clang 13+` or `MSVC 2019+` (C++20 support required)
- **Build System:** `CMake 3.20+` & `Ninja` / `Make`
- **Testing:** [GoogleTest Framework](https://github.com/google/googletest)
- **Memory Analysis:** `Valgrind` / AddressSanitizer (ASan)

---

## ⚡ Building and Running

### 1. Clone the Repository
```bash
git clone https://github.com/your-username/advanced-cpp-module.git
cd advanced-cpp-module
```

### 2. Build via CMake
```bash
# Generate build files
cmake -B build -DCMAKE_BUILD_TYPE=Release

# Compile project
cmake --build build --config Release
```

### 3. Run Unit Tests & Benchmarks
```bash
# Run unit tests
cd build && ctest --output-on-failure

# Run specific binary
./bin/advanced_cpp_app
```

---

## 🧪 Memory Leak Testing

To ensure leak-free memory management, builds are tested against Valgrind and AddressSanitizer:

```bash
# Run with AddressSanitizer enabled
cmake -B build_asan -DENABLE_ASAN=ON
cmake --build build_asan
./build_asan/bin/advanced_cpp_app
```

---

## 📜 License

This project is licensed under the MIT License - see the `LICENSE` file for details.
