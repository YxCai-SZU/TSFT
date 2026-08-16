#include <stdint.h>

/*@
    requires ((x) <= 100 && (y) <= 100);
    ensures \result == x * y;
    assigns \nothing;
*/
uint32_t non_linear_arith_example(uint32_t x, uint32_t y)
{
    //@ assert ((x) <= 100 && (y) <= 100);
    //@ assert x * y <= 10000;
    //@ assert x * y >= 0;
    return x * y;
}

/*@
    requires ((x) <= 100 && (y) <= 100);
    ensures \result <= 10000;
    assigns \nothing;
*/
uint32_t bound_check(uint32_t x, uint32_t y)
{
    //@ assert ((x) <= 100 && (y) <= 100);
    //@ assert x * y <= 10000;
    //@ assert x * y >= 0;
    return x * y;
}

/*@
    requires ((x) <= 100 && (y) <= 100) && ret == x * y;
    ensures \result <= 10000;
    assigns \nothing;
*/
uint32_t postcondition_check(uint32_t ret, uint32_t x, uint32_t y)
{
    //@ assert ((x) <= 100 && (y) <= 100);
    //@ assert x * y <= 10000;
    //@ assert ret <= 10000;
    return ret;
}

int main()
{
    return 0;
}
