
#include <iostream>
#include "Recipe.h"
#include <vector>
#include <iterator>
#include <windows.h>
#include <fstream>
#include <iomanip>

using namespace std;

/*-----------------------Wektor klasy Recipe jako ksiazka kucharska----------------------------------*/
vector<Recipe> cuisinebook;
/*-----------------------zainicjowanie funkcji aby kompilator wiedział o ich istnieniu---------------*/
/*-----------------------Funkcja menu glownego-------------------------------------------------------*/
void mainManu();
/*-----------------------Funkcja dodajaca przepisy---------------------------------------------------*/
void addMenu(vector<Recipe>& vect);
/*-----------------------funkcja wypisująca na ekran skladniki danego przepisu-----------------------*/
void PrintIngridient(vector<Recipe> vect, int p);
/*-----------------------Funkcja wypisująca na ekranie przepisy przydzielone do kategorii------------*/
void printList(vector<Recipe>& vect);
/*-----------------------Funkcja jako podmenu zmiany przepisu--------------------------------------- */
void ModifyRecipe(vector<Recipe>& vect, int p);
/*-----------------------Funkcja pomocnicza, wybieramy ktory przepis chcemy zmienic------------------*/
void modifyMenu(vector<Recipe>& vect);
/*-----------------------Funkcja zapisująca do pliku zmiany------------------------------------------*/
void uptadeRecipe();
/*-----------------------Funkcja zczytujaca z pliku przepisy-----------------------------------------*/
void getRecipe();

int main()
{
	cout << "__________________________________________________________________________________________________" << endl << endl;
	cout << "		                 Welcome in Recipe Creator Manager!" << endl;
	cout << "__________________________________________________________________________________________________" << endl << endl;
	getRecipe();
	CONSOLE_FONT_INFOEX win;
	system("color F5");
	win.cbSize = sizeof(win);
	win.nFont = 0;
	win.dwFontSize.X = 0;
	win.dwFontSize.Y = 20;
	win.FontFamily = FF_DECORATIVE;
	win.FontWeight = FW_NORMAL;
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &win);
	mainManu();
	
	
}
void addMenu(vector<Recipe>& vect)
{
	Recipe recipe_;
	while (true)
	{
		string food;
		cout << "Choose what kind of recipe you want to add:" << endl;
		cout << "1: appetizers" << endl;
		cout << "2: main courses" << endl;
		cout << "3: dessert" << endl;
		cin >> ws;
		getline(cin, food);
		recipe_.set_category(food);

		cout << "Enter the name of recipe:" << endl;
		cin >> ws;
		getline(cin, food);
		recipe_.set_name(food);
		cout << "----------------------------------------------------------------------" << endl;
		cout << "\t\tTime to add some ingridiens." << endl;
		cout << "----------------------------------------------------------------------" << endl;
		cout << "Every added ingridient confirm by click on enter, when you finish type in 2." << endl;
		while (true)
		{
			cout << " Enter the name of infridient: " << endl;
			cin >> ws;
			getline(cin, food);
			if (food[0] == '2')
				break;
			recipe_.add_ingredient(food);
		}
		cout << "Enter instructions for the recipe. Click enter when finish." << endl;
		cin >> ws;
		getline(cin, food);
		recipe_.set_instructions(food);

		vect.push_back(recipe_);
		food.clear();

		cout << "Recipe has been added. Do you wish to add another one:" << endl;
		cout << "1: Yes" << endl;
		cout << "2: No" << endl;
		string choice;
		cin >> choice;
		switch (choice[0])
		{
		case '2':
			break;
		case '1':
			break;
		default:
			cout << "Bad value, try again." << endl;
			cin >> choice;

		}
		if (choice[0] == '2')
			break;
	}
	uptadeRecipe();
}

void PrintIngridient(vector<Recipe> vect, int p)
{
	cout << "__________________________________________________________________________________________________" << endl;
	cout << "Ingridients of  " << vect[p].get_name() << " are: " << endl;
	vect[p].listingridient();
	cout << endl;
	cout << "__________________________________________________________________________________________________" << endl;
	cout <<"---------------------------------------------------------------------------------------------------" << endl;
	cout << " To make this dish you have to follow this instructions: \n";
	cout << vect[p].get_instructions() << endl;
	cout << "__________________________________________________________________________________________________" << endl;
}

void printList(vector<Recipe>& vect)
{
	if (vect.size() == 0) {
		cout << "Cuisine book is empty now." << endl << endl;
	}
	else {
		for (std::vector<Recipe>::iterator it0 = vect.begin(); it0 != vect.end(); it0++)
		{
			int ik = it0 - vect.begin();
			if (vect[ik].get_category() == "1")
				cout  << left<< ik + 1 << ": "<< setw(25) << vect[ik].get_name() << setw(25) << "Category : Appetizer " << endl;

			if (vect[ik].get_category() == "2")
				cout  <<left<< ik + 1 << ": " << setw(25) << vect[ik].get_name() << setw(25) << "Category : Main Course " << endl;

			if (vect[ik].get_category() == "3")
				cout <<left<< ik + 1 << ": " << setw(25) << vect[ik].get_name() << setw(25) << "Category : Dessert " << endl;
		}
		cout << "__________________________________________________________________________________________________" << endl;
		cout << "Enter the number of recipe whom you want to see ingridients and instructions" << endl;
		cout << "--------------------------------------------------------------------------------------------------" << endl;
		cout << "If you want to stop enter -1." << endl;
		cout << "__________________________________________________________________________________________________" << endl;
		while (true) {
			int i;
			cin >> i;
			i = static_cast<int>(i);
			if (i != -1)
			{
				if (i > vect.size() || i < -1)
				{
					cout << "Please type in correct number." << endl;
					cin >> i;
					if (i == -1)
						mainManu();

				}
				PrintIngridient(vect, i - 1);
				cout << endl;
			}
			else
				break;
		}
	}
}

void ModifyRecipe(vector<Recipe>& vect, int p) {
	while (true) {
		cout << "__________________________________________________________________________________________________" << endl;
		cout << "You have chosen: " << vect[p].get_name() << endl;
		cout << "Pick the option you would like to make: " << endl;
		cout << "1:Change the name of recipe" << endl;
		cout << "2:add new ingridient" << endl;
		cout << "3:remove ingridient " << endl;
		cout << "4:change discription" << endl;
		cout << "5: go to main manu" << endl;
		cout << "__________________________________________________________________________________________________" << endl;
		string choice;
		string change;
		cin >> choice;
		switch (choice[0]) {
		case '1':
			cout << "Current name is " << vect[p].get_name() << endl;
			cout << "Type in new name: " << endl;
			cin.ignore();
			getline(cin, change);
			vect[p].set_name(change);
			uptadeRecipe();
			break;
		case '2':
			cout << "Type in one new ingridient: " << endl;
			cin.ignore();
			getline(cin, change);
			vect[p].add_ingredient(change);
			cout << change << ": has been added to the recipe." << endl;
			uptadeRecipe();
			break;
		case '3':
		{
			cout << "Type the name of ingridient you want to remove" << endl;
			cin.ignore();
			getline(cin, change);
			vect[p].eraseingridient(change);
			cout << endl;
			cout << " List of ingridients after changes :" << change << endl;
			vect[p].listingridient();
			cout << endl;
			cout << change << ": has been removed succesfully." << endl;
			uptadeRecipe();
		}
		break;
		case '4':
			cout << "Please type in new instruction for this recipe." << endl;
			cin >> ws;
			getline(cin, change);
			vect[p].set_instructions(change);
			uptadeRecipe();
			break;
		case '5':
			return mainManu();

		default:
			cout << "there is no option like this!" << endl;
			break;
		}
	}
	uptadeRecipe();
}

void modifyMenu(vector<Recipe>& vect)
{
	while (true) {

		if (vect.size() == 0)
		{
			cout << "There is no recipes. " << endl;
			cout << "__________________________________________________________________________________________________" << endl;
			return;
		}
		else
		{
			cout << "__________________________________________________________________________________________________" << endl;
			cout << "Pick the number of recipe you wish to change" << endl;
			cout << "--------------------------------------------------------------------------------------------------" << endl;
			cout << "\t type in -1 to return to previous manu." << endl;
			cout << "__________________________________________________________________________________________________" << endl;
			for (auto it = vect.begin(); it != vect.end(); ++it)
			{
				int i = it - vect.begin();
				cout << i + 1 << ": " << vect[i].get_name() << endl;
			}
			int i;
			cin >> i;
			i = static_cast<int>(i);
			if (i != -1)
			{
				if (i > vect.size() || i < -1)
				{
					cout << "Please enter correct numeber." << endl;
					cin >> i;
					if (i == -1)
						mainManu();

				}
				ModifyRecipe(vect, i - 1);
			}
			else
				break;
		}
	}
}

void mainManu()
{
	while (true) {
		cout << "Choose from below options" << endl;
		cout << "1: Change recipe" << endl;
		cout << "2: Add recipe" << endl;
		cout << "3: List of recipes" << endl;
		cout << "4: Quit " << endl;
		string choice;
		cin >> choice;
		switch (choice[0]) {
		case '1': modifyMenu(cuisinebook);
			break;
		case '2': addMenu(cuisinebook);
			break;
		case '3': printList(cuisinebook);
			break;
		case '4':
			exit(0);
		default:
			cout << "a little mistake! " << endl;
			break;
		}
	}
}

void getRecipe()
{
	fstream file("recipe.txt");
	if (file.is_open())
	{
		while (!file.eof())
		{

			string  Category, NameofRecipe, instruct;

			getline(file, NameofRecipe, '|');
			getline(file, Category, '|');
			getline(file, instruct, '|');

			vector<string> ingridientss;
			string tem;
			getline(file, tem, '\n');

			size_t poz1 = 0;
			size_t poz2 = tem.find(";");

			while (poz2 != string::npos) {
				string tmp = tem.substr(poz1, poz2 - poz1);
				ingridientss.push_back(tmp);
				poz1 = poz2 + 1;
				poz2 = tem.find(";", poz2 + 1);
			}
			string tmp = tem.substr(poz1, tem.size() - poz1);
			ingridientss.push_back(tmp);

			Recipe* recipe = new Recipe(NameofRecipe,Category,instruct, ingridientss);
			cuisinebook.push_back(*recipe);
			delete recipe;
		}file.close();
	}

}

void uptadeRecipe()
{
	ofstream myfile("recipenew.txt");
	int count = 1;
	for (auto it : cuisinebook)
	{
		myfile << it.get_name() << "|" << it.get_category() << "|"<<it.get_instructions()<<"|";
		int temp = it.get_igridients().size() - 1;
		int check = 0;

		for (auto i : it.get_igridients())
		{
			myfile << i;
			if (check != temp) myfile << ";";
			check++;
		}
		if (count != cuisinebook.size()) myfile << "\n";
		count++;
	}
	myfile.close();

	remove("recipe.txt");
	rename("recipenew.txt", "recipe.txt");

	cuisinebook.clear();
	getRecipe();
}


