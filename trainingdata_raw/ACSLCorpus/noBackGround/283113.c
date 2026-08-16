#include <stdint.h>
#include <stdbool.h>

/*@
    requires (1 <= (n) && (n) <= 100);
    ensures \result == ((n) * (n));
    assigns \nothing;
*/
uint32_t func(uint32_t n)
{
    uint32_t result;
    
    //@ assert (1 <= (n) && (n) <= 100);
    //@ assert ((n) * (n)) <= 10000;
    
    result = n * n;
    //@ assert result == ((n) * (n));
    return result;
}

/*@
    ensures (*(map) == 0);
    assigns *map;
*/
void ensure_empty_map(int *map)
{
    *map = 0;
    //@ assert (*(map) == 0);
}
