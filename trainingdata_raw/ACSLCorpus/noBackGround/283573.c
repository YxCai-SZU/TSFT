#include <stdint.h>

/*@
    requires (1 <= (a) <= 10000 &&
        1 <= (b) <= 10000 &&
        1 <= (c) <= 10000 &&
        1 <= (d) <= 10000 &&
        (a) <= (b) &&
        (c) <= (d));
    ensures \result >= 0;
    ensures \result <= b - a;
    ensures \result <= d - c;
    ensures \result == (\let begin = ((a) > (c)) ? (a) : (c);
        \let end = ((b) < (d)) ? (b) : (d);
        (end - begin > 0) ? (end - begin) : 0);
*/
int64_t func(int64_t a, int64_t b, int64_t c, int64_t d)
{
    int64_t begin;
    int64_t end;
    int64_t x;

    //@ assert (1 <= (a) <= 10000 &&         1 <= (b) <= 10000 &&         1 <= (c) <= 10000 &&         1 <= (d) <= 10000 &&         (a) <= (b) &&         (c) <= (d));
    
    if (a > c) {
        begin = a;
    } else {
        begin = c;
    }
    
    if (b < d) {
        end = b;
    } else {
        end = d;
    }
    
    if (end - begin > 0) {
        x = end - begin;
    } else {
        x = 0;
    }
    
    //@ assert x >= 0;
    //@ assert x <= b - a;
    //@ assert x <= d - c;
    
    return x;
}
