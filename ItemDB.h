#pragma once
#include "ItemClass.h"
using namespace std;

class cerealDataBase{
public:
  void printArrayToScreen();
  void printArrayToFile(const char fileName[]);
  int readCerealData();
  void addCereal();
  void removeCereal();
  void printbyCalories();
  void returnMenu();
  cerealDataBase();
private:
  enum {MAX_NUM_CEREALS = 100};
  cereal cerealList[MAX_NUM_CEREALS];
  int numCereals;
};