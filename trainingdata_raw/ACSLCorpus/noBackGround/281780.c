#include <stdint.h>
/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100) && (1 <= (d) <= 100);
    ensures \result >= 0;
    ensures \result == a * c || \result == a * d || \result == b * c || \result == b * d;
*/
int64_t func(int64_t a, int64_t b, int64_t c, int64_t d)
{
    int64_t tmp[4];
    int64_t max_value;
    int64_t i;
    //@ assert (1 <= (a) <= 100);
    //@ assert (1 <= (c) <= 100);
    //@ assert (1 <= (a) * (c) <= 10000);
    tmp[0] = a * c;
    //@ assert (1 <= (a) <= 100);
    //@ assert (1 <= (d) <= 100);
    //@ assert (1 <= (a) * (d) <= 10000);
    tmp[1] = a * d;
    //@ assert (1 <= (b) <= 100);
    //@ assert (1 <= (c) <= 100);
    //@ assert (1 <= (b) * (c) <= 10000);
    tmp[2] = b * c;
    //@ assert (1 <= (b) <= 100);
    //@ assert (1 <= (d) <= 100);
    //@ assert (1 <= (b) * (d) <= 10000);
    tmp[3] = b * d;
    max_value = tmp[0];
    i = 1;
    /*@
        loop invariant 0 <= i <= 4;
        loop invariant \exists integer k; 0 <= k < i && max_value == tmp[k];
        loop invariant \forall integer j; 0 <= j < i ==> max_value >= tmp[j];
        loop invariant tmp[0] == a * c && tmp[1] == a * d && tmp[2] == b * c && tmp[3] == b * d;
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
    return max_value;
}
