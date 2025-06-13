/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nporras- <nporras-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 14:25:20 by nporras-          #+#    #+#             */
/*   Updated: 2025/06/04 14:25:31 by nporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	extract_delimiter_token(char *input, int i, t_token **tokens)
{
	int		len;
	char	*token_str;

	if ((input[i] == '<' || input[i] == '>') && input[i + 1] == input[i])
		len = 2;
	else
		len = 1;
	token_str = ft_substr(input, i, len);
	add_token(tokens, get_token_type(&input[i]), token_str);
	free(token_str);
	return (len);
}

static int	extract_word_token(char *input, int i, t_token **tokens)
{
	int		start;
	char	*token_str;
	int		len;
	int		has_quotes;
	char	quote_char;

	start = i;
	has_quotes = 0;
	while (input[i] && !is_space(input[i]) && !is_delimiter(input[i]))
	{
		if (input[i] == '\'' || input[i] == '\"')
		{
			quote_char = input[i];
			i = handle_quoted_word(input, i, quote_char, &has_quotes);
		}
		else
			i++;
	}
	len = i - start;
	token_str = ft_substr(input, start, len);
	add_token(tokens, TOKEN_WORD, token_str);
	free(token_str);
	return (len);
}

static int	extract_token(char *input, int i, t_token **tokens)
{
	if (!input[i])
		return (0);
	if (is_delimiter(input[i]))
		return (extract_delimiter_token(input, i, tokens));
	else
		return (extract_word_token(input, i, tokens));
}

void	free_tokens(t_token *tokens)
{
	t_token	*tmp;

	while (tokens)
	{
		tmp = tokens;
		tokens = tokens->next;
		free(tmp->value);
		free(tmp);
	}
}

t_token	*tokenize(char *input)
{
	t_token	*tokens;
	int		i;
	int		len;

	tokens = NULL;
	if (!check_quotes(input))
		return (NULL);
	i = 0;
	while (input[i])
	{
		if (is_space(input[i]))
		{
			i++;
			continue ;
		}
		len = extract_token(input, i, &tokens);
		if (len == 0)
			break ;
		i += len;
	}
	return (tokens);
}
