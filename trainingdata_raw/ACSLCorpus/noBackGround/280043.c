/*@
    requires 1 <= n <= 100;
    requires n % 3 == 0;
    ensures (n + 3) % 3 == 0;
*/
void func(int n) {
    //@ assert 1 <= n <= 100;
    //@ assert n % 3 == 0;
    
    //@ assert n == 3 * (n / 3);
    //@ assert n + 3 == 3 * (n / 3) + 3;
    //@ assert n + 3 == 3 * (n / 3 + 1);
    //@ assert (n + 3) % 3 == 0;
}
