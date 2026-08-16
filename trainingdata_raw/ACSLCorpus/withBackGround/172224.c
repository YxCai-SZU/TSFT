#include <stdbool.h>
#include <stddef.h>

/*@ predicate valid_params(integer n, integer x) =
      n >= 1 && n <= 100 &&
      x >= 1 && x <= 10000;
*/

/*@ predicate valid_array(integer n, unsigned int *ls, integer len) =
      len == n &&
      \forall integer i; 0 <= i < n ==> ls[i] >= 1 && ls[i] <= 100;
*/

/*@ lemma acc_bound_lemma:
      \forall integer index, integer acc, unsigned int *ls, integer n, integer x;
      valid_params(n, x) && valid_array(n, ls, n) &&
      0 <= index <= n && acc >= 0 && acc <= index * 100 &&
      (index > 0 ==> acc <= x) &&
      index < n && acc + ls[index] <= x ==>
      acc + ls[index] >= 0 && acc + ls[index] <= (index + 1) * 100;
*/

/*@ lemma loop_maintains_invariants:
      \forall integer index, integer acc, integer count, unsigned int *ls, integer n, integer x;
      valid_params(n, x) && valid_array(n, ls, n) &&
      0 <= index <= n && acc >= 0 && acc <= index * 100 &&
      count >= 0 && count <= index &&
      (index > 0 ==> acc <= x) &&
      index < n && acc + ls[index] <= x ==>
      0 <= index + 1 <= n &&
      acc + ls[index] >= 0 && acc + ls[index] <= (index + 1) * 100 &&
      count + 1 >= 0 && count + 1 <= index + 1 &&
      (index + 1 > 0 ==> acc + ls[index] <= x);
*/

/*@ requires valid_params(n, x) && valid_array(n, ls, n);
    ensures \result >= 0 && \result <= n;
*/
unsigned int func(unsigned int n, unsigned int x, unsigned int *ls)
{
    unsigned int count = 0;
    unsigned int index = 0;
    unsigned int acc = 0;
    
    //@ ghost unsigned int old_n = n;
    //@ ghost unsigned int old_x = x;
    
    /*@ loop invariant 0 <= index <= n;
        loop invariant acc >= 0 && acc <= index * 100;
        loop invariant count >= 0 && count <= index;
        loop invariant index > 0 ==> acc <= x;
        loop invariant n == old_n && x == old_x;
        loop invariant valid_array(n, ls, n);
        loop assigns index, acc, count;
        loop variant n - index;
    */
    while (index < n && acc + ls[index] <= x) {
        //@ assert index < n;
        //@ assert acc + ls[index] <= x;
        
        acc += ls[index];
        count += 1;
        index += 1;
        
        //@ assert acc <= x;
    }
    
    //@ assert count <= n;
    return count;
}
