#pragma once
#include <fstream>
using namespace std;

class cereal{
public:
  cereal();
  void printCereal(ostream &out);
  void readCereal(ifstream &inFile);
  void addCereal();
  double getcalories();
private:
  enum {MAX_NAME_LEN=100};
  char name[MAX_NAME_LEN];
  double calories;
  double gramsofProtein;
  double gramsofFat;
  double gramsofSodium;
  double gramsofFiber;
  double gramsofCarbs;
  double gramsofSugar;
  double cupsPerServing;
};