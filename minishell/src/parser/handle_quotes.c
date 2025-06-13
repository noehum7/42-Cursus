/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nporras- <nporras-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 14:23:56 by nporras-          #+#    #+#             */
/*   Updated: 2025/06/04 14:24:13 by nporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	validate_quote_pair(char *input, int i, char quote_char)
{
	i++;
	while (input[i] && input[i] != quote_char)
		i++;
	if (!input[i])
		return (-1);
	return (i);
}

int	handle_quotes(char c, int *in_dquote, int *in_squote)
{
	if (c == '\"' && !*in_squote)
	{
		*in_dquote = !*in_dquote;
		return (1);
	}
	else if (c == '\'' && !*in_dquote)
	{
		*in_squote = !*in_squote;
		return (1);
	}
	return (0);
}

int	handle_quoted_word(char *input, int i, char quote_char, int *has_quotes)
{
	i++;
	*has_quotes = 1;
	while (input[i] && input[i] != quote_char)
		i++;
	if (input[i])
		i++;
	return (i);
}

int	check_quotes(char *input)
{
	int	i;
	int	new_pos;

	i = 0;
	while (input[i])
	{
		if (input[i] == '\'' || input[i] == '\"')
		{
			new_pos = validate_quote_pair(input, i, input[i]);
			if (new_pos == -1)
			{
				ft_putstr_fd("minishell: syntax error: unclosed quote\n",
					STDERR_FILENO);
				return (0);
			}
			i = new_pos;
		}
		i++;
	}
	return (1);
}
