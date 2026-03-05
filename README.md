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
- Custom callback support via `tensr_elementwise`

### Linear Algebra

- **Dot Product** - Inner product of vectors/matrices
- **Cross Product** - Cross product for 3D vectors
- **Norm** - Compute vector/matrix norms

### Reductions

- **Sum** - Sum all elements along specified axes
- **Min** - Minimum value along specified axes
- **Max** - Maximum value along specified axes

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

- [libft](https://github.com/SeanAndrie/libft-adapt) - Utility library for C

## Installation

```bash
# Clone libft first
git clone https://github.com/SeanAndrie/libft-adapt libft

# Clone libtensr
git clone https://github.com/SeanAndrie/libtensr.git

# Navigate to repository
cd libtensr

make
```

This produces a static library `libtensr.a`.

## Usage

```c
#include <libtensr.h>

int main() {

    // Create a typed array
    t_array vec_a = arr_i32((int[]{1, 2, 3}), 3);

    // Create a vector
    tensr_t *a = tensr_from_arr(&vec_a, 1, (size_t[]){3}, DT_I32);
    
    // ... use the tensor ...
    
    tensr_free(a);
    return 0;
}
```

<p align="center">
  Built for numerical computing in C
</p>
