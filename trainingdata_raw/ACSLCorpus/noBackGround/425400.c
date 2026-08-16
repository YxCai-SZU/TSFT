/*@
    requires (1 <= (a) && (a) <= 100) && (1 <= (b) && (b) <= 100);
    ensures \result == (a * b % 2 == 0);
*/
int func(unsigned int a, unsigned int b) {
    unsigned int product;
    int is_even;

    //@ assert a * b <= 10000;
    product = a * b;
    is_even = (product % 2 == 0);

    //@ assert product == a * b;
    //@ assert is_even == (a * b % 2 == 0);

    return is_even;
}
