#include<stdio.h>
#include<string.h>


int main()
{
	int i,j,La,Lb,L2,L1,k=0;
	
	printf("������ԭ�ַ����ĳ��ȣ�");
	scanf("%d",&L1);
	
	char A[L1];
	
	printf("����������ԭ�ַ�����");
	scanf("%s",A);
	
	printf("����������ַ����ĳ��ȣ�"); 
	scanf("%d",&L2);
	
	char B[L2];

	printf("������Ҫ�������ַ�����"); 
	scanf("%s",B); 
	
	char C[L2];

	printf("������Ҫ����Ƭ�滻�ɵ��ַ�����"); 
	scanf("%s",C);//�������ֽ�����
	
	
	La=strlen(A);//�ܳ�
	Lb=strlen(B);//�������� 
	
	
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
	printf("�����ַ���Ϊ��%s",A);
	
	return 0;
}
