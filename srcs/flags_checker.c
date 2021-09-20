/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jserpa-p <jserpa-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 11:02:03 by jserpa-p          #+#    #+#             */
/*   Updated: 2021/05/24 16:14:47 by jserpa-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	star_checker(t_flags *flags, int arg)
{
	if (!flags->point)
		flags->min_width = arg;
	else
		flags->precision = arg;
	flags->star += 0;
}

int	digit_checker(t_flags *flags, char *input)
{
	int		i;

	i = 0;
	if (!flags->point)
		flags->min_width = ft_atoi(input);
	else
		flags->precision = ft_atoi(input);
	while (ft_isdigit(input[i]))
		i++;
	return (--i);
}

void	minus_checker(t_flags *flags)
{
	if (flags->min_width < 0)
	{
		flags->minus = 1;
		flags->min_width *= -1;
	}
	if (flags->minus && flags->zero)
		flags->zero = 0;
	if (flags->space && flags->plus)
		flags->space = 0;
	if (!(flags->type == 'd' || flags->type == 'i'
			|| flags->type == 'u' || flags->type == 'x'
			||flags->type == 'X' || flags->type == 'o'))
		flags->h = 0;
	if (!(flags->type == 'd' || flags->type == 'i'
			|| flags->type == 'u' || flags->type == 'x'
			||flags->type == 'X' || flags->type == 's'
			|| flags->type == 'c' || flags->type == 'o'))
		flags->l = 0;
}

void	flags_checker(char input, t_flags *flags, va_list args)
{
	if (input == '-')
		flags->minus = 1;
	else if (input == '0' && !flags->minus && !flags->point)
		flags->zero = 1;
	else if (input == '*')
		star_checker(flags, va_arg(args, int));
	else if (input == '.')
		flags->point = 1;
	else if (input == '#')
		flags->hash = 1;
	else if (input == ' ')
		flags->space = 1;
	else if (input == '+')
		flags->plus = 1;
}

int	lh_checker(char *input, t_flags *flags)
{
	int		i;

	i = 0;
	if (input[i] == 'l' && !flags->l && !flags->h)
	{
		if (input[i + 1] == 'l')
		{
			flags->l += 1;
			i++;
		}
		flags->l += 1;
	}
	else if (input[i] == 'h' && !flags->h && !flags->l)
	{
		if (input[i + 1] == 'h')
		{
			flags->h += 1;
			i++;
		}
		flags->h += 1;
	}
	return (i);
}
