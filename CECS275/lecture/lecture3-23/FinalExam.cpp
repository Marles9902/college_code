#include <iostream>
#include "FinalExam.h"

using namespace std;

FinalExam::FinalExam(){
    numOfQuestions = 0;
    pointEach = 0.0;
    numMissed = 0;
}

FinalExam::FinalExam(int numQuestions, int missed){
    set(numQuestions, missed);
}

void FinalExam::set(int numQuestions, int missed){
    double score;

    numOfQuestions = numQuestions;
    numMissed = missed;

    pointEach = 100.0 / numQuestions;

    score = 100.0 - (missed * pointEach);

    setScore(score);
}

// function overriding (it has to be the exact same as the parent class such as same parameters etc.)
void FinalExam::setScore(double s){
    cout << "CALLING setScore from FinalExam" << endl;
    GradeActivity::setScore(s);             // how to call from parent
}

int FinalExam::getNumQuestions() const{
return numOfQuestions;
}

double FinalExam::getPointsEach() const{
    return pointEach;
}

int FinalExam::getNumMissed() const{
    return numMissed;
}