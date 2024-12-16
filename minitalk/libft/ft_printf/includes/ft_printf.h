/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpico-co <gpico-co@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 11:17:51 by gpico-co          #+#    #+#             */
/*   Updated: 2024/12/13 12:46:46 by gpico-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../../libft.h"
# include <stdarg.h>
# include <unistd.h>
# include <limits.h>

//MAIN functions
int		ft_printf(const char *str, ...);

void	ft_putstr_ft(const char *s, unsigned int *counter);
void	ft_putnbr_ft(int n, unsigned int *counter);
void	ft_putunbr_ft(unsigned int n, unsigned int *counter);
void	ft_puthex_ft(unsigned int hex, char uppercase, unsigned int *counter);
void	ft_puthexp_ft(unsigned long hex, unsigned int *counter);

#endif
