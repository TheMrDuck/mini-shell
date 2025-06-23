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
    {
        buffer[buff_index] = str[*i];
        buff_index++;
        (*i)++;
    }
    buffer[buff_index] = '\0';
    lst_add_back(tokens, create_node(buffer, TOKEN_WORD));
    return (1);
}

int	double_quot_handler(char *str, int *i, t_tokens **tokens)
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
        if (str[*i] && str[*i] == '\"')
            break;
    }
    if (str[*i] != '\0' && str[*i] == '\"')
    {
        buffer[buff_index] = str[*i];
        buff_index++;
        (*i)++;
    }
    buffer[buff_index] = '\0';
    lst_add_back(tokens, create_node(buffer, TOKEN_WORD));
    return (1);
}

t_tokens	*tokenizer(char *str)
{
    t_tokens	*tokens;
    int			i;
    int 		buff_index;
    char 		buffer[4096];

    i = 0;
    buff_index = 0;
    if (!str)
        return (NULL);
    tokens = NULL;
    
    while (str[i])
    {
        while (str[i] == ' ')
        {
            if (buff_index > 0)
            {
                buffer[buff_index] = '\0';
                lst_add_back(&tokens, create_node(buffer, TOKEN_WORD));
                buff_index = 0;
            }
            i++;
        }
        
        if (!str[i])
            break;

        if (str[i] == '\'')
        {
            if (buff_index > 0)
            {
                buffer[buff_index] = '\0';
                lst_add_back(&tokens, create_node(buffer, TOKEN_WORD));
                buff_index = 0;
            }
            if (!(single_quot_handler(str, &i, &tokens)))
                return (NULL);
            continue;
        }
        
        if (str[i] == '\"')
        {
            if (buff_index > 0)
            {
                buffer[buff_index] = '\0';
                lst_add_back(&tokens, create_node(buffer, TOKEN_WORD));
                buff_index = 0;
            }
            if (!(double_quot_handler(str, &i, &tokens)))
                return (NULL);
            continue;
        }
        
        if (str[i] == '|')
        {
            if (buff_index > 0)
            {
                buffer[buff_index] = '\0';
                lst_add_back(&tokens, create_node(buffer, TOKEN_WORD));
                buff_index = 0;
            }
            lst_add_back(&tokens, create_node("|", TOKEN_PIPE));
            i++;
            continue;
        }
        
        if (str[i] == '>')
        {
            if (buff_index > 0)
            {
                buffer[buff_index] = '\0';
                lst_add_back(&tokens, create_node(buffer, TOKEN_WORD));
                buff_index = 0;
            }
            if (str[i + 1] == '>')
            {
                lst_add_back(&tokens, create_node(">>", TOKEN_APPEND));
                i += 2;
            }
            else
            {
                lst_add_back(&tokens, create_node(">", TOKEN_REDIROUT));
                i++;
            }
            continue;
        }
        
        if (str[i] == '<')
        {
            if (buff_index > 0)
            {
                buffer[buff_index] = '\0';
                lst_add_back(&tokens, create_node(buffer, TOKEN_WORD));
                buff_index = 0;
            }
            if (str[i + 1] == '<')
            {
                lst_add_back(&tokens, create_node("<<", TOKEN_HERDOC));
                i += 2;
            }
            else
            {
                lst_add_back(&tokens, create_node("<", TOKEN_REDIRIN));
                i++;
            }
            continue;
        }
        
        buffer[buff_index] = str[i];
        buff_index++;
        i++;
    }
    
    if (buff_index > 0)
    {
        buffer[buff_index] = '\0';
        lst_add_back(&tokens, create_node(buffer, TOKEN_WORD));
    }
    
    return (tokens);
}

// int main(int ac, char **av)
// {
//     t_tokens *testing = tokenizer("echo 'hello world' | grep \"hello\" > output.txt");
//     if (!testing) return 1;
    
//     while (testing)
//     {
//         printf("Token: %s, Type: %d\n", testing->token, testing->type);
//         testing = testing->next;
//     }
//     return 0;
// }
