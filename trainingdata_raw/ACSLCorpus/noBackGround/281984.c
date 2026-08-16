#include <limits.h>

/*@
    requires (0 <= (a) && 0 <= (b) && 0 <= (c) &&
        1 <= (k) && (k) <= (a) + (b) + (c) &&
        (a) + (b) + (c) <= 2000000000);
    ensures -c <= \result && \result <= a;
    assigns \nothing;
*/
int func(int a, int b, int c, int k)
{
    int ka = 0;
    int kb = 0;
    int kc = 0;

    //@ assert (0 <= (ka) && (ka) <= (a));
    //@ assert (0 <= (kc) && (kc) <= (c));

    if (k <= a)
    {
        ka = k;
        //@ assert (0 <= (ka) && (ka) <= (a));
    }
    else
    {
        ka = a;
        int rem = k - a;
        //@ assert (0 <= (ka) && (ka) <= (a));

        if (rem <= b)
        {
            kb = rem;
            //@ assert (0 <= (kc) && (kc) <= (c));
        }
        else
        {
            kb = b;
            kc = rem - b;
            //@ assert (0 <= (kc) && (kc) <= (c));
        }
    }

    //@ assert (0 <= (ka) && (ka) <= (a));
    //@ assert (0 <= (kc) && (kc) <= (c));
    //@ assert -c <= ka - kc;

    return ka - kc;
}
