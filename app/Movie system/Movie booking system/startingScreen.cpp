#include <iostream>
using namespace std;

void aboutPage()
{

}

class Menu
{
public:
	Movie m;
	Administrator a;
	void displayMenu()
	{
		aboutPage();
		int enter;
		cin >> enter;
		if (enter == 1)
		{
			do
			{
				int check = 0;
				system("cls");
				cout << "1. Add movie " << endl;
				cout << "2. Display movie " << endl;
				cout << "3. Admin settings " << endl;
				cout << "4. Exit " << endl;
				cin >> check;
				switch (check)
				{
				case 1:
					system("cls");
					m.addMovie();
					break;
				case 2:
					system("cls");
					m.displayMovie();
					break;
				case 3:
					system("cls");
					a.changePass();
					break;
				case 4:
					exit(0);
					break;
					system("cls");
				}
			} while (true);
		}
		else if (enter == 2)
		{
			exit(0);
		}
		else
		{
			cout << "Invalid input!"
		}
	}
};

void startMenu()
{
	while (true)
	{
		int mainCheck = 0;
		int newCheck = 0;
		system("cls");
		aboutPage();
		cin >> newCheck;
		system("cls");
		if (newCheck == 1)
		{
			cout << " Welcome to..." << endl;
			cout << " 1. Administrator" << endl;
			cout << " 2. Customer" << endl;
			cin >> mainCheck;
			if (mainCheck == 1) {
				char userName[100];
				char pass[100];
				cout << "Enter username: ";
				cin >> userName;
				cout << "Enter password: ";
				cin >> pass;
				char user[100];
				char userPass[100];
				int nCheck = 0;
				int aCheck = 0;
				ifstream userData("admins.txt");
				{
					if (!userData)
					{
						cout << "Cannot open file!";
					}
					while (!(userData.eof()))
					{
						userData >> user >> userPass;
						if (compare(user, userName))
						{
							nCheck = 1;
						}
						if (compare(userPass, pass))
						{
							aCheck = 1;
						}
					}
					userData.close();
				}
				if (nCheck == 1 and aCheck == 1)
				{
					system("cls");
					Menu am;
					am.displayMenu();
					system("cls");
				}
			}
			else {
				cout << " Permission denied!\n";
				cout << "Press any key to go back: ";
				system("cls");
			}
		}
		else if (newCheck == 3)
		{
			exit(0);
		}
		else
		{
			int rCheck = 0;
			int userSelect = 0;
			cout << "Enter personal details" << endl;
			Customer c2;
			c2.getData();
			getch();
			system("cls");
			cout << " 1. Dispay movies" << endl;
			cout << " 2. Select movie" << endl;
			cout << " 3. Exit" << endl;
			cin >> userSelect;
			Movie m2;
			Recepton r2;
			Hall h2;
		}
	}
}