#include "parser.h"

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	c;
	unsigned int	j;
	unsigned int	i;

	c = 0;
	j = 0;
	i = 0;
	while (dest[c] != '\0')
		c++;
	while (src[j] != '\0')
		j++;
	if (size <= c)
		return (size + j);
	while (src[i] != '\0' && (c + i) < (size - 1))
	{
		dest[c + i] = src[i];
		i++;
	}
	dest[c + i] = '\0';
	return (c + j);
}

int check_env_var(char *token)
{
	if (!token || !*token)
		return (0);
	if (token[0] == '\'')
		return (0);
	if (strchr(token, '$') == 0)
		return (0);
	return (1);
}

char	*look_for_env(char	*str, char **envp)
{
	int	i;
	int var_len;
	char *equals_pos;

	i = 0;
	var_len = strlen(str);
	while (envp[i])
	{
		// Find the '=' in the environment variable
		equals_pos = strchr(envp[i], '=');
		if (equals_pos != NULL)
		{
			// Check if variable name matches (before the '=')
			if (strncmp(str, envp[i], var_len) == 0 &&
				envp[i][var_len] == '=')
			{
				// Return the value part (after '=')
				return (strdup(equals_pos + 1));
			}
		}
		i++;
	}
	return (strdup(""));
}

int	expand_env_var(t_tokens *current, char **envp)
{
	int		dollar_pos;
	int		var_start;
	int		var_end;
	char	buffer[4096] = {0};
	char	var_name[256] = {0};
	char	*env_value;

	dollar_pos = 0;
	while(current->token[dollar_pos] && current->token[dollar_pos] != '$')
		dollar_pos++;
	if (!current->token[dollar_pos])
		return (0);
	var_start = dollar_pos + 1;
	var_end = var_start;
	while(current->token[var_end] &&
		  current->token[var_end] != ' ' &&
		  current->token[var_end] != '$' &&
		  current->token[var_end] != '"' &&
		  current->token[var_end] != '\'' &&
		  current->token[var_end] != '|' &&
		  current->token[var_end] != '>' &&
		  current->token[var_end] != '<')
		var_end++;
	strncpy(var_name, current->token + var_start, var_end - var_start);
	var_name[var_end - var_start] = '\0';
	printf("Variable name: '%s'\n", var_name);
	env_value = look_for_env(var_name, envp);
	if (dollar_pos > 0)
		strncpy(buffer, current->token, dollar_pos);
	if (env_value && strlen(env_value) > 0)
		ft_strlcat(buffer, env_value, 4096);
	if (current->token[var_end])
		ft_strlcat(buffer, current->token + var_end, 4096);
	free(env_value);
	free(current->token);
	current->token = strdup(buffer);
	return (1);

	// DO NOT FORGET TO SWITCH TO THE LIBFT FUNCTION NOT <STRING.H>
}

void	expand(t_tokens **tokens, char **envp)
{
	t_tokens	*current;

	if (!tokens || !*tokens || !envp)
		return;
	current = *tokens;
	while (current)
	{
		if (current->type == TOKEN_WORD)
		{
			if (check_env_var(current->token))
			{
				printf("hi\n");
				expand_env_var(current, envp);
			}
		}
		current = current->next;
	}
}
