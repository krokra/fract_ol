/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psirault <psirault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 13:18:25 by psirault          #+#    #+#             */
/*   Updated: 2025/02/11 13:18:25 by psirault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract_ol.h"

static void	skip_whitespace(const char **str)
{
    while (**str == ' ' || **str == '\t' || **str == '\n' || **str == '\v' || **str == '\f' || **str == '\r')
        (*str)++;
}

static int	get_sign(const char **str)
{
    int	sign;

    sign = 1;
    if (**str == '-')
    {
        sign = -1;
        (*str)++;
    }
    else if (**str == '+')
        (*str)++;
    return (sign);
}

double	ft_atof(const char *str)
{
    double	res;
    double	fraction;
    int		divisor;
    int		sign;

    res = 0.0;
    fraction = 0.0;
    divisor = 1;
    skip_whitespace(&str);
    sign = get_sign(&str);
    while (ft_isdigit(*str))
        res = res * 10.0 + (*str++ - '0');
    if (*str == '.')
    {
        str++;
        while (ft_isdigit(*str))
        {
            fraction = fraction * 10.0 + (*str++ - '0');
            divisor *= 10;
        }
        res += fraction / divisor;
    }
    return (sign * res);
}
