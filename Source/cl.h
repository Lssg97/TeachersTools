void cl()//清理多余信息
{
	struct Data sj2[20];//临时存储
	fp=fopen("data.dat","r");//读班级列表
	if(fp==NULL)
	{ 
		printf("数据加载错误！请退出查找问题。\n");
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

	color(2);zuobiao(35,2);printf("请输入保留班级个数：");
	scanf("%d",&i);
	color(2);zuobiao(35,4);printf("请选择要保留的班级序号（序号间用空格隔开）：\n");
	for(j=0;j<n;j++)
		printf("%d：%s\n",sj[j].id,sj[j].name);
	for(j=0;j<i;j++)//将选择班级导入临时存储
	{
		scanf("%d",&a);
		sj2[j].id=j+1,sj2[j].rs=sj[a-1].rs,sj2[j].qd=sj[a-1].qd;
		strcpy(sj2[j].name,sj[a-1].name);
	}
	fp=fopen("data.dat","w");
	if(fp==NULL)
	{ 
		printf("数据加载错误！请退出查找问题。\n");
		exit(0);
	}
	for(j=0;j<i;j++)//将临时存储导回文件
		fprintf(fp,"%d %s %d %d\n",j+1,sj2[j].name,sj2[j].rs,sj2[j].qd);
	fclose(fp);
	printf("已删除完毕，请重新进入以更新。");
	exit(1);
}