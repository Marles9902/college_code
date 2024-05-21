#include "PassFailActivity.h"

char PassFailActivity::getLetterGrade() const{
    char letterGrade;

    if(score >= minPassingScore){
        letterGrade = 'P';
    }else{
        letterGrade = 'F';
    }

    return letterGrade;
}