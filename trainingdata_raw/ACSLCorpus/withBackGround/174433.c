#include <limits.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 9;

    logic integer expr1(integer a, integer b, integer c) = a * 10 + b + c;
    logic integer expr2(integer a, integer b, integer c) = a + b * 10 + c;
    logic integer expr3(integer a, integer b, integer c) = a + b + c * 10;

    lemma expr1_ge_11: \forall integer a, b, c; 
        valid_range(a) && valid_range(b) && valid_range(c) ==> expr1(a,b,c) >= 11;
    lemma expr2_ge_11: \forall integer a, b, c; 
        valid_range(a) && valid_range(b) && valid_range(c) ==> expr2(a,b,c) >= 11;
    lemma expr3_ge_11: \forall integer a, b, c; 
        valid_range(a) && valid_range(b) && valid_range(c) ==> expr3(a,b,c) >= 11;
*/

/*@
    requires 1 <= a <= 9;
    requires 1 <= b <= 9;
    requires 1 <= c <= 9;
    ensures \result == expr1(a,b,c) || 
            \result == expr2(a,b,c) || 
            \result == expr3(a,b,c);
    ensures \result >= 11;
*/
int func(int a, int b, int c)
{
    int mx;
    int tmp;

    mx = a * 10 + b + c;
    tmp = a + b * 10 + c;
    
    //@ assert mx >= expr1(a,b,c);
    
    if (tmp > mx)
    {
        mx = tmp;
    }
    
    //@ assert mx >= expr1(a,b,c);
    //@ assert mx >= expr2(a,b,c);
    
    tmp = a + b + c * 10;
    
    if (tmp > mx)
    {
        mx = tmp;
    }
    
    //@ assert mx >= expr1(a,b,c);
    //@ assert mx >= expr2(a,b,c);
    //@ assert mx >= expr3(a,b,c);
    
    //@ assert expr1(a,b,c) >= 11;
    //@ assert expr2(a,b,c) >= 11;
    //@ assert expr3(a,b,c) >= 11;
    //@ assert mx >= 11;
    
    return mx;
}
