/*@
    predicate valid_range(integer a, integer b, integer c) =
        0 <= a && a <= b && b <= c && c <= 100;

    lemma complex_calc_lemma:
        \forall integer a, b, c;
        valid_range(a, b, c) ==> a + b + c <= 300;
*/

/*@
    requires valid_range(a, b, c);
    ensures \result == (a + b + c <= 300);
    assigns \nothing;
*/
int complex_calc(int a, int b, int c) {
    // Variable declarations at top of scope
    int result;

    //@ assert valid_range(a, b, c);
    
    //@ assert a + b + c <= 300;
    result = (a + b + c) <= 300;
    
    return result;
}

/*@
    assigns \nothing;
*/
int main() {
    return 0;
}
