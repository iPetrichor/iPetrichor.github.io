#include<stdio.h>
#include<stdlib.h>

int main()
{
	int i,j,n;
	
	printf("请输入金字塔行数：\n");
	scanf("%d",&n);
	for(i=1;i<n+1;i++)
	{
		printf("\n");
		for(j=1;j<2*n;j++)
		{
			if(abs(j-n)>i-1)
				printf(" ");
			else
				printf("%c",'A'+i-1-abs(j-n));
			
		}
	}
	return 0;
}
