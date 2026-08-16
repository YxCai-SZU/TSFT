#include <stdint.h>

/*@
    requires n <= 2047;
    ensures \result == n * (n + 1) / 2;
    ensures \result >= n;
    assigns \nothing;
*/
uint32_t is_triangular(uint32_t n)
{
    //@ assert n >= 0;
    //@ assert n <= 2047;
    //@ assert n * (n + 1) / 2 <= (2047 * (2047 + 1)) / 2;
    //@ assert n * (n + 1) / 2 >= n;
    //@ assert n * (n + 1) / 2 <= 2147483647;
    //@ assert n * (n + 1) / 2 >= n;
    
    return n * (n + 1) / 2;
}
