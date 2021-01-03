#include <iostream>
#include <conio.h>
#include <fstream>
#include <string.h>
#include <iomanip>
#include <cstdlib>
#include <stdio.h>
using namespace std;
ifstream fin;
ofstream fout;
fstream finout;
struct node
{
	char fname[20];
	char lname[20];
	int age;
	char sex;
	char num[10];
	char email[50];
	char bday[8];
	node * link;
}
n;
class contact
{
	node *rear, *front;
	public:
		contact()
		{
			rear = NULL;
			front = NULL;
		}

	void insert();
	void deletecontact();
	void display();
	void displaycontact(node n);
	void save();
	void search();
	void edit();
	~contact();
};
void contact::insert()
{
	node *temp = new node;
	cout << "\nEnter the details:";
	cout << "\nFirst Name: ";
	cin >> temp->fname;
	cout << "Last name: ";
	cin >> temp->lname;
	cout << "Age: ";
	cin >> temp->age;
	cout << "Sex: ";
	cin >> temp->sex;
	cout << "Number: ";
	cin >> temp->num;
	cout << "E-mail id: ";
	cin >> temp->email;
	cout << "Birthday:(ddmmyyyy) ";
	cin >> temp->bday;
	cout << "\nContact successfully inserted!";
	temp->link = NULL;
	if (rear == NULL)
		rear = front = temp;
	else
	{
		rear->link = temp;
		rear = temp;
	}
}
void contact::display()
{
	node *temp = front;
	while (temp != NULL)
	{
		cout << "\n\nName:" << temp->fname << " " << temp->lname;
		cout << "\nAge: " << temp->age;
		cout << "\nSex: " << temp->sex;
		cout << "\nNumber: " << temp->num;
		cout << "\nE-mail id: " << temp->email;
		cout << "\nBirthday:(ddmmyyyy) " << temp->bday;
		temp = temp->link;
	}
}
void contact::displaycontact(node n)
{
	cout << "\n\nName:" << n.fname << " " << n.lname;
	cout << "\nAge: " << n.age;
	cout << "\nSex: " << n.sex;
	cout << "\nNumber: " << n.num;
	cout << "\nE-mail id: " << n.email;
	cout << "\nBirthday:(ddmmyyyy) " << n.bday;
}
void contact::search()
{
	int choice;
	char nm[20], found = 'n';
	cout << "\nWhat would you like to search on the basis of?";
	cout << "\n1.First name\n2.Number\n3.Birthday\n";
	cin >> choice;
	node *ptr = front;
	switch (choice)
	{
		case 1:
			cout << "\nEnter the first name: ";
			cin >> nm;
			while (ptr != NULL)
			{
				if (strcmp(ptr->fname, nm) == 0)
				{
					found = 'y';
					displaycontact(*ptr);
					break;
				}
				ptr = ptr->link;
			}
			if (found == 'n')
				cout << "\nContact not found!";
			break;
		case 2:
			cout << "\nEnter the number: ";
			cin >> nm;
			while (ptr != NULL)
			{
				if (strcmp(ptr->num, nm) == 0)
				{
					found = 'y';
					displaycontact(*ptr);
					break;
				}
				ptr = ptr->link;
			}
			if (found == 'n') cout << "\nContact not found!";
			break;
		case 3:
			cout << "\nEnter the birthday:(ddmmyyyy) ";
			cin >> nm;
			while (ptr != NULL)
			{
				if (strcmp(ptr->bday, nm) == 0)
				{
					found = 'y';
					displaycontact(*ptr);
					break;
				}
				ptr = ptr->link;
			}
			if (found == 'n') cout << "\nContact not found!";
			break;
		default:
			cout << "\nInvalid choice!";
			break;
	}
}
void contact::deletecontact()
{
	char nm[10], found = 'n';
	if (front == NULL)
	{
		cout << "\nUnderflow!";
		return;
	}
	else
	{
		cout << "\nEnter the first name of the contact to be deleted: ";
		cin >> nm;
		node *ptr = front;
		if (strcmp(ptr->fname, nm) == 0)
		{
			found = 'y';
			front = front->link;
			delete ptr;
			cout << "\nContact deleted!";
		}
		else if (strcmp(rear->fname, nm) == 0)
		{
			found = 'y';
			node *temp = rear;
			rear = ptr;
			ptr->link = NULL;
			cout << "\nContact deleted!";
		}
		else
		{
			while (ptr->link->link != NULL)
			{
				if (strcmp(ptr->fname, nm) == 0)
				{
					ptr->link = ptr->link->link;
					delete ptr;
					found = 'y';
					cout << "\nContact deleted!";
					break;
				}
				ptr = ptr->link;
			}
		}
		if (found == 'n') cout << "\nContact not found!";
		if (front == NULL) rear = NULL;
	}
}
void contact::edit()
{
	char nm[20], lname1[20], sex1, num1[10], email1[50], bday1[8], found = 'n';
	int age1;
	node *ptr = front;
	cout << "\nEnter the first name: ";
	cin >> nm;
	while (ptr != NULL)
	{
		if (strcmp(ptr->fname, nm) == 0)
		{
			found = 'y';
			displaycontact(*ptr);
			break;
		}
		ptr = ptr->link;
	}
	if (found == 'n')
	{
		cout << "\nContact not found!";
		return;
	}
	cout << "\n\nEnter new details: ";
	cout << "\nNew Last name: (Enter '.' to retain old one)";
	cin >> lname1;
	if (strcmp(lname1, ".") != 0)
		strcpy(ptr->lname, lname1);
	cout << "\nNew Age: (Enter '0' to retain old one)";
	cin >> age1;
	if (age1 != 0)
		ptr->age = age1;
	cout << "\nNew Sex: (Enter '.' to retain old one)";
	cin >> sex1;
	if (sex1 != '.')
		ptr->sex = sex1;
	cout << "\nNew Number: (Enter '.' to retain old one)";
	cin >> num1;
	if (strcmp(num1, ".") != 0)
		strcpy(ptr->num, num1);
	cout << "\nNew Email id: (Enter '.' to retain old one)";
	cin >> email1;
	if (strcmp(email1, ".") != 0)
		strcpy(ptr->email, email1);
	cout << "\nNew Birthday: (Enter '.' to retain old one)";
	cin >> bday1;
	if (strcmp(bday1, ".") != 0)
		strcpy(ptr->bday, bday1);
	cout << "\n\nContact modified! :)\n";
}
void contact::save()
{
	char found = 'n';
	finout.open("Contacts.dat", ios::out | ios::app);
	finout.seekg(0, ios::beg);
	while (finout)
	{
		finout.read((char*) &n, sizeof(n));
		if (finout.eof()) break;
		if (n.fname == front->fname && n.lname == front->lname)
		{
			found = 'y';
			finout.seekp(-1* sizeof(n), ios::cur);
			finout.write((char*) &n, sizeof(n));
		}
	}
	if (found == 'n')
	{
		finout.seekp(0, ios::end);
		node *temp = front;
		n = *temp;
		while (temp != NULL)
		{
			finout.write((char*) &n, sizeof(n));
			temp = temp->link;
		}
		finout.close();
	}
}
contact::~contact()
{
	node * temp;
	while (front != NULL)
	{
		temp = front;
		front = front->link;
		delete temp;
	}
}
int main()
{
	contact c1;
	int choice;
	char ans = 'y';
	while (ans == 'y' || ans == 'Y')
	{
		cout << "\n\t\tWELCOME TO YOUR CONTACT BOOK\n";
		cout << "\n\t\t\t ";
		cout << "\n\t\t\t MAIN MENU ";
		cout << "\n\t\t\t ";
		cout << "\n\t\t\t Choose an operation: ";
		cout << "\n\t\t\t ";
		cout << "\n\t\t\t 1.Insert a contact ";
		cout << "\n\t\t\t 2.Display all contacts ";
		cout << "\n\t\t\t 3.Search for a contact ";
		cout << "\n\t\t\t 4.Delete a contact ";
		cout << "\n\t\t\t 5.Edit a contact ";
		cout << "\n\t\t\t 6.Save contacts to file ";
		cout << "\n\t\t\t 0.Exit ";
		cout << "\t\n\n\n\t\t\tYour choice please: ";
		cin >> choice;
		switch (choice)
		{
			case 1:
				c1.insert();
				break;
			case 2:
				c1.display();
				break;
			case 3:
				c1.search();
				break;
			case 4:
				c1.deletecontact();
				break;
			case 5:
				c1.edit();
				break;
			case 6:
				c1.save();
				cout << "\nThe current contact has been successfully saved in the
				file.
				";
				break;
			case 0:
				exit(0);
				break;
			default:
				cout << "\nInvalid choice!";
				break;
		}
		cout << "\n\nDo you want to continue?(y/n) ";
		cin >> ans;
	}
	getch();
	return 0;
}
