#include <stdbool.h>

/*@
    requires (1 <= (a) && (a) <= 100 &&
        1 <= (b) && (b) <= 100 &&
        1 <= (c) && (c) <= 100);
    ensures \result == (a + b == c || b + c == a || c + a == b);
    assigns \nothing;
*/
bool func(unsigned long long a, unsigned long long b, unsigned long long c)
{
    unsigned long long max;
    unsigned long long sum;

    max = a;
    //@ assert max == a;
    if (b > max)
    {
        max = b;
    }
    //@ assert max >= a && max >= b;
    if (c > max)
    {
        max = c;
    }
    //@ assert max == (((a) >= (b) && (a) >= (c)) ? (a) : (((b) >= (c)) ? (b) : (c)));

    sum = a + b + c;
    //@ assert sum == ((a) + (b) + (c));

    //@ assert sum == 2 * max ==> (a + b == c || b + c == a || c + a == b);
    return sum == 2 * max;
}
