#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include <windows.h>
struct goods
{
	int bianhao;
	char pinming[20];
	float jinjia;
	float shoujia;
	int jinhuoliang;
	int xiaoshouliang;
	float xiaoshoue;
	int shengyushu;
	float maoli;
};
struct Node
{
	struct goods data;
	struct Node *next;
};
struct Node *head;
struct Node*create();
void input();
void addgoods();
void delgoods(); 
void changegoods();
void viewgoods();
void paixu();
void search();
void tongji();
int main()
{
	int choice;
//	system("color a6");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 | 64 | 8 | 128);
	//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),前景色 | 背景色 | 前景加强 | 背景加强)
	FILE *fp;
	printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
	printf("┃                                       ┃\n");
	printf("┃               欢迎光临                ┃\n");
	printf("┃              没灰尘小超市             ┃\n");
	printf("┃                                       ┃\n");
	printf("┠━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┨\n");
	while(1)
	{
		
		printf("┃            1.录入商品                 ┃\n");
		printf("┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┨\n");
		printf("┃            2.添加商品                 ┃\n");
		printf("┠━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┨\n");
		printf("┃            3.删除商品                 ┃\n");
		printf("┠━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┨\n");
		printf("┃            4.修改商品                 ┃\n");
		printf("┠━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┨\n");
		printf("┃            5.浏览商品                 ┃\n"); 
		printf("┠━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┨\n");
		printf("┃            6.排序并显示               ┃\n"); 
		printf("┠━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┨\n");
		printf("┃            7.查询商品信息             ┃\n"); 
		printf("┠━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┨\n");
		printf("┃            8.统计商品信息             ┃\n");
		printf("┠━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┨\n");
		printf("┃            9.退出系统                 ┃\n");
		printf("┠━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┨\n");
		printf("┃                                       ┃\n");
		printf("┃            请输入对应编号             ┃\n");
		printf("┃                                       ┃\n");
		printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
		scanf("%d",&choice);
		fp=fopen("D:\\file1.dat","rb");
		if(fp==NULL)
		{
			while(choice!=1)
			{
				printf("请先输入1录入商品\n");
				scanf("%d",&choice);
			}
		}
		system("cls");
		switch(choice)
		{
		case 1:input();break;
		case 2:addgoods();break;
		case 3:delgoods();break;
		case 4:changegoods();break;
		case 5:viewgoods();break;
		case 6:paixu();break;
		case 7:search();break;
		case 8:tongji();break;
		case 9:exit(0);break;
		default:break;
		}
	}
	return 0;
}
void input()
{
	FILE *fp;
	struct goods SP;
	char m;
	printf("录入\n");
	printf("请输入要录入商品信息\n");
	printf("*************************\n");
	fp=fopen("D:\\file1.dat","wb");
	if(fp==NULL)
	{
		printf("文件打开失败\n");
		exit(0);
	}
	fclose(fp);
	while(1)
	{
		printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
		printf("        请输入商品编号\n");
		printf("┠━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┨\n");
		scanf("%d",&SP.bianhao);
		printf("        请输入商品品名\n");
		printf("┠━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┨\n");
		scanf("%s",SP.pinming);
		printf("		请输入商品进价\n");
		printf("┠━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┨\n");
		scanf("%f",&SP.jinjia);
		printf("		请输入商品售价\n");
		printf("┠━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┨\n");
		scanf("%f",&SP.shoujia);
		printf("		请输入商品进货量\n");
		printf("┠━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┨\n");
		scanf("%d",&SP.jinhuoliang);
		printf("		请输入商品销售量\n");
		printf("┠━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┨\n");
		scanf("%d",&SP.xiaoshouliang);
		printf("		请输入商品销售额\n");
		printf("┠━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┨\n");
		scanf("%f",&SP.xiaoshoue);
		printf("		请输入商品剩余数\n");
		printf("┠━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┨\n");
		scanf("%d",&SP.shengyushu);
		printf("		请输入商品毛利\n");
		printf("┠━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┨\n");
		scanf("%f",&SP.maoli);
		printf("		是否确定要录入该商品信息？(y or n)\n");
		printf("┠━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┨\n");
		m=getchar();
		while(m!='Y'&&m!='y'&&m!='N'&&m!='n')
		{
			m=getchar();
		}
		if(m=='Y'||m=='y')
		{
			fp=fopen("D:\\file1.dat","ab");
			if(fp==NULL)
			{
				printf("文件打开失败\n");
				exit(0);
			}
			fwrite(&SP,sizeof(struct goods),1,fp);
			fclose(fp);
			printf("*************************\n");
			printf("该商品录入完成\n");
		}
		printf("是否继续录入商品信息?(y or n)\n");
		m=getchar();
		while(m!='Y'&&m!='y'&&m!='N'&&m!='n')
		{
			m=getchar();
		}
		if(m=='Y'||m=='y')
		{
			system("cls");
			continue;
		}
		else
		{
			printf("录入完成\n");
			break;
		}
	}
	viewgoods();
}
void addgoods()
{
	char m;
	FILE *fp;
	struct goods SP;
	struct Node *p1,*p2,*p3,*head;
	while(1)
	{
		head=NULL;
		p1=p2=(struct Node*)malloc(sizeof(struct Node));
		fp=fopen("D:\\file1.dat","rb");
		if(fp==NULL)
		{
			printf("文件打开失败\n");
			exit(0);
		}
		while(!feof(fp))
		{
			if(fread(&SP,sizeof(struct goods),1,fp)==1)
			{
				p1->data=SP;
				if(head==NULL)
					head=p1;
				else
					p2->next=p1;
				p2=p1;
				p1=(struct Node*)malloc(sizeof(struct Node));
			}
		}
		p2->next=NULL;
		fclose(fp);
		printf("添加商品\n");
		printf("请输入该商品以下信息\n");
		printf("*************************\n");
		printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
		printf("        请输入商品编号\n");
		printf("┠━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┨\n");
		scanf("%d",&SP.bianhao);
		printf("        请输入商品品名\n");
		printf("┠━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┨\n");
		scanf("%s",SP.pinming);
		printf("		请输入商品进价\n");
		printf("┠━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┨\n");
		scanf("%f",&SP.jinjia);
		printf("		请输入商品售价\n");
		printf("┠━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┨\n");
		scanf("%f",&SP.shoujia);
		printf("		请输入商品进货量\n");
		printf("┠━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┨\n");
		scanf("%d",&SP.jinhuoliang);
		printf("		请输入商品销售量\n");
		printf("┠━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┨\n");
		scanf("%d",&SP.xiaoshouliang);
		printf("		请输入商品销售额\n");
		printf("┠━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┨\n");
		scanf("%f",&SP.xiaoshoue);
		printf("		请输入商品剩余数\n");
		printf("┠━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┨\n");
		scanf("%d",&SP.shengyushu);
		printf("		请输入商品毛利\n");
		printf("┠━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┨\n");
		scanf("%f",&SP.maoli);
		printf("		是否确定要录入该商品信息？(y or n)\n");
		printf("┠━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┨\n");
		m=getchar();
		while(m!='Y'&&m!='y'&&m!='N'&&m!='n')
		{
			m=getchar();
		}
		if(m=='Y'||m=='y')
		{
			p1=(struct Node*)malloc(sizeof(struct Node));
			p1->data=SP;
			p1->next=NULL;
			p2->next=p1;
			fp=fopen("D:\\file1.dat","wb");
			if(fp==NULL)
			{
				printf("文件打开失败\n");
				exit(0);
			}
			p1=head;
			while(p1!=NULL)
			{
				fwrite(&p1->data,sizeof(struct goods),1,fp);
				p3=p1;
				p1=p1->next;
				free(p3);
			}
			fclose(fp);
			printf("*************************\n");
			printf("该商品添加完成\n");
		}
		printf("是否要继续添加商品？(y or n)\n");
		m=getchar();
		while(m!='Y'&&m!='y'&&m!='N'&&m!='n')
		{
			m=getchar();
		}
		if(m=='Y'||m=='y')
		{
			system("cls");
			continue;
		}
		else
		{
			printf("添加功能完成\n");
			break;
		}
	}
	viewgoods();
} 
void delgoods()
{
	struct Node *p1,*p2,*p3;
	char m;
	int bianhao,flag=0;
	FILE *fp;
	printf("删除商品\n");
	printf("*************************\n");
	while(1)
	{
		head=create();
		if(head==NULL)
		{
			printf("文件里没有商品\n");
			system("pause");
			system("cls");
			break;
		}
		p1=head;
		p2=head->next;
		printf("请输出您要删除商品的编号\n");
		scanf("%d",&bianhao);
		fp=fopen("D:\\file1.dat","rb");
		if(fp==NULL)
		{
			printf("文件打开失败");
			exit(0);
		}
		if(p1->data.bianhao==bianhao)
		{
			flag++;
			printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
			printf("  商品编号	:	%d\n",p1->data.bianhao);
			printf("┠━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┨\n");
			printf("  商品品名	:	%s\n",p1->data.pinming);
			printf("┠━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┨\n");
			printf("  商品进价	:	%.2f\n",p1->data.jinjia);
			printf("┠━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┨\n");
			printf("  商品售价	:	%.2f\n",p1->data.shoujia);
			printf("┠━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┨\n");
			printf("  商品进货量	:	%d\n",p1->data.jinhuoliang);
			printf("┠━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┨\n");
			printf("  商品销售量	:	%d\n",p1->data.xiaoshouliang);
			printf("┠━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┨\n");
			printf("  商品销售额	:	%.2f\n",p1->data.xiaoshoue);
			printf("┠━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┨\n");
			printf("  商品剩余数	:	%.2f\n",p1->data.shengyushu);
			printf("┠━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┨\n");
			printf("  商品毛利	:	%d\n",p1->data.maoli);
			printf("┠━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┨\n");
		    printf("┠━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┨\n");
		    printf("┠━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┨\n");
		    printf("┠━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┨\n");
			printf("您确定要删除这件商品的信息吗？(y or n)\n");
			m=getchar();
			while(m!='Y'&&m!='y'&&m!='N'&&m!='n')
			{
				m=getchar();
			}
			if(m=='Y'||m=='y')
			{
				head=p1->next;
				fp=fopen("D:\\file1.dat","wb");
				if(fp==NULL)
				{
					printf("文件打开失败\n");
					exit(0);
				}
				p1=head;
				while(p1!=NULL)
				{
					fwrite(&p1->data,sizeof(struct goods),1,fp);
					p3=p1;
					p1=p1->next;
					free(p3);
				}
				fclose(fp);
				printf("*************************\n");
				printf("该商品已删除\n");
			}
		}
		else
		{
			while(p2!=NULL)
			{
				if(p2->data.bianhao==bianhao)
				{
					flag++;
					printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
					printf("  商品编号	:	%d\n",p1->data.bianhao);
					printf("┠━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┨\n");
					printf("  商品品名	:	%s\n",p1->data.pinming);
					printf("┠━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┨\n");
					printf("  商品进价	:	%.2f\n",p1->data.jinjia);
					printf("┠━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┨\n");
					printf("  商品售价	:	%.2f\n",p1->data.shoujia);
					printf("┠━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┨\n");
					printf("  商品进货量	:	%d\n",p1->data.jinhuoliang);
					printf("┠━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┨\n");
					printf("  商品销售量	:	%d\n",p1->data.xiaoshouliang);
					printf("┠━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┨\n");
					printf("  商品销售额	:	%.2f\n",p1->data.xiaoshoue);
					printf("┠━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┨\n");
					printf("  商品剩余数	:	%.2f\n",p1->data.shengyushu);
					printf("┠━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┨\n");
					printf("  商品毛利	:	%d\n",p1->data.maoli);
					printf("┠━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┨\n");
				    printf("┠━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┨\n");
				    printf("┠━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┨\n");
				    printf("┠━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┨\n");
					printf("您确定要删除这件商品的信息吗？(y or n)\n");
					while(m!='Y'&&m!='y'&&m!='N'&&m!='n')
					{
						m=getchar();
					}
					if(m=='Y'||m=='y')
					{
						p1->next=p2->next;
						fp=fopen("D:\\file1.dat","wb");
						if(fp==NULL)
						{
							printf("文件打开失败\n");
							exit(0);
						}
						p1=head;
						while(p1!=NULL)
						{
							fwrite(&p1->data,sizeof(struct goods),1,fp);
							p3=p1;
							p1=p1->next;
							free(p3);
						}
						fclose(fp);
						printf("*************************\n");
						printf("该商品已删除\n");
						break;
					}
				}
				else
				{
					p1=p1->next;
					p2=p2->next;
				}
			}
		}
		if(flag==0)
		{
			printf("这件商品不存在\n");
		}
		printf("是否要继续删除商品？(y or n)\n");
		m=getchar();
		while(m!='Y'&&m!='y'&&m!='N'&&m!='n')
		{
			m=getchar();
		}
		if(m=='Y'||m=='y')
		{
			system("cls");
			continue;
		}
		else
		{
			printf("删除功能完成\n");
			break;
		}
	}
	viewgoods();
}
struct Node*create() 
{
	struct Node *p1,*p2;
	struct goods SP;
	FILE *fp;
	head=NULL;
	p1=p2=(struct Node*)malloc(sizeof(struct Node));
	fp=fopen("D:\\file1.dat","rb");
	if(fp==NULL)
	{
		printf("文件打开失败");
		exit(0);
	}
	while(!feof(fp))
	{
		if(fread(&SP,sizeof(struct goods),1,fp)==1)
		{
			p1->data=SP;
			if(head==NULL)
				head=p1;
			else
				p2->next=p1;
			p2=p1;
			p1=(struct Node*)malloc(sizeof(struct Node));
		}
	}
	p2->next=NULL;
	fclose(fp);
	return head;
}
void changegoods()
{
	int bianhao,i,flag=0,count=0;
	char m;
	struct goods SPP[20];
	struct goods SP;
	FILE *fp;
	fp=fopen("D:\\file1.dat","rb");
	if(fp==NULL)
	{
		printf("文件打开失败");
		exit(0);
	}  
	while(!feof(fp))
	{
		if(fread(&SPP[count],sizeof(struct goods),1,fp)==1)
		{
			count++;
		}
	}
	fclose(fp);
	if(count==0)
	{
		printf("文件里没有商品\n");
		system("pause");
		system("cls");
	}
	else
	{
		printf("是否要根据编号找到该商品修改信息？(y or n)\n");
		m=getchar();
		while(m!='Y'&&m!='y'&&m!='N'&&m!='n')
		{
			m=getchar();
		}
		if(m=='Y'||m=='y')
		{
			while(1)
			{
				count=0,flag=0;
				printf("请输入要找的商品编号\n");
				scanf("%d",&bianhao);
				fp=fopen("D:\\file1.dat","rb");
				if(fp==NULL)
				{
					printf("文件打开失败");
					exit(0);
				}  
				printf("******************\n");
				while(!feof(fp))
				{
					if(fread(&SPP[count],sizeof(struct goods),1,fp)==1)
					{
						count++;
					}
				}
				fclose(fp);
				printf("******************\n");
				for(i=0;i<count;i++)
				{
					if(SPP[i].bianhao==bianhao)
					{
						flag++;
						break;
					}
				}
				if(flag==0)
				{
					printf("该商品不存在\n");
				}
				else
				{
					printf("是否确定修改？(y or n)\n");
					m=getchar();
					while(m!='Y'&&m!='y'&&m!='N'&&m!='n')
					{
						m=getchar();
					}
					if(m=='Y'||m=='y')
					{
						printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
						printf("        请输入商品编号\n");
						printf("┠━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┨\n");
						scanf("%d",&SP.bianhao);
						printf("        请输入商品品名\n");
						printf("┠━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┨\n");
						scanf("%s",SP.pinming);
						printf("		请输入商品进价\n");
						printf("┠━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┨\n");
						scanf("%f",&SP.jinjia);
						printf("		请输入商品售价\n");
						printf("┠━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┨\n");
						scanf("%f",&SP.shoujia);
						printf("		请输入商品进货量\n");
						printf("┠━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┨\n");
						scanf("%d",&SP.jinhuoliang);
						printf("		请输入商品销售量\n");
						printf("┠━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┨\n");
						scanf("%d",&SP.xiaoshouliang);
						printf("		请输入商品销售额\n");
						printf("┠━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┨\n");
						scanf("%f",&SP.xiaoshoue);
						printf("		请输入商品剩余数\n");
						printf("┠━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┨\n");
						scanf("%d",&SP.shengyushu);
						printf("		请输入商品毛利\n");
						printf("┠━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┨\n");
						scanf("%f",&SP.maoli);
						printf("┠━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┨\n");
						SPP[i]=SP;
						fp=fopen("D:\\file1.dat","wb");
						if(fp==NULL)
						{
							printf("文件打开失败");
							exit(0);
						}
						for(i=0;i<count;i++)
						{
							fwrite(&SPP[i],sizeof(struct goods),1,fp);
						}
						fclose(fp);
						printf("*************************\n");
						printf("该商品修改已完成\n");
					}
				}
				printf("是否要继续修改商品？(y or n)\n");
				m=getchar();
				while(m!='Y'&&m!='y'&&m!='N'&&m!='n')
				{
					m=getchar();
				}
				if(m=='Y'||m=='y')
				{
					system("cls");
					continue;
				}
				else
				{
					printf("修改结束\n");
					break;
				}
			}
		}
		viewgoods();
	}
}
void viewgoods()
{
	struct goods *p;
	FILE *fp;
	p=(struct goods*)malloc(sizeof(struct goods));
	fp = fopen("D:\\file1.dat","rb");
	if (fp == NULL)
	{
		printf("文件打开失败！\n");
	}
	while(1)
	{
		if (fread(p,sizeof(struct goods),1,fp) == 1)
		{
			printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
			printf("  商品编号	:	%d\n",p->bianhao);
			printf("┠━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┨\n");
			printf("  商品品名	:	%s\n",p->pinming);
			printf("┠━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┨\n");
			printf("  商品进价	:	%.2f\n",p->jinjia);
			printf("┠━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┨\n");
			printf("  商品售价	:	%.2f\n",p->shoujia);
			printf("┠━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┨\n");
			printf("  商品进货量	:	%d\n",p->jinhuoliang);
			printf("┠━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┨\n");
			printf("  商品销售量	:	%d\n",p->xiaoshouliang);
			printf("┠━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┨\n");
			printf("  商品销售额	:	%.2f\n",p->xiaoshoue);
			printf("┠━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┨\n");
			printf("  商品剩余数	:	%d\n",p->shengyushu);
			printf("┠━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┨\n");
			printf("  商品毛利	:	%.2f\n",p->maoli);
			printf("┠━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┨\n");
		    printf("┠━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┨\n");
		    printf("┠━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┨\n");
		    printf("┠━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┨\n");
			p=(struct goods*)malloc(sizeof(struct goods));
		}
		else
		{
			break;
		}
	}
	fclose(fp);
	free(p);
	system("pause");
	system("cls");
	getchar();
}
void paixu()
{
	struct goods SPP[20];
	struct goods SP;
	int i,j,count;
	FILE *fp;
	count=0;
	fp=fopen("D:\\file1.dat","rb");
	if(fp==NULL)
	{
		printf("文件打开失败\n");
		exit(0);
	}
	while(!feof(fp))
	{
		if(fread(&SPP[count],sizeof(struct goods),1,fp)==1)
		{
			count++;
		}
	}
	fclose(fp);
	for(i=0;i<count-1;i++)
	{
		for(j=i+1;j<count;j++)
		{
			if(SPP[i].bianhao>SPP[j].bianhao)
			{
				SP=SPP[i];
				SPP[i]=SPP[j];
				SPP[j]=SP;
			}
		}
	}
	fp=fopen("D:\\file1.dat","wb");
	if(fp==NULL)
	{
		printf("文件打开失败");
		exit(0);
	}  
	printf("******************\n");
	printf("按编号从小到大排序并显示\n");
	for(i=0;i<count;i++)
	{
		fwrite(&SPP[i],sizeof(struct goods),1,fp);
		printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
		printf("  商品编号	:	%d\n",SPP[i].bianhao);
		printf("┠━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┨\n");
		printf("  商品品名	:	%s\n",SPP[i].pinming);
		printf("┠━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┨\n");
		printf("  商品进价	:	%.2f\n",SPP[i].jinjia);
		printf("┠━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┨\n");
		printf("  商品售价	:	%.2f\n",SPP[i].shoujia);
		printf("┠━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┨\n");
		printf("  商品进货量	:	%d\n",SPP[i].jinhuoliang);
		printf("┠━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┨\n");
		printf("  商品销售量	:	%d\n",SPP[i].xiaoshouliang);
		printf("┠━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┨\n");
		printf("  商品销售额	:	%.2f\n",SPP[i].xiaoshoue);
		printf("┠━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┨\n");
		printf("  商品剩余数	:	%d\n",SPP[i].shengyushu);
		printf("┠━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┨\n");
		printf("  商品毛利	:	%.2f\n",SPP[i].maoli);
		printf("┠━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┨\n");
	    printf("┠━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┨\n");
	    printf("┠━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┨\n");
	    printf("┠━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┨\n");
	}
	fclose(fp);
	system("pause");
	printf("*************************\n");
	count=0;
	fp=fopen("D:\\file1.dat","rb");
	if(fp==NULL)
	{
		printf("文件打开失败\n");
		exit(0);
	}
	while(!feof(fp))
	{
		if(fread(&SPP[count],sizeof(struct goods),1,fp)==1)
		{
			count++;
		}
	}
	fclose(fp);
	for(i=0;i<count-1;i++)
	{
		for(j=i+1;j<count;j++)
		{
			if(SPP[i].maoli<SPP[j].maoli)
			{
				SP=SPP[i];
				SPP[i]=SPP[j];
				SPP[j]=SP;
			}
		}
	}
	fp=fopen("D:\\file1.dat","wb");
	if(fp==NULL)
	{
		printf("文件打开失败");
		exit(0);
	}  
	printf("******************\n");
	printf("按毛利从高到低排序并显示\n");
	for(i=0;i<count;i++)
	{
		fwrite(&SPP[i],sizeof(struct goods),1,fp);
		printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
		printf("  商品编号	:	%d\n",SPP[i].bianhao);
		printf("┠━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┨\n");
		printf("  商品品名	:	%s\n",SPP[i].pinming);
		printf("┠━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┨\n");
		printf("  商品进价	:	%d\n",SPP[i].jinjia);
		printf("┠━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┨\n");
		printf("  商品售价	:	%d\n",SPP[i].shoujia);
		printf("┠━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┨\n");
		printf("  商品进货量	:	%d\n",SPP[i].jinhuoliang);
		printf("┠━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┨\n");
		printf("  商品销售量	:	%d\n",SPP[i].xiaoshouliang);
		printf("┠━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┨\n");
		printf("  商品销售额	:	%d\n",SPP[i].xiaoshoue);
		printf("┠━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┨\n");
		printf("  商品剩余数	:	%d\n",SPP[i].shengyushu);
		printf("┠━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┨\n");
		printf("  商品毛利	:	%d\n",SPP[i].maoli);
		printf("┠━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┨\n");
	    printf("┠━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┨\n");
	    printf("┠━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┨\n");
	    printf("┠━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┨\n");
	}
	fclose(fp);
	system("pause");
	printf("********************\n");
	count=0;
	fp=fopen("D:\\file1.dat","rb");
	if(fp==NULL)
	{
		printf("文件打开失败\n");
		exit(0);
	}
	while(!feof(fp))
	{
		if(fread(&SPP[count],sizeof(struct goods),1,fp)==1)
		{
			count++;
		}
	}
	fclose(fp);
	for(i=0;i<count-1;i++)
	{
		for(j=i+1;j<count;j++)
		{
			if(SPP[i].xiaoshoue<SPP[j].xiaoshoue)
			{
				SP=SPP[i];
				SPP[i]=SPP[j];
				SPP[j]=SP;
			}
		}
	}
	fp=fopen("D:\\file1.dat","wb");
	if(fp==NULL)
	{
		printf("文件打开失败");
		exit(0);
	}  
	printf("******************\n");
	printf("按销售额从高到低排序并显示\n");
	for(i=0;i<count;i++)
	{
		fwrite(&SPP[i],sizeof(struct goods),1,fp);
		printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
		printf("  商品编号	:	%d\n",SPP[i].bianhao);
		printf("┠━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┨\n");
		printf("  商品品名	:	%s\n",SPP[i].pinming);
		printf("┠━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┨\n");
		printf("  商品进价	:	%d\n",SPP[i].jinjia);
		printf("┠━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┨\n");
		printf("  商品售价	:	%d\n",SPP[i].shoujia);
		printf("┠━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┨\n");
		printf("  商品进货量	:	%d\n",SPP[i].jinhuoliang);
		printf("┠━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┨\n");
		printf("  商品销售量	:	%d\n",SPP[i].xiaoshouliang);
		printf("┠━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┨\n");
		printf("  商品销售额	:	%d\n",SPP[i].xiaoshoue);
		printf("┠━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┨\n");
		printf("  商品剩余数	:	%d\n",SPP[i].shengyushu);
		printf("┠━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┨\n");
		printf("  商品毛利	:	%d\n",SPP[i].maoli);
		printf("┠━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┨\n");
	    printf("┠━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┨\n");
	    printf("┠━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┨\n");
	    printf("┠━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┨\n");
	}
	fclose(fp);
	printf("*************************\n");
	system("pause");
	system("cls");
}
void search()
{
	FILE *fp;
	struct goods SPP[20],SP;
	char name[20],m;
	int rest,low=0,high=0,mid;
	int i,j,flag=0,count=0;
	fp=fopen("D:\\file1.dat","rb");
	if(fp==NULL)
	{
		printf("文件打开失败\n");
		exit(0);
	}
	while(!feof(fp))
	{
		if(fread(&SP,sizeof(struct goods),1,fp)==1)
		{
			count++;
		}
	}
	fclose(fp);
	if(count==0)
	{
		printf("文件里没有商品\n");
		system("pause");
		system("cls");
	}
	else
	{
		printf("是否要根据商品品名查询商品信息?(y or n)\n");
		m=getchar();
		while(m!='Y'&&m!='y'&&m!='N'&&m!='n')
		{
			m=getchar();
		}
		if(m=='Y'||m=='y')
		{
			printf("*************************\n");
			printf("请输入该品名商品的信息\n");
			scanf("%s",name);
			fp=fopen("D:\\file1.dat","rb");
			if(fp==NULL)
			{
				printf("文件打开失败\n");
				exit(0);
			}
			while(!feof(fp))
			{
				if(fread(&SP,sizeof(struct goods),1,fp)==1)
				{
					if(strcmp(name,SP.pinming)==0)
					{
						printf("按品名查找到的商品如下\n");
						printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
						printf("  商品编号	:	%d\n",SP.bianhao);
						printf("┠━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┨\n");
						printf("  商品品名	:	%s\n",SP.pinming);
						printf("┠━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┨\n");
						printf("  商品进价	:	%.2f\n",SP.jinjia);
						printf("┠━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┨\n");
						printf("  商品售价	:	%.2f\n",SP.shoujia);
						printf("┠━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┨\n");
						printf("  商品进货量	:	%d\n",SP.jinhuoliang);
						printf("┠━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┨\n");
						printf("  商品销售量	:	%d\n",SP.xiaoshouliang);
						printf("┠━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┨\n");
						printf("  商品销售额	:	%.2f\n",SP.xiaoshoue);
						printf("┠━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┨\n");
						printf("  商品剩余数	:	%d\n",SP.shengyushu);
						printf("┠━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┨\n");
						printf("  商品毛利	:	%.2f\n",SP.maoli);
						printf("┠━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┨\n");
					    printf("┠━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┨\n");
					    printf("┠━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┨\n");
					    printf("┠━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┨\n");
						flag++;
					}
				}
			}
			if(flag==0)
			{
				printf("该品名商品不存在\n");
			}
		}
		printf("是否要根据剩余数来查询商品信息？(y or n)\n");
		m=getchar();
		while(m!='Y'&&m!='y'&&m!='N'&&m!='n')
		{
			m=getchar();
		}
		if(m=='Y'||m=='y')
		{
			fp=fopen("D:\\file1.dat","rb");
			if(fp==NULL)
			{
				printf("文件打开失败\n");
				exit(0);
			}
			while(!feof(fp))
			{
				if(fread(&SPP[high],sizeof(struct goods),1,fp)==1)
				{
					high++;
				}
			}
			fclose(fp);
			for(i=0;i<high-1;i++)
			{
				for(j=i+1;j<high;j++)
				{
					if(SPP[i].shengyushu>SPP[j].shengyushu)
					{
						SP=SPP[i];
						SPP[i]=SPP[j];
						SPP[j]=SP;
					}
				}
			}
			printf("*************************\n");
			printf("请输出要查询商品的剩余数为: ");
			scanf("%d",&rest);
			while(low<=high)
			{
				mid=(low+high)/2;
				if(rest==SPP[mid].shengyushu)
				{
					break;
				}
				else
					if(rest<SPP[mid].shengyushu)
					{
						high=mid-1;
					}
					else
					{
						low=mid+1;
					}
			}
			if(low<=high)
			{
				printf("按剩余数查找到的商品如下\n");
				printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
				printf("  商品编号	:	%d\n",SPP[mid].bianhao);
				printf("┠━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┨\n");
				printf("  商品品名	:	%s\n",SPP[mid].pinming);
				printf("┠━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┨\n");
				printf("  商品进价	:	%.2f\n",SPP[mid].jinjia);
				printf("┠━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┨\n");
				printf("  商品售价	:	%.2f\n",SPP[mid].shoujia);
				printf("┠━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┨\n");
				printf("  商品进货量	:	%d\n",SPP[mid].jinhuoliang);
				printf("┠━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┨\n");
				printf("  商品销售量	:	%d\n",SPP[mid].xiaoshouliang);
				printf("┠━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┨\n");
				printf("  商品销售额	:	%.2f\n",SPP[mid].xiaoshoue);
				printf("┠━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┨\n");
				printf("  商品剩余数	:	%d\n",SPP[mid].shengyushu);
				printf("┠━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┨\n");
				printf("  商品毛利	:	%.2f\n",SPP[mid].maoli);
				printf("┠━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┨\n");
			    printf("┠━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┨\n");
			    printf("┠━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┨\n");
			    printf("┠━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┨\n");
			}
			else
			{
				printf("该商品不存在\n");
			}
		}
	}
	system("pause");
	system("cls");
}
void tongji()
{
	FILE *fp;
	struct goods SP;
	int count=0;
	fp=fopen("D:\\file1.dat","rb");
	if(fp==NULL)
	{
		printf("文件打开失败\n");
		exit(0);
	}
	while(!feof(fp))
	{
		if(fread(&SP,sizeof(struct goods),1,fp)==1)
		{
			count++;
		}
	}
	fclose(fp);
	if(count==0)
	{
		printf("文件里没有商品\n");
		system("pause");
		system("cls");
	}
	else
	{
		fp=fopen("D:\\file1.dat","rb");
		if(fp==NULL)
		{
			printf("文件打开失败\n");
			exit(0);
		}
		while(!feof(fp))
		{
			if(fread(&SP,sizeof(struct goods),1,fp)==1)
			{
				printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
				printf("┃  商品编号	:	%d\n",SP.bianhao);
				printf("┠━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┨\n");
				printf("┃  商品品名	:	%s\n",SP.pinming);
				printf("┠━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┨\n");
				printf("┃  商品销售额	:	%.2f\n",SP.xiaoshoue);
				printf("┠━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┨\n");
				printf("┃  商品剩余数	:	%d\n",SP.shengyushu);
				printf("┠━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┨\n");
				printf("┃  商品毛利	:	%.2f\n",SP.maoli);
				printf("┠━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┨\n");
				printf("┠_______________________________________┨\n");
			}
		}
	}
	system("pause");
	system("cls");
}
