





/*��ɫ��Ӧֵ�� 
����0=��ɫ                8=��ɫ����
�� 1=��ɫ                9=����ɫ                ����                        
����2=��ɫ                10=����ɫ       0xa        ����
����3=����ɫ			11=��ǳ��ɫ        0xb��
����4=��ɫ                12=����ɫ        0xc����
����5=��ɫ                13=����ɫ        0xd        ����
����6=��ɫ                14=����ɫ        0xe        ����
����7=��ɫ                15=����ɫ        0xf 
����Ҳ���԰���Щֵ���óɳ�����
*/
void color(const unsigned short color1)
{			/*���޸ı�0-15����ɫ;�����0-15��ôʵ��������ɫ   ��Ϊ�������15����ĸı�����ı�����ɫ��*/
	if(color1>=0&&color1<=15)
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color1|BACKGROUND_BLUE|BACKGROUND_RED|BACKGROUND_GREEN|BACKGROUND_INTENSITY );
	/*�������0-15�ķ�Χ��ɫ����ô��ΪĬ�ϵ���ɫ��ɫ��*/
    else
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}




void zuobiao(int x, int y) //��λ����y�еĵ�x��
{
	HANDLE hOutput;
	COORD loc;
	loc.X=x;
	loc.Y=y;
	hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOutput, loc);
	return;
}


void side()/*��ӡ����߽�*/
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