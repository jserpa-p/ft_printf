/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jserpa-p <jserpa-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 10:52:33 by jserpa-p          #+#    #+#             */
/*   Updated: 2021/05/07 11:05:01 by jserpa-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*append_ptr(char *ptr)
{
	char	*temp;

	temp = ptr;
	ptr = ft_strjoin("0x", ptr);
	free(temp);
	return (ptr);
}

int	case_p(t_flags *flags, va_list args)
{
	int		count;
	char	*ptr;

	count = 0;
	ptr = arg_conversions(flags, args);
	if (flags->point)
		flags->zero = 0;
	ptr = number_checker(flags, ptr);
	ptr = append_ptr(ptr);
	if (flags->minus && flags->min_width)
	{
		count += ft_putstr(ptr);
		count += width_checker(flags, (int)ft_strlen(ptr));
	}
	else if (flags->min_width)
	{
		count += width_checker(flags, (int)ft_strlen(ptr));
		count += ft_putstr(ptr);
	}
	else
		count += ft_putstr(ptr);
	free(ptr);
	return (count);
}
