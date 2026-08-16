/*@
    requires a < b;
    ensures \result == 1;
*/
int calc_example_4_impl(int a, int b) {
    //@ assert a < b;
    //@ assert a < b + 1;
    return 1;
}

/*@
    requires n < 10;
    ensures \result == 1;
*/
int lemma_inequality_impl(int n) {
    //@ assert n < 10;
    return 1;
}

/*@
    requires n < 10;
    ensures \result == 1;
*/
int calc_example_5_impl(int n) {
    //@ assert n < 10;
    return 1;
}

int main() {
    int a;
    int b;
    int n;
    
    a = 5;
    b = 8;
    calc_example_4_impl(a, b);
    
    n = 7;
    lemma_inequality_impl(n);
    
    n = 3;
    calc_example_5_impl(n);
    
    return 0;
}
