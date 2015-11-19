#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int		i;
	int		j;
	int		tmp;

	i = -1;
	if (n == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
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
		ft_putchar_fd(tmp % 10 + '0', fd);
		i--;
	}
}
