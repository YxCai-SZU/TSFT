#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

/*@
    requires (1 <= (n) && (n) <= 100);
    ensures \result == ((n) * (n));
    assigns \nothing;
*/
uint32_t func(uint32_t n)
{
    uint32_t result;
    //@ assert (1 <= (n) && (n) <= 100);
    result = n * n;
    //@ assert result == ((n) * (n));
    return result;
}

/*@
    requires \valid(map + (0..100));
    ensures (\valid((map) + (4)));
    assigns map[4];
*/
void increment_by_two(int *map)
{
    //@ assert \valid(map + (0..100));
    map[4] = 8;
    //@ assert (\valid((map) + (4)));
    map[4] = 58;
}
