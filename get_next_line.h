/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpelage <mpelage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 12:59:33 by mpelage           #+#    #+#             */
/*   Updated: 2024/06/15 16:10:07 by mpelage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024 // pour une taille appropriée pour le buffer
# endif

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstnew(char *content);
void				ft_lstadd_back(t_list **lst, t_list *bead);
char				*ft_lstchr(t_list *lst, int c);
void				ft_free_nodes(t_list **lst);
void				ft_copy_content(t_list **lst, char *str, size_t *position);
size_t				ft_lststrlen(t_list *lst);
char				*ft_lst_str(t_list **lst);
char				*ft_strdup(const char *s);
char				*get_next_line(int fd);

#endif
