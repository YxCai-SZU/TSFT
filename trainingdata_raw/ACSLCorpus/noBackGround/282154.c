#include <stdbool.h>

/*@
    requires 1 <= a && a <= 100;
    requires 1 <= b && b <= 100;
    requires 1 <= c && c <= 100;
    requires 1 <= d && d <= 100;
    ensures \result == true <==> (a * b) - (c * d) == (c * d) - (a * b);
    ensures \result == true <==> a * b == c * d;
*/
bool func(unsigned long long a, unsigned long long b,
          unsigned long long c, unsigned long long d)
{
    // Variable declarations at scope top
    unsigned long long product1;
    unsigned long long product2;
    bool result;

    //@ assert (1 <= (a) && (a) <= 100 &&         1 <= (b) && (b) <= 100 &&         (a) * (b) <= 10000);
    //@ assert (1 <= (c) && (c) <= 100 &&         1 <= (d) && (d) <= 100 &&         (c) * (d) <= 10000);
    //@ assert a * b <= 10000;
    //@ assert c * d <= 10000;

    product1 = a * b;
    product2 = c * d;

    if (product1 == product2)
    {
        result = true;
    }
    else
    {
        result = false;
    }

    //@ assert result == (product1 == product2);
    return result;
}
