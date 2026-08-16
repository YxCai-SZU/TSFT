#include <stdbool.h>

/*@
    requires (1 <= (a) && (a) <= 10 &&
        1 <= (b) && (b) <= 10 &&
        1 <= (c) && (c) <= 10);
    ensures \result == (a == b + c || b == c + a || c == a + b);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    unsigned int min;
    unsigned int mid;
    unsigned int max;
    unsigned int temp;

    min = a;
    mid = b;
    max = c;

    //@ assert (1 <= (min) && (min) <= 10 &&         1 <= (mid) && (mid) <= 10 &&         1 <= (max) && (max) <= 10);

    if (min > mid)
    {
        temp = min;
        min = mid;
        mid = temp;
    }
    //@ assert min <= mid;

    if (mid > max)
    {
        temp = mid;
        mid = max;
        max = temp;
    }
    //@ assert mid <= max;

    if (min > mid)
    {
        temp = min;
        min = mid;
        mid = temp;
    }
    //@ assert ((min) <= (mid) && (mid) <= (max));

    //@ assert min + mid <= 20;
    //@ assert max + min <= 20;
    //@ assert min + mid + max <= 30;

    return min == mid + max || mid == max + min || max == min + mid;
}
