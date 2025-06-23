#include "parser.h"

int syntax_validator(t_tokens *tokens)
{
    int i;
    i = 0;
    while (tokens)
    {
        if (tokens->type == TOKEN_REDIRIN || tokens->type == TOKEN_REDIROUT || tokens->type == TOKEN_APPEND || tokens->type == TOKEN_HERDOC)
        {
            if (!tokens->next || (tokens->next && (tokens->next->type != TOKEN_WORD)))
            {
                printf("Syntax error: Redirection without a valid command.\n%d\n", i);
                return 0;
            }
        }
        if (tokens->type == TOKEN_PIPE)
        {
            if (!tokens->next || (tokens->next && (tokens->next->type != TOKEN_WORD)))
            {
                printf("Syntax error: Pipe without a valid command.\n%d\n", i);
                return 0;
            }
        }
        tokens = tokens->next;
        i++;
    }
    return (1);
}