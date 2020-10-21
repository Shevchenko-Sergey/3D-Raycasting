#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)malloc(nmemb * size);
	if (!(ptr))
		return (NULL);
	else
		ft_memset(ptr, 0, nmemb * size);
	return (ptr);
}
