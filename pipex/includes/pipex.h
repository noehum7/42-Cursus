#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h> // Para perror
# include <fcntl.h> // Usado para open y flags como O_RDONLY, O_WRONLY, etc.
# include <sys/wait.h> // Usado para waitpid y macros como WIFEXITED, WEXITSTATUS
# include <errno.h> // Usado para errno en manejo de errores
# include <unistd.h>    // Para fork, pipe, access, dup2, execve
# include "libft.h"

void	pipex(char **av, char **envp);
void	handle_child1(int *pipe_fd, char **av, char **envp);
void	handle_child2(int *pipe_fd, char **av, char **envp);
void	close_and_wait(int *pipe_fd, int outfile, pid_t pid2);
void	execute_command(char *cmd, char **envp);
void	error_exit(char *message);
void	ft_free_array(char **str);
void	print_cmd_error(char *cmd, char *info);

#endif
