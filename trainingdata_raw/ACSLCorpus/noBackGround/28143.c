#include <stdbool.h>

/*@
    requires a >= 0 && b >= 0 && c >= 0 && d >= 0 && e >= 0;
    requires a < b && b < c && c < d && d < e;
    requires k >= 0 && k <= 123;
    ensures \result == true;
*/
bool func(long a, long b, long c, long d, long e, long k)
{
    long v[5];
    long i;
    long j;
    long l;
    long l2;
    long l_abs;
    long l2_abs;

    v[0] = a;
    v[1] = b;
    v[2] = c;
    v[3] = d;
    v[4] = e;

    //@ assert (\forall integer m, n; 0 <= m < n < (5) ==> (&v[0])[m] < (&v[0])[n]);

    i = 0;
    /*@
        loop invariant 0 <= i <= 5;
        loop invariant (\forall integer m, n; 0 <= m < n < (5) ==> (&v[0])[m] < (&v[0])[n]);
        loop invariant a >= 0 && b >= 0 && c >= 0 && d >= 0 && e >= 0;
        loop invariant a < b && b < c && c < d && d < e;
        loop invariant k >= 0 && k <= 123;
        loop invariant i < 5 ==> v[0] < v[1] && v[1] < v[2] && v[2] < v[3] && v[3] < v[4];
        loop assigns i, j, l, l2, l_abs, l2_abs;
    */
    while (i < 5)
    {
        j = i + 1;
        /*@
            loop invariant i < j <= 5;
            loop invariant (\forall integer m, n; 0 <= m < n < (5) ==> (&v[0])[m] < (&v[0])[n]);
            loop invariant a >= 0 && b >= 0 && c >= 0 && d >= 0 && e >= 0;
            loop invariant a < b && b < c && c < d && d < e;
            loop invariant k >= 0 && k <= 123;
            loop invariant i < 5 ==> v[0] < v[1] && v[1] < v[2] && v[2] < v[3] && v[3] < v[4];
            loop assigns j, l, l2, l_abs, l2_abs;
        */
        while (j < 5)
        {
            l = v[i] - v[j];
            l2 = v[j] - v[i];
            l_abs = (l < 0) ? -l : l;
            l2_abs = (l2 < 0) ? -l2 : l2;

            //@ assert l_abs == l2_abs;

            if (l_abs > k || l2_abs > k)
            {
            }
            j++;
        }
        i++;
    }
    return true;
}
