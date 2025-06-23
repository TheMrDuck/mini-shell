/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_lst_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aswedan <aswedan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 14:09:39 by aswedan           #+#    #+#             */
/*   Updated: 2025/06/23 17:24:18 by aswedan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include <string.h>

t_tokens	*last_node(t_tokens *lst)
{
	t_tokens	*last_node;

	while (lst ->next != NULL)
		lst = lst->next;
	last_node = lst;
	return (last_node);
}

void	lst_add_back(t_tokens **lst, t_tokens *new_node)
{
	t_tokens	*last;

	if(lst)
	{
		if (*lst)
		{
			last = last_node(*lst);
			last ->next = new_node;
		}
		else
			*lst = new_node;
	}
}
t_tokens	*create_node(char *token, t_meta_chars token_type)
{
	t_tokens *node;

	node = malloc(sizeof(t_tokens));
	if (!node)
		return (NULL);
	node -> token = strdup(token); // replace it with ft version *MANDATORY*
	node ->type = token_type;
	node ->next = NULL;
	return (node);
}

void	lst_clear(t_tokens **lst)
{
	t_tokens	*current;
	t_tokens	*next;

	if (!lst || !*lst)
		return ;
	current = *lst;
	while (current)
	{
		next = current ->next;
		free(current->token);
		free(current);
		current = next;
	}
	*lst = NULL;
}

int	lst_iter(t_tokens *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		lst = lst -> next;
		i++;
	}
	return (i);
}
