#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char *str;

	str = s;
	while (n--)
		str[n] = c;
	return (s);
}
