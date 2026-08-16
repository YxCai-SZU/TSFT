#include <stdbool.h>

/*@
    requires (1 <= (over) && (over) <= 10 &&
        1 <= (goal) && (goal) <= 1000);
    ensures \result == (over * 100 >= goal);
    assigns \nothing;
*/
bool func(int over, int goal) {
    int total = 0;
    int i = 0;
    
    /*@
        loop invariant 0 <= i <= over;
        loop invariant total == ((i) * 100);
        loop invariant (1 <= (over) && (over) <= 10 &&
        1 <= (goal) && (goal) <= 1000);
        loop assigns total, i;
    */
    while (i < over) {
        total += 100;
        i += 1;
    }
    
    //@ assert total == over * 100;
    return total >= goal;
}
