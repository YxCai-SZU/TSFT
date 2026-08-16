/*@
    requires (0 <= (x) && (x) <= 10 &&
        5 <= (y) && (y) <= 15);
    ensures \result == 0;
*/
int assert_bounds(int x, int y) {
    //@ assert x <= 10;
    //@ assert 5 <= y;
    return 0;
}

int main() {
    int x = 5;
    int y = 10;
    //@ assert (0 <= (x) && (x) <= 10 &&         5 <= (y) && (y) <= 15);
    assert_bounds(x, y);
    return 0;
}
