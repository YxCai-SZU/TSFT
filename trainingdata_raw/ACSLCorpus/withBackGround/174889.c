/*@
    predicate is_valid(integer a, integer b) = a >= 3 && b == 2;
    
    lemma calc_example_lemma:
        \forall integer a, b; is_valid(a, b) ==> a + 3 >= a;
    
    lemma non_linear_arith_example_lemma:
        \forall integer a, b; is_valid(a, b) ==> (a + 3) * b >= a * b;
*/

/*@
    requires is_valid(a, b);
    ensures \result == 0;
*/
int calc_example(int a, int b) {
    //@ assert is_valid(a, b);
    //@ assert a + 3 >= a;
    return 0;
}

/*@
    requires is_valid(a, b);
    ensures \result == 0;
*/
int non_linear_arith_example(int a, int b) {
    //@ assert is_valid(a, b);
    //@ assert (a + 3) * b >= a * b;
    return 0;
}

int main() {
    int a;
    int b;
    
    a = 3;
    b = 2;
    
    calc_example(a, b);
    non_linear_arith_example(a, b);
    
    return 0;
}
