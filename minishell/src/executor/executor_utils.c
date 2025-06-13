/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nporras- <nporras-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 14:19:05 by nporras-          #+#    #+#             */
/*   Updated: 2025/06/04 14:19:21 by nporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execute_cmd(char *cmd_name, char **args, char **env)
{
	char	*cmd_path;

	if (!args || !args[0] || args[0][0] == '\0')
	{
		ft_putstr_fd("minishell: command not found\n", STDERR_FILENO);
		exit(EXIT_CMD_NOT_FOUND);
	}
	if (ft_strchr(cmd_name, '/'))
		cmd_path = ft_strdup(cmd_name);
	else
		cmd_path = find_command_path(cmd_name, env);
	if (!cmd_path)
	{
		ft_putstr_fd("minishell: ", STDERR_FILENO);
		ft_putstr_fd(args[0], STDERR_FILENO);
		ft_putstr_fd(": command not found\n", STDERR_FILENO);
		exit(EXIT_CMD_NOT_FOUND);
	}
	verify_command_permissions(cmd_path, args[0]);
	execve(cmd_path, args, env);
	perror("minishell");
	free(cmd_path);
	exit(EXIT_CMD_NOT_EXECUTABLE);
}

void	verify_command_permissions(char *cmd_path, char *cmd_name)
{
	if (access(cmd_path, X_OK) != 0)
	{
		ft_putstr_fd("minishell: ", STDERR_FILENO);
		ft_putstr_fd(cmd_name, STDERR_FILENO);
		ft_putstr_fd(": permission denied\n", STDERR_FILENO);
		free(cmd_path);
		exit(EXIT_CMD_NOT_EXECUTABLE);
	}
}

int	count_commands(t_command *cmd)
{
	int			count;
	t_command	*current;

	count = 0;
	current = cmd;
	while (current)
	{
		count++;
		current = current->next;
	}
	return (count);
}

int	is_builtin(char *cmd)
{
	if (!cmd)
		return (0);
	return (ft_strcmp(cmd, "echo") == 0 || ft_strcmp(cmd, "cd") == 0
		|| ft_strcmp(cmd, "pwd") == 0 || ft_strcmp(cmd, "export") == 0
		|| ft_strcmp(cmd, "unset") == 0 || ft_strcmp(cmd, "env") == 0
		|| ft_strcmp(cmd, "exit") == 0);
}

int	handle_builtin(t_command *cmd, t_shell *shell)
{
	if (ft_strcmp(cmd->args[0], "echo") == 0)
		return (builtin_echo(cmd->args));
	else if (ft_strcmp(cmd->args[0], "cd") == 0)
		return (builtin_cd(cmd->args, shell));
	else if (ft_strcmp(cmd->args[0], "pwd") == 0)
		return (builtin_pwd());
	else if (ft_strcmp(cmd->args[0], "export") == 0)
		return (builtin_export(cmd->args, shell));
	else if (ft_strcmp(cmd->args[0], "unset") == 0)
		return (builtin_unset(cmd->args, shell));
	else if (ft_strcmp(cmd->args[0], "env") == 0)
		return (builtin_env(cmd, shell));
	else if (ft_strcmp(cmd->args[0], "exit") == 0)
		return (builtin_exit(cmd->args, shell));
	return (EXIT_FAILURE);
}
