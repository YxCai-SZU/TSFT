#include <stdint.h>

/*@
    requires (1 <= (a) <= 20) && (1 <= (b) <= 20);
    ensures ((1 <= (a) <= 9) && (1 <= (b) <= 9)) ==> \result == a * b;
    ensures (!((1 <= (a) <= 9) && (1 <= (b) <= 9)) && ((1 <= (a) <= 9) || (1 <= (b) <= 9))) ==> \result == -1;
    ensures (!((1 <= (a) <= 9) && (1 <= (b) <= 9)) && !((1 <= (a) <= 9) || (1 <= (b) <= 9))) ==> \result == -1;
    assigns \nothing;
*/
int64_t func(int64_t a, int64_t b)
{
    int64_t result;
    //@ assert (1 <= (a) <= 20) && (1 <= (b) <= 20);
    
    if ((1 <= a && a <= 9) && (1 <= b && b <= 9))
    {
        //@ assert (1 <= (a) <= 9) && (1 <= (b) <= 9);
        //@ assert 1 <= a * b <= 81;
        result = a * b;
    }
    else
    {
        result = -1;
    }
    
    return result;
}
