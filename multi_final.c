char multi(char a2[], char b2[])
{
	char k[61]={};
	int t=51, q;
	for(int i=60;i>51;i--)
		if(a2[i]!='0')
		{
			t=i+1;
			break;
		}
	for(int i=1;i<61;i++)
		if((a2[i]!='0')&&(a2[i]!='.'))
		{
			q=i;
			break;
		}
	printf("%d %d\n", t, q);
	for(int i=0;i<61;i++)
		k[i]=b2[i];
	for(int i=q;i<t;i++)
	{
		int p=a2[i]-'0';
		if(i==51)
			continue;
		for(int j=0;j<p;j++)
		{
			if((i==q)&&(j==0))
				continue;
			plus(k,b2);
		}
		if(i==t-1)
			break;
		for(int j=0;j<60;j++)
		{
			if(j==50)
				b2[j]=b2[j+2];
			else if(j==51)
				continue;
			else
				b2[j]=b2[j+1];
		}
		b2[60]='0';
	}
	if(t>51)
		q=t-52;
	for(int j=60;j>=0;j--)
	{
		if(j==52)
			b2[j]=b2[j-(t-51)];
		else if(j==51)
			continue;
		else
			b2[j]=b2[j-(t-52)];
	}
	for(int i=0;i<t-52;i++)
		b2[i]='0';

}
