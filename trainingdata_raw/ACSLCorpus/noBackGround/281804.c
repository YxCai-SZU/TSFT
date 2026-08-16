/*@
    requires (0 <= (n) && (n) <= 65535);
    ensures \result == ((n) * ((n) + 1) / 2);
    ensures \result <= n * n;
    assigns \nothing;
*/
unsigned int find_triangular_num(unsigned int n)
{
    // Variable declarations at the top
    unsigned int result;

    //@ assert n <= 65535;
    //@ assert n + 1 <= 65536;
    //@ assert n * (n + 1) <= 65535 * 65536;
    //@ assert n * (n + 1) / 2 <= (65535 * 65536) / 2;
    //@ assert n * n <= 65535 * 65535;
    //@ assert n * (n + 1) / 2 <= n * n;

    result = n * (n + 1) / 2;
    return result;
}
