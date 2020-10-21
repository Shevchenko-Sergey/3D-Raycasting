#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*dest_str;
	unsigned char	*src_str;
	size_t			count;

	if (!(dest) && !(src))
		return (NULL);
	dest_str = (unsigned char *)dest;
	src_str = (unsigned char *)src;
	count = 0;
	while (count < n)
	{
		dest_str[count] = src_str[count];
		count++;
	}
	return (dest);
}
