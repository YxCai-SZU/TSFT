#include <stddef.h>
#include <stdbool.h>

/*@ requires (1 <= (n) && (n) <= 100);
    ensures \result == n * n;
    assigns \nothing;
 */
size_t func(size_t n)
{
    //@ assert (1 <= (n) && (n) <= 100);
    return n * n;
}

/*@ requires (1 <= (n) && (n) <= 100);
    ensures \result == n * n;
    assigns \nothing;
 */
size_t func_vec(size_t n)
{
    size_t *vec = NULL;
    size_t i = 0;
    
    /*@ loop invariant 0 <= i <= n;
        loop invariant \forall integer j; 0 <= j < i ==> j < n;
        loop assigns i;
        loop variant n - i;
     */
    while (i < n)
    {
        i = i + 1;
    }
    
    //@ assert i == n;
    return n * n;
}
