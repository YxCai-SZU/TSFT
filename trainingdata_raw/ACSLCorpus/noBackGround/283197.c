#include <stdbool.h>

/*@
    requires (-10000 <= (a) <= 10000) && (-10000 <= (b) <= 10000) && (-10000 <= (c) <= 10000) && (-10000 <= (d) <= 10000);
    requires a <= b && c <= d;
    ensures \result == ((b) * (d)) || \result == ((b) * (c)) || 
            \result == ((a) * (d)) || \result == ((a) * (c));
*/
int func(int a, int b, int c, int d)
{
    int tmp[4];
    int max_val;
    int i;

    //@ assert -100000000 <= a * c <= 100000000;
    //@ assert -100000000 <= a * d <= 100000000;
    //@ assert -100000000 <= b * c <= 100000000;
    //@ assert -100000000 <= b * d <= 100000000;

    tmp[0] = a * c;
    tmp[1] = a * d;
    tmp[2] = b * c;
    tmp[3] = b * d;

    max_val = tmp[0];
    i = 1;

    /*@
        loop invariant 0 <= i <= 4;
        loop invariant \exists integer k; 0 <= k < i && max_val == tmp[k];
        loop invariant \forall integer j; 0 <= j < i ==> max_val >= tmp[j];
        loop invariant (-10000 <= (a) <= 10000) && (-10000 <= (b) <= 10000) && (-10000 <= (c) <= 10000) && (-10000 <= (d) <= 10000);
        loop invariant a <= b && c <= d;
        loop assigns i, max_val;
        loop variant 4 - i;
    */
    while (i < 4)
    {
        if (tmp[i] > max_val)
        {
            max_val = tmp[i];
        }
        i = i + 1;
    }

    return max_val;
}
