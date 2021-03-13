





/*颜色对应值： 
　　0=黑色                8=灰色　　
　 1=蓝色                9=淡蓝色                　　                        
　　2=绿色                10=淡绿色       0xa        　　
　　3=湖蓝色			11=淡浅绿色        0xb　
　　4=红色                12=淡红色        0xc　　
　　5=紫色                13=淡紫色        0xd        　　
　　6=黄色                14=淡黄色        0xe        　　
　　7=白色                15=亮白色        0xf 
　　也可以吧这些值设置成常量。
*/
void color(const unsigned short color1)
{			/*仅限改变0-15的颜色;如果在0-15那么实现他的颜色   因为如果超过15后面的改变的是文本背景色。*/
	if(color1>=0&&color1<=15)
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color1|BACKGROUND_BLUE|BACKGROUND_RED|BACKGROUND_GREEN|BACKGROUND_INTENSITY );
	/*如果不在0-15的范围颜色，那么改为默认的颜色白色；*/
    else
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}




void zuobiao(int x, int y) //定位到第y行的第x列
{
	HANDLE hOutput;
	COORD loc;
	loc.X=x;
	loc.Y=y;
	hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOutput, loc);
	return;
}


void side()/*打印界面边界*/
{
	int i,j;
	for(i=0;i<100;i++)
		{
			color(12);
			zuobiao(i,1);
			printf("*");
		}

	for(i=0;i<100;i++)
		{
			color(12);
			zuobiao(i,29);
			printf("*");
		}
	for(i=0;i<100;i++)
	{
		color(12);
		zuobiao(i,26);
		printf("*");
	}
}


void face()
{
	color(12);
	zuobiao(5,3);  printf("******************************************************************************************");
	zuobiao(5,4);  printf("*                                                                                        *");
	zuobiao(5,5);  printf("*  ***** ****   **      ***  *   * **** ****  **  ***      *****  ***   ***  *     ***   *");
	zuobiao(5,6);  printf("*    *   *     *  *    *   * *   * *    *   * ** *   *       *   *   * *   * *    *   *  *");
	zuobiao(5,7);  printf("*    *   *    *    *  *      *   * *    *   *    *           *   *   * *   * *    *      *");
	zuobiao(5,8);  printf("*    *   *    *    * *       *   * *    *  *      *          *   *   * *   * *     *     *");
	zuobiao(5,9);  printf("*    *   **** ****** *       ***** **** ***        *         *   *   * *   * *      *    *");
	zuobiao(5,10); printf("*    *   *    *    * *       *   * *    *  *        *        *   *   * *   * *       *   *");
	zuobiao(5,11); printf("*    *   *    *    * *     * *   * *    *   *        *       *   *   * *   * *        *  *");
	zuobiao(5,12); printf("*    *   *    *    *  *   *  *   * *    *    *   *   *       *   *   * *   * *    *   *  *");
	zuobiao(5,13); printf("*    *   **** *    *   ***   *   * **** *    *    ***        *    ***   ***  ****  ***   *");
	zuobiao(5,14); printf("*                                                                                        *");
	zuobiao(5,15); printf("******************************************************************************************");

}