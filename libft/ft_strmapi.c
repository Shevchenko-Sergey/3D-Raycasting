#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned	int	count;
	char			*string;

	if (!s)
		return (NULL);
	count = 0;
	string = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!string)
		return (NULL);
	else
		while (s[count])
		{
			string[count] = f(count, s[count]);
			count++;
		}
	string[count] = '\0';
	return (string);
}
