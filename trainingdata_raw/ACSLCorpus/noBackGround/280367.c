/*@
    requires ((a) >= 1) && ((b) >= 1) && ((a) * (b) >= 2);
    ensures ((a) * (b) >= 2);
*/
void calc_example_10(int a, int b) {
    // Variable declarations at scope top
    // No local variables needed
    
    //@ assert a >= 1;
    //@ assert b >= 1;
    //@ assert a * b >= 2;
    //@ assert a * b >= 2;
}

int main() {
    return 0;
}
