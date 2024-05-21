#include "GradeActivity.h"
#include "PassFailActivity.h"
#include "PassFailExam.h"

#include <iostream>
#include <iomanip>
#include <vector>


using namespace std;

void displayGrade(const GradeActivity& activity){
    cout << fixed << showpoint << setprecision(2);
    // cout << "Point per question: " << test.getPointsEach() << endl;
    cout << "The exam score: " << activity.getScore() << endl;
    cout << "The exam grade: " << activity.getLetterGrade() << endl;
}

double divide(int num1, int num2){
    if(num2 == 0){
        string exceptionString = "ERROR: Divided by 0";
        throw exceptionString;
    }
    return double(num1) / num2;
}

int main()
{
    int num1, num2;
    double quotient;
    cout << "Enter two numbers: ";
    cin >> num1 >> num2;

    try{
        quotient = divide(num1, num2);
        cout << "The quotient is " << quotient << endl;
    }catch(string exceptionString){
        cout << exceptionString << endl;
    }
    cout << "DONE" << endl;

    // // polymorphism
    // GradeActivity *gActivity = new PassFailActivity(70);    // dynamic binding
    // gActivity->setScore(80);
    // displayGrade(*gActivity);

    // // vector example
    // vector<GradeActivity*> gradeActivities;
    // gradeActivities.push_back(new PassFailExam(100, 10, 70));
    // gradeActivities.push_back(new PassFailExam(100, 25, 80));
    
    // for(GradeActivity* gc : gradeActivities){
    //     displayGrade(*gc);
    // }

    // // take out pure virtual and reference to work
    // PassFailExam exam(100, 25, 70);
    // displayGrade(exam);

    // PassFailActivity activity(70);
    // activity.setScore(80);
    // displayGrade(activity);

    // int questions = 10;
    // int missed = 3;
    // double minPassingScore = 70.0;

    // PassFailExam test(questions, missed, minPassingScore);

    // cout << fixed << showpoint << setprecision(2);
    // cout << "Point per question: " << test.getPointsEach() << endl;
    // cout << "The exam score: " << test.getScore() << endl;
    // cout << "The exam grade: " << test.getLetterGrade() << endl;

    return 0;
}