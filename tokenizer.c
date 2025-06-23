#include "parser.h"

int	single_quot_handler(char *str, int *i, t_tokens **tokens)
{
	char	buffer[4096];
	int		buff_index;

	buff_index = 0;
	buffer[0] = str[*i];
	buff_index++;
	(*i)++;
	while(str[*i])
	{
		buffer[buff_index] = str[*i];
		buff_index++;
		(*i)++;
		if (str[*i] && str[*i] == '\'')
			break;
	}
	if (str[*i] != '\0' && str[*i] == '\'')
		buffer[buff_index] = str[*i];
	buffer[++buff_index] = '\0';
	lst_add_back(tokens, create_node(buffer, TOKEN_WORD));
	return (1);
}
t_tokens	*tokenizer(char *str)
{
	t_tokens	*tokens;
	int			i;
	int			single_quot;
	int			double_quot;

	i = 0;
	if (!str)
		return (NULL);
	tokens = NULL;
	while (str[i])
	{
		if (str[i] == '\'')
			single_quot = 1;
		if (single_quot)
			{
				if(!(single_quot_handler(str, &i, &tokens)))
					return (NULL);
				single_quot = 0;
			}
		i++;
	}
	return (tokens);
}

int main(int ac, char **av)
{
	t_tokens *testing = tokenizer(av[1]);
	printf("%s\n", av[1]);
	if (!testing) return 1;
	int i = 0;
	while (testing)
	{
		printf("%s\n", testing->token);
		testing = testing->next;
	}
}
