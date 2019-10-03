#include <fstream>
#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>

using namespace std;

string stringInput = "";

string tArgS = "";

bool tArgB = false;

map <char,char> rot13_map;
map <char,char> interator it;

string alphabetupper_lower = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
string rot13_pair = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
string input;
ifstream rot13_file;
string line;
set<char> lettersUsed;



void rot13(std :: string input)
{
    string encryptedString;
    for(int u = 0; u < input.length(); u++)
    {

        if (rot13_map.count(input[u]) == 1)
        {
            encryptedString += rot13_map[input[u]];
        }

        else
        {
            encryptedString += input[u];
        }
    }
    cout << encryptedString << "\n";

}

void gCommand()
{
    srand(time(0));

    int lettersPrinted = 0;
    string abcs = "abcdefghijklmnopqrstuvwxyz";

    while (lettersPrinted < 26)
    {
        int index = rand() % 26;

        if(lettersUsed.count(abcs[index]) == 0)
        {
            if(abcs[lettersPrinted] != abcs[index])
            {
                lettersUsed.insert(abcs[index]);

                cout << abcs[lettersPrinted] << abcs[index] << "\n";

                lettersPrinted++;
            }
        }

    }

}

int main (int argc , char *argv[])
{
    if(argc == 1)
    {
        cout << "MISSING COMMAND" << endl;

        return 1;
    }

    if(string(argv[1]) == "-r")
    {
        for(int i = 0; i < rot13_pair.length(); i++)
        {
            rot13_map.insert({alphabetupper_lower[i], rot13_pair[i]});
        }

        if(argc < 3)
        {
            while(getline(cin, input))
            {
                rot13(input);

            }

        }

        else
        {
            rot13_file.open(argv[2]);

            if(rot13_file.is_open() && rot13_file.good())
            {
                while (getline(rot13_file, line))
                {
                    rot13(line);
                }

                rot13_file.close();
            }



            else
            {
                cout << "FILE COULD NOT BE OPENED\n";
                return 0;
            }
        }


        //externalFunc();
        //return 0;

    }

    else if(string(argv[1]) == "-g")
    {
        //genjoe();


        gCommand();
        return 0;
    }

    else if (string(argv[1]) == "-e")
    {

        if (argc < 3)
        {
            cout << "NO DICTIONARY GIVEN\n";
            return 0;
        }

        rot13_file.open(argv[2]);

        if (argc == 4) {
            rot13_file.open(argv[3]);
            if (rot13_file.fail()){
                cout << argv[3] << " FILE COULD NOT BE OPENED" << endl;
                return 0;
            }
        }

        if (rot13_file.is_open() && rot13_file.good())
        {
            string abcs = "abcdefghijklmnopqrstuvwxyz";
            int counter = 0;

            while (getline(rot13_file, line))
            {

                //OTHER INE
                if (lettersUsed.count(line[1]) == 1)
                {
                    cout << "DUPLICATE CIPHERTEXT " << line[1] << "\n";
                    return 0;
                }


                if (line.length() < 2)
                {
                    cout << "FORMATTING ERROR " << line << endl;
                    //return 0;
                }

                if (line[0] == line[1])
                {
                    cout << "MAPPING ERROR " << line[0] << endl;
                    return 0;
                }

                if (line[0] != abcs[counter])
                {
                    cout << "MISSING LETTER " << abcs[counter] << endl;
                    return 0;
                }

                //lettersUsed.insert(abcs[counter]);
                counter++;
            }

            rot13_file.close();
        }

        else
        {
            cout << argv[2] << " DICTIONARY COULD NOT BE OPENED\n";
        }

    }


    else
    {
        cout << argv[1] << " NOT A VALID COMMAND\n";
        return 0;
    }

}
