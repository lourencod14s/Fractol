/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldias-fe <ldias-fe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 19:49:46 by ldias-fe          #+#    #+#             */
/*   Updated: 2023/02/02 22:03:30 by ldias-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

void	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (s[i] == '\0')
		return ;
	while (s[i] != '\0')
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0' && i < n)
	{
		if (i < (n - 1))
			i++;
		else
			return (0);
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

double	ft_atof(const char *nptr)
{
	int		i;
	int		sign;
	double	num;
	double	power;

	i = 0;
	sign = 1;
	if (nptr[i++] == '-')
		sign = -1;
	num = 0.0;
	power = 1.0;
	while (ft_isdigit(nptr[i]) == 1)
		num = num * 10 + (nptr[i++] - 48);
	if (nptr[i] == '.')
		i++;
	while (ft_isdigit(nptr[i]) == 1)
	{
		num = num * 10 + (nptr[i++] - 48);
		power *= 10;
	}
	return (num / power * sign);
}
