#include <limits.h>

/*@
    requires h1 >= 0 && m1 >= 0 && h2 >= 0 && m2 >= 0 && k >= 0;
    requires h1 < 24 && m1 < 60 && h2 < 24 && m2 < 60;
    requires h1 < h2 || (h1 == h2 && m1 < m2);
    ensures \result >= 0 && \result <= 60 * 24;
    ensures \result == 60 * (h2 - h1) + m2 - m1 - k || \result == 0;
*/
int func(int h1, int m1, int h2, int m2, int k)
{
    int x;
    int tmp;

    //@ assert ((h1) >= 0 && (m1) >= 0 && (h1) < 24 && (m1) < 60);
    //@ assert ((h2) >= 0 && (m2) >= 0 && (h2) < 24 && (m2) < 60);
    //@ assert ((h1) < (h2) || ((h1) == (h2) && (m1) < (m2)));

    tmp = 60 * (h2 - h1) + m2 - m1 - k;

    //@ assert tmp == (60 * ((h2) - (h1)) + (m2) - (m1) - (k));

    if (tmp < 0)
    {
        x = 0;
    }
    else
    {
        x = tmp;
    }

    //@ assert x >= 0 && x <= 60 * 24;
    //@ assert x == (60 * ((h2) - (h1)) + (m2) - (m1) - (k)) || x == 0;

    return x;
}
