#include"Clinic.h"
void main()
{
	person* ptr;	Doc doc;	Patient patient;
	int ch;
	char idd[17];
	system("color 05");
	cout << "\t\t\t\t|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n";
	cout << "\t\t\t\t|                WELCOME TO MY CLINIC                       |\n";
	cout << "\t\t\t\t|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n\n\n";
	cout << "\t\t\t\t\t\t 1- Doctor\n\t\t\t\t\t\t 2- Patient\n\nEnter your chose (1-2) : ";
	cin >> ch;
	system("color 7");
	switch (ch)
	{
	case 1:
		ptr = &doc;
		system("cls");
		cout << "\t\t\t\t 1- login\n\t\t\t\t 2- Add\n\nEnter your chose (1-2) : ";
		cin >> ch;
		if (ch == 1)
		{
			system("cls");
			if (ptr->login())
			{
				system("cls");
				doc.showAllPatients();
				cout << "\n\n\t\t\t\t\t\t\t\t 1- Show All Patient Statu\n\t\t\t\t\t\t\t\t 2- Delet Patient\n\nEnter your chose (1-2) : ";
				cin >> ch;

				if (ch == 1)
				{
					system("cls");
					doc.showAllStatus();
					cout << "\n\nTo UpDate Statu Of Patient Pless Enter (1) of Patient thit you want to update it : ";
					cin >> ch;
					if (ch == 1)
					{
						cout << "\n\n";
						doc.upDateStatus();
					}
					else
					{
						exit(0);
					}
				}
				else if (ch == 2)
				{
					system("cls");
					doc.DeletPatient();
				}
				else
				{
					cout << "Enter correct number " << endl;
				}
			}
			else
			{
				cout << "Enter correct usrt name or password " << endl;
			}
		}
		else if (ch == 2)
		{
			system("cls");
			ptr->setData();
		}
		else
		{
			cout << "Enter correct number " << endl;
		}
		break;
	case 2:
		ptr = &patient;
		system("cls");
		cout << "\t\t\t\t 1- New patient.\n\t\t\t\t 2- Consult\n\nEnter your chose (1-2) : ";
		cin >> ch;
		if (ch == 1)
		{
			system("cls");
			ptr->setData();
		}
		else if (ch == 2)
		{
			if (ptr->login())
			{

			}
			else
			{
				cout << "Enter correct id " << endl;
			}
		}
		else
		{
			cout << "Enter correct number " << endl;
		}
		break;
	default:
		break;
	}
}