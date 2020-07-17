#include <iostream>
#include <cstdio>
#include <windows.h>
#include <TlHelp32.h>
#include <tchar.h>

using namespace std;
HWND okno = NULL;



int wlaczMody()
{
	char oldname[] = "mody.ini";
	
	char newname[] = "C:\\Users\\kfius\\OneDrive\\Dokumenty\\My games\\Fallout 76\\Fallout76Custom.ini";
	
	if (!CopyFileA(oldname, newname, FALSE))
	{
		cout << "Blad Przenoszenia Pliku : " << GetLastError() << endl;

	}

	else
	{
		cout << "Mody Wlaczone" << endl;
	}
	return 0;
}

int wylaczMody()
{

	char oldname[] = "czysty.ini";
	char newname[] = "C:\\Users\\kfius\\OneDrive\\Dokumenty\\My games\\Fallout 76\\Fallout76Custom.ini";


	if (!CopyFileA(oldname, newname, FALSE))
	{
		cout << "Blad Przenoszenia Pliku : " << GetLastError() <<endl;
	
	}
	else
	{
		cout << "Mody Wylaczone" << endl;
	}

	return 0;

	
}


bool SingleKeyToggle(DWORD KeyCode, bool* KeyToggle)
{
	if (GetAsyncKeyState(KeyCode))
	{
		if (!*KeyToggle)
		{
			*KeyToggle = true;
			return true;
		}
	}
	else
	{
		if (*KeyToggle)
		{
			*KeyToggle = false;
			return false;
		}
	}

	return false;
}

bool DoubleKeyToggle(DWORD KeyCodeA, DWORD KeyCodeB, bool* KeyToggle)
{
	if (GetAsyncKeyState(KeyCodeA))
	{
		return SingleKeyToggle(KeyCodeB, KeyToggle);
	}

	if (GetAsyncKeyState(KeyCodeB))
	{
		return SingleKeyToggle(KeyCodeA, KeyToggle);
	}

	return false;
}

bool sprawdz(HWND ok, char* nazwa)
{
	if(ok) 
	{
		cout << "Wylacz " << nazwa << " aby kontynowac.\nZamykam."<< endl;
		
		cin.get();
		return true;
	}
	return false;
}

int main()

{

	bool OneKeyToggle = false;
	bool TwoKeyToggle = false;
	bool ThreeKeyToggle = false;
	char nazwaOkna[] = "Fallout76";
	okno = FindWindowA(0, (LPCSTR)(nazwaOkna)); // nazwa okna

	cout << "1. Wylacz mody" << endl;
	cout << "2. Wlacz mody" << endl;
	cout << "END. aby zakonczyc" << endl;
	if (sprawdz(okno, nazwaOkna))
	{
		return 0;
	}
	
	while (!GetAsyncKeyState(VK_END))
	{





		if (DoubleKeyToggle(VK_SHIFT, '1', &ThreeKeyToggle))
		{
			wylaczMody();

			Sleep(666);

		}
		if (DoubleKeyToggle(VK_SHIFT, '2', &ThreeKeyToggle))
		{
			wlaczMody();

			Sleep(666);

		}
	}
	cout << "Wylaczam" << endl;
	cin.get();
	return 0;
}
