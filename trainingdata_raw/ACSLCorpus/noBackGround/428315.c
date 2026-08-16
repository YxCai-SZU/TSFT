/*@
requires a > 0 && b > 0;
ensures \result == a;
*/
int non_linear_arith_example20(int a, int b) {
    //@ assert a > 0 && b > 0;
    int result;
    result = (a * b) / b;
    //@ assert result == a;
    return result;
}

int main() {
    return 0;
}
