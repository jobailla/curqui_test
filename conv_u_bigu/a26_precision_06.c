#include "conv_u_bigu_test.h"

int		u_precision_06(void)
{
	t_data	data;
	int		pfd[2];
	int		ret;
	int		save_stdout;

	ft_connect_stdout(pfd, &save_stdout);
	data.r1 = ft_printf("%.0U", 0);
	data.s1 = ft_get_stdout(pfd, &save_stdout);
	ft_connect_stdout(pfd, &save_stdout);
	data.r2 = printf("%.0U", 0);
	data.s2 = ft_get_stdout(pfd, &save_stdout);
	ret = 0;
	if (data.r1 != data.r2)
		ret = -1;
	if (ft_strcmp(data.s1, data.s2))
		ret = -1;
	if (ret == -1)
		printf("\t\t\t\t\t\t   printf: [%s]\tret = %d\n\t\t\t\t\t\tft_printf: [%s]\tret = %d\n", data.s2, data.r2, data.s1, data.r1);
	ft_strdel(&data.s1);
	ft_strdel(&data.s2);
	return (ret);
}
