// exemplo 1

#include <stdio.h>

void main (void){
	int target, source;
	int *m;

	source = 10;
	m = &source;

	target = *m;

	printf("%d", target);
}
