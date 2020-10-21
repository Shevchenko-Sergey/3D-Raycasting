#include "libft.h"

static		int		ft_num(char const *s, char c)
{
	int		count;
	int		number;

	number = 0;
	count = 0;
	while (s[count])
	{
		if (s[count] != c && (s[count + 1] == c || s[count + 1] == '\0'))
			number++;
		count++;
	}
	return (number);
}

static		char	**ft_free(char **words, int n)
{
	while (n-- > 0)
		free(words[n]);
	free(words);
	return (NULL);
}

static		char	**ft_words(char const *s, char c, char **words)
{
	int count;
	int n;
	int t;
	int swap;

	count = 0;
	n = 0;
	while (s[count] && n < ft_num(s, c))
	{
		while (s[count] == c)
			count++;
		swap = count;
		while (s[count] != c && s[count])
			count++;
		if (!(words[n] = malloc(sizeof(char) * (count - swap + 1))))
			return (words = ft_free(words, n));
		t = 0;
		count = swap;
		while (s[count] != c && s[count])
			words[n][t++] = s[count++];
		words[n][t] = '\0';
		n++;
	}
	words[n] = NULL;
	return (words);
}

char				**ft_split(char const *s, char c)
{
	char	**words;

	if (!s)
		return (NULL);
	if (!(words = (char**)malloc(sizeof(char*) * (ft_num(s, c) + 1))))
		return (NULL);
	words = ft_words(s, c, words);
	return (words);
}
