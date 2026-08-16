#include <stdbool.h>

/*@
    requires 1 <= a && a <= 20;
    requires 1 <= b && b <= 20;
    ensures (1 <= (a) && (a) <= 9 && 1 <= (b) && (b) <= 9) ==> \result == a * b;
    ensures !(1 <= (a) && (a) <= 9 && 1 <= (b) && (b) <= 9) ==> \result == -1;
    assigns \nothing;
*/
int func(int a, int b)
{
    int result;
    
    //@ assert 1 <= a && a <= 20;
    //@ assert 1 <= b && b <= 20;
    
    if (1 <= a && a <= 9 && 1 <= b && b <= 9) {
        //@ assert (1 <= (a) && (a) <= 9 && 1 <= (b) && (b) <= 9);
        //@ assert a * b <= 81;
        result = a * b;
    } else {
        result = -1;
    }
    
    return result;
}
