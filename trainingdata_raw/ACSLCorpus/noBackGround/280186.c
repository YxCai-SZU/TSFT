/*@
    requires a > 0 && b > 0 && c > 0;
    ensures \result == (a * b) / c;
    ensures \result == (a / 1) * b / c;
*/
int non_linear_arith_example(int a, int b, int c) {
    //@ assert a > 0 && b > 0 && c > 0;
    int result = (a * b) / c;
    //@ assert result == (a / 1) * b / c;
    return result;
}

int main() {
    return 0;
}
