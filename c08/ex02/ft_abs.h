/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokaimov <kokaimov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 22:05:00 by kokaimov          #+#    #+#             */
/*   Updated: 2023/10/15 22:10:38 by kokaimov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ABS_H

# define FT_ABS_H
# define ABS(x) \
	({ \
		int abs_value;\
		if (x < 0) { \
			abs_value = -x;\
		} else { \
			abs_value = x;\
		} \
		abs_value; \
	})
#endif