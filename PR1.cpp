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
string alphabetupper_lower = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
string rot13_pair = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
string input;
ifstream rot13_file;
string line;
set<char> lettersUsed;
set<char> cLettersUsed; //Cipher Library
map <char, char> dictionaryMap;
map <char, char> decryptionMap;
void decrypt (map <char, char> &dictionaryMap, map <char, char> &decryptionMap, string source){
string decryptedText = "";
bool flag = false;  //Flag variable
int size = source.size();
char temp;
      for(auto itr = dictionaryMap.begin(); itr !=dictionaryMap.end(); itr++){
       decryptionMap [ itr -> second] = itr -> first;
       }
for (int i = 0; i <= size; i++) {
temp = source[i];
    if (isalpha(temp) == false || isspace(temp))
    {
    decryptedText.append(1,temp);
    continue;
    }
    if (isupper(temp)){
        temp = tolower(temp);
        flag = true;
    }
    else
 temp = (decryptionMap.find(temp)->second);
        if ((decryptionMap.find(temp)->first)== temp && flag == true) {
            decryptedText.append(1, toupper(decryptionMap[temp]));
            flag = false;
        }
        else if ((decryptionMap.find(source[i])->first) == source[i]) {
            decryptedText.append(1, (decryptionMap.find(source[i])->second));
        }
    }
 cout << decryptedText;
 }
void rot13(std :: string input)
{
    string encryptedString;
   for(int i = 0; i < input.length(); i++)
        {
            if (rot13_map.count(input[i]) == 1)
            {
                encryptedString += rot13_map[input[i]];
            }
            else
            {
                encryptedString += input[i];
            }
        }
   cout << encryptedString << "\n";
}
/*
void externalFunc()
{
    if(tArgB == true)
    {
        ifstream infile;
        infile.open (tArgS);
        if(!infile.is_open())
            cout << "FILE COULD NOT BE OPENED" << endl;
        while(!infile.eof()) // To get you all the lines.
        {
            getline(infile,stringInput); // Saves the line in STRING.
            rot13(stringInput);
            cout << stringInput << "\n";
        }
        infile.close();
    }
    else
    {
        while (getline(cin, stringInput))
        {
            rot13(stringInput);
        }
    }
}
*/
/*
void genjoe()
{
    vector <int> letterList;
    srand(time(0));
    for(int i = 97; i < 123; i++)
    {
        letterList.push_back(i);
    }
    for(int i = 0; i < 26; i++)
    {
        int index = rand() % 26;
        int temp = letterList[i];
        letterList[i] = letterList[index];
        letterList[index] = temp;
    }
    string abcs = "abcdefghijklmnopqrstuvwxyz";
    for(int i = 0; i <26; i++)
    {
        cout << abcs[i] << (char) (letterList[i]) << endl;
    }
    //return 0;
    vector <int> orderedLettrelist;
    for(int i = 97; i < 123; i++)
    {
        orderedLettrelist.push_back(i);
    }
    vector <int> letterList;
    srand(time(0));
    for(int i = 97; i < 123; i++)
    {
        letterList.push_back(i);
    }
    for(int i = 0; i < 26; i++)
    {
        int index = rand() % 26;
        int temp = letterList[i];
        letterList[i] = letterList[index];
        letterList[index] = temp;
    }
    string mixedString = "";
    for(int i = 0; i <26; i++)
    {
        mixedString += orderedLettrelist[i];
        mixedString += letterList[i];
        mixedString += ' ';
    }
    cout << mixedString << endl;
   
}
*/
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
               
                if (line.length() < 2)
                {
                    cout << "FORMATTING ERROR " << line << endl;
                    //return 0;
                }
               
                else if (line[0] == line[1])
                {
                    cout << "MAPPING ERROR " << line[0] << endl;
                    return 0;
                }
               
                else if (line[0] != abcs[counter])
                {
                    cout << "MISSING LETTER " << abcs[counter] << endl;
                    return 0;
                }
               
                else if (cLettersUsed.count(line[1]) == 1)
                {
                    cout << "DUPLICATE CIPHERTEXT " << line[1]  << "\n";
                    return 0;
                }
               
               
                lettersUsed.insert(abcs[line[0]]);
                cLettersUsed.insert(line[1]);
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


