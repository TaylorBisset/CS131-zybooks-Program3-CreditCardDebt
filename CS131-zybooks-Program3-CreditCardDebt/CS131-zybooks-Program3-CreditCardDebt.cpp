#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

// Read customer information from external file
// Make no changes to the following code
void ReadCustomerData(vector<string>& names, vector<string>& states, vector<double>& debt) 
{
    ifstream inFS;

    // Read all data from file into three parallel vectors
    try 
    {
        inFS.open("CustomerData.csv");

        for (long unsigned index = 0; index < names.size(); ++index) 
        {
            inFS >> names.at(index); // last name
            inFS >> states.at(index); // state of residence
            inFS >> debt.at(index);   // amount of debt
        }
    }
    // What if data file not found?
    catch (string err) 
    {
        cout << "Failed to read the data file: " << err << endl;
    }

    inFS.close();
}

int main() 
{
    int size;

    // Input # of customers and create parallel vectors
    cin >> size;
    vector<string> names(size);
    vector<string> states(size);
    vector<double> debt(size);

    // Fill vectors with data from external file (described in another section)
    ReadCustomerData(names, states, debt);

    /* Type your code here */
    // Input debt limit, search phrase, and state

    return 0;
}

/*
Program Specifications Write a program to search three parallel vectors containing customer credit card debt information. 
Identify statistics such as the number of customer names that begin with 'S', 
the number of customers with no debt, and the number of customers that live in a specific state.

Note: This program is designed for incremental development. 
Complete each step and submit for grading before starting the next step. 
Only a portion of tests pass after each step but confirm progress.


Step 0. Review the starter code in main(). 
The number of requested customers is input (integer). 
A function is called that reads data from a text file and fills three parallel vectors 
with customer names, state of residence, and amount of credit card debt for each customer. 
Using a function is a convenient way to fill vectors with hundreds of elements. 
Functions and reading data from text files are described in other sections of the book.


Step 1. Input a debt limit (integer), first letter of customer's name (char), and state abbreviation (string). 
Note that the number of customers is already input during Step 0.


Step 2 (2 pts). Use a loop to process each element of the names and debt vectors to identify the customer with the highest debt. 
Output a report header, number of customers, and the person's name with the highest debt. 
Submit for grading to confirm two tests pass.

Ex: If input is:

1000 250 P LA
the output is:

U.S. Report
Customers: 1000
Highest debt: Sullivan


Step 3 (2 pts). Use a loop to process each element of the names vector to count 
all customer names that begin with the specified letter. 
Ex: How many customer names begin with 'B' or 'L'? 
Output the number of customer names that start with the specified letter. 
Submit for grading to confirm four tests pass.

Ex: If input is:

1000 250 P TX
the output is:

U.S. Report
Customers: 1000
Highest debt: Sullivan
Customer names that start with 'P': 57


Step 4 (2 pts). Use a loop to process each element of the names and debt vectors 
to count the number of customers that have debt higher than the specified debt limit 
and the number of customers that have no debt. Output all results. 
Submit for grading to confirm six tests pass.

Ex: If input is:

2000 250 P TX
the output is:

U.S. Report
Customers: 2000
Highest debt: Sullivan
Customer names that start with 'P': 111
Customers with debt over $250: 1562
Customers debt free: 438


Step 5 (4 pts). Repeat steps 2 - 4 for all customers living in the specified state. 
Output all results including a header for the state report. 
Submit for grading to confirm all tests pass.

Ex: If input is:

8000 8000 A CA
the output is:

U.S. Report
Customers: 8000
Highest debt: Anderson
Customer names that start with 'A': 261
Customers with debt over $8000: 2480
Customers debt free: 1697

CA Report
Customers: 851
Highest debt: Duenas
Customer names that start with 'A': 38
Customers with debt over $8000: 268
Customers debt free: 176
*/