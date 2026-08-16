#include <limits.h>

/*@
    requires (1 <= (A) && (A) <= 20 &&
        1 <= (B) && (B) <= 20);
    ensures ((A) > 9 || (B) > 9) ==> \result == -1;
    ensures ((A) <= 9 && (B) <= 9) ==> \result == ((A) * (B));
*/
int func(int A, int B)
{
    int result;

    //@ assert (1 <= (A) && (A) <= 20 &&         1 <= (B) && (B) <= 20);

    if (A > 9 || B > 9)
    {
        //@ assert ((A) > 9 || (B) > 9);
        result = -1;
    }
    else
    {
        //@ assert ((A) <= 9 && (B) <= 9);
        //@ assert A >= 1 && A <= 9;
        //@ assert B >= 1 && B <= 9;
        //@ assert ((A) * (B)) <= 81;
        result = A * B;
    }

    return result;
}
