#include <stdint.h>

/*@
    requires 1 <= n <= 10000;
    ensures \result == (n / 100) * 100 + ((n % 100) / 5) * 5 + (n % 5);
    assigns \nothing;
*/
uint32_t func(uint32_t n)
{
    uint32_t num1;
    uint32_t num2;
    uint32_t num3;
    uint32_t result;

    num1 = n / 100;
    //@ assert 0 <= num1 <= 100;

    num2 = (n - 100 * num1) / 5;
    //@ assert 0 <= num2 <= 200;

    num3 = n - 100 * num1 - 5 * num2;
    //@ assert 0 <= num3 <= 4;

    //@ assert num1 * 100 + num2 * 5 + num3 <= 100 * 100 + 200 * 5 + 4;

    result = num1 * 100 + num2 * 5 + num3;
    return result;
}
