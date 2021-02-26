/*
 * Project1.cpp
 *
 *  Date: 1/24/2021
 *  Author: Michelle Hitchcock
 */

#include <iostream>
#include<iomanip>
using namespace std;

// creating a function for the clock
 void PrintOutClock(int hour12hr, int min12hr, int sec12hr, int hour24hr,int min24hr, int sec24hr, string dividingSpace){

     cout << right << setw(29) << setfill('*' )<< "*"; // printing out top line of * for both clocks
     cout << dividingSpace << right << setw(29) << setfill('*' )<< "*" << endl;
     cout << "*" << dividingSpace << "12-Hour Clock" << dividingSpace << "*"; // printing words for 12 hour clock
     cout << dividingSpace << "*" << dividingSpace << "24-Hour Clock" << dividingSpace << "*" << endl; //24hr words

     cout << "*" << dividingSpace + "  "<< setw(2)<< setfill('0')<< hour12hr << ":"; // 12 hour clock printing
     cout << min12hr << ":" << setw(2)<< setfill('0')<< sec12hr << " PM"; //12 hour clock printing
     cout << dividingSpace << "*"; //12 hour clock printing. used setfill to get 0's to show. used same method for 24 hr.
     cout << dividingSpace << "*" << dividingSpace <<  hour24hr << ":" << min24hr << ":" << setw(2);
     cout << setfill('0') << sec24hr << " PM"; // 24 hr printing
     cout << dividingSpace + "  " << "*" << endl; //24 hour time print statment

     cout << right << setw(29) << setfill('*' )<< "*"; // printing out bottom line of *
     cout << dividingSpace << right << setw(29) << setfill('*' )<< "*" << endl;

 }
 // creating a function to print the menue
 void PrintMenu(string dividingSpace){
     cout << endl << dividingSpace + dividingSpace + "  " << right << setw(33) << setfill('*' )<< "*" << endl;
     cout << dividingSpace + dividingSpace << "  *" << " 1-Add One Hour" << dividingSpace + dividingSpace << "  *" << endl;
     cout << dividingSpace + dividingSpace << "  *" << " 2-Add One Minute" << dividingSpace + dividingSpace << "*" << endl;
     cout << dividingSpace + dividingSpace << "  *" << " 3-Add One Second" << dividingSpace + dividingSpace << "*" << endl;
     cout << dividingSpace + dividingSpace << "  *" << " 4-Exit Program" << dividingSpace + dividingSpace << "  *" << endl;
     cout << dividingSpace + dividingSpace + "  " << right << setw(33) << setfill('*' )<< "*" << endl;
 }

int main() {

    int hour12hrClock = 03;    //setting variables for 12 hr clock
    int min12hrClock = 22;
    int sec12hrClock = 01;

    int hour24hrClock = 15;  //setting variables for 24 hour clock
    int min24hrClock = 22;   //will be able to call these later in order to change the time
    int sec24hrClock = 01;
    string dividingSpace = "       "; //variable for spaces, in order to make formatting cleaner.
    int answer; //will be used later for user input

    //calling clock functon
    PrintOutClock(hour12hrClock, min12hrClock, sec12hrClock, hour24hrClock, min24hrClock, sec24hrClock, dividingSpace);
    //calling function to print menu
    PrintMenu(dividingSpace);

    cin >> answer; //getting first user input in order to start the loop.

while( (answer == 1) || (answer == 2) || (answer == 3) ) { // while loop used to allow user input

    if (answer == 1){
        hour12hrClock += 1;
        hour24hrClock += 1;
    }
    else if (answer == 2){
        min12hrClock += 1;          //if and if else statments used to see
        min24hrClock += 1;          // which input was used.
    }
    else if (answer == 3){
        sec12hrClock += 1;
        sec24hrClock += 1;
    }

    if(hour12hrClock == 13){ // if statment to keep clock in 12 hour time range
        hour12hrClock = 1;
    }
    if(min12hrClock == 60){ //if statment for minute
        min12hrClock = 0; //when minutes hit 60 reassign to 0
        hour12hrClock +=1; //add one to hour
    }
    if(sec12hrClock == 60){ //if statment for seconds
        sec12hrClock = 0; //when seconds hit 60 re-assign to 0
        min12hrClock += 1; //add 1 to minutes
    }
    if(hour24hrClock == 25){ //checking if 24 hr clock is over 24hrs
        hour24hrClock = 1;
    }

    if(min24hrClock == 60){ //chekcing if 24hr min is over 60
        min24hrClock = 0;  //when minutes hit 60 reassign to 0
        hour24hrClock +=1; //add one to hour
    }
    if(sec24hrClock == 60){ //checking if 24hr min is over 60
        sec24hrClock = 0; //when seconds hit 60 re-assign to 0
        min24hrClock += 1; //add one to minutes
    }

    // printing the clock by calling the function

    PrintOutClock(hour12hrClock, min12hrClock, sec12hrClock, hour24hrClock, min24hrClock, sec24hrClock, dividingSpace);
    cin >> answer;

}

    return 0;
}
