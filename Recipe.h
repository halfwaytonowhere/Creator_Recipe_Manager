#pragma once

#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

class Recipe
{
private: 
	vector<string> _ingredients;
	string _name;
	string _category;
	string _instructions;

public:
	/*------konstrukor------*/
	Recipe() {};
	Recipe(string name, string category,string instructions, vector<string> ingredients);
	/*------gettery------*/
	vector<string> const get_igridients(void)const;
	string get_name()const ;
	string get_category()const ;
	string get_instructions()const;
	/*------settery------*/
	void set_name(string name);
	void set_category(string category) ;
	void set_instructions(string instuctions);
	/*------funkcja do dodawania skladnikow do wektora _ingridients------*/
	void add_ingredient(string ingredient);
	/*------funkcja usuwaj¹ca sk³adnik z wektora _ingridients------ */
	void eraseingridient(string ingr);
	/*------funkcja do wypisywania sk³adników------*/
	void listingridient();
};	