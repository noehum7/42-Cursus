/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nporras- <nporras-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 14:24:34 by nporras-          #+#    #+#             */
/*   Updated: 2025/06/11 10:27:37 by nporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	process_word_token(t_token *token, t_command *cmd, t_shell *shell)
{
	char	*expanded_value;

	expanded_value = expand_token(token->value, shell);
	add_argument(cmd, expanded_value);
	free(expanded_value);
}

static void	process_redir_token(t_token **token, t_command *cmd, t_shell *shell)
{
	char	*expanded_value;
	t_redir	*current;

	if (!(*token)->next || (*token)->next->type != TOKEN_WORD)
		return ;
	expanded_value = expand_token((*token)->next->value, shell);
	add_token_redirection(cmd, *token, (*token)->next);
	current = cmd->redirs;
	while (current->next)
		current = current->next;
	free(current->file);
	current->file = expanded_value;
	*token = (*token)->next;
}

t_command	*parse_tokens(t_token *tokens, t_shell *shell)
{
	t_command	*first_cmd;
	t_command	*current_cmd;
	t_token		*token;

	if (!tokens)
		return (NULL);
	first_cmd = new_command();
	current_cmd = first_cmd;
	token = tokens;
	while (token)
	{
		if (token->type == TOKEN_WORD)
			process_word_token(token, current_cmd, shell);
		else if (token->type == TOKEN_PIPE)
		{
			current_cmd->next = new_command();
			current_cmd = current_cmd->next;
		}
		else if (token->type == TOKEN_REDIR_IN
			|| token->type == TOKEN_REDIR_OUT)
			process_redir_token(&token, current_cmd, shell);
		token = token->next;
	}
	return (first_cmd);
}

t_command	*parse_line(char *line, t_shell *shell)
{
	t_token		*tokens;
	t_command	*cmds;

	tokens = tokenize(line);
	if (!tokens)
		return (NULL);
	if (!check_syntax(tokens))
	{
		shell->exit_status = 2;
		free_tokens(tokens);
		return (NULL);
	}
	cmds = parse_tokens(tokens, shell);
	free_tokens(tokens);
	return (cmds);
}
