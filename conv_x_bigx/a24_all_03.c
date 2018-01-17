#include "conv_x_bigx_test.h"

int		x_all_03(void)
{
	t_data	data;
	int		pfd[2];
	int		ret;
	int		save_stdout;

	ft_connect_stdout(pfd, &save_stdout);
	data.r1 = ft_printf("toto %0##0.4X%#4.2xet c'est fini \n", 0x037a, 0x9e);
	data.s1 = ft_get_stdout(pfd, &save_stdout);
	ft_connect_stdout(pfd, &save_stdout);
	data.r2 = printf("toto %0##0.4X%#4.2xet c'est fini \n", 0x037a, 0x9e);
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
