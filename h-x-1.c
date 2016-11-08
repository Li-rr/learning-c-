#include <stdio.h>
int main ()
{
	int fuc(int n);
	int n;
	int s;
	printf("input an integer number:");
	scanf("%d",&n);
	s=fuc(n);
	printf("%d",s);
	return 0;
}

    int fuc(int n)
	{
	int f;
	if(n<0)
		printf("n<0,data error!");
	else if(n==0||n==1)
		f=1;
	else 
		f=fuc(n-1)*n;
	return (f);
}

