#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1

void ft_putstr_fd(char *str, int fd)
{
	write(fd, str, strlen(str));
}

int ft_strlen(char *str)
{
	int i = 0;
	while (str[i])
		i++;
	return (i);
}

char *ft_strjoin_char(char *s, char c)
{
	char *new;
	int i = 0;
	int len = 0;

	if (s)
		while (s[len])
			len++;
	if (!(new = malloc(len + 2)))
	{
		free(s);
		return (NULL);
	}
	while (i < len)
	{
		new[i] = s[i];
		i++;
	}
	new[i] = c;
	new[i + 1] = '\0';
	free(s);
	return (new);
}

int check_match(char *buffer, char *filter, int filter_len)
{
	int i = 0;

	while (i < filter_len && buffer[i] && buffer[i] == filter[i])
		i++;
	return (i == filter_len);
}

void print_stars(int count)
{
	int i = 0;
	while (i < count)
	{
		write(1, "*", 1);
		i++;
	}
}

int process_input(char *filter)
{
	char buf[1];
	char *buffer = NULL;
	int bytes_read;
	int filter_len = ft_strlen(filter);
	int i;

	while ((bytes_read = read(0, buf, 1)) > 0)
	{
		if (!(buffer = ft_strjoin_char(buffer, buf[0])))
		{
			ft_putstr_fd("error: malloc failed\n", 2);
			return (1);
		}

		if (ft_strlen(buffer) >= filter_len)
		{
			i = ft_strlen(buffer) - filter_len;
			if (check_match(&buffer[i], filter, filter_len))
			{
				print_stars(filter_len);
				free(buffer);
				buffer = NULL;
			}
			else if (ft_strlen(buffer) > filter_len)
			{
				write(1, &buffer[0], 1);
				char *tmp = malloc(ft_strlen(buffer));
				if (!tmp)
				{
					free(buffer);
					ft_putstr_fd("error: malloc failed\n", 2);
					return (1);
				}
				i = 0;
				while (buffer[i + 1])
				{
					tmp[i] = buffer[i + 1];
					i++;
				}
				tmp[i] = '\0';
				free(buffer);
				buffer = tmp;
			}
		}
	}

	if (bytes_read < 0)
	{
		free(buffer);
		ft_putstr_fd("error: read failed\n", 2);
		return (1);
	}

	if (buffer)
	{
		ft_putstr_fd(buffer, 1);
		free(buffer);
	}
	return (0);
}

int main(int argc, char **argv)
{
	if (argc != 2)
		return (1);

	if (!argv[1] || argv[1][0] == '\0')
		return (1);

	return (process_input(argv[1]));
}
