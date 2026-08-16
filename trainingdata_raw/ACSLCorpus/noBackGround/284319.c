#include <stdint.h>

/*@
    requires (1 <= (A) && (A) <= 9 && 1 <= (B) && (B) <= 9);
    ensures (((A) + (B)) >= 10 ==> \result == -1);
    ensures (((A) + (B)) < 10 ==> \result == ((A) + (B)));
*/
int64_t func(int64_t A, int64_t B)
{
    int64_t sum;
    //@ assert (1 <= (A) && (A) <= 9 && 1 <= (B) && (B) <= 9);
    sum = A + B;
    
    if (sum >= 10)
    {
        //@ assert ((((A)) + ((B))) >= 10);
        //@ assert ((A) + (B)) >= 10;
        return -1;
    }
    else
    {
        //@ assert ((((A)) + ((B))) < 10);
        //@ assert ((A) + (B)) < 10;
        return sum;
    }
}
