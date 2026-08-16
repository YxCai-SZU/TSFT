#include <stdint.h>

/*@
    requires (1 <= (x) && (x) <= 100 &&
        1 <= (y) && (y) <= 100 &&
        (y) % 2 == 0);
    ensures \result == ((x) + (y) / 2);
    assigns \nothing;
*/
uint32_t func(uint32_t x, uint32_t y)
{
    // Local variable declarations
    uint32_t result;

    //@ assert y % 2 == 0;
    //@ assert y / 2 <= 50;
    //@ assert x + y / 2 <= 150;

    result = x + y / 2;
    return result;
}

#ifdef TEST
#include <assert.h>

int main()
{
    // Test case 1
    uint32_t x1 = 10;
    uint32_t y1 = 20;
    uint32_t result1 = func(x1, y1);
    //@ assert result1 == ((x1) + (y1) / 2);
    assert(result1 == x1 + y1 / 2);

    // Test case 2
    uint32_t x2 = 50;
    uint32_t y2 = 100;
    uint32_t result2 = func(x2, y2);
    //@ assert result2 == ((x2) + (y2) / 2);
    assert(result2 == x2 + y2 / 2);

    return 0;
}
#endif
