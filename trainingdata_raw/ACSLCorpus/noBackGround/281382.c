#include <limits.h>

/*@
    requires (-100 <= (A) <= 100) && (-100 <= (B) <= 100);
    ensures \result == ((A) + (B)) || \result == ((A) - (B)) || \result == ((A) * (B));
    ensures \result >= ((A) + (B));
    ensures \result >= ((A) - (B));
    ensures \result >= ((A) * (B));
    assigns \nothing;
*/
int func(int A, int B)
{
    int sum;
    int diff;
    int prod;
    int ans;

    //@ assert (-100 <= (A) <= 100) && (-100 <= (B) <= 100);
    sum = A + B;
    diff = A - B;
    //@ assert (-100 <= (A) <= 100) && (-100 <= (B) <= 100);
    prod = A * B;
    ans = sum;

    //@ assert ans == ((A) + (B));
    if (diff > ans)
    {
        ans = diff;
        //@ assert ans == ((A) - (B));
    }
    //@ assert ans >= ((A) + (B)) && ans >= ((A) - (B));
    if (prod > ans)
    {
        ans = prod;
        //@ assert ans == ((A) * (B));
    }
    //@ assert ans >= ((A) + (B)) && ans >= ((A) - (B)) && ans >= ((A) * (B));
    //@ assert ans == ((A) + (B)) || ans == ((A) - (B)) || ans == ((A) * (B));
    return ans;
}
