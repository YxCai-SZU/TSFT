#include <stdbool.h>

/*@
  requires \valid(a+(0..4));
  requires \forall integer i; 0 <= i < 5 ==> 0 <= a[i] && a[i] <= 123;
  requires 0 <= k && k <= 123;
  assigns \nothing;
  ensures \result == true <==> 
          ((\forall integer i; 0 <= i < (5) - 1 ==> ((a)[i] <= (a)[i+1] || (a)[i] - 1 == (a)[i+1])) || (\forall integer i; 0 <= i < (5) - 1 ==> ((a)[i] == (a)[i+1] || (a)[i] + 1 == (a)[i+1] || (a)[i] - 1 == (a)[i+1])));
*/
bool func(int a[5], int k) {
    bool ans = true;
    int i = 0;
    
    /*@
      loop invariant 0 <= i <= 4;
      loop invariant ans == true <==> 
                     (\forall integer j; 0 <= j < i ==> (a[j] <= a[j+1] || a[j] - 1 == a[j+1])) ||
                     (\forall integer j; 0 <= j < i ==> (a[j] == a[j+1] || a[j] + 1 == a[j+1] || a[j] - 1 == a[j+1]));
      loop assigns i, ans;
      loop variant 4 - i;
    */
    while (i < 4) {
        //@ assert 0 <= i && i < 4;
        if (!(a[i] <= a[i + 1] || a[i] - 1 == a[i + 1])) {
            ans = false;
        }
        i++;
    }
    return ans;
}
