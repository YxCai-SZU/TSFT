#include <stddef.h>

/*@ predicate is_valid_input(integer a, integer b, integer c, integer d) =
      1 <= a && a <= 10000 &&
      1 <= b && b <= 10000 &&
      1 <= c && c <= 10000 &&
      1 <= d && d <= 10000;
*/

/*@ logic integer sum_ab(integer a, integer b) = a + b;
    logic integer sum_cd(integer c, integer d) = c + d;
    logic integer sum_bc(integer b, integer c) = b + c;
    logic integer sum_ad(integer a, integer d) = a + d;
*/

/*@ lemma sum_bounds_ab: \forall integer a, b;
      is_valid_input(a, b, 1, 1) ==> a + b <= 20000;
    lemma sum_bounds_cd: \forall integer c, d;
      is_valid_input(1, 1, c, d) ==> c + d <= 20000;
    lemma sum_bounds_bc: \forall integer b, c;
      is_valid_input(1, b, c, 1) ==> b + c <= 20000;
    lemma sum_bounds_ad: \forall integer a, d;
      is_valid_input(a, 1, 1, d) ==> a + d <= 20000;
*/

/*@ requires is_valid_input(a, b, c, d);
    ensures \result == a + b || \result == c + d || 
            \result == b + c || \result == a + d;
    assigns \nothing;
*/
unsigned int func(unsigned int a, unsigned int b, 
                  unsigned int c, unsigned int d)
{
    unsigned int xs[4];
    unsigned int max_val;
    unsigned int i;
    
    //@ assert a + b <= 20000;
    //@ assert c + d <= 20000;
    //@ assert b + c <= 20000;
    //@ assert a + d <= 20000;
    
    xs[0] = a + b;
    xs[1] = c + d;
    xs[2] = b + c;
    xs[3] = a + d;
    
    max_val = xs[0];
    i = 1;
    
    /*@ loop invariant 1 <= i <= 4;
        loop invariant \exists integer k; 0 <= k < i && max_val == xs[k];
        loop invariant \forall integer j; 0 <= j < i ==> max_val >= xs[j];
        loop invariant \forall integer k; 0 <= k < 4 ==> 
            xs[k] == a + b || xs[k] == c + d || 
            xs[k] == b + c || xs[k] == a + d;
        loop assigns i, max_val;
        loop variant 4 - i;
    */
    while (i < 4)
    {
        if (xs[i] > max_val)
        {
            max_val = xs[i];
        }
        i++;
    }
    
    //@ assert max_val == a + b || max_val == c + d || max_val == b + c || max_val == a + d;
    return max_val;
}
