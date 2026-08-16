/*@
    requires 2 <= a && a <= 100;
    requires 2 <= b && b <= 100;
    ensures \result == (a - 1) * (b - 1);
    assigns \nothing;
*/
unsigned int func(unsigned int a, unsigned int b)
{
    // Variable declarations at top of scope
    unsigned int a_minus_one;
    unsigned int b_minus_one;
    unsigned int result;

    //@ assert 2 <= a && a <= 100;
    a_minus_one = a - 1;

    //@ assert 2 <= b && b <= 100;
    b_minus_one = b - 1;

    //@ assert a_minus_one * b_minus_one <= 9801;
    result = a_minus_one * b_minus_one;

    return result;
}
