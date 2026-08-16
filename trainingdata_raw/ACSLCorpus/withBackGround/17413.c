#include <stdbool.h>
#include <string.h>

typedef enum {
    Preschool,
    Elementary,
    MiddleSchool,
    HighSchool,
    College
} EducationalLevelTag;

typedef struct {
    EducationalLevelTag tag;
    union {
        struct { unsigned char age; } preschool;
        struct { unsigned char grade; } elementary;
        struct { unsigned char grade; } middle_school;
        struct { unsigned char grade; } high_school;
        struct { char* major; unsigned char year; } college;
    } data;
} EducationalLevel;

/*@ predicate is_college_student(EducationalLevel e) = 
        e.tag == College; */

/*@ lemma check_college_student: 
        \forall EducationalLevel p; 
        is_college_student(p) ==> 
        p.tag != HighSchool && 
        p.tag != MiddleSchool && 
        p.tag != Elementary && 
        p.tag != Preschool; */

int main() {
    EducationalLevel p;
    p.tag = College;
    p.data.college.major = "Computer Science";
    p.data.college.year = 3;
    
    //@ assert is_college_student(p);
    
    return 0;
}
