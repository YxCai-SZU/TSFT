/*@
    requires a <= 100 && b <= 100 && c <= 100 && d <= 100;
    ensures \result == 0;
    assigns \nothing;
*/
int nonlinear_arithmetic_example_3(unsigned long long a,
                                   unsigned long long b,
                                   unsigned long long c,
                                   unsigned long long d) {
    //@ assert a * b <= 10000;
    //@ assert c * d <= 10000;
    //@ assert a * b <= c * d || a * b >= c * d;
    return 0;
}

int main() {
    return 0;
}
