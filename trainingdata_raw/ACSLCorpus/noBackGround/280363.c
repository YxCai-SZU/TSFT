#include <stdint.h>

/*@
    requires (1 <= (a) <= 20 && 1 <= (b) <= 20);
    ensures (a <= 9 && b <= 9) ==> \result == a * b;
    ensures (a > 9 || b > 9) ==> \result == -1;
    assigns \nothing;
*/
int64_t func(int64_t a, int64_t b)
{
    int64_t result;
    //@ assert (1 <= (a) <= 20 && 1 <= (b) <= 20);
    
    if (a <= 9 && b <= 9)
    {
        //@ assert 1 <= a <= 9 && 1 <= b <= 9;
        //@ assert 1 <= a * b <= 81;
        result = a * b;
    }
    else
    {
        //@ assert a > 9 || b > 9;
        result = -1;
    }
    
    //@ assert result == (((a) <= 9 && (b) <= 9) ? (a) * (b) : -1);
    return result;
}
