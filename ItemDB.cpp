#include <iostream>
#include "ReadUtils.h"
#include "ItemDB.h"
using namespace std;

cerealDataBase::cerealDataBase(){
  numCereals = 0;
  readCerealData();
}

void cerealDataBase::printArrayToScreen() {
    for (int index = 0; index < numCereals; index++) {
        cout << "Index " << index << ": ";
        cerealList[index].printCereal(cout);
    }
}

void cerealDataBase::printArrayToFile(const char fileName[]) {
    ofstream outFile(fileName);
    for (int index = 0; index < numCereals; index++) {
    cerealList[index].printCereal(outFile);
    }
}

int cerealDataBase::readCerealData(){
ifstream cerealFile("cereal.txt");
    numCereals = 0;
    while(cerealFile.peek() != EOF && numCereals < MAX_NUM_CEREALS) {
        cerealList[numCereals].readCereal(cerealFile);
        numCereals++;
    }
    return numCereals;
  //returns how many cereals are read.
  }

void cerealDataBase::addCereal(){
      cerealList[numCereals].addCereal();
        numCereals++;
  }

void cerealDataBase::removeCereal(){
  int removeIndex = 0;
  do{
  removeIndex = readInt("Enter an index to remove: ");
    for(int index = removeIndex; index < numCereals - 1; index++){
    cerealList[index] = cerealList[index + 1];
  }
}
while(removeIndex < 0 && removeIndex >= 100);
}

void cerealDataBase::printbyCalories(){
  for(int index = 0; index < numCereals; index++){
  if (cerealList[index].getcalories() <= 100){
      cerealList[index].printCereal(cout);
    }
    }
}

void cerealDataBase::returnMenu(){
  int userInput = 0;  
  while(userInput !=7){
      cout << "Choose a number option to continue or type quit." << endl;
      cout << "1. Reload database from the file." << endl;
      cout << "2. Print database." << endl;
      cout << "3. Add a new entry." << endl;
      cout << "4. Remove an entry." << endl;
      cout << "5. Print all cereals with less than an amount of calories." << endl;
      cout << "6. Save database to the file." << endl;
      cout << "7. Quit" << endl;
      cin >> userInput;

    if(userInput == 1){
    numCereals = readCerealData();
    }
    if(userInput == 2){
    printArrayToScreen();  
    }
    if(userInput == 3){
      if(numCereals < 100){
        addCereal();
        numCereals++;
        }
      else{
        cout << "The database is full!" << endl;
        }
    }
    if(userInput == 4){
    removeCereal();  
      numCereals--;
    }
    if(userInput == 5){
    printbyCalories();  
    }
    if(userInput == 6){
    printArrayToFile("cereal1.txt");  
    }
    if(userInput == 7){
      cout << "You decided to quit.";
      break;
        }
}
  }