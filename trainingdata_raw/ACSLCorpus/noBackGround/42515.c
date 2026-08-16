/*@
    requires a > 2;
    ensures \result > 3;
*/
int calc_example_7(int a) {
    int result;

    //@ assert a > 2;
    result = a + 3;
    //@ assert result > 3;
    
    return result;
}

int main() {
    return 0;
}
