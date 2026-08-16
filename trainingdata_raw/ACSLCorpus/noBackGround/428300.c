/*@
    requires n >= 0 && n <= 100;
    ensures \result == n * n;
    ensures \result <= 10000;
*/
int square(int n) {
    //@ assert n >= 0 && n <= 100;
    //@ assert n * n <= 10000;
    return n * n;
}

/*@
    requires a >= 0 && b >= 0;
    requires a <= 100 && b <= 100;
    ensures \result == a * a + b * b;
    ensures \result <= 20000;
*/
int sum_of_squares(int a, int b) {
    int a_sq;
    int b_sq;
    int result;
    
    //@ assert a >= 0 && a <= 100;
    a_sq = square(a);
    
    //@ assert b >= 0 && b <= 100;
    b_sq = square(b);
    
    //@ assert a_sq == a * a && b_sq == b * b;
    //@ assert a_sq <= 10000 && b_sq <= 10000;
    //@ assert a_sq + b_sq <= 20000;
    
    result = a_sq + b_sq;
    return result;
}

int main() {
    return 0;
}
