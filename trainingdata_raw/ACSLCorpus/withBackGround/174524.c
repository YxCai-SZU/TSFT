/*@
    predicate is_valid_x(integer x) = 1 <= x && x <= 1000000000;
    predicate loop1_inv(integer x, integer c) =
        is_valid_x(x) &&
        c >= 1 &&
        c <= x &&
        c <= 1000000000;
    predicate loop2_inv(integer x, integer c, integer r) =
        is_valid_x(x) &&
        r < c &&
        c >= 1 &&
        c <= x &&
        c <= 1000000000;
    lemma loop1_decreases: \forall integer x, integer c; loop1_inv(x, c) ==> x - c >= 0;
    lemma loop2_decreases: \forall integer c, integer r; c >= 1 && r < c ==> c - r > 0;
*/

/*@
    requires is_valid_x(x);
    ensures \result == 0 || \result == 1;
    assigns \nothing;
*/
int func(long long x) {
    long long c;
    long long result;
    
    //@ assert is_valid_x(x);
    c = 1;
    
    /*@
        loop invariant loop1_inv(x, c);
        loop assigns c;
        loop variant x - c;
    */
    while (c * 2 <= x) {
        //@ assert loop1_inv(x, c) && c * 2 <= x;
        c *= 2;
        //@ assert loop1_inv(x, c);
    }
    
    result = x - c;
    
    /*@
        loop invariant loop2_inv(x, c, result);
        loop assigns result;
        loop variant c - result;
    */
    while (result < 0) {
        //@ assert loop2_inv(x, c, result) && result < 0;
        result += c;
        //@ assert loop2_inv(x, c, result);
    }
    
    if (result == 0) {
        //@ assert result == 0;
        return 0;
    } else {
        //@ assert result != 0;
        return 1;
    }
}
