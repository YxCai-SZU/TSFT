#include <stdbool.h>
#include <stddef.h>

/*@ predicate is_valid_array(integer n, int *p) =
      n >= 1 && n <= 200000 &&
      \valid(p + (0 .. n-1)) &&
      (\forall integer i; 0 <= i < n ==> p[i] >= 1 && p[i] <= n) &&
      (\forall integer i, j; 0 <= i < j < n ==> p[i] != p[j]);
*/

/*@ lemma result_bounds:
      \forall integer n, int *p, integer result;
      is_valid_array(n, p) && 0 <= result <= n-1 ==> result >= 0 && result <= n-1;
*/

/*@ requires is_valid_array(n, p);
    assigns \nothing;
    ensures 0 <= \result <= n-1;
*/
int func(unsigned long n, int *p) {
    int result = 0;
    size_t index = 1;
    
    /*@ loop invariant 1 <= index <= n;
        loop invariant 0 <= result <= index-1;
        loop invariant is_valid_array(n, p);
        loop assigns result, index;
        loop variant n - index;
    */
    while (index < n) {
        int p_im1 = p[index - 1];
        int p_i = p[index];
        
        //@ assert p_im1 >= 1 && p_im1 <= n;
        //@ assert p_i >= 1 && p_i <= n;
        //@ assert p_im1 != p_i;
        
        if ((p_im1 < p_i) != (p_i < p[index - 1])) {
            //@ assert result + 1 >= 0;
            //@ assert result + 1 <= index;
            result += 1;
        }
        //@ assert 0 <= result <= index;
        index += 1;
    }
    //@ assert 0 <= result <= n-1;
    return result;
}
