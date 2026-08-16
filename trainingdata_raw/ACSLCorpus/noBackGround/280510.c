#include <stdint.h>

/*@
    requires (0 <= (x) <= 1);
    ensures \result == (1 - (x));
    assigns \nothing;
*/
uint32_t func(uint32_t x)
{
    //@ assert (0 <= (x) <= 1);
    if (x == 0) {
        //@ assert x == 0;
        return 1;
    } else {
        //@ assert x == 1;
        return 0;
    }
}

/*@
    requires (0 <= (x) <= 1);
    ensures \result == (1 - (x));
    assigns \nothing;
*/
uint32_t func1(uint32_t x)
{
    //@ assert (0 <= (x) <= 1);
    if (x == 1) {
        //@ assert x == 1;
        return 0;
    } else {
        //@ assert x == 0;
        return 1;
    }
}

/*@
    requires (0 <= (x) <= 1);
    ensures \result == (1 - (x));
    assigns \nothing;
*/
uint32_t func2(uint32_t x)
{
    //@ assert (0 <= (x) <= 1);
    if (x == 1) {
        //@ assert x == 1;
        return 0;
    } else {
        //@ assert x == 0;
        return 1;
    }
}

/*@
    requires (0 <= (x) <= 1);
    ensures \result == (1 - (x));
    assigns \nothing;
*/
uint32_t func3(uint32_t x)
{
    //@ assert (0 <= (x) <= 1);
    if (x == 1) {
        //@ assert x == 1;
        return 0;
    } else {
        //@ assert x == 0;
        return 1;
    }
}

/*@
    requires (0 <= (x) <= 1);
    ensures \result == (1 - (x));
    assigns \nothing;
*/
uint32_t func4(uint32_t x)
{
    //@ assert (0 <= (x) <= 1);
    if (x == 1) {
        //@ assert x == 1;
        return 0;
    } else {
        //@ assert x == 0;
        return 1;
    }
}

/*@
    requires (0 <= (x) <= 1);
    ensures \result == (1 - (x));
    assigns \nothing;
*/
uint32_t func5(uint32_t x)
{
    //@ assert (0 <= (x) <= 1);
    if (x == 1) {
        //@ assert x == 1;
        return 0;
    } else {
        //@ assert x == 0;
        return 1;
    }
}

/*@
    requires (0 <= (x) <= 1);
    ensures \result == (1 - (x));
    assigns \nothing;
*/
uint32_t func6(uint32_t x)
{
    //@ assert (0 <= (x) <= 1);
    if (x == 1) {
        //@ assert x == 1;
        return 0;
    } else {
        //@ assert x == 0;
        return 1;
    }
}

/*@
    requires (0 <= (x) <= 1);
    ensures \result == (1 - (x));
    assigns \nothing;
*/
uint32_t func7(uint32_t x)
{
    //@ assert (0 <= (x) <= 1);
    if (x == 1) {
        //@ assert x == 1;
        return 0;
    } else {
        //@ assert x == 0;
        return 1;
    }
}
