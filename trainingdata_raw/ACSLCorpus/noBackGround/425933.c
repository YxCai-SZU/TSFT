#include <stdbool.h>
#include <stddef.h>

/*@
  requires n > 0;
  requires \valid(a + (0..n-1));
  requires ((n) > 0 &&
      \forall integer i; 0 <= i < (n) ==> (a)[i] > 0 && (a)[i] <= 1000);
  ensures \result == true <==> (\forall integer i; 0 <= i < (n) ==> 
        (a)[i] % 2 != 0 || (a)[i] % 3 == 0 || (a)[i] % 5 == 0);
  assigns \nothing;
*/
bool func(size_t n, int *a) {
    size_t i = 0;
    bool result = true;
    
    /*@
      loop invariant 0 <= i <= n;
      loop invariant ((n) > 0 &&
      \forall integer i; 0 <= i < (n) ==> (a)[i] > 0 && (a)[i] <= 1000);
      loop invariant \forall integer j; 0 <= j < i ==> 
        !(a[j] % 2 == 0 && a[j] % 3 != 0 && a[j] % 5 != 0);
      loop invariant result == true;
      loop assigns i, result;
      loop variant n - i;
    */
    while (i < n) {
        int s = a[i];
        
        //@ assert s > 0 && s <= 1000;
        
        if (s % 2 == 0 && (s % 3 != 0 && s % 5 != 0)) {
            result = false;
            //@ assert !(\forall integer i; 0 <= i < (n) ==>          (a)[i] % 2 != 0 || (a)[i] % 3 == 0 || (a)[i] % 5 == 0);
            return result;
        }
        
        i++;
    }
    
    //@ assert (\forall integer i; 0 <= i < (n) ==>          (a)[i] % 2 != 0 || (a)[i] % 3 == 0 || (a)[i] % 5 == 0);
    return result;
}
