#include <stddef.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t src_length;
	size_t count;

	if (!dst || !src)
		return (0);
	count = 0;
	src_length = 0;
	while (src[src_length])
		src_length++;
	if (size != 0)
	{
		while ((count < size - 1) && (count < src_length))
		{
			dst[count] = src[count];
			count++;
		}
		dst[count] = '\0';
	}
	return (src_length);
}
