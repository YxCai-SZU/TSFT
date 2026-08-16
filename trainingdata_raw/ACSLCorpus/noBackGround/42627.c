/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100);
    ensures \result == ((a) * (b)) || \result == -1;
    ensures -1 <= \result <= 10000;
    assigns \nothing;
*/
int func(unsigned int a, unsigned int b)
{
    // Variable declarations at scope top
    unsigned int product;
    int result;

    product = a * b;

    //@ assert product <= 10000;

    if (product <= 10000) {
        result = (int)product;
    } else {
        result = -1;
    }

    //@ assert result == (int)product || result == -1;
    //@ assert -1 <= result <= 10000;

    return result;
}
