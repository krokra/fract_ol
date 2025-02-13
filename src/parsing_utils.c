/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psirault <psirault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 12:14:10 by psirault          #+#    #+#             */
/*   Updated: 2025/02/13 11:17:43 by psirault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract_ol.h"

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s1 == *s2)
	{
		++s1;
		++s2;
	}
	return (*s1 - *s2);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}

int	ft_isdigit(char c)
{
	if ((c <= '9' && c >= '0'))
		return (1);
	return (0);
}

int	is_julia_param_valid(char *str)
{
	int	i;
	int	dot;

	dot = 0;
	i = 0;
	if (str[0] == '+' || str[0] == '-')
		i++;
	while (str[i] != '\0')
	{
		if (str[i] == '.')
		{
			i++;
			dot++;
		}
		if (ft_isdigit(str[i]) == 0 || dot > 1)
			return (0);
		i++;
	}
	return (1);
}
