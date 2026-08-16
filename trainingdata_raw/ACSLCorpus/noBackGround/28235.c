#include <limits.h>

/*@
    requires (1 <= (a) <= 9) && (1 <= (b) <= 9) && (1 <= (c) <= 9);
    ensures \result == ((a) * 10 + (b) + (c)) || \result == ((a) + (b) * 10 + (c)) || \result == ((a) + (b) + (c) * 10);
    ensures \result >= 0;
*/
int func(int a, int b, int c)
{
    int max;
    int temp;

    //@ assert (1 <= (a) <= 9) && (1 <= (b) <= 9) && (1 <= (c) <= 9);
    max = a * 10 + b + c;
    //@ assert max == ((a) * 10 + (b) + (c));
    //@ assert max >= 0;

    temp = a + b * 10 + c;
    //@ assert temp == ((a) + (b) * 10 + (c));
    //@ assert temp >= 0;

    if (temp > max)
    {
        max = temp;
    }
    //@ assert max == ((a) * 10 + (b) + (c)) || max == ((a) + (b) * 10 + (c));
    //@ assert max >= 0;

    temp = a + b + c * 10;
    //@ assert temp == ((a) + (b) + (c) * 10);
    //@ assert temp >= 0;

    if (temp > max)
    {
        max = temp;
    }
    //@ assert max == ((a) * 10 + (b) + (c)) || max == ((a) + (b) * 10 + (c)) || max == ((a) + (b) + (c) * 10);
    //@ assert max >= 0;

    return max;
}
