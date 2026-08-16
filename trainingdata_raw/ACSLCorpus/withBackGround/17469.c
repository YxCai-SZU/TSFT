#include <stdbool.h>

/*@
    predicate in_range_400_599(integer x) = 400 <= x && x <= 599;
    predicate in_range_600_799(integer x) = 600 <= x && x <= 799;
    predicate in_range_800_1999(integer x) = 800 <= x && x <= 1999;
*/

/*@
    requires 400 <= X && X < 2000;
    ensures \result >= 1 && \result <= 3;
    ensures \result == 1 ==> (X >= 400 && X <= 599);
    ensures \result == 2 ==> (X >= 600 && X <= 799);
    ensures \result == 3 ==> (X >= 800 && X <= 1999);
*/
int func(int X)
{
    int result;

    //@ assert 400 <= X && X < 2000;
    
    if (X >= 400 && X <= 599) {
        //@ assert in_range_400_599(X);
        result = 1;
    } else if (X >= 600 && X <= 799) {
        //@ assert in_range_600_799(X);
        result = 2;
    } else if (X >= 800 && X <= 1999) {
        //@ assert in_range_800_1999(X);
        result = 3;
    } else {
        //@ assert false;
        result = -1;
    }
    
    return result;
}
