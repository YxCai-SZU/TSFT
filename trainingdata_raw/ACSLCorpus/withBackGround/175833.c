#include <limits.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 9;

    logic integer expr1(integer a, integer b, integer c) = a * 10 + b + c;
    logic integer expr2(integer a, integer b, integer c) = a + b * 10 + c;
    logic integer expr3(integer a, integer b, integer c) = a + b + c * 10;

    lemma expr1_bounds: \forall integer a,b,c; 
        valid_range(a) && valid_range(b) && valid_range(c) ==> 
        expr1(a,b,c) <= 108 && expr1(a,b,c) >= 12;
    lemma expr2_bounds: \forall integer a,b,c; 
        valid_range(a) && valid_range(b) && valid_range(c) ==> 
        expr2(a,b,c) <= 108 && expr2(a,b,c) >= 12;
    lemma expr3_bounds: \forall integer a,b,c; 
        valid_range(a) && valid_range(b) && valid_range(c) ==> 
        expr3(a,b,c) <= 108 && expr3(a,b,c) >= 12;
*/

/*@
    requires valid_range(a) && valid_range(b) && valid_range(c);
    ensures \result == expr1(a,b,c) || 
            \result == expr2(a,b,c) || 
            \result == expr3(a,b,c);
    ensures \result >= 11;
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    // Declare all variables at the top
    int max;
    int expr1_val;
    int expr2_val;
    int expr3_val;
    int temp1;
    int temp2;
    int temp3;
    int temp4;

    //@ assert a * 10 <= 90;
    //@ assert b * 10 <= 90;
    //@ assert c * 10 <= 90;

    expr1_val = a * 10 + b + c;
    expr2_val = a + b * 10 + c;
    expr3_val = a + b + c * 10;

    // First comparison branch
    if (expr1_val > expr2_val)
    {
        // Second comparison branch
        if (expr1_val > expr3_val)
        {
            max = expr1_val;
        }
        else
        {
            max = expr3_val;
        }
    }
    else
    {
        // Second comparison branch
        if (expr2_val > expr3_val)
        {
            max = expr2_val;
        }
        else
        {
            max = expr3_val;
        }
    }

    return max;
}
