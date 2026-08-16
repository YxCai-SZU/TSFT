/*@
    requires (1 <= (a) <= 5000) && (1 <= (b) <= 5000) && (1 <= (c) <= 5000);
    ensures \result == (a + b >= c);
    assigns \nothing;
*/
int func(int a, int b, int c) {
    int d;
    //@ assert (1 <= (a) <= 5000) && (1 <= (b) <= 5000) && (1 <= (c) <= 5000);
    d = a + b;
    //@ assert d == a + b;
    return d >= c;
}

