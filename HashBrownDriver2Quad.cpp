#include "hash.hpp"
#include <iostream>
#include<string>
#include<chrono>
#include<math.h>
#include <fstream>
using namespace std;

int main(int argc, char *argv[])
{

/*
HashTable HT(5);
HT.LinearProbe(5);
HT.printTable();
HT.LinearSearch(5);
HT.QuadraticProbe(6);
HT.QuadSearch(6);
HT.Chaining(2);
*/

    if(argc!=2)
    {
        cout << "Invalid number of arg provided" << endl;
    }
    const int size = 40000;
    int testData[size];
    float insert[400];
    float search[400]; 

    ifstream file(argv[1]);
    string line = " ";
    string temp[1];
    int num;
    int index;
    int search_index = 100;

        int i=0;
        while(getline(file,line,','))
        {
            
           // string word;
            //istringstream ss(line);
            num = stoi(line);
            testData[i] = num;
           i++;

        }
        for(int i=0; i < size; ++i)
        {
           cout << testData[i] << endl;
        } 

        HashTable HT(40009);
        using namespace chrono;
        chrono::duration<double>execTime;
        chrono::high_resolution_clock::time_point start, end;
        cout << "Time it takes to use Linear Probe" << endl;
        for(int j=0; j < 400; j++) // iterating over insertion
        {

           // high_resolution_clock::time_point start, end;
            start = high_resolution_clock::now();
            for(int i = 100*j; i < 100*j+100; ++i)
            {
                HT.QuadraticProbe(testData[i]);
            }
            //this_thread::sleep_for(seconds(2));
            end = high_resolution_clock::now();
            execTime = duration_cast<microseconds>(end-start);

            insert[i] = execTime.count() / 100;
            cout << insert[i] << endl;
        }
        
            for(int i=0; i < 400; ++i)
            {
                start = high_resolution_clock::now();

                    for(int j=0; j<=100; j++)
                    {
                        index = (rand() % search_index);
                        HT.QuadSearch(testData[index]);
                    }
                    search_index += 100;
                    end = high_resolution_clock::now();
                    execTime = duration_cast<microseconds>(end-start);
                    search[i] = execTime.count() / 100;
                    cout <<  search[i] << endl;
            }
    ofstream myFile("Quad2.csv");
    for(int i=0; i < 400.0; ++i)
    {
        myFile << i << ", " << insert[i] << ", " << search[i] << endl;
    }
} 