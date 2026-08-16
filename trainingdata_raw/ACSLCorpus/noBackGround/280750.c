/*@
requires n > 0;
ensures n < n + 2;
*/
void calc_example_6(int n) {
    //@ assert n > 0;
    //@ assert n < n + 1;
    //@ assert n + 1 < n + 2;
}

/*@
requires m > 0 && n > 0;
ensures m * n < m * (n + 2);
*/
void calc_example_7(int m, int n) {
    //@ assert m > 0 && n > 0;
    //@ assert m * n < m * (n + 1);
    //@ assert m * (n + 1) < m * (n + 2);
}

int main() {
    return 0;
}
