#include "parser.h"

void	add_token(t_tokens **linked_list, char *word, int start,int end)
{
	t_tokens *last;
	t_tokens *new;

	if (linked_list)
	{
		if (*linked_list)
			{
				while((*linked_list)->next != NULL)
					*linked_list = (*linked_list)-> next;
				last -> next = new;
			}
		else
		{
			*linked_list = new;
		}
	}

}

struct t_tokens	*tokenizer(char *str)
{
	int	i;
	t_tokens	*linked_list;

	i = 0;

	while (str[i])
	{
		if (str[i] == ' ')
			add_token();
	}
}
