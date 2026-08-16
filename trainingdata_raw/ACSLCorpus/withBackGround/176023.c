/*@
    predicate is_valid_range(integer r) = 1 <= r <= 100;
    predicate pi_constant(integer pi) = pi == 314159;
    
    logic integer initial_product(integer pi, integer r) = 2 * pi * r;
    logic integer expected_result(integer pi, integer r, integer divisor) = 
        (2 * pi * r) / divisor;
    
    lemma product_identity: 
        \forall integer pi, integer r; 
        pi == 314159 ==> 2 * pi * r == 2 * 314159 * r;
*/

/*@
    requires is_valid_range(r);
    ensures \result == (2 * 314159 * r) / 100000;
*/
int func(int r) {
    int pi;
    int result;
    int temp;
    int divisor;
    
    pi = 314159;
    result = 0;
    temp = 2 * pi * r;
    divisor = 100000;
    
    /*@
        loop invariant is_valid_range(r);
        loop invariant pi_constant(pi);
        loop invariant 0 <= temp <= initial_product(pi, r);
        loop invariant temp == initial_product(pi, r) - result * divisor;
        loop invariant result == (initial_product(pi, r) - temp) / divisor;
        loop invariant 0 <= result;
        loop invariant result <= expected_result(pi, r, divisor);
        loop invariant initial_product(pi, r) == 2 * 314159 * r;
        loop assigns temp, result;
        loop variant temp;
    */
    while (temp >= divisor) {
        temp -= divisor;
        result += 1;
    }
    
    //@ assert temp < divisor;
    //@ assert result <= expected_result(pi, r, divisor);
    //@ assert result * divisor + temp == initial_product(pi, r);
    
    return result;
}

int main() {
    return 0;
}
