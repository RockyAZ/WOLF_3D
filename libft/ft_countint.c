/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaporoz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 15:03:13 by azaporoz          #+#    #+#             */
/*   Updated: 2018/04/04 15:05:28 by azaporoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_countint(int n)
{
	int i;

	if (n == -2147483648)
		return (0);
	i = 0;
	if (n == 0)
		i++;
	else
	{
		if (n < 0)
		{
			i++;
			n *= -1;
		}
		while (n > 0)
		{
			i++;
			n /= 10;
		}
	}
	return (i);
}
