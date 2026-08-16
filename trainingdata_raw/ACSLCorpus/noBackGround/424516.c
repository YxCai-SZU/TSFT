#include <stdbool.h>

/*@
    requires (1 <= (A) <= 100 && 1 <= (B) <= 100);
    ensures \result >= 0 && \result <= A;
    assigns \nothing;
*/
int func(int A, int B)
{
    int ans;
    int result;

    ans = A - B * 2;

    //@ assert (1 <= (A) <= 100 && 1 <= (B) <= 100);
    //@ assert ans == ((A) - (B) * 2);

    if (ans < 0)
    {
        result = 0;
    }
    else
    {
        result = ans;
    }

    //@ assert result == ((((A)) - ((B)) * 2) < 0 ? 0 : (((A)) - ((B)) * 2));
    //@ assert result >= 0 && result <= A;

    return result;
}
