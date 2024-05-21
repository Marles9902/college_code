#include <iostream> 
#include <iomanip>
#include "GradeActivity.h"
#include "FinalExam.h"

using namespace std;

int main(){
    // double testScore = 75.0;
    // GradeActivity test;

    // test.setScore(testScore);
    // cout << "THE GRADE IS: " << test.getLetterGrade() << endl;

    int questions = 10;
    int missed = 3;

    FinalExam test(questions, missed);

    cout << fixed << showpoint << setprecision(2);
    cout << "Point per question: " << test.getPointsEach() << endl;
    cout << "The exam score: " << test.getScore() << endl;
    cout << "The exam grade: " << test.getLetterGrade() << endl;

    return 0;
}