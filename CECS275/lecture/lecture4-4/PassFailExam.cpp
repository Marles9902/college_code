#include "PassFailExam.h"

void PassFailExam::set(int questions, int missed){
    double numericScore;

    numQuestions = questions;
    numMissed = missed;

    pointsEach = 100.0 / numQuestions;
    numericScore = 100.0 - (missed * pointsEach);
    setScore(numericScore);
}