#include <iostream>
#include <conio.h> // getch

#include <limits> // numeric_limits

#include "facilities.h"
#include "countingSort.h"
#include "radixSort.h"
#include "bucketSort.h"

using namespace std;

// Головна функція вибору та навігації по меню
void selection_menu(int level, int algorithm) {

  int choice;

  // Перший рівень вибору алгоритму сортування або виходу з програми
  if (level==0) {
    cout << "\t\t*****MAIN MENU*****\n\n\n\n" << endl;
    cout << "\t\tThis is a program for researching some famous sorting algorithms. Have a fun and choose your algorithm by entering the relevant number: " << endl;
    cout << "\t\t1. CountingSort" << endl;
    cout << "\t\t2. RadixSort" << endl;
    cout << "\t\t3. BucketSort" << endl;
    cout << "\t\t0. Exit, Good luck and Good Bye!" << endl;
    cout << endl;
    cout << "\t\tEnter your choice: ";
    cin.clear();
    cin >> choice;
    cout << endl;
    switch(choice) {
      case 1:
        selection_menu(1,1);
        break;
      case 2:
        selection_menu(1,2);
        break;
      case 3:
        selection_menu(1,3);
        break;
      // Так званий базовий випадок для рекурсивної функції
      case 0:
        cout << "\t\t*****See You next time! Keep going!*****";
        exit(0);
      default:
        cout << "\t\tCommand undefined" << endl;
        cout << endl;
        cout << "\t\tPress any key to return" << endl;
        getch();
        cout << endl;
        selection_menu(0,0);
    }
  }

  // Меню алгоритму підрахунком
  if (level==1) {
    if (algorithm==1) {
      cout << "\t\t--- MAIN MENU / COUNTING SORT ---" << endl;
    } else if (algorithm==2) {
      cout << "\t\t--- MAIN MENU / RADIX SORT ---" << endl;
    } else if (algorithm==3) {
      cout << "\t\t--- MAIN MENU / BUCKET SORT ---" << endl;
    }
    cout << "\t\tChoose the mode of an algorithm:" << endl;    
    cout << "\t\t1. Demo array 1000 ASC" << endl;
    cout << "\t\t2. Demo array 1000 DESC" << endl;
    cout << "\t\t3. Demo array 1000 random" << endl;
    cout << "\t\t4. Demo array 10000 ASC" << endl;
    cout << "\t\t5. Demo array 10000 DESC" << endl;
    cout << "\t\t6. Demo array 10000 random" << endl;
    cout << "\t\t7. Demo array 100000 ASC" << endl;
    cout << "\t\t8. Demo array 100000 DESC" << endl;
    cout << "\t\t9. Demo array 100000 random" << endl;
    if (algorithm==1) {
      cout << "\t\t10. Your array (random integers from 0 to 9)" << endl;
    } else if (algorithm==2) {
      cout << "\t\t10. Your array (random integers from 0 to 999)" << endl;
    } else if (algorithm==3) {
      cout << "\t\t10. Your array (random integers from 0 to 99)" << endl;
    }
    cout << "\t\t0. Main menu" << endl;
    cout << endl;
    cout << "\t\tEnter your choice: ";
    cin.clear();
    cin >> choice;
    cout << endl;

    if ((choice >= 1) && (choice <= 10)) {
      if (algorithm==1) {
        runCountingSort(choice); 
      } else if (algorithm==2) {
        runRadixSort(choice); 
      } else if (algorithm==3) {
        runBucketSort(choice); 
      }        
    } else if (choice == 0) {
      selection_menu(0,0);
    } else {
      cout << "\t\tCommand undefined" << endl;
    }

    cout << endl;
    cout << "\t\tPress any key to return" << endl;
    getch();
    cout << endl;    
    selection_menu(1,algorithm);
  }  

}

// Головна функція
int main(void) {
  // Меню
  selection_menu(0,0);

  // Запобігання передчасному закриттю консолі
  system("pause"); 
}