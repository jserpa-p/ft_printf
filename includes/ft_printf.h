/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jserpa-p <jserpa-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 14:49:30 by jserpa-p          #+#    #+#             */
/*   Updated: 2021/05/25 15:56:18 by jserpa-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define D "0123456789"
# define H "0123456789abcdef"
# define UH "0123456789ABCDEF"
# define O "01234567"

# include "../libft/libft.h"
# include <stdarg.h>
# include <stdio.h>

typedef struct s_flags
{
	int		minus;
	int		plus;
	int		zero;
	int		star;
	int		point;
	int		hash;
	int		space;
	int		min_width;
	int		precision;
	char	type;
	int		l;
	int		h;
}			t_flags;

int		ft_printf(const char *fmt, ...);
int		input_reader(char *input, va_list arg);
int		set_params(char *input, t_flags *flags, va_list args);
void	star_checker(t_flags *flags, int arg);
int		digit_checker(t_flags *flags, char *input);
void	minus_checker(t_flags *flags);
void	flags_checker(char input, t_flags *flags, va_list args);
int		lh_checker(char *input, t_flags *flags);
int		width_checker(t_flags *flags, int len);
int		which_case(t_flags *flags, va_list args, int *count);
int		case_c(t_flags *flags, va_list args);
int		case_s(t_flags *flags, va_list args);
int		case_p(t_flags *flags, va_list args);
int		case_d(t_flags *flags, va_list args);
int		case_i(t_flags *flags, va_list args);
int		case_u(t_flags *flags, va_list args);
int		case_x(t_flags *flags, va_list args);
int		case_percentage(t_flags *flags);
int		case_n(t_flags *flags, va_list args, int *count);
int		case_f(t_flags *flags, va_list args);
int		case_g(t_flags *flags, va_list args);
int		case_e(t_flags *flags, va_list args);
int		case_o(t_flags *flags, va_list args);
char	*arg_conversions(t_flags *flags, va_list args);
char	*number_checker(t_flags *flags, char *nbr);
char	*double_checker(t_flags *flags, char *d);

#endif
