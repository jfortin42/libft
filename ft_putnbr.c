#include "libft.h"

char	*ft_putnbr(int n)
{
	int		i;
	int		j;
	int		tmp;
	char	*str;

	i = -1;
	if (n == -2147483648)
		ft_putstr("-2147483648");
	else if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	tmp = n;
	while (i++, tmp >= 10)
		tmp = tmp / 10;
	while (i >= 0 && n != -2147483648)
	{
		tmp = n;
		j = 0;
		while (j++ < i)
			tmp = tmp / 10;
		ft_putchar(tmp % 10 + '0');
		i--;
	}
}
