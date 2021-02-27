#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct player{
	int number;
	int age; 
	char name[25];
	char place[25];
}Player; 
 
typedef struct user{
	char name[25];
	int code;
	struct user * next;
}User; 

typedef User* uList;
 
typedef struct node{
	Player item;
	struct node * next; 
}Node;

typedef Node* List;


//�������岿�֣�
void regis(void);
int login(char * temp,int n);
void makeMenu(void);
void makeuMenu(void);
void menuKey(int n);
void menuOne(void);
void menuTwo(void);
void menuThree(void);
void menuFour(void);
void menuFive(void); 
void menuSix(void);
void menuZero(void);
void read(void);
void write(void);


List head;
uList uhead;

void main()
{
	int SeqN,n,a=1,b;
	char temp[20];
	head=(List)malloc(sizeof(Node));
	head->next=NULL; 
	uhead=(uList)malloc(sizeof(User));
	uhead->next=NULL;
	
	while(a)
	{
		makeuMenu();
		scanf("%d",&b);
		if(b==1)	
		{	
			printf("�������û�����");
			scanf("%s",temp);
			printf("\n���������룺");
			scanf("%d",&n);
			a=login(temp,n);
		}
		else if(b==2)
		{
			
			
			
		}
	}
	system("cls");
	
	makeMenu();
	read();
	while(scanf("%d",&SeqN)==1)
	{ 
		menuKey(SeqN); 
		makeMenu();
	}
	
	return;
}


void regis(void)
{
	uList p,q;
	p=uhead->next;
	FILE * fp;
	char buf[20];
	
	fp=fopen("user.txt","a+");
	while(p!=NULL)
	{
		fprintf(fp,"%s\t%d\n",p->name,p->code);
		p=p->next;
	}
	
	fclose(fp);
	return;
}


int login(char * temp,int n)
{
	uList p,q;
	p=uhead->next;
	FILE * fp;
	int a,b,c;
	char buf[20];
	char ch;
	
	fp=fopen("user.txt","r");
	c=fscanf(fp,"%s\t%d\n",buf,b);
	while(c!=EOF)
	{
		a=strncmp(buf,temp,20);
		if(a==0)
		{
			if(n==b)
			{
				printf("��½�ɹ������س�ȷ�ϣ�");
				ch=getchar();
				while(ch=getchar()!='\n')
					continue;
				system("cls");
				fclose(fp);
				return 0;	
			}
			else
				break;
		}
		fscanf(fp,"%s\t%d\n",buf,b);
	}
	printf("�������򲻴��ڴ��û������س�ȷ�ϣ�");
	ch=getchar();
	while(ch=getchar()!='\n')
		continue;
	system("cls");
	fclose(fp);
	return 1;	
}


void makeuMenu(void)
{
	printf("*************\n");
	printf("1.��¼\n");
	printf("2.ע��\n");
	printf("0.�˳�\n");
	printf("*************\n");
	printf("������0~2��");	
	return;
}


void makeMenu(void)
{
	printf("----------------------------------------------------\n");
	printf("\t1.��ʾȫ����Ա��Ϣ\n"); 
	printf("\t2.��Ա���а�\n");
	printf("\t3.��ѯ��Ա��Ϣ\n");
	printf("\t4.�޸���Ա��Ϣ\n");
	printf("\t5.ɾ����Ա��Ϣ\n");
	printf("\t6.��������Ա\n");
	printf("\t7.��δ�Ƴ���\n");
	printf("\t8.��δ�Ƴ���\n");
	printf("\t9.��δ�Ƴ���\n");
	printf("\t0.���沢�˳�ϵͳ");
	printf("\n----------------------------------------------------\n");
	printf("������0~9��");
	return;
}


void menuKey(int n)
{
	switch(n)
	{
		case 1:
			menuOne();
			return;
		case 2:
			menuTwo();
			return;
		case 3:
			menuThree();
			return;
		case 4:
			menuFour();
			return;
		case 5:
			menuFive();
			return;
		case 6:
			menuSix();
			while(getchar()!='\n')
				continue;
			return;
		case 0:
			menuZero();
			return;
		default:
			while(getchar()!='\n')
				continue;
			return;
	}
}


void menuOne(void)
{
	List current;
	current=head->next;
	char ch;
	
	char a[10];//ȷ���뷵�ء� 
	system("cls");
	printf("ȷ��Ҫ��ʾȫ����Ա��Ϣ��(Y/N)");
	scanf("%s",a);
	if(a[0]!='Y'&&a[0]!='y')
	{
		system("cls");
 		return;
	}
	if(a[0]=='Y'||a[0]=='y')
	{	
		if(current==NULL)//ÿ������ȷ�Ϻ���ʾ�Ĳ�һ���� 
		{
			system("cls");
			printf("��δ¼����Ա��Ϣ�����س�ȷ�ϣ�");
			ch=getchar();
			while(ch=getchar()!='\n')
				continue;
			system("cls");
			return;
		}
		printf("--------------------------------------------------------------------------------\n");
		printf("����\t\t\t����\t  ����\t    λ��\n");
		while(current!=NULL)
		{
			printf("%-25s%-10d%-10d%-10s\n",current->item.name,current->item.number,
			current->item.age,current->item.place);
			current=current->next;
		}
		printf("(���س�����)");
		printf("\n--------------------------------------------------------------------------------");
		ch=getchar();
		while(ch=getchar()!='\n')
			continue;
		system("cls");
		return;
	} 		
}  


void menuTwo(void)//���� 
{
	List p,q;
	Node temp;
	int a,b,c;
	char ch;	
	char buf[25];
	
	system("cls");
	printf("*************\n");
	printf("1.����������\n");
	printf("2.����������\n");
	printf("0.����\n");
	printf("*************\n");
	printf("������0~2��");
	scanf("%d",&a);
	system("cls");
	if(a==1)
	{
		for(p=head->next;p!=NULL;p=p->next)
		{
			for(q=head->next;q->next!=NULL;q=q->next)
			{
				if((q->item.number) > (q->next->item.number))
				{
					temp.item=q->next->item;
					q->next->item=q->item;
					q->item=temp.item;
				}	
			}
		}
		printf("����ɹ���(���س�����)"); 
		ch=getchar();
		while(ch=getchar()!='\n')
			continue;
		system("cls");
		return;		
	}	
	else if(a==2)
	{
		for(p=head->next;p!=NULL;p=p->next)
		{
			for(q=head->next;q->next!=NULL;q=q->next)
			{
				if((q->item.age) > (q->next->item.age))
				{
					temp.item=q->next->item;
					q->next->item=q->item;
					q->item=temp.item;
				}	
			}
		}
		printf("����ɹ���(���س�����)"); 
		ch=getchar();
		while(ch=getchar()!='\n')
			continue;
		system("cls");
		return;	
	}
	else
	{
		system("cls");
		return;
	}
}



void menuThree(void)
{
	List current;
	current=head->next;
	int a,b,c;
	char ch;	
	char buf[25];
	
	system("cls");
	printf("*************\n");
	printf("1.�����ֲ�ѯ\n");
	printf("2.�������ѯ\n");
	printf("0.����\n");
	printf("*************\n");
	printf("������0~2��");
	scanf("%d",&a);
	system("cls");
	if(a==1)
	{
		printf("������Ҫ��ѯ����Ա����");
		scanf("%s",buf);
		while(current!=NULL)
		{
			b=strncmp(buf,current->item.name,25);	
			if(b==0)
			{
				printf("--------------------------------------------------------------------------------\n");
				printf("����\t\t\t����\t  ����\t    λ��\n");
				printf("%-25s%-10d%-10d%-10s\n",current->item.name,current->item.number,
				current->item.age,current->item.place);
				printf("(���س�����)");
				printf("\n--------------------------------------------------------------------------------");
				ch=getchar();
				while(ch=getchar()!='\n')
					continue;
				system("cls");
				return;
			}
			current=current->next;
		}
		printf("���޴��ˣ�(���س�����)"); 
		ch=getchar();
		while(ch=getchar()!='\n')
			continue;
		system("cls");
		return;
	}
	else if(a==2)
	{
		printf("������Ҫ��ѯ����Ա�ţ�");
		scanf("%d",&c);
		while(current!=NULL)
		{
			b=current->item.number;
			if(b==c)
			{
				printf("--------------------------------------------------------------------------------\n");
				printf("����\t\t\t����\t  ����\t    λ��\n");
				printf("%-25s%-10d%-10d%-10s\n",current->item.name,current->item.number,
				current->item.age,current->item.place);
				printf("(���س�����)");
				printf("\n--------------------------------------------------------------------------------");
				ch=getchar();
				while(ch=getchar()!='\n')
					continue;
				system("cls");
				return;
			}
			current=current->next;
		}
		printf("���޴��ˣ�(���س�����)"); 
		ch=getchar();
		while(ch=getchar()!='\n')
			continue;
		system("cls");
		return;
	}
	else
	{
		system("cls");
		return;
	}
	
}

void menuFour(void)//�� 
{
	List current=head->next;
	int a,b,c ;
	char buf[25];
	char ch;
	 
	printf("������Ҫ�޸���Ϣ����Ա��");
	scanf("%s",buf);
	while(current!=NULL)
	{
		b=strncmp(buf,current->item.name,25);	
		if(b==0)
		{
			printf("*************\n");
			printf("1.�޸ĺ���\n");
			printf("2.�޸�����\n");
			printf("3.�޸�λ��\n");
			printf("0.����\n");
			printf("*************\n");
			printf("������0~3��");
			scanf("%d",&a);
			if(a==1)
			{
				printf("�����Ϊ��");
				scanf("%d",&c);
				current->item.number=c;
				printf("�޸ĳɹ���");
			}
			else if(a==2)
			{
				printf("�����Ϊ��");
				scanf("%d",&c);
				current->item.age=c;
				printf("�޸ĳɹ���");
			}
			else if(a==3)
			{
				printf("�����Ϊ��");
				scanf("%s",buf);
				strcpy(current->item.place,buf);
				printf("�޸ĳɹ���");
			}
			else
			{
				system("cls");
				return;
			}
			ch=getchar();
			while(ch=getchar()!='\n')
				continue;
			system("cls");
			return;
		}
		current=current->next;
	}
	printf("���޴��ˣ�(���س�����)"); 
	ch=getchar();
	while(ch=getchar()!='\n')
		continue;
	system("cls");
	return;
}

void menuFive(void)//ɾ 
{
	List current=head->next;
	List prev=head;
	int b;
	char buf[25];
	char ch;
	
	printf("������Ҫɾ������Ա��");
		scanf("%s",buf);
		while(current!=NULL)
		{
			b=strncmp(buf,current->item.name,25);
			if(b==0)
			{
				prev->next=current->next;
				free(current);
				printf("ɾ���ɹ���(���س�����)");
				ch=getchar();
				while(ch=getchar()!='\n')
					continue;
				system("cls");
				return;
			}
			current=current->next;
			prev=prev->next;
		}
	printf("���޴��ˣ�(���س�����)"); 
	ch=getchar();
	while(ch=getchar()!='\n')
		continue;
	system("cls");
	return;
}

void menuSix(void)
{
	List current,prev;
	current=head;
	FILE * fp;
	
	char a[10];//ȷ���뷵�ء� 
	system("cls");
	printf("ȷ��Ҫ��������Ա��(Y/N)");
	scanf("%s",a);
	if(a[0]!='Y'&&a[0]!='y')
	{
		system("cls");
 		return;
	}
	if(a[0]=='Y'||a[0]=='y')
	{	
		while(current->next!=NULL)
			current=current->next;
		prev=current;
		current=(List)malloc(sizeof(Node));
		prev->next=current;
		current->next=NULL;
		printf("����������Ա��Ϣ������ ���� ���� λ�� ��:");
		scanf("%s%d%d%s",&current->item.name,&current->item.number,&current->item.age,
		current->item.place);
		system("cls");
		return;
	}	
}


void menuZero(void)
{
	char ch;
	
	char a[10];//ȷ���뷵�ء� 
	system("cls");
	printf("ȷ��Ҫ�˳���(Y/N)");
	scanf("%s",a);
	if(a[0]!='Y'&&a[0]!='y')
	{
		system("cls");
 		return;
	}
	if(a[0]=='Y'||a[0]=='y') 
	{
		write();
		exit(1);
	}
}


void read(void)
{
	FILE * fp;
	List current,prev;
	int a;
	prev=head;
	
	fp=fopen("data.txt","r");
	if(fp==NULL)
	{
		fp=fopen("data.txt","w");//����ļ������ڣ����½�һ���� 
	}
	current=(List)malloc(sizeof(Node));
	current->next=NULL;
	while(a=fscanf(fp,"%s\t%d\t%d\t%s\t",current->item.name,&current->item.number,&current->item.age,
		current->item.place)!=EOF)
	{
		prev->next=current;
		prev=current;
		current=(List)malloc(sizeof(Node));
		current->next=NULL;
	}
	free(current);
	fclose(fp);
	return;
}


void write(void)
{
	FILE * fp;
	List current=head->next;
	
	fp=fopen("data.txt","w");
	while(current!=NULL)
	{
		fprintf(fp,"%s\t%d\t%d\t%s\t",current->item.name,current->item.number,current->item.age,
		current->item.place);
		current=current->next;
	}
	fclose(fp);
	return;		
}
