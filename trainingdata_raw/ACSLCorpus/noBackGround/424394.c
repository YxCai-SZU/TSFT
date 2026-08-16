/*@
    requires (1 <= (n) && 1 <= (m) && (n) <= 1000000000000 && (m) <= 1000000000000);
    ensures \result <= n + m;
    ensures \result >= 0;
    assigns \nothing;
*/
unsigned long long func(unsigned long long n, unsigned long long m)
{
    // Variable declarations at top of scope
    unsigned long long result;
    unsigned long long rem;
    
    //@ assert (1 <= (n) && 1 <= (m) && (n) <= 1000000000000 && (m) <= 1000000000000);
    
    if (n * 2 > m) {
        //@ assert m / 2 <= n + m;
        result = m / 2;
    } else {
        rem = m - n * 2;
        //@ assert rem <= m;
        result = n + (rem / 4);
    }
    
    return result;
}
