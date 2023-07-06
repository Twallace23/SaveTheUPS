#include <iostream>
#include <cstdlib>
#include <chrono>
#include "_BST.hpp"
#include <string>
#include <fstream>
#include <sstream>
using namespace std;
int main(int argc, char* argv[])
{
    //input file
    ifstream filename(argv[1]);
    //string for each line in the csv
    string s = "";
    //bst to call the functions
    BST binary;
    //data array size (csv file)
    const int size = 40000;
    //array for the data in the csv file
    int data[size];
    //array for the counter for the insertions
    float insert[400];
    //array for the counter for the searches
    float search[400];
    //iterator
    int i=0;
    //integer to store the data one by one
    int num;
    //loop through the file line by line with delimeter ,
   while(getline(filename,s,','))
    {
        //store each number into num
        num = stoi(s);
        //store it in the array
        data[i]= num;
        //print the data
        cout << data[i] << endl;
        i++;
    }
    //for time functions
    using namespace chrono;
    //for execution time
    chrono::duration <double> execTime;
    //set start and end
    chrono::high_resolution_clock:: time_point start,end;
    //indedx for the search loop
    int search_index;
    //value to search 
    int y;
    //loop 400 times for 400 outcomes in the insert array
   for(int i=0;i<400;i++)
   {
       //start timer
       start = high_resolution_clock::now();
       //loop through the first hundred numbers
       for(int j=i*100;j<100*i+100;j++)
       {
           //insert
            binary.insert(data[j]);
       }
       
       //end timer
       end = high_resolution_clock::now();
       //update time
       execTime = duration_cast<microseconds>(end-start);
       //give insert the values of the average time of the hundred 
       insert[i] = execTime.count()/100;
       //print
       cout << insert[i] << endl;
       //start a new timer for the search
       start = high_resolution_clock::now();
       //loop 100 times
       for(int x = 0;x<100;x++)
       {
           //give search index a random value from 0 to 100
           search_index = rand() % (100);
           //give y the value of that index
           y = data[search_index];
           //search for that value
            binary.search(y);
       }
       //end timer
       end = high_resolution_clock::now();
       //update the recorded time
       execTime = duration_cast<microseconds>(end-start);
       //print the average time
       search[i] = execTime.count()/100;
       //print out the outcomes
       cout << search[i] << endl;

   }
   //method to write outcomes into a file
   //output
   ofstream stats ("BST.csv"); // BST.csv for data set B
   //loop through the insert and search arrays
   for(int i =0;i<400;i++)
   {
       stats << i << ", " << insert[i] << ", " << search[i] << endl;
   }
   //close file
   stats.close();

}