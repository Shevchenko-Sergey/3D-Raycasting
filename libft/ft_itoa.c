#include "libft.h"

static		int		ft_capacity(int n)
{
	int				sign;
	int				number;
	unsigned	int	nu;

	sign = -1;
	number = 0;
	nu = n;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		nu = sign * n;
		number++;
	}
	while (nu >= 1)
	{
		nu = nu / 10;
		number++;
	}
	return (number);
}

char				*ft_itoa(int n)
{
	int				count;
	int				dig;
	unsigned	int	nu;
	char			*string;

	dig = ft_capacity(n);
	if (!(string = malloc(dig + 1)))
		return (NULL);
	count = dig;
	nu = n;
	if (n < 0)
	{
		string[0] = '-';
		nu = -1 * n;
		count = dig - 1;
	}
	string[dig] = '\0';
	dig--;
	while (count > 0)
	{
		string[dig--] = (nu % 10) + '0';
		count--;
		nu /= 10;
	}
	return (string);
}
