#ifndef GRADE_ACTIVITY_H
#define GRADE_ACTIVITY_H

// base class
// parent class
class GradeActivity{
    protected:        // change 'private' to 'protected' to let the child class have access to private members
        double score;
    public:
        GradeActivity();
        GradeActivity(double s);
        void setScore(double s);
        double getScore() const;
        virtual char getLetterGrade() const = 0;    // pure virtual --> GradeActivity
                                                    // becomes an abstract class

};

#endif