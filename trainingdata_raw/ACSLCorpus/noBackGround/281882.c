/*@
    requires (1 <= (n) && (n) <= 10000) && ((n) >= 0);
    ensures \result >= 0 && \result < 1000;
    ensures \result == ((1000 - ((n) % 1000)) % 1000);
    assigns \nothing;
*/
int func(int n)
{
    unsigned int n_unsigned;
    unsigned int res_unsigned;
    int res_signed;

    //@ assert n >= 0;
    n_unsigned = (unsigned int)n;
    res_unsigned = (1000 - n_unsigned % 1000) % 1000;
    res_signed = (int)res_unsigned;

    //@ assert res_signed >= 0 && res_signed < 1000;
    return res_signed;
}
