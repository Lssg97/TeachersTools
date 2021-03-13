//子函数选项
void cq()//抽签
{
	int r;
	char a;
line9:
	
	system("cls");
	side();
	color(2);zuobiao(2,27);printf("按回车键继续抽取学生，按*键返回。");
	//产生随机数
	srand(time(NULL));
	r=rand()%n;
	color(2);zuobiao(35,12);printf("请 %s 班第 %d 组的 %s 同学上台。\n",studens[r].clas,studens[r].zid,studens[r].name);
	line3:
		a=getch();
		if(a=='\r')
			goto line9;
		else if(a=='*')
		{
			flag=1;
			return;
		}
		else
			goto line3;
}

void qd()//签到（可随时停止，其余人签到次数自动加1）
{
	side();
	int i,v=0;
	char a;
	
	color(12);zuobiao(2,27);printf("到者请按y，未到者请按n！");
	char q;
	for(j=0;j<n;j++)
		studens[j].come++;//开始所有人签到次数+1
	for(j=0,i=1;j<n,i<n+1;j++,i++)
	{
		
		color(13);zuobiao(49,i);printf("%s",studens[j].name);
		q=getch();
		if(q=='y')
		{
			
			color(2);zuobiao(58,i);printf("已到！");
			v++;
		}
		else if(q=='n')
		{
			color(4);zuobiao(58,i);printf("未到！");
				studens[j].come--;//未到的人次数-1
		}
		else if(q=='*')
		{
			flag=1;
			return;
		}
		else
		{
			color(12);zuobiao(58,i);printf(" 非指定命令！");
			Sleep(2000);
			zuobiao(58,i);printf("             ");
			i--;
			j--;//此人重新签到
		}
	}
	k++;
	sj[a-1].qd=k;
	zuobiao(2,27);printf("                              ");
	color(12);zuobiao(2,27);printf("点名完毕！按回车返回。");
	printf("应出勤%d人，实出勤%d人",n,v);

line3:
	a=getch();
	if(a=='\r')
	{
		flag=1;
		return;
	}
	else
		goto line3;
}

void tj()//添加信息
{
	
	for(j=n;j<N;j++,n++)
	{
		system("cls");
		side();
		color(4);zuobiao(2,27);printf("输入学号时若输入*，则可返回。");
		color(2);zuobiao(40,12);printf("请输入第%d名学生的信息：\n",j+1);
		studens[j].id=j+1;
		studens[j].zid=j%5+1;
		color(2);zuobiao(40,13);printf("学号：");
		gets(studens[j].no);
		for(x=0;x<11;x++)
		{
			if(studens[j].no[x]=='*')
				goto line2;
		}
		color(2);zuobiao(40,14);printf("姓名：");
		gets(studens[j].name);
		color(2);zuobiao(40,15);printf("姓别：");
		gets(studens[j].sex);
		color(2);zuobiao(40,16);printf("班级：");
		gets(studens[j].clas);
		studens[j].come=0;
	}
line2:
	sj[a-1].rs=n;
	flag=1;

}

void xs()//显示学生信息
{
	color(4);
	side();
	zuobiao(1,1);
	printf("学生信息如下：\n");
	printf("\n");
	printf("--------------------------------------------华丽丽的分割线-----------------------------------------\n");
	printf("\n");
	color(0); printf("代码          组号           学号          姓名          性别          班级          签到次数\n");
	for(j=0;j<n;j++)
	{
	color(10);
	zuobiao(2,j+6);	printf("%d",studens[j].id);
	zuobiao(16,j+6);  printf("%d",studens[j].zid); 
	zuobiao(30,j+6);	printf("%s",studens[j].no);
	zuobiao(44,j+6);	printf("%s",studens[j].name);
	zuobiao(58,j+6);	printf("%s",studens[j].sex);
	zuobiao(72,j+6);	printf("%s",studens[j].clas);
	zuobiao(86,j+6);	printf("%d",studens[j].come);
	}
	color(2);zuobiao(2,27);printf("按回车返回");
	line3:
	a=getch();
	if(a=='\r')
	{
		flag=1;
		return;
	}
	else
		goto line3;

}

void xg()//修改学生信息
{
	side();
	int b;
	color(2);zuobiao(2,27);printf("按回车返回");
	zuobiao(1,1);printf("请输入要修改的学生代码：");

	scanf("%d",&b);
	getchar();
	color(2);zuobiao(40,13);printf("学号：");
	gets(studens[b-1].no);
	color(2);zuobiao(40,14);printf("姓名：");
	gets(studens[b-1].name);
	color(2);zuobiao(40,15);printf("姓别：");
	gets(studens[b-1].sex);
	color(2);zuobiao(40,16);printf("班级：");
	gets(studens[b-1].clas);

	
	line3:
	a=getch();
	if(a=='\r')
	{
		flag=1;
		return;
	}
	else
		goto line3;
}

void dc()//导出到表格
{
	FILE *fd=fopen("Student.csv","w");
	if(fd==NULL)
	{ 
		printf("无法创建文件！请退出。\n");
		exit(0);
	}
	fprintf(fd,"代码,组号,学号,姓名,性别,班级,签到次数\n");
	for(j=0;j<n;j++)
		fprintf(fd,"%d,%d,%s,%s,%s,%s,%d\n",studens[j].id,studens[j].zid,studens[j].no,studens[j].name,studens[j].sex,studens[j].clas,studens[j].come);
	fclose(fd);
	zuobiao(40,14);color(5);printf("创建成功！按回车键返回。");
	line3:
	a=getch();
	if(a=='\r')
	{
		flag=1;
		return;
	}
	else
		goto line3;
}