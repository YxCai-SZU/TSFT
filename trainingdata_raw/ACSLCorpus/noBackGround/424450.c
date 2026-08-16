#include <limits.h>

/*@
    requires (-100 <= (A) <= 100) && (-100 <= (B) <= 100) && (-100 <= (C) <= 100) && (-100 <= (D) <= 100);
    ensures \result == A + C || \result == A + D || 
            \result == B + C || \result == B + D;
    assigns \nothing;
*/
int func(int A, int B, int C, int D)
{
    int max1;
    int max2;
    int max3;
    int max4;
    int max_val;

    //@ assert -200 <= A + C <= 200;
    max1 = A + C;

    //@ assert -200 <= A + D <= 200;
    max2 = A + D;

    //@ assert -200 <= B + C <= 200;
    max3 = B + C;

    //@ assert -200 <= B + D <= 200;
    max4 = B + D;

    max_val = max1;
    if (max2 > max_val)
    {
        max_val = max2;
    }
    if (max3 > max_val)
    {
        max_val = max3;
    }
    if (max4 > max_val)
    {
        max_val = max4;
    }

    //@ assert max_val == max1 || max_val == max2 || max_val == max3 || max_val == max4;
    return max_val;
}
