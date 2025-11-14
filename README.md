# libtensr (WIP)

`libtensr` is a lightweight multi-dimensional tensor library written in C, designed for numerical and linear algebra operations. It provides a simple API for creating, managing, and accessing N-dimensional arrays (tensors) with stride-based memory layout — similar in concept to NumPy arrays, but implemented in pure C.

The library depends on the <a href='https://github.com/SeanAndrie/libft-adapt'>libft-adapt</a>
 repository, which provides foundational utilities and data structures, and should be placed in the root directory alongside it to ensure proper compilation and linkage.

## Features (Current)

**Core Tensor Management**
- Creation of tensors with arbitrary rank and shape
- Automatic computation of strides (row-major layout only)
- Element access via indexed lookup
- Iteration over N-dimensional indices through contextual helpers

**Elementwise Operations**
- Generic elementwise operation framework
- User-defined binary functions supported through callbacks

**Shape Handling**
- Infer broadcast-compatible shapes
- Support broadcasting rules during elementwise operations

## Planned Features

**Initialization & Data Handling**
- [ ] Generate 1-D ranges
- [ ] Clone tensors
- [ ] Import from raw C arrays
- [ ] Export to raw C arrays

**Shape Manipulation**
- [ ] Reshape tensors without copying
- [ ] Permute dimensions (general transpose)
- [ ] Flatten tensors into 1-D views
- [ ] Squeeze dimensions of size 1
- [ ] Unsqueze/expand dimensions

**Mathematical Operations**
- [ ] Basic elementwise arithmetic (add, sub, mul, div)
- [ ] Vector dot product
- [ ] Matrix multiplication
- [ ] Norm and normalization functions
