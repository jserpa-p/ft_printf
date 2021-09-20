/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jserpa-p <jserpa-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 10:59:16 by jserpa-p          #+#    #+#             */
/*   Updated: 2021/05/24 16:25:21 by jserpa-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char	*space_checker(t_flags *flags, char *nbr)
{
	while (flags->precision > (int)ft_strlen(nbr))
		nbr = ft_free_function("ft_strjoin", "0", nbr, 2);
	nbr = ft_free_function("ft_strjoin", " ", nbr, 2);
	return (nbr);
}

static char	*positive_checker(t_flags *flags, char *nbr)
{
	while (flags->precision > (int)ft_strlen(nbr))
		nbr = ft_free_function("ft_strjoin", "0", nbr, 2);
	nbr = ft_free_function("ft_strjoin", "+", nbr, 2);
	return (nbr);
}

static char	*negative_checker(t_flags *flags, char *nbr)
{
	nbr = ft_free_function("ft_substr", nbr, 1, (int)ft_strlen(nbr));
	while (flags->precision > (int)ft_strlen(nbr))
		nbr = ft_free_function("ft_strjoin", "0", nbr, 2);
	nbr = ft_free_function("ft_strjoin", "-", nbr, 2);
	return (nbr);
}

static char	*hash_checker(t_flags *flags, char *nbr)
{
	if (flags->type == 'x' || flags->type == 'X')
		nbr = ft_free_function("ft_substr", nbr, 2, (int)ft_strlen(nbr));
	if (flags->type == 'o')
		nbr = ft_free_function("ft_substr", nbr, 1, (int)ft_strlen(nbr));
	while (flags->precision > (int)ft_strlen(nbr))
		nbr = ft_free_function("ft_strjoin", "0", nbr, 2);
	if (flags->type == 'x' && !flags->zero)
		nbr = ft_free_function("ft_strjoin", "0x", nbr, 2);
	else if (flags->type == 'X' && !flags->zero)
		nbr = ft_free_function("ft_strjoin", "0X", nbr, 2);
	else if (flags->type == 'o' && !flags->zero)
		nbr = ft_free_function("ft_strjoin", "0", nbr, 2);
	return (nbr);
}

char	*number_checker(t_flags *flags, char *nbr)
{
	if (!ft_strncmp(nbr, "0", 2) && flags->point && !flags->precision)
		nbr = ft_free_function("ft_strdup", nbr, "");
	if (nbr[0] == '-')
		return (negative_checker(flags, nbr));
	else if (flags->hash && (flags->type == 'x' || flags->type == 'X'
			|| flags->type == 'o'))
		return (hash_checker(flags, nbr));
	else if (flags->plus && !flags->zero)
		return (positive_checker(flags, nbr));
	else if (flags->space && !flags->zero)
		return (space_checker(flags, nbr));
	while (flags->precision > (int)ft_strlen(nbr))
		nbr = ft_free_function("ft_strjoin", "0", nbr, 2);
	return (nbr);
}
