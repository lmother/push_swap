#include "includes/push_swap.h"

char	*ft_cstrcpy(char *dest, const char *src)
{
	size_t	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

size_t	ft_cstrlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_cstrdup(char *str)
{
	char	*dup;
	size_t	i;

	i = 0;
	dup = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (dup == NULL)
		return (NULL);
	while (str[i])
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*ft_cstrchr(const char *str, int c)
{
	size_t	i;
	size_t	len;

	i = 0;
	if (!str)
		return (NULL);
	len = ft_strlen((char *)str);
	while (i <= len)
	{
		if (str[i] == (char) c)
			return ((char *)&str[i]);
		i++;
	}
	return (NULL);
}

char	*ft_cstrjoin(char *dest, char *src)
{
	char		*res;
	size_t		i;
	size_t		k;

	i = 0;
	if (dest == NULL || src == NULL)
		return (NULL);
	k = ft_strlen(dest) + ft_strlen(src);
	res = (char *)malloc(sizeof(char) * (k + 1));
	if (res == NULL)
		return (NULL);
	k = 0;
	while (dest[i])
	{
		res[i] = dest[i];
		i++;
	}
	while (src[k])
		res[i++] = src[k++];
	free(dest);
	res[i] = '\0';
	return (res);
}
