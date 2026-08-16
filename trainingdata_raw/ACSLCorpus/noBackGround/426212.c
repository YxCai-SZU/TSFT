#include <stdbool.h>
#include <stddef.h>

/*@
  requires (1 <= (n) <= 100 &&
      \valid((a) + (0 .. (n)-1)) &&
      \forall integer i; 0 <= i < (n) ==> 1 <= (a)[i] <= 1000);
  ensures \result == true <==>
           \forall integer x; 0 <= x < n ==>
             (a[x] % 2 == 0 ==> (a[x] % 3 == 0 || a[x] % 5 == 0));
  assigns \nothing;
*/
bool func(size_t n, int *a) {
    bool ans = true;
    size_t i = 0;

    /*@
      loop invariant 0 <= i <= n;
      loop invariant (1 <= (n) <= 100 &&
      \valid((a) + (0 .. (n)-1)) &&
      \forall integer i; 0 <= i < (n) ==> 1 <= (a)[i] <= 1000);
      loop invariant ans == true <==> (\forall integer x; 0 <= x < (i) ==>
        ((a)[x] % 2 == 0 ==> ((a)[x] % 3 == 0 || (a)[x] % 5 == 0)));
      loop invariant ans == false ==> (\exists integer x; 0 <= x < (i) &&
        (a)[x] % 2 == 0 && !((a)[x] % 3 == 0 || (a)[x] % 5 == 0));
      loop assigns i, ans;
      loop variant n - i;
    */
    while (i < n) {
        int ai = a[i];
        if (ai % 2 == 0) {
            if (!(ai % 3 == 0 || ai % 5 == 0)) {
                ans = false;
                break;
            }
        }
        i++;
    }

    //@ assert ans == true <==> (\forall integer x; 0 <= x < (n) ==>         ((a)[x] % 2 == 0 ==> ((a)[x] % 3 == 0 || (a)[x] % 5 == 0)));
    return ans;
}
