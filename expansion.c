#include "parser.h"

int check_env_var(char *token)
{
    if (!token || !*token)
        return (0);
    if (token[0] == '\'')
        return (0);
    if (strchr(token, '$') == NULL)
        return (0);
    return (1);
}



void    expand(t_tokens **tokens, char **envp)
{
    t_tokens    *current;

    if (!tokens || !*tokens || !envp)
        return;
    current = *tokens;
    while (current)
    {
        if (current->type == TOKEN_WORD)
        {
            if (check_env_var(current->token))
            {
                expand_env_var(current, envp);
                continue;
            }
        }
        current = current->next;
    }
}
