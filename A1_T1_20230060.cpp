#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <fstream>

using namespace std;

// File: A1_T1_Sec_20230060
// Author: Eslam Saeed Hamdy Alshreef
// Section: S21
// ID: 20230060
// Date 11 oct 2024


/*
    This program offers a menu with four options to choose from:

    Convert Male to Inclusive Speech: You enter a sentence, and it replaces male-specific
    pronouns like "he" or "him" with both-gender pronouns ("he or she" or "him or her").

    Top 10 Scores: You input players' names and their scores, and it ranks the top 10 players.
    You can also search for a player's highest score.

    Fractal Pattern (Fatal Pattern): You input a number, and it prints a fractal pattern using stars (*).

    File Comparison: You compare two text files either character by character or word by word to check for differences.

    The program ends with a goodbye message, and you can choose to run it again.
*/

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

        cout << '\n';
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

    void CharByChar(ifstream &ff1, ifstream &ff2, const string& s1, const string& s2)
    {

        string line1, line2;
        int count = 0;

        while (getline(ff1, line1) && getline(ff2, line2)) {
            count++;
            if (line1 != line2) {
                cout << "Files differ at line " << count << ":\n";
                cout << "File 1: " << line1 << '\n';
                cout << "File 2: " << line2 << '\n';
                return;
            }
        }

        cout << "Files are identical (character by character).\n";

        ff1.close();
        ff2.close();
    }

    void WordByWord(ifstream &f1, ifstream &f2, const string& s1, const string& s2)
    {
        string word1, word2;
        int WordPosition = 1;

        while (f1 >> word1 && f2 >> word2)
        {
            if (word1 != word2)
            {
                cout << "Files differ at (word position " << WordPosition << "):\n";
                cout << "File 1: " << word1 << '\n';
                cout << "File 2: " << word2 << '\n';
                return;
            }
            WordPosition++;
        }

        cout << "Files are identical (Word by Word).\n";
    }

    void FileComparison()
    {
        ofstream file1, file2;
        string s1, s2, Choice = "0";
        cout << "File 1:";
        cin >> s1;
        file1.open(s1);
        cout << "File 2:";
        cin >> s2;
        file2.open(s2);

        if(!file1 || !file2)
        {
            cout << "Unable to open files\n";
            return;
        }
        cout << "Do You wanna compare it char by char or word by word ?\n"
                "1) Char by char\n"
                "2) word by word\n";

        while(Choice != "1" && Choice != "2")
        {
            cout << "Choose 1 or 2\n";
            cin >> Choice;
        }

        string CountLine;
        cout << "How many lines you want ?\n";
        cin >> CountLine;

        while (!digits(CountLine))
        {
            cout << "Please Input a number\n";
            cin >> CountLine;
        }

        int CountLine1 = stoi(CountLine);
        cin.ignore();
        cout << "File 1:\n";

        for(int i = 0; i < CountLine1; i++)
        {
            string s;
            getline(cin,s);
            file1 << s << '\n';
        }

        cout << "File 2:\n";

        for(int i = 0; i < CountLine1; i++)
        {
            string s;
            getline(cin,s);
            file2 << s << '\n';
        }

        file1.close();
        file2.close();

        ifstream ff1("eslam.txt"), ff2("eslam2.txt");

        if (!ff1 || !ff2) {
            cout << "Error: Unable to open one or both files for reading.\n";
            return;
        }

        if(Choice == "1")
        {
            CharByChar(ff1, ff2, "eslam.txt", "eslam2.txt");
        }
        else
        {
            WordByWord(ff1, ff2, "eslam.txt", "eslam2.txt");
        }
        ff1.close();
        ff2.close();
    }

    void again()
    {
        hello();
        ManageChoices();
        GoodBye();
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
                "4: File Comparison\n";

        do
        {
            cout << "Choose a Number from 1 to 4\n";
            cin >> choice;
        }
        while(choice < "1" || choice > "4");
        cin.ignore();
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
        else if(choice == "4")
        {
            FileComparison();
        }
    }

    void GoodBye()
    {
        string Choice;

        cout << "Do You wanna operate the project again ?\n"
                "1) Yes\n"
                "2) No\n";
        cin >> Choice;

        while(Choice != "1" && Choice != "2")
        {
            cout << "Input 1 | 2 Please\n";
            cin >> Choice;
        }

        if(Choice == "1")
        {
            again();
        }
        else
        {
            cout << "Good Bye!\n";
        }
    }
};

int main()
{
    objectives ob;
    ob.hello();
    ob.ManageChoices();
    ob.GoodBye();
}