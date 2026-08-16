/*@
    requires x == 5;
    ensures \result == 5;
*/
int proof_equality_example(int x) {
    //@ assert x == 5;
    return x;
}

/*@
    requires x <= 5;
    requires 5 <= y;
    ensures \result <= y;
*/
int proof_order_example(int x, int y) {
    //@ assert x <= 5;
    //@ assert 5 <= y;
    //@ assert x <= y;
    return x;
}

int main() {
    return 0;
}
