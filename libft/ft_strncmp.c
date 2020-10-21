#include <stddef.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t				count;
	const unsigned char	*s1_ft;
	const unsigned char	*s2_ft;

	s1_ft = (const unsigned char *)s1;
	s2_ft = (const unsigned char *)s2;
	count = 0;
	while (count < n && (s1_ft[count] || s2_ft[count]))
	{
		if (s1_ft[count] - s2_ft[count] != 0)
			return (s1_ft[count] - s2_ft[count]);
		count++;
	}
	return (0);
}
