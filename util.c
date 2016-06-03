#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	char a[10000];
	static char k[10000];
	FILE *sv;

	printf("입력 : ");
	scanf("%s", a);
	
	if((strcmp(a,"clear")!=0)&&(strcmp(a,"save")!=0))
		for(int i=0;i<100;i++)
			k[i]=a[i];
	
	if(strcmp(a,"clear")==0)
		system("clear");


	else if(strcmp(a,"save")==0)
	{
		sv=fopen("save","w");
		fprintf(sv, "%s", k);
		fclose(sv);
	}
	
	else if(strcmp(a,"end")==0)
		return 0;
	main();
}
