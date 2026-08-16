#include <limits.h>

/*@
    requires (1 <= (N) <= 20 &&
        1 <= (A) <= 100 &&
        1 <= (B) <= 2000);
    ensures \result == ((N) * (A)) || \result == B;
    ensures \result <= B;
    assigns \nothing;
*/
int func(int N, int A, int B)
{
    // Variable declarations at scope top
    int product_val;
    int result;

    // Precondition validation
    //@ assert (1 <= (N) <= 20 &&         1 <= (A) <= 100 &&         1 <= (B) <= 2000);

    // Overflow prevention check
    //@ assert ((N) * (A)) <= INT_MAX;

    product_val = N * A;

    if (product_val < B)
    {
        result = product_val;
        //@ assert result == ((N) * (A));
    }
    else
    {
        //@ assert ((N) * (A)) >= B;
        result = B;
        //@ assert result == B;
    }

    // Postcondition verification
    //@ assert result == ((N) * (A)) || result == B;
    //@ assert result <= B;

    return result;
}
