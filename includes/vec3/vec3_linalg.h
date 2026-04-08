/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_linalg.h                                      :::      :::     */
/*                                                    :::       */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +:++:+                   */
/*                                                +:++:+                   */
/*   Created: 2026/04/08 23:00:00 by sgadinga          #+#   #+              */
/*   Updated: 2026/04/08 23:00:00 by sgadinga         ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC3_LINALG_H
# define VEC3_LINALG_H

# include <vec3/vec3.h>
# include <vec3/vec3_elem.h>

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

t_vec3		vec3_slerp(t_vec3 curr, t_vec3 target, const float t);
void		vec3_slerp_ip(t_vec3 *curr, t_vec3 target, const float t);

t_vec3		vec3_clamp(t_vec3 v, const float min, const float max);
void		vec3_clamp_ip(t_vec3 *v, const float min, const float max);

t_project	vec3_project(t_vec3 v, t_vec3 axis);

#endif