#include "includes/push_swap.h"

static char	*ft_alocmem(void)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * 1);
	if (str == NULL)
		return (NULL);
	str[0] = '\0';
	return (str);
}

static void	ft_memclr(char **mem)
{
	if (*mem)
	{
		free(*mem);
		*mem = NULL;
	}
}

static char	*ft_check_mem(char **mem, char **line)
{
	char	*n;

	n = ft_cstrchr(*mem, '\n');
	*line = NULL;
	if (*mem)
	{
		if (n)
		{
			*n = '\0';
			n++;
			*line = ft_cstrdup(*mem);
			if (*n)
				ft_cstrcpy(*mem, n);
			else
				ft_memclr(&*mem);
		}
		else
		{
			*line = ft_cstrdup(*mem);
			ft_memclr(&*mem);
		}
	}
	else
		*line = ft_alocmem();
	return (n);
}

static int	ft_read_buf(int fd, char *buf, char **line, char **mem)
{
	char	*n;
	ssize_t	bread;

	n = ft_check_mem(mem, line);
	bread = 1;
	while ((!n) && bread)
	{
		bread = read(fd, buf, BUFFER_SIZE);
		buf[bread] = '\0';
		n = ft_cstrchr(buf, '\n');
		if (n)
		{
			*n = '\0';
			*mem = ft_cstrdup(++n);
			if ((*n) && !ft_strlen(*mem))
				return (-1);
		}
		*line = ft_cstrjoin(*line, buf);
	}
	free(buf);
	if (n)
		return (1);
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static char	*mem;
	char		*buf;

	if (line == NULL || (read(fd, 0, 0) < 0))
		return (-1);
	buf = (char *) malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf)
		return (-1);
	return (ft_read_buf(fd, buf, line, &mem));
}
