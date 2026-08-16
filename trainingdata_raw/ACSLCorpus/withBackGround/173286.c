#include <stdbool.h>
#include <stddef.h>

/*@ predicate all_even_divisible_by_3_or_5(integer n, int *a) =
      \forall integer i; 0 <= i < n ==> 
        (a[i] % 2 == 0 ==> (a[i] % 3 == 0 || a[i] % 5 == 0));
*/

/*@ lemma index_property:
      \forall integer n, int *a, integer idx;
        0 <= idx <= n &&
        (\forall integer k; 0 <= k < n ==> 1 <= a[k] <= 1000000) &&
        (\forall integer i; 0 <= i < idx && a[i] % 2 == 0 ==> 
          a[i] % 3 == 0 || a[i] % 5 == 0) ==>
        (idx == n ==> all_even_divisible_by_3_or_5(n, a));
*/

/*@ requires 1 <= n <= 100000;
    requires \valid(a + (0 .. n-1));
    requires \forall integer i; 0 <= i < n ==> 1 <= a[i] <= 1000000;
    ensures \result == true <==> all_even_divisible_by_3_or_5(n, a);
    assigns \nothing;
*/
bool func(size_t n, const int *a) {
    size_t index = 0;
    
    /*@ loop invariant 0 <= index <= n;
        loop invariant \forall integer k; 0 <= k < n ==> 1 <= a[k] <= 1000000;
        loop invariant index > 0 ==> 
          \forall integer i; 0 <= i < index && a[i] % 2 == 0 ==> 
            a[i] % 3 == 0 || a[i] % 5 == 0;
        loop assigns index;
        loop variant n - index;
    */
    while (index < n) {
        int ai = a[index];
        
        if (ai % 2 == 0) {
            //@ assert ai % 2 == 0;
            if (!(ai % 3 == 0 || ai % 5 == 0)) {
                //@ assert !(ai % 3 == 0 || ai % 5 == 0);
                return false;
            }
        }
        index++;
    }
    //@ assert index == n;
    return true;
}
