/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_conversions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jserpa-p <jserpa-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 10:18:02 by jserpa-p          #+#    #+#             */
/*   Updated: 2021/05/07 11:04:28 by jserpa-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "../includes/ft_printf.h"

static char	*h_checker(t_flags *flags, va_list args)
{
	if (flags->h == 2 && (flags->type == 'd' || flags->type == 'i'))
		return (ft_itoa((signed char)va_arg(args, int)));
	if (flags->h == 2 && flags->type == 'x')
		return (ft_itoa_base((unsigned char)va_arg(args, unsigned int), H));
	if (flags->h == 2 && flags->type == 'X')
		return (ft_itoa_base((unsigned char)va_arg(args, unsigned int), UH));
	if (flags->h == 2 && flags->type == 'u')
		return (ft_itoa_base((unsigned char)va_arg(args, unsigned int), D));
	if (flags->h == 2 && flags->type == 'o')
		return (ft_itoa_base((unsigned char)va_arg(args, unsigned int), O));
	if (flags->h == 1 && (flags->type == 'd' || flags->type == 'i'))
		return (ft_itoa((short int)va_arg(args, int)));
	if (flags->h == 1 && flags->type == 'x')
		return (ft_itoa_base((unsigned short)va_arg(args, unsigned int), H));
	if (flags->h == 1 && flags->type == 'X')
		return (ft_itoa_base((unsigned short)va_arg(args, unsigned int), UH));
	if (flags->h == 1 && flags->type == 'u')
		return (ft_itoa_base((unsigned short)va_arg(args, unsigned int), D));
	if (flags->h == 1 && flags->type == 'o')
		return (ft_itoa_base((unsigned short)va_arg(args, unsigned int), O));
	return (0);
}

static char	*l_checker(t_flags *flags, va_list args)
{
	if (flags->l == 1 && (flags->type == 'd' || flags->type == 'i'))
		return (ft_llitoa((long int)va_arg(args, long int)));
	if (flags->l == 1 && flags->type == 'x')
		return (ft_llitoa_base((unsigned long)va_arg(args, unsigned long), H));
	if (flags->l == 1 && flags->type == 'X')
		return (ft_llitoa_base((unsigned long)va_arg(args, unsigned long), UH));
	if (flags->l == 1 && flags->type == 'u')
		return (ft_llitoa_base((unsigned long)va_arg(args, unsigned long), D));
	if (flags->l == 1 && flags->type == 'o')
		return (ft_llitoa_base((unsigned long)va_arg(args, unsigned long), O));
	if (flags->l == 2 && (flags->type == 'd' || flags->type == 'i'))
		return (ft_llitoa((long long)va_arg(args, long long)));
	if (flags->l == 2 && flags->type == 'x')
		return (ft_llitoa_base(va_arg(args, unsigned long long), H));
	if (flags->l == 2 && flags->type == 'X')
		return (ft_llitoa_base(va_arg(args, unsigned long long), UH));
	if (flags->l == 2 && flags->type == 'u')
		return (ft_llitoa_base(va_arg(args, unsigned long long), D));
	if (flags->l == 2 && flags->type == 'o')
		return (ft_llitoa_base(va_arg(args, unsigned long long), O));
	return (0);
}

char	*arg_conversions(t_flags *flags, va_list args)
{
	if (flags->h)
		return (h_checker(flags, args));
	if (flags->l)
		return (l_checker(flags, args));
	if (flags->type == 's')
		return (va_arg(args, char *));
	if (flags->type == 'd' || flags->type == 'i')
		return (ft_itoa(va_arg(args, int)));
	if (flags->type == 'u')
		return (ft_itoa_base(va_arg(args, unsigned int), D));
	if (flags->type == 'x')
		return (ft_itoa_base(va_arg(args, unsigned int), H));
	if (flags->type == 'o')
		return (ft_itoa_base(va_arg(args, unsigned int), O));
	if (flags->type == 'X')
		return (ft_itoa_base(va_arg(args, unsigned int), UH));
	if (flags->type == 'p')
		return (ft_llitoa_base((unsigned long)va_arg(args, unsigned long), H));
	return (NULL);
}
