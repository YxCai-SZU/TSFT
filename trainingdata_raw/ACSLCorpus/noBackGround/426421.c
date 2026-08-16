#include <stddef.h>

/*@ requires 
      (1 <= (n) <= 100 &&
     1 <= (m) <= 100 &&
     1 <= (x) <= (n) - 1) &&
      (\valid((a) + (0 .. (m)-1))) &&
      (\forall integer j; 0 <= j < (m) ==> 1 <= (a)[j] <= (n)) &&
      (\forall integer j; 0 <= j < (m) ==> (a)[j] != (x));
    ensures
      \result <= m;
*/
size_t func(size_t n, size_t m, size_t x, int* a)
{
    size_t l = 0;
    size_t r = 0;
    size_t i = 0;
    
    /*@ loop invariant 
         0 <= i <= m &&
         l <= i &&
         r <= i &&
         \forall integer j; 0 <= j < i ==> 1 <= a[j] <= n &&
         \forall integer j; 0 <= j < i ==> a[j] != x &&
         l + r <= i;
       loop assigns i, l, r;
       loop variant m - i;
    */
    while (i < m) {
        int value = a[i];
        //@ assert 1 <= value <= n;
        //@ assert value != x;
        
        if (value > (int)x) {
            r = r + 1;
        }
        if (value < (int)x) {
            l = l + 1;
        }
        i = i + 1;
    }
    
    //@ assert l <= m && r <= m;
    size_t ans = (r < l) ? r : l;
    //@ assert ans <= m;
    
    return ans;
}
