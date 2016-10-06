#include <stdio.h>
#include <string.h>
int main(){
	char str[1000]={0};
	char a[60]={0};
	char b[2]={0};
	char c[60]={0};
	char result;
	char x = '+';
	printf("Start....\n(input) ");
	fgets(str, sizeof(str),stdin);
	result = strchr(str, x);
	strcpy(b[0],result);
	printf("%c",b[0]);
	return 0;
}
