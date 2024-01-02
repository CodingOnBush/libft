/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 08:27:35 by momrane           #+#    #+#             */
/*   Updated: 2023/11/17 20:06:15 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

static int	ft_nb_words(char const *s, char c)
{
	int	count;
	int	i;
	int	flag;

	count = 0;
	i = 0;
	flag = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			flag = 1;
			count++;
			while (s[i] != c && s[i] != '\0')
				i++;
			flag = 0;
		}
		else
			i++;
	}
	return (count);
}

static char	*ft_strndup(char const *src, int n)
{
	char	*res;
	int		i;

	if (!src)
		return (NULL);
	res = (char *)malloc(sizeof(char) * (n + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (i < n)
	{
		res[i] = src[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

static int	ft_wordlen(char const *start, char c)
{
	int	i;

	i = 0;
	while (start[i] != '\0' && start[i] != c)
		i++;
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		words;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	words = ft_nb_words(s, c);
	res = malloc((words + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			res[j++] = ft_strndup(&s[i], ft_wordlen(&s[i], c));
			i = i + ft_wordlen(&s[i], c);
		}
		else
			i++;
	}
	res[j] = 0;
	return (res);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char *str = "This is a test string";
// 	char **result = ft_split(str, ' ');

// 	int i = 0;
// 	while (result[i] != NULL) {
// 		printf("%s\n", result[i]);
// 		i++;
// 	}
// 	return (0);
// }