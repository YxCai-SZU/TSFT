/*@
requires n % 3 == 0;
ensures (n + 6) % 3 == 0;
*/
void example_6_func(int n) {
    //@ assert n % 3 == 0;
    //@ assert (n + 6) % 3 == n % 3;
    //@ assert (n + 6) % 3 == 0;
}

/*@
requires m % 3 == 1;
ensures (m + 6) % 3 == 1;
*/
void example_7_func(int m) {
    //@ assert m % 3 == 1;
    //@ assert (m + 6) % 3 == m % 3;
    //@ assert (m + 6) % 3 == 1;
}

/*@
requires k % 3 == 2;
ensures (k + 6) % 3 == 2;
*/
void example_8_func(int k) {
    //@ assert k % 3 == 2;
    //@ assert (k + 6) % 3 == k % 3;
    //@ assert (k + 6) % 3 == 2;
}

int main() {
    return 0;
}
