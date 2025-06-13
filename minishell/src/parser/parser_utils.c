/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nporras- <nporras-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 14:25:09 by nporras-          #+#    #+#             */
/*   Updated: 2025/06/04 14:25:19 by nporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

int	is_delimiter(char c)
{
	return (c == '|' || c == '<' || c == '>');
}

t_token_type	get_token_type(char *str)
{
	if (str[0] == '|')
		return (TOKEN_PIPE);
	else if (str[0] == '<')
		return (TOKEN_REDIR_IN);
	else if (str[0] == '>')
		return (TOKEN_REDIR_OUT);
	else
		return (TOKEN_WORD);
}

void	add_token(t_token **tokens, t_token_type type, char *value)
{
	t_token	*new_token;
	t_token	*last;

	new_token = (t_token *)malloc(sizeof(t_token));
	if (!new_token)
		return ;
	new_token->type = type;
	new_token->value = ft_strdup(value);
	new_token->next = NULL;
	if (!*tokens)
		*tokens = new_token;
	else
	{
		last = *tokens;
		while (last->next)
			last = last->next;
		last->next = new_token;
	}
}

int	count_args(t_command *cmd)
{
	int	count;

	count = 0;
	if (cmd && cmd->args)
	{
		while (cmd->args[count])
			count++;
	}
	return (count);
}
