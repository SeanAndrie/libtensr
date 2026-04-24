# API Reference

## Headers

| Header | Description |
|--------|-------------|
| `tensr/tensr.h` | Core tensor operations, allocation, views, layout, iteration, debugging |
| `tensr/tensr_math.h` | Mathematical operations: element-wise, reductions, linear algebra |
| `tensr/tensr_callbacks.h` | Callback functions for custom operations |

---

## Data Types

| Type | Description |
|------|-------------|
| `DT_F32` | 32-bit floating point |
| `DT_F64` | 64-bit floating point |
| `DT_I32` | 32-bit signed integer |
| `DT_I64` | 64-bit signed integer |
| `DT_U8` | 8-bit unsigned integer |
| `DT_C64` | 64-bit complex float |
| `DT_C128` | 128-bit complex double |

---

## Core Tensor Operations (`tensr.h`)

### Allocation

| Function | Description |
|----------|-------------|
| `tensr_alloc` | Create tensor with custom shape |
| `tensr_full` | Create tensor filled with constant value |
| `tensr_scalar` | Create scalar tensor |
| `tensr_linspace` | Create evenly spaced values |
| `tensr_from_arr` | Create tensor from array with dtype validation |
| `tensr_copy` | Deep copy tensor |
| `tensr_cast` | Convert between data types |
| `tensr_broadcast` | Apply broadcasting rules |

### Element Access

| Function | Description |
|----------|-------------|
| `tensr_get` | Get element at indices |
| `tensr_set` | Set element at indices |
| `tensr_offset` | Compute memory offset from indices |
| `tensr_fill` | Fill tensor with constant value |

### Properties

| Function | Description |
|----------|-------------|
| `tensr_is_contiguous` | Check if tensor data is contiguous |
| `tensr_equal` | Compare tensors for equality |
| `tensr_equal_eps` | Compare with epsilon tolerance |

### Dimension Operations

| Function | Description |
|----------|-------------|
| `tensr_expand_dims` | Add new dimension |
| `tensr_reduced` | Create reduced tensor view |

### Views & Transformations

| Function | Description |
|----------|-------------|
| `tensr_view` | Create lightweight view |
| `tensr_transpose` | Reverse tensor dimensions |
| `tensr_permute` | Reorder dimensions |
| `tensr_reshape` | Change shape without copying |
| `tensr_slice` | Extract sub-tensors |

### Layout Management

| Function | Description |
|----------|-------------|
| `layout_alloc` | Allocate layout structure |
| `layout_init` | Initialize with shape |
| `layout_copy` | Copy layout |
| `layout_equal` | Compare layouts |
| `layout_free` | Free layout |

### Iteration

| Function | Description |
|----------|-------------|
| `iter_init` | Initialize iterator |
| `iter_next` | Advance to next element |
| `iter_reset` | Reset iterator |

### Debugging

| Function | Description |
|----------|-------------|
| `tensr_print` | Print tensor contents |
| `tensr_info` | Display metadata |

---

## Element-wise Operations (`tensr_math.h`)

| Function | Operation |
|----------|-----------|
| `tensr_add` | Element-wise addition |
| `tensr_sub` | Element-wise subtraction |
| `tensr_mul` | Element-wise multiplication |
| `tensr_div` | Element-wise division |
| `tensr_neg` | Negate each element |
| `tensr_abs` | Absolute value |
| `tensr_sqrt` | Square root |
| `tensr_clamp` | Clamp values to range |
| `tensr_scale` | Scale by constant |

---

## Reductions (`tensr_math.h`)

| Function | Description |
|----------|-------------|
| `tensr_sum` | Sum along axes |
| `tensr_min` | Minimum along axes |
| `tensr_max` | Maximum along axes |
| `tensr_mean` | Arithmetic mean along axes |
| `tensr_reduce` | Generic reduction |

---

## Linear Algebra (`tensr_math.h`)

| Function | Description |
|----------|-------------|
| `tensr_dot` | Dot product |
| `tensr_inner` | Inner product |
| `tensr_cross` | Cross product (3D) |
| `tensr_matmul` | Matrix multiplication |
| `tensr_norm` | L2 norm |
| `tensr_normalize` | Normalize to unit length |
| `tensr_cdot` | Hermitian dot product (complex conjugate) |

---

## Generic Operations (`tensr.h`)

| Function | Description |
|----------|-------------|
| `tensr_elementwise` | Custom binary operation via callback |
| `tensr_reduce_strided` | Custom strided reduction via callback |

---

## Callbacks (`tensr_callbacks.h`)

### Binary Operations

| Function | Operation |
|----------|-----------|
| `add_func` | Addition |
| `sub_func` | Subtraction |
| `mul_func` | Multiplication |
| `div_func` | Division |

### Reduction Operations

| Function | Description |
|----------|-------------|
| `sum_init` / `sum_apply` | Sum reduction |
| `min_init` / `min_apply` | Min reduction |
| `max_init` / `max_apply` | Max reduction |
| `mean_finalize` | Mean finalization |

---

## Typed Arrays (`tensr.h`)

| Function | Data Type |
|----------|-----------|
| `arr_u8` | uint8_t |
| `arr_i32` | int32_t |
| `arr_i64` | int64_t |
| `arr_f32` | float |
| `arr_f64` | double |
| `arr_c64` | float complex |
| `arr_c128` | double complex |

---

## Complex Operations (`tensr.h`)

| Function | Description |
|----------|-------------|
| `tensr_complex` | Create scalar complex tensor |
| `tensr_cfill` | Fill tensor with complex value |
| `tensr_cfull` | Create tensor filled with complex value |
| `tensr_clinspace` | Create complex evenly spaced values |
| `tensr_cscale` | Scale by complex constant |

---

## Complex Arithmetic (`tensr_math.h`)

| Function | Description |
|----------|-------------|
| `tensr_conjugate` | Complex conjugate |
| `tensr_creal` | Extract real components |
| `tensr_cimag` | Extract imaginary components |
| `tensr_carg` | Phase angle (argument) |
| `tensr_abs` | Magnitude (cabs) |
| `tensr_sqrt` | Complex square root |

---

## Types

### Core Types

| Type | Description |
|------|-------------|
| `t_tensr` | Tensor structure |
| `t_layout` | Memory layout structure |
| `t_iter` | Iterator structure |
| `t_array` | Typed array wrapper |
| `t_dtype` | Data type enum |
| `t_bool` | Boolean type |