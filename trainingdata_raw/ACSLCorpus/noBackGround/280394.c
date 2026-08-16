/*@
    requires 0 <= x && x <= 10;
    ensures \result == x * 2 + 2;
    ensures \result <= 22;
*/
int func(int x) {
    //@ assert 0 <= x && x <= 10;
    int result;
    result = x * 2 + 2;
    //@ assert result <= 22;
    return result;
}

/*@
    requires 0 <= x && x <= 10;
    ensures 2 <= \result && \result <= 22;
*/
int func_range(int x) {
    //@ assert 0 <= x && x <= 10;
    int result;
    result = x * 2 + 2;
    //@ assert 2 <= result && result <= 22;
    return result;
}

/*@
    requires 0 <= x && x <= 10;
    ensures \result == x * 2 + 2;
    ensures \result <= 22;
*/
int func_uninterpreted(int x) {
    //@ assert 0 <= x && x <= 10;
    int result;
    result = x * 2 + 2;
    //@ assert result <= 22;
    return result;
}

/*@
    requires 0 <= x && x <= 10;
    ensures \result == x * 2 + 2;
    ensures \result <= 22;
*/
int func_bool(int x) {
    //@ assert 0 <= x && x <= 10;
    int result;
    result = x * 2 + 2;
    //@ assert result <= 22;
    return result;
}

/*@
    requires 0 <= x && x <= 10;
    ensures \result == x * 2 + 2;
    ensures \result <= 22;
*/
int func_arith(int x) {
    //@ assert 0 <= x && x <= 10;
    int result;
    result = x * 2 + 2;
    //@ assert result <= 22;
    return result;
}

int main() {
    return 0;
}
