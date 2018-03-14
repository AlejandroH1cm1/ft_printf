#include "libpf.h"
#include <limits.h>

int main(void){
	int i;
	void *p;
	wchar_t c;
	wchar_t s[] = L"PO요猫O5";

	c = L'莨';
	i = ft_printf("OWO%-+12.14lld %c %p %#o WHATS THIS",112421421412,92, &c, 33);
	i = printf("%d\n",i);
	p = &i;
	printf("<%u>",-42);
	printf("<%6.4s>\n","OWO WHATS THIS");
	printf("<%+012.6f>\n",41.41);
	printf("<%10.2%>\n");
	printf("[%d]\n",0);
	printf("%C\n", c);
	ft_putwchar(L'δ');
	printf("<<%12ls>>\n", (wchar_t *)NULL);
	printf("<%ls>",s);

	return -1;
}
