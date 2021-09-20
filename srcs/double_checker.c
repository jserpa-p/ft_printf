/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jserpa-p <jserpa-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 10:58:34 by jserpa-p          #+#    #+#             */
/*   Updated: 2021/05/07 11:05:16 by jserpa-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*double_checker(t_flags *flags, char *d)
{
	if (flags->plus && !flags->zero)
		return (ft_free_function("ft_strjoin", " ", d, 2));
	else if (flags->space && !flags->zero)
		return (ft_free_function("ft_strjoin", "+", d, 2));
	return (d);
}
