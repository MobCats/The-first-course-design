#include<stdio.h>
#include<stdlib.h> 
#include<string.h>
static int StudentNum;
static int ClassMoney;//班费总金额 
static int FinancialNum;
static int j=0;
static int Sum;
struct StuInf
{
	int No;//学号
	char Name[20];//姓名
	char Sex[5];//性别 
}Stu[100],*p;
struct Financial 
{
	char Date[12];//日期 
	int Money;//金额 
	char type[100];//类型
	char ps[100];
}Fin[100],*p1; 
void ViewLoginShow();//菜单选项
int BWLogin();       // 班委登录 
void meanushow(); //显示登录界面
void menuselection();//菜单选项显示
void CYLogin();//班级成员登录
void CYmeanushow();//显示成员登陆界面
void CYmenuselection();//成员登陆菜单显示
void SetInfs();//新建全部成员信息    
void DisplayAll();//显示全部信息 
void InfQuerys();//查询学生信息
void ReviseInf();//修改学生信息
void DelInf();//删除指定学号的学生信息 
void SortInf();//根据学号进行排序 
void AddFinancil();//班委存入班费
void CYAddFinancil();//成员存入班费
void PayFinancil();// 支出财务 
void CYFinQuerys();//成员查询详细列表 
void FinQuerys();//班委查询详细列表
void main()
{
	while(1)
	{   
		ViewLoginShow();
		system("cls");
	}
}
void ViewLoginShow()//显示登陆界面                             退出系统 返回登录 
{
	char ch;
	system("cls");
	printf("\n\n");
	printf("\n\t\t\t+----------------------------------+");
	printf("\n\t\t\t+    欢迎使用班级财务管理系统      +");
	printf("\n\t\t\t+----------------------------------+");
	printf("\n\t\t\t请选择登录方方式： 1.班委登录 2. 班级成员登录\n");
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
		  printf("\n\t\t\t您选择的功能不存在！");
		  break;
	}
}
int BWLogin()	//管理员登录
{
	char name[]="admin",pwd[]="my123";												//正确的和密码
	char username[10],userpwd[10];													//用户输入的用户名和密码
	int count;																		//用户输入用户名和密码的次数
	for(count=1;count<=3;count++)													//给用户三次机会
	{
		printf("\n");
		printf("******请输入用户名:\n");
		scanf("%s",&username);
		printf("******请输入密码:");
		scanf("%s",userpwd);
		if(strcmp(name,username)==0&&strcmp(pwd,userpwd)==0)
			{
				meanushow();
		    	menuselection();
			}																//如果用户名和密码输入正确，则登录成功，返回1
		else																		//如果输入错误则显示错误提示信息，
			if(count<3)																//如果不是第三次，则输出此错误信息
			printf("*******用户名或密码输入错误，请重新输入！！！*******\n");
	}
	printf("******用户名或密码错误已超过3次，系统自动退出！！！******");
	return 0;																		//退出循环时则说明已经超过三次，登陆失败
}
void meanushow()//管理员选择界面 
{
	printf("\n");
	printf("\t**************************\n");
	printf("\t*欢迎使用*\n");
	printf("\t*学校班级班费管理系统*\n");
	printf("\t**************************\n");
	printf("\t*1:创建班级成员信息*\n");
	printf("\t*2:删除指定学号的学生信息  *\n");
	printf("\t*3:查询学生信息*\n");
	printf("\t*4:显示全部成员信息*\n");
	printf("\t*5:修改学生信息*\n");
	printf("\t*6:增添（收入）财务信息*\n");
	printf("\t*7:支出财务*\n"); 
	printf("\t*8:查询详细列表 *\n");
	printf("\t*9:退出系统*\n");
}
void menuselection()//管理员选择界面菜单 
{
	int a;
	printf("请输入你的选择(1﹣9):");
	scanf("%d",&a);
	switch(a)
	{
		case 1: SetInfs();break;	//创建班级成员信息
		case 2: DelInf();break;//删除信息 
		case 3: InfQuerys();break;	//查询学生信息
		case 4: DisplayAll();break;//显示全部成员信息
		case 5: ReviseInf() ;break;	//修改学生信息
		case 6: AddFinancil();break;//增添（收入）财务信息 
		case 7:	PayFinancil();break;// 支出财务 
		case 8: FinQuerys();break;//查询详细列表 
		case 9: system("pause");break;		//退出系统
		default:printf("%d,请输入1-9之间的数字\n",a);
	}
}
void CYLogin()	//普通用户登录
{
	char name[]="cxy",pwd[]="666";												//正确的和密码
	char username[10],userpwd[10];													//用户输入的用户名和密码
	int count;																		//用户输入用户名和密码的次数
	for(count=1;count<=3;count++)													//给用户三次机会
	{
		printf("\n");
		printf("******请输入用户名:");
		scanf("%s",username);
		printf("******请输入密码:");
		scanf("%s",userpwd);
		if(strcmp(name,username)==0&&strcmp(pwd,userpwd)==0)
			{
				CYmeanushow();
		    	CYmenuselection();
			}//如果用户名和密码输入正确，则登录成功返回1
		else																		//如果输入错误则显示错误提示信息，
			if(count<3)																//如果不是第三次，则输出此错误信息
			printf("*******用户名或密码输入错误，请重新输入！！！*******\n");
	}
	printf("******用户名或密码错误已超过3次，系统自动退出！！！******");																//退出循环时则说明已经超过三次，登陆失败
}
void CYmeanushow()//成员选择界面 
{
	printf("\n");
	printf("\t**************************\n");
	printf("\t*欢迎使用*\n");
	printf("\t*学校班级班费管理系统*\n");
	printf("\t**************************\n");
	printf("\t*1:上交班费*\n");
	printf("\t*2:查询学生信息*\n");
	printf("\t*3:查询详细列表*\n");
	printf("\t*4:退出系统*\n"); 
}
void CYmenuselection()//成员选择界面菜单 
{
	int a;
	printf("请输入你的选择(1﹣):");
	scanf("%d",&a);
	switch(a)
	{
		case 1: CYAddFinancil();break;		    //上交班费
		case 2: InfQuerys();break;			//查询学生信息 
		case 3: FinQuerys();break;			//查询详细列表
		case 4: system("pause");break;			//退出系统
	
		default:printf("%d,请输入1-9之间的数字\n",a);
	
	}
	CYmeanushow();
	CYmenuselection();
}
void SetInfs()//输入班级成员信息 
{ 
	system("cls");
	FILE *fp;
	char ch;
	int i=0;
	p=Stu;
	if((fp=fopen("stu.txt","w+"))==NULL)
	{
		printf("文件打开失败！\n");
		exit(0);
	}
		printf("请输入你要新建学生人数:\n");
	scanf("%d",&StudentNum);
	do
	{
		printf("请输入学号:\n");
		scanf("%d",&p->No);
		printf("请输入姓名:\n");
		scanf("%s",&p->Name);
		printf("请输入性别\n");
		scanf("%s",&p->Sex);
		i++;p++;
		system("cls");
	}
	while (i<StudentNum);
	printf("输入完毕\n");
	p=Stu;
	for(i=0;i<StudentNum;i++,p++)
	{
		fprintf(fp,"%d %s %s \n",p->No,p->Name,p->Sex);
	}
	printf("读出文件内容为：\n");
	p=Stu;
	for(i=0;i<StudentNum;i++,p++)
	{
		printf("%d\t %s\t %s\t \n",p->No,p->Name,p->Sex);
	}
	fclose(fp);
	meanushow();
	menuselection();
}
void DisplayAll()//显示全部信息 
{
	system("cls");
	SortInf();
	int i;
	for(i=0;i<StudentNum;i++)
	{
		printf("%-8d %-12s %-6d %-12s %-6d",Stu[i].No,Stu[i].Name,Stu[i].Sex);
	}
}
void DelInf()//删除指定学号的学生信息 
{
	char ok[5];//确定是否要真删除
	int i,j;
	printf("请输入你要删除的学生学号:");
	scanf("%d",&p->No);
	printf("你是否要删除这条信息?(y/n)\n");
	scanf("%d",ok);
	if(ok[0]=='y'||ok[0]=='Y')
	{
		Stu[i]=Stu[i+1];
	}
	StudentNum--;
	printf("信息已删除");
	meanushow();
	menuselection();
}
void ReviseInf()//修改学生信息
{
	int No1;
	printf("请输入你要查找的学号:"); 
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
		printf("未找到%d",No1);
	printf("请填入正确的信息");
	 	printf("请输入学号:\n");
		scanf("%d",&Stu[No1].No);
		printf("请输入姓名:\n");
		scanf("%s",&Stu[No1].Name);
		printf("请输入性别\n");
		scanf("%s",&Stu[No1].Sex);
		system("cls");
} 
void SortInf()//根据学号进行排序
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
void InfQuerys()//查询学生信息 
{
	int No1;
	printf("请输入你要查找的学号:");
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
		printf("未找到%d",No1);
	printf("\n查找完毕\n");
	

}
void AddFinancil()//班委存入 
{
	system("cls");
	printf("请输入你要存入的财务信息个数:\n");
	scanf("%d",&FinancialNum);
	do
	{
		printf("请输入日期:\n");
		scanf("%s",&Fin[j].Date);
		strcpy(Fin[j].type,"上交");
		printf("请输入金额:\n");
		scanf("%d",&Fin[j].Money);
		printf("请输入备注\n");
		scanf("%s",&Fin[j].ps);
		j++;
		system("cls");
	}
	while (j<FinancialNum);
	printf("输入完毕\n");
	printf("你输入的内容为：\n");
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
void PayFinancil()// 支出财务
{
	int t=j;
	printf("请输入你要支出的财务信息个数:\n");
	scanf("%d",&FinancialNum);
	do
	{
		printf("请输入日期:\n");
		scanf("%s",&Fin[t].Date);
		printf("请输入金额:\n");
		scanf("%d",&Fin[t].Money);
		strcpy(Fin[t].type,"支出"); 
		printf("请输入备注\n");
		scanf("%s",&Fin[t].ps);
		t++;
		ClassMoney-=Fin[t].Money; 
		system("cls");
	}
	while (t<FinancialNum+j);
	printf("输入完毕\n");
	for(t=j;t<FinancialNum+j;t++)
	{
		ClassMoney-=Fin[t].Money;
	}
	printf("你输入的内容为：\n");
	for(t=j;t<FinancialNum+j;t++)
	{
		printf("%s %d %s %s \n",Fin[t].Date,Fin[t].Money,Fin[t].type,Fin[t].ps);
	}
	Sum=t;
	meanushow();
	menuselection();
}
void FinQuerys()//班委查询详细列表
{
	printf("班费剩余总金额为 %d\n",ClassMoney);
	int q;
	for (q=0;q<6;q++)
	{
	printf("%s\t%d\t%s\t%s\n",Fin[q].Date,Fin[q].Money,Fin[q].type,Fin[q].ps);
	}
	meanushow();
	menuselection();
}
void CYAddFinancil()//成员存入 
{
	system("cls");
	printf("请输入你要存入的财务信息个数:\n");
	scanf("%d",&FinancialNum);
	do
	{
		printf("请输入日期:\n");
		scanf("%s",&Fin[j].Date);
		strcpy(Fin[j].type,"上交");
		printf("请输入金额:\n");
		scanf("%d",&Fin[j].Money);
		printf("请输入备注\n");
		scanf("%s",&Fin[j].ps);
		j++;
		system("cls");
	}
	while (j<FinancialNum);
	printf("输入完毕\n");
	printf("你输入的内容为：\n");
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
void CYFinQuerys()//成员查询详细列表
{
	printf("班费剩余总金额为 %d\n",ClassMoney);
	int q;
	for (q=0;q<6;q++)
	{
	printf("%s\t%d\t%s\t%s\n",Fin[q].Date,Fin[q].Money,Fin[q].type,Fin[q].ps);
	}
	CYmeanushow();
	CYmenuselection();
}