/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections_heredoc.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nporras- <nporras-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 14:20:45 by nporras-          #+#    #+#             */
/*   Updated: 2025/06/09 11:54:22 by nporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	read_heredoc_lines(int fd, char *delimiter, t_shell *shell)
{
	char	*line;
	char	*expanded_line;
	int		len;

	while (1)
	{
		ft_putstr_fd("> ", STDOUT_FILENO);
		line = get_next_line(STDIN_FILENO);
		if (!line)
			break ;
		len = ft_strlen(line);
		if (len > 0 && line[len - 1] == '\n')
			line[len - 1] = '\0';
		if (ft_strcmp(line, delimiter) == 0)
		{
			free(line);
			break ;
		}
		expanded_line = expand_token(line, shell);
		ft_putendl_fd(expanded_line, fd);
		free(line);
		free(expanded_line);
	}
	return (0);
}

int	handle_heredoc(char *delimiter, t_shell *shell)
{
	int	fd[2];

	if (pipe(fd) == -1)
	{
		perror("pipe");
		return (1);
	}
	read_heredoc_lines(fd[1], delimiter, shell);
	close(fd[1]);
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
	return (0);
}
