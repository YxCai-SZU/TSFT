/*@
    requires ((a) <= (b) && (b) <= (c) && (c) <= (d) && (d) - (a) <= 5);
    ensures \result == 0;
    ensures a <= d && d - a <= 5;
*/
int example(int a, int b, int c, int d) {
    //@ assert a <= b;
    //@ assert b <= c;
    //@ assert c <= d;
    //@ assert d - a <= 5;
    //@ assert a <= d;
    return 0;
}

int main() {
    return 0;
}
