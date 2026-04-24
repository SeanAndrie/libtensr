/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tensr.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 12:54:59 by sgadinga          #+#    #+#             */
/*   Updated: 2026/04/25 02:27:41 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TENSR_H
# define TENSR_H

# include <complex.h>
# include <libft.h>
# include <stdint.h>

# define MAX_NDIM 32
# define MAX_ACC_SIZE 8

/* Supported Data Types */
typedef enum e_dtype
{
	DT_U8,
	DT_I32,
	DT_I64,
	DT_F32,
	DT_F64,
	DT_C64,
	DT_C128
}					t_dtype;

/* Typed Array */
typedef struct s_array
{
	void			*data;
	size_t			len;
	enum e_dtype	dtype;
}					t_array;

/* Tensor Memory Layout */
typedef struct s_layout
{
	int				ndim;
	size_t			*shape;
	size_t			*stride;
	size_t			shape_buf[MAX_NDIM];
	size_t			stride_buf[MAX_NDIM];
}					t_layout;

/* Main Tensor Structure */
typedef struct s_tensr
{
	void			*data;
	size_t			size;
	enum e_dtype	dtype;
	struct s_layout	layout;
	size_t			elemsize;
	enum e_bool		owns_data;
}					t_tensr;

/* Slice descriptor */
typedef struct s_slice
{
	int				axis;
	size_t			start;
	size_t			end;
	size_t			step;
}					t_slice;

/* Tensor iterator */
typedef struct s_iter
{
	size_t			total;
	size_t			counter;
	struct s_layout	*layout;
	size_t			indices[MAX_NDIM];
}					t_iter;

/*
** Allocates and initializes an empty base tensor.
**
** @param ndim     Number of dimensions.
** @param shape    An array representing the number of dimensions per axis.
** @param dtype   Data type of the tensor.
** @return        A pointer to the base tensor.
*/
t_tensr				*tensr_alloc(const int ndim, const size_t *shape,
						t_dtype dtype);

/*
 ** Creates a deep copy of a tensor.
 **
 ** @param t         Pointer to the tensor to copy.
 **
 ** @return          A pointer to the copied tensor, or NULL on failure.
 */
t_tensr				*tensr_copy(const t_tensr *t);

/*
 ** Casts a tensor to a different data type.
 **
 ** @param t         Pointer to the tensor to cast.
 ** @param dtype     Target data type.
 **
 ** @return          A pointer to the cast tensor, or NULL on failure.
 */
t_tensr				*tensr_cast(const t_tensr *t, t_dtype dtype, t_tensr *out);

/*
 ** Converts a typed array into a tensor.
 **
 ** @param arr       A typed array.
 ** @param ndim      Number of dimensions.
 ** @param shape     An array representing the number of dimensions per axis.
 ** @param dtype     Data type of the tensor.
 **
 ** @return          A pointer to the converted tensor.
 */
t_tensr				*tensr_from_arr(t_array *arr, const int ndim,
						const size_t *shape, t_dtype dtype);

t_tensr				*tensr_from_data(void *data, const int ndim,
						const size_t *shape, t_dtype dtype);

/*
 ** Creates a 1D tensor with evenly spaced values between start and end.
 **
 ** @param start     Starting value of the sequence.
 ** @param end       Ending value of the sequence.
 ** @param n         Number of elements in the tensor.
 ** @param dtype     Data type for the tensor (DT_I32, DT_I64, DT_F32, DT_F64).
 **
 ** @return          A pointer to the created tensor, or NULL on failure.
 */
t_tensr				*tensr_linspace(double start, double end, const size_t n,
						t_dtype dtype);

/*
 ** Creates a tensor filled with a constant value.
 **
 ** @param value     The constant value to fill the tensor with.
 ** @param ndim      Number of dimensions.
 ** @param shape     An array representing the number of dimensions per axis.
 ** @param dtype     Data type of the tensor.
 **
 ** @return          A pointer to the filled tensor, or NULL on failure.
 */
t_tensr				*tensr_full(double value, const int ndim,
						const size_t *shape, t_dtype dtype);

/*
 ** Creates a scalar tensor.
 **
 ** @param n        The value of the scalar.
 ** @param t_dtype  Data type of tensor.
 */
t_tensr				*tensr_scalar(double n, t_dtype dtype);

/*
 ** Creates a new tensor by broadcasting two tensors together.
 **
 ** Broadcasting aligns tensors of different shapes by expanding
 ** dimensions of size 1 to match the other tensor's dimensions.
 **
 ** @param a         Pointer to the first tensor layout.
 ** @param b         Pointer to the second tensor layout.
 ** @param dtype     Data type of the resulting tensor.
 **
 ** @return          A pointer to the broadcasted tensor, or NULL on failure.
 */
t_tensr				*tensr_broadcast(const t_layout *a, const t_layout *b,
						t_dtype dtype);

/*
** Creates a reduced (collapsed) tensor from a layout without data.
**
** Similar to tensr_reduce but operates only on layout information,
** creating a new tensor with reduced dimensions.
**
** @param l         Pointer to the source layout.
** @param n_axes    Number of axes to reduce.
** @param axes      Array of axis indices to reduce.
** @param dtype     Data type of the resulting tensor.
**
** @return          A pointer to the reduced tensor, or NULL on failure.
*/

t_tensr				*tensr_reduced(const t_tensr *t, const int n_axes,
						t_bool *reduce_mask, t_dtype dtype);

/*
 ** Creates a view of a parent tensor.
 **
 ** A view is a tensor whose data or points to the data of another tensor.
 ** Mainly used to apply transformations without copying or reallocating
 ** the parent tensor's data.
 **
 ** @param t         Pointer to the parent tensor
 ** @param l         Pointer to a tensor layout
 ** @param data      Pointer to some data
 **
 ** @return          Pointer to tensor view.
 */
t_tensr				*tensr_view(const t_tensr *t, void *data,
						const t_layout *l);

/*
 ** Creates a transposed view of a parent 2-D tensor.
 **
 ** @param           Pointer to the parent tensor.
 ** @return          Pointer to tensor view.
 */
t_tensr				*tensr_transpose(const t_tensr *t);

/*
 ** Creates a view of a parent tensor whose shape is reorganized based
 ** on an array of indices representing the specific permutation of shape values.
 **
 ** @param t         Pointer to the parent tensor.
 ** @param perm      An array of permutation indices.
 **
 ** @return          Pointer to tensor view.
 */
t_tensr				*tensr_permute(const t_tensr *t, const size_t *perm);

/*
 ** Creates a view of a reshaped parent tensor
 **
 ** @param t         Pointer to the parent tensor.
 ** @param ndim      Number of dimensions of parent tensor.
 ** @param shape     An array representing the number of dimensions per axis.
 **
 ** @return          Pointer to parent tensor view.
 */
t_tensr				*tensr_reshape(const t_tensr *t, const int ndim,
						size_t *shape);

/*
 ** Given an array of slice descriptors, creates a sliced
 ** view of the parent tensor.
 **
 ** @param t         Pointer to the parent tensor.
 ** @param n_slices  Number of slices to perform on parent tensor.
 ** @param slices    An array of slice descriptors.
 */
t_tensr				*tensr_slice(const t_tensr *t, const int n_slices,
						const t_slice *slices);

/*
 ** Expands the dimensions of a tensor by inserting a new axis at
 ** the specified position.
 **
 ** Similar to NumPy's np.expand_dims(), this function adds a dimension
 ** of size 1 at the given axis without modifying the underlying data.
 **
 ** @param t         Pointer to the tensor to expand.
 ** @param axis      Position at which to insert the new dimension
 **					(0 to ndim inclusive).
 **
 ** @return          true on success, false on failure.
 */
t_bool				tensr_expand_dims(t_tensr *t, const int axis);

/*
 ** Sets the value at a specific index in the tensor.
 **
 ** @param t         Pointer to the tensor.
 ** @param data      Pointer to the data to set.
 ** @param indices   Array of indices specifying the location.
 **
 ** @return          true on success, false on failure.
 */
t_bool				tensr_set(const t_tensr *t, void *data,
						const size_t *indices);

/*
 ** Gets the value at a specific index in the tensor.
 **
 ** @param t         Pointer to the tensor.
 ** @param indices   Array of indices specifying the location.
 **
 ** @return          Pointer to the data at the specified index,
	or NULL on failure.
 */
void				*tensr_get(const t_tensr *t, const size_t *indices);

/*
 ** Computes the element offset for a given set of indices in a layout.
 **
 ** @param l         Pointer to the tensor layout.
 ** @param indices   Array of indices for each dimension.
 **
 ** @return          The element offset from the base data pointer.
 */
size_t				tensr_offset(const t_layout *l, const size_t *indices);

/*
 ** Checks if a tensor is stored contiguously in memory.
 **
 ** A contiguous tensor has its elements stored in row-major (C) order
 ** with no gaps between dimensions.
 **
 ** @param t         Pointer to the tensor.
 **
 ** @return          true if contiguous, false otherwise.
 */
t_bool				tensr_is_contiguous(const t_tensr *t);

/*
 ** Checks if two tensors are exactly equal.
 **
 ** Both tensors must have the same shape, dtype, and data values.
 **
 ** @param a         Pointer to the first tensor.
 ** @param b         Pointer to the second tensor.
 **
 ** @return          true if equal, false otherwise.
 */
t_bool				tensr_equal(const t_tensr *a, const t_tensr *b);

/*
** Checks if two tensors are equal within a tolerance.
**
** @param a         Pointer to the first tensor.
** @param b         Pointer to the second tensor.
** @param epsilon   Tolerance value for comparison.
**
** @return          true if equal within epsilon, false otherwise.
*/
t_bool				tensr_equal_eps(const t_tensr *a, const t_tensr *b,
						double epsilon);

/*
 ** Frees the memory allocated for a tensor.
 **
 ** If the tensor owns its data, the data pointer is also freed.
 **
 ** @param t         Pointer to the tensor to free.
 */
void				tensr_free(t_tensr *t);

/*
 ** Initializes a tensor iterator for iterating over all elements.
 **
 ** @param t         Pointer to the tensor.
 ** @param it        Pointer to the iterator to initialize.
 **
 ** @return          true on success, false on failure.
 */
t_bool				iter_init(const t_layout *l, t_iter *it);

/*
 ** Advances the iterator to the next element.
 **
 ** @param it        Pointer to the iterator.
 **
 ** @return          true if there are more elements,
	false if iteration is complete.
 */
t_bool				iter_next(t_iter *it);

/*
 ** Resets the iterator to the beginning.
 **
 ** @param it        Pointer to the iterator to reset.
 */
void				iter_reset(t_iter *it);

/*
 ** Allocates and initializes a tensor layout.
 **
 ** @param ndim      Number of dimensions.
 ** @param l         Pointer to the layout to allocate.
 **
 ** @return          true on success, false on failure.
 */
t_bool				layout_alloc(const int ndim, t_layout *l);

/*
 ** Initializes a tensor layout with the given shape and computes strides.
 **
 ** This function allocates memory for the layout and computes row-major
 ** strides based on the provided shape.
 **
 ** @param l         Pointer to the layout to initialize.
 ** @param ndim      Number of dimensions.
 ** @param shape     Array representing the number of elements per axis.
 **
 ** @return          The total number of elements (product of shape),
 **					or 0 on failure.
 */
size_t				layout_init(t_layout *l, const int ndim,
						const size_t *shape);

/*
 ** Copies a layout from source to destination.
 **
 ** @param dst       Pointer to the destination layout.
 ** @param src       Pointer to the source layout.
 **
 ** @return          true on success, false on failure.
 */
t_bool				layout_copy(t_layout *dst, const t_layout *src);

/*
 ** Compares the shapes of two tensor layouts.
 **
 ** @param a        Pointer to layout A.
 ** @param b        Pointer to layout B.
 **
 ** @return         true if shapes are equal, false if otherwise
 */
t_bool				layout_equal(const t_layout *a, const t_layout *b);

t_layout			layout_reduced(const t_layout *l, const t_bool *is_reduced);

/*
 ** Frees the memory allocated for a layout.
 **
 ** @param l         Pointer to the layout to free.
 */
void				layout_free(t_layout *l);

/*
 ** Creates a typed array with 8-bit unsigned integer data.
 **
 ** @param data      Pointer to the data array.
 ** @param len       Length of the array.
 **
 ** @return          A typed array structure.
 */
t_array				arr_u8(uint8_t *data, const size_t len);

/*
 ** Creates a typed array with 32-bit integer data.
 **
 ** @param data      Pointer to the data array.
 ** @param len       Length of the array.
 **
 ** @return          A typed array structure.
 */
t_array				arr_i32(int32_t *data, const size_t len);

/*
 ** Creates a typed array with 32-bit floating point data.
 **
 ** @param data      Pointer to the data array.
 ** @param len       Length of the array.
 **
 ** @return          A typed array structure.
 */
t_array				arr_f32(float *data, const size_t len);

/*
 ** Creates a typed array with 64-bit integer data.
 **
 ** @param data      Pointer to the data array.
 ** @param len       Length of the array.
 **
 ** @return          A typed array structure.
 */
t_array				arr_i64(int64_t *data, const size_t len);

/*
 ** Creates a typed array with 64-bit floating point data.
 **
 ** @param data      Pointer to the data array.
 ** @param len       Length of the array.
 **
 ** @return          A typed array structure.
 */
t_array				arr_f64(double *data, const size_t len);

/*
 ** Creates a typed array with 64-bit complex float data.
 **
 ** @param data      Pointer to the data array.
 ** @param len       Length of the array.
 **
 ** @return          A typed array structure.
 */
t_array				arr_c64(float complex *data, const size_t len);

/*
 ** Creates a typed array with 128-bit complex double data.
 **
 ** @param data      Pointer to the data array.
 ** @param len       Length of the array.
 **
 ** @return          A typed array structure.
 */
t_array				arr_c128(double complex *data, const size_t len);

/*
 ** Fills a tensor with a constant value.
 **
 ** @param t         Pointer to the tensor to fill.
 ** @param value     The constant value to fill the tensor with.
 **
 ** @return          true on success, false on failure.
 */
t_bool				tensr_fill(t_tensr *t, double value);

/*
 ** Creates a scalar complex tensor.
 **
 ** @param n        Complex value for the scalar.
 ** @param dtype   Complex data type (DT_C64 or DT_C128).
 **
 ** @return         Pointer to the scalar complex tensor, or NULL on failure.
 */
t_tensr				*tensr_complex(double complex n, t_dtype dtype);

/*
 ** Fills a complex tensor with a constant value.
 **
 ** @param t         Pointer to the complex tensor to fill.
 ** @param value    Complex value to fill with.
 **
 ** @return         true on success, false on failure.
 */
t_bool				tensr_cfill(t_tensr *t, double complex value);

/*
 ** Creates a complex tensor filled with a constant value.
 **
 ** @param value    Complex value to fill the tensor with.
 ** @param ndim    Number of dimensions.
 ** @param shape   Array representing the number of elements per axis.
 ** @param dtype   Complex data type (DT_C64 or DT_C128).
 **
 ** @return         Pointer to the filled complex tensor, or NULL on failure.
 */
t_tensr				*tensr_cfull(double complex value, const int ndim,
						const size_t *shape, t_dtype dtype);

/*
 ** Creates a complex tensor with evenly spaced values.
 **
 ** @param start    Starting complex value.
 ** @param end      Ending complex value.
 ** @param n        Number of elements in the tensor.
 ** @param dtype    Complex data type (DT_C64 or DT_C128).
 **
 ** @return         Pointer to the complex tensor, or NULL on failure.
 */
t_tensr				*tensr_clinspace(double complex start, double complex end,
						const size_t n, t_dtype dtype);

/*
 ** Scales a complex tensor by a complex constant.
 **
 ** @param t        Pointer to the input complex tensor.
 ** @param value   Complex scaling factor.
 ** @param out     Optional output tensor. If NULL, a new tensor is allocated.
 **
 ** @return         Pointer to the scaled complex tensor, or NULL on failure.
 */
t_tensr				*tensr_cscale(const t_tensr *t, double complex value,
						t_tensr *out);

/*
 ** Computes the complex conjugate of a tensor.
 **
 ** Negates the imaginary part of each complex element.
 **
 ** @param t        Pointer to the input complex tensor.
 ** @param out      Optional output tensor. If NULL, a new tensor is allocated.
 **
 ** @return         Pointer to the conjugate tensor, or NULL on failure.
 */
t_tensr				*tensr_conjugate(const t_tensr *t, t_tensr *out);

/*
 ** Computes the Hermitian (conjugate) dot product.
 **
 ** Uses conjugate of a: sum(conj(a) * b.
 ** This is the standard inner product for complex vectors.
 **
 ** @param a        Pointer to the first complex tensor.
 ** @param b        Pointer to the second complex tensor.
 **
 ** @return         Pointer to the scalar result tensor, or NULL on failure.
 */
t_tensr				*tensr_cdot(const t_tensr *a, const t_tensr *b);

/*
 ** Extracts the real components from a complex tensor.
 **
 ** @param t        Pointer to the input complex tensor.
 ** @param out      Optional output tensor. If NULL, a new tensor is allocated.
 **
 ** @return         Pointer to tensor with real components, or NULL on failure.
 */
t_tensr				*tensr_creal(const t_tensr *t, t_tensr *out);

/*
 ** Extracts the imaginary components from a complex tensor.
 **
 ** @param t        Pointer to the input complex tensor.
 ** @param out      Optional output tensor. If NULL, a new tensor is allocated.
 **
 ** @return         Pointer to tensor with imaginary components, or NULL.
 */
t_tensr				*tensr_cimag(const t_tensr *t, t_tensr *out);

/*
 ** Computes the phase angle (argument) of complex elements.
 **
 ** @param t        Pointer to the input complex tensor.
 ** @param out      Optional output tensor. If NULL, a new tensor is allocated.
 **
 ** @return         Pointer to tensor with phase angles, or NULL on failure.
 */
t_tensr				*tensr_carg(const t_tensr *t, t_tensr *out);

#endif
