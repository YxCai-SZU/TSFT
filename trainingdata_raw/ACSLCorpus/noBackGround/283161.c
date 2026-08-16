/*@
    requires 1 <= a <= 10000;
    requires 1 <= b <= 10000;
    ensures \result == (((a) * (b)) % 2 != 0);
    assigns \nothing;
*/
int func(int a, int b) {
    int ret;
    //@ assert ((a) * (b)) <= 100000000;
    ret = (a * b) % 2 != 0;
    return ret;
}
