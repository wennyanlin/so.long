#include "so_long.h"

int	string_contain(char *str, char target)
{
	int	i;

	i = 0;
	if (!str)
		return (1);
	while (str[i])
	{
		if (str[i] == target)
			return (1);
		i++;
	}
	return (0);
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while(str[i])
		i++;
	return (i);
}

char	**ft_strdup_array(char **array)
{
	int		i;
	int		j;
	char	**result;
	int		len_i;
	int		len_j;

	i = 0;
	j = 0;
	if (!array || !array[i])
		return (NULL);
	while (array[i])
		i++;
	len_i = i;
	len_j = ft_strlen(array[0]);
	result = malloc(sizeof(char *) * (len_i + 1));
	if (!result)
		return (NULL);
	i = -1;
	while (array[++i])
	{
		j = -1;
		result[i] = malloc(sizeof(char) * (len_j + 1));
		if (!array[i])
			return (NULL);
		while (array[i][++j])
			result[i][j] = array[i][j];
		result[i][j] = '\0';
	}
	result[i] = NULL;
	return (result);
}

void	ft_putnbr(int nbr)
{
	int		i;
	char	n;

	i = 0;
	if (nbr > 9)
	{
		ft_putnbr(nbr / 10);
		ft_putnbr(nbr % 10);
	}
	else
	{
		n = nbr + '0';
		write(1, &n, 1);
	}
}

void	write_num_moves(int num_move)
{
	
	write(1, "You made: ", 10);
	ft_putnbr(num_move);
	if (num_move == 1)
		write(1, " step\n", 6);
	else
		write(1, " steps\n", 7);
}

void	*free_space(char **reserved_space)
{
	if (*reserved_space)
	{
		free(*reserved_space);
		*reserved_space = NULL;
	}
	return (NULL);
}

char	*duplicate_storage(char *storage, char *buffer)
{
	char	*result;
	int		i;

	i = -1;
	if (!storage || !buffer)
		return (NULL);
	result = malloc(ft_strlen(storage) + ft_strlen(buffer) + 1);
	if (!result)
		return (free_space(&storage));
	while (storage[++i] != '\0')
		result[i] = storage[i];
	result[i] = '\0';
	return (result);
}

char	*ft_strjoin(char *storage, char *buffer)
{
	char	*result;
	int		i;
	int		j;

	if (!storage)
	{
		storage = malloc(sizeof(char));
		if (!storage)
			return (NULL);
		storage[0] = '\0';
	}
	i = ft_strlen(storage);
	result = duplicate_storage(storage, buffer);
	if (!result)
		return (NULL);
	j = -1;
	while (buffer[++j] != '\0')
		result[i + j] = buffer[j];
	result[i + j] = '\0';
	free(storage);
	return (result);
}

// -g -fsanitize='address,undefined'