#include <limits.h>

/*@
    requires (1 <= (A) <= 20 && 1 <= (B) <= 20);
    ensures \result == (((A) <= 9 && (B) <= 9) ? (A) * (B) : -1);
    assigns \nothing;
*/
int func(int A, int B)
{
    // Variable declarations at top of scope
    int result;

    //@ assert (1 <= (A) <= 20 && 1 <= (B) <= 20);

    if (A > 9)
    {
        //@ assert ((A) > 9 || (B) > 9);
        return -1;
    }

    if (B > 9)
    {
        //@ assert ((A) > 9 || (B) > 9);
        return -1;
    }

    //@ assert A <= 9 && B <= 9;
    //@ assert 1 <= A && A <= 9;
    //@ assert 1 <= B && B <= 9;
    //@ assert 1 <= A * B && A * B <= 81;

    result = A * B;
    //@ assert result == (((A) <= 9 && (B) <= 9) ? (A) * (B) : -1);
    return result;
}
