/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nporras- <nporras-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 13:36:33 by nporras-          #+#    #+#             */
/*   Updated: 2025/06/09 11:57:13 by nporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include <errno.h>
# include <fcntl.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <unistd.h>

# define EXIT_SUCCESS 0
# define EXIT_FAILURE 1
# define EXIT_CMD_NOT_EXECUTABLE 126
# define EXIT_CMD_NOT_FOUND 127

extern int				g_signal;

typedef enum e_redir_type
{
	REDIR_IN,
	REDIR_OUT,
	REDIR_APPEND,
	REDIR_HEREDOC
}						t_redir_type;

typedef enum e_token_type
{
	TOKEN_WORD,
	TOKEN_PIPE,
	TOKEN_REDIR_IN,
	TOKEN_REDIR_OUT
}						t_token_type;

typedef struct s_token
{
	t_token_type		type;
	char				*value;
	struct s_token		*next;
}						t_token;

typedef struct s_redir
{
	t_redir_type		type;
	char				*file;
	struct s_redir		*next;
}						t_redir;

typedef struct s_command
{
	char				**args;
	t_redir				*redirs;
	struct s_command	*next;
}						t_command;

typedef struct s_pipe_data
{
	int					pipe_fd[2];
	int					prev_pipe_read;
	int					cmd_count;
	int					i;
	pid_t				last_pid;
}						t_pipe_data;

typedef struct s_expand_data
{
	int					i;
	int					j;
	int					in_dquote;
	int					in_squote;
}						t_expand_data;

typedef struct s_env
{
	char				*key;
	char				*value;
	struct s_env		*next;
}						t_env;

typedef struct s_shell
{
	t_env				*env_list;
	char				**env_array;
	int					exit_status;
}						t_shell;

// Shell initialization and cleanup
t_shell					*init_shell(char **envp);
void					free_shell(t_shell *shell);

// Utility functions
void					ft_free_array(char **array);
int						ft_strcmp(const char *s1, const char *s2);

// Builtin commands
int						builtin_cd(char **args, t_shell *shell);
int						builtin_echo(char **args);
int						builtin_env(t_command *cmd, t_shell *shell);
int						builtin_exit(char **args, t_shell *shell);
int						builtin_export(char **args, t_shell *shell);
int						builtin_pwd(void);
int						builtin_unset(char **args, t_shell *shell);

// Environment operations (env_ops.c)
char					*get_env_value(t_env *list, char *key);
int						set_env_var(t_env **list, char *key, char *value);
int						unset_env_var(t_env **list, char *key);
char					*get_var_value(const char *var_name, t_shell *shell);
void					update_env_array(t_shell *shell);

// Environment utilities (env_utils.c)
char					**env_list_to_array(t_env *list);
void					free_env_list(t_env *list);
t_env					*add_env_var(t_env **list, char *key, char *value);
t_env					*init_env_list(char **envp);
void					free_env_node(t_env *node);

// Environment utilities 2 (env_utils2.c)
int						is_valid_var_name(char *name);
t_env					*find_env_var(t_env *list, char *key);

// Execution functions
int						execute_commands(t_command *cmd, t_shell *shell);
int						execute_single_command(t_command *cmd, t_shell *shell);
int						execute_piped_commands(t_command *cmd, t_shell *shell);
int						execute_builtin_with_redirections(t_command *cmd,
							t_shell *shell);
int						execute_external_command(t_command *cmd,
							t_shell *shell);

// Execution utilities
void					execute_cmd(char *cmd_name, char **args, char **env);
int						is_builtin(char *cmd);
int						handle_builtin(t_command *cmd, t_shell *shell);
void					verify_command_permissions(char *cmd_path,
							char *cmd_name);
int						count_commands(t_command *cmd);

// Path resolution
char					*find_command_path(char *cmd, char **envp);

// Pipe handling
int						setup_pipe(int *pipe_fd);
void					setup_pipe_redirections(int prev_pipe, int *pipe_fd,
							int is_last);
void					close_pipe_fds(int prev_pipe, int *pipe_fd,
							int is_last);
void					handle_parent_pipes(int *prev_pipe, int *pipe_fd, int i,
							int cmd_count);
int						create_pipe_child(t_command *cmd, t_pipe_data *data,
							int is_last, t_shell *shell);

// Process handling
int						process_pipe_command(t_command *current,
							t_pipe_data *data, t_shell *shell);
void					child_process_with_pipes(t_command *cmd,
							t_pipe_data *data, int is_last, t_shell *shell);
void					update_exit_status(int status, t_shell *shell);

// Redirections
int						apply_redirections(t_redir *redirs, t_shell *shell);
int						prepare_redirections(t_redir *redirs, int *stdout_copy,
							int *stdin_copy, t_shell *shell);
void					restore_redirections(int stdout_copy, int stdin_copy);
int						handle_redir_in(char *file);
int						handle_redir_out(char *file);
int						handle_redir_append(char *file);

// Heredoc
int						handle_heredoc(char *delimiter, t_shell *shell);
int						read_heredoc_lines(int fd, char *delimiter,
							t_shell *shell);

// Expansions
char					*expand_token(char *token, t_shell *shell);

// Quote handling
int						check_quotes(char *input);
int						handle_quotes(char c, int *in_dquote, int *in_squote);
int						handle_quoted_word(char *input, int i, char quote_char,
							int *has_quotes);

// Parser utilities
int						is_space(char c);
int						is_delimiter(char c);
t_token_type			get_token_type(char *str);
void					add_token(t_token **tokens, t_token_type type,
							char *value);
int						count_args(t_command *cmd);
t_command				*new_command(void);
void					add_argument(t_command *cmd, char *arg);
int						add_redirection(t_command *cmd, t_redir_type type,
							char *file);
void					add_token_redirection(t_command *cmd,
							t_token *redir_token, t_token *file_token);

// Free command utilities
void					free_command(t_command *cmd);
void					free_command_list(t_command *cmd);

// Parser main functions
t_command				*parse_line(char *line, t_shell *shell);
t_command				*parse_tokens(t_token *tokens, t_shell *shell);

// Syntax checking
int						check_syntax(t_token *tokens);

// Tokenizer
t_token					*tokenize(char *input);
void					free_tokens(t_token *tokens);

// Signal handling
void					setup_signals(void);
void					setup_child_signals(void);
void					handle_eof(void);

#endif
