/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcadinot <zcadinot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 00:04:15 by zcadinot          #+#    #+#             */
/*   Updated: 2025/11/08 00:21:23 by zcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/ft_randint.h"
#include <stdio.h>

int	main(void)
{
	printf("ft_randint(100) = %d\n", ft_randint(100));
	printf("ft_randint(50) = %d\n", ft_randint(50));
	printf("ft_randint(0) = %d\n", ft_randint(0));
	return (0);
}
