#include <stdio.h>
int main(){
	int n = 10;
	int *pointer = &n;
	printf("Address using variable: %p\n", &n);
	printf("Address using pointer: %p\n", pointer);
	*pointer = 20;
	printf("new value of the number: %d\n", n);
     	return 1;
}
