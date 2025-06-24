/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aswedan <aswedan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 17:09:34 by aswedan           #+#    #+#             */
/*   Updated: 2025/06/24 14:51:08 by aswedan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

typedef enum	s_meta_chars
{
	TOKEN_WORD,
	TOKEN_PIPE,
	TOKEN_REDIRIN,
	TOKEN_REDIROUT,
	TOKEN_APPEND,
	TOKEN_HERDOC
}	t_meta_chars;

typedef struct	s_tokens
{
	char	*token;
	t_meta_chars type;
	struct s_tokens *next;

}	t_tokens;

t_tokens	*last_node(t_tokens *lst);
void	lst_add_back(t_tokens **lst, t_tokens *new_node);
t_tokens	*create_node(char *token, t_meta_chars token_type);
void	lst_clear(t_tokens **lst);
int	lst_iter(t_tokens *lst);
int syntax_validator(t_tokens *tokens);
t_tokens	*tokenizer(char *str);
void	expand(t_tokens **tokens, char **envp);
