/*@
requires a + b >= 5;
ensures b + a >= 5;
*/
void calc_geq_example(int a, int b) {
    //@ assert a + b >= 5;
    //@ assert b + a >= 5;
}

/*@
requires a > 0 && b > 0;
ensures a * b > 0;
*/
void lemma(int a, int b) {
    //@ assert a * b > 0;
}

/*@
requires 0 <= n && n <= 100 && 0 <= m && m <= 100;
ensures n * m <= 10000;
*/
void example_cals(int n, int m) {
    //@ assert n * m <= 10000;
}

/*@
requires n + m >= 5;
ensures m + n >= 5;
*/
void example_geq_example(int n, int m) {
    //@ assert n + m >= 5;
    //@ assert m + n >= 5;
}

/*@
requires n + m < 5;
ensures m + n < 5;
*/
void example_less_example(int n, int m) {
    //@ assert n + m < 5;
    //@ assert m + n < 5;
}

/*@
requires n + m == 5;
ensures m + n == 5;
*/
void example_equal_example(int n, int m) {
    //@ assert n + m == 5;
    //@ assert m + n == 5;
}

int main() {
    return 0;
}
