#include <stdbool.h>

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    ensures \result == ((a + b) % 2 == 0);
    ensures ((\result) == (((a) + (b)) % 2 == 0));
*/
bool func(unsigned int a, unsigned int b)
{
    unsigned int sum;
    bool result;

    sum = a + b;
    result = (sum % 2 == 0);
    //@ assert sum == a + b;
    return result;
}

/*@
    requires 1 <= n <= 100;
    ensures \result == (n * 800) - ((n / 15) * 200);
    ensures \result == (((n) * 800) - (((n) / 15) * 200));
*/
unsigned int func2(unsigned int n)
{
    unsigned int x;
    unsigned int y;
    unsigned int z;
    unsigned int result;

    x = n * 800;
    y = n / 15;
    z = y * 200;
    result = x - z;

    //@ assert x == n * 800;
    //@ assert y == n / 15;
    //@ assert z == y * 200;
    return result;
}
