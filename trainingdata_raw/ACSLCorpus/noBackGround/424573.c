#include <stdbool.h>
#include <stddef.h>

/*@
  requires n > 0 && n <= 100;
  requires \valid(a + (0 .. n-1));
  requires \forall integer i; 0 <= i < n ==> 1 <= a[i] <= 1000;
  ensures \result == true <==> (\forall integer i; 0 <= i < (n) ==>
        ((a)[i] % 2 == 0 ==> ((a)[i] % 3 == 0 || (a)[i] % 5 == 0)));
*/
bool func(size_t n, int *a) {
    size_t i = 0;
    /*@
      loop invariant 0 <= i <= n;
      loop invariant \forall integer j; 0 <= j < i ==>
        (a[j] % 2 == 0 ==> (a[j] % 3 == 0 || a[j] % 5 == 0));
      loop assigns i;
      loop variant n - i;
    */
    while (i < n) {
        int val = a[i];
        if (val % 2 == 0) {
            int mod_3 = val % 3;
            int mod_5 = val % 5;
            if (mod_3 != 0 && mod_5 != 0) {
                //@ assert !(\forall integer i; 0 <= i < (n) ==>         ((a)[i] % 2 == 0 ==> ((a)[i] % 3 == 0 || (a)[i] % 5 == 0)));
                return false;
            }
        }
        i++;
    }
    //@ assert (\forall integer i; 0 <= i < (n) ==>         ((a)[i] % 2 == 0 ==> ((a)[i] % 3 == 0 || (a)[i] % 5 == 0)));
    return true;
}
