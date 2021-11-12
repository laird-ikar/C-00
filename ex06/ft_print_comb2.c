/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 15:00:53 by bguyot            #+#    #+#             */
/*   Updated: 2021/11/11 16:15:32 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	print_ints(int nb1, int nb2);

void	ft_print_comb2(void)
{
	int	nb1;
	int	nb2;

	nb1 = 0;
	while (nb1 < 100)
	{
		nb2 = 0;
		while (nb2 < 100)
		{
			if (nb1 < nb2)
			{
				print_ints(nb1, nb2);
			}
			nb2++;
		}
		nb1++;
	}
}

void	print_ints(int nb1, int nb2)
{
	int	magic_chars[4];

	magic_chars[0] = (nb1 - nb1 % 10) / 10 + '0';
	magic_chars[1] = nb1 % 10 + '0';
	magic_chars[2] = (nb2 - nb2 % 10) / 10 + '0';
	magic_chars[3] = nb2 % 10 + '0';
	write(1, &magic_chars[0], 1);
	write(1, &magic_chars[1], 1);
	write(1, " ", 1);
	write(1, &magic_chars[2], 1);
	write(1, &magic_chars[3], 1);
	if (nb1 != 98)
	{
		write(1, ", ", 2);
	}
}
