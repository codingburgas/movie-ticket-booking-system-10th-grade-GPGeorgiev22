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