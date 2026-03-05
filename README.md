<p align="center">
  <h1 align="center">libtensr</h1>
  <!-- <img src="" alt="libtensr" width="200" /> -->
</p>

<p align="center">
  A lightweight multi-dimensional tensor library written in C
</p>

<p align="center">
  <a href="#overview">Overview</a> ·
  <a href="#features">Features</a> ·
  <a href="#installation">Installation</a> ·
  <a href="#usage">Usage</a> ·
  <a href="#api-reference">API Reference</a>
</p>

---

## Overview

`libtensr` is a lightweight multi-dimensional tensor library written in C, designed for numerical and linear algebra operations in small-scale projects. It provides a simple API for creating, managing, and accessing N-dimensional arrays with stride-based memory layout.

---

## Planned Features

| Feature | Description |
|---------|-------------|
| `tensr_matmul` | Matrix multiplication |
| `tensr_mean` | Arithmetic mean over axis |
| `tensr_abs` | Element-wise absolute value |
| `tensr_clamp` | Clamp tensor values to a range |
| `tensr_cast` | Cast tensor to different data type |
| `tensr_linspace` | Create evenly spaced tensor |

---

## Features

### Data Types

| Type | Description |
|------|-------------|
| `DT_F32` | 32-bit floating point |
| `DT_F64` | 64-bit floating point |
| `DT_I32` | 32-bit signed integer |
| `DT_I64` | 64-bit signed integer |

### Core Tensor Operations

- **Allocation** - Create tensors with custom shapes and strides
- **Broadcasting** - Efficiently expand tensors during operations
- **Array Conversion** - Convert between C arrays and tensors
- **Element Access** - Get and set individual elements
- **Contiguity Check** - Verify if tensor data is contiguous in memory
- **Offset Calculation** - Compute memory offsets for indices
- **Tensor Equality** - Compare tensors for equality

### Views & Transformations

- **View** - Create lightweight views into existing tensor data
- **Transpose** - Reverse or permute tensor dimensions
- **Slice** - Extract sub-tensors along specified dimensions
- **Reshape** - Change tensor shape without copying data
- **Permute** - Reorder tensor dimensions

### Layout Management

- **Shape Equality** - Compare tensor shapes
- **Layout Copy** - Copy layout information between tensors
- **Memory Layout** - Manage stride-based memory layouts

### Element-wise Operations

- Addition (`+`)
- Subtraction (`-`)
- Multiplication (`*`)
- Division (`/`)
- Negation (`-`)
- Custom callback support

### Linear Algebra

- **Matrix Multiplication** - General matrix-matrix multiply
- **Dot Product** - Inner product of vectors/matrices
- **Cross Product** - Cross product for 3D vectors
- **Norm** - Compute vector/matrix norms

### Reductions

- **Sum** - Sum all elements along specified axes
- **Min** - Minimum value along specified axes
- **Max** - Maximum value along specified axes
- **Strided Reductions** - Optimized reductions for strided tensors

### Iteration

- **Iterator Init** - Initialize tensor iterator
- **Iterator Next** - Advance to next element
- **Iterator Reset** - Reset iterator to beginning

### Generic Math

- **Square Root** - Element-wise square root

### Debugging

- **Print** - Print tensor contents and metadata
- **Metadata** - Display tensor shape, stride, and type information

## Dependencies

- [libft](https://github.com/ft-nr/libft) - Utility library for C

## Installation

```bash
# Clone libft first
git clone https://github.com/ft-nr/libft.git ../libft
cd ../libft && make && cd -

make
```

This produces a static library `libtensr.a`.

## Usage

#include <libtensr.h>
```c

int main() {
    // Create a 3x3 tensor
    tensr_t *a = tensr_alloc((uint32_t[]){3, 3}, 2, DT_F64);
    
    // ... use the tensor ...
    
    tensr_free(a);
    return 0;
}
```

<p align="center">
  Built for numerical computing in C
</p>
