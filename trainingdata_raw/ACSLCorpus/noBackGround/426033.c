#include <stdint.h>

/*@
    requires (0 <= (a) && 0 <= (b) && 0 <= (c) &&
        1 <= (k) && (k) <= (a) + (b) + (c) &&
        (a) + (b) + (c) <= 2000000000);
    ensures \result == ((k) <= (a) ? (k) :
        ((a) < (k) && (k) <= (a) + (b)) ? (a) :
        ((a) + (b) < (k) && (k) <= (a) + (b) + (c)) ? (a) - ((k) - (a) - (b)) :
        -(c));
    ensures \result <= a;
    ensures \result >= -c;
*/
int64_t func(int64_t a, int64_t b, int64_t c, int64_t k)
{
    // Variable declarations at top of scope
    int64_t result;

    if (k <= a)
    {
        result = k;
        //@ assert result == ((k) <= (a) ? (k) :         ((a) < (k) && (k) <= (a) + (b)) ? (a) :         ((a) + (b) < (k) && (k) <= (a) + (b) + (c)) ? (a) - ((k) - (a) - (b)) :         -(c));
        return result;
    }

    if (a < k && k <= a + b)
    {
        result = a;
        //@ assert result == ((k) <= (a) ? (k) :         ((a) < (k) && (k) <= (a) + (b)) ? (a) :         ((a) + (b) < (k) && (k) <= (a) + (b) + (c)) ? (a) - ((k) - (a) - (b)) :         -(c));
        return result;
    }

    if (a + b < k && k <= a + b + c)
    {
        //@ assert a - (k - a - b) >= -c;
        result = a - (k - a - b);
        //@ assert result == ((k) <= (a) ? (k) :         ((a) < (k) && (k) <= (a) + (b)) ? (a) :         ((a) + (b) < (k) && (k) <= (a) + (b) + (c)) ? (a) - ((k) - (a) - (b)) :         -(c));
        return result;
    }

    result = -c;
    //@ assert result == ((k) <= (a) ? (k) :         ((a) < (k) && (k) <= (a) + (b)) ? (a) :         ((a) + (b) < (k) && (k) <= (a) + (b) + (c)) ? (a) - ((k) - (a) - (b)) :         -(c));
    return result;
}
