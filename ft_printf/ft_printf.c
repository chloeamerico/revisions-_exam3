/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 17:16:31 by camerico          #+#    #+#             */
/*   Updated: 2025/04/01 12:55:26 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	int		i = 0;

	if (str == NULL)
		str = "(null)";
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}

int	ft_putnbr(int n)
{
	int	i = 0;
	
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		i += ft_putchar('-');
		n *= -1;
	}
	if (n > 9)
	{
		i += ft_putnbr(n / 10);
		i += ft_putnbr(n % 10);
	}
	else
		i += ft_putchar(n + 48);
	return (i);
}

int	print_hexa(unsigned int n)
{
	int		len;
	char	*hexa = "0123456789abcdef";

	len = 0;
	if (n >= 16)
		len += print_hexa(n / 16);
	len += ft_putchar(hexa[n % 16]);
	return (len);
}

int	ft_printf(char *str, ...)
{
	va_list		ap;
	int			count = 0;
	int			i = 0;

	va_start(ap, str);
	if (str == NULL)
		return (0);
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (str[i + 1] == 'd')
				count += ft_putnbr(va_arg(ap, int));
			else if (str[i + 1] == 'x')
				count += print_hexa(va_arg(ap, unsigned int));
			else if (str[i + 1] == 's')
				count += ft_putstr(va_arg(ap, char *));
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


// int	ft_putnbr(unsigned int nb, int base)
// {
// 	int		i = nb % base;
// 	char	*base_set = "0123456789abcdef";
// 	int		count = 0;

// 	if (nb / base > 0)
// 		count += ft_putnbr(nb / base, base);
// 	count += ft_putchar(base_set[i]);
// 	return (count);
// }

// int	print_d(int nb)
// {
// 	int		count = 0;

// 	if (nb < 0)
// 	{
// 		count += ft_putchar('-');
// 		if (nb == -2147483648)
// 		{
// 			count += ft_putstr("2147483648");
// 			return (count);
// 		}
// 		nb = -nb;
// 	}
// 	count += ft_putnbr((unsigned int)nb, 10);
// 	return (count);
// }