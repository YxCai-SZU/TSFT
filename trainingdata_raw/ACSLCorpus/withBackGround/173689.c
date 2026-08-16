#include <stdbool.h>

/*@ predicate all_ge_or_eq_minus_one(int *a, integer len, integer k) =
      \forall integer i; 0 <= i < len ==> (a[i] >= k || a[i] == -1);
*/

/*@ predicate all_in_range(int *a, integer len) =
      \forall integer i; 0 <= i < len ==> (a[i] >= 0 && a[i] <= 123);
*/

/*@
  requires \valid(a + (0 .. 4));
  requires all_in_range(a, 5);
  requires k >= 0 && k <= 123;
  ensures \result == true <==> all_ge_or_eq_minus_one(a, 5, k);
*/
bool func(int *a, int k) {
    int i;
    i = 0;
    /*@
      loop invariant 0 <= i <= 5;
      loop invariant all_in_range(a, 5);
      loop invariant \forall integer j; 0 <= j < i ==> (a[j] >= k || a[j] == -1);
      loop assigns i;
    */
    while (i < 5) {
        if (a[i] < k && a[i] != -1) {
            //@ assert !all_ge_or_eq_minus_one(a, 5, k);
            return false;
        }
        i = i + 1;
    }
    //@ assert all_ge_or_eq_minus_one(a, 5, k);
    return true;
}
