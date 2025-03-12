/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 16:07:20 by dapanciu          #+#    #+#             */
/*   Updated: 2022/06/28 16:37:00 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	str_pos;

	str_pos = 0;
	while (str[str_pos] != '\0')
		str_pos++;
	return (str_pos);
}

char	*ft_strchr(char *str, int chr)
{
	int	str_pos;

	str_pos = 0;
	if (!str)
		return (NULL);
	if (chr == '\0')
		return (&str[str_pos]);
	while (str[str_pos])
	{
		if (str[str_pos] == chr)
			return (&str[str_pos]);
		str_pos++;
	}
	return (NULL);
}

char	*ft_strjoin(char *str1, char *str2)
{
	int				str1_pos;
	int				str2_pos;
	char			*str_merge;
	unsigned int	len_merge;

	if (!str1)
	{
		str1 = (char *)malloc(1 * sizeof(char));
		str1[0] = '\0';
	}
	len_merge = ft_strlen(str1) + ft_strlen(str2);
	str_merge = (char *)malloc(sizeof(char) * (len_merge + 1));
	if (!str_merge)
		return (NULL);
	str1_pos = -1;
	str2_pos = 0;
	while (str1[++str1_pos])
		str_merge[str1_pos] = str1[str1_pos];
	while (str2[str2_pos])
		str_merge[str1_pos++] = str2[str2_pos++];
	str_merge[len_merge] = '\0';
	free(str1);
	return (str_merge);
}
