/*@
    requires ((a) <= (b) && (b) <= (c)) && ((a) >= 0);
    ensures \result == 0;
*/
int proof_context_exercise(int a, int b, int c) {
    //@ assert a <= b;
    //@ assert b <= c;
    //@ assert a <= c;
    //@ assert a >= 0;
    //@ assert c >= 0;
    return 0;
}

int main() {
    return 0;
}
