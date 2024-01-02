/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 07:06:13 by momrane           #+#    #+#             */
/*   Updated: 2023/11/16 14:03:48 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				i;
	char			*ptr;
	char			*res;
	unsigned char	val;

	i = 0;
	ptr = (char *)s;
	res = NULL;
	val = (unsigned char)c;
	while (*ptr != '\0')
	{
		if (*ptr == val)
			res = ptr;
		ptr++;
		i++;
	}
	if (res != NULL)
		return (res);
	if (*ptr == val)
		res = ptr;
	return (res);
}

// #include <stdio.h>

// int main(void)
// {
// 	const char *str = "Hello, World!";
// 	int ch = 'o';
// 	char *result = ft_strrchr(str, ch);

// 	if (result != NULL) {
// 		printf("'%c' trouvé à la pos : %ld\n", ch, result - str);
// 	} else {
// 		printf("'%c' pas trouvé...\n", ch);
// 	}

// 	return (0);
// }