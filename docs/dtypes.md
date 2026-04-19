# Data Types

## Overview

The library supports multiple data types for different numerical precision and memory requirements.

## Supported Types

| Enum | C Type | Description | Size |
|------|-------|-------------|------|
| `DT_F32` | float | 32-bit floating point | 4 bytes |
| `DT_F64` | double | 64-bit floating point | 8 bytes |
| `DT_I32` | int32_t | 32-bit signed integer | 4 bytes |
| `DT_I64` | int64_t | 64-bit signed integer | 8 bytes |
| `DT_U8` | uint8_t | 8-bit unsigned integer | 1 byte |

## Type Selection

Choose the appropriate data type based on your needs:

- **DT_F64** (double) - Default for numerical computations requiring high precision
- **DT_F32** (float) - Use for lower memory footprint and faster operations
- **DT_I32** / **DT_I64** - For integer data
- **DT_U8** - For categorical data or binary flags

## Type Conversion

Use `tensr_cast` to convert between types:

```c
t_tensr *float_tensor = tensr_linspace(0.0, 1.0, 10, DT_F64);

// Convert to float
t_tensr *converted = tensr_cast(float_tensor, DT_F32, NULL);
```

## Typed Arrays

Helper functions create typed array wrappers from C arrays:

```c
double data[] = {1.0, 2.0, 3.0};
t_array arr = arr_f64(data, 3);
t_tensr *t = tensr_from_arr(&arr, 1, (size_t[]){3}, DT_F64);
```

Available: `arr_u8`, `arr_i32`, `arr_i64`, `arr_f32`, `arr_f64`

---

## Tensor Structure

```c
struct s_tensr {
    void        *data;       // Pointer to tensor data
    t_layout    layout;      // Shape and stride information
    t_dtype     dtype;      // Data type
};
```

The tensor manages its own memory and handles type-specific operations internally.

---

## Memory Layout

Tensors use row-major (C-style) memory layout by default:

```
For a 2x3 tensor:
[data[0][0], data[0][1], data[0][2], data[1][0], data[1][1], data[1][2]]
  stride[0]=3, stride[1]=1
```

Strides are automatically computed based on shape but can be customized for advanced use cases.