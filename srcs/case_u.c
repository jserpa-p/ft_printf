/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jserpa-p <jserpa-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 10:55:28 by jserpa-p          #+#    #+#             */
/*   Updated: 2021/05/07 11:05:11 by jserpa-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	case_u(t_flags *flags, va_list args)
{
	int		count;
	char	*nbr;

	count = 0;
	nbr = arg_conversions(flags, args);
	if (flags->point)
		flags->zero = 0;
	nbr = number_checker(flags, nbr);
	if (flags->minus && flags->min_width)
	{
		count += ft_putstr(nbr);
		count += width_checker(flags, ft_strlen(nbr));
	}
	else if (flags->min_width)
	{
		count += width_checker(flags, ft_strlen(nbr));
		count += ft_putstr(nbr);
	}
	else
		count += ft_putstr(nbr);
	free(nbr);
	return (count);
}
