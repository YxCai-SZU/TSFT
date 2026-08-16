/*@
    requires 1 <= n <= 100;
    ensures n * (n + 1) / 2 <= 100 * (100 + 1) / 2;
*/
void verify_triangular_number(int n) {
    //@ assert 1 <= n && n <= 100;
    //@ assert n * (n + 1) / 2 <= 100 * (100 + 1) / 2;
}

int main() {
    return 0;
}
