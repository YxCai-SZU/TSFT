#include <stdbool.h>
#include <stdint.h>

/*@
  requires 3 <= n <= 20;
  requires \valid(p + (0 .. n-1));
  requires (\forall integer i, j; 0 <= i < j < (n) ==> (p)[i] != (p)[j]);
  requires (\forall integer i; 0 <= i < (n) ==> 1 <= (p)[i] && (p)[i] <= (n));
  ensures \result <= n-2;
*/
uint32_t func(uint32_t n, uint32_t *p)
{
    uint32_t ans = 0;
    uint32_t i = 1;
    //@ assert 1 <= i && i <= n-1;
    //@ assert ans <= i-1;
    
    /*@ loop invariant 1 <= i <= n-1;
        loop invariant ans <= i-1;
        loop assigns ans, i;
        loop variant n-i;
    */
    while (i < n - 1) {
        //@ assert 0 <= i-1 < n;
        //@ assert 0 <= i < n;
        //@ assert 0 <= i+1 < n;
        
        if (p[i-1] < p[i] && p[i] < p[i+1]) {
            ans += 1;
        }
        //@ assert ans <= i;
        
        if (p[i-1] < p[i+1] && p[i+1] < p[i]) {
            ans += 1;
        }
        //@ assert ans <= i;
        
        i += 1;
        //@ assert ans <= i-1;
    }
    
    //@ assert ans <= n-2;
    return ans;
}
