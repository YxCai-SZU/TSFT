#include <stdbool.h>

/*@
    predicate valid_range(integer a) = 1 <= a <= 100;
    
    logic integer multiply(integer a, integer b) = a * b;
    
    lemma multiplication_bounds:
        \forall integer a, b;
        valid_range(a) && valid_range(b) ==> 
        1 <= multiply(a, b) <= 10000;
*/

/*@
    requires valid_range(a) && valid_range(b) && valid_range(c);
    ensures \result == (a * b) / 2;
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    // Variable declarations at scope top
    int result;
    int count;
    int sum;
    
    // Precondition verification
    //@ assert valid_range(a);
    //@ assert valid_range(b);
    //@ assert valid_range(c);
    
    //@ assert 1 <= a * b <= 10000;
    
    result = a * b;
    count = 0;
    sum = 0;
    
    /*@
        loop invariant 0 <= result <= a * b;
        loop invariant count == (a * b - result) / 2;
        loop invariant a * b == result + 2 * count;
        loop assigns result, count;
        loop variant result;
    */
    while (result >= 2)
    {
        //@ assert result >= 2;
        result -= 2;
        count += 1;
        //@ assert a * b == result + 2 * count;
    }
    
    //@ assert a * b == result + 2 * count;
    return count;
}
