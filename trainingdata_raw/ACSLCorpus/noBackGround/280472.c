/*@
    requires 1 <= n;
    ensures \result == n + 1;
    ensures \result >= 2;
*/
int example_4(int n) {
    //@ assert 1 <= n;
    int result = n + 1;
    //@ assert result >= 2;
    return result;
}

int main() {
    return 0;
}
