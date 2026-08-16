#include <stdbool.h>
#include <stddef.h>

/*@ predicate valid_index_range(integer i, integer n) =
      0 <= i && i < n;
*/

/*@ predicate valid_task_value(integer v) =
      v >= 1 && v <= 100;
*/

/*@ predicate valid_array(int *arr, integer n) =
      \forall integer i; valid_index_range(i, n) ==> valid_task_value(arr[i]);
*/

/*@ lemma result_bound_lemma:
      \forall integer n, integer index, integer result;
      n >= 1 && n <= 100 &&
      result >= 0 && result <= index && index <= n ==>
      result <= n;
*/

/*@ requires n >= 1 && n <= 100;
    requires \valid(a + (0 .. n-1));
    requires valid_array(a, n);
    assigns \nothing;
    ensures \result >= 0;
    ensures \result <= n;
*/
int func(int n, int *a) {
    int ai = 0;
    int bi = 0;
    int result = 0;
    size_t index = 0;
    
    //@ ghost int old_n = n;
    
    /*@ loop invariant 0 <= index <= n;
        loop invariant result >= 0;
        loop invariant result <= index;
        loop invariant index > 0 ==> valid_array(a, index);
        loop invariant n >= 1 && n <= 100;
        loop invariant valid_array(a, n);
        loop invariant result <= n;
        loop assigns ai, bi, result, index;
        loop variant n - index;
    */
    while (index < (size_t)n) {
        ai = a[index];
        
        //@ assert valid_task_value(ai);
        
        if (ai == bi) {
            result += 1;
            bi = 0;
        } else {
            bi = ai;
        }
        
        //@ assert result >= 0;
        //@ assert result <= index + 1;
        
        index += 1;
    }
    
    //@ assert result <= n;
    return result;
}
