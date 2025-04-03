/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myprintf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chloeamerico <chloeamerico@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 16:23:45 by chloeameric       #+#    #+#             */
/*   Updated: 2025/04/01 18:23:24 by chloeameric      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

int	ft_putchar(char c)
{
	return(write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	int	i = 0;
	
	if (str == NULL)
		str = "(null)";
	while(str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}

int	ft_putnbr(int nb)
{
	int	i = 0;
	
	if (nb == -2147483648)
		return(write(1, "-2147483648", 11));
	if (nb < 0)
	{
		i += ft_putchar('-');
		nb *= -1;
	}
	if (nb > 9)
	{
		i += ft_putnbr(nb / 10);
		i += ft_putnbr(nb % 10);
	}
	else
		i += ft_putchar(nb + 48);
	return (i);
}

int	print_hexa(unsigned int nb)
{
	int	i = 0;
	char *hexa = "0123456789abcdef";
	
	if (nb > 16)
		i += print_hexa(nb / 16);
	i += ft_putchar(hexa[nb % 16]);
	return (i);	
}

int	ft_printf(char *str, ...)
{
	va_list	ap;
	int	i = 0;
	int	count = 0;

	va_start(ap, str);
	if (str == NULL)
		return (0);
	while(str[i])
	{
		if (str[i] == '%')
		{
			if (str[i + 1] == 'd')
				count += ft_putnbr(va_arg(ap, int));
			else if (str[i + 1] == 'x')
				count += print_hexa(va_arg(ap, unsigned int));
			else if (str[i + 1] == 's')
				count += ft_putnbr(va_arg(ap, int));
			i++;
		}
		else
			count += ft_putchar(str[i]);
		i++;
	}
	va_end(ap);
	return (count);
}

int	main(void)
{
	int nb = -2147483648;
	char *str = "abcde";
	int nb2 = 15;
	
	ft_printf("int : %d\n", nb);
	ft_printf("char : %s\n", str);
	ft_printf("hexa : %x\n", nb2);
	return (0);
}