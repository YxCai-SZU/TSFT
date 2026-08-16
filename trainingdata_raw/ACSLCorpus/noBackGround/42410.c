/*@
    requires 1 <= n && n <= 100;
    ensures \result == 1;
    assigns \nothing;
*/
int func(int n) {
    //@ assert 1 <= n && n <= 100;
    //@ assert n * n <= n * 100;
    return 1;
}
