#include "libpf.h"
#include <limits.h>

int main(void){
	printf("%0#-8X\n", INT_MAX);
	ft_printf("%0#-8X\n", INT_MAX);
	return 0;
}
