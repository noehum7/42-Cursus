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

int	execute_commands(t_command *cmd, t_shell *shell)
{
	if (!cmd)
		return (EXIT_SUCCESS);
	if (!cmd->next)
		return (execute_single_command(cmd, shell));
	else
		return (execute_piped_commands(cmd, shell));
}

int	execute_single_command(t_command *cmd, t_shell *shell)
{
	if (!cmd->args || !cmd->args[0])
		return (EXIT_SUCCESS);
	if (is_builtin(cmd->args[0]))
		return (execute_builtin_with_redirections(cmd, shell));
	return (execute_external_command(cmd, shell));
}

int	execute_builtin_with_redirections(t_command *cmd, t_shell *shell)
{
	int	stdout_copy;
	int	stdin_copy;
	int	result;

	stdout_copy = -1;
	stdin_copy = -1;
	if (cmd->redirs)
	{
		if (prepare_redirections(cmd->redirs, &stdout_copy,
				&stdin_copy, shell) != 0)
			return (EXIT_FAILURE);
	}
	result = handle_builtin(cmd, shell);
	if (cmd->redirs)
		restore_redirections(stdout_copy, stdin_copy);
	return (result);
}

int	execute_external_command(t_command *cmd, t_shell *shell)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid < 0)
	{
		perror("fork");
		return (EXIT_FAILURE);
	}
	if (pid == 0)
	{
		setup_child_signals();
		if (apply_redirections(cmd->redirs, shell) != 0)
			exit(EXIT_FAILURE);
		execute_cmd(cmd->args[0], cmd->args, shell->env_array);
	}
	waitpid(pid, &status, 0);
	update_exit_status(status, shell);
	return (shell->exit_status);
}

int	execute_piped_commands(t_command *cmd, t_shell *shell)
{
	t_pipe_data	data;
	t_command	*current;
	int			status;

	data.cmd_count = count_commands(cmd);
	data.prev_pipe_read = -1;
	data.i = 0;
	current = cmd;
	while (current)
	{
		if (process_pipe_command(current, &data, shell) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		current = current->next;
		data.i++;
	}
	waitpid(data.last_pid, &status, 0);
	while (wait(NULL) > 0)
		;
	update_exit_status(status, shell);
	return (shell->exit_status);
}
