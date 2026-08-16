#include <limits.h>

/*@
    predicate valid_range(integer v) = 1 <= v <= 9;

    logic integer expr1(integer a, integer b, integer c) = a * 10 + b + c;
    logic integer expr2(integer a, integer b, integer c) = a + b * 10 + c;
    logic integer expr3(integer a, integer b, integer c) = a + b + c * 10;

    lemma bound_10a: \forall integer a; valid_range(a) ==> 10 * a <= 90;
    lemma bound_10b: \forall integer b; valid_range(b) ==> 10 * b <= 90;
    lemma bound_10c: \forall integer c; valid_range(c) ==> 10 * c <= 90;

    lemma bound_expr1: \forall integer a, b, c;
        valid_range(a) && valid_range(b) && valid_range(c) ==> 
        expr1(a,b,c) <= 90 + 9 + 9;
    lemma bound_expr2: \forall integer a, b, c;
        valid_range(a) && valid_range(b) && valid_range(c) ==> 
        expr2(a,b,c) <= 90 + 9 + 9;
    lemma bound_expr3: \forall integer a, b, c;
        valid_range(a) && valid_range(b) && valid_range(c) ==> 
        expr3(a,b,c) <= 90 + 9 + 9;
*/

/*@
    requires 1 <= A <= 9;
    requires 1 <= B <= 9;
    requires 1 <= C <= 9;
    ensures \result == expr1(A,B,C) || 
            \result == expr2(A,B,C) || 
            \result == expr3(A,B,C);
    ensures \result >= 11;
*/
int func(int A, int B, int C) {
    int max1;
    int max2;
    
    //@ assert valid_range(A);
    //@ assert valid_range(B);
    //@ assert valid_range(C);
    
    //@ assert 10 * A <= 90;
    //@ assert 10 * B <= 90;
    //@ assert 10 * C <= 90;
    
    //@ assert expr1(A,B,C) <= 90 + 9 + 9;
    //@ assert expr2(A,B,C) <= 90 + 9 + 9;
    //@ assert expr3(A,B,C) <= 90 + 9 + 9;
    
    if (A * 10 + B + C > A + B * 10 + C) {
        max1 = A * 10 + B + C;
    } else {
        max1 = A + B * 10 + C;
    }
    
    if (max1 > A + B + C * 10) {
        max2 = max1;
    } else {
        max2 = A + B + C * 10;
    }
    
    //@ assert max2 == expr1(A,B,C) || max2 == expr2(A,B,C) || max2 == expr3(A,B,C);
    //@ assert max2 >= 11;
    
    return max2;
}
