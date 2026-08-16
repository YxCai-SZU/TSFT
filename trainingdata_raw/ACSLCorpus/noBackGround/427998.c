#include <stdint.h>

/*@
    requires \true;
    ensures \result == 60;
*/
uint16_t closure_capture_example(void)
{
    uint16_t x;
    uint16_t result;

    x = 30;
    //@ assert ((x) == 30);

    //@ assert (2 * (x)) == 60;

    result = 2 * x;
    //@ assert ((result) == 60);

    return result;
}

int main(void)
{
    uint16_t res;
    res = closure_capture_example();
    //@ assert res == 60;
    return 0;
}
