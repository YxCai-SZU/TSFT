/*@
    requires a >= b;
    ensures \result >= 0;
*/
int sub_function(int a, int b) {
    //@ assert a >= b;
    int result = a - b;
    //@ assert result >= 0;
    return result;
}

/*@
    requires a >= 0 && b >= 0 && a + b <= 1000;
    ensures \result >= 0;
*/
int add_function(int a, int b) {
    //@ assert a >= 0 && b >= 0 && a + b <= 1000;
    int result = a + b;
    //@ assert result >= 0;
    return result;
}

int main() {
    return 0;
}
