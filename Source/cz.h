#include"du.h"
void cz()  //������ģ��Ͽ�
{
	char c;
	
	fp=fopen("data.dat","r");   //����༶�б�
	if(fp==NULL)
	{
		color(4);
		zuobiao(44,15);
		printf("���ݼ��ش������˳��������⡣\n");
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
	zuobiao(40,18); printf("��ѡ�񱾽ڿ����̵İ༶��\n");//ѡ��༶��ʼ�ϿΣ�������ѡ��ͬ���ļ����ж�д������
	for(j=0;j<m;j++)
		printf("%d��%s         ",sj[j].id,sj[j].name);
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
		printf("�Ҳ����ļ���������ѡ��");
		goto line1;
	}
	n=sj[a-1].rs;//���뱾������
	k=sj[a-1].qd;//����ǩ������
	fi=fopen(fnt,"r");
	for(j=0;j<n;j++)
		fscanf(fi,"%d %d %s %s %s %s %d",&studens[j].id,&studens[j].zid,studens[j].no,studens[j].name,studens[j].sex,studens[j].clas,&studens[j].come);
	fclose(fi);
line9:
		system("cls");
		face();
		color(2);
		zuobiao(40,18);printf("�������ţ�");//�Ӵ���
		zuobiao(46,19);printf("1��ǩ��");
		zuobiao(46,20);printf("2����ǩ");
		zuobiao(46,21);printf("3����ʾ");
		zuobiao(46,22);printf("4�����");
		zuobiao(46,23);printf("5���޸�");
		zuobiao(46,24);printf("6������");
		zuobiao(46,25);printf("�������������\n");
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
		fi=fopen(fnt,"w");//���޸ĺ����Ϣ���µ����ļ�
		if(fi==NULL)
		{ 
			printf("���ݼ��ش������˳��������⡣\n");
			exit(0);
		}
		for(j=0;j<n;j++)
			fprintf(fi,"%d %d %s %s %s %s %d\n",studens[j].id,studens[j].zid,studens[j].no,studens[j].name,studens[j].sex,studens[j].clas,studens[j].come);
		fclose(fi);
		fp=fopen("data.dat","w");
		if(fp==NULL)
		{ 
			printf("���ݼ��ش������˳��������⡣\n");
			exit(0);
		}
		for(j=0;j<m;j++)
			fprintf(fp,"%d %s %d %d\n",sj[j].id,sj[j].name,sj[j].rs,sj[j].qd);
		fclose(fp);	
	}
	while(1);
}