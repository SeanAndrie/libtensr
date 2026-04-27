<p align="center">
  <h1 align="center">libtensr</h1>
</p>

<p align="center">
  A lightweight multi-dimensional tensor library written in C
</p>

<p align="center">
  <a href="#overview">Overview</a> ·
  <a href="#features">Features</a> ·
  <a href="#installation">Installation</a> ·
  <a href="#usage">Usage</a> ·
  <a href="#documentation">Documentation</a>
</p>

---

## Overview

`libtensr` is a lightweight multi-dimensional tensor library written in C, designed for numerical and linear algebra operations. It provides a simple API for creating, managing, and accessing N-dimensional arrays with stride-based memory layout.

### Key Characteristics

- **Zero-copy views** - Create lightweight views without copying data
- **Broadcasting** - Automatic shape expansion during operations
- **Multiple data types** - Support for f32, f64, i32, i64, u8, c64, c128
- **Strided memory** - Row-major layout with customizable strides
- **Custom operations** - Extend via callbacks

---

## Features

| Category | Description |
|----------|-------------|
| Allocation | Create tensors from scratch, data, or existing arrays |
| Views | Transpose, permute, reshape, slice without copying |
| Element-wise | Add, subtract, multiply, divide, abs, sqrt, clamp |
| Reductions | Sum, min, max, mean along specified axes |
| Linear Algebra | Dot, cross, matmul, norm, normalize |
| Iteration | Traverse tensor elements efficiently |

For a complete list of functions and types, see the [API documentation](./docs/api.md).

---

## Installation

```bash
# Clone dependencies
git clone https://github.com/SeanAndrie/libft-adapt libft

# Clone this library
git clone https://github.com/SeanAndrie/libtensr.git

# Build
cd libtensr && make
```

This produces a static library `libtensr.a`.

---

## Usage

```c
#include <libft.h>
#include <libtensr.h>

int main() {
    // Create a 1D tensor with values 0, 1, 2
    t_tensr *a = tensr_linspace(0.0, 2.0, 3, DT_F64);

    // Create another tensor
    t_tensr *b = tensr_full(1.0, 1, (size_t[]){3}, DT_F64);

    // Element-wise addition
    t_tensr *c = tensr_add(a, b, NULL);

    // Print result
    tensr_print(c);

    // Cleanup
    tensr_free(a);
    tensr_free(b);
    tensr_free(c);

    return 0;
}
```

Compile with:
```bash
cc -o program program.c -I/path/to/libft/includes -I/path/to/libtensr/includes -L/path/to/libtensr -ltensr -L/path/to/libft -lft -lm
```

---

## Documentation

- [API Reference](./docs/api.md) - Complete function reference
- [Data Types](./docs/dtypes.md) - Type system overview

---

<p align="center">
  Built for numerical computing in C
</p>
