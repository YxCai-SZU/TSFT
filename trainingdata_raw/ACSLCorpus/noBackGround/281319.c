#include <stdint.h>

/*@
    requires (-100 <= (a) && (a) <= 100 &&
        -100 <= (b) && (b) <= 100 &&
        -100 <= (c) && (c) <= 100);
    ensures \result == (((a) == (b) && (a) != (c)) ? (c) :
        ((a) == (c) && (a) != (b)) ? (b) :
        ((b) == (c) && (a) != (b)) ? (a) :
        0);
    assigns \nothing;
*/
int64_t func(int64_t a, int64_t b, int64_t c)
{
    //@ assert (-100 <= (a) && (a) <= 100 &&         -100 <= (b) && (b) <= 100 &&         -100 <= (c) && (c) <= 100);
    
    if (a == b && a != c) {
        //@ assert (((a) == (b) && (a) != (c)) ? (c) :         ((a) == (c) && (a) != (b)) ? (b) :         ((b) == (c) && (a) != (b)) ? (a) :         0) == c;
        return c;
    } else if (a == c && a != b) {
        //@ assert (((a) == (b) && (a) != (c)) ? (c) :         ((a) == (c) && (a) != (b)) ? (b) :         ((b) == (c) && (a) != (b)) ? (a) :         0) == b;
        return b;
    } else if (b == c && a != b) {
        //@ assert (((a) == (b) && (a) != (c)) ? (c) :         ((a) == (c) && (a) != (b)) ? (b) :         ((b) == (c) && (a) != (b)) ? (a) :         0) == a;
        return a;
    } else {
        //@ assert (((a) == (b) && (a) != (c)) ? (c) :         ((a) == (c) && (a) != (b)) ? (b) :         ((b) == (c) && (a) != (b)) ? (a) :         0) == 0;
        return 0;
    }
}
