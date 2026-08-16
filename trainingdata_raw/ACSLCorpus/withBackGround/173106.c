/*@
    predicate is_in_range(integer n) = 1 <= n && n <= 10;
    predicate product_in_range(integer n, integer m) = 1 <= n * m && n * m <= 100;
    
    logic integer double_val(integer x) = x * 2;
    
    lemma double_monotonic:
        \forall integer a, b; a <= b ==> double_val(a) <= double_val(b);
    
    lemma product_bound:
        \forall integer n, m; is_in_range(n) && is_in_range(m) ==> product_in_range(n, m);
*/

/*@
    requires a <= b;
    ensures \result == 1;
    assigns \nothing;
*/
int calc_example_7(int a, int b) {
    //@ assert double_val(a) <= double_val(b);
    return 1;
}

/*@
    requires 1 <= n && n <= 10;
    requires 1 <= m && m <= 10;
    ensures \result == 1;
    assigns \nothing;
*/
int product_property(int n, int m) {
    //@ assert is_in_range(n);
    //@ assert is_in_range(m);
    //@ assert product_in_range(n, m);
    return 1;
}

int main() {
    return 0;
}
