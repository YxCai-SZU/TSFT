/*@
    requires ((a) > 0) && ((b) > 0);
    ensures \true;
*/
void non_linear_arith_example2(int a, int b) {
    //@ assert ((a) >= 0) && ((b) >= 0);
    //@ assert a * b >= 0;
    //@ assert a * b <= a * b;
}

int main() {
    return 0;
}
