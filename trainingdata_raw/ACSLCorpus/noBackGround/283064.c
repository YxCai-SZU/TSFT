/*@
    requires x > 0 && a > 0 && b > 0;
    ensures \result == x * (a + b);
    assigns \nothing;
*/
int compute_example(int x, int a, int b) {
    //@ assert x * (a + b) == x * a + x * b;
    return x * (a + b);
}

int main() {
    int x = 1;
    int a = 1;
    int b = 1;
    
    int result = compute_example(x, a, b);
    //@ assert result == x * a + x * b;
    //@ assert (x * a) + (x * b) == (x * (a + b));
    //@ assert (x * (a + b) * 3) == (x * a * 3 + x * b * 3);
    
    return 0;
}
