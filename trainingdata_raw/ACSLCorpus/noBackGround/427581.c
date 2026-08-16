#include <stddef.h>
#include <stdbool.h>

/*@ requires (1 <= (n) <= 100 &&
      1 <= (m) <= 100 &&
      1 <= (x) <= (n) - 1);
    requires \valid(a + (0..m-1));
    requires (\forall integer i; 0 <= i < (m) ==> 
        (a)[i] >= 1 && (a)[i] <= (n) && (a)[i] != (x));
    assigns \nothing;
    ensures \result <= m;
*/
size_t func(size_t n, size_t m, int x, int *a) {
    size_t l = 0;
    size_t r = 0;
    size_t i = 0;
    
    /*@ loop invariant (0 <= (i) <= (m) &&
      (l) <= (i) &&
      (r) <= (i) &&
      (\forall integer i; 0 <= i < ((m)) ==> 
        ((a))[i] >= 1 && ((a))[i] <= ((n)) && ((a))[i] != ((x))) &&
      (1 <= ((n)) <= 100 &&
      1 <= ((m)) <= 100 &&
      1 <= ((x)) <= ((n)) - 1) &&
      (\forall integer j; 0 <= j < (i) ==> 
        ((a)[j] < (x) ==> (l) >= 1) && ((a)[j] > (x) ==> (r) >= 1)));
        loop assigns i, l, r;
        loop variant m - i;
    */
    while (i < m) {
        int value = a[i];
        
        //@ assert value >= 1 && value <= n && value != x;
        
        if (value < x) {
            l = l + 1;
            //@ assert l >= 1;
        }
        
        if (value > x) {
            r = r + 1;
            //@ assert r >= 1;
        }
        
        i = i + 1;
    }
    
    size_t min_val = (l < r) ? l : r;
    
    //@ assert min_val <= l && min_val <= r;
    //@ assert min_val <= m;
    
    return min_val;
}
