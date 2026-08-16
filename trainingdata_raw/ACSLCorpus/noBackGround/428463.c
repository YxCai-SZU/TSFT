#include <limits.h>

/*@ requires 1 <= x <= 100;
    ensures \result == x * x;
    assigns \nothing;
 */
int func(int x)
{
    //@ assert 1 <= x <= 100;
    //@ assert x * x <= 10000;
    return x * x;
}

int main()
{
    return 0;
}
