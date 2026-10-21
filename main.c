#include "libft.h"
#include <stdio.h>

char	foo(unsigned int a, char c)
{
	c = (c + a);
	return (c);
}

int main(void)
{
	char *str = "taha";
	char (*f)(unsigned int, char);
	f = foo;
	char *ptr = ft_strmapi(str, f);
	printf("%s\n", ptr);
	free(ptr);
}
