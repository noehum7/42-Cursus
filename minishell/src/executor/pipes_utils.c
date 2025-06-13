/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nporras- <nporras-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 14:19:58 by nporras-          #+#    #+#             */
/*   Updated: 2025/06/04 14:20:18 by nporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	close_pipe_fds(int prev_pipe, int *pipe_fd, int is_last)
{
	if (prev_pipe != -1)
		close(prev_pipe);
	if (!is_last && pipe_fd)
	{
		close(pipe_fd[0]);
		close(pipe_fd[1]);
	}
}

void	handle_parent_pipes(int *prev_pipe, int *pipe_fd, int i, int cmd_count)
{
	if (*prev_pipe != -1)
		close(*prev_pipe);
	if (i < cmd_count - 1)
	{
		close(pipe_fd[1]);
		*prev_pipe = pipe_fd[0];
	}
}

void	setup_pipe_redirections(int prev_pipe, int *pipe_fd, int is_last)
{
	if (prev_pipe != -1)
	{
		dup2(prev_pipe, STDIN_FILENO);
		close(prev_pipe);
	}
	if (!is_last && pipe_fd)
	{
		dup2(pipe_fd[1], STDOUT_FILENO);
		close(pipe_fd[0]);
		close(pipe_fd[1]);
	}
}

int	setup_pipe(int *pipe_fd)
{
	if (pipe(pipe_fd) == -1)
	{
		perror("pipe");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
