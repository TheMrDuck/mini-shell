/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aswedan <aswedan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 17:08:55 by aswedan           #+#    #+#             */
/*   Updated: 2025/06/10 17:29:07 by aswedan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"




struct t_tokens	*parser(char *str, char **envp)
{
	t_tokens *linked_list;

	linked_list = tokenizer(str);

}
