int	ft_atoi(const char *str)
{
	int n;
	int ret;
	int set;
	int sign;

	n = 0;
	ret = 0;
	sign = 1;
	while (str[n] && (str[n] == '\n' || str[n] == ' ' || str[n] == '\t' \
		|| str[n] == '\f' || str[n] == '\r' || str[n] == '\v'))
		n++;
	if (str[n] == '-')
		sign = -1;
	if (str[n] == '+' || str[n] == '-')
		n++;
	while (str[n] && str[n] >= '0' && str[n] <= '9')
	{
		set = str[n] - '0';
		ret = ret * 10 + set;
		n++;
	}
	return (ret * sign);
}
