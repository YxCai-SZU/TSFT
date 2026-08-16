#include <stdint.h>

/*@
    requires (1 <= (n) <= 100);
    ensures \result == n * n;
    assigns \nothing;
*/
int32_t func(int32_t n)
{
    //@ assert (1 <= (n) <= 100);
    //@ assert ((n) * (n) <= 10000);
    return n * n;
}

/*@
    requires (1 <= (a) <= 100);
    ensures \result == a * a * 3;
    assigns \nothing;
*/
int32_t func1(int32_t a)
{
    //@ assert (1 <= (a) <= 100);
    //@ assert ((a) * (a) <= 10000);
    return a * a * 3;
}

int main()
{
    return 0;
}
