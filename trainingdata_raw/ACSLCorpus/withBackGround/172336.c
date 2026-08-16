/*@
    predicate positive(integer x) = x > 0;
    
    lemma multiplication_commutative:
        \forall integer a, b, c;
            positive(a) && positive(b) && positive(c) ==>
            a * b * c == b * c * a;
*/

/*@
    requires a > 0 && b > 0 && c > 0;
    ensures \result == 0;
    assigns \nothing;
*/
int non_linear_arith_example8(int a, int b, int c) {
    //@ assert a > 0 && b > 0 && c > 0;
    //@ assert a * b * c == b * c * a;
    return 0;
}

/*@
    requires a > 0 && b > 0 && c > 0;
    ensures \result == 0;
    assigns \nothing;
*/
int non_linear_arith_example8_test(int a, int b, int c) {
    //@ assert a > 0 && b > 0 && c > 0;
    int result;
    result = non_linear_arith_example8(a, b, c);
    return result;
}
