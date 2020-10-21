#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	count;
	char	*s3;
	size_t	len_s1;
	size_t	len_s2;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	if (!s1 || !s2)
		return (NULL);
	count = 0;
	s3 = (char *)malloc(len_s1 + len_s2 + 1);
	if (!s3)
		return (NULL);
	while (count < (len_s1 + len_s2))
	{
		if (count < len_s1)
			s3[count] = s1[count];
		if (count >= len_s1 && count < len_s2 + len_s1)
			s3[count] = s2[count - len_s1];
		count++;
	}
	s3[count] = '\0';
	return (s3);
}
