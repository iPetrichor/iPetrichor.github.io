#include<stdio.h>
#include<string.h>


int main()
{
	int i,j,La,Lb,L2,L1,k=0;
	
	printf("请输入原字符串的长度：");
	scanf("%d",&L1);
	
	char A[L1];
	
	printf("请输入所需原字符串：");
	scanf("%s",A);
	
	printf("请输入检索字符串的长度："); 
	scanf("%d",&L2);
	
	char B[L2];

	printf("请输入要检索的字符串："); 
	scanf("%s",B); 
	
	char C[L2];

	printf("请输入要将切片替换成的字符串："); 
	scanf("%s",C);//交互部分结束。
	
	
	La=strlen(A);//总长
	Lb=strlen(B);//检索长度 
	
	
	for(i=0;i<La;i++)
	{
		for(j=0;j<Lb;j++)
		{
			if(A[i+j]==B[j])
			{
				k++;
				if(k==Lb)
				{
					printf("the goal is %d.\n",i+1);
					for(;k>0;k--)
						A[i+k-1]=C[k-1];
					k=0;
					break;	
				}			
			}
			else
				break;
		}
	}		
	printf("最终字符串为：%s",A);
	
	return 0;
}
