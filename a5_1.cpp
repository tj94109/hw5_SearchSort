/*
Terrance Stevenson
06/23/19
Assignment 5.1

This program demonstrates the linear search, binary search, bubble sort, and selection sort
algorithms through the storage of names and scores in 2 arrays. Then names are sorted using
selection sort and then displayed from highest to lowest score.

*/
#include <iostream>
#include <string>
using namespace std;


void initializeArrays(string names[], int scores[], int size);
void sortData(string names[], int scores[], int size);
void displayData(const string names[], const int scores[], int size);

int main() {

    string names[5];
    int scores[5];

    initializeArrays(names, scores, 5);
    sortData(names, scores, 5);
    displayData(names, scores, 5);

}

void initializeArrays(string names[], int scores[], int size){

    for(int i = 0; i < size; i++ ){
      cout << "Enter the name for score #"<< i+1 << ":" << endl;
      cin >> names[i];
      cout << "Enter the score for score #"<< i+1 << ":" << endl;
      cin >> scores[i];
    }

}

void sortData(string names[], int scores[], int size){

  int startScan, targetIndex, maxValue;
  string name = "";

  for(startScan = 0; startScan < (size -1); startScan++){
    targetIndex = startScan;
    maxValue = scores[startScan];
    string tempNames = names[startScan];
    for(int index = startScan + 1; index < size; index++){
      if(scores[index] > maxValue){
        maxValue = scores[index];
        tempNames = names[index];
        targetIndex = index;

      }
    }
    scores[targetIndex] = scores[startScan];
    scores[startScan] = maxValue;

    names[targetIndex] = names[startScan];
    names[startScan] = tempNames;
  }

}

void displayData(const string names[], const int scores[], int size){
	  cout << "" << endl;
	  cout << "Top Scorers: " << endl;

	  for(int count = 0; count < size; count++){
		  cout << names[count] << ":  "<< scores[count] << " " << endl;
  }
}

/* Sample Output:
Enter the name for score #1:
alice
Enter the score for score #1:
450
Enter the name for score #2:
billy
Enter the score for score #2:
560
Enter the name for score #3:
henry
Enter the score for score #3:
670
Enter the name for score #4:
vickie
Enter the score for score #4:
2200
Enter the name for score #5:
jim
Enter the score for score #5:
6988

Top Scorers:
jim:  6988
vickie:  2200
henry:  670
billy:  560
alice:  450

 */
