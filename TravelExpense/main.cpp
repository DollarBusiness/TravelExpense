#include <iostream>
#include <iomanip>

using namespace std;

int tripDays(){
    int days;
    cout << "Total number of days spent on the trip? ";
    cin >> days;
    while(days < 1){
        cout << "Please enter 1 or greater" << endl;
        cin >> days;
    }
}

double TimeOfDepart_Arrival(){
    double TOD; // Time of depart
    double TOD2; // Time of arrival
    cout << "Time of departure on first day? Use (00.00) format: ";
    cin >> TOD;
    while(TOD < 0 || TOD > 23.59){
        cout << "Please enter valid time frame, (00.00) format: ";
        cin >> TOD;
    }

    cout << "Time of arrival? Use (00.00) format: ";
    cin >> TOD2;
    while(TOD2 < 0 || TOD2 > 23.59){
        cout << "Please enter valid time frame, (00.00) format: ";
        cin >> TOD2;
    }
}

double RoundTripFair(){
    double RTF;
    cout << "Amount of round-trip fair? ";
    cin >> RTF;

}

double AmountOfRentalCars(){
    double ARC;
    cout << "Amount of rental cars? ";
    cin >> ARC;
    while(ARC < 0){
        cout << "Invalid input, try again: ";
        cin >> ARC;
    }
}

 // also need to calculate the expense $0.27 per mile driven (completed)
double MilesDriven(){
    string answer;
    double mi;
    double miSum;
    cout << "Was a private vehicle used? Y/N: ";
    cin >> answer;
    if(answer == "y" || answer == "Y"){
        cout << "Miles driven? ";
        cin >> mi;
        while(mi < 0){
            cout << "Invalid input, try again: ";
            cin >> mi;
        }
        miSum = (0.27 * mi);


        cout << setprecision(2) << fixed;
        cout << "Driving expense is: $" << miSum;

    }
}

double parkingFees(){ // (completed)
    static double fees;
    double total;
    string answer;
    cout << "Were there any parking fee's? Y/N: ";
    cin >> answer;
    if(answer == "y" || answer == "Y"){
        cout << "How much was the ticket? ";
        cin >> fees; // company allows up to $6 a day any more must be paid by employee
        while(fees < 0){
            cout << "Invalid input, try again: ";
            cin >> fees;
        }
        if(fees > 6){
            total = (fees - 6);
            cout << "Employee pays: $" << total << endl;
        }else{
            cout << "Company covered your ticket!" << fees;
        }
    }
}

double taxiFees(){ // (completed)
    double taxiFee;
    double total;
    string answer;
    cout << "Were there any taxi fee's? Y/N: ";
    cin >> answer;
    if(answer == "y" || answer == "Y"){
        cout << "How much was the taxi fee? ";
        cin >> taxiFee;
        while(taxiFee < 0){
            cout << "Invalid input, try again: ";
            cin >> taxiFee;
        }
        // company allows up to $10 per day for each taxi used. Any excess amount must be paid by employee
        if(taxiFee > 10){
           total = (taxiFee - 10);
           cout << "Employee pays: $" << total << endl;
        }else{
            cout << "Company paid your taxi fee!" << endl;
        }
    }
}

double conferOrSeminarRegFees(){ // (completed)
    string rFeesAnswer;
    double rFeeAmount;
    cout << "Were there any conference or seminar registration fees? Y/N: ";
    cin >> rFeesAnswer;
    if(rFeesAnswer == "y" || "Y"){
        cout << "How much were the fees? ";
        cin >> rFeeAmount;
        while (rFeeAmount < 0){
            cout << "Invalid input, try again: ";
            cin >> rFeeAmount;
        }
    }else{
        cout << endl;
    }
}

double hotelExpenses(){ // (completed)
    string answer;
    double price;
    double total;
    cout << "Were there any hotel expenses? Y/N: ";
    cin >> answer;
    if(answer == "y" || answer == "Y"){
        cout << "How much were the expenses? "; // company allows up to $90 per night for lodging, anything access employee pays
        cin >> price;
        while(price < 0){
            cout << "Invalid input, try again: ";
            cin >> price;
        }
        if(price > 90){
          total = (price - 90);
          cout << "Employee pays: $" << total << endl;
    }else{
        cout << "Company paid hotel expense!" << endl;
    }
 }
}

double mealTotal(double days, double depart, double arrive){
    double breaksfastFee;
    double lunchFee;
    double dinnerFee;

    // one day trip
    if(days == 1){
    if(depart < 7 && arrive >= 8){
        cout << "Breakfast amount: ";
        cin >> breaksfastFee;
    }
    if(depart < 12 && arrive >= 13){
        cout << "Lunch amount: ";
        cin >> lunchFee;
    }
    if(depart < 18 && arrive >= 19){
        cout << "Dinner amount: ";
        cin >> dinnerFee;
    }
 }
    // if not one day trip, get meal amount allowed for the first day
    if(days > 1 && depart >= 18){
        cout << "No meals allowed!" << endl;
    }
    else if(days > 1 && depart <= 7){
        cout << "Breakfast amount: ";
        cin >> breaksfastFee;
    }
    else if(days > 1 && depart >= 12){
        cout << "Lunch amount: ";
        cin >> lunchFee;
    }
    else{
        cout << "Dinner amount: ";
        cin >> dinnerFee;
    }
    // get meal amounts for the 2nd day through the next-to-last day using for loop
}



int main()
{
    int days = 0;
    double ArrivalTime;
    double DepartureTime;
    double carRentalFee;
    double mi;
    double RTF;
    double airfairFee;
    double vechileExpense;
    double privateCarMilage;
    double fees;
    double taxiFee;
    double rFeeAmount;
    double ST;              // Overall spent total
    double allowedTotal;    //overall allowed cost
    double mealTotal;
    double total;
    double allowedParking;
    double allowedTaxiFee;
    double hotelFee;
    double allowedHotelFee;
    double hotelFeeTotal;
    double allowedBreaksfastFee;
    double allowedLunchFee;
    double allowedDinnerFee;
    double breaksfastFee;
    double lunchFee;
    double dinnerFee;
    double allowedMealTotal;
    double spentMealTotal;
    string firstName;
    string lastName;

    cout << "Expense Report" << endl;
    cout << "---------------" << endl;
    cout << endl;

    cout << "Employee Name: ";
    cin >> firstName >> lastName;
    cout << endl;

    tripDays();
    TimeOfDepart_Arrival();
    cout << endl;

    cout << "TRAVEL" << endl;
    cout << "-------" << endl;
    RoundTripFair();
    AmountOfRentalCars();
    MilesDriven();
    cout << endl;

    cout << endl;
    cout << "FEE'S" << endl;
    cout << "------" << endl;

    parkingFees();
    taxiFees();
    allowedTaxiFee = 10 * days;
    conferOrSeminarRegFees();
    hotelExpenses();
    cout << endl;

    cout << "MEAL" << endl;
    cout << "-----" << endl;
    allowedBreaksfastFee = 9.00 * days;
    allowedLunchFee = 12.00 * days;
    allowedDinnerFee = 16.00 * days;
    allowedMealTotal = allowedBreaksfastFee + allowedLunchFee + allowedDinnerFee;
    mealTotal = breaksfastFee + lunchFee + dinnerFee;
    //getMealAmount();
    cout << endl;

    // cal total for all expenses
    allowedTotal = allowedBreaksfastFee + allowedDinnerFee + allowedLunchFee + allowedParking;

    // Display total for travel


    return 0;
}
