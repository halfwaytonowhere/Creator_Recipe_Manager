#include "Recipe.h"
#include <iostream>
#include<vector>

using namespace std;

/*--------------Konstruktor--------------*/
Recipe::Recipe(string name, string category,string instructions, vector<string> ingredients) : _name(name), _category(category),_instructions(instructions), _ingredients(ingredients) {}
/*--------------gettery i settery--------------*/
string Recipe::get_category() const { return _category; }
string Recipe::get_name() const { return _name; }
string Recipe::get_instructions() const { return _instructions; }
vector<string> const Recipe::get_igridients() const { return _ingredients; }
void Recipe::set_category(string category) { _category = category; }
void Recipe::set_name(string name) { _name = name; }
void Recipe::set_instructions(string instructions) { _instructions = instructions; }
/*--------------funkcja dodaj¹ca skladniki do wektora ingridients_--------------*/
void Recipe::add_ingredient(string ingredient){_ingredients.push_back( ingredient);}
/*--------------funkcja wypisuj¹ca zawartoœæ wektora--------------*/
void Recipe::listingridient()
{
	for (auto i : _ingredients)
	{	
		cout<< i << " "; 
	}
}
/*--------------funkcja usuwaj¹ca dany skladnik z wektora--------------*/
void Recipe::eraseingridient(string ingr)
{
	auto it = find(_ingredients.begin(), _ingredients.end(), ingr);
	while (it != _ingredients.end()) {
		_ingredients.erase(it);
		it = find(_ingredients.begin(), _ingredients.end(), ingr);
	}
}
