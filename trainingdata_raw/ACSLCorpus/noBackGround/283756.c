#include <limits.h>

/*@
    requires ((a) >= 0 && (b) >= 0 && (c) >= 0 && 1 <= (k) && (k) <= (a) + (b) + (c));
    ensures \result >= -c;
    ensures \result <= a;
    ensures \result == ((k) < (a) ? (k) : ((k) < (a) + (b) ? (a) : (a) - ((k) - (a) - (b))));
*/
int func(int a, int b, int c, int k)
{
    int result = 0;
    int remaining_k = k;

    //@ assert ((a) >= 0 && (b) >= 0 && (c) >= 0 && 1 <= (k) && (k) <= (a) + (b) + (c));
    
    if (remaining_k < a)
    {
        result += remaining_k;
        //@ assert result == remaining_k;
    }
    else
    {
        result += a;
        remaining_k -= a;
        //@ assert result == a;
        //@ assert remaining_k == k - a;

        if (remaining_k < b)
        {
            //@ assert result == a;
        }
        else
        {
            result -= remaining_k - b;
            //@ assert result == a - (remaining_k - b);
        }
    }

    //@ assert result >= -c;
    //@ assert result <= a;
    return result;
}
