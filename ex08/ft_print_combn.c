/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 07:21:52 by bguyot            #+#    #+#             */
/*   Updated: 2021/11/12 11:46:31 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int		raise(int base, int power);
int		get_digit(int number, int pos);
int		check_number(int number, int n);
void	print_number(int number, int n);

void	ft_print_combn(int n)
{
	int	number;

	number = 0;
	if (!(n < 0 || n > 10))
	{
		while (number < raise(10, n))
		{
			if (check_number(number, n))
			{
				print_number(number, n);
			}
			number ++;
		}
	}
}

int	raise(int base, int power)
{
	if (power == 0)
	{
		return (1);
	}
	else
	{
		return (base * raise(base, power - 1));
	}
}

int	check_number(int number, int n)
{
	int	res;
	int	count;
	int	dig1;
	int	dig2;

	res = 1;
	count = 1;
	while (count < n)
	{
		dig1 = get_digit(number, count);
		dig2 = get_digit(number, count + 1);
		res = res & (dig1 > dig2);
		count++;
	}
	return (res);
}

void	print_number(int number, int n)
{
	char	out_char;
	int		count;

	count = n;
	while (count > 0)
	{
		out_char = '0' + get_digit(number, count);
		write(1, &out_char, 1);
		count --;
	}
	if (get_digit(number, n) != 10 - n)
	{
		write(1, ", ", 2);
	}
}

int	get_digit(int number, int pos)
{
	return (number / raise(10, pos - 1) % 10);
}
