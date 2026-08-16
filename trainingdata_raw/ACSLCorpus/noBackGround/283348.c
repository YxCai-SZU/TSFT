#include <stdbool.h>
#include <stddef.h>

/*@
  requires \valid(a + (0 .. n-1));
  requires ((n) > 0 && (n) <= 100 &&
      \forall integer i; 0 <= i < (n) ==> (a)[i] > 0 && (a)[i] <= 1000);
  ensures \result == true <==> (\forall integer i; 0 <= i < (n) ==>
        ((a)[i] % 2 != 0) || ((a)[i] % 6 == 0) || ((a)[i] % 10 == 0));
*/
bool func(size_t n, const int a[]) {
    size_t i = 0;
    bool ans = true;

    /*@
      loop invariant 0 <= i <= n;
      loop invariant ans == true <==> 
        \forall integer j; 0 <= j < i ==>
          (a[j] % 2 != 0) || (a[j] % 6 == 0) || (a[j] % 10 == 0);
      loop assigns i, ans;
      loop variant n - i;
    */
    while (i < n) {
        int ai = a[i];
        if (!((ai % 2 != 0) || (ai % 6 == 0) || (ai % 10 == 0))) {
            ans = false;
            break;
        }
        i++;
    }

    //@ assert ans == true <==> (\forall integer i; 0 <= i < (n) ==>         ((a)[i] % 2 != 0) || ((a)[i] % 6 == 0) || ((a)[i] % 10 == 0));
    return ans;
}
