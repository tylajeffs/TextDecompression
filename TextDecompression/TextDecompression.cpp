// LongestCommonSubsequence.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cstdlib>


using namespace std;


//global variables
vector<string> codes;
vector<string> characters;
string text = "";
int numOfBits;
int bitCounter = 0;









int main(int argc, char** argv)
{

    //get the file from the command line
    string filename = argv[1];//"C:/users/config/Desktop/pokemon.txt";
    ifstream ifs;

    //open the file
    ifs.open(filename, ios::in);

    //some basic error-checking...
    if (!ifs)
    {
        cout << "Error opening file: " << filename << endl;
        return -1;
    }


    //set boolean
    bool x = true;

    //get and store the line in the file
    while(x == true)
    {
        //read in the line
        string str;
        getline(ifs, str);


        //check 
        if (str == "*****")
        {
            x = false;
            //break
        }
        else
        {
            //split the string into the numerical code and the character
            string d = " ";
            string num = filename.substr(0, filename.find(d));
            string ch = filename.substr(1, filename.find(d));

            //add them into their respective vectors (2D)
            codes.push_back(num);
            characters.push_back(ch);
        }

    }

    //read in the number of bits
    string bits;
    getline(ifs, bits);



    //read in the charcters to decode from the file
    string charToDecode;
    getline(ifs, charToDecode);



    //close the scanner thingy
    ifs.close();









    //convert the codes into characters
    for (int i = 0; i < charToDecode.length(); i++)
    {
           //turn all the random characters into bits



        

        bitset<M> bits(string("1100"));
        

        //check to make sure we are at the correct number of bits
        if(bitCounter <= numOfBits)
        {
            //increase counter
            bitCounter ++;
        }



        //TODO - convert into a bitset, loop through each bit 

    }










































    //isolate the text name
    string delimiter = ".";
    string name = filename.substr(0, filename.find(delimiter));



    //write out the new file

    ofstream ofs;

    ofstream MyFile(filename + ".txt");

    //ofs.open("C:/users/config/desktop/quickSorted2.txt", ios::out);

 
    //put the text into the file 
    ofs << text << endl;

    

    //close it
    ofs.close();



    //print that the file was generated
    cout << "Text File Generated.\n";


}

