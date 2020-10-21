#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*new_str;
	int		count;

	count = 0;
	new_str = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!(new_str))
		return (NULL);
	else
		while (s[count])
		{
			new_str[count] = s[count];
			count++;
		}
	new_str[count] = '\0';
	return ((char *)new_str);
}
