#include <stdbool.h>

/*@
    predicate is_valid_params(integer a, integer b) =
        0 <= a <= 100 &&
        2 <= b <= 1000 &&
        b % 2 == 0;

    logic integer half_of(integer b) = b / 2;

    lemma half_of_even: \forall integer b; b % 2 == 0 ==> half_of(b) * 2 == b;
*/

/*@
    requires is_valid_params(a, b);
    ensures (\result == 0 && a <= 5) ||
            (\result == half_of(b) && 6 <= a && a <= 12) ||
            (\result == b && a >= 13);
    assigns \nothing;
*/
int func(int a, int b)
{
    int result;
    
    //@ assert is_valid_params(a, b);
    
    if (a <= 5)
    {
        result = 0;
        //@ assert result == 0 && a <= 5;
        return result;
    }
    else if (a <= 12)
    {
        int half_b = 0;
        int count = 0;
        
        /*@
            loop invariant 0 <= count <= b;
            loop invariant half_b == count / 2;
            loop invariant 2 <= b <= 1000;
            loop invariant b % 2 == 0;
            loop invariant half_b >= 0;
            loop invariant count >= 0;
            loop invariant count % 2 == 0;
            loop assigns half_b, count;
            loop variant b - count;
        */
        while (count < b)
        {
            half_b += 1;
            count += 2;
        }
        
        result = half_b;
        //@ assert result == half_of(b) && 6 <= a && a <= 12;
        return result;
    }
    else
    {
        result = b;
        //@ assert result == b && a >= 13;
        return result;
    }
}
