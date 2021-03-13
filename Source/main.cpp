#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#include<string.h>
#include<windows.h>
#include<io.h>


//定义变量
#define N 200
int j,n,m,a,x,k,i,flag=0;
char fn[100],fnt[100];
FILE *fp,*fi;
struct Data
{
	int id;
	char name[100];
	int rs;
	int qd;
};struct Data sj[20];
struct Student
{
	int id;
	int zid;
	char no[11];
	char name[20];
	char sex[3];
	char clas[30];
	int come;
};struct Student studens[N];
#include"tools.h"
#include"cz.h"
#include"xr.h"
#include"cl.h"

void main()
{//主菜单选择
	do
	{
	char z;
	
	system("mode con cols=100 lines=30");
	system("color f7");
	face();
	  color(2);
	  zuobiao(40,18); printf("  1:  上课");
	  zuobiao(40,19); printf("  2:  写入新名单");
	  zuobiao(40,20); printf("  3:  清理班级");
	  zuobiao(40,21); printf("  0:  退出");
	  
		z=getch();
		system("cls");
		switch(z)
		{
		case '1':cz();break;
		case '2':xr();break;
		case '3':cl();break;
		case '0':exit(1);break;

		}
		
		  system("cls");
	}
	while(1);
}