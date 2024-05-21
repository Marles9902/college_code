#ifndef PASSFAILACTIVITY_H
#define PASSFAILACTIVITY_H

#include "GradeActivity.h"

class PassFailActivity : public GradeActivity{
    protected:      // gives permission to a child 
        double minPassingScore;
    public:
        PassFailActivity() : GradeActivity(){
            minPassingScore = 0.0;
        }
        PassFailActivity(double mps) : GradeActivity(){
            minPassingScore = mps;
        }
        void setMinPassingScore(double mps){
            minPassingScore = mps;
        }
        double getMinPassingScore() const{
            return minPassingScore;
        }
        virtual char getLetterGrade() const;
};

#endif