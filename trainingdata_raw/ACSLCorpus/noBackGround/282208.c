#include <stdbool.h>

/*@
    requires (0 <= (a) < (b) < (c) < (d) < (e) < 0x80000000);
    requires ((k) >= 0 && (k) < 0x80000000);
    ensures \result == (((e) - (a)) <= k);
    assigns \nothing;
*/
bool func(int a, int b, int c, int d, int e, int k)
{
    int distance;
    int max_val;
    int min_val;
    int range;
    bool result;

    //@ assert e >= a;
    //@ assert e - a >= 0;

    distance = e - a;
    //@ assert distance == e - a;

    max_val = a > b ? a : b;
    max_val = max_val > c ? max_val : c;
    max_val = max_val > d ? max_val : d;
    max_val = max_val > e ? max_val : e;

    min_val = a < b ? a : b;
    min_val = min_val < c ? min_val : c;
    min_val = min_val < d ? min_val : d;
    min_val = min_val < e ? min_val : e;

    range = max_val - min_val;

    if (distance <= k)
    {
        result = true;
    }
    else
    {
        //@ assert distance > k;
        result = false;
    }

    return result;
}
