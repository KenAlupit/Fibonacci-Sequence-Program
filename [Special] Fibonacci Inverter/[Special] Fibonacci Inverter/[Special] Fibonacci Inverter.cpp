#include <iostream>
#include <fstream>
#include <stdio.h>
#include <cstdio>
#include <string>
using namespace std;
    
int terms;
int firstTerm = 0;
int secondTerm = 1;
int nextTerm = 0;
string tempFile = "temporary.txt";
string fileName;
char input;

void fibonacci() 
{
    ofstream writeFile("temporary.txt");
    cout << "Enter the number of terms: ";
    cin >> terms;
    cout << "Fibonacci Series: ";
    for (int i = 1; i <= terms-2; ++i)
    {
      if (i == 1)
      {
       cout << firstTerm << " ";
       writeFile << firstTerm << " " << endl;
      }
      if (i == 2)
      {
       cout << secondTerm << " ";
       writeFile << secondTerm << " " << endl;
      }
       nextTerm = firstTerm + secondTerm;
       firstTerm = secondTerm;
       secondTerm = nextTerm;

       cout << nextTerm << " ";
       writeFile << nextTerm << " " << endl;
    }
    writeFile.close();

    cout << "\nEnter the file name: ";
    cin >> fileName;
    string file = fileName + ".txt";
    const char* a = file.c_str();
    const char* b = tempFile.c_str();

    if (rename(b, a) != 0)
    {
     perror("error");
    }
}
void Print()
{   
   string Text;
   cout << "what is the file name: ";
   cin >> fileName;
   ifstream readFile(fileName + ".txt");
   if(readFile)
   {
     while (getline(readFile, Text)) {
      cout << Text;
     }
   }
   else
   {
       cout << "file does not exist create a new one...\n";
       fibonacci();
   }
   
  
   readFile.close();
}
int main()
{  
    cout << "Selection an option below\n";
    cout << "[O] - Old\n";
    cout << "[N] - New\n";
    cin >> input;
    
    switch (input) {
    case 'o':
    case 'O':
        Print();
        break;
    case 'n':
    case 'N':
        fibonacci();
        break;
    default:
        cout << "Invalid Input";
        break;
    }

}

