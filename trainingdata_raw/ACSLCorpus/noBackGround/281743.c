#include <stdint.h>

/*@
    requires (1 <= (a) && (a) <= 100 &&
        1 <= (b) && (b) <= 100 &&
        1 <= (c) && (c) <= 100);
    ensures \result >= 1 && \result <= 3;
    ensures \result == 1 ==> (a == b && b == c);
    ensures \result == 2 ==> ((a == b && b != c) || (a == c && c != b) || (b == c && a != c));
    ensures \result == 3 ==> (a != b && b != c && a != c);
    assigns \nothing;
*/
int64_t func(int64_t a, int64_t b, int64_t c)
{
    int64_t num = 0;

    if (a == b && b == c)
    {
        num = 1;
        //@ assert num == 1 && a == b && b == c;
    }
    else if (a == b || a == c || b == c)
    {
        num = 2;
        //@ assert num == 2 && (a == b || a == c || b == c);
    }
    else
    {
        num = 3;
        //@ assert num == 3 && a != b && b != c && a != c;
    }

    //@ assert num >= 1 && num <= 3;
    return num;
}
