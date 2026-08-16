#include <stdbool.h>
#include <stddef.h>

/*@
    requires n > 0;
    requires \valid(a + (0..n-1));
    requires (\forall integer i; 0 <= i < (n) ==> (a)[i] > 0);
    ensures \result == true <==> (\forall integer i; 0 <= i < (n) ==> 
            ((a)[i] % 2 != 0) || ((a)[i] % 3 == 0) || ((a)[i] % 5 == 0));
*/
bool func(size_t n, const size_t *a)
{
    bool ans = true;
    size_t i = 0;
    
    /*@
        loop invariant 0 <= i <= n;
        loop invariant ans == true <==> (\forall integer k; 0 <= k < (i) ==> 
            ((a)[k] % 2 != 0) || ((a)[k] % 3 == 0) || ((a)[k] % 5 == 0));
        loop assigns i, ans;
        loop variant n - i;
    */
    while (i < n)
    {
        size_t s = a[i];
        if (s % 2 == 0)
        {
            if (s % 3 == 0 || s % 5 == 0)
            {
                ans = ans && true;
            }
            else
            {
                ans = ans && false;
            }
        }
        i += 1;
    }
    
    //@ assert ans == true <==> (\forall integer i; 0 <= i < (n) ==>              ((a)[i] % 2 != 0) || ((a)[i] % 3 == 0) || ((a)[i] % 5 == 0));
    return ans;
}
