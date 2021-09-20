/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   which_case.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jserpa-p <jserpa-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 10:37:24 by jserpa-p          #+#    #+#             */
/*   Updated: 2021/05/07 11:05:31 by jserpa-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	which_case(t_flags *flags, va_list args, int *count)
{
	if (flags->type == 'c')
		return (case_c(flags, args));
	else if (flags->type == 's')
		return (case_s(flags, args));
	else if (flags->type == 'p')
		return (case_p(flags, args));
	else if (flags->type == 'd' || flags->type == 'i')
		return (case_d(flags, args));
	else if (flags->type == 'u')
		return (case_u(flags, args));
	else if (flags->type == 'x' || flags->type == 'X')
		return (case_x(flags, args));
	else if (flags->type == '%')
		return (case_percentage(flags));
	else if (flags->type == 'n')
		return (case_n(flags, args, count));
	else if (flags->type == 'f')
		return (case_f(flags, args));
	else if (flags->type == 'g')
		return (case_g(flags, args));
	else if (flags->type == 'e')
		return (case_e(flags, args));
	else if (flags->type == 'o')
		return (case_o(flags, args));
	return (0);
}
