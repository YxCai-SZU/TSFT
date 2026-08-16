#include <stdint.h>

/*@
    requires (1 <= (a) <= 10000) && (1 <= (b) <= 10000) && (1 <= (c) <= 10000) && (1 <= (d) <= 10000);
    ensures \result == a * b || \result == c * d;
    ensures \result >= a * b && \result >= c * d;
    assigns \nothing;
*/
int64_t func(int64_t a, int64_t b, int64_t c, int64_t d)
{
    // Variable declarations at scope top
    int64_t s1;
    int64_t s2;
    int64_t result;

    //@ assert (1 <= (a) <= 10000);
    //@ assert (1 <= (b) <= 10000);
    //@ assert (1 <= (c) <= 10000);
    //@ assert (1 <= (d) <= 10000);

    //@ assert a * b <= 9223372036854775807;
    //@ assert c * d <= 9223372036854775807;

    s1 = a * b;
    s2 = c * d;

    //@ assert s1 >= a * b;
    //@ assert s2 >= c * d;

    if (s1 > s2) {
        result = s1;
    } else {
        result = s2;
    }

    //@ assert result == ((s1) > (s2) ? (s1) : (s2));
    return result;
}
