/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_roundup_number.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jserpa-p <jserpa-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 12:13:20 by jserpa-p          #+#    #+#             */
/*   Updated: 2021/05/07 12:13:36 by jserpa-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*integral(char *nbr, int i)
{
	char	*temp;

	if (nbr[i] > '5' || (nbr[i] == '5' && (nbr[i - 2] % 2) != 0))
	{
		while (nbr[i - 2] == '9')
		{
			nbr[i - 2] = '0';
			i--;
		}
		if (i - 2 >= 0)
			nbr[i - 2] += 1;
		else
		{
			nbr = ft_free_function("ft_strjoin", "0", nbr, 2);
			nbr[i - 1] += 1;
		}
	}
	temp = ft_substr(nbr, 0, (int)ft_strlen(nbr) - 2);
	free(nbr);
	return (temp);
}

char	*ft_roundup_number(char *nbr)
{
	int		i;
	int		flag;
	char	*temp;

	i = ft_strlen(nbr) - 1;
	flag = 0;
	if (nbr[i - 1] == '.')
		return (integral(nbr, i));
	else if (nbr[i] > '5')
	{
		while (nbr[i] == '9')
		{
			nbr[i] = '0';
			i--;
			flag = 1;
		}
		if (!flag)
			nbr[--i] += 1;
		else
			nbr[i] += 1;
	}
	temp = ft_substr(nbr, 0, (int)ft_strlen(nbr) - 1);
	free(nbr);
	return (temp);
}
