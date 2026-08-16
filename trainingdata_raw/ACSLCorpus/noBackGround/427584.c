/*@
    requires a <= 2147483647;
    requires b <= 2147483647;
    requires c <= 2147483647;
    requires a >= -2147483648;
    requires b >= -2147483648;
    requires c >= -2147483648;
    ensures \result == (a < b && b < c);
*/
_Bool func(int a, int b, int c) {
    _Bool ok1;
    _Bool ok2;
    _Bool a_lt_b;
    _Bool b_lt_c;
    
    ok1 = 0;
    ok2 = 0;
    a_lt_b = 0;
    b_lt_c = 0;
    
    if (a < b) {
        a_lt_b = 1;
    }
    
    if (b < c) {
        b_lt_c = 1;
    }
    
    if (a_lt_b) {
        ok1 = 1;
    }
    if (b_lt_c) {
        ok2 = 1;
    }
    
    //@ assert ok1 == a_lt_b;
    //@ assert ok2 == b_lt_c;
    
    return ok1 && ok2;
}
