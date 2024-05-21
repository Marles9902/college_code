#include <iostream>
#include "GradeActivity.h"

using namespace std;

GradeActivity::GradeActivity(){
    score = 0.0;
}

GradeActivity::GradeActivity(double s){
    score = s;
}

void GradeActivity::setScore(double s){
    cout << "CALLING from parent" << endl;
    score = s;
}
double GradeActivity::getScore() const{
    return score;
}
char GradeActivity::getLetterGrade() const{
    if(score >= 90.0){
        return 'A';
    }else if(score >= 80.0){
        return 'B';
    }else if(score >= 70.0){
        return 'C';
    }else if(score >= 60.0){
        return 'D';
    }else{
        return 'F';
    }
}