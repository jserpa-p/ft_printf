/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_params.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jserpa-p <jserpa-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 17:38:55 by jserpa-p          #+#    #+#             */
/*   Updated: 2021/05/14 15:12:08 by jserpa-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	set_params(char *input, t_flags *flags, va_list args)
{
	int		i;

	i = 0;
	while (input[i++])
	{
		if (input[i] == '-' || input[i] == '0' || input[i] == '.'
			|| input[i] == '*' || input[i] == '#' || input[i] == ' '
			|| input[i] == '+')
			flags_checker(input[i], flags, args);
		else if ((input[i] == 'l' && !flags->l)
			|| (input[i] == 'h' && !flags->h))
			i += lh_checker(&input[i], flags);
		else if (ft_isdigit(input[i]))
			i += digit_checker(flags, &input[i]);
		else if (ft_strchr("cspdiuxX%nfgeo", input[i]) && i != 0)
		{
			flags->type = input[i];
			minus_checker(flags);
			return (i);
		}
		else if (ft_isalpha(input[i]))
			break ;
	}
	return (0);
}
