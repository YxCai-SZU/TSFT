/*@
    requires a >= 1;
    ensures \result == 1;
    assigns \nothing;
*/
int square_consecutive_int(int a) {
    //@ assert a >= 1;
    //@ assert a * a < (a + 1) * (a + 1);
    return 1;
}

/*@
    assigns \nothing;
*/
void calc_example_6(void) {
    int a;
    //@ assert a * 2 == 2 * a;
}

int main(void) {
    return 0;
}
