
#include "parser.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	*cutter(char *sub_word, int start, int end)
{
	char	*buffer;
	int		i;

	i = 0;
	buffer = malloc(end-start + 1);
	while (start <= end)
	{
		buffer[i] = sub_word[start];
		i++;
		start++;
	}
	buffer[i] = '\0';
	return (buffer);
}

void	add_token(t_tokens **linked_list, char *sub_word, int start,int end)
{
	t_tokens *last;
	t_tokens *new;

	new = malloc(sizeof(t_tokens));
	last = malloc(sizeof(t_tokens *));
	new->token = cutter(sub_word, start, end);
	new->next = NULL;
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

t_tokens	*tokenizer(char *str)
{
	int	i;
	int	start;
	t_tokens	*linked_list;

	i = 0;
	start = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			{
				add_token(&linked_list, str, start, i - 1);
				start = i;
			}
		i++;
	}
	return NULL;
}

int main(int argc, char **argv)
{
	char *input = "hello world test tokenizer";
	t_tokens *tokens;

	printf("Input string: %s\n", input);
	tokens = tokenizer(input);

	return 0;
}
