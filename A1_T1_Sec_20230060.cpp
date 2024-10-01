#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

// File: A1_T1_Sec_20230060
// Purpose:
// Author:
// Section:
// ID:
// TA:
// Date 8 oct 2024
// Detailed explanation of the file and how program works ...

class objectives
{
private:
    string choice;

    void MaleToInclusive()
    {
        string sentence;
        string newsentence;
        getline(cin, sentence);

        int i = 0, j = 0;

        while(i < sentence.size() && j < sentence.size())
        {
            if()
        }
    }

public:
    objectives(){choice = "";};
    ~objectives(){};

    void hello()
    {
        cout << "Hello, This is our sheet, It does some programs and solves some problems\n"
                "Choose the number of the problem You want\n"
                "1: The male speech to inclusive speech converter\n"
                "2: \n"
                "3: \n"
                "4: \n";

        do
        {
            cout << "Choose a Number from 1 to 4\n";
            cin >> choice;
        }
        while(choice < "1" || choice > "4");
    }


};

int main()
{
    objectives ob;
    ob.hello();
}