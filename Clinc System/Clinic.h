#pragma once
#include<fstream>
#include<iostream>
#include<conio.h>
#include<iomanip>
#include<string.h>
using namespace std;


class Adress
{
public:
	char city[10];
	int streaNo;
};
class Data
{
public:
	int Day;
	int Month;
	int Year;
};
class person : public Adress
{
	char Name[25];
	char phone[12];
	char Email[50];
public:
	void setName()
	{
		cout << "Enter your name : ";
		cin.getline(Name, 25);
	}
	void setPhone()
	{
		cout << "Enter your Phone : ";
		cin.getline(phone, 25);
	}
	void setmail()
	{
		cout << "Enter your Email : ";
		cin.getline(Email, 25);
	}


	char* getName()
	{
		return Name;
	}
	char* getPhone()
	{
		return phone;
	}
	char* getmail()
	{
		return Email;
	}

	virtual void setData() {};
	virtual bool login() { return 0; };
};

class Patient : public Data, public person
{
public:
	char ID[17];
	float balance;
	char State[100];

	void setData();
	bool login();
	void showstatu(char id[]);

};

class Doc : public person
{
public:
	char Dgree[20];
	char user[20];
	char pass[20];

	void setData();
	void showAllPatients();
	void upDateStatus();
	void showAllStatus();
	void DeletPatient();
	bool login();
};
