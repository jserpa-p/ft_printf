/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jserpa-p <jserpa-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 10:54:26 by jserpa-p          #+#    #+#             */
/*   Updated: 2021/05/07 11:05:07 by jserpa-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char	*precision_checker(t_flags *flags, char *s)
{
	if (!flags->precision && flags->point)
		s = ft_strdup("");
	else if (flags->precision < (int)ft_strlen(s) && flags->point)
		s = ft_substr(s, 0, flags->precision);
	else
		s = ft_strdup(s);
	return (s);
}

int	case_s(t_flags *flags, va_list args)
{
	int		count;
	char	*s;

	count = 0;
	s = arg_conversions(flags, args);
	if (!s)
		s = "(null)";
	s = precision_checker(flags, s);
	if (flags->minus && flags->min_width)
	{
		count += ft_putstr(s);
		count += width_checker(flags, (int)ft_strlen(s));
	}
	else if (flags->min_width)
	{
		count += width_checker(flags, (int)ft_strlen(s));
		count += ft_putstr(s);
	}
	else
		count += ft_putstr(s);
	free(s);
	return (count);
}
