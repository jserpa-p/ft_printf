/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_n.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jserpa-p <jserpa-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 10:40:12 by jserpa-p          #+#    #+#             */
/*   Updated: 2021/05/07 11:04:54 by jserpa-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	case_n(t_flags *flags, va_list args, int *count)
{
	if (flags->l == 1)
		*va_arg(args, long int *) = (long int)*count;
	else if (flags->l == 2)
		*va_arg(args, long long int *) = (long long int)*count;
	else if (flags->h == 1)
		*va_arg(args, short int *) = (short int)*count;
	else if (flags->h == 2)
		*va_arg(args, signed char *) = (signed char)*count;
	else
		*va_arg(args, int *) = *count;
	return (0);
}
