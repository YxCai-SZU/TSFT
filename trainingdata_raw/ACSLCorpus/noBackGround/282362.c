/*@
    requires (1 <= (N) && (N) <= 100000 &&
        1 <= (K) && (K) <= (N));
    ensures \result == ((N) - (K) + 1);
    assigns \nothing;
*/
unsigned int func(unsigned int N, unsigned int K)
{
    unsigned int result = N - K + 1;
    //@ assert result == ((N) - (K) + 1);
    return result;
}

/*@
    requires (1 <= (N) && (N) <= 100000 &&
        1 <= (K) && (K) <= (N));
    ensures \result == ((N) - (K) + 1);
    assigns \nothing;
*/
unsigned int func2(unsigned int N, unsigned int K)
{
    unsigned int result = N - K + 1;
    /*@
        assert (1 <= (N) && (N) <= 100000 &&
        1 <= (K) && (K) <= (N));
    */
    //@ assert result == ((N) - (K) + 1);
    return result;
}
