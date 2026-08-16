#include <stdint.h>
#include <limits.h>

/*@
    requires (-1000000000 <= (a) <= 1000000000) && (-1000000000 <= (b) <= 1000000000) && (-1000000000 <= (c) <= 1000000000) && (-1000000000 <= (d) <= 1000000000);
    requires a <= b && c <= d;
    ensures \result == b * d || \result == b * c || \result == a * d || \result == a * c;
*/
int64_t func(int64_t a, int64_t b, int64_t c, int64_t d)
{
    int64_t tmp[4];
    int64_t max_value;
    int64_t i;

    //@ assert (-1000000000000000000 <= (a * c) <= 1000000000000000000);
    tmp[0] = a * c;

    //@ assert (-1000000000000000000 <= (a * d) <= 1000000000000000000);
    tmp[1] = a * d;

    //@ assert (-1000000000000000000 <= (b * c) <= 1000000000000000000);
    tmp[2] = b * c;

    //@ assert (-1000000000000000000 <= (b * d) <= 1000000000000000000);
    tmp[3] = b * d;

    max_value = tmp[0];
    i = 1;

    /*@
        loop invariant 0 <= i <= 4;
        loop invariant \exists integer j; 0 <= j < i && max_value == tmp[j];
        loop invariant \forall integer k; 0 <= k < i ==> max_value >= tmp[k];
        loop invariant (-1000000000000000000 <= (tmp[0]) <= 1000000000000000000) && (-1000000000000000000 <= (tmp[1]) <= 1000000000000000000) &&
                       (-1000000000000000000 <= (tmp[2]) <= 1000000000000000000) && (-1000000000000000000 <= (tmp[3]) <= 1000000000000000000);
        loop invariant (-1000000000000000000 <= (max_value) <= 1000000000000000000);
        loop invariant (-1000000000 <= (a) <= 1000000000) && (-1000000000 <= (b) <= 1000000000) && (-1000000000 <= (c) <= 1000000000) && (-1000000000 <= (d) <= 1000000000);
        loop invariant a <= b && c <= d;
        loop assigns i, max_value;
    */
    while (i < 4)
    {
        if (tmp[i] > max_value)
        {
            max_value = tmp[i];
        }
        i = i + 1;
    }

    //@ assert max_value == (((tmp[0]) >= (tmp[1]) && (tmp[0]) >= (tmp[2]) && (tmp[0]) >= (tmp[3])) ? (tmp[0]) :         ((tmp[1]) >= (tmp[2]) && (tmp[1]) >= (tmp[3])) ? (tmp[1]) :         ((tmp[2]) >= (tmp[3])) ? (tmp[2]) : (tmp[3]));
    return max_value;
}
