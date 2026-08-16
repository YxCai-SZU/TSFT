#include <stdbool.h>

/*@
    requires (1 <= (a) && (a) <= 100) && (1 <= (b) && (b) <= 100) && (1 <= (x) && (x) <= 100);
    ensures \result == (
        (x >= a && x <= ((a) + (b))) ||
        (x >= ((a) + (b)) + 1 && x <= ((a) + 2 * (b)))
    );
    assigns \nothing;
*/
bool func(unsigned long long a, unsigned long long b, unsigned long long x)
{
    unsigned long long c;
    unsigned long long d;
    bool result;

    //@ assert (1 <= (a) && (a) <= 100) && (1 <= (b) && (b) <= 100) && (1 <= (x) && (x) <= 100);
    //@ assert ((a) + (b)) == a + b;
    //@ assert ((a) + 2 * (b)) == a + 2 * b;

    c = a + b;
    d = a + 2 * b;

    //@ assert c == ((a) + (b));
    //@ assert d == ((a) + 2 * (b));

    result = (x >= a && x <= c) || (x >= c + 1 && x <= d);
    //@ assert result == ((x >= a && x <= c) || (x >= c + 1 && x <= d));
    return result;
}
