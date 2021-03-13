#include"du.h"
void cz()  //程序核心，上课
{
	char c;
	
	fp=fopen("data.dat","r");   //导入班级列表
	if(fp==NULL)
	{
		color(4);
		zuobiao(44,15);
		printf("数据加载错误！请退出查找问题。\n");
		Sleep(3000);
		exit(0);
	}
	for(j=0,m=0;j<20;j++)
	{
		m++;
		fscanf(fp,"%d %s %d %d",&sj[j].id,sj[j].name,&sj[j].rs,&sj[j].qd);
		if(sj[j].id!=m)
		{
			m--;
			break;
		}
	}
	fclose(fp);
	do
	{
	if(flag==1)
	{
		flag=0;
		goto line9;
	}
	face();
	color(2);
	zuobiao(40,18); printf("请选择本节课所教的班级：\n");//选择班级开始上课（本质是选择不同的文件进行读写操作）
	for(j=0;j<m;j++)
		printf("%d：%s         ",sj[j].id,sj[j].name);
line1:
	scanf("%d",&a);
	getchar();
	if(a>0&&a<=m)
	{
		strcpy(fnt,sj[a-1].name);
		strcat(fnt,".txt");
	}
	else
	{
		printf("找不到文件，请重新选择：");
		goto line1;
	}
	n=sj[a-1].rs;//导入本班人数
	k=sj[a-1].qd;//导入签到次数
	fi=fopen(fnt,"r");
	for(j=0;j<n;j++)
		fscanf(fi,"%d %d %s %s %s %s %d",&studens[j].id,&studens[j].zid,studens[j].no,studens[j].name,studens[j].sex,studens[j].clas,&studens[j].come);
	fclose(fi);
line9:
		system("cls");
		face();
		color(2);
		zuobiao(40,18);printf("请输入编号：");//子代码
		zuobiao(46,19);printf("1：签到");
		zuobiao(46,20);printf("2：抽签");
		zuobiao(46,21);printf("3：显示");
		zuobiao(46,22);printf("4：添加");
		zuobiao(46,23);printf("5：修改");
		zuobiao(46,24);printf("6：导出");
		zuobiao(46,25);printf("其余任意键返回\n");
		c=getch();
		system("cls");
		if(c=='1')
			qd();
		else if(c=='2')
			cq();
		else if(c=='3')
			xs();
		else if(c=='4')
			tj();
		else if(c=='5')
			xg();
		else if(c=='6')
			dc();
		else
			return;
		system("cls");
		fi=fopen(fnt,"w");//将修改后的信息重新导回文件
		if(fi==NULL)
		{ 
			printf("数据加载错误！请退出查找问题。\n");
			exit(0);
		}
		for(j=0;j<n;j++)
			fprintf(fi,"%d %d %s %s %s %s %d\n",studens[j].id,studens[j].zid,studens[j].no,studens[j].name,studens[j].sex,studens[j].clas,studens[j].come);
		fclose(fi);
		fp=fopen("data.dat","w");
		if(fp==NULL)
		{ 
			printf("数据加载错误！请退出查找问题。\n");
			exit(0);
		}
		for(j=0;j<m;j++)
			fprintf(fp,"%d %s %d %d\n",sj[j].id,sj[j].name,sj[j].rs,sj[j].qd);
		fclose(fp);	
	}
	while(1);
}