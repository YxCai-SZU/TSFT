#include <stdbool.h>
#include <stddef.h>

/*@
  requires ((n) >= 1 && (n) <= 100000 &&
      (k) >= 1 && (k) <= 500);
  requires \valid(h + (0 .. n-1));
  requires (\forall integer i; 0 <= i < (n) ==> (h)[i] >= 1 && (h)[i] <= 500);
  assigns \nothing;
  ensures \result >= 0 && \result <= n;
  ensures \forall integer i; 0 <= i < n ==> 
            (h[i] >= k ==> \result >= 1) && 
            (h[i] < k ==> \result >= 0);
*/
long func(long n, long k, int *h) {
    long res = 0;
    long index = 0;
    
    /*@
      loop invariant (0 <= (index) <= (n) &&
      (res) >= 0 &&
      (res) <= (index) &&
      \forall integer i; 0 <= i < (index) ==> 
        ((((h)[i]) >= ((k)) ==> ((res)) >= 1) && (((h)[i]) < ((k)) ==> ((res)) >= 0)) &&
      (\forall integer i; 0 <= i < ((n)) ==> ((h))[i] >= 1 && ((h))[i] <= 500) &&
      (((n)) >= 1 && ((n)) <= 100000 &&
      ((k)) >= 1 && ((k)) <= 500));
      loop assigns res, index;
      loop variant n - index;
    */
    while (index < n) {
        long i = h[index];
        
        //@ assert (\forall integer i; 0 <= i < (n) ==> (h)[i] >= 1 && (h)[i] <= 500);
        //@ assert h[index] >= 1 && h[index] <= 500;
        
        if (i >= k) {
            //@ assert i >= k ==> res + 1 >= 1;
            res += 1;
        }
        
        //@ assert (((i) >= (k) ==> (res) >= 1) && ((i) < (k) ==> (res) >= 0));
        index += 1;
        
        //@ assert index <= n;
        //@ assert res <= index;
    }
    
    //@ assert index == n;
    //@ assert (0 <= (n) <= (n) &&       (res) >= 0 &&       (res) <= (n) &&       \forall integer i; 0 <= i < (n) ==>          ((((h)[i]) >= ((k)) ==> ((res)) >= 1) && (((h)[i]) < ((k)) ==> ((res)) >= 0)) &&       (\forall integer i; 0 <= i < ((n)) ==> ((h))[i] >= 1 && ((h))[i] <= 500) &&       (((n)) >= 1 && ((n)) <= 100000 &&       ((k)) >= 1 && ((k)) <= 500));
    return res;
}
