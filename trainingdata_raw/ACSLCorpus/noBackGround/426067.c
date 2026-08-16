/*@
    requires (1 <= (n) && (n) <= 100);
    ensures ((\result) >= 1 && (\result) <= (n));
*/
int func(int n) {
    int result;
    //@ assert (1 <= (n) && (n) <= 100);
    result = 1;
    //@ assert ((result) >= 1 && (result) <= (n));
    return result;
}
