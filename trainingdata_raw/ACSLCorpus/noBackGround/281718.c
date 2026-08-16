#include <stdbool.h>

/*@
    requires 1 <= A <= 16;
    requires 1 <= B <= 16;
    requires A + B <= 16;
    ensures \result == true <==> (A <= 8 && B <= 8);
*/
bool func(int A, int B)
{
    bool ans;
    ans = false;

    if (A <= 8 && B <= 8)
    {
        ans = true;
        //@ assert ans == true;
    }
    else
    {
        ans = false;
        //@ assert ans == false;
    }

    return ans;
}
