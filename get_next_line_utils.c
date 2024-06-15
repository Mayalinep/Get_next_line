/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpelage <mpelage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 13:14:01 by mpelage           #+#    #+#             */
/*   Updated: 2024/06/15 17:07:11 by mpelage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*ft_lstnew(char *content)
{
	t_list	*bead;

	bead = (t_list *)malloc(sizeof(t_list));
	if (!bead)
		return (NULL);
	bead->content = content;
	bead->next = NULL;
	return (bead);
}

void	ft_lstadd_back(t_list **lst, t_list *bead)
{
	t_list	*tmp;

	if (!lst || !bead)
		return ;
	if (*lst == NULL)
	{
		*lst = bead;
		return ;
	}
	tmp = *lst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = bead;
}

char	*ft_lstchr(t_list *lst, int c)
{
	char	*content;

	while (lst)
	{
		content = lst->content;
		while (*content)
		{
			if (*content == (char)c)
				return (content);
			content++;
		}
		lst = lst->next;
	}
	return (NULL);
}

void	ft_free_nodes(t_list **lst)
{
	t_list	*temp;

	while (*lst)
	{
		temp = (*lst)->next;
		free((*lst)->content);
		free(*lst);
		*lst = temp;
	}
}

void	ft_copy_content(t_list **lst, char *str, size_t *position)
{
	char	*content;
	t_list	*temp;

	while (*lst)
	{
		content = (*lst)->content;
		while (*content)
		{
			str[(*position)++] = *content;
			if (*content == '\n')
				break ;
			content++;
		}
		temp = (*lst)->next;
		free((*lst)->content);
		free(*lst);
		*lst = temp;
		if (*position > 0 && str[*position - 1] == '\n')
			break ;
	}
}
