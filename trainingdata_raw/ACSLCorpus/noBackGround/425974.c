/*@
    requires (1 <= (m) && (m) <= 10 && 1 <= (n) && (n) <= 10);
    ensures (1 <= (m) * (n) && (m) * (n) <= 100);
*/
void func(int m, int n) {
    //@ assert (1 <= (m) && (m) <= 10 && 1 <= (n) && (n) <= 10);
    //@ assert (1 <= (m) * (n) && (m) * (n) <= 100);
}

/*@
    requires (1 <= (m) && (m) <= 10 && 1 <= (n) && (n) <= 10);
*/
void assertionproof(int m, int n) {
    //@ assert (1 <= (m) && (m) <= 10 && 1 <= (n) && (n) <= 10);
    //@ assert (1 <= (m) * (n) && (m) * (n) <= 100);
    //@ assert m * n >= 1;
    //@ assert m * n <= 100;
}
