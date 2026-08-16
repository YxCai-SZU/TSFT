#include <stdbool.h>
#include <stdint.h>

/*@
    requires (1 <= (n) && (n) <= 100);
    ensures \result == (((n) / 2) + ((n) % 2));
    assigns \nothing;
*/
uint32_t func(uint32_t n)
{
    uint32_t ans;
    uint32_t v[5];
    uint32_t i;

    // Initialize vector with fixed values
    v[0] = 0;
    v[1] = 10;
    v[2] = 20;
    v[3] = 30;
    v[4] = 40;

    // Modify element at index 2
    v[2] = 21;

    //@ assert v[2] == 21;
    //@ assert v[3] == 30;
    //@ assert v[0] == 0 && v[1] == 10 && v[4] == 40;

    ans = (n / 2) + (n % 2);
    return ans;
}
