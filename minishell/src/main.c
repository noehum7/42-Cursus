/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nporras- <nporras-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 13:42:42 by nporras-          #+#    #+#             */
/*   Updated: 2025/06/04 13:44:50 by nporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	process_line(char *line, t_shell *shell)
{
	t_command	*cmd;

	if (g_signal)
	{
		shell->exit_status = g_signal;
		g_signal = 0;
	}
	if (!*line)
		return ;
	add_history(line);
	cmd = parse_line(line, shell);
	if (cmd)
	{
		shell->exit_status = execute_commands(cmd, shell);
		free_command_list(cmd);
	}
}

static void	shell_loop(t_shell *shell)
{
	char	*line;

	while (1)
	{
		line = readline("minishell$ ");
		if (!line)
		{
			handle_eof();
			break ;
		}
		process_line(line, shell);
		free(line);
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_shell	*shell;

	(void)argc;
	(void)argv;
	shell = init_shell(envp);
	setup_signals();
	shell_loop(shell);
	free_shell(shell);
	return (0);
}
