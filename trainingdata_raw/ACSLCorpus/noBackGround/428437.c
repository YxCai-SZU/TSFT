/*@
    requires 0 <= x && x <= 100;
    requires 0 <= y && y <= 100;
    ensures \result <= 500;
    assigns \nothing;
*/
int calculation_example(int x, int y) {
    // Variable declarations at scope top
    int result;

    //@ assert 2*x <= 200;
    //@ assert 3*y <= 300;
    //@ assert 2*x + 3*y <= 500;
    
    result = 2*x + 3*y;
    return result;
}

int main() {
    return 0;
}
