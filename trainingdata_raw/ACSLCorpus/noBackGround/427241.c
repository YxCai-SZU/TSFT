#include <stddef.h>
#include <stdbool.h>

/*@
    requires (2 <= (k) && (k) <= (n) && (n) <= 100000 &&
        \valid((a) + (0 .. (n)-1)) &&
        \forall integer i; 0 <= i < (n) ==> 1 <= (a)[i] <= (n) &&
        \forall integer i, j; 0 <= i < j < (n) ==> (a)[i] != (a)[j]);
    ensures \result >= (((n) - 1) / ((k) - 1));
    ensures \result <= (((n) - 1) / ((k) - 1) + 1);
    assigns \nothing;
*/
size_t func(size_t n, size_t k, const size_t *a)
{
    //@ assert 2 <= k && k <= n && n <= 100000;
    
    if (n == 1)
    {
        //@ assert (((n) - 1) / ((k) - 1)) == 0;
        return 0;
    }
    else
    {
        //@ assert n - 1 >= 0;
        size_t base = (n - 1) / (k - 1);
        size_t remainder = (n - 1) % (k - 1);
        size_t adjustment = (remainder == 0) ? 0 : 1;
        
        //@ assert base >= (((n) - 1) / ((k) - 1));
        return base + adjustment;
    }
}
