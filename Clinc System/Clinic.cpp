#include "Clinic.h"

void Patient::setData()
{

	Patient p;
	cout << "Enter your id : ";
	cin.ignore(); cin.getline(p.ID, 16);
	p.setName();
	p.setPhone();
	p.setmail();
	cout << "Enter City : ";
	cin.getline(p.city, 10);
	cout << "Enter streat No : ";
	cin >> p.streaNo;
	cout << "Enter the current day. : ";
	cin >> p.Day;
	cout << "Enter the current month. : ";
	cin >> p.Month;
	cout << "Enter the current year. : ";
	cin >> p.Year;
	cout << "Enter the amount of money you're going to pay. : ";
	cin >> p.balance;
	strcpy_s(p.State, "");
	fstream file;
	file.open("Patient.dat", ios::app, ios::binary);
	cout << "\n\n\t\t\t\t\t Created Doon \n\n";
	file.write((char*)&p, sizeof(p));
	file.close();
}

void Doc::showAllPatients()
{
	Patient p;
	fstream f;
	f.open("Patient.dat", ios::in, ios::binary);
	cout << "\n\n\t\t\t\t\t\t Patient information \n\n";
	cout << "ID\t" << setw(20) << "Name\t" << setw(20) << "Phone\t" << setw(30) << "Email\t" << setw(10) << "City\t" << setw(5) << "Straet No\t" << setw(10) << "Date of disclosure" << endl;
	while ((f.read((char*)&p, sizeof(p))))
	{
		cout << p.ID << "\t" << setw(20) << p.getName() << "\t" << setw(20) << p.getPhone() << "\t" << setw(30) << p.getmail() << "\t" << setw(10) << p.city << "\t" << setw(5) << p.streaNo << "\t" << setw(10) << p.Day << "/" << p.Month << "/" << p.Year << endl;
	}
	f.close();
}

void Doc::upDateStatus()
{
	Doc d;
	char id[17];
	Patient p;
	fstream f, temp;
	f.open("Patient.dat", ios::in, ios::binary);
	temp.open("temp.dat", ios::app, ios::binary);
	cout << "Enter Id : ";
	cin.ignore(); cin.getline(id, 17);
	while ((f.read((char*)&p, sizeof(p))))
	{
		if (strcmp(p.ID, id) == 0)
		{
			cout << "Enter the patient's condition description " << endl << "\t";
			cin.getline(p.State, 100);
			temp.write((char*)&p, sizeof(p));
		}
		else
		{
			temp.write((char*)&p, sizeof(p));
		}
	}
	f.clear();
	f.close();
	remove("Patient.dat");
	temp.close();

	f.open("Patient.dat", ios::app, ios::binary);
	temp.open("temp.dat", ios::in, ios::binary);

	while ((temp.read((char*)&p, sizeof(p))))
	{
		f.write((char*)&p, sizeof(p));
	}
	cout << "\n\n\t\t\t\t\t UpDate Doon \n\n";
	f.close();
	temp.close();
	remove("temp.dat");
}

void Doc::showAllStatus()
{
	Patient p;
	fstream f;
	f.open("Patient.dat", ios::in, ios::binary);
	cout << "\n\n================================================= Patient Status   ===================================================\n\n";

	cout << "ID\t" << setw(100) << "Patient status\t" << endl;
	while ((f.read((char*)&p, sizeof(p))))
	{
		cout << p.ID << "\t" << setw(100) << p.State << "\t" << endl;
	}
	f.close();
}

void Doc::DeletPatient()
{
	Doc d;
	d.showAllPatients();
	d.showAllStatus();
	char id[17];
	Patient p;
	fstream f, temp;
	f.open("Patient.dat", ios::in, ios::binary);
	temp.open("temp.dat", ios::app, ios::binary);
	cout << "Enter Id : ";
	cin.ignore(); cin.getline(id, 17);
	while ((f.read((char*)&p, sizeof(p))))
	{
		if (strcmp(p.ID, id) == 0)
		{
			continue;
		}
		else
		{
			temp.write((char*)&p, sizeof(p));
		}
	}

	f.close();
	remove("Patient.dat");
	temp.close();

	f.open("Patient.dat", ios::app, ios::binary);
	temp.open("temp.dat", ios::in, ios::binary);

	while ((temp.read((char*)&p, sizeof(p))))
	{
		f.write((char*)&p, sizeof(p));
	}
	cout << "\n\n\t\t\t\t\t Delet Doon \n\n";
	f.close();
	temp.close();
	remove("temp.dat");
}

bool Patient::login()
{
	int z = 0;
	char id[17];
	char h[17];
	Patient p;
	fstream f;
	f.open("Patient.dat", ios::in, ios::binary);
	cout << "Enter your Id : ";
	cin.ignore(); cin.getline(id, 17);
	while ((f.read((char*)&p, sizeof(p))))
	{
		if (strcmp(p.ID, id) == 0)
		{
			z++;
		}
	}
	f.close();
	if (z == 0)
	{

		return false;
	}
	else
	{
		system("cls");
		this->showstatu(id);
		return true;
	}
}

void Patient::showstatu(char id[])
{

	Patient p;
	fstream f;
	f.open("Patient.dat", ios::in, ios::binary);
	cout << "ID\t" << setw(100) << "Patient status\t" << endl;
	while ((f.read((char*)&p, sizeof(p))))
	{
		if (strcmp(p.ID, id) == 0)
		{
			cout << p.ID << "\t" << setw(100) << p.State << endl;
		}
	}
}

void Doc::setData()
{
	Doc d;
	d.setName();
	d.setPhone();
	d.setmail();
	cout << "Enter your Degree : ";
	cin.getline(d.Dgree, 20);
	cout << "Enter user name  : ";
	cin.getline(d.user, 20);
	cout << "Enter password : ";
	cin.getline(d.pass, 20);
	fstream file;
	file.open("Doctors.dat", ios::app, ios::binary);
	file.write((char*)&d, sizeof(d));
	cout << "\n\n\t\t\t\t\t Created Doon \n\n";
	file.close();
}

bool Doc::login()
{
	int z = 0;
	char user[20], passs[20];
	Doc d;
	fstream f;
	f.open("Doctors.dat", ios::in, ios::binary);
	cout << "Enter user name : ";
	cin.ignore(); cin.getline(user, 20);
	cout << "Enter password : ";
	cin.getline(passs, 20);
	while ((f.read((char*)&d, sizeof(d))))
	{
		if ((strcmp(d.user, user) == 0) && (strcmp(d.pass, passs) == 0))
		{
			z++;
		}
	}
	f.close();
	if (z == 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}
