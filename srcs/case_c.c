/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jserpa-p <jserpa-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 10:26:00 by jserpa-p          #+#    #+#             */
/*   Updated: 2021/05/07 11:04:34 by jserpa-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "../includes/ft_printf.h"

int	case_c(t_flags *flags, va_list args)
{
	int		count;

	count = 0;
	if (flags->minus && flags->min_width)
	{
		count += ft_putchar(va_arg(args, int));
		count += width_checker(flags, 1);
	}
	else if (flags->min_width)
	{
		count += width_checker(flags, 1);
		count += ft_putchar(va_arg(args, int));
	}
	else
		count += ft_putchar(va_arg(args, int));
	return (count);
}
