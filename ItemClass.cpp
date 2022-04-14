#include <iostream>
#include "ReadUtils.h"
#include "ItemClass.h"
using namespace std;

cereal::cereal(){
  for(int index = 0; index < MAX_NAME_LEN; index++){
    name[index]=0;
  }
  calories = 0;
  gramsofProtein = 0;
  gramsofFat = 0;
  gramsofSodium = 0;
  gramsofFiber = 0;
  gramsofCarbs = 0;
  gramsofSugar = 0;
  cupsPerServing = 0;
}

void cereal::printCereal(ostream &out){
    out << name << ";";
    out << calories << ";";
    out << gramsofProtein << ";";
    out << gramsofFat << ";";
    out << gramsofSodium << ";";
    out << gramsofFiber << ";";
    out << gramsofCarbs << ";";
    out << gramsofSugar << ";";
    out << cupsPerServing << endl;
}

void cereal::readCereal(ifstream &inFile){
    inFile.get(name, cereal::MAX_NAME_LEN, ';');
    inFile.ignore(100,';');
    inFile >> calories;
    inFile.ignore(100,';');
    inFile >> gramsofProtein;
    inFile.ignore(100,';');
    inFile >> gramsofFat;
    inFile.ignore(100,';');
    inFile >> gramsofSodium;
    inFile.ignore(100,';');
    inFile >> gramsofFiber;
    inFile.ignore(100,';');
    inFile >> gramsofCarbs;
    inFile.ignore(100,';');
    inFile >> gramsofSugar;
    inFile.ignore(100,';');
    inFile >> cupsPerServing;
    inFile.ignore(100,'\n');

}

void cereal::addCereal(){
      cout << "Enter the name of the cereal you want to add:" << endl;
      cin.ignore(11,'\n'); cin.getline(name,cereal::MAX_NAME_LEN);
      calories = readDouble("Enter the amount of calories: ");
      gramsofProtein = readDouble("Enter the grams of protein: ");
      gramsofFat = readDouble("Enter the grams of fat: ");
      gramsofSodium = readDouble("Enter the grams of sodium: ");
      gramsofFiber = readDouble("Enter the grams of fiber: ");
      gramsofCarbs = readDouble("Enter the grams of carbs: ");
      gramsofSugar = readDouble("Enter the grams of sugar: ");
      cupsPerServing = readDouble("Enter the amount of cups per serving: ");
      //cin.ignore(11,'\n');
      return;
        }

double cereal::getcalories(){
  return calories;
}