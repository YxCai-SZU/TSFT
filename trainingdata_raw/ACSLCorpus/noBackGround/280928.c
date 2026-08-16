/*@
    requires n < 2;
    ensures \result == (n % 2 == 0);
    assigns \nothing;
*/
int is_even(unsigned int n) {
    //@ assert n < 2;
    return n % 2 == 0;
}

/*@
    requires n < 2;
    ensures \result == (n % 2 != 0);
    assigns \nothing;
*/
int is_odd(unsigned int n) {
    //@ assert n < 2;
    return n % 2 != 0;
}

/*@
    requires x < 2;
    assigns \nothing;
*/
void test_is_even_and_odd(unsigned int x) {
    //@ assert x % 2 == 0 || x % 2 != 0;
    //@ assert !(x % 2 == 0 && x % 2 != 0);
    //@ assert x < 2;
}
