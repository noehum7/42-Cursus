#include "pipex.h"

static void	verify_path(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0 && envp[i][5])
			return ;
		i++;
	}
	error_exit("PATH");
}

void	pipex(char **av, char **envp)
{
	int		pipe_fd[2];
	pid_t	pid1;

	verify_path(envp);
	if (pipe(pipe_fd) == -1)
		error_exit("pipe");
	pid1 = fork();
	if (pid1 < 0)
		error_exit("fork");
	if (pid1 == 0)
		handle_child1(pipe_fd, av, envp);
	waitpid(pid1, NULL, 0);
	handle_child2(pipe_fd, av, envp);
}

void	handle_child1(int *pipe_fd, char **av, char **envp)
{
	int	infile;

	infile = open(av[1], O_RDONLY);
	if (infile == -1)
		error_exit(av[1]);
	dup2(infile, STDIN_FILENO);
	dup2(pipe_fd[1], STDOUT_FILENO);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	close(infile);
	execute_command(av[2], envp);
}

void	handle_child2(int *pipe_fd, char **av, char **envp)
{
	int		outfile;
	pid_t	pid2;

	outfile = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (outfile == -1)
		error_exit(av[4]);
	pid2 = fork();
	if (pid2 < 0)
		error_exit("fork");
	if (pid2 == 0)
	{
		dup2(pipe_fd[0], STDIN_FILENO);
		dup2(outfile, STDOUT_FILENO);
		close(pipe_fd[0]);
		close(pipe_fd[1]);
		close(outfile);
		execute_command(av[3], envp);
	}
	close_and_wait(pipe_fd, outfile, pid2);
}

void	close_and_wait(int *pipe_fd, int outfile, pid_t pid2)
{
	int	status;
	int	exit_code;

	close(pipe_fd[0]);
	close(pipe_fd[1]);
	close(outfile);
	waitpid(pid2, &status, 0);
	if (WIFEXITED(status))
	{
		exit_code = WEXITSTATUS(status);
		exit(exit_code);
	}
	exit(1);
}
