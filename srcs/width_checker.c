/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jserpa-p <jserpa-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 11:01:30 by jserpa-p          #+#    #+#             */
/*   Updated: 2021/05/07 11:05:34 by jserpa-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	width_checker(t_flags *flags, int len)
{
	int		count;

	count = 0;
	while (flags->zero && flags->min_width-- > len)
		count += ft_putchar('0');
	while (!flags->zero && flags->min_width-- > len)
		count += ft_putchar(' ');
	return (count);
}
