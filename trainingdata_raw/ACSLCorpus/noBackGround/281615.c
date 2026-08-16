#include <stdint.h>

/*@
    requires (1 <= (a) <= 1000000000 &&
        1 <= (b) <= 1000000000 &&
        1 <= (c) <= 1000000000 &&
        1 <= (d) <= 1000000000);
    ensures \result == (((a) <= (b) || (b) <= (c) || (c) <= (d)) ? 0 :
        ((a) > (b) && (b) > (c) && (c) > (d)) ? 1 : 2);
    ensures \result == 0 || \result == 1 || \result == 2;
    ensures \result == 1 ==> (a > b && b > c && c > d);
    ensures \result == 2 ==>
        ((a > b && b > c && c == d) ||
         (a > b && b == c && c > d) ||
         (a == b && b > c && c > d) ||
         (a == b && b == c && c == d));
    ensures \result == 0 ==> (a <= b || b <= c || c <= d);
*/
int32_t func(uint64_t a, uint64_t b, uint64_t c, uint64_t d)
{
    int32_t res;

    //@ assert (1 <= (a) <= 1000000000 &&         1 <= (b) <= 1000000000 &&         1 <= (c) <= 1000000000 &&         1 <= (d) <= 1000000000);

    if (a <= b || b <= c || c <= d)
    {
        //@ assert a <= b || b <= c || c <= d;
        res = 0;
        //@ assert res == (((a) <= (b) || (b) <= (c) || (c) <= (d)) ? 0 :         ((a) > (b) && (b) > (c) && (c) > (d)) ? 1 : 2);
        return res;
    }

    //@ assert !(a <= b || b <= c || c <= d);
    //@ assert a > b && b > c && c > d;

    if (a > b && b > c && c > d)
    {
        //@ assert a > b && b > c && c > d;
        res = 1;
        //@ assert res == (((a) <= (b) || (b) <= (c) || (c) <= (d)) ? 0 :         ((a) > (b) && (b) > (c) && (c) > (d)) ? 1 : 2);
        return res;
    }

    //@ assert !(a > b && b > c && c > d);
    /*@ assert
        (a > b && b > c && c == d) ||
        (a > b && b == c && c > d) ||
        (a == b && b > c && c > d) ||
        (a == b && b == c && c == d);
    */
    res = 2;
    //@ assert res == (((a) <= (b) || (b) <= (c) || (c) <= (d)) ? 0 :         ((a) > (b) && (b) > (c) && (c) > (d)) ? 1 : 2);
    return res;
}
