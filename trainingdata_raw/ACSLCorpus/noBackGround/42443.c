#include <stddef.h>
#include <stdbool.h>

/*@
    requires ((n) > 0 && (n) <= 200000 &&
        \valid_read((a) + (0 .. (n)-1)) &&
        \forall integer j; 0 <= j < (n) ==> (a)[j] > 0 && (a)[j] <= 1000000000);
    ensures 0 <= \result <= n;
*/
size_t func(size_t n, size_t *a)
{
    size_t res = 0;
    size_t i = 0;
    
    //@ ghost size_t old_n = n;
    //@ ghost size_t *old_a = a;
    
    /*@
        loop invariant 0 <= i <= n;
        loop invariant res <= i;
        loop invariant n == old_n;
        loop invariant a == old_a;
        loop invariant ((n) > 0 && (n) <= 200000 &&
        \valid_read((a) + (0 .. (n)-1)) &&
        \forall integer j; 0 <= j < (n) ==> (a)[j] > 0 && (a)[j] <= 1000000000);
        loop assigns i, res;
        loop variant n - i;
    */
    while (i < n)
    {
        size_t ai = a[i];
        
        //@ assert ai > 0 && ai <= 1000000000;
        
        if ((ai % 2 == 1) && (res % 2 == 0))
        {
            //@ assert res % 2 == 0;
            res += 1;
            //@ assert res <= i + 1;
        }
        
        i += 1;
        //@ assert res <= i;
    }
    
    //@ assert res <= n;
    return res;
}
