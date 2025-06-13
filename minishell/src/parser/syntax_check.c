/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nporras- <nporras-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 14:24:49 by nporras-          #+#    #+#             */
/*   Updated: 2025/06/04 14:25:01 by nporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	check_first_token(t_token *token)
{
	if (!token)
		return (1);
	if (token->type == TOKEN_PIPE)
	{
		ft_putstr_fd("minishell: syntax error near unexpected token `|'\n",
			STDERR_FILENO);
		return (0);
	}
	return (1);
}

static int	check_pipe_syntax(t_token *token)
{
	while (token->next)
	{
		token = token->next;
		if (token->type != TOKEN_WORD || ft_strlen(token->value) > 0)
			return (1);
	}
	ft_putstr_fd("minishell: syntax error near unexpected token `|'\n",
		STDERR_FILENO);
	return (0);
}

static int	check_redir_syntax(t_token *token)
{
	if (!token->next || token->next->type != TOKEN_WORD)
	{
		ft_putstr_fd("minishell: syntax error near unexpected token `",
			STDERR_FILENO);
		ft_putstr_fd(token->value, STDERR_FILENO);
		ft_putstr_fd("'\n", STDERR_FILENO);
		return (0);
	}
	return (1);
}

int	check_syntax(t_token *tokens)
{
	t_token	*token;

	if (!check_first_token(tokens))
		return (0);
	token = tokens;
	while (token)
	{
		if (token->type == TOKEN_PIPE)
		{
			if (!check_pipe_syntax(token))
				return (0);
		}
		else if (token->type == TOKEN_REDIR_IN
			|| token->type == TOKEN_REDIR_OUT)
		{
			if (!check_redir_syntax(token))
				return (0);
		}
		token = token->next;
	}
	return (1);
}
