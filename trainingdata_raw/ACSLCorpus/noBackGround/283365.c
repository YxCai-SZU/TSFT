#include <limits.h>

/*@
    requires (1 <= (a) <= 10000) && (1 <= (b) <= 10000) && (1 <= (c) <= 10000) && (1 <= (d) <= 10000);
    ensures \result == ((a) + (c)) || \result == ((a) + (d)) || 
            \result == ((b) + (c)) || \result == ((b) + (d));
    ensures 1 <= \result <= 20000;
*/
int func(int a, int b, int c, int d)
{
    int sa = a;
    int sb = b;
    int sc = c;
    int sd = d;
    int temp;
    int s1;
    int s2;
    int s3;
    int s4;
    int max_val;

    //@ assert (1 <= (sa) <= 10000) && (1 <= (sb) <= 10000) && (1 <= (sc) <= 10000) && (1 <= (sd) <= 10000);

    if (sa > sb)
    {
        temp = sa;
        sa = sb;
        sb = temp;
    }
    //@ assert sa <= sb;

    if (sc > sd)
    {
        temp = sc;
        sc = sd;
        sd = temp;
    }
    //@ assert sc <= sd;

    s1 = sa + sc;
    s2 = sa + sd;
    s3 = sb + sc;
    s4 = sb + sd;

    //@ assert s1 == ((sa) + (sc));
    //@ assert s2 == ((sa) + (sd));
    //@ assert s3 == ((sb) + (sc));
    //@ assert s4 == ((sb) + (sd));

    max_val = s1;
    if (s2 > max_val)
    {
        max_val = s2;
    }
    if (s3 > max_val)
    {
        max_val = s3;
    }
    if (s4 > max_val)
    {
        max_val = s4;
    }

    //@ assert max_val == s1 || max_val == s2 || max_val == s3 || max_val == s4;

    return max_val;
}
