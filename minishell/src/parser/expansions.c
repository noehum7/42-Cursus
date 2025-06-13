/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nporras- <nporras-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 14:23:19 by nporras-          #+#    #+#             */
/*   Updated: 2025/06/04 14:23:42 by nporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*init_expansion(t_expand_data *data)
{
	char	*result;

	result = malloc(4096);
	if (!result)
		return (NULL);
	data->i = 0;
	data->j = 0;
	data->in_dquote = 0;
	data->in_squote = 0;
	return (result);
}

static int	extract_var_name(char *token, t_expand_data *data, char *var_name)
{
	int	name_len;

	name_len = 0;
	if (token[data->i] == '?')
		var_name[name_len++] = token[data->i++];
	else
	{
		while (token[data->i] && (ft_isalnum(token[data->i])
				|| token[data->i] == '_') && name_len < 255)
			var_name[name_len++] = token[data->i++];
	}
	var_name[name_len] = '\0';
	return (name_len);
}

static int	process_var(char *token, t_expand_data *data, char *result,
			t_shell *shell)
{
	char	var_name[256];
	int		name_len;
	char	*value;
	int		k;

	data->i++;
	name_len = extract_var_name(token, data, var_name);
	if (name_len > 0)
	{
		value = get_var_value(var_name, shell);
		if (!value)
			return (0);
		k = 0;
		while (value[k])
			result[data->j++] = value[k++];
		free(value);
		return (1);
	}
	return (0);
}

static int	process_special_chars(char *token, t_expand_data *data,
			char *result, t_shell *shell)
{
	char	*home;
	int		k;

	if (token[data->i] == '~' && !data->in_dquote && !data->in_squote
		&& data->i == 0 && (token[data->i + 1] == '\0'
			|| token[data->i + 1] == '/'))
	{
		home = get_var_value("HOME", shell);
		if (!home)
			return (0);
		k = 0;
		while (home[k])
			result[data->j++] = home[k++];
		free(home);
		data->i++;
		return (1);
	}
	return (0);
}

char	*expand_token(char *token, t_shell *shell)
{
	char			*result;
	t_expand_data	data;

	result = init_expansion(&data);
	if (!result)
		return (NULL);
	while (token[data.i])
	{
		if (handle_quotes(token[data.i], &data.in_dquote, &data.in_squote))
			data.i++;
		else if (process_special_chars(token, &data, result, shell))
			continue ;
		else if (token[data.i] == '$' && !data.in_squote && token[data.i + 1])
		{
			if (!process_var(token, &data, result, shell))
				result[data.j++] = '$';
		}
		else
			result[data.j++] = token[data.i++];
	}
	result[data.j] = '\0';
	return (result);
}
