/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nporras- <nporras-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 14:24:14 by nporras-          #+#    #+#             */
/*   Updated: 2025/06/04 14:24:22 by nporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_redir_type	get_redir_type(char *redir_str)
{
	if (ft_strcmp(redir_str, "<<") == 0)
		return (REDIR_HEREDOC);
	else if (ft_strcmp(redir_str, ">>") == 0)
		return (REDIR_APPEND);
	else if (ft_strcmp(redir_str, "<") == 0)
		return (REDIR_IN);
	else if (ft_strcmp(redir_str, ">") == 0)
		return (REDIR_OUT);
	else
		return (0);
}

void	add_argument(t_command *cmd, char *arg)
{
	char	**new_args;
	int		i;
	int		size;

	if (!arg)
		return ;
	size = count_args(cmd);
	new_args = (char **)malloc(sizeof(char *) * (size + 2));
	if (!new_args)
		return ;
	i = 0;
	while (i < size)
	{
		new_args[i] = cmd->args[i];
		i++;
	}
	new_args[size] = ft_strdup(arg);
	new_args[size + 1] = NULL;
	if (cmd->args)
		free(cmd->args);
	cmd->args = new_args;
}

void	add_token_redirection(t_command *cmd, t_token *redir_token,
		t_token *file_token)
{
	t_redir			*new_redir;
	t_redir			*current;
	t_redir_type	type;

	type = get_redir_type(redir_token->value);
	new_redir = (t_redir *)malloc(sizeof(t_redir));
	if (!new_redir)
		return ;
	new_redir->type = type;
	new_redir->file = ft_strdup(file_token->value);
	new_redir->next = NULL;
	if (!cmd->redirs)
		cmd->redirs = new_redir;
	else
	{
		current = cmd->redirs;
		while (current->next)
			current = current->next;
		current->next = new_redir;
	}
}

int	add_redirection(t_command *cmd, t_redir_type type, char *file)
{
	t_redir	*new_redir;
	t_redir	*last;

	new_redir = (t_redir *)malloc(sizeof(t_redir));
	if (!new_redir)
		return (0);
	new_redir->type = type;
	new_redir->file = ft_strdup(file);
	new_redir->next = NULL;
	if (!cmd->redirs)
		cmd->redirs = new_redir;
	else
	{
		last = cmd->redirs;
		while (last->next)
			last = last->next;
		last->next = new_redir;
	}
	return (1);
}

t_command	*new_command(void)
{
	t_command	*cmd;

	cmd = (t_command *)malloc(sizeof(t_command));
	if (!cmd)
		return (NULL);
	cmd->args = NULL;
	cmd->redirs = NULL;
	cmd->next = NULL;
	return (cmd);
}
