#include <stdint.h>
/*@
    requires (-1000000000 <= (a) <= 1000000000) && (-1000000000 <= (b) <= 1000000000) && (-1000000000 <= (c) <= 1000000000) && (-1000000000 <= (d) <= 1000000000);
    requires a <= b && c <= d;
    ensures \result == b * d || \result == b * c || \result == a * d || \result == a * c;
    assigns \nothing;
*/
int64_t func(int64_t a, int64_t b, int64_t c, int64_t d)
{
    int64_t answers[4];
    int64_t max_value;
    int64_t i;
    //@ assert (-1000000000 <= (a) <= 1000000000) && (-1000000000 <= (b) <= 1000000000) && (-1000000000 <= (c) <= 1000000000) && (-1000000000 <= (d) <= 1000000000);
    //@ assert a <= b && c <= d;
    //@ assert (-1000000000000000000 <= (a * c) <= 1000000000000000000);
    answers[0] = a * c;
    //@ assert (-1000000000000000000 <= (a * d) <= 1000000000000000000);
    answers[1] = a * d;
    //@ assert (-1000000000000000000 <= (b * c) <= 1000000000000000000);
    answers[2] = b * c;
    //@ assert (-1000000000000000000 <= (b * d) <= 1000000000000000000);
    answers[3] = b * d;
    max_value = answers[0];
    i = 1;
    /*@
        loop invariant 0 <= i <= 4;
        loop invariant \exists integer k; 0 <= k < i && max_value == answers[k];
        loop invariant \forall integer j; 0 <= j < i ==> max_value >= answers[j];
        loop invariant answers[0] == a * c && answers[1] == a * d &&
                        answers[2] == b * c && answers[3] == b * d;
        loop invariant (-1000000000 <= (a) <= 1000000000) && (-1000000000 <= (b) <= 1000000000) && (-1000000000 <= (c) <= 1000000000) && (-1000000000 <= (d) <= 1000000000);
        loop invariant a <= b && c <= d;
        loop assigns i, max_value;
        loop variant 4 - i;
    */
    while (i < 4)
    {
        if (answers[i] > max_value)
        {
            max_value = answers[i];
        }
        i = i + 1;
    }
    //@ assert max_value == b * d || max_value == b * c || max_value == a * d || max_value == a * c;
    return max_value;
}
