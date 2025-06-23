#include "parser.h"

int expansion_handler(t_tokens **tokens)
{
    if (tokens == NULL)
        return (0);
    t_tokens *current = *tokens;
    while (current)
    {
        if (current->type == TOKEN_WORD && current->token[0] == '\'')
            current = current->next;
        else if (current->type == TOKEN_WORD)
        {
            if(strchr(current->token, '$'))
                {
                    
                }
        }
        current = current->next;
    }
}