#include <stddef.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t src_length;
	size_t dst_length;
	size_t count;

	count = 0;
	src_length = 0;
	dst_length = 0;
	while (src[src_length])
		src_length++;
	while (dst[dst_length])
		dst_length++;
	if (size != 0 && size > dst_length)
	{
		while ((count < ((size - 1) - dst_length)) && (count < src_length))
		{
			dst[count + dst_length] = src[count];
			count++;
		}
		dst[count + dst_length] = '\0';
		return (dst_length + src_length);
	}
	return (src_length + size);
}
