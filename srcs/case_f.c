/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_f.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jserpa-p <jserpa-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 10:34:46 by jserpa-p          #+#    #+#             */
/*   Updated: 2021/05/07 11:04:46 by jserpa-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	precision_checker(t_flags *flags, double d)
{
	if (!flags->point)
		flags->precision = 6;
	else if (!flags->precision && !d)
		flags->precision = -1;
}

static char	*zero_checker(t_flags *flags, char *d, int *count)
{
	if (!(ft_strncmp("inf", d, 3)) || (!(ft_strncmp("-inf", d, 4))
			|| (!(ft_strncmp("nan", d, 3)))))
		flags->zero = 0;
	else if (d[0] == '-' && flags->zero)
	{
		*count += ft_putchar('-');
		d = ft_free_function("ft_substr", d, 1, (int)ft_strlen(d));
		flags->min_width -= 1;
	}
	else if (flags->space && flags->zero)
	{
		*count += ft_putchar(' ');
		flags->min_width -= 1;
	}
	else if (flags->plus && flags->zero)
	{
		*count += ft_putchar('+');
		flags->min_width -= 1;
	}
	return (d);
}

int	case_f(t_flags *flags, va_list args)
{
	int		count;
	char	*d;
	double	n;

	count = 0;
	n = va_arg(args, double);
	precision_checker(flags, n);
	d = ft_ftoa(n, flags->precision);
	d = zero_checker(flags, d, &count);
	d = double_checker(flags, d);
	if (flags->minus && flags->min_width)
	{
		count += ft_putstr(d);
		count += width_checker(flags, (int)ft_strlen(d));
	}
	else if (flags->min_width)
	{
		count += width_checker(flags, (int)ft_strlen(d));
		count += ft_putstr(d);
	}
	else
		count += ft_putstr(d);
	free(d);
	return (count);
}
