//�Ӻ���ѡ��
void cq()//��ǩ
{
	int r;
	char a;
line9:
	
	system("cls");
	side();
	color(2);zuobiao(2,27);printf("���س���������ȡѧ������*�����ء�");
	//���������
	srand(time(NULL));
	r=rand()%n;
	color(2);zuobiao(35,12);printf("�� %s ��� %d ��� %s ͬѧ��̨��\n",studens[r].clas,studens[r].zid,studens[r].name);
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

void qd()//ǩ��������ʱֹͣ��������ǩ�������Զ���1��
{
	side();
	int i,v=0;
	char a;
	
	color(12);zuobiao(2,27);printf("�����밴y��δ�����밴n��");
	char q;
	for(j=0;j<n;j++)
		studens[j].come++;//��ʼ������ǩ������+1
	for(j=0,i=1;j<n,i<n+1;j++,i++)
	{
		
		color(13);zuobiao(49,i);printf("%s",studens[j].name);
		q=getch();
		if(q=='y')
		{
			
			color(2);zuobiao(58,i);printf("�ѵ���");
			v++;
		}
		else if(q=='n')
		{
			color(4);zuobiao(58,i);printf("δ����");
				studens[j].come--;//δ�����˴���-1
		}
		else if(q=='*')
		{
			flag=1;
			return;
		}
		else
		{
			color(12);zuobiao(58,i);printf(" ��ָ�����");
			Sleep(2000);
			zuobiao(58,i);printf("             ");
			i--;
			j--;//��������ǩ��
		}
	}
	k++;
	sj[a-1].qd=k;
	zuobiao(2,27);printf("                              ");
	color(12);zuobiao(2,27);printf("������ϣ����س����ء�");
	printf("Ӧ����%d�ˣ�ʵ����%d��",n,v);

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

void tj()//�����Ϣ
{
	
	for(j=n;j<N;j++,n++)
	{
		system("cls");
		side();
		color(4);zuobiao(2,27);printf("����ѧ��ʱ������*����ɷ��ء�");
		color(2);zuobiao(40,12);printf("�������%d��ѧ������Ϣ��\n",j+1);
		studens[j].id=j+1;
		studens[j].zid=j%5+1;
		color(2);zuobiao(40,13);printf("ѧ�ţ�");
		gets(studens[j].no);
		for(x=0;x<11;x++)
		{
			if(studens[j].no[x]=='*')
				goto line2;
		}
		color(2);zuobiao(40,14);printf("������");
		gets(studens[j].name);
		color(2);zuobiao(40,15);printf("�ձ�");
		gets(studens[j].sex);
		color(2);zuobiao(40,16);printf("�༶��");
		gets(studens[j].clas);
		studens[j].come=0;
	}
line2:
	sj[a-1].rs=n;
	flag=1;

}

void xs()//��ʾѧ����Ϣ
{
	color(4);
	side();
	zuobiao(1,1);
	printf("ѧ����Ϣ���£�\n");
	printf("\n");
	printf("--------------------------------------------�������ķָ���-----------------------------------------\n");
	printf("\n");
	color(0); printf("����          ���           ѧ��          ����          �Ա�          �༶          ǩ������\n");
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
	color(2);zuobiao(2,27);printf("���س�����");
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

void xg()//�޸�ѧ����Ϣ
{
	side();
	int b;
	color(2);zuobiao(2,27);printf("���س�����");
	zuobiao(1,1);printf("������Ҫ�޸ĵ�ѧ�����룺");

	scanf("%d",&b);
	getchar();
	color(2);zuobiao(40,13);printf("ѧ�ţ�");
	gets(studens[b-1].no);
	color(2);zuobiao(40,14);printf("������");
	gets(studens[b-1].name);
	color(2);zuobiao(40,15);printf("�ձ�");
	gets(studens[b-1].sex);
	color(2);zuobiao(40,16);printf("�༶��");
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

void dc()//���������
{
	FILE *fd=fopen("Student.csv","w");
	if(fd==NULL)
	{ 
		printf("�޷������ļ������˳���\n");
		exit(0);
	}
	fprintf(fd,"����,���,ѧ��,����,�Ա�,�༶,ǩ������\n");
	for(j=0;j<n;j++)
		fprintf(fd,"%d,%d,%s,%s,%s,%s,%d\n",studens[j].id,studens[j].zid,studens[j].no,studens[j].name,studens[j].sex,studens[j].clas,studens[j].come);
	fclose(fd);
	zuobiao(40,14);color(5);printf("�����ɹ������س������ء�");
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