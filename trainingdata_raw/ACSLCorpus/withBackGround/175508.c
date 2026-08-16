#include <stdbool.h>
#include <stddef.h>

/*@ predicate all_positive_and_bounded(int *v, integer n) =
      \forall integer i; 0 <= i < n ==> v[i] > 0 && v[i] <= 1000;
*/

/*@ predicate condition_holds(int *v, integer n) =
      \forall integer i; 0 <= i < n && v[i] % 2 == 0 ==> 
        v[i] % 3 == 0 || v[i] % 5 == 0;
*/

/*@ predicate partial_condition(int *v, integer i) =
      \forall integer j; 0 <= j < i && v[j] % 2 == 0 ==> 
        v[j] % 3 == 0 || v[j] % 5 == 0;
*/

/*@ lemma condition_lemma:
      \forall int *v, integer n;
        all_positive_and_bounded(v, n) && n > 0 ==>
        (condition_holds(v, n) <==> partial_condition(v, n));
*/

/*@ requires n > 0;
    requires \valid(v + (0 .. n-1));
    requires all_positive_and_bounded(v, n);
    assigns \nothing;
    ensures \result == true <==> condition_holds(v, n);
*/
bool func(size_t n, int *v) {
    size_t i = 0;
    bool res = true;
    
    /*@ loop invariant 0 <= i <= n;
        loop invariant all_positive_and_bounded(v, n);
        loop invariant res == true <==> partial_condition(v, i);
        loop invariant n > 0;
        loop assigns i, res;
        loop variant n - i;
    */
    while (i < n) {
        int value = v[i];
        if (value % 2 == 0) {
            if (value % 3 != 0 && value % 5 != 0) {
                res = false;
            }
        }
        i++;
    }
    return res;
}
