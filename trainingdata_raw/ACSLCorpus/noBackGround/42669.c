/*@
    requires n > 0;
    ensures \result > n;
*/
int example_usage(int n) {
    int x;
    int result;

    x = n + 1;
    //@ assert x > n;
    //@ assert ((x) + 1) > n;
    result = x + 1;

    return result;
}
