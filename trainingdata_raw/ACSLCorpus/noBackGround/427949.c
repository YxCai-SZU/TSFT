#include <limits.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100);
    ensures \result == ((a) * (b));
    assigns \nothing;
*/
int func(int a, int b)
{
    //@ assert (1 <= (a) <= 100);
    //@ assert (1 <= (b) <= 100);
    //@ assert 1 <= a * b <= 10000;
    int product = a * b;
    return product;
}

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100);
    ensures \result == ((a) - (b));
    assigns \nothing;
*/
int func2(int a, int b)
{
    int difference = a - b;
    return difference;
}

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100);
    ensures \result == ((a) + (b));
    assigns \nothing;
*/
int func3(int a, int b)
{
    int sum = a + b;
    return sum;
}
