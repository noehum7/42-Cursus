/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_pipe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nporras- <nporras-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 14:17:50 by nporras-          #+#    #+#             */
/*   Updated: 2025/06/04 14:18:05 by nporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	create_pipe_child(t_command *cmd, t_pipe_data *data, int is_last,
		t_shell *shell)
{
	if (!cmd->args || !cmd->args[0])
		return (EXIT_SUCCESS);
	data->last_pid = fork();
	if (data->last_pid < 0)
	{
		perror("fork");
		close_pipe_fds(data->prev_pipe_read, data->pipe_fd, is_last);
		return (EXIT_FAILURE);
	}
	if (data->last_pid == 0)
		child_process_with_pipes(cmd, data, is_last, shell);
	return (EXIT_SUCCESS);
}

void	child_process_with_pipes(t_command *cmd, t_pipe_data *data, int is_last,
		t_shell *shell)
{
	setup_child_signals();
	setup_pipe_redirections(data->prev_pipe_read, data->pipe_fd, is_last);
	if (apply_redirections(cmd->redirs, shell) != 0)
		exit(EXIT_FAILURE);
	if (!cmd->args || !cmd->args[0])
		exit(EXIT_SUCCESS);
	if (is_builtin(cmd->args[0]))
		exit(handle_builtin(cmd, shell));
	else
		execute_cmd(cmd->args[0], cmd->args, shell->env_array);
}

int	process_pipe_command(t_command *current, t_pipe_data *data,
		t_shell *shell)
{
	int	is_last;

	is_last = (data->i == data->cmd_count - 1);
	if (data->i < data->cmd_count - 1 && setup_pipe(data->pipe_fd)
		== EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (create_pipe_child(current, data, is_last, shell) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	handle_parent_pipes(&data->prev_pipe_read, data->pipe_fd, data->i,
		data->cmd_count);
	return (EXIT_SUCCESS);
}
