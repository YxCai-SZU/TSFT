#include <stddef.h>

/*@
    requires (2 <= (n) && (n) <= 100 &&
        (w) >= 1 && (w) <= 50 &&
        \valid((s2) + (0 .. (n)-1)) &&
        \forall integer i; 0 <= i < (n) ==> 1 <= (s2)[i] && (s2)[i] <= 50);
    assigns \nothing;
    ensures \result >= 0;
*/
int func(size_t n, int w, int *s2)
{
    int last1 = 0;
    int last0;
    int choice0;
    int choice1 = 0;
    int max_val;

    //@ assert n >= 2 && n <= 100;
    //@ assert w >= 1 && w <= 50;
    
    if (n > 1)
    {
        //@ assert s2[n-2] >= 1 && s2[n-2] <= 50;
        last1 = s2[n - 2];
    }

    //@ assert s2[n-1] >= 1 && s2[n-1] <= 50;
    last0 = s2[n - 1];

    //@ assert last0 - w >= -49 && last0 - w <= 49;
    choice0 = (last0 - w < 0) ? -(last0 - w) : (last0 - w);
    //@ assert choice0 >= 0;

    if (n > 1)
    {
        //@ assert last1 - last0 >= -49 && last1 - last0 <= 49;
        choice1 = (last1 - last0 < 0) ? -(last1 - last0) : (last1 - last0);
        //@ assert choice1 >= 0;
    }

    max_val = choice0;
    //@ assert max_val >= 0;

    if (n > 1)
    {
        //@ assert choice1 >= 0;
        if (choice1 > max_val)
        {
            max_val = choice1;
        }
        //@ assert max_val >= 0;
    }

    //@ assert max_val >= 0;
    return max_val;
}
