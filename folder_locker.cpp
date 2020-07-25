// folder_locker.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <string.h>
#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <fstream>
#include <windows.h>

using namespace std;

// Functions Declaration
void Lock();
void Unlock();
string getpass();

int main() {
	char choice;
	cout <<endl<< "Welcome to Folder Locker:....." << endl;
	while (1) {
		cout << "Enter your Choice of action" << endl << "1: Lock" << endl << "2: Unlock" << endl << "3: Exit " << endl;
		cout << ">>";
		choice = _getch();
		cout << choice << endl;
		if (choice == '1')
		{
			Lock();
		}
		else if (choice == '2')
		{
			string pass = "";
			cout << endl << "Enter your Password: ";
			pass = getpass();
			while (pass != "1972")
			{
				cout << endl << "Password is incorrect" << endl;
				cout << " Try Again!!!" << endl;
				cout << "Enter your Password: ";
				pass = getpass();
			}
			if (pass == "1972")
			{
				Unlock();
			}
			
		}
		else if (choice == '3')
		{
			break;
		}
		else 
		{
			cout << endl << "Invalid Choice"<<endl;
		}
	}
	return 0;
}

void Lock() {
	char pass[15] = "";
	ofstream lfolder;
	char folder[200] = { 0 };
	char tempfolder[200] = { '0' };
	char attributes[50] = { '0' };

	cout << "\nEnter the complete path to the Folder: ";
	cin >> folder;

	strcpy_s(tempfolder, folder);

	strcat_s(folder, "\\Desktop.ini");

	lfolder.open(folder, ios::out);

	lfolder << "[.shellClassInfo]" << endl;
	lfolder << "CLSID = {63E23168-BFF7-4E87-A246-EF024425E4EC}" << endl;

	lfolder.close();

	strcpy_s(attributes, "attrib +h +s ");
	strcat_s(attributes, tempfolder);

	WinExec(attributes, NULL);

	lfolder.open("C:\\windows\\db.dat", ios::app);
	lfolder << "Folder Locked: " << tempfolder << endl;
	lfolder.close();

	cout << "\n\n" << tempfolder << " has been locked successfully!\n";
}

void Unlock() {
	char folder[255];
	char tempfolder[255];
	char attributes[50];
	char del[50];
	ofstream lfolder;

	cout << "\nEnter the complete path to the Folder: ";
	cin >> folder;

	strcpy_s(tempfolder, folder);

	strcat_s(folder, "\\Desktop.ini");

	strcpy_s(del, "del ");
	strcat_s(del, folder);
	system(del);

	strcpy_s(attributes, "attrib -h -s ");
	strcat_s(attributes, tempfolder);

	WinExec(attributes, NULL);

	lfolder.open("C:\\windows\\db.dat", ios::app);
	lfolder << "! Folder Unlocked: " << tempfolder << endl;
	lfolder.close();

	cout << "\n\n" << tempfolder << " has been unlocked successfully!\n";
}

string getpass() {
	string pass = "";
	char ch;
	ch = _getch();
	while (ch != 13) {
		if (ch != 8) {
			pass.push_back(ch);
			cout << "*";
		}
		else if (pass.size() > 0) {
			pass.pop_back();
			cout << "\b \b";
		}
		ch = _getch();
	}
	return pass;
}