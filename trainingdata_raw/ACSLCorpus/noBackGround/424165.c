/*@
    requires ((a) < (b) && (b) < 10 && (a) > 0 && (b) > 0);
    ensures ((a) + 1 < (b) + 3);
    assigns \nothing;
*/
void example_calc_chain(int a, int b) {
    //@ assert b > a;
    //@ assert a > 0;
    //@ assert b > 0;
    //@ assert b + 3 > a;
    //@ assert b + 3 <= 13;
    //@ assert a + 1 <= 10;
    //@ assert b + 3 <= 13;
    //@ assert a + 1 < b + 3;
}

int main() {
    return 0;
}
