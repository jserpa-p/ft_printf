/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_percentage.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jserpa-p <jserpa-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 10:53:45 by jserpa-p          #+#    #+#             */
/*   Updated: 2021/05/07 11:05:04 by jserpa-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	case_percentage(t_flags *flags)
{
	int		count;

	count = 0;
	if (flags->minus && flags->min_width)
	{
		count += ft_putchar('%');
		count += width_checker(flags, 1);
	}
	else if (flags->min_width)
	{
		count += width_checker(flags, 1);
		count += ft_putchar('%');
	}
	else
		count += ft_putchar('%');
	return (count);
}
