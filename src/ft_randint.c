/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_randint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcadinot <zcadinot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 00:04:37 by zcadinot          #+#    #+#             */
/*   Updated: 2025/11/08 01:34:22 by zcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_randint.h"

unsigned long	ft_cpu_cycles(void)
{
	unsigned int	lo;
	unsigned int	hi;

	__asm__(
		"rdtsc\n\t"
		: "=a"(lo), "=d"(hi)
		);
	return (((unsigned long)hi << 32) | lo);
}

int	ft_randint(int max)
{
	static unsigned long	seed;
	int						local;
	unsigned long			mix;

	if (max <= 0)
		max = 1;
	mix = (unsigned long)&local
		^ (unsigned long)&max
		^ (unsigned long)&ft_randint
		^ ft_cpu_cycles();
	seed += mix + 0x9e3779b97f4a7c15UL;
	return ((seed % (unsigned long)max));
}
