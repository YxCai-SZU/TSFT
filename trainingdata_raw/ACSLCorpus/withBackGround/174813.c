#include <limits.h>

/*@
    predicate is_in_range(integer x) = -100 <= x <= 100;
*/

/*@
    requires is_in_range(a) && is_in_range(b) && is_in_range(c) && is_in_range(d);
    ensures \result == a || \result == b || \result == c || \result == d;
    ensures \result >= a && \result >= b && \result >= c && \result >= d;
    assigns \nothing;
*/
int func(int a, int b, int c, int d)
{
    int max_val = a;
    
    //@ assert max_val == a;
    //@ assert max_val >= a;
    
    if (b > max_val)
    {
        max_val = b;
        //@ assert max_val == b;
    }
    //@ assert max_val >= b;
    
    if (c > max_val)
    {
        max_val = c;
        //@ assert max_val == c;
    }
    //@ assert max_val >= c;
    
    if (d > max_val)
    {
        max_val = d;
        //@ assert max_val == d;
    }
    //@ assert max_val >= d;
    
    //@ assert max_val == a || max_val == b || max_val == c || max_val == d;
    //@ assert max_val >= a && max_val >= b && max_val >= c && max_val >= d;
    
    return max_val;
}

/*@
    lemma test11: -100 <= -100 && -100 >= -100 && 100 <= 100 && 100 >= 100;
    lemma test12: -100 >= -100 && -100 >= -100 && 100 <= 100 && 100 <= 100;
    lemma test2: -100 >= -100 && 100 <= 100 && -100 <= -100 && 100 >= 100;
    lemma test3: -100 <= -100 && 100 >= 100 && -100 >= -100 && 100 <= 100;
    lemma test4: -100 <= -100 && 100 <= 100 && -100 >= -100 && 100 >= 100;
    lemma test5: -100 <= -100 && 100 >= 100 && -100 >= -100 && 100 <= 100;
    lemma test6: -100 <= -100 && 100 <= 100 && -100 >= -100 && 100 >= 100;
*/
