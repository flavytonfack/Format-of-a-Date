//
//  main.cpp
//  assignment1
//
//  Created by Flavy Tonfack on 6/21/17.
//  Copyright © 2017 Flavy Tonfack. All rights reserved.
//

#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <sstream>


using namespace std;

string ReformatDate(string oldDate);

int main()
{
    cout << "\nPlease Enter the date in the format date MM DD YYYY:" <<endl;
    string input;
    getline(cin, input);
    
    
    ReformatDate(input);
    
    cout << "\n\n";
    system("pause");
    return 0;
}
string ReformatDate(string oldDate)
{
    string dateValue, date, month, year;
    stringstream str_stream;
    int myYear;
    vector<string> myDate;
    int position = oldDate.find(' '), start = 0;
    while (position != string::npos)
    {
        myDate.push_back(oldDate.substr(start, position - start));
        start = position + 1;
        position = oldDate.find(' ', start);
    }
    
    myDate.push_back(oldDate.substr(start, min<int>(position, oldDate.size()) - start));
    date = (myDate.at(0)).substr(0, (myDate.at(0)).length() - 2);
    if (myDate.at(2).length() == 4)
    {
        myYear = std::stoi(myDate.at(2));
        if (myYear > 1900 && myYear < 2100)
        {
            if (myDate.at(1) == "Jan")
            {
                month = "1";
            }
            else if (myDate.at(1) == "Feb")
            {
                month = "2";
            }
            else if (myDate.at(1) == "Mar")
            {
                month = "3";
            }
            else if (myDate.at(1) == "Apr")
            {
                month = "4";
            }
            else if (myDate.at(1) == "May")
            {
                month = "5";
            }
            else if (myDate.at(1) == "Jun")
            {
                month = "6";
            }
            else if (myDate.at(1) == "Jul")
            {
                month = "7";
            }
            else if (myDate.at(1) == "Aug")
            {
                month = "8";
            }
            else if (myDate.at(1) == "Sep")
            {
                month = "9";
            }
            else if (myDate.at(1) == "Oct")
            {
                month = "10";
            }
            else if (myDate.at(1) == "Nov")
            {
                month = "11";
            }
            else
            {
                month = "12";
            }
            str_stream << myDate.at(2) << "-" << setfill('0') << setw(2) << month << "-" << setfill('0') << setw(2) << date;
            dateValue = str_stream.str();
            cout << dateValue;
        }
        else
            cout << "Invalid. Year is not between 1900 and 2100. Try again please" << endl;
    }
    else
        cout << "Year is invalid";
    return "";
}
