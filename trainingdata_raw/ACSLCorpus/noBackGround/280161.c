/*@
    requires ((x) >= 1 && (y) >= 1 && (x) <= 10 && (y) <= 10);
    ensures \result == x * y;
    ensures \result <= 100;
*/
int proof_mul_correctness(int x, int y) {
    //@ assert x <= 10;
    //@ assert y <= 10;
    //@ assert x * y <= 10 * 10;
    //@ assert x * y <= 100;
    
    return x * y;
}

int main() {
    return 0;
}
