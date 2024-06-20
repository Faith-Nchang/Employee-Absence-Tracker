/*
  Employee Absence Tracker
*/
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

ofstream outputFile;

const int MIN_NUMBER_Of_EMPLOYEES = 1,
          MIN_EMPLOYEE_ID = 1,
          MAX_EMPLOYEE_ID = 9999,
          MIN_DAY_ABSENT = 0,
          MAX_DAY_ABSENT = 365;

// prototype of the functions
int get_total_employees(); 
int calculate_total_days_absented(ofstream &, int); 
double compute_average_days_absented (int, int);

int main() 
{
  cout << "**********************************************************************************\n";
  cout << setw(75) << "Calculate the average number of times a company's employees are absent\n";
  cout << "**********************************************************************************\n";
 // opens the file "Absences.txt" where data will be written
  outputFile.open("Absences.txt");

  if(outputFile.fail()){
    cout << "Error opening the file\n";
  }
  else{
    //writes to the Absences.txt file
    outputFile << "EMPLOYEE ABSENCE REPORT\n";
    outputFile << "Employee Id " << setw(15) << "days absent\n";

    // stores the total # of employees in the company
    int totalNumberOfEmployees = get_total_employees();
    //stores the # of days of absences by all employees
    int totalNumberOfAbsences = calculate_total_days_absented(outputFile, totalNumberOfEmployees);
    //stores the average of all the absences
    double averageNumberOfAbsences = compute_average_days_absented(totalNumberOfEmployees, totalNumberOfAbsences);

  // writes the total # of days and the average # of days absent to the Absences.txt file
    outputFile << "The " << totalNumberOfEmployees << " employees were absent a total of " << totalNumberOfAbsences <<" days.\n";
    outputFile << setprecision(1) << fixed << showpoint <<"The average number of days absent is " << averageNumberOfAbsences <<" days.\n\n";
    outputFile << "Programmer: Faith Nchang\n";

    //closes the file
    outputFile.close();

  }
  
  cout << "\nThank you for testing my program.\n";  
  cout << "Programmer: Faith Nchang\n";

  return 0;

}

//gets the number of employees in the company
int get_total_employees()
{
  int numOfEmployees; //total employees in the company
  cout << "Please enter the number of employees in the company: ";
  cin >> numOfEmployees;
  cin.ignore(20, '\n');
  //ensures # of employes is not <1
  while (numOfEmployees < MIN_NUMBER_Of_EMPLOYEES){
    cout << "Number of employees cannot be less than 1.\n"
          << "Please re-enter the number of employees: ";
    cin >> numOfEmployees;
    cin.ignore(20, '\n');
  }
  return numOfEmployees;
}

/*computes the total number of missed days of all employees
  Display and save each employee number (ID) and number of days missed to an output file
*/
int calculate_total_days_absented(ofstream& outputFile, int numOfEmployees)
{
  int employeeId, //stores the employee's id
      numOfDaysAbsentPerEmployee,
      totalNumberOfDaysAbsent = 0;//run total of the total # of employees

  
  for(int employee = 1; employee <= numOfEmployees; employee++)
  {
    // ask for the employee id
    do {
      cout << "Please enter the employee Id #" << employee <<": ";
      cin >> employeeId;
      cin.ignore(20, '\n'); //if the user inputs a floating point

      // ensures the employee id is not < 1 and not > 9999
      if (employeeId < MIN_EMPLOYEE_ID || employeeId > MAX_EMPLOYEE_ID)
      {
        cout << "An employee Id must be within the range of " << MIN_EMPLOYEE_ID 
              << " and " << MAX_EMPLOYEE_ID << endl;
      }
    } while (employeeId < MIN_EMPLOYEE_ID || employeeId > MAX_EMPLOYEE_ID);

    // ask for the number of days absent by each employee
    do {
      cout << "Please enter the number of days this employee was absent: ";
      cin >> numOfDaysAbsentPerEmployee;
      cin.ignore(20, '\n'); //if the user inputs a floating point

      //when the user enters a value out of the range 0-365 
      if (numOfDaysAbsentPerEmployee < MIN_DAY_ABSENT || numOfDaysAbsentPerEmployee > MAX_DAY_ABSENT)
      {
        cout << "Number of days absent must be within the range of " << MIN_DAY_ABSENT
             << " and " << MAX_DAY_ABSENT <<endl;
      }
        
    } while (numOfDaysAbsentPerEmployee < MIN_DAY_ABSENT || numOfDaysAbsentPerEmployee > MAX_DAY_ABSENT);
    
    //computes the running total of the total days absent of all employees
    totalNumberOfDaysAbsent += numOfDaysAbsentPerEmployee;
    //writes each employee id and the # of days absent to the Absences.txt file
    outputFile << setw(7) << employeeId << setw(15) << numOfDaysAbsentPerEmployee << endl;
    
  }
  //prints a new line in the absences.txt file
  outputFile << endl;
  // returns the grand total of the number days absent for all the employees
  return totalNumberOfDaysAbsent;
}

//computes the average number of absences for all the employees
double compute_average_days_absented (int numOfEmployees, int daysAbsent)
{
  //computes the average absences in floating point
  double avgNumberOfAbsentDays = static_cast<double>(daysAbsent) / numOfEmployees;
  return avgNumberOfAbsentDays;
}
