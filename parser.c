/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aswedan <aswedan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 17:08:55 by aswedan           #+#    #+#             */
/*   Updated: 2025/06/23 15:07:34 by aswedan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_tokens	*parser(char *str, char **envp)
{
	t_tokens *linked_list;
	
	linked_list = tokenizer(str);
	if (syntax_validator(linked_list) == 0)
	{
		printf("Syntax error in the input.\n");
		lst_clear(&linked_list);
		return (NULL);
	}
	return (linked_list);
}
int main(int ac, char **av)
{
    t_tokens *testing = parser("echo 'hello world' | grep \"hello\" > output.txt |", NULL);
    if (!testing) return 1;
    
    while (testing)
    {
        printf("Token: %s, Type: %d\n", testing->token, testing->type);
        testing = testing->next;
    }
    return 0;
}
