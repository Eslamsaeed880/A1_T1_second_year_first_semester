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

    bool IsHe(string s)
    {
        string s1;
        for(int i = 0; i < s.size(); i++)
        {
            s[i] = tolower(s[i]);

            if(isalpha(s[i]))
            {
                s1 += s[i];
            }
            else if(isdigit(s[i]))
            {
                return false;
            }
            else if(ispunct(s[i]))
            {
                if(i != 0 && i != s.size() - 1)
                {
                    return false;
                }
            }
        }

        return s1 == "he";
    }

    bool IsHim(string s)
    {
        string s1;
        for(int i = 0; i < s.size(); i++)
        {
            s[i] = tolower(s[i]);

            if(isalpha(s[i]))
            {
                s1 += s[i];
            }
            else if(isdigit(s[i]))
            {
                return false;
            }
            else if(ispunct(s[i]))
            {
                if(i != 0 && i != s.size() - 1)
                {
                    return false;
                }
            }
        }

        return (s1 == "him" || s1 == "his");
    }

    void PunctDetict(string s)
    {
        if(IsHe(s))
        {
            if(ispunct(s[s.size() - 1]))
            {
                for(int i = 0; i < s.size() - 1; i++)
                {
                    cout << s[i];
                }
                cout << " or she" << s.back() << " ";
            }
            else
            {
                cout << s << " or she ";
            }
        }
        else if(IsHim(s))
        {
            if(ispunct(s[s.size() - 1]))
            {
                for(int i = 0; i < s.size() - 1; i++)
                {
                    cout << s[i];
                }
                cout << " or her" << s.back() << " ";
            }
            else
            {
                cout << s << " or her ";
            }
        }
    }

    void MaleToInclusive()
    {
        cout << "Input a sentence to convert from Male to Inclusive\n";
        string sentence;
        string newword;
        vector<string> words;
        getline(cin, sentence);

        for(int i = 0; i < sentence.size(); i++)
        {
            if(sentence[i] != ' ')
            {
                newword += sentence[i];
            }
            else
            {
                words.push_back(newword);
                newword = "";
            }
        }

        words.push_back(newword);

        for(int i = 0; i < words.size(); i++)
        {
            if(IsHe(words[i]))
            {
                PunctDetict(words[i]);
            }
            else if(IsHim(words[i]))
            {
                PunctDetict(words[i]);
            }
            else
            {
                cout << words[i] << " ";
            }
        }
    }

    

    void ManageChoices()
    {
        if(choice == "1")
        {
            MaleToInclusive();
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
        cin.ignore();
        ManageChoices();
    }


};

int main()
{
    objectives ob;
    ob.hello();
}