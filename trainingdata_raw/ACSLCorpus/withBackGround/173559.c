#include <stdbool.h>
#include <stddef.h>

/*@ predicate all_even_divisible_by_3_or_5{L}(size_t *a, integer n, integer i) =
      \forall integer j; 0 <= j < i ==> 
        (a[j] % 2 == 0 ==> a[j] % 3 == 0 || a[j] % 5 == 0);
*/

/*@ lemma final_condition{L}:
      \forall size_t *a, integer n, bool res;
        (1 <= n && res == true <==> all_even_divisible_by_3_or_5(a, n, n)) ==>
        (res == true <==> \forall integer i; 0 <= i < n ==> 
          (a[i] % 2 == 0 ==> a[i] % 3 == 0 || a[i] % 5 == 0));
*/

/*@ requires 1 <= n;
    requires \valid(a + (0 .. n-1));
    ensures \result == true <==> \forall integer i; 0 <= i < n ==> (a[i] % 2 == 0 ==> a[i] % 3 == 0 || a[i] % 5 == 0);
*/
bool func(size_t n, size_t *a)
{
    bool res = true;
    size_t i = 0;
    
    /*@ loop invariant 0 <= i <= n;
        loop invariant res == true <==> all_even_divisible_by_3_or_5(a, n, i);
        loop assigns i, res;
        loop variant n - i;
    */
    while (i < n) {
        size_t ai = a[i];
        if (ai % 2 != 0) {
            i++;
            continue;
        }
        if (!(ai % 3 == 0 || ai % 5 == 0)) {
            res = false;
            break;
        }
        i++;
    }
    
    //@ assert res == true <==> all_even_divisible_by_3_or_5(a, n, n);
    return res;
}
