/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: nismail <nismail@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/23 04:14:45 by nismail       #+#    #+#                 */
/*   Updated: 2021/11/25 13:30:09 by nismail       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
*
* The ft_strchr() function locates the first occurrence of the null-terminated 
* string needle in the null-terminated string haystack.
*
*/

char	*ft_strchr(const char *str, int c)
{
	int	n;

	n = 0;
	if (!str)
		return (0);
	while (str[n] != '\0')
	{
		if ((unsigned char)str[n] == (unsigned char)c)
		{
			return ((char *)(str + n));
		}
		n++;
	}
	if ((unsigned char)str[n] == (unsigned char)c)
	{
		return ((char *)(str + n));
	}
	return (0);
}

/*
*
* The strlen() function computes the length of the string s.  The strnlen() 
* function attempts to compute the length of s, but never scans beyond the 
* first maxlen bytes of s.
*
*/

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

/*
*
* The ft_memmove() function copies len bytes from string 
* src to string dst. The two strings may overlap; the copy 
* is always done in a non-destructive manner.
*
*/

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	if (!dst && !src)
		return (0);
	if (dst > src)
	{
		while (len > 0)
		{
			((unsigned char *)dst)[len - 1] = ((unsigned char *)src)[len - 1];
			len--;
		}
	}
	else
	{
		i = 0;
		while (i < len)
		{
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	return (dst);
}

/*
*
* The ft_strdup() function allocates sufficient memory 
* for a copy of the string s1, does the copy, and returns 
* a pointer to it.  The pointer may subsequently be used 
* as an argument to the function free(3).
*
* If insufficient memory is available, NULL is returned and 
* errno is set to ENOMEM.
*
*/

char	*ft_strdup(const char *str)
{
	char	*dst;
	size_t	strlen;

	strlen = ft_strlen(str) + 1;
	dst = (char *)malloc(strlen * sizeof(char));
	if (!dst)
		return (0);
	dst = ft_memmove(dst, str, strlen);
	return ((char *)dst);
}

/*
*
* The ft_strjoin() function allocates (with malloc(3)) and returns 
* a new string, which is the result of the concatenation of ’s1’ and ’s2’.
*
*/

char	*ft_strjoin(char const *str1, char const *str2)
{
	int		len;
	int		str1_len;
	int		str2_len;
	char	*tmp;

	if (!str1 && !str2)
		return (ft_strdup(""));
	if (!str1)
		return (ft_strdup(str2));
	if (!str2)
		return (ft_strdup(str1));
	str1_len = ft_strlen(str1);
	str2_len = ft_strlen(str2);
	len = str1_len + str2_len;
	tmp = malloc((len + 1) * sizeof(char));
	if (!tmp)
		return (0);
	ft_memmove(tmp, str1, str1_len);
	ft_memmove(tmp + str1_len, str2, str2_len);
	tmp[len] = 0;
	return (tmp);
}
