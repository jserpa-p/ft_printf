/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_o.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jserpa-p <jserpa-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 10:41:00 by jserpa-p          #+#    #+#             */
/*   Updated: 2021/05/07 11:04:57 by jserpa-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char	*hash_checker(t_flags *flags, char *oct, int *count)
{
	if (!(flags->hash && ft_strncmp("0", oct, 2)))
	{
		flags->hash = 0;
		return (oct);
	}
	oct = ft_free_function("ft_strjoin", "0", oct, 2);
	if (flags->point)
		flags->zero = 0;
	else if (flags->zero)
	{
		*count += ft_putchar('0');
		flags->min_width -= 1;
	}
	return (oct);
}

int	case_o(t_flags *flags, va_list args)
{
	int		count;
	char	*oct;

	count = 0;
	oct = arg_conversions(flags, args);
	oct = hash_checker(flags, oct, &count);
	if (flags->point)
		flags->zero = 0;
	oct = number_checker(flags, oct);
	if (flags->minus && flags->min_width)
	{
		count += ft_putstr(oct);
		count += width_checker(flags, (int)ft_strlen(oct));
	}
	else if (flags->min_width)
	{
		count += width_checker(flags, (int)ft_strlen(oct));
		count += ft_putstr(oct);
	}
	else
		count += ft_putstr(oct);
	free(oct);
	return (count);
}
