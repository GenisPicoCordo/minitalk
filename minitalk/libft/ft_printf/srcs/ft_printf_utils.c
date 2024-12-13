/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpico-co <gpico-co@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 11:18:02 by gpico-co          #+#    #+#             */
/*   Updated: 2024/10/15 16:46:46 by gpico-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putstr_ft(const char *s, unsigned int *counter)
{
	int	i;

	i = 0;
	if (!s)
	{
		*counter += write(1, "(null)", 6);
		return ;
	}
	while (s[i] != '\0')
	{
		*counter += write(1, &s[i], 1);
		i++;
	}
	return ;
}

void	ft_putnbr_ft(int n, unsigned int *counter)
{
	char	res;

	if (n == -2147483648)
	{
		ft_putnbr_ft(n / 10, counter);
		*counter += write(1, "8", 1);
	}
	else if (n < 0)
	{
		*counter += write(1, "-", 1);
		ft_putnbr_ft(-n, counter);
	}
	else
	{
		if (n > 9)
			ft_putnbr_ft(n / 10, counter);
		res = (n % 10) + '0';
		*counter += write(1, &res, 1);
	}
}

void	ft_putunbr_ft(unsigned int n, unsigned int *counter)
{
	char	res;

	if (n > 9)
		ft_putunbr_ft(n / 10, counter);
	res = (n % 10) + '0';
	*counter += write(1, &res, 1);
}

void	ft_puthex_ft(unsigned int hex, char uppercase, unsigned int *counter)
{
	char	*alpha;

	if (uppercase == 'X')
		alpha = "ABCDEF";
	else
		alpha = "abcdef";
	if ((hex / 16) == 0)
	{
		if ((hex % 16) < 10)
			ft_putnbr_ft(hex % 16, counter);
		else
			*counter += write(1, &alpha[hex % 16 - 10], 1);
		return ;
	}
	ft_puthex_ft(hex / 16, uppercase, counter);
	if (hex % 16 < 10)
		ft_putnbr_ft(hex % 16, counter);
	else
		*counter += write(1, &alpha[hex % 16 - 10], 1);
}

void	ft_puthexp_ft(unsigned long hex, unsigned int *counter)
{
	char	*alpha;

	if (hex == 0)
	{
		*counter += write(1, "(nil)", 5);
		return ;
	}
	alpha = "abcdef";
	if ((hex / 16) == 0)
	{
		if ((hex % 16) < 10)
			ft_putnbr_ft(hex % 16, counter);
		else
			*counter += write(1, &alpha[hex % 16 - 10], 1);
		return ;
	}
	ft_puthexp_ft(hex / 16, counter);
	if (hex % 16 < 10)
		ft_putnbr_ft(hex % 16, counter);
	else
		*counter += write(1, &alpha[hex % 16 - 10], 1);
}
