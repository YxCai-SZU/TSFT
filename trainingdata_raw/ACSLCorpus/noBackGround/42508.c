/*@
    requires ((x) <= (y));
    ensures \result == 1;
    assigns \nothing;
*/
int example_4(int x, int y) {
    // Variable declarations at top of scope
    int sum;
    int avg;
    int result;

    sum = x + y;
    avg = sum / 2;
    result = 1;

    //@ assert avg == (x + y) / 2;
    //@ assert x + y <= 2 * y;
    //@ assert (x + y) / 2 <= (2 * y) / 2;
    //@ assert (2 * y) / 2 == y;
    //@ assert avg <= y;

    return result;
}

int main() {
    return 0;
}
