// LongestCommonSubsequence.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <map>
#include <cstdlib>
#include <bitset>


using namespace std;


//global variables
map<string, string> charCodes;

int numOfBits;
int bitCounter = 0;
string working = "";
string output = "";









int main(int argc, char** argv)
{

    //get the file from the command line
    string filename = argv[1];//"C:/users/config/Desktop/pokemon.txt";
    ifstream ifs;

    //open the file
    ifs.open(filename, ios::in | ios::binary);

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
            charCodes[num] = ch;
        }

    }

    //read in the number of bits
    string bits;
    getline(ifs, bits);



    //read in the charcters to decode from the file
    string charToDecode;

    //check to see what is next with out moving the pointer
    while (ifs.peek() == '\n' || ifs.peek() == '\r') 
    {
        //if the first two are new lines, skip 
        ifs.seekg(1, ifs.cur);
    }

    //save the current position
    auto start = ifs.tellg();

    //save end position
    ifs.seekg(0, ifs.end);
    auto end = ifs.tellg();

    //move back to the start position
    ifs.seekg(start);

    //create a vector of all the characters
    vector<char> bytes(end - start);

    //dump the data into the vector of characters
    ifs.read(bytes.data(), end - start);

    //convert vector to string
    charToDecode = string(bytes.data(), end - start);



    //close the scanner thingy
    ifs.close();









    //convert the codes into characters
    for (int i = 0; i < charToDecode.length(); i++)
    {
        //turn the character into 8 bits
        bitset<8> bits(charToDecode[i]);
        


        //go through each of the bits for that character
        for (int j = 0; j < 8; j++)
        {


            //check to make sure we are at the correct number of bits
            if (bitCounter < numOfBits)
            {

                //increase counter
                bitCounter++;


                //add one bit to the working string and check if it matches any of the character codes
                working += bits[j];



                //check to see if the working string matches one of the codes
                if (charCodes.count(working) == 1)
                {


                    //the code exists, add the character to the output string
                    output += charCodes.at(working);

                    //clear the working string
                    working = "";

                }



            }

        }
        


    }



















    //isolate the text name
    string delimiter = ".";
    string name = filename.substr(0, filename.find(delimiter));



    //write out the new file

    ofstream ofs;

    ofstream MyFile(name + ".txt", ios::out | ios::binary);

    //ofs.open("C:/users/config/desktop/quickSorted2.txt", ios::out);

 
    //put the text into the file 
    ofs << output << endl;

    

    //close it
    ofs.close();



    //print that the file was generated
    cout << "Text File Generated.\n";


}

