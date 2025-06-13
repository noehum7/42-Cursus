/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nporras- <nporras-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 14:17:43 by nporras-          #+#    #+#             */
/*   Updated: 2025/06/04 14:17:44 by nporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	handle_redirection(t_redir *redir, t_shell *shell)
{
	if (redir->type == REDIR_IN)
		return (handle_redir_in(redir->file));
	else if (redir->type == REDIR_OUT)
		return (handle_redir_out(redir->file));
	else if (redir->type == REDIR_APPEND)
		return (handle_redir_append(redir->file));
	else if (redir->type == REDIR_HEREDOC)
		return (handle_heredoc(redir->file, shell));
	else
		return (1);
}

int	apply_redirections(t_redir *redirs, t_shell *shell)
{
	t_redir	*current;
	int		result;

	if (!redirs)
		return (0);
	current = redirs;
	while (current)
	{
		result = handle_redirection(current, shell);
		if (result != 0)
			return (result);
		current = current->next;
	}
	return (0);
}

int	prepare_redirections(t_redir *redirs, int *stdout_copy, int *stdin_copy,
						t_shell *shell)
{
	*stdout_copy = dup(STDOUT_FILENO);
	*stdin_copy = dup(STDIN_FILENO);
	if (*stdout_copy == -1 || *stdin_copy == -1)
	{
		perror("minishell: dup");
		return (EXIT_FAILURE);
	}
	return (apply_redirections(redirs, shell));
}

void	restore_redirections(int stdout_copy, int stdin_copy)
{
	if (stdout_copy != -1)
	{
		dup2(stdout_copy, STDOUT_FILENO);
		close(stdout_copy);
	}
	if (stdin_copy != -1)
	{
		dup2(stdin_copy, STDIN_FILENO);
		close(stdin_copy);
	}
}
