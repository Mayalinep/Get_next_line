/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpelage <mpelage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 15:06:41 by mpelage           #+#    #+#             */
/*   Updated: 2024/06/15 17:10:28 by mpelage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s)
{
	char	*copy;
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	copy = (char *)malloc((len + 1) * sizeof(char));
	if (!copy)
		return (NULL);
	len = 0;
	while (s[len])
	{
		copy[len] = s[len];
		len++;
	}
	copy[len] = '\0';
	return (copy);
}

size_t	ft_lststrlen(t_list *lst)
{
	size_t	total_len;
	char	*content;

	total_len = 0;
	while (lst)
	{
		content = lst->content;
		while (*content)
		{
			if (*content == '\n')
				return (total_len + 1);
			total_len++;
			content++;
		}
		lst = lst->next;
	}
	return (total_len);
}

char	*ft_lst_str(t_list **lst)
{
	char	*str;
	size_t	total_len;
	size_t	position;

	total_len = ft_lststrlen(*lst);
	str = (char *)malloc(total_len + 1);
	if (!str)
		return (NULL);
	position = 0;
	ft_copy_content(lst, str, &position);
	str[position] = '\0';
	return (str);
}

static void	add_to_list(t_list **current, int fd)
{
	char	*buffer;
	ssize_t	bytes_read;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return ;
	while (!ft_lstchr(*current, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			break ;
		buffer[bytes_read] = '\0';
		ft_lstadd_back(current, ft_lstnew(ft_strdup(buffer)));
	}
	free(buffer);
}

char	*get_next_line(int fd)
{
	static t_list	*remainder = NULL;
	t_list			*current;
	char			*line;

	current = remainder;
	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	add_to_list(&current, fd);
	if (!current)
		return (line);
	line = ft_lst_str(&current);
	remainder = current;
	return (line);
}
