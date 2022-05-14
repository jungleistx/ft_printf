#include "./includes/ft_printf.h"

void plust(void)
{
		int i = 7, j = -7, k = 0;

	printf("\n%-8s|%+d|\t\t|%+d|\t|%+d|\n", "%+d", i, j, k);
	ft_printf("\t|%+d|\t\t|%+d|\t|%+d|\n",  i, j, k);
	printf("%-8s|%+1d|\t\t|%+1d|\t|%+1d|\n", "%+1d", i, j, k);
	ft_printf("\t|%+1d|\t\t|%+1d|\t|%+1d|\n",  i, j, k);
	printf("%-8s|%+3.0d|\t\t|%+3.0d|\t|%+3.0d|\n", "%+3.0d", i, j, k);
	ft_printf("\t|%+3.0d|\t\t|%+3.0d|\t|%+3.0d|\n",  i, j, k);
	printf("%-8s|%+4d|\t\t|%+4d|\t|%+4d|\n", "%+4d", i, j, k);
	ft_printf("\t|%+4d|\t\t|%+4d|\t|%+4d|\n",  i, j, k);
	printf("%-8s|%+.1d|\t\t|%+.1d|\t|%+.1d|\n", "%+.1d", i, j, k);
	ft_printf("\t|%+.1d|\t\t|%+.1d|\t|%+.1d|\n", i, j, k);
	printf("%-8s|%+.5d|\t|%+.5d|\t|%+.5d|\n", "%+.5d", i, j, k);
	ft_printf("\t|%+.5d|\t|%+.5d|\t|%+.5d|\n",  i, j, k);
	printf("%-8s|%+1.1d|\t\t|%+1.1d|\t|%+1.1d|\n", "%+1.1d", i, j, k);
	ft_printf("\t|%+1.1d|\t\t|%+1.1d|\t|%+1.1d|\n",  i, j, k);
	printf("%-8s|%+1.5d|\t|%+1.5d|\t|%+1.5d|\n", "%+1.5d", i, j, k);
	ft_printf("\t|%+1.5d|\t|%+1.5d|\t|%+1.5d|\n",  i, j, k);
	printf("%-8s|%+3.5d|\t|%+3.5d|\t|%+3.5d|\n", "%+3.5d", i, j, k);
	ft_printf("\t|%+3.5d|\t|%+3.5d|\t|%+3.5d|\n", i, j, k);
	printf("%-8s|%+4.1d|\t\t|%+4.1d|\t|%+4.1d|\n", "%+4.1d", i, j, k);
	ft_printf("\t|%+4.1d|\t\t|%+4.1d|\t|%+4.1d|\n",  i, j, k);
	printf("%-8s|%+5.2d|\t\t|%+5.2d|\t|%+5.2d|\n", "%+5.2d", i, j, k);
	ft_printf("\t|%+5.2d|\t\t|%+5.2d|\t|%+5.2d|\n", i, j, k);
	printf("%-8s|%+5.0d|\t\t|%+5.0d|\t|%+5.0d|\n", "%+5.0d", i, j, k);
	ft_printf("\t|%+5.0d|\t\t|%+5.0d|\t|%+5.0d|\n",  i, j, k);
	printf("%-8s|%+0d|\t\t|%+0d|\t|%+0d|\n", "%+0d", i, j, k);
	ft_printf("\t|%+0d|\t\t|%+0d|\t|%+0d|\n",  i, j, k);
	printf("%-8s|%+01d|\t\t|%+01d|\t|%+01d|\n", "%+01d", i, j, k);
	ft_printf("\t|%+01d|\t\t|%+01d|\t|%+01d|\n",  i, j, k);
	printf("%-8s|%+04d|\t\t|%+04d|\t|%+04d|\n", "%+04d", i, j, k);
	ft_printf("\t|%+04d|\t\t|%+04d|\t|%+04d|\n",  i, j, k);
	printf("%-8s|%+0.0d|\t\t|%+0.0d|\t|%+0.0d|\n", "%+0.0d", i, j, k);
	ft_printf("\t|%+0.0d|\t\t|%+0.0d|\t|%+0.0d|\n",  i, j, k);
	printf("%-8s|%+0.2d|\t\t|%+0.2d|\t|%+0.2d|\n", "%+0.2d", i, j, k);
	ft_printf("\t|%+0.2d|\t\t|%+0.2d|\t|%+0.2d|\n",  i, j, k);
	printf("%-8s|%+0.5d|\t|%+0.5d|\t|%+0.5d|\n", "%+0.5d", i, j, k);
	ft_printf("\t|%+0.5d|\t|%+0.5d|\t|%+0.5d|\n",  i, j, k);
	printf("%-8s|%+04.0d|\t\t|%+04.0d|\t|%+04.0d|\n", "%+04.0d", i, j, k);
	ft_printf("\t|%+04.0d|\t\t|%+04.0d|\t|%+04.0d|\n",  i, j, k);
	printf("%-8s|%+04.2d|\t\t|%+04.2d|\t|%+04.2d|\n", "%+04.2d", i, j, k);
	ft_printf("\t|%+04.2d|\t\t|%+04.2d|\t|%+04.2d|\n",  i, j, k);
	printf("%-8s|%+02.2d|\t\t|%+02.2d|\t|%+02.2d|\n", "%+02.2d", i, j, k);
	ft_printf("\t|%+02.2d|\t\t|%+02.2d|\t|%+02.2d|\n", i, j, k);
	printf("%-8s|%+02.5d|\t|%+02.5d|\t|%+02.5d|\n", "%+02.5d", i, j, k);
	ft_printf("\t|%+02.5d|\t|%+02.5d|\t|%+02.5d|\n",  i, j, k);
	printf("%-8s|%+-d|\t\t|%+-d|\t|%+-d|\n", "%+-d", i, j, k);
	ft_printf("\t|%+-d|\t\t|%+-d|\t|%+-d|\n", i, j, k);
	printf("%-8s|%+-1d|\t\t|%+-1d|\t|%+-1d|\n", "%+-1d", i, j, k);
	ft_printf("\t|%+-1d|\t\t|%+-1d|\t|%+-1d|\n",  i, j, k);
	printf("%-8s|%+-2d|\t\t|%+-2d|\t|%+-2d|\n", "%+-2d", i, j, k);
	ft_printf("\t|%+-2d|\t\t|%+-2d|\t|%+-2d|\n",  i, j, k);
	printf("%-8s|%+-4d|\t\t|%+-4d|\t|%+-4d|\n", "%+-4d", i, j, k);
	ft_printf("\t|%+-4d|\t\t|%+-4d|\t|%+-4d|\n",  i, j, k);
	printf("%-8s|%+-2.0d|\t\t|%+-2.0d|\t|%+-2.0d|\n", "%+-2.0d", i, j, k);
	ft_printf("\t|%+-2.0d|\t\t|%+-2.0d|\t|%+-2.0d|\n",  i, j, k);
	printf("%-8s|%+-2.1d|\t\t|%+-2.1d|\t|%+-2.1d|\n", "%+-2.1d", i, j, k);
	ft_printf("\t|%+-2.1d|\t\t|%+-2.1d|\t|%+-2.1d|\n",  i, j, k);
	printf("%-8s|%+-2.5d|\t|%+-2.5d|\t|%+-2.5d|\n", "%+-2.5d", i, j, k);
	ft_printf("\t|%+-2.5d|\t|%+-2.5d|\t|%+-2.5d|\n", i, j, k);
	printf("%-8s|%+-4.1d|\t\t|%+-4.1d|\t|%+-4.1d|\n", "%+-4.1d", i, j, k);
	ft_printf("\t|%+-4.1d|\t\t|%+-4.1d|\t|%+-4.1d|\n",  i, j, k);
	printf("%-8s|%+-4.5d|\t|%+-4.5d|\t|%+-4.5d|\n", "%+-4.5d", i, j, k);
	ft_printf("\t|%+-4.5d|\t|%+-4.5d|\t|%+-4.5d|\n", i, j, k);
	printf("%-8s|%+-4.6d|\t|%+-4.6d|\t|%+-4.6d|\n", "%+-4.6d", i, j, k);
	ft_printf("\t|%+-4.6d|\t|%+-4.6d|\t|%+-4.6d|\n",  i, j, k);
	printf("%-8s|%+-6.5d|\t|%+-6.5d|\t|%+-6.5d|\n", "%+-6.5d", i, j, k);
	ft_printf("\t|%+-6.5d|\t|%+-6.5d|\t|%+-6.5d|\n",  i, j, k);
	printf("%-8s|%+-6.3d|\t|%+-6.3d|\t|%+-6.3d|\n", "%+-6.3d", i, j, k);
	ft_printf("\t|%+-6.3d|\t|%+-6.3d|\t|%+-6.3d|\n",  i, j, k);
	printf("%-8s|%+-.0d|\t\t|%+-.0d|\t|%+-.0d|\n", "%+-.0d", i, j, k);
	ft_printf("\t|%+-.0d|\t\t|%+-.0d|\t|%+-.0d|\n",  i, j, k);
	printf("%-8s|%+-.2d|\t|%+-.2d|\t|%+-.2d|\n", "%+-.2d", i, j, k);
	ft_printf("\t|%+-.2d|\t|%+-.2d|\t|%+-.2d|\n",  i, j, k);
	printf("%-8s|%+-.5d|\t|%+-.5d|\t|%+-.5d|\n", "%+-.5d", i, j, k);
	ft_printf("\t|%+-.5d|\t|%+-.5d|\t|%+-.5d|\n",  i, j, k);

}
void minust(void)
{
		int i = 7, j = -7, k = 0;

	printf("\n%-8s|%-d|\t\t|%-d|\t|%-d|\n", "%-d", i, j, k);
	ft_printf("\t|%-d|\t\t|%-d|\t|%-d|\n", i, j, k);
	printf("%-8s|%-.1d|\t\t|%-.1d|\t|%-.1d|\n", "%-.1d", i, j, k);
	ft_printf("\t|%-.1d|\t\t|%-.1d|\t|%-.1d|\n",  i, j, k);
	printf("%-8s|%-.5d|\t\t|%-.5d|\t|%-.5d|\n", "%-.5d", i, j, k);
	ft_printf("\t|%-.5d|\t\t|%-.5d|\t|%-.5d|\n",  i, j, k);
	printf("%-8s|%-1d|\t\t|%-1d|\t|%-1d|\n", "%-1d", i, j, k);
	ft_printf("\t|%-1d|\t\t|%-1d|\t|%-1d|\n",  i, j, k);
	printf("%-8s|%-1.2d|\t\t|%-1.2d|\t|%-1.2d|\n", "%-1.2d", i, j, k);
	ft_printf("\t|%-1.2d|\t\t|%-1.2d|\t|%-1.2d|\n", i, j, k);
	printf("%-8s|%-1.6d|\t|%-1.6d|\t|%-1.6d|\n", "%-1.6d", i, j, k);
	ft_printf("\t|%-1.6d|\t|%-1.6d|\t|%-1.6d|\n", i, j, k);
	printf("%-8s|%-2d|\t\t|%-2d|\t|%-2d|\n", "%-2d", i, j, k);
	ft_printf("\t|%-2d|\t\t|%-2d|\t|%-2d|\n", i, j, k);
	printf("%-8s|%-2.0d|\t\t|%-2.0d|\t|%-2.0d|\n", "%-2.0d", i, j, k);
	ft_printf("\t|%-2.0d|\t\t|%-2.0d|\t|%-2.0d|\n", i, j, k);
	printf("%-8s|%-4d|\t\t|%-4d|\t|%-4d|\n", "%-4d", i, j, k);
	ft_printf("\t|%-4d|\t\t|%-4d|\t|%-4d|\n",  i, j, k);
	printf("%-8s|%-4.2d|\t\t|%-4.2d|\t|%-4.2d|\n", "%-4.2d", i, j, k);
	ft_printf("\t|%-4.2d|\t\t|%-4.2d|\t|%-4.2d|\n", i, j, k);
	printf("%-8s|%-4.6d|\t|%-4.6d|\t|%-4.6d|\n", "%-4.6d", i, j, k);
	ft_printf("\t|%-4.6d|\t|%-4.6d|\t|%-4.6d|\n",  i, j, k);
	printf("%-8s|%- d|\t\t|%- d|\t|%- d|\n", "%- d", i, j, k);
	ft_printf("\t|%- d|\t\t|%- d|\t|%- d|\n",  i, j, k);
	printf("%-8s|%- .1d|\t\t|%- .1d|\t|%- .1d|\n", "%- .1d", i, j, k);
	ft_printf("\t|%- .1d|\t\t|%- .1d|\t|%- .1d|\n",  i, j, k);
	printf("%-8s|%- .4d|\t\t|%- .4d|\t|%- .4d|\n", "%- .4d", i, j, k);
	ft_printf("\t|%- .4d|\t\t|%- .4d|\t|%- .4d|\n",  i, j, k);
	printf("%-8s|%- 1d|\t\t|%- 1d|\t|%- 1d|\n", "%- 1d", i, j, k);
	ft_printf("\t|%- 1d|\t\t|%- 1d|\t|%- 1d|\n",  i, j, k);
	printf("%-8s|%- 1.1d|\t\t|%- 1.1d|\t|%- 1.1d|\n", "%- 1.1d", i, j, k);
	ft_printf("\t|%- 1.1d|\t\t|%- 1.1d|\t|%- 1.1d|\n", i, j, k);
	printf("%-8s|%- 1.5d|\t|%- 1.5d|\t|%- 1.5d|\n", "%- 1.5d", i, j, k);
	ft_printf("\t|%- 1.5d|\t|%- 1.5d|\t|%- 1.5d|\n",  i, j, k);
	printf("%-8s|%- 2d|\t\t|%- 2d|\t|%- 2d|\n", "%- 2d", i, j, k);
	ft_printf("\t|%- 2d|\t\t|%- 2d|\t|%- 2d|\n",  i, j, k);
	printf("%-8s|%- 4d|\t\t|%- 4d|\t|%- 4d|\n", "%- 4d", i, j, k);
	ft_printf("\t|%- 4d|\t\t|%- 4d|\t|%- 4d|\n",  i, j, k);
	printf("%-8s|%- 4.1d|\t\t|%- 4.1d|\t|%- 4.1d|\n", "%- 4.1d", i, j, k);
	ft_printf("\t|%- 4.1d|\t\t|%- 4.1d|\t|%- 4.1d|\n",  i, j, k);
	printf("%-8s|%- 4.5d|\t|%- 4.5d|\t|%- 4.5d|\n", "%- 4.5d", i, j, k);
	ft_printf("\t|%- 4.5d|\t|%- 4.5d|\t|%- 4.5d|\n",  i, j, k);
	printf("%-8s|%- 6.4d|\t|%- 6.4d|\t|%- 6.4d|\n", "%- 6.4d", i, j, k);
	ft_printf("\t|%- 6.4d|\t|%- 6.4d|\t|%- 6.4d|\n", i, j, k);
	printf("%-8s|%+-d|\t\t|%+-d|\t|%+-d|\n", "%+-d", i, j, k);
	ft_printf("\t|%+-d|\t\t|%+-d|\t|%+-d|\n", i, j, k);
	printf("%-8s|%+-1d|\t\t|%+-1d|\t|%+-1d|\n", "%+-1d", i, j, k);
	ft_printf("\t|%+-1d|\t\t|%+-1d|\t|%+-1d|\n",  i, j, k);
	printf("%-8s|%+-2d|\t\t|%+-2d|\t|%+-2d|\n", "%+-2d", i, j, k);
	ft_printf("\t|%+-2d|\t\t|%+-2d|\t|%+-2d|\n", i, j, k);
	printf("%-8s|%+-3.2d|\t\t|%+-3.2d|\t|%+-3.2d|\n", "%+-3.2d", i, j, k);
	ft_printf("\t|%+-3.2d|\t\t|%+-3.2d|\t|%+-3.2d|\n",  i, j, k);
	printf("%-8s|%+-2.5d|\t|%+-2.5d|\t|%+-2.5d|\n", "%+-2.5d", i, j, k);
	ft_printf("\t|%+-2.5d|\t|%+-2.5d|\t|%+-2.5d|\n",  i, j, k);
	printf("%-8s|%+-4d|\t\t|%+-4d|\t|%+-4d|\n", "%+-4d", i, j, k);
	ft_printf("\t|%+-4d|\t\t|%+-4d|\t|%+-4d|\n", i, j, k);
	printf("%-8s|%+-4.2d|\t\t|%+-4.2d|\t|%+-4.2d|\n", "%+-4.2d", i, j, k);
	ft_printf("\t|%+-4.2d|\t\t|%+-4.2d|\t|%+-4.2d|\n",  i, j, k);
	printf("%-8s|%+-3.5d|\t|%+-3.5d|\t|%+-3.5d|\n", "%+-3.5d", i, j, k);
	ft_printf("\t|%+-3.5d|\t|%+-3.5d|\t|%+-3.5d|\n", i, j, k);
}


void	spacet(void)
{
	int i = 7, j = -7, k = 0;

	printf("\n%-8s|% d|\t\t|% d|\t|%d|\n", "% d", i, j, k);
	ft_printf("\t|% d|\t\t|% d|\t|%d|\n",  i, j, k);
	printf("%-8s|% .1d|\t\t|% .1d|\t|% .1d|\n", "% .1d", i, j, k);
	ft_printf("\t|% .1d|\t\t|% .1d|\t|% .1d|\n",  i, j, k);
	printf("%-8s|% .0d|\t\t|% .0d|\t|% .0d|\n", "% .0d", i, j, k);
	ft_printf("\t|% .0d|\t\t|% .0d|\t|% .0d|\n",  i, j, k);
	printf("%-8s|% 3.0d|\t\t|% 3.0d|\t|% 3.0d|\n", "% 3.0d", i, j, k);
	ft_printf("\t|% 3.0d|\t\t|% 3.0d|\t|% 3.0d|\n",  i, j, k);
	printf("%-8s|% 1.0d|\t\t|% 1.0d|\t|% 1.0d|\n", "% 1.0d", i, j, k);
	ft_printf("\t|% 1.0d|\t\t|% 1.0d|\t|% 1.0d|\n",  i, j, k);
	printf("%-8s|% 0.0d|\t\t|% 0.0d|\t|% 0.0d|\n", "% 0.0d", i, j, k);
	ft_printf("\t|% 0.0d|\t\t|% 0.0d|\t|% 0.0d|\n",  i, j, k);
	printf("%-8s|% .4d|\t\t|% .4d|\t|% .4d|\n", "% .4d", i, j, k);
	ft_printf("\t|% .4d|\t\t|% .4d|\t|% .4d|\n", i, j, k);
	printf("%-8s|% 1.1d|\t\t|% 1.1d|\t|% 1.1d|\n", "% 1.1d", i, j, k);
	ft_printf("\t|% 1.1d|\t\t|% 1.1d|\t|% 1.1d|\n",  i, j, k);
	printf("%-8s|% 1.5d|\t|% 1.5d|\t|% 1.5d|\n", "% 1.5d", i, j, k);
	ft_printf("\t|% 1.5d|\t|% 1.5d|\t|% 1.5d|\n",  i, j, k);
	printf("%-8s|% 4.1d|\t\t|% 4.1d|\t|% 4.1d|\n", "% 4.1d", i, j, k);
	ft_printf("\t|% 4.1d|\t\t|% 4.1d|\t|% 4.1d|\n", i, j, k);
	printf("%-8s|% 3.2d|\t\t|% 3.2d|\t|% 3.2d|\n", "% 3.2d", i, j, k);
	ft_printf("\t|% 3.2d|\t\t|% 3.2d|\t|% 3.2d|\n", i, j, k);
	printf("%-8s|% 4.5d|\t|% 4.5d|\t|% 4.5d|\n", "% 4.5d", i, j, k);
	ft_printf("\t|% 4.5d|\t|% 4.5d|\t|% 4.5d|\n", i, j, k);
	printf("%-8s|% 6.3d|\t|% 6.3d|\t|% 6.3d|\n", "% 6.3d", i, j, k);
	ft_printf("\t|% 6.3d|\t|% 6.3d|\t|% 6.3d|\n",  i, j, k);
	printf("%-8s|% 6.5d|\t|% 6.5d|\t|% 6.5d|\n", "% 6.5d", i, j, k);
	ft_printf("\t|% 6.5d|\t|% 6.5d|\t|% 6.5d|\n",  i, j, k);
	printf("%-8s|% 6.4d|\t|% 6.4d|\t|% 6.4d|\n", "% 6.4d", i, j, k);
	ft_printf("\t|% 6.4d|\t|% 6.4d|\t|% 6.4d|\n",  i, j, k);
	printf("%-8s|% 0d|\t\t|% 0d|\t|% 0d|\n", "% 0d", i, j, k);
	ft_printf("\t|% 0d|\t\t|% 0d|\t|% 0d|\n", i, j, k);
	printf("%-8s|% 1d|\t\t|% 1d|\t|% 1d|\n", "% 1d", i, j, k);
	ft_printf("\t|% 1d|\t\t|% 1d|\t|% 1d|\n",  i, j, k);
	printf("%-8s|% 2d|\t\t|% 2d|\t|% 2d|\n", "% 2d", i, j, k);
	ft_printf("\t|% 2d|\t\t|% 2d|\t|% 2d|\n",  i, j, k);
	printf("%-8s|% 4d|\t\t|% 4d|\t|% 4d|\n", "% 4d", i, j, k);
	ft_printf("\t|% 4d|\t\t|% 4d|\t|% 4d|\n", i, j, k);
	printf("%-8s|% 01d|\t\t|% 01d|\t|% 01d|\n", "% 01d", i, j, k);
	ft_printf("\t|% 01d|\t\t|% 01d|\t|% 01d|\n",  i, j, k);
	printf("%-8s|% 02d|\t\t|% 02d|\t|% 02d|\n", "% 02d", i, j, k);
	ft_printf("\t|% 02d|\t\t|% 02d|\t|% 02d|\n", i, j, k);
	printf("%-8s|% 04d|\t\t|% 04d|\t|% 04d|\n", "% 04d", i, j, k);
	ft_printf("\t|% 04d|\t\t|% 04d|\t|% 04d|\n",  i, j, k);
	printf("%-8s|% 0.1d|\t\t|% 0.1d|\t|% 0.1d|\n", "% 0.1d", i, j, k);
	ft_printf("\t|% 0.1d|\t\t|% 0.1d|\t|% 0.1d|\n",  i, j, k);
	printf("%-8s|% 0.5d|\t|% 0.5d|\t|% 0.5d|\n", "% 0.5d", i, j, k);
	ft_printf("\t|% 0.5d|\t|% 0.5d|\t|% 0.5d|\n",  i, j, k);
	printf("%-8s|% 01.5d|\t|% 01.5d|\t|% 01.5d|\n", "% 01.5d", i, j, k);
	ft_printf("\t|% 01.5d|\t|% 01.5d|\t|% 01.5d|\n",  i, j, k);
	printf("%-8s|% 04.1d|\t\t|% 04.1d|\t|% 04.1d|\n", "% 04.1d", i, j, k);
	ft_printf("\t|% 04.1d|\t\t|% 04.1d|\t|% 04.1d|\n",  i, j, k);
	printf("%-8s|% 04.6d|\t|% 04.6d|\t|% 04.6d|\n", "% 04.6d", i, j, k);
	ft_printf("\t|% 04.6d|\t|% 04.6d|\t|% 04.6d|\n",  i, j, k);
	printf("%-8s|% 05.3d|\t\t|% 05.3d|\t|% 05.3d|\n", "% 05.3d", i, j, k);
	ft_printf("\t|% 05.3d|\t\t|% 05.3d|\t|% 05.3d|\n", i, j, k);
	printf("%-8s|%- d|\t\t|%- d|\t|%- d|\n", "%- d", i, j, k);
	ft_printf("\t|%- d|\t\t|%- d|\t|%- d|\n", i, j, k);
	printf("%-8s|%- 1d|\t\t|%- 1d|\t|%- 1d|\n", "%- 1d", i, j, k);
	ft_printf("\t|%- 1d|\t\t|%- 1d|\t|%- 1d|\n",  i, j, k);
	printf("%-8s|%- 2d|\t\t|%- 2d|\t|%- 2d|\n", "%- 2d", i, j, k);
	ft_printf("\t|%- 2d|\t\t|%- 2d|\t|%- 2d|\n",  i, j, k);
	printf("%-8s|%- 4d|\t\t|%- 4d|\t|%- 4d|\n", "%- 4d", i, j, k);
	ft_printf("\t|%- 4d|\t\t|%- 4d|\t|%- 4d|\n",  i, j, k);
	printf("%-8s|%- .0d|\t\t|%- .0d|\t|%- .0d|\n", "%- .0d", i, j, k);
	ft_printf("\t|%- .0d|\t\t|%- .0d|\t|%- .0d|\n",  i, j, k);
	printf("%-8s|%- .1d|\t\t|%- .1d|\t|%- .1d|\n", "%- .1d", i, j, k);
	ft_printf("\t|%- .1d|\t\t|%- .1d|\t|%- .1d|\n",  i, j, k);
	printf("%-8s|%- .5d|\t|%- .5d|\t|%- .5d|\n", "%- .5d", i, j, k);
	ft_printf("\t|%- .5d|\t|%- .5d|\t|%- .5d|\n",  i, j, k);
	printf("%-8s|%- 1.1d|\t\t|%- 1.1d|\t|%- 1.1d|\n", "%- 1.1d", i, j, k);
	ft_printf("\t|%- 1.1d|\t\t|%- 1.1d|\t|%- 1.1d|\n",  i, j, k);
	printf("%-8s|%- 1.5d|\t|%- 1.5d|\t|%- 1.5d|\n", "%- 1.5d", i, j, k);
	ft_printf("\t|%- 1.5d|\t|%- 1.5d|\t|%- 1.5d|\n",  i, j, k);
	printf("%-8s|%- 4.0d|\t\t|%- 4.0d|\t|%- 4.0d|\n", "%- 4.0d", i, j, k);
	ft_printf("\t|%- 4.0d|\t\t|%- 4.0d|\t|%- 4.0d|\n",  i, j, k);
	printf("%-8s|%- 4.1d|\t\t|%- 4.1d|\t|%- 4.1d|\n", "%- 4.1d", i, j, k);
	ft_printf("\t|%- 4.1d|\t\t|%- 4.1d|\t|%- 4.1d|\n",  i, j, k);
	printf("%-8s|%- 4.6d|\t|%- 4.6d|\t|%- 4.6d|\n", "%- 4.6d", i, j, k);
	ft_printf("\t|%- 4.6d|\t|%- 4.6d|\t|%- 4.6d|\n", i, j, k);
	printf("%-8s|%- 6.3d|\t|%- 6.3d|\t|%- 6.3d|\n", "%- 6.3d", i, j, k);
	ft_printf("\t|%- 6.3d|\t|%- 6.3d|\t|%- 6.3d|\n",  i, j, k);
}
void	widt(void)
{
		int i = 7, j = -7, k = 0;

	printf("\n%-8s|%1d|\t\t|%1d|\t|%1d|\n", "%1d", i, j, k);
	ft_printf("\t|%1d|\t\t|%1d|\t|%1d|\n",  i, j, k);
	printf("%-8s|%2d|\t\t|%2d|\t|%2d|\n", "%2d", i, j, k);
	ft_printf("\t|%2d|\t\t|%2d|\t|%2d|\n",  i, j, k);
	printf("%-8s|%4d|\t\t|%4d|\t|%4d|\n", "%4d", i, j, k);
	ft_printf("\t|%4d|\t\t|%4d|\t|%4d|\n",  i, j, k);
	printf("%-8s|% 1d|\t\t|% 1d|\t|% 1d|\n", "% 1d", i, j, k);
	ft_printf("\t|% 1d|\t\t|% 1d|\t|% 1d|\n",  i, j, k);
	printf("%-8s|% 1.1d|\t\t|% 1.1d|\t|% 1.1d|\n", "% 1.1d", i, j, k);
	ft_printf("\t|% 1.1d|\t\t|% 1.1d|\t|% 1.1d|\n",  i, j, k);
	printf("%-8s|% 1.5d|\t|% 1.5d|\t|% 1.5d|\n", "% 1.5d", i, j, k);
	ft_printf("\t|% 1.5d|\t|% 1.5d|\t|% 1.5d|\n", i, j, k);
	printf("%-8s|% 2d|\t\t|% 2d|\t|% 2d|\n", "% 2d", i, j, k);
	ft_printf("\t|% 2d|\t\t|% 2d|\t|% 2d|\n",  i, j, k);
	printf("%-8s|% 4d|\t\t|% 4d|\t|% 4d|\n", "% 4d", i, j, k);
	ft_printf("\t|% 4d|\t\t|% 4d|\t|% 4d|\n",  i, j, k);
	printf("%-8s|% 4.5d|\t|% 4.5d|\t|% 4.5d|\n", "% 4.5d", i, j, k);
	ft_printf("\t|% 4.5d|\t|% 4.5d|\t|% 4.5d|\n",  i, j, k);
	printf("%-8s|% 4.1d|\t\t|% 4.1d|\t|% 4.1d|\n", "% 4.1d", i, j, k);
	ft_printf("\t|% 4.1d|\t\t|% 4.1d|\t|% 4.1d|\n",  i, j, k);
	printf("%-8s|% 6.4d|\t|% 6.4d|\t|% 6.4d|\n", "% 6.4d", i, j, k);
	ft_printf("\t|% 6.4d|\t|% 6.4d|\t|% 6.4d|\n",  i, j, k);
	printf("%-8s|% 01.5d|\t|% 01.5d|\t|% 01.5d|\n", "% 01.5d", i, j, k);
	ft_printf("\t|% 01.5d|\t|% 01.5d|\t|% 01.5d|\n",  i, j, k);
	printf("%-8s|% 01d|\t\t|% 01d|\t|% 01d|\n", "% 01d", i, j, k);
	ft_printf("\t|% 01d|\t\t|% 01d|\t|% 01d|\n", i, j, k);
	printf("%-8s|% 04d|\t\t|% 04d|\t|% 04d|\n", "% 04d", i, j, k);
	ft_printf("\t|% 04d|\t\t|% 04d|\t|% 04d|\n",  i, j, k);
	printf("%-8s|% 02d|\t\t|% 02d|\t|% 02d|\n", "% 02d", i, j, k);
	ft_printf("\t|% 02d|\t\t|% 02d|\t|% 02d|\n", i, j, k);
	printf("%-8s|% 04.1d|\t\t|% 04.1d|\t|% 04.1d|\n", "% 04.1d", i, j, k);
	ft_printf("\t|% 04.1d|\t\t|% 04.1d|\t|% 04.1d|\n",  i, j, k);
	printf("%-8s|% 04.5d|\t|% 04.5d|\t|% 04.5d|\n", "% 04.5d", i, j, k);
	ft_printf("\t|% 04.5d|\t|% 04.5d|\t|% 04.5d|\n",  i, j, k);
	printf("%-8s|% 05.3d|\t\t|% 05.3d|\t|% 05.3d|\n", "% 05.3d", i, j, k);
	ft_printf("\t|% 05.3d|\t\t|% 05.3d|\t|% 05.3d|\n",  i, j, k);
	printf("%-8s|%01d|\t\t|%01d|\t|%01d|\n", "%01d", i, j, k);
	ft_printf("\t|%01d|\t\t|%01d|\t|%01d|\n",  i, j, k);
	printf("%-8s|%01.4d|\t\t|%01.4d|\t|%01.4d|\n", "%01.4d", i, j, k);
	ft_printf("\t|%01.4d|\t\t|%01.4d|\t|%01.4d|\n",  i, j, k);
	printf("%-8s|%02d|\t\t|%02d|\t|%02d|\n", "%02d", i, j, k);
	ft_printf("\t|%02d|\t\t|%02d|\t|%02d|\n",  i, j, k);
	printf("%-8s|%04d|\t\t|%04d|\t|%04d|\n", "%04d", i, j, k);
	ft_printf("\t|%04d|\t\t|%04d|\t|%04d|\n",  i, j, k);
	printf("%-8s|%04.6d|\t|%04.6d|\t|%04.6d|\n", "%04.6d", i, j, k);
	ft_printf("\t|%04.6d|\t|%04.6d|\t|%04.6d|\n", i, j, k);
	printf("%-8s|%06.4d|\t|%06.4d|\t|%06.4d|\n", "%06.4d", i, j, k);
	ft_printf("\t|%06.4d|\t|%06.4d|\t|%06.4d|\n",  i, j, k);
	printf("%-8s|%- 1d|\t\t|%- 1d|\t|%- 1d|\n", "%- 1d", i, j, k);
	ft_printf("\t|%- 1d|\t\t|%- 1d|\t|%- 1d|\n",  i, j, k);
	printf("%-8s|%- 1.1d|\t\t|%- 1.1d|\t|%- 1.1d|\n", "%- 1.1d", i, j, k);
	ft_printf("\t|%- 1.1d|\t\t|%- 1.1d|\t|%- 1.1d|\n",  i, j, k);
	printf("%-8s|%- 1.5d|\t|%- 1.5d|\t|%- 1.5d|\n", "%- 1.5d", i, j, k);
	ft_printf("\t|%- 1.5d|\t|%- 1.5d|\t|%- 1.5d|\n",  i, j, k);
	printf("%-8s|%- 2d|\t\t|%- 2d|\t|%- 2d|\n", "%- 2d", i, j, k);
	ft_printf("\t|%- 2d|\t\t|%- 2d|\t|%- 2d|\n",  i, j, k);
	printf("%-8s|%- 4d|\t\t|%- 4d|\t|%- 4d|\n", "%- 4d", i, j, k);
	ft_printf("\t|%- 4d|\t\t|%- 4d|\t|%- 4d|\n",  i, j, k);
	printf("%-8s|%- 5.3d|\t\t|%- 5.3d|\t|%- 5.3d|\n", "%- 5.3d", i, j, k);
	ft_printf("\t|%- 5.3d|\t\t|%- 5.3d|\t|%- 5.3d|\n",  i, j, k);
	printf("%-8s|%- 4.5d|\t|%- 4.5d|\t|%- 4.5d|\n", "%- 4.5d", i, j, k);
	ft_printf("\t|%- 4.5d|\t|%- 4.5d|\t|%- 4.5d|\n", i, j, k);
	printf("%-8s|%- 6.4d|\t|%- 6.4d|\t|%- 6.4d|\n", "%- 6.4d", i, j, k);
	ft_printf("\t|%- 6.4d|\t|%- 6.4d|\t|%- 6.4d|\n",  i, j, k);
	printf("%-8s|%+-1d|\t\t|%+-1d|\t|%+-1d|\n", "%+-1d", i, j, k);
	ft_printf("\t|%+-1d|\t\t|%+-1d|\t|%+-1d|\n", i, j, k);
	printf("%-8s|%+-2d|\t\t|%+-2d|\t|%+-2d|\n", "%+-2d", i, j, k);
	ft_printf("\t|%+-2d|\t\t|%+-2d|\t|%+-2d|\n",  i, j, k);
	printf("%-8s|%+-3.2d|\t\t|%+-3.2d|\t|%+-3.2d|\n", "%+-3.2d", i, j, k);
	ft_printf("\t|%+-3.2d|\t\t|%+-3.2d|\t|%+-3.2d|\n",  i, j, k);
	printf("%-8s|%+-3.5d|\t|%+-3.5d|\t|%+-3.5d|\n", "%+-3.5d", i, j, k);
	ft_printf("\t|%+-3.5d|\t|%+-3.5d|\t|%+-3.5d|\n",  i, j, k);
	printf("%-8s|%+-4d|\t\t|%+-4d|\t|%+-4d|\n", "%+-4d", i, j, k);
	ft_printf("\t|%+-4d|\t\t|%+-4d|\t|%+-4d|\n",  i, j, k);
	printf("%-8s|%+-4.0d|\t\t|%+-4.0d|\t|%+-4.0d|\n", "%+-4.0d", i, j, k);
	ft_printf("\t|%+-4.0d|\t\t|%+-4.0d|\t|%+-4.0d|\n",  i, j, k);
	printf("%-8s|%+-4.2d|\t\t|%+-4.2d|\t|%+-4.2d|\n", "%+-4.2d", i, j, k);
	ft_printf("\t|%+-4.2d|\t\t|%+-4.2d|\t|%+-4.2d|\n",  i, j, k);
	printf("%-8s|%+-4.6d|\t|%+-4.6d|\t|%+-4.6d|\n", "%+-4.6d", i, j, k);
	ft_printf("\t|%+-4.6d|\t|%+-4.6d|\t|%+-4.6d|\n", i, j, k);
	printf("%-8s|%+-6.3d|\t|%+-6.3d|\t|%+-6.3d|\n", "%+-6.3d", i, j, k);
	ft_printf("\t|%+-6.3d|\t|%+-6.3d|\t|%+-6.3d|\n",  i, j, k);
	printf("%-8s|%-1d|\t\t|%-1d|\t|%-1d|\n", "%-1d", i, j, k);
	ft_printf("\t|%-1d|\t\t|%-1d|\t|%-1d|\n",  i, j, k);
	printf("%-8s|%-1.2d|\t\t|%-1.2d|\t|%-1.2d|\n", "%-1.2d", i, j, k);
	ft_printf("\t|%-1.2d|\t\t|%-1.2d|\t|%-1.2d|\n",  i, j, k);
	printf("%-8s|%-1.6d|\t|%-1.6d|\t|%-1.6d|\n", "%-1.6d", i, j, k);
	ft_printf("\t|%-1.6d|\t|%-1.6d|\t|%-1.6d|\n",  i, j, k);
	printf("%-8s|%-2d|\t\t|%-2d|\t|%-2d|\n", "%-2d", i, j, k);
	ft_printf("\t|%-2d|\t\t|%-2d|\t|%-2d|\n", i, j, k);
	printf("%-8s|%-4d|\t\t|%-4d|\t|%-4d|\n", "%-4d", i, j, k);
	ft_printf("\t|%-4d|\t\t|%-4d|\t|%-4d|\n",  i, j, k);
	printf("%-8s|%-4.2d|\t\t|%-4.2d|\t|%-4.2d|\n", "%-4.2d", i, j, k);
	ft_printf("\t|%-4.2d|\t\t|%-4.2d|\t|%-4.2d|\n",  i, j, k);
	printf("%-8s|%-4.6d|\t|%-4.6d|\t|%-4.6d|\n", "%-4.6d", i, j, k);
	ft_printf("\t|%-4.6d|\t|%-4.6d|\t|%-4.6d|\n",  i, j, k);
	printf("%-8s|%+04d|\t\t|%+04d|\t|%+04d|\n", "%+04d", i, j, k);
	ft_printf("\t|%+04d|\t\t|%+04d|\t|%+04d|\n",  i, j, k);
	printf("%-8s|%+02d|\t\t|%+02d|\t|%+02d|\n", "%+02d", i, j, k);
	ft_printf("\t|%+02d|\t\t|%+02d|\t|%+02d|\n", i, j, k);
	printf("%-8s|%+2d|\t\t|%+2d|\t|%+2d|\n", "%+2d", i, j, k);
	ft_printf("\t|%+2d|\t\t|%+2d|\t|%+2d|\n", i, j, k);
	printf("%-8s|%+4d|\t\t|%+4d|\t|%+4d|\n", "%+4d", i, j, k);
	ft_printf("\t|%+4d|\t\t|%+4d|\t|%+4d|\n",  i, j, k);
	printf("%-8s|%+4.0d|\t\t|%+4.0d|\t|%+4.0d|\n", "%+4.0d", i, j, k);
	ft_printf("\t|%+4.0d|\t\t|%+4.0d|\t|%+4.0d|\n",  i, j, k);
	printf("%-8s|%+3.6d|\t|%+3.6d|\t|%+3.6d|\n", "%+3.6d", i, j, k);
	ft_printf("\t|%+3.6d|\t|%+3.6d|\t|%+3.6d|\n",  i, j, k);
	printf("%-8s|%+6.3d|\t|%+6.3d|\t|%+6.3d|\n", "%+6.3d", i, j, k);
	ft_printf("\t|%+6.3d|\t|%+6.3d|\t|%+6.3d|\n",  i, j, k);
	printf("%-8s|%1.1d|\t\t|%1.1d|\t|%1.1d|\n", "%1.1d", i, j, k);
	ft_printf("\t|%1.1d|\t\t|%1.1d|\t|%1.1d|\n",  i, j, k);
	printf("%-8s|%1.5d|\t\t|%1.5d|\t|%1.5d|\n", "%1.5d", i, j, k);
	ft_printf("\t|%1.5d|\t\t|%1.5d|\t|%1.5d|\n",  i, j, k);
	printf("%-8s|%4.2d|\t\t|%4.2d|\t|%4.2d|\n", "%4.2d", i, j, k);
	ft_printf("\t|%4.2d|\t\t|%4.2d|\t|%4.2d|\n",  i, j, k);
	printf("%-8s|%4.0d|\t\t|%4.0d|\t|%4.0d|\n", "%4.0d", i, j, k);
	ft_printf("\t|%4.0d|\t\t|%4.0d|\t|%4.0d|\n",  i, j, k);
	printf("%-8s|%4.5d|\t\t|%4.5d|\t|%4.5d|\n", "%4.5d", i, j, k);
	ft_printf("\t|%4.5d|\t\t|%4.5d|\t|%4.5d|\n", i, j, k);
	printf("%-8s|%5.4d|\t\t|%5.4d|\t|%5.4d|\n", "%5.4d", i, j, k);
	ft_printf("\t|%5.4d|\t\t|%5.4d|\t|%5.4d|\n",  i, j, k);
}
void	prect(void)
{
		int i = 7, j = -7, k = 0;

	printf("\n%-8s|%.0d|\t\t|%.0d|\t|%.0d|\n", "%.0d", i, j, k);
	ft_printf("\t|%.0d|\t\t|%.0d|\t|%.0d|\n",  i, j, k);
	printf("%-8s|%.1d|\t\t|%.1d|\t|%.1d|\n", "%.1d", i, j, k);
	ft_printf("\t|%.1d|\t\t|%.1d|\t|%.1d|\n",  i, j, k);
	printf("%-8s|%.5d|\t\t|%.5d|\t|%.5d|\n", "%.5d", i, j, k);
	ft_printf("\t|%.5d|\t\t|%.5d|\t|%.5d|\n",  i, j, k);
	printf("%-8s|%0.5d|\t\t|%0.5d|\t|%0.5d|\n", "%0.5d", i, j, k);
	ft_printf("\t|%0.5d|\t\t|%0.5d|\t|%0.5d|\n",  i, j, k);
	printf("%-8s|%3.0d|\t\t|%3.0d|\t|%3.0d|\n", "%3.0d", i, j, k);
	ft_printf("\t|%3.0d|\t\t|%3.0d|\t|%3.0d|\n",  i, j, k);
	printf("%-8s|%2.5d|\t\t|%2.5d|\t|%2.5d|\n", "%2.5d", i, j, k);
	ft_printf("\t|%2.5d|\t\t|%2.5d|\t|%2.5d|\n",  i, j, k);
	printf("%-8s|%6.3d|\t|%6.3d|\t|%6.3d|\n", "%6.3d", i, j, k);
	ft_printf("\t|%6.3d|\t|%6.3d|\t|%6.3d|\n",  i, j, k);
	printf("%-8s|% .0d|\t\t|% .0d|\t|% .0d|\n", "% .0d", i, j, k);
	ft_printf("\t|% .0d|\t\t|% .0d|\t|% .0d|\n",  i, j, k);
	printf("%-8s|% .1d|\t\t|% .1d|\t|% .1d|\n", "% .1d", i, j, k);
	ft_printf("\t|% .1d|\t\t|% .1d|\t|% .1d|\n",  i, j, k);
	printf("%-8s|% .5d|\t|% .5d|\t|% .5d|\n", "% .5d", i, j, k);
	ft_printf("\t|% .5d|\t|% .5d|\t|% .5d|\n",  i, j, k);
	printf("%-8s|% 3.5d|\t|% 3.5d|\t|% 3.5d|\n", "% 3.5d", i, j, k);
	ft_printf("\t|% 3.5d|\t|% 3.5d|\t|% 3.5d|\n",  i, j, k);
	printf("%-8s|% 5.3d|\t\t|% 5.3d|\t|% 5.3d|\n", "% 5.3d", i, j, k);
	ft_printf("\t|% 5.3d|\t\t|% 5.3d|\t|% 5.3d|\n",  i, j, k);
	printf("%-8s|% 0.0d|\t\t|% 0.0d|\t|% 0.0d|\n", "% 0.0d", i, j, k);
	ft_printf("\t|% 0.0d|\t\t|% 0.0d|\t|% 0.0d|\n",  i, j, k);
	printf("%-8s|% 0.3d|\t\t|% 0.3d|\t|% 0.3d|\n", "% 0.3d", i, j, k);
	ft_printf("\t|% 0.3d|\t\t|% 0.3d|\t|% 0.3d|\n",  i, j, k);
	printf("%-8s|% 03.5d|\t|% 03.5d|\t|% 03.5d|\n", "% 03.5d", i, j, k);
	ft_printf("\t|% 03.5d|\t|% 03.5d|\t|% 03.5d|\n",  i, j, k);
	printf("%-8s|% 05.3d|\t\t|% 05.3d|\t|% 05.3d|\n", "% 05.3d", i, j, k);
	ft_printf("\t|% 05.3d|\t\t|% 05.3d|\t|% 05.3d|\n",  i, j, k);
	printf("%-8s|%-.0d|\t\t|%-.0d|\t|%-.0d|\n", "%-.0d", i, j, k);
	ft_printf("\t|%-.0d|\t\t|%-.0d|\t|%-.0d|\n",  i, j, k);
	printf("%-8s|%-4.0d|\t\t|%-4.0d|\t|%-4.0d|\n", "%-4.0d", i, j, k);
	ft_printf("\t|%-4.0d|\t\t|%-4.0d|\t|%-4.0d|\n",  i, j, k);
	printf("%-8s|%-.5d|\t\t|%-.5d|\t|%-.5d|\n", "%-.5d", i, j, k);
	ft_printf("\t|%-.5d|\t\t|%-.5d|\t|%-.5d|\n",  i, j, k);
	printf("%-8s|%-3.5d|\t\t|%-3.5d|\t|%-3.5d|\n", "%-3.5d", i, j, k);
	ft_printf("\t|%-3.5d|\t\t|%-3.5d|\t|%-3.5d|\n",  i, j, k);
	printf("%-8s|%-5.3d|\t\t|%-5.3d|\t|%-5.3d|\n", "%-5.3d", i, j, k);
	ft_printf("\t|%-5.3d|\t\t|%-5.3d|\t|%-5.3d|\n",  i, j, k);
	printf("%-8s|%- .0d|\t\t|%- .0d|\t|%- .0d|\n", "%- .0d", i, j, k);
	ft_printf("\t|%- .0d|\t\t|%- .0d|\t|%- .0d|\n",  i, j, k);
	printf("%-8s|%- .5d|\t|%- .5d|\t|%- .5d|\n", "%- .5d", i, j, k);
	ft_printf("\t|%- .5d|\t|%- .5d|\t|%- .5d|\n",  i, j, k);
	printf("%-8s|%- 3.5d|\t|%- 3.5d|\t|%- 3.5d|\n", "%- 3.5d", i, j, k);
	ft_printf("\t|%- 3.5d|\t|%- 3.5d|\t|%- 3.5d|\n",  i, j, k);
	printf("%-8s|%- 5.3d|\t\t|%- 5.3d|\t|%- 5.3d|\n", "%- 5.3d", i, j, k);
	ft_printf("\t|%- 5.3d|\t\t|%- 5.3d|\t|%- 5.3d|\n",  i, j, k);
	printf("%-8s|%-+.0d|\t\t|%-+.0d|\t|%-+.0d|\n", "%-+.0d", i, j, k);
	ft_printf("\t|%-+.0d|\t\t|%-+.0d|\t|%-+.0d|\n",  i, j, k);
	printf("%-8s|%-+.5d|\t|%-+.5d|\t|%-+.5d|\n", "%-+.5d", i, j, k);
	ft_printf("\t|%-+.5d|\t|%-+.5d|\t|%-+.5d|\n",  i, j, k);
	printf("%-8s|%-+3.5d|\t|%-+3.5d|\t|%-+3.5d|\n", "%-+3.5d", i, j, k);
	ft_printf("\t|%-+3.5d|\t|%-+3.5d|\t|%-+3.5d|\n",  i, j, k);
	printf("%-8s|%-+5.3d|\t\t|%-+5.3d|\t|%-+5.3d|\n", "%-+5.3d", i, j, k);
	ft_printf("\t|%-+5.3d|\t\t|%-+5.3d|\t|%-+5.3d|\n",  i, j, k);
	printf("%-8s|%+.0d|\t\t|%+.0d|\t|%+.0d|\n", "%+.0d", i, j, k);
	ft_printf("\t|%+.0d|\t\t|%+.0d|\t|%+.0d|\n",  i, j, k);
	printf("%-8s|%+4.0d|\t\t|%+4.0d|\t|%+4.0d|\n", "%+4.0d", i, j, k);
	ft_printf("\t|%+4.0d|\t\t|%+4.0d|\t|%+4.0d|\n",  i, j, k);
	printf("%-8s|%+.3d|\t\t|%+.3d|\t|%+.3d|\n", "%+.3d", i, j, k);
	ft_printf("\t|%+.3d|\t\t|%+.3d|\t|%+.3d|\n",  i, j, k);
	printf("%-8s|%+3.5d|\t|%+3.5d|\t|%+3.5d|\n", "%+3.5d", i, j, k);
	ft_printf("\t|%+3.5d|\t|%+3.5d|\t|%+3.5d|\n",  i, j, k);
	printf("%-8s|%+5.3d|\t\t|%+5.3d|\t|%+5.3d|\n", "%+5.3d", i, j, k);
	ft_printf("\t|%+5.3d|\t\t|%+5.3d|\t|%+5.3d|\n",  i, j, k);
}
void	zerot(void)
{
		int i = 7, j = -7, k = 0;

	printf("\n%-8s|%0d|\t\t|%0d|\t|%0d|\n", "%0d", i, j, k);
	ft_printf("\t|%0d|\t\t|%0d|\t|%0d|\n",  i, j, k);
	printf("%-8s|%04d|\t\t|%04d|\t|%04d|\n", "%04d", i, j, k);
	ft_printf("\t|%04d|\t\t|%04d|\t|%04d|\n",  i, j, k);
	printf("%-8s|%03.5d|\t\t|%03.5d|\t|%03.5d|\n", "%03.5d", i, j, k);
	ft_printf("\t|%03.5d|\t\t|%03.5d|\t|%03.5d|\n",  i, j, k);
	printf("%-8s|%04.0d|\t\t|%04.0d|\t|%04.0d|\n", "%04.0d", i, j, k);
	ft_printf("\t|%04.0d|\t\t|%04.0d|\t|%04.0d|\n",  i, j, k);
	printf("%-8s|%04.2d|\t\t|%04.2d|\t|%04.2d|\n", "%04.2d", i, j, k);
	ft_printf("\t|%04.2d|\t\t|%04.2d|\t|%04.2d|\n",  i, j, k);
	printf("%-8s|%04.3d|\t\t|%04.3d|\t|%04.3d|\n", "%04.3d", i, j, k);
	ft_printf("\t|%04.3d|\t\t|%04.3d|\t|%04.3d|\n",  i, j, k);
	printf("%-8s|%+0d|\t\t|%+0d|\t|%+0d|\n", "%+0d", i, j, k);
	ft_printf("\t|%+0d|\t\t|%+0d|\t|%+0d|\n", i, j, k);
	printf("%-8s|%+04d|\t\t|%+04d|\t|%+04d|\n", "%+04d", i, j, k);
	ft_printf("\t|%+04d|\t\t|%+04d|\t|%+04d|\n", i, j, k);
	printf("%-8s|%+0.0d|\t\t|%+0.0d|\t|%+0.0d|\n", "%+0.0d", i, j, k);
	ft_printf("\t|%+0.0d|\t\t|%+0.0d|\t|%+0.0d|\n",  i, j, k);
	printf("%-8s|%+0.3d|\t\t|%+0.3d|\t|%+0.3d|\n", "%+0.3d", i, j, k);
	ft_printf("\t|%+0.3d|\t\t|%+0.3d|\t|%+0.3d|\n",  i, j, k);
	printf("%-8s|%+03.5d|\t|%+03.5d|\t|%+03.5d|\n", "%+03.5d", i, j, k);
	ft_printf("\t|%+03.5d|\t|%+03.5d|\t|%+03.5d|\n",  i, j, k);
	printf("%-8s|%+05.3d|\t\t|%+05.3d|\t|%+05.3d|\n", "%+05.3d", i, j, k);
	ft_printf("\t|%+05.3d|\t\t|%+05.3d|\t|%+05.3d|\n",  i, j, k);
	printf("%-8s|%0 d|\t\t|%0 d|\t|%0 d|\n", "%0 d", i, j, k);
	ft_printf("\t|%0 d|\t\t|%0 d|\t|%0 d|\n",  i, j, k);
	printf("%-8s|%0 4d|\t\t|%0 4d|\t|%0 4d|\n", "%0 4d", i, j, k);
	ft_printf("\t|%0 4d|\t\t|%0 4d|\t|%0 4d|\n",  i, j, k);
	printf("%-8s|%0 .0d|\t\t|%0 .0d|\t|%0 .0d|\n", "%0 .0d", i, j, k);
	ft_printf("\t|%0 .0d|\t\t|%0 .0d|\t|%0 .0d|\n",  i, j, k);
	printf("%-8s|%0 .5d|\t|%0 .5d|\t|%0 .5d|\n", "%0 .5d", i, j, k);
	ft_printf("\t|%0 .5d|\t|%0 .5d|\t|%0 .5d|\n",  i, j, k);
	printf("%-8s|%0 3.5d|\t|%0 3.5d|\t|%0 3.5d|\n", "%0 3.5d", i, j, k);
	ft_printf("\t|%0 3.5d|\t|%0 3.5d|\t|%0 3.5d|\n",  i, j, k);
	printf("%-8s|%0 5.3d|\t\t|%0 5.3d|\t|%0 5.3d|\n", "%0 5.3d", i, j, k);
	ft_printf("\t|%0 5.3d|\t\t|%0 5.3d|\t|%0 5.3d|\n",  i, j, k);
}

void	test_d(void)
{
	printf("\n%s", "% [flags][width][.precision][length]specifier\n");
	printf("\n--- d ---\n");
	printf("%-8s|%d|\t|%d|\t|%d|\n", "%d", 7, -7, 0);
	ft_printf("\t|%d|\t|%d|\t|%d|\n",  7, -7, 0);
	spacet();
	widt();
	plust();
	prect();
	zerot();
	minust();
	printf("\n");
}

void	percent(void)
{
	printf("%-8s|%%|\n", "%%");
	ft_printf("\t|%%|\n");
	printf("%-8s|% %|\n", "% %");
	ft_printf("\t|% %|\n");
	printf("%-8s|%-4%|\n", "%-4%");
	ft_printf("\t|%-4%|\n");
	printf("%-8s|%- 4%|\n", "%- 4%");
	ft_printf("\t|%- 4%|\n");
	printf("%-8s|%-2%|\n", "%-2%");
	ft_printf("\t|%-2%|\n");
	printf("%-8s|%- 2%|\n", "%- 2%");
	ft_printf("\t|%- 2%|\n");
	printf("%-8s|%-1%|\n", "%-1%");
	ft_printf("\t|%-1%|\n");
	printf("%-8s|%4%|\n", "%4%");
	ft_printf("\t|%4%|\n");
	printf("%-8s|% 4%|\n", "% 4%");
	ft_printf("\t|% 4%|\n");
	printf("%-8s|%3%|\n", "%3%");
	ft_printf("\t|%3%|\n");
	printf("%-8s|% 3%|\n", "% 3%");
	ft_printf("\t|% 3%|\n");
	printf("%-8s|%2%|\n", "%2%");
	ft_printf("\t|%2%|\n");
	printf("%-8s|% 2%|\n", "% 2%");
	ft_printf("\t|% 2%|\n");
	printf("%-8s|%1%|\n", "%1%");
	ft_printf("\t|%1%|\n");
	printf("%-8s|% 1%|\n", "% 1%");
	ft_printf("\t|% 1%|\n");
	printf("%-8s|%0%|\n", "%0%");
	ft_printf("\t|%0%|\n");
	printf("%-8s|% 0%|\n", "% 0%");
	ft_printf("\t|% 0%|\n");
	printf("%-8s|%-%|\n", "%-%");
	ft_printf("\t|%-%|\n");
	printf("%-8s|%+%|\n", "%+%");
	ft_printf("\t|%+%|\n");
	printf("%-8s|%+ 4%|\n", "%+ 4%");
	ft_printf("\t|%+ 4%|\n");
	printf("%-8s|%+4%|\n", "%+4%");
	ft_printf("\t|%+4%|\n");
	printf("%-8s|%04%|\n", "%04%");
	ft_printf("\t|%04%|\n");
	printf("%-8s|% 04%|\n", "% 04%");
	ft_printf("\t|% 04%|\n");
	printf("%-8s|%-04%|\n", "%-04%");
	ft_printf("\t|%-04%|\n");
	printf("%-8s|%.4%|\n", "%.4%");
	ft_printf("\t|%.4%|\n");
	printf("%-8s|%4.2%|\n", "%4.2%");
	ft_printf("\t|%4.2%|\n");
	printf("%-8s|%-4.2%|\n", "%-4.2%");
	ft_printf("\t|%-4.2%|\n");
	printf("%-8s|%3.5%|\n", "%3.5%");
	ft_printf("\t|%3.5%|\n");
	printf("%-8s|%03.5%|\n", "%03.5%");
	ft_printf("\t|%03.5%|\n");
	printf("%-8s|%#4%|\n", "%#4%");
	ft_printf("\t|%#4%|\n");
	printf("%-8s|%#-4%|\n", "%#-4%");
	ft_printf("\t|%#-4%|\n");
}

void	chart(void)
{
	int a = 65, b = -65, c = 0;

	printf("%-8s|%c|\t|%c|\t|%c|\n", "%c", a, b, c);
	ft_printf("\t|%c|\t|%c|\t|%c|\n", a, b, c);
	printf("%-8s|%3c|\t|%3c|\t|%3c|\n", "%3c", a, b, c);
	ft_printf("\t|%3c|\t|%3c|\t|%3c|\n", a, b, c);
	printf("%-8s|%-c|\t|%-c|\t|%-c|\n", "%-c", a, b, c);
	ft_printf("\t|%-c|\t|%-c|\t|%-c|\n", a, b, c);
	printf("%-8s|%-3c|\t|%-3c|\t|%-3c|\n", "%-3c", a, b, c);
	ft_printf("\t|%-3c|\t|%-3c|\t|%-3c|\n", a, b, c);
	printf("%-8s|%*c|\t|%*c|\t|%*c|\n", "%*c", 3, a, 3, b, 3, c);
	ft_printf("\t|%*c|\t|%*c|\t|%*c|\n", 3, a, 3, b, 3, c);
	printf("%-8s|%*c|\t|%*c|\t|%*c|\n", "%*c", -3, a, -3, b, -3, c);
	ft_printf("\t|%*c|\t|%*c|\t|%*c|\n", -3, a, -3, b, -3, c);
}


void	unsigt(void)
{
	printf("\n\t--- UNSIGNED %%u ---\n");
	printf("CASES\t0\t\t17\t\t424242\t\t-1000\n\n");

	printf("%-8s|%u|\t\t|%u|\t\t|%u|\t|%u|\n", "%", 0, 17, 424242, -1000);
	ft_printf("\t|%u|\t\t|%u|\t\t|%u|\t|%u|\n",  0, 17, 424242, -1000);
	printf("%-8s|%0u|\t\t|%0u|\t\t|%0u|\t|%0u|\n", "%0", 0, 17, 424242, -1000);
	ft_printf("\t|%0u|\t\t|%0u|\t\t|%0u|\t|%0u|\n",  0, 17, 424242, -1000);
	printf("%-8s|%05u|\t\t|%05u|\t\t|%05u|\t|%05u|\n", "%05", 0, 17, 424242, -1000);
	ft_printf("\t|%05u|\t\t|%05u|\t\t|%05u|\t|%05u|\n",  0, 17, 424242, -1000);
	printf("%-8s|%03.5u|\t\t|%03.5u|\t\t|%03.5u|\t|%03.5u|\n", "%03.5", 0, 17, 424242, -1000);
	ft_printf("\t|%03.5u|\t\t|%03.5u|\t\t|%03.5u|\t|%03.5u|\n", 0, 17, 424242, -1000);
	printf("%-8s|%05.3u|\t\t|%05.3u|\t\t|%05.3u|\t|%05.3u|\n", "%05.3", 0, 17, 424242, -1000);
	ft_printf("\t|%05.3u|\t\t|%05.3u|\t\t|%05.3u|\t|%05.3u|\n",  0, 17, 424242, -1000);
	printf("%-8s|%5u|\t\t|%5u|\t\t|%5u|\t|%5u|\n", "%5", 0, 17, 424242, -1000);
	ft_printf("\t|%5u|\t\t|%5u|\t\t|%5u|\t|%5u|\n", 0, 17, 424242, -1000);
	printf("%-8s|%5.0u|\t\t|%5.0u|\t\t|%5.0u|\t|%5.0u|\n", "%5.0", 0, 17, 424242, -1000);
	ft_printf("\t|%5.0u|\t\t|%5.0u|\t\t|%5.0u|\t|%5.0u|\n", 0, 17, 424242, -1000);
	printf("%-8s|%5.3u|\t\t|%5.3u|\t\t|%5.3u|\t|%5.3u|\n", "%5.3", 0, 17, 424242, -1000);
	ft_printf("\t|%5.3u|\t\t|%5.3u|\t\t|%5.3u|\t|%5.3u|\n",  0, 17, 424242, -1000);
	printf("%-8s|%2.5u|\t\t|%2.5u|\t\t|%2.5u|\t|%2.5u|\n", "%2.5", 0, 17, 424242, -1000);
	ft_printf("\t|%2.5u|\t\t|%2.5u|\t\t|%2.5u|\t|%2.5u|\n",  0, 17, 424242, -1000);
	printf("%-8s|%.5u|\t\t|%.5u|\t\t|%.5u|\t|%.5u|\n", "%.5", 0, 17, 424242, -1000);
	ft_printf("\t|%.5u|\t\t|%.5u|\t\t|%.5u|\t|%.5u|\n",  0, 17, 424242, -1000);
	printf("%-8s|%-u|\t\t|%-u|\t\t|%-u|\t|%-u|\n", "%-", 0, 17, 424242, -1000);
	ft_printf("\t|%-u|\t\t|%-u|\t\t|%-u|\t|%-u|\n",  0, 17, 424242, -1000);
	printf("%-8s|%-5u|\t\t|%-5u|\t\t|%-5u|\t|%-5u|\n", "%-5", 0, 17, 424242, -1000);
	ft_printf("\t|%-5u|\t\t|%-5u|\t\t|%-5u|\t|%-5u|\n",  0, 17, 424242, -1000);
	printf("%-8s|%-5.0u|\t\t|%-5.0u|\t\t|%-5.0u|\t|%-5.0u|\n", "%-5.0", 0, 17, 424242, -1000);
	ft_printf("\t|%-5.0u|\t\t|%-5.0u|\t\t|%-5.0u|\t|%-5.0u|\n",  0, 17, 424242, -1000);
	printf("%-8s|%-5.3u|\t\t|%-5.3u|\t\t|%-5.3u|\t|%-5.3u|\n", "%-5.3", 0, 17, 424242, -1000);
	ft_printf("\t|%-5.3u|\t\t|%-5.3u|\t\t|%-5.3u|\t|%-5.3u|\n", 0, 17, 424242, -1000);
	printf("%-8s|%-2.5u|\t\t|%-2.5u|\t\t|%-2.5u|\t|%-2.5u|\n", "%-2.5", 0, 17, 424242, -1000);
	ft_printf("\t|%-2.5u|\t\t|%-2.5u|\t\t|%-2.5u|\t|%-2.5u|\n",  0, 17, 424242, -1000);
	printf("%-8s|%-.5u|\t\t|%-.5u|\t\t|%-.5u|\t|%-.5u|\n", "%-.5", 0, 17, 424242, -1000);
	ft_printf("\t|%-.5u|\t\t|%-.5u|\t\t|%-.5u|\t|%-.5u|\n",  0, 17, 424242, -1000);

	// undefined
	// printf("%-8s|%-0u|\t\t|%-0u|\t\t|%-0u|\t|%-0u|\n", "%-0", 0, 17, 424242, -1000);
	// printf("%-8s|%-05u|\t\t|%-05u|\t\t|%-05u|\t|%-05u|\n", "%-05", 0, 17, 424242, -1000);
	// printf("%-8s|%-03.5u|\t\t|%-03.5u|\t\t|%-03.5u|\t|%-03.5u|\n", "%-03.5", 0, 17, 424242, -1000);
	// printf("%-8s|%-05.3u|\t\t|%-05.3u|\t\t|%-05.3u|\t|%-05.3u|\n", "%-05.3", 0, 17, 424242, -1000);
	// printf("%-8s|%+u|\t|%+u|\t|%+u|\t|%+u|\n", "%+", 0, 17, 424242, -1000);
	// printf("%-8s|% u|\t|% u|\t|% u|\t|% u|\n", "% ", 0, 17, 424242, -1000);
	// printf("%-8s|%#u|\t\t|%#u|\t\t|%#u|\t|%#u|\n", "%#", 0, 17, 424242, -1000);
}

void	hext(void)
{
	int a = 0, b = -4242, c = 1096382, d = 17;
	// long c = 3405691582;
	// 414
	// 02
	printf("\n\t--- HEX ---\n");
	printf("CASES\t0\t\t17\t\t-4242\t\t1096382\n");
	printf("\n%-8s|%x|\t\t|%x|\t\t|%x|\t|%x|\n", "%", a, d, b, c);
	ft_printf("\t|%x|\t\t|%x|\t\t|%x|\t|%x|\n", 0, 17, -4242, 1096382);
	printf("%-8s|%#x|\t\t|%#x|\t\t|%#x|\t|%#x|\n", "%#", a, d, b, c);
	ft_printf("\t|%#x|\t\t|%#x|\t\t|%#x|\t|%#x|\n", 0, 17, -4242, 1096382);
	printf("%-8s|%1x|\t\t|%1x|\t\t|%1x|\t|%1x|\n", "%1", a, d, b, c);
	ft_printf("\t|%1x|\t\t|%1x|\t\t|%1x|\t|%1x|\n", 0, 17, -4242, 1096382);
	printf("%-8s|%2x|\t\t|%2x|\t\t|%2x|\t|%2x|\n", "%2", a, d, b, c);
	ft_printf("\t|%2x|\t\t|%2x|\t\t|%2x|\t|%2x|\n", 0, 17, -4242, 1096382);
	printf("%-8s|%2.2x|\t\t|%2.2x|\t\t|%2.2x|\t|%2.2x|\n", "%2.2", a, d, b, c);
	ft_printf("\t|%2.2x|\t\t|%2.2x|\t\t|%2.2x|\t|%2.2x|\n", 0, 17, -4242, 1096382);
	printf("%-8s|%.0x|\t\t|%.0x|\t\t|%.0x|\t|%.0x|\n", "%.0", a, d, b, c);
	ft_printf("\t|%.0x|\t\t|%.0x|\t\t|%.0x|\t|%.0x|\n", 0, 17, -4242, 1096382);
	printf("%-8s|%#.0x|\t\t|%#.0x|\t\t|%#.0x|\t|%#.0x|\n", "%#.0", a, d, b, c);
	ft_printf("\t|%#.0x|\t\t|%#.0x|\t\t|%#.0x|\t|%#.0x|\n", 0, 17, -4242, 1096382);
	printf("%-8s|%4.0x|\t\t|%4.0x|\t\t|%4.0x|\t|%4.0x|\n", "%4.0", a, d, b, c);
	ft_printf("\t|%4.0x|\t\t|%4.0x|\t\t|%4.0x|\t|%4.0x|\n", 0, 17, -4242, 1096382);
	printf("%-8s|%04.0x|\t\t|%04.0x|\t\t|%04.0x|\t|%04.0x|\n", "%04.0", a, d, b, c);
	ft_printf("\t|%04.0x|\t\t|%04.0x|\t\t|%04.0x|\t|%04.0x|\n", 0, 17, -4242, 1096382);
	printf("%-8s|%#04.0x|\t\t|%#04.0x|\t\t|%#04.0x|\t|%#04.0x|\n", "%#04.0", a, d, b, c);
	ft_printf("\t|%#04.0x|\t\t|%#04.0x|\t\t|%#04.0x|\t|%#04.0x|\n", 0, 17, -4242, 1096382);
	printf("%-8s|%#4.0x|\t\t|%#4.0x|\t\t|%#4.0x|\t|%#4.0x|\n", "%#4.0", a, d, b, c);
	ft_printf("\t|%#4.0x|\t\t|%#4.0x|\t\t|%#4.0x|\t|%#4.0x|\n", 0, 17, -4242, 1096382);
	printf("%-8s|%4.6x|\t|%4.6x|\t|%4.6x|\t|%4.6x|\n", "%4.6", a, d, b, c);
	ft_printf("\t|%4.6x|\t|%4.6x|\t|%4.6x|\t|%4.6x|\n", 0, 17, -4242, 1096382);
	printf("%-8s|%#4.6x|\t|%#4.6x|\t|%#4.6x|\t|%#4.6x|\n", "%#4.6", a, d, b, c);
	ft_printf("\t|%#4.6x|\t|%#4.6x|\t|%#4.6x|\t|%#4.6x|\n", 0, 17, -4242, 1096382);
	printf("%-8s|%6.4x|\t|%6.4x|\t|%6.4x|\t|%6.4x|\n", "%6.4", a, d, b, c);
	ft_printf("\t|%6.4x|\t|%6.4x|\t|%6.4x|\t|%6.4x|\n", 0, 17, -4242, 1096382);
	printf("%-8s|%.4x|\t\t|%.4x|\t\t|%.4x|\t|%.4x|\n", "%.4", a, d, b, c);
	ft_printf("\t|%.4x|\t\t|%.4x|\t\t|%.4x|\t|%.4x|\n", 0, 17, -4242, 1096382);
	printf("%-8s|%#10x|\t|%#10x|\t|%#10x|\t|%#10x|\n", "%#10", a, d, b, c);
	ft_printf("\t|%#10x|\t|%#10x|\t|%#10x|\t|%#10x|\n", 0, 17, -4242, 1096382);
	printf("%-8s|%7x|\t|%7x|\t|%7x|\t|%7x|\n", "%7", a, d, b, c);
	ft_printf("\t|%7x|\t|%7x|\t|%7x|\t|%7x|\n", 0, 17, -4242, 1096382);
	printf("%-8s|%0x|\t\t|%0x|\t\t|%0x|\t|%0x|\n", "%0", a, d, b, c);
	ft_printf("\t|%0x|\t\t|%0x|\t\t|%0x|\t|%0x|\n", 0, 17, -4242, 1096382);
	printf("%-8s|%07x|\t|%07x|\t|%07x|\t|%07x|\n", "%07", a, d, b, c);
	ft_printf("\t|%07x|\t|%07x|\t|%07x|\t|%07x|\n", 0, 17, -4242, 1096382);
	printf("%-8s|%07.0x|\t|%07.0x|\t|%07.0x|\t|%07.0x|\n", "%07.0", a, d, b, c);
	ft_printf("\t|%07.0x|\t|%07.0x|\t|%07.0x|\t|%07.0x|\n", 0, 17, -4242, 1096382);
	printf("\n%-8s|%#-10x|\t|%#-10x|\t|%#-10x|\t|%#-10x|\n", "%#-10", a, d, b, c);
	ft_printf("\t|%#-10x|\t|%#-10x|\t|%#-10x|\t|%#-10x|\n", 0, 17, -4242, 1096382);
	printf("%-8s|%-x|\t\t|%-x|\t\t|%-x|\t|%-x|\n", "%-", a, d, b, c);
	ft_printf("\t|%-x|\t\t|%-x|\t\t|%-x|\t|%-x|\n", 0, 17, -4242, 1096382);
	printf("%-8s|%-7x|\t|%-7x|\t|%-7x|\t|%-7x|\n", "%-7", a, d, b, c);
	ft_printf("\t|%-7x|\t|%-7x|\t|%-7x|\t|%-7x|\n", 0, 17, -4242, 1096382);
	printf("%-8s|%-7.4x|\t|%-7.4x|\t|%-7.4x|\t|%-7.4x|\n", "%-7.4", a, d, b, c);
	ft_printf("\t|%-7.4x|\t|%-7.4x|\t|%-7.4x|\t|%-7.4x|\n", 0, 17, -4242, 1096382);
	printf("%-8s|%-7.0x|\t|%-7.0x|\t|%-7.0x|\t|%-7.0x|\n", "%-7.0", a, d, b, c);
	ft_printf("\t|%-7.0x|\t|%-7.0x|\t|%-7.0x|\t|%-7.0x|\n", 0, 17, -4242, 1096382);
	printf("%-8s|%-4.7x|\t|%-4.7x|\t|%-4.7x|\t|%-4.7x|\n", "%-4.7", a, d, b, c);
	ft_printf("\t|%-4.7x|\t|%-4.7x|\t|%-4.7x|\t|%-4.7x|\n", 0, 17, -4242, 1096382);
	printf("%-8s|%#-7x|\t|%#-7x|\t|%#-7x|\t|%#-7x|\n", "%#-7", a, d, b, c);
	ft_printf("\t|%#-7x|\t|%#-7x|\t|%#-7x|\t|%#-7x|\n", 0, 17, -4242, 1096382);
	printf("%-8s|%-#x|\t\t|%-#x|\t\t|%-#x|\t|%-#x|\n", "%-#", a, d, b, c);
	ft_printf("\t|%-#x|\t\t|%-#x|\t\t|%-#x|\t|%-#x|\n", 0, 17, -4242, 1096382);
	printf("%-8s|%-4x|\t\t|%-4x|\t\t|%-4x|\t|%-4x|\n", "%-4", a, d, b, c);
	ft_printf("\t|%-4x|\t\t|%-4x|\t\t|%-4x|\t|%-4x|\n", 0, 17, -4242, 1096382);
	printf("\n%-8s|%#5x|\t\t|%#5x|\t\t|%#5x|\t|%#5x|\n", "%#5", a, d, b, c);
	ft_printf("\t|%#5x|\t\t|%#5x|\t\t|%#5x|\t|%#5x|\n",  a, d, b, c);
	printf("%-8s|%#5.2x|\t\t|%#5.2x|\t\t|%#5.2x|\t|%#5.2x|\n", "%#5.2", a, d, b, c);
	ft_printf("\t|%#5.2x|\t\t|%#5.2x|\t\t|%#5.2x|\t|%#5.2x|\n",  a, d, b, c);
	printf("%-8s|%#4.7x|\t|%#4.7x|\t|%#4.7x|\t|%#4.7x|\n", "%#4.7", a, d, b, c);
	ft_printf("\t|%#4.7x|\t|%#4.7x|\t|%#4.7x|\t|%#4.7x|\n",  a, d, b, c);
	printf("%-8s|%#7.4x|\t|%#7.4x|\t|%#7.4x|\t|%#7.4x|\n", "%#7.4", a, d, b, c);
	ft_printf("\t|%#7.4x|\t|%#7.4x|\t|%#7.4x|\t|%#7.4x|\n",  a, d, b, c);
	printf("%-8s|%#-5x|\t\t|%#-5x|\t\t|%#-5x|\t|%#-5x|\n", "%#-5", a, d, b, c);
	ft_printf("\t|%#-5x|\t\t|%#-5x|\t\t|%#-5x|\t|%#-5x|\n",  a, d, b, c);
	printf("%-8s|%#-1x|\t\t|%#-1x|\t\t|%#-1x|\t|%#-1x|\n", "%#-1", a, d, b, c);
	ft_printf("\t|%#-1x|\t\t|%#-1x|\t\t|%#-1x|\t|%#-1x|\n",  a, d, b, c);
	printf("%-8s|%#-.1x|\t\t|%#-.1x|\t\t|%#-.1x|\t|%#-.1x|\n", "%#-.1", a, d, b, c);
	ft_printf("\t|%#-.1x|\t\t|%#-.1x|\t\t|%#-.1x|\t|%#-.1x|\n",  a, d, b, c);
	printf("%-8s|%-#5.2x|\t\t|%-#5.2x|\t\t|%-#5.2x|\t|%-#5.2x|\n", "%-#5.2", a, d, b, c);
	ft_printf("\t|%-#5.2x|\t\t|%-#5.2x|\t\t|%-#5.2x|\t|%-#5.2x|\n", a, d, b, c);
	printf("%-8s|%-#3.6x|\t|%-#3.6x|\t|%-#3.6x|\t|%-#3.6x|\n", "%-#3.6", a, d, b, c);
	ft_printf("\t|%-#3.6x|\t|%-#3.6x|\t|%-#3.6x|\t|%-#3.6x|\n",  a, d, b, c);

	printf("\n%-8s|%X|\t\t|%X|\t\t|%X|\t|%X|\n", "%", a, d, b, c);
	ft_printf("\t|%X|\t\t|%X|\t\t|%X|\t|%X|\n", 0, 17, -4242, 1096382);
	printf("%-8s|%#X|\t\t|%#X|\t\t|%#X|\t|%#X|\n", "%#", a, d, b, c);
	ft_printf("\t|%#X|\t\t|%#X|\t\t|%#X|\t|%#X|\n", 0, 17, -4242, 1096382);
	printf("%-8s|%1X|\t\t|%1X|\t\t|%1X|\t|%1X|\n", "%1", a, d, b, c);
	ft_printf("\t|%1X|\t\t|%1X|\t\t|%1X|\t|%1X|\n", 0, 17, -4242, 1096382);
	printf("%-8s|%2X|\t\t|%2X|\t\t|%2X|\t|%2X|\n", "%2", a, d, b, c);
	ft_printf("\t|%2X|\t\t|%2X|\t\t|%2X|\t|%2X|\n", 0, 17, -4242, 1096382);
	printf("%-8s|%2.2X|\t\t|%2.2X|\t\t|%2.2X|\t|%2.2X|\n", "%2.2", a, d, b, c);
	ft_printf("\t|%2.2X|\t\t|%2.2X|\t\t|%2.2X|\t|%2.2X|\n", 0, 17, -4242, 1096382);
	printf("%-8s|%.0X|\t\t|%.0X|\t\t|%.0X|\t|%.0X|\n", "%.0", a, d, b, c);
	ft_printf("\t|%.0X|\t\t|%.0X|\t\t|%.0X|\t|%.0X|\n", 0, 17, -4242, 1096382);
	printf("%-8s|%#.0X|\t\t|%#.0X|\t\t|%#.0X|\t|%#.0X|\n", "%#.0", a, d, b, c);
	ft_printf("\t|%#.0X|\t\t|%#.0X|\t\t|%#.0X|\t|%#.0X|\n", 0, 17, -4242, 1096382);
	printf("%-8s|%4.0X|\t\t|%4.0X|\t\t|%4.0X|\t|%4.0X|\n", "%4.0", a, d, b, c);
	ft_printf("\t|%4.0X|\t\t|%4.0X|\t\t|%4.0X|\t|%4.0X|\n", 0, 17, -4242, 1096382);
	printf("%-8s|%04.0X|\t\t|%04.0X|\t\t|%04.0X|\t|%04.0X|\n", "%04.0", a, d, b, c);
	ft_printf("\t|%04.0X|\t\t|%04.0X|\t\t|%04.0X|\t|%04.0X|\n", 0, 17, -4242, 1096382);
	printf("%-8s|%#04.0X|\t\t|%#04.0X|\t\t|%#04.0X|\t|%#04.0X|\n", "%#04.0", a, d, b, c);
	ft_printf("\t|%#04.0X|\t\t|%#04.0X|\t\t|%#04.0X|\t|%#04.0X|\n", 0, 17, -4242, 1096382);
	printf("%-8s|%#4.0X|\t\t|%#4.0X|\t\t|%#4.0X|\t|%#4.0X|\n", "%#4.0", a, d, b, c);
	ft_printf("\t|%#4.0X|\t\t|%#4.0X|\t\t|%#4.0X|\t|%#4.0X|\n", 0, 17, -4242, 1096382);
	printf("%-8s|%4.6X|\t|%4.6X|\t|%4.6X|\t|%4.6X|\n", "%4.6", a, d, b, c);
	ft_printf("\t|%4.6X|\t|%4.6X|\t|%4.6X|\t|%4.6X|\n", 0, 17, -4242, 1096382);
	printf("%-8s|%#4.6X|\t|%#4.6X|\t|%#4.6X|\t|%#4.6X|\n", "%#4.6", a, d, b, c);
	ft_printf("\t|%#4.6X|\t|%#4.6X|\t|%#4.6X|\t|%#4.6X|\n", 0, 17, -4242, 1096382);
	printf("%-8s|%6.4X|\t|%6.4X|\t|%6.4X|\t|%6.4X|\n", "%6.4", a, d, b, c);
	ft_printf("\t|%6.4X|\t|%6.4X|\t|%6.4X|\t|%6.4X|\n", 0, 17, -4242, 1096382);
	printf("%-8s|%.4X|\t\t|%.4X|\t\t|%.4X|\t|%.4X|\n", "%.4", a, d, b, c);
	ft_printf("\t|%.4X|\t\t|%.4X|\t\t|%.4X|\t|%.4X|\n", 0, 17, -4242, 1096382);
	printf("%-8s|%#10X|\t|%#10X|\t|%#10X|\t|%#10X|\n", "%#10", a, d, b, c);
	ft_printf("\t|%#10X|\t|%#10X|\t|%#10X|\t|%#10X|\n", 0, 17, -4242, 1096382);
	printf("%-8s|%7X|\t|%7X|\t|%7X|\t|%7X|\n", "%7", a, d, b, c);
	ft_printf("\t|%7X|\t|%7X|\t|%7X|\t|%7X|\n", 0, 17, -4242, 1096382);
	printf("%-8s|%0X|\t\t|%0X|\t\t|%0X|\t|%0X|\n", "%0", a, d, b, c);
	ft_printf("\t|%0X|\t\t|%0X|\t\t|%0X|\t|%0X|\n", 0, 17, -4242, 1096382);
	printf("%-8s|%07X|\t|%07X|\t|%07X|\t|%07X|\n", "%07", a, d, b, c);
	ft_printf("\t|%07X|\t|%07X|\t|%07X|\t|%07X|\n", 0, 17, -4242, 1096382);
	printf("%-8s|%07.0X|\t|%07.0X|\t|%07.0X|\t|%07.0X|\n", "%07.0", a, d, b, c);
	ft_printf("\t|%07.0X|\t|%07.0X|\t|%07.0X|\t|%07.0X|\n", 0, 17, -4242, 1096382);
	printf("\n%-8s|%#-10X|\t|%#-10X|\t|%#-10X|\t|%#-10X|\n", "%#-10", a, d, b, c);
	ft_printf("\t|%#-10X|\t|%#-10X|\t|%#-10X|\t|%#-10X|\n", 0, 17, -4242, 1096382);
	printf("%-8s|%-X|\t\t|%-X|\t\t|%-X|\t|%-X|\n", "%-", a, d, b, c);
	ft_printf("\t|%-X|\t\t|%-X|\t\t|%-X|\t|%-X|\n", 0, 17, -4242, 1096382);
	printf("%-8s|%-7X|\t|%-7X|\t|%-7X|\t|%-7X|\n", "%-7", a, d, b, c);
	ft_printf("\t|%-7X|\t|%-7X|\t|%-7X|\t|%-7X|\n", 0, 17, -4242, 1096382);
	printf("%-8s|%-7.4X|\t|%-7.4X|\t|%-7.4X|\t|%-7.4X|\n", "%-7.4", a, d, b, c);
	ft_printf("\t|%-7.4X|\t|%-7.4X|\t|%-7.4X|\t|%-7.4X|\n", 0, 17, -4242, 1096382);
	printf("%-8s|%-7.0X|\t|%-7.0X|\t|%-7.0X|\t|%-7.0X|\n", "%-7.0", a, d, b, c);
	ft_printf("\t|%-7.0X|\t|%-7.0X|\t|%-7.0X|\t|%-7.0X|\n", 0, 17, -4242, 1096382);
	printf("%-8s|%-4.7X|\t|%-4.7X|\t|%-4.7X|\t|%-4.7X|\n", "%-4.7", a, d, b, c);
	ft_printf("\t|%-4.7X|\t|%-4.7X|\t|%-4.7X|\t|%-4.7X|\n", 0, 17, -4242, 1096382);
	printf("%-8s|%#-7X|\t|%#-7X|\t|%#-7X|\t|%#-7X|\n", "%#-7", a, d, b, c);
	ft_printf("\t|%#-7X|\t|%#-7X|\t|%#-7X|\t|%#-7X|\n", 0, 17, -4242, 1096382);
	printf("%-8s|%-#X|\t\t|%-#X|\t\t|%-#X|\t|%-#X|\n", "%-#", a, d, b, c);
	ft_printf("\t|%-#X|\t\t|%-#X|\t\t|%-#X|\t|%-#X|\n", 0, 17, -4242, 1096382);
	printf("%-8s|%-4X|\t\t|%-4X|\t\t|%-4X|\t|%-4X|\n", "%-4", a, d, b, c);
	ft_printf("\t|%-4X|\t\t|%-4X|\t\t|%-4X|\t|%-4X|\n", 0, 17, -4242, 1096382);
	printf("\n%-8s|%#5X|\t\t|%#5X|\t\t|%#5X|\t|%#5X|\n", "%#5", a, d, b, c);
	ft_printf("\t|%#5X|\t\t|%#5X|\t\t|%#5X|\t|%#5X|\n",  a, d, b, c);
	printf("%-8s|%#5.2X|\t\t|%#5.2X|\t\t|%#5.2X|\t|%#5.2X|\n", "%#5.2", a, d, b, c);
	ft_printf("\t|%#5.2X|\t\t|%#5.2X|\t\t|%#5.2X|\t|%#5.2X|\n",  a, d, b, c);
	printf("%-8s|%#4.7X|\t|%#4.7X|\t|%#4.7X|\t|%#4.7X|\n", "%#4.7", a, d, b, c);
	ft_printf("\t|%#4.7X|\t|%#4.7X|\t|%#4.7X|\t|%#4.7X|\n",  a, d, b, c);
	printf("%-8s|%#7.4X|\t|%#7.4X|\t|%#7.4X|\t|%#7.4X|\n", "%#7.4", a, d, b, c);
	ft_printf("\t|%#7.4X|\t|%#7.4X|\t|%#7.4X|\t|%#7.4X|\n",  a, d, b, c);
	printf("%-8s|%#-5X|\t\t|%#-5X|\t\t|%#-5X|\t|%#-5X|\n", "%#-5", a, d, b, c);
	ft_printf("\t|%#-5X|\t\t|%#-5X|\t\t|%#-5X|\t|%#-5X|\n",  a, d, b, c);
	printf("%-8s|%#-1X|\t\t|%#-1X|\t\t|%#-1X|\t|%#-1X|\n", "%#-1", a, d, b, c);
	ft_printf("\t|%#-1X|\t\t|%#-1X|\t\t|%#-1X|\t|%#-1X|\n",  a, d, b, c);
	printf("%-8s|%#-.1X|\t\t|%#-.1X|\t\t|%#-.1X|\t|%#-.1X|\n", "%#-.1", a, d, b, c);
	ft_printf("\t|%#-.1X|\t\t|%#-.1X|\t\t|%#-.1X|\t|%#-.1X|\n",  a, d, b, c);
	printf("%-8s|%-#5.2X|\t\t|%-#5.2X|\t\t|%-#5.2X|\t|%-#5.2X|\n", "%-#5.2", a, d, b, c);
	ft_printf("\t|%-#5.2X|\t\t|%-#5.2X|\t\t|%-#5.2X|\t|%-#5.2X|\n", a, d, b, c);
	printf("%-8s|%-#3.6X|\t|%-#3.6X|\t|%-#3.6X|\t|%-#3.6X|\n", "%-#3.6", a, d, b, c);
	ft_printf("\t|%-#3.6X|\t|%-#3.6X|\t|%-#3.6X|\t|%-#3.6X|\n",  a, d, b, c);


	// ft_printf("%llx\n", 18446744073709551615u);
	// ft_printf("%llx\n", 1152921504606846975u);
	unsigned long long ll = 18446744073709551615u;
	printf("\nCASES:\t18,446,744,073,709,551,615\n");
	printf("\t|%llx|\n", ll);

	// undefined
	// printf("%-8s|% 4x|\t|% 4x|\t|% 4x|\n", "% 4", a, d, b, c);
	// printf("%-8s|%+x|\t|%+x|\t|%+x|\n", "%+", a, d, b, c);
}

void	octals(void)
{
	printf("\n\t--- OCTALS ---\nCASES:\t0\t\t17\t\t1234\n");
	printf("\n%-8s|%o|\t\t|%o|\t\t|%o|\n","%", 0, 17, 1234);
	ft_printf("\t|%o|\t\t|%o|\t\t|%o|\n", 0, 17, 1234);
	printf("%-8s|%0o|\t\t|%0o|\t\t|%0o|\n","%0", 0, 17, 1234);
	ft_printf("\t|%0o|\t\t|%0o|\t\t|%0o|\n", 0, 17, 1234);
	printf("%-8s|%.o|\t\t|%.o|\t\t|%.o|\n","%.", 0, 17, 1234);
	ft_printf("\t|%.o|\t\t|%.o|\t\t|%.o|\n", 0, 17, 1234);
	printf("%-8s|%.0o|\t\t|%.0o|\t\t|%.0o|\n","%.0", 0, 17, 1234);
	ft_printf("\t|%.0o|\t\t|%.0o|\t\t|%.0o|\n", 0, 17, 1234);
	printf("%-8s|%1.0o|\t\t|%1.0o|\t\t|%1.0o|\n","%1.0", 0, 17, 1234);
	ft_printf("\t|%1.0o|\t\t|%1.0o|\t\t|%1.0o|\n", 0, 17, 1234);
	printf("%-8s|%0.o|\t\t|%0.o|\t\t|%0.o|\n","%0.", 0, 17, 1234);
	ft_printf("\t|%0.o|\t\t|%0.o|\t\t|%0.o|\n", 0, 17, 1234);
	printf("%-8s|%5.0o|\t\t|%5.0o|\t\t|%5.0o|\n","%5.0", 0, 17, 1234);
	ft_printf("\t|%5.0o|\t\t|%5.0o|\t\t|%5.0o|\n", 0, 17, 1234);
	printf("%-8s|%#o|\t\t|%#o|\t\t|%#o|\n","%#", 0, 17, 1234);
	ft_printf("\t|%#o|\t\t|%#o|\t\t|%#o|\n", 0, 17, 1234);
	printf("%-8s|%#0o|\t\t|%#0o|\t\t|%#0o|\n","%#0", 0, 17, 1234);
	ft_printf("\t|%#0o|\t\t|%#0o|\t\t|%#0o|\n", 0, 17, 1234);
	printf("%-8s|%0o|\t\t|%0o|\t\t|%0o|\n","%0", 0, 17, 1234);
	ft_printf("\t|%0o|\t\t|%0o|\t\t|%0o|\n", 0, 17, 1234);
	printf("%-8s|%03.5o|\t\t|%03.5o|\t\t|%03.5o|\n","%03.5", 0, 17, 1234);
	ft_printf("\t|%03.5o|\t\t|%03.5o|\t\t|%03.5o|\n", 0, 17, 1234);
	printf("%-8s|%08o|\t|%08o|\t|%08o|\n","%08", 0, 17, 1234);
	ft_printf("\t|%08o|\t|%08o|\t|%08o|\n", 0, 17, 1234);
	printf("%-8s|%08.0o|\t|%08.0o|\t|%08.0o|\n","%08.0", 0, 17, 1234);
	ft_printf("\t|%08.0o|\t|%08.0o|\t|%08.0o|\n", 0, 17, 1234);
	printf("%-8s|%8o|\t|%8o|\t|%8o|\n","%8", 0, 17, 1234);
	ft_printf("\t|%8o|\t|%8o|\t|%8o|\n", 0, 17, 1234);
	printf("%-8s|%#8o|\t|%#8o|\t|%#8o|\n","%#8", 0, 17, 1234);
	ft_printf("\t|%#8o|\t|%#8o|\t|%#8o|\n", 0, 17, 1234);
	printf("%-8s|%#08o|\t|%#08o|\t|%#08o|\n","%#08", 0, 17, 1234);
	ft_printf("\t|%#08o|\t|%#08o|\t|%#08o|\n", 0, 17, 1234);
	printf("%-8s|%#6o|\t|%#6o|\t|%#6o|\n","%#6", 0, 17, 1234);
	ft_printf("\t|%#6o|\t|%#6o|\t|%#6o|\n", 0, 17, 1234);
	printf("%-8s|%.8o|\t|%.8o|\t|%.8o|\n","%.8", 0, 17, 1234);
	ft_printf("\t|%.8o|\t|%.8o|\t|%.8o|\n", 0, 17, 1234);
	printf("%-8s|%4.8o|\t|%4.8o|\t|%4.8o|\n","%4.8", 0, 17, 1234);
	ft_printf("\t|%4.8o|\t|%4.8o|\t|%4.8o|\n", 0, 17, 1234);
	printf("%-8s|%8.4o|\t|%8.4o|\t|%8.4o|\n","%8.4", 0, 17, 1234);
	ft_printf("\t|%8.4o|\t|%8.4o|\t|%8.4o|\n", 0, 17, 1234);
	printf("%-8s|%#.8o|\t|%#.8o|\t|%#.8o|\n","%#.8", 0, 17, 1234);
	ft_printf("\t|%#.8o|\t|%#.8o|\t|%#.8o|\n", 0, 17, 1234);
	printf("%-8s|%#4.8o|\t|%#4.8o|\t|%#4.8o|\n","%#4.8", 0, 17, 1234);
	ft_printf("\t|%#4.8o|\t|%#4.8o|\t|%#4.8o|\n", 0, 17, 1234);
	printf("%-8s|%#8.4o|\t|%#8.4o|\t|%#8.4o|\n","%#8.4", 0, 17, 1234);
	ft_printf("\t|%#8.4o|\t|%#8.4o|\t|%#8.4o|\n", 0, 17, 1234);
	printf("%-8s|%#5.1o|\t\t|%#5.1o|\t\t|%#5.1o|\n","%#5.1", 0, 17, 1234);
	ft_printf("\t|%#5.1o|\t\t|%#5.1o|\t\t|%#5.1o|\n", 0, 17, 1234);
	printf("%-8s|%#8.5o|\t|%#8.5o|\t|%#8.5o|\n","%#8.5", 0, 17, 1234);
	ft_printf("\t|%#8.5o|\t|%#8.5o|\t|%#8.5o|\n", 0, 17, 1234);
	printf("%-8s|%#.o|\t\t|%#.o|\t\t|%#.o|\n","%#.", 0, 17, 1234);
	ft_printf("\t|%#.o|\t\t|%#.o|\t\t|%#.o|\n", 0, 17, 1234);
	printf("%-8s|%#0.o|\t\t|%#0.o|\t\t|%#0.o|\n","%#0.", 0, 17, 1234);
	ft_printf("\t|%#0.o|\t\t|%#0.o|\t\t|%#0.o|\n", 0, 17, 1234);
	printf("%-8s|%0.3o|\t\t|%0.3o|\t\t|%0.3o|\n","%0.3", 0, 17, 1234);
	ft_printf("\t|%0.3o|\t\t|%0.3o|\t\t|%0.3o|\n", 0, 17, 1234);
	printf("%-8s|%#6.0o|\t|%#6.0o|\t|%#6.0o|\n","%#6.0", 0, 17, 1234);
	ft_printf("\t|%#6.0o|\t|%#6.0o|\t|%#6.0o|\n", 0, 17, 1234);
	printf("\n%-8s|%-o|\t\t|%-o|\t\t|%-o|\n","%-", 0, 17, 1234);
	ft_printf("\t|%-o|\t\t|%-o|\t\t|%-o|\n", 0, 17, 1234);
	printf("%-8s|%-.o|\t\t|%-.o|\t\t|%-.o|\n","%-.", 0, 17, 1234);
	ft_printf("\t|%-.o|\t\t|%-.o|\t\t|%-.o|\n", 0, 17, 1234);
	printf("%-8s|%#-.o|\t\t|%#-.o|\t\t|%#-.o|\n","%#-.", 0, 17, 1234);
	ft_printf("\t|%#-.o|\t\t|%#-.o|\t\t|%#-.o|\n", 0, 17, 1234);
	printf("%-8s|%-4.0o|\t\t|%-4.0o|\t\t|%-4.0o|\n","%-4.0", 0, 17, 1234);
	ft_printf("\t|%-4.0o|\t\t|%-4.0o|\t\t|%-4.0o|\n", 0, 17, 1234);
	printf("%-8s|%#-4.0o|\t\t|%#-4.0o|\t\t|%#-4.0o|\n","%#-4.0", 0, 17, 1234);
	ft_printf("\t|%#-4.0o|\t\t|%#-4.0o|\t\t|%#-4.0o|\n", 0, 17, 1234);
	printf("%-8s|%-6o|\t|%-6o|\t|%-6o|\n","%-6", 0, 17, 1234);
	ft_printf("\t|%-6o|\t|%-6o|\t|%-6o|\n", 0, 17, 1234);
	printf("%-8s|%#-6o|\t|%#-6o|\t|%#-6o|\n","%#-6", 0, 17, 1234);
	ft_printf("\t|%#-6o|\t|%#-6o|\t|%#-6o|\n", 0, 17, 1234);
	printf("%-8s|%-8.4o|\t|%-8.4o|\t|%-8.4o|\n","%-8.4", 0, 17, 1234);
	ft_printf("\t|%-8.4o|\t|%-8.4o|\t|%-8.4o|\n", 0, 17, 1234);
	printf("%-8s|%#-8.4o|\t|%#-8.4o|\t|%#-8.4o|\n","%#-8.4", 0, 17, 1234);
	ft_printf("\t|%#-8.4o|\t|%#-8.4o|\t|%#-8.4o|\n", 0, 17, 1234);
	printf("%-8s|%-4.8o|\t|%-4.8o|\t|%-4.8o|\n","%-4.8", 0, 17, 1234);
	ft_printf("\t|%-4.8o|\t|%-4.8o|\t|%-4.8o|\n", 0, 17, 1234);
	printf("%-8s|%#-4.8o|\t|%#-4.8o|\t|%#-4.8o|\n","%#-4.8", 0, 17, 1234);
	ft_printf("\t|%#-4.8o|\t|%#-4.8o|\t|%#-4.8o|\n", 0, 17, 1234);
	printf("%-8s|%-.5o|\t\t|%-.5o|\t\t|%-.5o|\n","%-.5", 0, 17, 1234);
	ft_printf("\t|%-.5o|\t\t|%-.5o|\t\t|%-.5o|\n", 0, 17, 1234);


	// undefined
	// printf("%-8s|% o|%16s|% o|%16s|% o|\n","% o0:", 0, "% o17: ", 17, "% o1234: ", 1234);
	// ft_printf("\t|% o|\t\t|% o|\t\t|% o|\n", 0, 17, 1234);
	// printf("%-8s|%+o|%16s|%+o|%16s|%+o|\n","%+o0:", 0, "%+o17: ", 17, "%+o1234: ", 1234);
	// ft_printf("\t|%+o|\t\t|%+o|\t\t|%+o|\n", 0, 17, 1234);
}

void	strt(void)
{
	printf("\n\t--- STRING %%s ---\n");
	printf("CASE STR:\t\"Random x10, another20\"\n\n");

	char *str = "Random x10, another20";

	printf("%-8s|%s|\n", "%s", str);
	ft_printf("\t|%s|\n",  str);
	printf("%-8s|%.5s|\n", "%.5s", str);
	ft_printf("\t|%.5s|\n",  str);
	printf("%-8s|%8s|\n", "%8s", str);
	ft_printf("\t|%8s|\n",  str);
	printf("%-8s|%8.5s|\n", "%8.5s", str);
	ft_printf("\t|%8.5s|\n",  str);
	printf("%-8s|%-s|\n", "%-s", str);
	ft_printf("\t|%-s|\n",  str);
	printf("%-8s|%-.5s|\n", "%-.5s", str);
	ft_printf("\t|%-.5s|\n",  str);
	printf("%-8s|%-8s|\n", "%-8s", str);
	ft_printf("\t|%-8s|\n",  str);
	printf("%-8s|%-8.5s|\n", "%-8.5s", str);
	ft_printf("\t|%-8.5s|\n", str);

	// printf("\nCASE STR:\t\"test5\"\n\n");
	str = "test5";
	printf("%-8s|%s|\n", "%s", str);
	ft_printf("\t|%s|\n",  str);
	printf("%-8s|%8s|\n", "%8s", str);
	ft_printf("\t|%8s|\n",  str);
	printf("%-8s|%-s|\n", "%-s", str);
	ft_printf("\t|%-s|\n",  str);
	printf("%-8s|%-8.2s|\n", "%-8.2s", str);
	ft_printf("\t|%-8.2s|\n",  str);

	char *test = NULL;
	printf("%-8s|%s|\n", "%s", test);
	ft_printf("\t|%s|\n",  test);
	printf("%-8s|%8s|\n", "%8s", test);
	ft_printf("\t|%8s|\n",  test);
	printf("%-8s|%8.4s|\n", "%8.4s", test);
	ft_printf("\t|%8.4s|\n",  test);
	//	undefined
	// printf("%-8s|%#s|\n", "%#s", str);
	// printf("%-8s|%+s|\n", "%+s", str);
	// printf("%-8s|%0s|\n", "%0s", str);
	// printf("%-8s|% s|\n", "% s", str);

}

void	adrt(void)
{
	int a = 42;
	float b = 100.1;
	char c = 'c';

	printf("\n\t--- ADDRESS %%p ---\n");
	printf("CASES:\t&int\t\t\t&float\t\t\t&char\n\n");

	printf("%-8s|%p|\t|%p|\t|%p|\n", "%", &a, &b, &c);
	ft_printf("%-8s|%p|\t|%p|\t|%p|\n", "%", &a, &b, &c);
	printf("%-8s|%16p|\t|%16p|\t|%16p|\n", "%16", &a, &b, &c);
	ft_printf("%-8s|%16p|\t|%16p|\t|%16p|\n", "%16", &a, &b, &c);
	printf("%-8s|%-16p|\t|%-16p|\t|%-16p|\n", "%-16", &a, &b, &c);
	ft_printf("%-8s|%-16p|\t|%-16p|\t|%-16p|\n", "%-16", &a, &b, &c);
	printf("%-8s|%5p|\t|%5p|\t|%5p|\n", "%5", &a, &b, &c);
	ft_printf("%-8s|%5p|\t|%5p|\t|%5p|\n", "%5", &a, &b, &c);

	//	undefined
	// printf("%-8s|% p|\t|% p|\t|% p|\n", "% ", &a, &b, &c);
	// printf("%-8s|%+p|\t|%+p|\t|%+p|\n", "%+", &a, &b, &c);
	// printf("%-8s|%016p|\t|%016p|\t|%016p|\n", "%016", &a, &b, &c);
	// printf("%-8s|%.5p|\t|%.5p|\t|%.5p|\n", "%.5", &a, &b, &c);
}

void	printed(void)
{
	printf("\n\t--- PRINTED %%n ---\n");
	printf("CASE:\t\"test%%n%%n\\ttest%%n x %%n\"\n\n");

	int a, b, c, d;
	printf("test%n%n\ttest%n x %n\n", &a, &b, &c, &d);
	printf("%d\t%d\t%d\t%d\n", a, b, c, d);
	a = 0, b = 0, c = 0, d = 0;
	printf("\n\tRESETTED RETURN VALUES: %d %d %d %d\n\n", a, b, c, d);
	ft_printf("test%n%n\ttest%n x %n\n", &a, &b, &c, &d);
	ft_printf("%d\t%d\t%d\t%d\n", a, b, c, d);

	//	undefined
	// printf("test%.5n%.5n\ttest%.5n x %.5n\n", &a, &b, &c, &d);
	// printf("test% n% n\ttest% n x % n\n", &a, &b, &c, &d);
	// printf("test%+n%+n\ttest%+n x %+n\n", &a, &b, &c, &d);
	// printf("test%0n%0n\ttest%0n x %0n\n", &a, &b, &c, &d);
	// printf("test%8n%8n\ttest%8n x %8n\n", &a, &b, &c, &d);
	// printf("test%-n%-n\ttest%-n x %-n\n", &a, &b, &c, &d);

}

void	floatt(void)
{
	double	z = 0, fm = 100.1234, f = -100.1234;
	printf("\n\t--- FLOAT %%f ---\n\n");
	printf("CASES:\t0\t\t100.1234\t-100.1234\n\n");
	// printf("CASES:\t0\t\t100.5\t\t42.49\t\t-42.5555\t\t10000.5000912\n\n");

	// printf("%-8s|%f|\t|%f|\t|%f|\t|%f|\t\t|%f|\n", "%", (double)0, 100.5, 42.49, -42.5555, 10000.5000912);
	// printf("\n\n\n");

	// long double a = 200.5;
	// unsigned long long b = 12345;
	// ft_printf("%f", 100.525);
	// ft_printf("%f", 6985.123459876);
	// ft_printf("%f", 6985123.12345987610101789123);
	// ft_printf("%f", 1234567891.4);
	// ft_printf("%f", 7.1234567891234567);
	// ft_printf("%Lf", a);
	// ft_printf("%Lf", 9999.4l);
	// ft_printf("%.10Lf", -2.9123349876123123l);
	// ft_printf("%.10Lf", 2.9123349876123123l);
	// printf("%Lf\n", (long double)b);
	//	*	*	*	*	*	*	*	*	*	*	*	*
	//	*	*	*	*	*	*	*	*	*	*	*	*
	//	*	*	*	*	*	*	*	*	*	*	*	*

	printf("\n");
	// single cases
	printf("%-8s", "%f");
	printf("|%f|\t|%f|\t|%f|\n", z, fm , f);
	ft_printf("\t|%f|\t|%f|\t|%f|\n", z, fm , f);
	printf("%-8s", "%+f");
	printf("|%+f|\t|%+f|\t|%+f|\n", z, fm , f);
	ft_printf("\t|%+f|\t|%+f|\t|%+f|\n", z, fm , f);
	printf("%-8s", "%-f");
	printf("|%-f|\t|%-f|\t|%-f|\n", z, fm , f);
	ft_printf("\t|%-f|\t|%-f|\t|%-f|\n", z, fm , f);
	printf("%-8s", "%0f");
	printf("|%0f|\t|%0f|\t|%0f|\n", z, fm , f);
	ft_printf("\t|%0f|\t|%0f|\t|%0f|\n", z, fm , f);
	printf("%-8s", "%8f");
	printf("|%8f|\t|%8f|\t|%8f|\n", z, fm , f);
	ft_printf("\t|%8f|\t|%8f|\t|%8f|\n", z, fm , f);
	printf("%-8s", "%3f");
	printf("|%3f|\t|%3f|\t|%3f|\n", z, fm , f);
	ft_printf("\t|%3f|\t|%3f|\t|%3f|\n", z, fm , f);
	printf("%-8s", "%.0f");
	printf("|%.0f|\t|%.0f|\t|%.0f|\n", z, fm , f);
	ft_printf("\t|%.0f|\t|%.0f|\t|%.0f|\n", z, fm , f);
	printf("%-8s", "%.3f");
	printf("|%.3f|\t|%.3f|\t|%.3f|\n", z, fm , f);
	ft_printf("\t|%.3f|\t|%.3f|\t|%.3f|\n", z, fm , f);
	printf("%-8s", "%.3f");
	printf("|%.3f|\t|%.3f|\t|%.3f|\n", z, fm , f);
	ft_printf("\t|%.3f|\t|%.3f|\t|%.3f|\n", z, fm , f);
	printf("%-8s", "%.9f");
	printf("|%.9f|\t|%.9f|\t|%.9f|\n", z, fm , f);
	ft_printf("\t|%.9f|\t|%.9f|\t|%.9f|\n", z, fm , f);
	printf("%-8s", "%#f");
	printf("|%#f|\t|%#f|\t|%#f|\n", z, fm , f);
	ft_printf("\t|%#f|\t|%#f|\t|%#f|\n", z, fm , f);
	printf("%-8s", "% f");
	printf("|% f|\t|% f|\t|% f|\n", z, fm , f);
	ft_printf("\t|% f|\t|% f|\t|% f|\n", z, fm , f);

	// all +0
	printf("%-8s", "%+0f");
	printf("|%+0f|\t|%+0f|\t|%+0f|\n", z, fm , f);
	ft_printf("\t|%+0f|\t|%+0f|\t|%+0f|\n", z, fm , f);
	printf("%-8s", "%+0.0f");
	printf("|%+0.0f|\t|%+0.0f|\t|%+0.0f|\n", z, fm , f);
	ft_printf("\t|%+0.0f|\t|%+0.0f|\t|%+0.0f|\n", z, fm , f);
	printf("%-8s", "%+0.3f");
	printf("|%+0.3f|\t|%+0.3f|\t|%+0.3f|\n", z, fm , f);
	ft_printf("\t|%+0.3f|\t|%+0.3f|\t|%+0.3f|\n", z, fm , f);
	printf("%-8s", "%+03f");
	printf("|%+0.8f|\t|%+0.8f|\t|%+0.8f|\n", z, fm , f);
	ft_printf("\t|%+0.8f|\t|%+0.8f|\t|%+0.8f|\n", z, fm , f);
	printf("%-8s", "%+03f");
	printf("|%+03f|\t|%+03f|\t|%+03f|\n", z, fm , f);
	ft_printf("\t|%+03f|\t|%+03f|\t|%+03f|\n", z, fm , f);
	printf("%-8s", "%+03.0f");
	printf("|%+03.0f|\t|%+03.0f|\t|%+03.0f|\n", z, fm , f);
	ft_printf("\t|%+03.0f|\t|%+03.0f|\t|%+03.0f|\n", z, fm , f);
	printf("%-8s", "%+03.8f");
	printf("|%+03.8f|\t|%+03.8f|\t|%+03.8f|\n", z, fm , f);
	ft_printf("\t|%+03.8f|\t|%+03.8f|\t|%+03.8f|\n", z, fm , f);
	printf("%-8s", "%+08.3f");
	printf("|%+08.3f|\t|%+08.3f|\t|%+08.3f|\n", z, fm , f);
	ft_printf("\t|%+08.3f|\t|%+08.3f|\t|%+08.3f|\n", z, fm , f);
	printf("%-8s", "%+08f");
	printf("|%+08f|\t|%+08f|\t|%+08f|\n", z, fm , f);
	ft_printf("\t|%+08f|\t|%+08f|\t|%+08f|\n", z, fm , f);
	printf("%-8s", "%+08.0f");
	printf("|%+08.0f|\t|%+08.0f|\t|%+08.0f|\n", z, fm , f);
	ft_printf("\t|%+08.0f|\t|%+08.0f|\t|%+08.0f|\n", z, fm , f);

		// all +-
	printf("%-8s", "%+-f");
	printf("|%+-f|\t|%+-f|\t|%+-f|\n", z, fm , f);
	ft_printf("\t|%+-f|\t|%+-f|\t|%+-f|\n", z, fm , f);
	printf("%-8s", "%+-.0f");
	printf("|%+-.0f|\t|%+-.0f|\t|%+-.0f|\n", z, fm , f);
	ft_printf("\t|%+-.0f|\t|%+-.0f|\t|%+-.0f|\n", z, fm , f);
	printf("%-8s", "%+-.3f");
	printf("|%+-.3f|\t|%+-.3f|\t|%+-.3f|\n", z, fm , f);
	ft_printf("\t|%+-.3f|\t|%+-.3f|\t|%+-.3f|\n", z, fm , f);
	printf("%-8s", "%+-.8f");
	printf("|%+-.8f|\t|%+-.8f|\t|%+-.8f|\n", z, fm , f);
	ft_printf("\t|%+-.8f|\t|%+-.8f|\t|%+-.8f|\n", z, fm , f);
	printf("%-8s", "%+-3f");
	printf("|%+-3f|\t|%+-3f|\t|%+-3f|\n", z, fm , f);
	ft_printf("\t|%+-3f|\t|%+-3f|\t|%+-3f|\n", z, fm , f);
	printf("%-8s", "%+-3.0f");
	printf("|%+-3.0f|\t|%+-3.0f|\t|%+-3.0f|\n", z, fm , f);
	ft_printf("\t|%+-3.0f|\t|%+-3.0f|\t|%+-3.0f|\n", z, fm , f);
	printf("%-8s", "%+-3.8f");
	printf("|%+-3.8f|\t|%+-3.8f|\t|%+-3.8f|\n", z, fm , f);
	ft_printf("\t|%+-3.8f|\t|%+-3.8f|\t|%+-3.8f|\n", z, fm , f);
	printf("%-8s", "%+-8f");
	printf("|%+-8f|\t|%+-8f|\t|%+-8f|\n", z, fm , f);
	ft_printf("\t|%+-8f|\t|%+-8f|\t|%+-8f|\n", z, fm , f);
	printf("%-8s", "%+-8.0f");
	printf("|%+-8.0f|\t|%+-8.0f|\t|%+-8.0f|\n", z, fm , f);
	ft_printf("\t|%+-8.0f|\t|%+-8.0f|\t|%+-8.0f|\n", z, fm , f);
	printf("%-8s", "%+-8.3f");
	printf("|%+-8.3f|\t|%+-8.3f|\t|%+-8.3f|\n", z, fm , f);
	ft_printf("\t|%+-8.3f|\t|%+-8.3f|\t|%+-8.3f|\n", z, fm , f);

	printf("%-8s", "%+.0f");
	printf("|%+.0f|\t|%+.0f|\t|%+.0f|\n", z, fm , f);
	ft_printf("\t|%+.0f|\t|%+.0f|\t|%+.0f|\n", z, fm , f);
	printf("%-8s", "%+8.0f");
	printf("|%+8.0f|\t|%+8.0f|\t|%+8.0f|\n", z, fm , f);
	ft_printf("\t|%+8.0f|\t|%+8.0f|\t|%+8.0f|\n", z, fm , f);
	printf("%-8s", "%+8.3f");
	printf("|%+8.3f|\t|%+8.3f|\t|%+8.3f|\n", z, fm , f);
	ft_printf("\t|%+8.3f|\t|%+8.3f|\t|%+8.3f|\n", z, fm , f);
	printf("%-8s", "%+3.0f");
	printf("|%+3.0f|\t|%+3.0f|\t|%+3.0f|\n", z, fm , f);
	ft_printf("\t|%+3.0f|\t|%+3.0f|\t|%+3.0f|\n", z, fm , f);
	printf("%-8s", "%+3.8f");
	printf("|%+3.8f|\t|%+3.8f|\t|%+3.8f|\n", z, fm , f);
	ft_printf("\t|%+3.8f|\t|%+3.8f|\t|%+3.8f|\n", z, fm , f);

	printf("%-8s", "% 8f");
	printf("|% 8f|\t|% 8f|\t|% 8f|\n", z, fm , f);
	ft_printf("\t|% 8f|\t|% 8f|\t|% 8f|\n", z, fm , f);
	printf("%-8s", "% 8.0f");
	printf("|% 8.0f|\t|% 8.0f|\t|% 8.0f|\n", z, fm , f);
	ft_printf("\t|% 8.0f|\t|% 8.0f|\t|% 8.0f|\n", z, fm , f);
	printf("%-8s", "% 3f");
	printf("|% 3f|\t|% 3f|\t|% 3f|\n", z, fm , f);
	ft_printf("\t|% 3f|\t|% 3f|\t|% 3f|\n", z, fm , f);
	printf("%-8s", "% 0f");
	printf("|% 0f|\t|% 0f|\t|% 0f|\n", z, fm , f);
	ft_printf("\t|% 0f|\t|% 0f|\t|% 0f|\n", z, fm , f);
	printf("%-8s", "% 3.8f");
	printf("|% 3.8f|\t|% 3.8f|\t|% 3.8f|\n", z, fm , f);
	ft_printf("\t|% 3.8f|\t|% 3.8f|\t|% 3.8f|\n", z, fm , f);
	printf("%-8s", "% 8.3f");
	printf("|% 8.3f|\t|% 8.3f|\t|% 8.3f|\n", z, fm , f);
	ft_printf("\t|% 8.3f|\t|% 8.3f|\t|% 8.3f|\n", z, fm , f);
	printf("%-8s", "% -f");
	printf("|% -f|\t|% -f|\t|% -f|\n", z, fm , f);
	ft_printf("\t|% -f|\t|% -f|\t|% -f|\n", z, fm , f);
	printf("%-8s", "% -8f");
	printf("|% -8f|\t|% -8f|\t|% -8f|\n", z, fm , f);
	ft_printf("\t|% -8f|\t|% -8f|\t|% -8f|\n", z, fm , f);
	printf("%-8s", "% -3f");
	printf("|% -3f|\t|% -3f|\t|% -3f|\n", z, fm , f);
	ft_printf("\t|% -3f|\t|% -3f|\t|% -3f|\n", z, fm , f);

	printf("%-8s", "%8.0f");
	printf("|%8.0f|\t|%8.0f|\t|%8.0f|\n", z, fm , f);
	ft_printf("\t|%8.0f|\t|%8.0f|\t|%8.0f|\n", z, fm , f);
	printf("%-8s", "%8.3f");
	printf("|%8.3f|\t|%8.3f|\t|%8.3f|\n", z, fm , f);
	ft_printf("\t|%8.3f|\t|%8.3f|\t|%8.3f|\n", z, fm , f);
	printf("%-8s", "%3.0f");
	printf("|%3.0f|\t|%3.0f|\t|%3.0f|\n", z, fm , f);
	ft_printf("\t|%3.0f|\t|%3.0f|\t|%3.0f|\n", z, fm , f);
	printf("%-8s", "%3.8f");
	printf("|%3.8f|\t|%3.8f|\t|%3.8f|\n", z, fm , f);
	ft_printf("\t|%3.8f|\t|%3.8f|\t|%3.8f|\n", z, fm , f);

	printf("%-8s", "%-8f");
	printf("|%-8f|\t|%-8f|\t|%-8f|\n", z, fm , f);
	ft_printf("\t|%-8f|\t|%-8f|\t|%-8f|\n", z, fm , f);
	printf("%-8s", "%-8.0f");
	printf("|%-8.0f|\t|%-8.0f|\t|%-8.0f|\n", z, fm , f);
	ft_printf("\t|%-8.0f|\t|%-8.0f|\t|%-8.0f|\n", z, fm , f);
	printf("%-8s", "%+-8.0f");
	printf("|%+-8.0f|\t|%+-8.0f|\t|%+-8.0f|\n", z, fm , f);
	ft_printf("\t|%+-8.0f|\t|%+-8.0f|\t|%+-8.0f|\n", z, fm , f);
	printf("%-8s", "%-8.3f");
	printf("|%-8.3f|\t|%-8.3f|\t|%-8.3f|\n", z, fm , f);
	ft_printf("\t|%-8.3f|\t|%-8.3f|\t|%-8.3f|\n", z, fm , f);
	printf("%-8s", "%-3f");
	printf("|%-3f|\t|%-3f|\t|%-3f|\n", z, fm , f);
	ft_printf("\t|%-3f|\t|%-3f|\t|%-3f|\n", z, fm , f);
	printf("%-8s", "%-3.0f");
	printf("|%-3.0f|\t|%-3.0f|\t|%-3.0f|\n", z, fm , f);
	ft_printf("\t|%-3.0f|\t|%-3.0f|\t|%-3.0f|\n", z, fm , f);
	printf("%-8s", "%-3.8f");
	printf("|%-3.8f|\t|%-3.8f|\t|%-3.8f|\n", z, fm , f);
	ft_printf("\t|%-3.8f|\t|%-3.8f|\t|%-3.8f|\n", z, fm , f);

	//	*	*	*	*	*	*	*	*	*	*	*	*
	//	*	*	*	*	*	*	*	*	*	*	*	*
	//	*	*	*	*	*	*	*	*	*	*	*	*

	(void)z, (void)fm, (void)f;

	printf("%-8s", "%.2f");
	printf("|%.2f|\n", 1.15);
	ft_printf("\t|%.2f|\n", 1.15);
	printf("%-8s", "%.2f");
	printf("|%.2f|\n", 1.55);
	ft_printf("\t|%.2f|\n", 1.55);
	printf("%-8s", "%.2f");
	printf("|%.2f|\n", 1.59);
	ft_printf("\t|%.2f|\n", 1.59);
	printf("%-8s", "%.15f");
	printf("|%.15f|\n", 1.15);
	ft_printf("\t|%.15f|\n", 1.15);
	printf("%-8s", "%.16f");
	printf("|%.16f|\n", 1.15);
	ft_printf("\t|%.16f|\n", 1.15);
	printf("%-8s", "%.17f");
	printf("|%.17f|\n", 1.15);
	ft_printf("\t|%.17f|\n", 1.15);
	printf("%-8s", "%.18f");
	printf("|%.18f|\n", 1.15);
	ft_printf("\t|%.18f|\n", 1.15);
	printf("%-8s", "%.19f");
	printf("|%.19f|\n", 1.15);
	ft_printf("\t|%.19f|\n", 1.15);
	printf("%-8s", "%.20f");
	printf("|%.20f|\n", 1.15);
	ft_printf("\t|%.20f|\n", 1.15);
	printf("%-8s", "%.21f");
	printf("|%.21f|\n", 1.15);
	ft_printf("\t|%.21f|\n", 1.15);
	printf("%-8s", "%.22f");
	printf("|%.22f|\n", 1.15);
	ft_printf("\t|%.22f|\n", 1.15);
	printf("%-8s", "%.23f");
	printf("|%.23f|\n", 1.15);
	ft_printf("\t|%.23f|\n", 1.15);
	printf("%-8s", "%.5f");
	printf("|%.5f|\n", 6985.123459111);
	ft_printf("\t|%.5f|\n", 6985.123459111);
	printf("%-8s", "%.6f");
	printf("|%.6f|\n", 6985.123459111);
	ft_printf("\t|%.6f|\n", 6985.123459111);
	printf("%-8s", "%.50f");
	printf("|%.50f|\n", 6985.123459111);
	ft_printf("\t|%.50f|\n", 6985.123459111);
	printf("%-8s", "%.100f");
	printf("|%.100f|\n", 6985.123459111);
	ft_printf("\t|%.100f|\n", 6985.123459111);
	printf("%-8s", "%.100f");
	printf("|%.100f|\n", 1.5);
	ft_printf("\t|%.100f|\n", 1.5);
	printf("%-8s", "%.100f");
	printf("|%.100f|\n", 2.5);
	ft_printf("\t|%.100f|\n", 2.5);
	printf("%-8s", "%.0f");
	printf("|%.0f|\n", 0.5);
	ft_printf("\t|%.0f|\n", 0.5);
	printf("%-8s", "%.0f");
	printf("|%.0f|\n", 1.5);
	ft_printf("\t|%.0f|\n", 1.5);
	printf("%-8s", "%.0f");
	printf("|%.0f|\n", 3.5);
	ft_printf("\t|%.0f|\n", 3.5);
	printf("%-8s", "%.0f");
	printf("|%.0f|\n", 4.5);
	ft_printf("\t|%.0f|\n", 4.5);
	printf("%-8s", "%.0f");
	printf("|%.0f|\n", 5.5);
	ft_printf("\t|%.0f|\n", 5.5);


	//	*	*	*	*	*	*	*	*	*	*	*	*
	//	*	*	*	*	*	*	*	*	*	*	*	*
	//	*	*	*	*	*	*	*	*	*	*	*	*

	// printf("%-8s|%#4.0f|\t\t|%#4.0f|\t\t|%#4.0f|\n", "%#4.0f", z, fm, f);
	// printf("%-8s|%#08.0f|\t|%#08.0f|\t|%#08.0f|\n", "%#08.0f", z, fm, f);

	// printf("\n");

	// printf("%-8s|%.1f|\t\t|%.1f|\t\t|%.1f|\n", "%.1f", (double)0, 9.96, 2.95);
	// printf("%-8s|%.2f|\t\t|%.2f|\t\t|%.2f|\n", "%.2f", (double)0, 9.969, 2.959);
	// printf("%-8s|%.1f|\t\t|%.1f|\t\t|%.1f|\n", "%.1f", (double)0, 9.9, 2.9);
	// printf("%-8s|%.0f|\t\t|%.0f|\t\t|%.0f|\t\t|%.0f|\n", "%.0f", 0.5, 1.5, 2.5, 3.5);

	// printf("\n");
	// printf("%.2f\n", 1.15);		//	1.15	(1.14 9999999999999911)
	// printf("%.2f\n", 1.55);		//	1.55	(1.55 0000000000000044)
	// printf("%.2f\n", 1.59);		// 	1.59	(1.59 000000000000008)
	// printf("%.15f\n", 1.15);	// 	1.50..	(1.149999999999999 911)
	// printf("%.16f\n", 1.15);	// 	1.49..	(1.1499999999999999 11)
	// printf("%.17f\n", 1.15);	// 	1.49..	(1.14999999999999991 1)
	// printf("%.5f\n", 6985.123459111);	//	6985.12345 9110999647
	// printf("%.6f\n", 6985.123459111);	//	6985.123459 110999647

	// printf("end of test\n");
	// printf("\n");

}

int main(void)
{
	floatt();	// ret value???
	// printf("%-8s", "%.22f");
	// printf("|%.24f|\n", 1.15);
	// printf("|%.23f|\n", 1.15);
	// printf("\t|%.22f|\n", 1.15);
	// ft_printf("\t|%.22f|\n", 1.15);
	// printf("\t|%.23f|\n", 1.15);
	// ft_printf("\t|%.23f|\n", 1.15);

	// printf("|%.100f|\n", 9.99);
	// ft_printf("|%.100|\nf", 9.99);

	// printf("|%#08x|\n", 42);
	// ft_printf("|%#08x|\n\n", 42);

	// int a = 0, b = 0;
	// a = printf("|%#lo|\n",ULONG_MAX);
	// b = ft_printf("|%#lo|\n",ULONG_MAX);
	// printf("\na = %d b = %d\n", a, b);
	// a = 0, b = 0;
	// a = printf("|%#26.24lo|\n",ULONG_MAX);
	// b = ft_printf("|%#26.24lo|\n",ULONG_MAX);
	// printf("\na = %d b = %d\n", a, b);
	// a = 0, b = 0;
	// a = printf("|%#24.26lo|\n",ULONG_MAX);
	// b = ft_printf("|%#24.26lo|\n",ULONG_MAX);
	// printf("\na = %d b = %d\n", a, b);
	// a = 0, b = 0;
	// a = printf("|%#-lo|\n",ULONG_MAX);
	// b = ft_printf("|%#-lo|\n",ULONG_MAX);
	// printf("\na = %d b = %d\n", a, b);
	// a = 0, b = 0;
	// a = printf("|%#-26.24lo|\n",ULONG_MAX);
	// b = ft_printf("|%#-26.24lo|\n",ULONG_MAX);
	// printf("\na = %d b = %d\n", a, b);
	// a = 0, b = 0;
	// a = printf("|%#-24.26lo|\n",ULONG_MAX);
	// b = ft_printf("|%#-24.26lo|\n",ULONG_MAX);
	// printf("\na = %d b = %d\n", a, b);
	// a = printf("|%#lo|\n",ULONG_MAX - 2);
	// b = ft_printf("|%#lo|\n",ULONG_MAX - 2);
	// printf("\na = %d b = %d|\n", a, b);
	// a = 0, b = 0;


	// a = printf("|%p|\n", &i);
	// b = ft_printf("|%p|\n", &i);
	// printf("a = %d b = %d|\n", a, b);
	// a = 0, b = 0;
	// a = printf("s: |%s|, p: |%p|, d:|%d|\n", "a string", &test_simple_mix, 42);
	// b = ft_printf("s: |%s|, p: |%p|, d:|%d|\n", "a string", &test_simple_mix, 42);
	// printf("a = %d b = %d|\n", a, b);
	// a = 0, b = 0;
	// a = printf("|%s| |%d| |%p| |%%| |%x|\n", "bonjour ", 42, &free, 42);
	// b = ft_printf("|%s| |%d| |%p| |%%| |%x|\n", "bonjour ", 42, &free, 42);
	// printf("a = %d b = %d|\n", a, b);
	// a = 0, b = 0;
	// int i = 42, test_simple_mix = 10;
	// a = printf("|%lo|, |%lo|\n", 0ul, ULONG_MAX);
	// b = ft_printf("|%lo|, |%lo|\n", 0ul, ULONG_MAX);
	// printf("a = %d b = %d|\n", a, b);
	// a = 0, b = 0;
	// a = printf("|%llo|, |%llo|\n", 0llu, ULLONG_MAX);
	// b = ft_printf("|%llo|, |%llo|\n", 0llu, ULLONG_MAX);
	// printf("a = %d b = %d|\n", a, b);
	// a = 0, b = 0;
	// a = printf("{%5p}|\n", 0);
	// b = ft_printf("{%5p}|\n", 0);
	// printf("a = %d b = %d|\n", a, b);
	// a = 0, b = 0;
	// a = printf("|%.4s|\n", "42");
	// b = ft_printf("|%.4s|\n", "42");
	// printf("a = %d b = %d|\n", a, b);
	// a = 0, b = 0;
	// a = printf("|%.0p|, |%.p|\n", 0, 0);
	// b = ft_printf("|%.0p|, |%.p|\n", 0, 0);
	// printf("a = %d b = %d|\n", a, b);
	// a = 0, b = 0;
	// a = printf("|%.p|, |%.0p|\n", 0, 0);
	// b = ft_printf("|%.p|, |%.0p|\n", 0, 0);
	// printf("a = %d b = %d|\n", a, b);
	// a = 0, b = 0;
	// a = printf("{%f}{%lf}{%Lf}|\n", 1.42, 1.42, 1.42l);
	// b = ft_printf("{%f}{%lf}{%Lf}|\n", 1.42, 1.42, 1.42l);
	// printf("a = %d b = %d|\n", a, b);
	// a = 0, b = 0;
	// a = printf("{%.*s}\n", 5, "42");
	// b = ft_printf("{%.*s}\n", 5, "42");
	// printf("a = %d b = %d|\n", a, b);

				// OK!
	// printed();
	// adrt();
	// strt();
	// octals();
	// hext();
	// unsigt();
	// chart();
	// percent();

	// test_d();
	// spacet();
	// widt();
	// plust();
	// prect();
	// zerot();
	// minust();


}
