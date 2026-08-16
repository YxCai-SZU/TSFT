/*@
    requires a <= 0xffffffff;
    requires b <= 0xffffffff;
    ensures \result == ((a & b) == (b & a));
    assigns \nothing;
*/
unsigned int func(unsigned int a, unsigned int b) {
    unsigned int result;
    //@ assert (a & b) == (a & b);
    //@ assert (b & a) == (b & a);
    result = ((a & b) == (b & a));
    //@ assert result == ((a & b) == (b & a));
    return result;
}
