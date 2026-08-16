#include <limits.h>

/*@
    requires ((pupils_in_class_1) >= 0 && (pupils_in_class_2) >= 0 && (pupils_in_class_3) >= 0 && (pupils_in_class_4) >= 0 && (pupils_in_class_5) >= 0);
    requires ((pupils_in_class_1) + (pupils_in_class_2) + (pupils_in_class_3) + (pupils_in_class_4) + (pupils_in_class_5)) <= INT_MAX;
    ensures \result >= 0;
    ensures \result == ((pupils_in_class_1) + (pupils_in_class_2) + (pupils_in_class_3) + (pupils_in_class_4) + (pupils_in_class_5));
*/
int count_pupils(int pupils_in_class_1, int pupils_in_class_2, int pupils_in_class_3,
                 int pupils_in_class_4, int pupils_in_class_5)
{
    int total_pupils;
    
    //@ assert ((pupils_in_class_1) >= 0 && (pupils_in_class_2) >= 0 && (pupils_in_class_3) >= 0 && (pupils_in_class_4) >= 0 && (pupils_in_class_5) >= 0);
    //@ assert ((pupils_in_class_1) + (pupils_in_class_2) + (pupils_in_class_3) + (pupils_in_class_4) + (pupils_in_class_5)) <= INT_MAX;
    
    //@ assert pupils_in_class_1 + pupils_in_class_2 <= INT_MAX;
    //@ assert pupils_in_class_1 + pupils_in_class_2 + pupils_in_class_3 <= INT_MAX;
    //@ assert pupils_in_class_1 + pupils_in_class_2 + pupils_in_class_3 + pupils_in_class_4 <= INT_MAX;
    
    total_pupils = pupils_in_class_1 + pupils_in_class_2 + pupils_in_class_3 + pupils_in_class_4 + pupils_in_class_5;
    
    return total_pupils;
}
