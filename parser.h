/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aswedan <aswedan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 17:09:34 by aswedan           #+#    #+#             */
/*   Updated: 2025/06/10 17:44:23 by aswedan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

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
	s_tokens *next;

}	t_tokens;
