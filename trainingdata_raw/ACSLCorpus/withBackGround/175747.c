#include <stdint.h>
#include <stdbool.h>

/*@ predicate valid_array(int64_t *a, integer n) =
      n >= 1 && n <= 200000 &&
      \valid(a + (0 .. n-1)) &&
      \forall integer i; 0 <= i < n ==> 1 <= a[i] <= 1000000;
*/

/*@ logic integer count_value(integer current, integer value) =
      current < value ? value - current : 0;
*/

/*@ lemma count_non_negative:
      \forall integer current, value; 1 <= current <= 1000000 && 1 <= value <= 1000000 ==> 
      count_value(current, value) >= 0;
*/

/*@ lemma count_bound:
      \forall integer current, value; 1 <= current <= 1000000 && 1 <= value <= 1000000 ==> 
      count_value(current, value) <= 1000000;
*/

/*@
  requires valid_array(a, n);
  ensures \result >= 0;
*/
int64_t func(int64_t n, int64_t *a)
{
    int64_t count = 0;
    int64_t i = 0;
    int64_t current = 1;
    
    //@ assert count >= 0;
    //@ assert 0 <= i <= n;
    //@ assert 1 <= current <= 1000000;
    
    /*@ loop invariant 0 <= i <= n;
        loop invariant 1 <= current <= 1000000;
        loop invariant count >= 0;
        loop invariant count <= i * 1000000;
        loop assigns i, current, count;
        loop variant n - i;
    */
    while (i < n) {
        int64_t value = a[i];
        
        //@ assert 1 <= value <= 1000000;
        
        if (current < value) {
            //@ assert value - current >= 0;
            count += value - current;
            current = value;
        } else {
            current = value;
        }
        
        //@ assert count >= 0;
        i += 1;
    }
    
    //@ assert count >= 0;
    return count;
}
