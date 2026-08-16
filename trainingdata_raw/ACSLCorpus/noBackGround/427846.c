#include <stddef.h>
#include <stdint.h>

/*@
  requires 2 <= n <= 20;
  requires \valid(a + (0..n-1));
  requires \valid(b + (0..n-1));
  requires \valid(c + (0..n-2));
  requires (\forall integer i; 0 <= i < (n) ==> 1 <= (a)[i] <= (n));
  requires (\forall integer i; 0 <= i < (n) ==> 1 <= (b)[i] <= 50);
  requires (\forall integer i; 0 <= i < (n)-1 ==> 1 <= (c)[i] <= 50);
  requires (\forall integer i, j; 0 <= i < j < (n) ==> (a)[i] != (a)[j]);
  assigns \nothing;
  ensures \result >= 0;
*/
int64_t func(size_t n, int64_t* a, int64_t* b, int64_t* c) {
    int64_t ret = 0;
    size_t i = 0;
    
    /*@
      loop invariant 0 <= i <= n;
      loop invariant 2 <= n <= 20;
      loop invariant ret >= 0;
      loop invariant ret <= i * 100;
      loop invariant \forall integer k; 0 <= k < i ==> 1 <= a[k] <= n;
      loop invariant \forall integer k; 0 <= k < i ==> 1 <= b[k] <= 50;
      loop invariant \forall integer k; 0 <= k < i-1 ==> 1 <= c[k] <= 50;
      loop invariant \forall integer k, l; 0 <= k < l < i ==> a[k] != a[l];
      loop assigns i, ret;
      loop variant n - i;
    */
    while (i < n) {
        int64_t num = a[i];
        num = num - 1;
        
        //@ assert 0 <= num < n;
        ret = ret + b[(size_t)num];
        
        if (i > 0) {
            if (a[i] == a[i-1] + 1) {
                //@ assert 1 <= a[i-1] <= n;
                //@ assert 0 <= a[i-1]-1 < n-1;
                ret = ret + c[(size_t)(a[i-1] - 1)];
            }
        }
        
        i++;
    }
    
    return ret;
}
