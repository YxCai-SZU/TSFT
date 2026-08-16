#include <stdbool.h>
#include <stddef.h>

/*@ predicate numbers_positive(int *numbers, integer n) =
      \forall integer i; 0 <= i < n ==> numbers[i] > 0;
*/

/*@ predicate index_in_range(integer index, integer n) =
      0 <= index <= n;
*/

/*@ predicate tmp_bounds(integer tmp, integer index) =
      tmp >= 0 && tmp <= index;
*/

/*@ lemma tmp_always_nonnegative:
      \forall integer tmp, integer index;
      tmp_bounds(tmp, index) ==> tmp >= 0;
*/

/*@ lemma tmp_never_exceeds_index:
      \forall integer tmp, integer index;
      tmp_bounds(tmp, index) ==> tmp <= index;
*/

/*@ lemma index_never_exceeds_n:
      \forall integer index, integer n;
      index_in_range(index, n) ==> index <= n;
*/

/*@ requires n > 0;
    requires \valid(numbers + (0 .. n-1));
    requires numbers_positive(numbers, n);
    ensures \result >= 0;
    ensures \result <= n;
    assigns \nothing;
*/
int func(int n, int *numbers) {
    int tmp = 0;
    size_t index = 0;
    
    /*@ loop invariant index_in_range(index, n);
        loop invariant tmp_bounds(tmp, index);
        loop invariant index <= n;
        loop assigns tmp, index;
        loop variant n - index;
    */
    while (index < (size_t)n) {
        int a = numbers[index];
        
        //@ assert a > 0;
        
        if (tmp < a) {
            tmp += 0;
        } else {
            tmp += 1;
        }
        
        //@ assert tmp_bounds(tmp, index + 1);
        
        index++;
        
        //@ assert index_in_range(index, n);
    }
    
    //@ assert tmp_bounds(tmp, n);
    
    return tmp;
}
