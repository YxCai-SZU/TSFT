/*@
    requires ((y) <= (x));
    ensures \result == x - y;
    assigns \nothing;
*/
unsigned int subtract(unsigned int x, unsigned int y) {
    unsigned int result;
    //@ assert y <= x;
    result = x - y;
    //@ assert result == x - y;
    return result;
}

/*@
    requires (0 <= (y) && (y) <= 50);
    ensures \result == 100 - y;
    assigns \nothing;
*/
unsigned int subtractor(unsigned int y) {
    unsigned int res;
    //@ assert 0 <= y && y <= 50;
    res = 100 - y;
    //@ assert res == 100 - y;
    return res;
}

int main() {
    unsigned int r1;
    r1 = subtractor(20);
    //@ assert r1 == 80;
    return 0;
}
