#include <stdbool.h>

/*@
    predicate is_valid_range(integer a) = -100 <= a <= 100;
    
    logic integer add(integer a, integer b) = a + b;
    logic integer sub(integer a, integer b) = a - b;
    logic integer mul(integer a, integer b) = a * b;
    
    lemma mul_bounds: \forall integer a, b; is_valid_range(a) && is_valid_range(b) ==> -10000 <= mul(a, b) <= 10000;
*/

/*@
    requires is_valid_range(a) && is_valid_range(b);
    ensures \result == add(a, b) || \result == sub(a, b) || \result == mul(a, b);
    ensures \result >= add(a, b);
    ensures \result >= sub(a, b);
    ensures \result >= mul(a, b);
*/
int func(int a, int b)
{
    int ar[3];
    int max_val;
    int i;
    
    //@ assert is_valid_range(a) && is_valid_range(b);
    //@ assert -10000 <= a * b <= 10000;
    
    ar[0] = a + b;
    ar[1] = a - b;
    ar[2] = a * b;
    
    max_val = ar[0];
    i = 1;
    
    /*@
        loop invariant 0 <= i <= 3;
        loop invariant \exists integer k; 0 <= k < i && max_val == ar[k];
        loop invariant \forall integer j; 0 <= j < i ==> max_val >= ar[j];
        loop invariant ar[0] == a + b && ar[1] == a - b && ar[2] == a * b;
        loop invariant is_valid_range(a) && is_valid_range(b);
        loop invariant -10000 <= a * b <= 10000;
        loop assigns i, max_val;
        loop variant 3 - i;
    */
    while (i < 3)
    {
        if (ar[i] > max_val)
        {
            max_val = ar[i];
        }
        i = i + 1;
    }
    
    //@ assert max_val >= a + b && max_val >= a - b && max_val >= a * b;
    //@ assert max_val == a + b || max_val == a - b || max_val == a * b;
    
    return max_val;
}
