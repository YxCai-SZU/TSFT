#include <stdint.h>

/*@
    requires (1 <= (A) && (A) <= 1000 &&
        1 <= (B) && (B) <= 1000 &&
        (A) + (B) <= (X) && (X) <= 10000);
    ensures 0 <= \result <= X;
    ensures \result <= A;
*/
int64_t func(int64_t X, int64_t A, int64_t B)
{
    int64_t result;
    int64_t ans;

    //@ assert (1 <= (A) && (A) <= 1000 &&         1 <= (B) && (B) <= 1000 &&         (A) + (B) <= (X) && (X) <= 10000);

    if (X > A)
    {
        if (A + B >= X)
        {
            result = X - A;
        }
        else
        {
            result = 0;
        }
    }
    else
    {
        result = 0;
    }

    //@ assert result == ((X) > (A) ?             ((A) + (B) >= (X) ? (X) - (A) : 0)         : 0);

    if (X - result < A)
    {
        ans = X - result;
    }
    else
    {
        ans = A;
    }

    //@ assert ans == ((X) - (((X)) > ((A)) ?             (((A)) + ((B)) >= ((X)) ? ((X)) - ((A)) : 0)         : 0) < (A) ?              (X) - (((X)) > ((A)) ?             (((A)) + ((B)) >= ((X)) ? ((X)) - ((A)) : 0)         : 0)          : (A));
    //@ assert 0 <= ans <= X;
    //@ assert ans <= A;

    return ans;
}
