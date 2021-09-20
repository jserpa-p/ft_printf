/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jserpa-p <jserpa-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 14:48:21 by jserpa-p          #+#    #+#             */
/*   Updated: 2021/05/24 14:38:18 by jserpa-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** In order to read the comments properly check if in your file
** interpret settings.json is ("editor.lineNumbers" : "relative")
** and place your indicator in the function that you wish to
*/

#include "includes/ft_printf.h"

t_flags	init(void)
{
	t_flags	flags;

	flags.minus = 0;
	flags.zero = 0;
	flags.star = 0;
	flags.min_width = 0;
	flags.point = 0;
	flags.precision = 0;
	flags.hash = 0;
	flags.space = 0;
	flags.plus = 0;
	flags.l = 0;
	flags.h = 0;
	flags.type = 0;
	return (flags);
}

/*
** This function reads the input and prints everything until it 
** finds the "%". It calls the init() function that initiates the
** flags and when it finds the "%" verifies what type of conversion 
** comes next "get_case() function", as it could be (s, c, d, etc).
** And it verifies the flag needed "set_params()" 
*/

int	input_reader(char *input, va_list args)
{
	int		count;
	int		i;
	t_flags	flags;

	if (!input)
		return (0);
	i = 0;
	count = 0;
	while (input[i])
	{
		flags = init();
		if (input[i] == '%' && input[i + 1])
		{
			i += set_params(&input[i], &flags, args);
			count += which_case(&flags, args, &count);
		}
		else
			count += ft_putchar(input[i]);
		i++;
	}
	return (count);
}

/*
** line2 -- Recieves the argument and saves it
** line3 -- It saves what we want to return
** line4 -- Reads and saves the input of the argument
** line6 -- It saves the copy of fmt into input
** line9 -- It recieves the first argument with fmt in it
** line11 -- It indicates the last argument
** line13 -- Returns the number of characters printed
*/

int	ft_printf(const char *fmt, ...)
{
	va_list	args;
	int		count;
	char	*input;

	input = ft_strdup(fmt);
	if (!input)
		return (0);
	va_start(args, fmt);
	count = input_reader(input, args);
	va_end(args);
	free(input);
	return (count);
}
