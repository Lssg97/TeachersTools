void cl()//���������Ϣ
{
	struct Data sj2[20];//��ʱ�洢
	fp=fopen("data.dat","r");//���༶�б�
	if(fp==NULL)
	{ 
		printf("���ݼ��ش������˳��������⡣\n");
		exit(0);
	}
	for(j=0;j<20;j++)
	{
		n++;
		fscanf(fp,"%d %s %d %d",&sj[j].id,sj[j].name,&sj[j].rs,&sj[j].qd);
		if(sj[j].id!=n)
		{
			n--;
			break;
		}
	}
	fclose(fp);

	side();

	color(2);zuobiao(35,2);printf("�����뱣���༶������");
	scanf("%d",&i);
	color(2);zuobiao(35,4);printf("��ѡ��Ҫ�����İ༶��ţ���ż��ÿո��������\n");
	for(j=0;j<n;j++)
		printf("%d��%s\n",sj[j].id,sj[j].name);
	for(j=0;j<i;j++)//��ѡ��༶������ʱ�洢
	{
		scanf("%d",&a);
		sj2[j].id=j+1,sj2[j].rs=sj[a-1].rs,sj2[j].qd=sj[a-1].qd;
		strcpy(sj2[j].name,sj[a-1].name);
	}
	fp=fopen("data.dat","w");
	if(fp==NULL)
	{ 
		printf("���ݼ��ش������˳��������⡣\n");
		exit(0);
	}
	for(j=0;j<i;j++)//����ʱ�洢�����ļ�
		fprintf(fp,"%d %s %d %d\n",j+1,sj2[j].name,sj2[j].rs,sj2[j].qd);
	fclose(fp);
	printf("��ɾ����ϣ������½����Ը��¡�");
	exit(1);
}