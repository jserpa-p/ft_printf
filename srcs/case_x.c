/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jserpa-p <jserpa-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 10:56:21 by jserpa-p          #+#    #+#             */
/*   Updated: 2021/05/07 11:05:13 by jserpa-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char	*hash_checker(t_flags *flags, char *hex, int *count)
{
	if (!(flags->hash && ft_strncmp("0", hex, 2)))
	{
		flags->hash = 0;
		return (hex);
	}
	if (flags->type == 'x')
		hex = ft_free_function("ft_strjoin", "0x", hex, 2);
	else
		hex = ft_free_function("ft_strjoin", "0X", hex, 2);
	if (flags->point)
		flags->zero = 0;
	else if (flags->zero)
	{
		if (flags->type == 'x')
			*count += ft_putstr("0x");
		else
			*count += ft_putstr("0X");
		flags->min_width -= 2;
	}
	return (hex);
}

int	case_x(t_flags *flags, va_list args)
{
	int		count;
	char	*hex;

	count = 0;
	hex = arg_conversions(flags, args);
	hex = hash_checker(flags, hex, &count);
	if (flags->point)
		flags->zero = 0;
	hex = number_checker(flags, hex);
	if (flags->minus && flags->min_width)
	{
		count += ft_putstr(hex);
		count += width_checker(flags, (int)ft_strlen(hex));
	}
	else if (flags->min_width)
	{
		count += width_checker(flags, (int)ft_strlen(hex));
		count += ft_putstr(hex);
	}
	else
		count += ft_putstr(hex);
	free(hex);
	return (count);
}
