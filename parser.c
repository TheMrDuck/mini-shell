/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hassende <hassende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 17:08:55 by aswedan           #+#    #+#             */
/*   Updated: 2025/06/24 13:49:15 by hassende         ###   ########.fr       */
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
	expand(&linked_list, envp);
	return (linked_list);
}
int main(int ac, char **av, char **envp)
{
    t_tokens *testing = parser("echo $USERR | grep \"hello\" > output.txt", envp);
    if (!testing) return 1;

    while (testing)
    {
        printf("Token: %s, Type: %d\n", testing->token, testing->type);
        testing = testing->next;
    }
    return 0;
}
