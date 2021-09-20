/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jserpa-p <jserpa-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 10:31:43 by jserpa-p          #+#    #+#             */
/*   Updated: 2021/05/24 15:38:54 by jserpa-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char	*zero_checker(t_flags *flags, char *nbr, int *count)
{
	if (flags->point)
		flags->zero = 0;
	else if (nbr[0] == '-' && flags->zero)
	{
		*count += ft_putchar('-');
		nbr = ft_free_function("ft_substr", nbr, 1, (int)ft_strlen(nbr));
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
	return (nbr);
}

int	case_d(t_flags *flags, va_list args)
{
	int		count;
	char	*nbr;

	count = 0;
	nbr = arg_conversions(flags, args);
	nbr = zero_checker(flags, nbr, &count);
	nbr = number_checker(flags, nbr);
	if (flags->minus && flags->min_width)
	{
		count += ft_putstr(nbr);
		count += width_checker(flags, (int)ft_strlen(nbr));
	}
	else if (flags->min_width)
	{
		count += width_checker(flags, (int)ft_strlen(nbr));
		count += ft_putstr(nbr);
	}
	else
		count += ft_putstr(nbr);
	free(nbr);
	return (count);
}
