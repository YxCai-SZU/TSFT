/*@
    predicate is_nonnegative(integer val) = val >= 0;

    lemma mult_distributive: \forall integer x, y, z; x * (y + z) == x * y + x * z;
    lemma division_nonnegative: \forall integer x, y; y > 0 && x >= y ==> x / y >= 0;
    lemma modulo_nonnegative: \forall integer x, y; y > 0 && x >= y ==> x % y >= 0;
*/

/*@
    requires y > 0 && x >= y;
    ensures \result >= 0;
    assigns \nothing;
*/
unsigned int verify_division(unsigned int x, unsigned int y) {
    unsigned int result;
    //@ assert y > 0 && x >= y;
    result = x / y;
    //@ assert is_nonnegative(result);
    return result;
}

/*@
    requires y > 0 && x >= y;
    ensures \result >= 0;
    assigns \nothing;
*/
unsigned int verify_modulo(unsigned int x, unsigned int y) {
    unsigned int result;
    //@ assert y > 0 && x >= y;
    result = x % y;
    //@ assert is_nonnegative(result);
    return result;
}

int main() {
    unsigned int a = 10;
    unsigned int b = 3;
    unsigned int c = 4;
    unsigned int div_result;
    unsigned int mod_result;
    
    //@ assert a * (b + c) == a * b + a * c;
    
    div_result = verify_division(a, b);
    //@ assert is_nonnegative(div_result);
    
    mod_result = verify_modulo(a, b);
    //@ assert is_nonnegative(mod_result);
    
    return 0;
}
