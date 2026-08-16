#include <stdbool.h>
#include <stddef.h>

/*@ predicate is_even_divisible(integer x) = 
      (x % 2 == 0) ==> (x % 3 == 0 || x % 5 == 0);
*/

/*@ predicate all_even_divisible(int *v, integer n, integer i) = 
      \forall integer j; 0 <= j < i ==> 
        ((v[j] % 2 == 0) ==> (v[j] % 3 == 0 || v[j] % 5 == 0));
*/

/*@ lemma range_constraints: 
      \forall integer n; n >= 2 && n <= 100000 ==> n >= 0;
*/

/*@ requires n >= 2 && n <= 100000;
    requires \valid(v + (0 .. n-1));
    requires \forall integer i; 0 <= i < n ==> v[i] >= 1 && v[i] <= 1000;
    ensures \result == true <==> 
            (\forall integer i; 0 <= i < n ==> 
              ((v[i] % 2 == 0) ==> (v[i] % 3 == 0 || v[i] % 5 == 0)));
*/
bool func(size_t n, int *v) {
    bool res = true;
    size_t i = 0;
    
    /*@ loop invariant 0 <= i <= n;
        loop invariant res == true <==> all_even_divisible(v, n, i);
        loop invariant \forall integer k; 0 <= k < n ==> v[k] >= 1 && v[k] <= 1000;
        loop assigns i, res;
        loop variant n - i;
    */
    while (i < n) {
        int ai = v[i];
        if (ai % 2 == 0) {
            if (!(ai % 3 == 0 || ai % 5 == 0)) {
                res = false;
            }
        }
        i++;
    }
    return res;
}
