#include<stdio.h>
#include<stdlib.h> 
#include<string.h>
static int StudentNum;
static int ClassMoney;//����ܽ�� 
static int FinancialNum;
static int j=0;
static int Sum;
struct StuInf
{
	int No;//ѧ��
	char Name[20];//����
	char Sex[5];//�Ա� 
}Stu[100],*p;
struct Financial 
{
	char Date[12];//���� 
	int Money;//��� 
	char type[100];//����
	char ps[100];
}Fin[100],*p1; 
void ViewLoginShow();//�˵�ѡ��
int BWLogin();       // ��ί��¼ 
void meanushow(); //��ʾ��¼����
void menuselection();//�˵�ѡ����ʾ
void CYLogin();//�༶��Ա��¼
void CYmeanushow();//��ʾ��Ա��½����
void CYmenuselection();//��Ա��½�˵���ʾ
void SetInfs();//�½�ȫ����Ա��Ϣ    
void DisplayAll();//��ʾȫ����Ϣ 
void InfQuerys();//��ѯѧ����Ϣ
void ReviseInf();//�޸�ѧ����Ϣ
void DelInf();//ɾ��ָ��ѧ�ŵ�ѧ����Ϣ 
void SortInf();//����ѧ�Ž������� 
void AddFinancil();//��ί������
void CYAddFinancil();//��Ա������
void PayFinancil();// ֧������ 
void CYFinQuerys();//��Ա��ѯ��ϸ�б� 
void FinQuerys();//��ί��ѯ��ϸ�б�
void main()
{
	while(1)
	{   
		ViewLoginShow();
		system("cls");
	}
}
void ViewLoginShow()//��ʾ��½����                             �˳�ϵͳ ���ص�¼ 
{
	char ch;
	system("cls");
	printf("\n\n");
	printf("\n\t\t\t+----------------------------------+");
	printf("\n\t\t\t+    ��ӭʹ�ð༶�������ϵͳ      +");
	printf("\n\t\t\t+----------------------------------+");
	printf("\n\t\t\t��ѡ���¼����ʽ�� 1.��ί��¼ 2. �༶��Ա��¼\n");
    ch=getchar();
    system("cls");
    switch(ch)
	{
	  case '1':
        BWLogin();
	    break;
	  case '2':
        CYLogin();
		break;
	  default :
		  printf("\n\t\t\t��ѡ��Ĺ��ܲ����ڣ�");
		  break;
	}
}
int BWLogin()	//����Ա��¼
{
	char name[]="admin",pwd[]="my123";												//��ȷ�ĺ�����
	char username[10],userpwd[10];													//�û�������û���������
	int count;																		//�û������û���������Ĵ���
	for(count=1;count<=3;count++)													//���û����λ���
	{
		printf("\n");
		printf("******�������û���:\n");
		scanf("%s",&username);
		printf("******����������:");
		scanf("%s",userpwd);
		if(strcmp(name,username)==0&&strcmp(pwd,userpwd)==0)
			{
				meanushow();
		    	menuselection();
			}																//����û���������������ȷ�����¼�ɹ�������1
		else																		//��������������ʾ������ʾ��Ϣ��
			if(count<3)																//������ǵ����Σ�������˴�����Ϣ
			printf("*******�û�������������������������룡����*******\n");
	}
	printf("******�û�������������ѳ���3�Σ�ϵͳ�Զ��˳�������******");
	return 0;																		//�˳�ѭ��ʱ��˵���Ѿ��������Σ���½ʧ��
}
void meanushow()//����Աѡ����� 
{
	printf("\n");
	printf("\t**************************\n");
	printf("\t*��ӭʹ��*\n");
	printf("\t*ѧУ�༶��ѹ���ϵͳ*\n");
	printf("\t**************************\n");
	printf("\t*1:�����༶��Ա��Ϣ*\n");
	printf("\t*2:ɾ��ָ��ѧ�ŵ�ѧ����Ϣ  *\n");
	printf("\t*3:��ѯѧ����Ϣ*\n");
	printf("\t*4:��ʾȫ����Ա��Ϣ*\n");
	printf("\t*5:�޸�ѧ����Ϣ*\n");
	printf("\t*6:�������룩������Ϣ*\n");
	printf("\t*7:֧������*\n"); 
	printf("\t*8:��ѯ��ϸ�б� *\n");
	printf("\t*9:�˳�ϵͳ*\n");
}
void menuselection()//����Աѡ�����˵� 
{
	int a;
	printf("���������ѡ��(1��9):");
	scanf("%d",&a);
	switch(a)
	{
		case 1: SetInfs();break;	//�����༶��Ա��Ϣ
		case 2: DelInf();break;//ɾ����Ϣ 
		case 3: InfQuerys();break;	//��ѯѧ����Ϣ
		case 4: DisplayAll();break;//��ʾȫ����Ա��Ϣ
		case 5: ReviseInf() ;break;	//�޸�ѧ����Ϣ
		case 6: AddFinancil();break;//�������룩������Ϣ 
		case 7:	PayFinancil();break;// ֧������ 
		case 8: FinQuerys();break;//��ѯ��ϸ�б� 
		case 9: system("pause");break;		//�˳�ϵͳ
		default:printf("%d,������1-9֮�������\n",a);
	}
}
void CYLogin()	//��ͨ�û���¼
{
	char name[]="cxy",pwd[]="666";												//��ȷ�ĺ�����
	char username[10],userpwd[10];													//�û�������û���������
	int count;																		//�û������û���������Ĵ���
	for(count=1;count<=3;count++)													//���û����λ���
	{
		printf("\n");
		printf("******�������û���:");
		scanf("%s",username);
		printf("******����������:");
		scanf("%s",userpwd);
		if(strcmp(name,username)==0&&strcmp(pwd,userpwd)==0)
			{
				CYmeanushow();
		    	CYmenuselection();
			}//����û���������������ȷ�����¼�ɹ�����1
		else																		//��������������ʾ������ʾ��Ϣ��
			if(count<3)																//������ǵ����Σ�������˴�����Ϣ
			printf("*******�û�������������������������룡����*******\n");
	}
	printf("******�û�������������ѳ���3�Σ�ϵͳ�Զ��˳�������******");																//�˳�ѭ��ʱ��˵���Ѿ��������Σ���½ʧ��
}
void CYmeanushow()//��Աѡ����� 
{
	printf("\n");
	printf("\t**************************\n");
	printf("\t*��ӭʹ��*\n");
	printf("\t*ѧУ�༶��ѹ���ϵͳ*\n");
	printf("\t**************************\n");
	printf("\t*1:�Ͻ����*\n");
	printf("\t*2:��ѯѧ����Ϣ*\n");
	printf("\t*3:��ѯ��ϸ�б�*\n");
	printf("\t*4:�˳�ϵͳ*\n"); 
}
void CYmenuselection()//��Աѡ�����˵� 
{
	int a;
	printf("���������ѡ��(1��):");
	scanf("%d",&a);
	switch(a)
	{
		case 1: CYAddFinancil();break;		    //�Ͻ����
		case 2: InfQuerys();break;			//��ѯѧ����Ϣ 
		case 3: FinQuerys();break;			//��ѯ��ϸ�б�
		case 4: system("pause");break;			//�˳�ϵͳ
	
		default:printf("%d,������1-9֮�������\n",a);
	
	}
	CYmeanushow();
	CYmenuselection();
}
void SetInfs()//����༶��Ա��Ϣ 
{ 
	system("cls");
	FILE *fp;
	char ch;
	int i=0;
	p=Stu;
	if((fp=fopen("stu.txt","w+"))==NULL)
	{
		printf("�ļ���ʧ�ܣ�\n");
		exit(0);
	}
		printf("��������Ҫ�½�ѧ������:\n");
	scanf("%d",&StudentNum);
	do
	{
		printf("������ѧ��:\n");
		scanf("%d",&p->No);
		printf("����������:\n");
		scanf("%s",&p->Name);
		printf("�������Ա�\n");
		scanf("%s",&p->Sex);
		i++;p++;
		system("cls");
	}
	while (i<StudentNum);
	printf("�������\n");
	p=Stu;
	for(i=0;i<StudentNum;i++,p++)
	{
		fprintf(fp,"%d %s %s \n",p->No,p->Name,p->Sex);
	}
	printf("�����ļ�����Ϊ��\n");
	p=Stu;
	for(i=0;i<StudentNum;i++,p++)
	{
		printf("%d\t %s\t %s\t \n",p->No,p->Name,p->Sex);
	}
	fclose(fp);
	meanushow();
	menuselection();
}
void DisplayAll()//��ʾȫ����Ϣ 
{
	system("cls");
	SortInf();
	int i;
	for(i=0;i<StudentNum;i++)
	{
		printf("%-8d %-12s %-6d %-12s %-6d",Stu[i].No,Stu[i].Name,Stu[i].Sex);
	}
}
void DelInf()//ɾ��ָ��ѧ�ŵ�ѧ����Ϣ 
{
	char ok[5];//ȷ���Ƿ�Ҫ��ɾ��
	int i,j;
	printf("��������Ҫɾ����ѧ��ѧ��:");
	scanf("%d",&p->No);
	printf("���Ƿ�Ҫɾ��������Ϣ?(y/n)\n");
	scanf("%d",ok);
	if(ok[0]=='y'||ok[0]=='Y')
	{
		Stu[i]=Stu[i+1];
	}
	StudentNum--;
	printf("��Ϣ��ɾ��");
	meanushow();
	menuselection();
}
void ReviseInf()//�޸�ѧ����Ϣ
{
	int No1;
	printf("��������Ҫ���ҵ�ѧ��:"); 
	for(No1=0;No1<StudentNum;No1++)
	{
		if(No1==0)
			break;
	}
	if(No1<StudentNum)         //
	{	
		
		printf("%d \t%s \t %s\n",Stu[No1].No,Stu[No1].Name,Stu[No1].Sex);

	}
	else      //
		printf("δ�ҵ�%d",No1);
	printf("��������ȷ����Ϣ");
	 	printf("������ѧ��:\n");
		scanf("%d",&Stu[No1].No);
		printf("����������:\n");
		scanf("%s",&Stu[No1].Name);
		printf("�������Ա�\n");
		scanf("%s",&Stu[No1].Sex);
		system("cls");
} 
void SortInf()//����ѧ�Ž�������
{
	int i,j,t,StudentNum;
	for(j=1;j<=StudentNum;j++)
		for(i=0;i<=StudentNum-j;i++)
			if(Stu[i].No>Stu[i+1].No)
			{
				t=Stu[i].No;
				Stu[i].No=Stu[i+1].No;
				Stu[i+1].No=t;
			}
 } 
void InfQuerys()//��ѯѧ����Ϣ 
{
	int No1;
	printf("��������Ҫ���ҵ�ѧ��:");
	scanf("%d",&No1);
	for(No1=0;No1<StudentNum;No1++)
	{
		if(No1==0)
			break;
	}
	if(No1<StudentNum)         //
	{	
		
		printf("%d \t%s \t %s\n",Stu[No1].No,Stu[No1].Name,Stu[No1].Sex);

	}
	else      //
		printf("δ�ҵ�%d",No1);
	printf("\n�������\n");
	

}
void AddFinancil()//��ί���� 
{
	system("cls");
	printf("��������Ҫ����Ĳ�����Ϣ����:\n");
	scanf("%d",&FinancialNum);
	do
	{
		printf("����������:\n");
		scanf("%s",&Fin[j].Date);
		strcpy(Fin[j].type,"�Ͻ�");
		printf("��������:\n");
		scanf("%d",&Fin[j].Money);
		printf("�����뱸ע\n");
		scanf("%s",&Fin[j].ps);
		j++;
		system("cls");
	}
	while (j<FinancialNum);
	printf("�������\n");
	printf("�����������Ϊ��\n");
	for(j=0;j<FinancialNum;j++)
	{
		ClassMoney+=Fin[j].Money;
	}
	for(j=0;j<FinancialNum;j++)
	{
		printf("%s %d %s %s\n",Fin[j].Date,Fin[j].Money,Fin[j].type,Fin[j].ps);
	}
	meanushow();
	menuselection();
}
void PayFinancil()// ֧������
{
	int t=j;
	printf("��������Ҫ֧���Ĳ�����Ϣ����:\n");
	scanf("%d",&FinancialNum);
	do
	{
		printf("����������:\n");
		scanf("%s",&Fin[t].Date);
		printf("��������:\n");
		scanf("%d",&Fin[t].Money);
		strcpy(Fin[t].type,"֧��"); 
		printf("�����뱸ע\n");
		scanf("%s",&Fin[t].ps);
		t++;
		ClassMoney-=Fin[t].Money; 
		system("cls");
	}
	while (t<FinancialNum+j);
	printf("�������\n");
	for(t=j;t<FinancialNum+j;t++)
	{
		ClassMoney-=Fin[t].Money;
	}
	printf("�����������Ϊ��\n");
	for(t=j;t<FinancialNum+j;t++)
	{
		printf("%s %d %s %s \n",Fin[t].Date,Fin[t].Money,Fin[t].type,Fin[t].ps);
	}
	Sum=t;
	meanushow();
	menuselection();
}
void FinQuerys()//��ί��ѯ��ϸ�б�
{
	printf("���ʣ���ܽ��Ϊ %d\n",ClassMoney);
	int q;
	for (q=0;q<6;q++)
	{
	printf("%s\t%d\t%s\t%s\n",Fin[q].Date,Fin[q].Money,Fin[q].type,Fin[q].ps);
	}
	meanushow();
	menuselection();
}
void CYAddFinancil()//��Ա���� 
{
	system("cls");
	printf("��������Ҫ����Ĳ�����Ϣ����:\n");
	scanf("%d",&FinancialNum);
	do
	{
		printf("����������:\n");
		scanf("%s",&Fin[j].Date);
		strcpy(Fin[j].type,"�Ͻ�");
		printf("��������:\n");
		scanf("%d",&Fin[j].Money);
		printf("�����뱸ע\n");
		scanf("%s",&Fin[j].ps);
		j++;
		system("cls");
	}
	while (j<FinancialNum);
	printf("�������\n");
	printf("�����������Ϊ��\n");
	for(j=0;j<FinancialNum;j++)
	{
		ClassMoney+=Fin[j].Money;
	}
	for(j=0;j<FinancialNum;j++)
	{
		printf("%s %d %s %s\n",Fin[j].Date,Fin[j].Money,Fin[j].type,Fin[j].ps);
	}
	CYmeanushow();
	CYmenuselection();
}
void CYFinQuerys()//��Ա��ѯ��ϸ�б�
{
	printf("���ʣ���ܽ��Ϊ %d\n",ClassMoney);
	int q;
	for (q=0;q<6;q++)
	{
	printf("%s\t%d\t%s\t%s\n",Fin[q].Date,Fin[q].Money,Fin[q].type,Fin[q].ps);
	}
	CYmeanushow();
	CYmenuselection();
}