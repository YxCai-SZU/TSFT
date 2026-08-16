#include <stdint.h>
#include <stdbool.h>

/*@
    requires ((a) <= 2147483647 - (b));
    ensures ((\result) == (a) + (b));
    assigns \nothing;
*/
uint32_t add(uint32_t a, uint32_t b)
{
    //@ assert ((a) <= 2147483647 - (b));
    uint32_t result = a + b;
    //@ assert ((result) == (a) + (b));
    return result;
}

/*@
    requires ((((a)) <= 2147483647 - ((b))));
    ensures \result == a + b;
    assigns \nothing;
*/
uint32_t high_order_calc(uint32_t a, uint32_t b)
{
    //@ assert ((((a)) <= 2147483647 - ((b))));
    uint32_t ans = add(a, b);
    //@ assert ((ans) == (a) + (b));
    return ans;
}

/*@
    assigns \nothing;
*/
int main()
{
    uint32_t r = high_order_calc(10, 8);
    //@ assert r == 18;
    return 0;
}
