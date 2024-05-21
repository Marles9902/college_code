#ifndef FINAL_EXAM_H
#define FINAL_EXAM_H

#include "GradeActivity.h"

// derive class
// child class
// inheritance (inherit stuff from base class) is called "is a" relationship
// FinalExam "is a" GradeActivity
class FinalExam : public GradeActivity{
    private:
        int numOfQuestions;
        double pointEach;
        int numMissed;
    public:
        FinalExam();
        FinalExam(int numQuestions, int missed);
        void set(int numQuestions, int missed);
        void setScore(double s);
        int getNumQuestions() const;
        double getPointsEach() const;
        int getNumMissed() const;
};

#endif