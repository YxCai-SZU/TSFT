/*@
    predicate is_valid_range(integer n) = 1 <= n && n <= 100;
    predicate is_valid_double(integer n) = 1 <= n && n <= 200;
    
    lemma property_example:
        \forall integer n; is_valid_range(n) ==> is_valid_double(n * 2);
*/

/*@
    requires 1 <= n && n <= 100;
    ensures 1 <= \result && \result <= 200;
    assigns \nothing;
*/
int property_example(int n) {
    int result;
    
    //@ assert 1 <= n && n <= 100;
    
    result = n * 2;
    
    //@ assert 1 <= result && result <= 200;
    
    return result;
}

int main() {
    return 0;
}
