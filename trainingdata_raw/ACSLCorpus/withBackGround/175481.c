/*@
    predicate valid_range(integer x) = 1 <= x <= 9;

    logic integer expr1(integer a, integer b, integer c) = a * 10 + b + c;
    logic integer expr2(integer a, integer b, integer c) = a + b * 10 + c;
    logic integer expr3(integer a, integer b, integer c) = a + b + c * 10;

    lemma expr1_bounds: \forall integer a,b,c; valid_range(a) && valid_range(b) && valid_range(c) ==> expr1(a,b,c) <= 9*10+9+9;
    lemma expr2_bounds: \forall integer a,b,c; valid_range(a) && valid_range(b) && valid_range(c) ==> expr2(a,b,c) <= 9+9*10+9;
    lemma expr3_bounds: \forall integer a,b,c; valid_range(a) && valid_range(b) && valid_range(c) ==> expr3(a,b,c) <= 9+9+9*10;
    lemma result_nonneg: \forall integer a,b,c; valid_range(a) && valid_range(b) && valid_range(c) ==> 
        (expr1(a,b,c) >= 0 && expr2(a,b,c) >= 0 && expr3(a,b,c) >= 0);
*/

/*@
    requires valid_range(a) && valid_range(b) && valid_range(c);
    ensures \result == expr1(a,b,c) || \result == expr2(a,b,c) || \result == expr3(a,b,c);
    ensures \result >= 0;
*/
int func(int a, int b, int c) {
    int max1;
    int max2;
    
    //@ assert expr1(a,b,c) <= 9*10+9+9;
    //@ assert expr2(a,b,c) <= 9+9*10+9;
    //@ assert expr3(a,b,c) <= 9+9+9*10;
    
    if (a * 10 + b + c > a + b * 10 + c) {
        max1 = a * 10 + b + c;
    } else {
        max1 = a + b * 10 + c;
    }
    
    if (max1 > a + b + c * 10) {
        max2 = max1;
    } else {
        max2 = a + b + c * 10;
    }
    
    //@ assert max2 == expr1(a,b,c) || max2 == expr2(a,b,c) || max2 == expr3(a,b,c);
    //@ assert max2 >= 0;
    
    return max2;
}
