#include <stdint.h>

/*@
    logic integer fib(integer n) =
        n <= 2 ? 1 : fib(n-1) + fib(n-2);
*/

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    ensures \result == a * b;
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b)
{
    // Variable declarations at top of scope
    uint32_t result;

    //@ assert a * b <= 10000;
    result = a * b;
    return result;
}

/*@
    lemma fib_10_is_55: fib(10) == 55;
*/

int main(void)
{
    // Variable declarations at top of scope
    uint32_t x;

    //@ assert fib(10) == 55;
    x = func(5, 10);
    return 0;
}
