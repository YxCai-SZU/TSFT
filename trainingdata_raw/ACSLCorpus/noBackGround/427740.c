#include <stdbool.h>
#include <stddef.h>

/*@
  requires n > 0 && n <= 100;
  requires \valid(a + (0 .. n-1));
  requires (\forall integer i; 0 <= i < (n) ==> (a)[i] > 0 && (a)[i] <= 1000);
  ensures \result == true <==> (\forall integer i; 0 <= i < (n) ==> 
        (a)[i] % 2 != 0 || (a)[i] % 6 == 0 || (a)[i] % 10 == 0);
  assigns \nothing;
*/
bool func(size_t n, int *a) {
    bool result = true;
    size_t i = 0;
    
    /*@
      loop invariant 0 <= i <= n;
      loop invariant result == true <==> 
        (\forall integer j; 0 <= j < i ==> 
          a[j] % 2 != 0 || a[j] % 6 == 0 || a[j] % 10 == 0);
      loop invariant (\forall integer i; 0 <= i < (n) ==> (a)[i] > 0 && (a)[i] <= 1000);
      loop assigns i, result;
      loop variant n - i;
    */
    while (i < n) {
        int value = a[i];
        //@ assert value > 0 && value <= 1000;
        
        if ((value % 2 == 0) && !(value % 6 == 0 || value % 10 == 0)) {
            result = false;
        }
        i++;
    }
    return result;
}
