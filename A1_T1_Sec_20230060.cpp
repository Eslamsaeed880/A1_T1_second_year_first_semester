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

    bool digits(string s)
    {
        for(auto i : s)
        {
            if(!isdigit(i))
            {
                return false;
            }
        }
        return true;
    }

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

    void Top10Players()
    {
        string NumOfPlayers;
        cout << "Please Input the number of players You want.\n";
        cin >> NumOfPlayers;
        vector<pair<int,string>> scores;

        while(!digits(NumOfPlayers))
        {
            cout << "Please Input a real number\n";
            cin >> NumOfPlayers;
        }

        for(int i = 1; i <= stoi(NumOfPlayers); i++)
        {
            string player;
            string score;

            cout << "Input the Name of the player and the score of him\n";
            cout << "Player " << i << ": ";
            cin >> player >> score;

            while(!digits(score))
            {
                cout << "Please Input a real number\n";
                cin >> score;
            }

            scores.emplace_back(stoi(score), player);
            sort(scores.begin(), scores.end());
            reverse(scores.begin(), scores.end());
            while(scores.size() > 10)
            {
                scores.pop_back();
            }
        }

        cout << "Top 10 Players\n";
        for(int i = 1; i <= min(10, stoi(NumOfPlayers)); i++)
        {
            cout << "Player " << i << ": " << scores[i - 1].second << ' ' << scores[i - 1].first << '\n';
        }

        while(true)
        {
            string YesOrNo;
            do
            {
                cout << "Do You wanna know highest score of any player\n";
                cout << "1) Yes\n2) No\n";
                cin >> YesOrNo;
            }
            while(YesOrNo != "1" && YesOrNo != "2");

            if(YesOrNo == "2")
            {
                return;
            }
            else
            {
                string name;
                bool exist = false;
                cout << "What's his name ?\n";
                cin >> name;

                for(int i = 0; i < scores.size(); i++)
                {
                    if(scores[i].second == name)
                    {
                        exist = true;
                        cout << scores[i].second << " " << scores[i].first << '\n';
                        break;
                    }
                }

                if(!exist)
                {
                    cout << "Your player isn't exist\n";
                }
            }
        }
    }

    void PrintLine(int n)
    {
        static int i = 0;

        if(n == 1)
        {
            for(int j = 0; j < i; j++)
            {
                cout << ' ';
            }
            cout << "*\n";
            i++;
            return;
        }
        else if(i > n)
        {

            for(int j = 0; j < i - n + 1; j++)
            {
                cout << ' ';
            }
        }

        for(int j = 0; j < n; j++)
        {
            cout << "* ";
        }
        cout << "\n";

        i++;
    }

    void pattern(int n)
    {
        if(n <= 1)
        {
            PrintLine(1);
            return;
        }

        pattern(n / 2);
        PrintLine(n);
        pattern(n / 2);
    }

    void ManageChoices()
    {
        if(choice == "1")
        {
            MaleToInclusive();
        }
        if(choice == "2")
        {
            Top10Players();
        }
        else if(choice == "3")
        {
            string n;
            cout << "Input a Number You wanna see his Fatal Pattern\n";
            cin >> n;
            while(!digits(n))
            {
                cout << "Please Input a Number\n";
                cin >> n;
            }
            pattern(stoi(n));
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
                "2: Top 10 Scores\n"
                "3: Fatal Pattern\n"
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