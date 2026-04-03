/* ************************************************************************** */
/*                                                                            */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +:++:+         +:      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 16:00:00 by sgadinga          #+#   #+        #+#    */
/*   Updated: 2026/04/02 13:02:04 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TENSR_RT_MATH_H
# define TENSR_RT_MATH_H

# include <math.h>
# include <tensr_rt/rt.h>

/* Elementwise Operations */

t_vec3		vec3_add(t_vec3 a, t_vec3 b);
void		vec3_add_ip(t_vec3 *a, t_vec3 b);

t_vec3		vec3_sub(t_vec3 a, t_vec3 b);
void		vec3_sub_ip(t_vec3 *a, t_vec3 b);

t_vec3		vec3_mul(t_vec3 a, t_vec3 b);
void		vec3_mul_ip(t_vec3 *a, t_vec3 b);

t_vec3		vec3_div(t_vec3 a, t_vec3 b);
void		vec3_div_ip(t_vec3 *a, t_vec3 b);

t_vec3		vec3_neg(t_vec3 v);
void		vec3_neg_ip(t_vec3 *v);

t_vec3		vec3_abs(t_vec3 v);
void		vec3_abs_ip(t_vec3 *v);

/* Linear Algebra Operations */

float		vec3_dot(t_vec3 a, t_vec3 b);

t_vec3		vec3_cross(t_vec3 a, t_vec3 b);

float		vec3_magnitude(t_vec3 v);
float		vec3_magnitude_sq(t_vec3 v);

t_vec3		vec3_normalize(t_vec3 v);
void		vec3_normalize_ip(t_vec3 *v);

t_vec3		vec3_scale(t_vec3 v, float n);
void		vec3_scale_ip(t_vec3 *v, float n);

t_vec3		vec3_lerp(t_vec3 curr, t_vec3 target, const float t);
void		vec3_lerp_ip(t_vec3 *curr, t_vec3 target, const float t);

t_project	vec3_project(t_vec3 v, t_vec3 axis);
bool		vec3_equal_eps(t_vec3 a, t_vec3 b, const float eps);

#endif
