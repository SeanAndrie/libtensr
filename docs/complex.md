# Complex Numbers

## Overview

libtensr provides comprehensive support for complex numbers through the C99 `<complex.h>` standard. Complex tensors use `float complex` (DT_C64) or `double complex` (DT_C128) data types.

## Data Types

| Enum | C Type | Size | Use Case |
|------|-------|------|----------|
| `DT_C64` | float complex | 8 bytes | Lower memory, faster operations |
| `DT_C128` | double complex | 16 bytes | Higher precision (default) |

## Creating Complex Tensors

### tensr_complex

Creates a scalar complex tensor from a single complex value.

```c
#include <tensr/tensr.h>

// Create scalar complex tensor
t_tensr *z = tensr_complex(3.0 + 4.0 * I, DT_C128);

// Free when done
tensr_free(z);
```

### tensr_cfull

Creates a tensor filled with a complex value.

```c
// Create 2x2 complex tensor filled with 1 + 2i
t_tensr *z = tensr_cfull(1.0 + 2.0 * I, 2, (size_t[]){2, 2}, DT_C128);
```

### tensr_clinspace

Creates evenly spaced complex values between start and end.

```c
// Complex values from 0+0i to 1+1i
t_tensr *z = tensr_clinspace(0.0, 1.0 + 1.0 * I, 5, DT_C128);
// Result: [0+0i, 0.25+0.25i, 0.5+0.5i, 0.75+0.75i, 1+1i]
```

---

## Accessing Real and Imaginary Parts

### tensr_creal

Extracts the real components from a complex tensor.

```c
t_tensr *real_part = tensr_creal(z, NULL);
// Returns tensor containing only real components
// Or specify output tensor:
t_tensr *output = tensr_alloc(1, (size_t[]){3}, DT_F64);
t_tensr *real_part = tensr_creal(z, output);
```

### tensr_cimag

Extracts the imaginary components from a complex tensor.

```c
t_tensr *imag_part = tensr_cimag(z, NULL);
// Returns tensor containing only imaginary components
```

### tensr_carg

Computes the phase angle (argument) of each complex element.

```c
t_tensr *phase = tensr_carg(z, NULL);
// For z = 1 + 1i, returns atan2(1, 1) ≈ 0.785 radians
```

---

## Complex Arithmetic

All standard element-wise operations work with complex tensors:

### tensr_add, tensr_sub, tensr_mul, tensr_div

```c
t_tensr *a = tensr_complex(1.0 + 2.0 * I, DT_C128);
t_tensr *b = tensr_complex(3.0 + 4.0 * I, DT_C128);

t_tensr *sum = tensr_add(a, b, NULL);    // 4 + 6i
t_tensr *diff = tensr_sub(a, b, NULL);    // -2 - 2i
t_tensr *prod = tensr_mul(a, b, NULL);   // -5 + 10i
t_tensr *quot = tensr_div(a, b, NULL);   // 0.44 + 0.08i
```

### tensr_conjugate

Computes the complex conjugate (negates imaginary part).

```c
t_tensr *z = tensr_complex(3.0 + 4.0 * I, DT_C128);
t_tensr *conj = tensr_conjugate(z, NULL);
// Result: 3.0 - 4.0i
```

### tensr_neg

Negates both real and imaginary parts.

```c
t_tensr *neg_z = tensr_neg(z, NULL);
// Result: -3.0 - 4.0i
```

### tensr_cscale

Scales by a complex constant.

```c
t_tensr *scaled = tensr_cscale(z, 2.0 + 1.0 * I, NULL);
// Multiplies each element by the complex factor
```

---

## Magnitude and Phase

### tensr_abs

Computes the magnitude (absolute value) of complex elements.

```c
t_tensr *z = tensr_complex(3.0 + 4.0 * I, DT_C128);
t_tensr *mag = tensr_abs(z, NULL);
// Result: magnitude = 5.0 (uses cabs())
```

### tensr_sqrt

Computes the complex square root.

```c
t_tensr *sqrt_z = tensr_sqrt(z, NULL);
// Returns complex square root (uses csqrt())
```

---

## Hermitian Inner Product

### tensr_cdot

Computes the Hermitian (conjugate) dot product: `sum(conj(a) * b)`

This is the standard inner product for complex vectors, different from `tensr_dot` which uses `a * b`.

```c
t_tensr *a = tensr_clinspace(1.0, 3.0, 3, DT_C128);   // [1, 2, 3]
t_tensr *b = tensr_clinspace(1.0, 3.0, 3, DT_C128);   // [1, 2, 3]

t_tensr *dot = tensr_cdot(a, b);
// Hermitian: conj(1)*1 + conj(2)*2 + conj(3)*3 = 14
// Non-Hermitian (tensr_dot): 1*1 + 2*2 + 3*3 = 14 (same for real tensors)
```

For complex tensors, `tensr_cdot` uses `tensr_conjugate(a)` internally before computing the inner product.

---

## Operations That Return NULL for Complex

The following operations are undefined for complex numbers and return NULL:

| Function | Reason |
|----------|--------|
| `tensr_clamp` | Clamping complex is undefined |
| `tensr_min` | Comparison undefined |
| `tensr_max` | Comparison undefined |

---

## Comparison with NumPy

libtensr's complex support follows similar patterns to NumPy:

| NumPy | libtensr | Notes |
|-------|----------|-------|
| `np.complex64` | `DT_C64` | 8 bytes |
| `np.complex128` | `DT_C128` | 16 bytes |
| `a.conj()` | `tensr_conjugate(a)` | Same |
| `a.real` | `tensr_creal(a)` | Same |
| `a.imag` | `tensr_cimag(a)` | Same |
| `np.abs(a)` | `tensr_abs(a)` | Uses cabs() |
| `np.angle(a)` | `tensr_carg(a)` | Same |
| `np.dot(a.conj(), b)` | `tensr_cdot(a, b)` | Hermitian product |

---

## Full Example

```c
#include <tensr/tensr.h>
#include <tensr/tensr_math.h>
#include <stdio.h>

int main(void)
{
    // Create complex 1D tensor
    t_tensr *z = tensr_clinspace(0.0, 3.0 + 3.0 * I, 4, DT_C128);

    // Print original
    printf("Original:\n");
    tensr_print(z);

    // Magnitude
    t_tensr *mag = tensr_abs(z, NULL);
    printf("Magnitude:\n");
    tensr_print(mag);
    tensr_free(mag);

    // Phase
    t_tensr *phase = tensr_carg(z, NULL);
    printf("Phase:\n");
    tensr_print(phase);
    tensr_free(phase);

    // Conjugate
    t_tensr *conj = tensr_conjugate(z, NULL);
    printf("Conjugate:\n");
    tensr_print(conj);
    tensr_free(conj);

    // Real part
    t_tensr *real = tensr_creal(z, NULL);
    printf("Real:\n");
    tensr_print(real);
    tensr_free(real);

    // Imaginary part
    t_tensr *imag = tensr_cimag(z, NULL);
    printf("Imaginary:\n");
    tensr_print(imag);
    tensr_free(imag);

    tensr_free(z);
    return 0;
}
```