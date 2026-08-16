/*@
    predicate valid_range(integer a, integer b) =
        1 <= a <= 100 && 1 <= b <= 100;
    
    logic integer product(integer a, integer b) = a * b;
    
    logic integer target_result(integer a, integer b) = 
        (product(a, b) + 1) / 2;
    
    lemma product_bound: 
        \forall integer a, b; valid_range(a, b) ==> product(a, b) <= 10000;
*/

/*@
    requires valid_range(a, b);
    ensures \result == target_result(a, b);
    assigns \nothing;
*/
int func(unsigned long long a, unsigned long long b) {
    // Variable declarations at scope top
    unsigned long long product;
    int result;
    unsigned long long remainder;
    
    //@ assert valid_range(a, b);
    
    product = a * b;
    //@ assert product == product(a, b);
    
    //@ assert product <= 10000;
    
    result = 0;
    remainder = product;
    
    /*@
        loop invariant 1 <= a <= 100;
        loop invariant 1 <= b <= 100;
        loop invariant result == (product - remainder) / 2;
        loop invariant remainder <= product;
        loop invariant remainder >= 0;
        loop invariant product == a * b;
        loop invariant result >= 0;
        loop invariant remainder + 2 * result == product;
        loop assigns remainder, result;
        loop variant remainder;
    */
    while (remainder >= 2) {
        remainder -= 2;
        result += 1;
    }
    
    if (remainder == 1) {
        result += 1;
    }
    
    //@ assert result == target_result(a, b);
    return result;
}

int main() {
    return 0;
}
