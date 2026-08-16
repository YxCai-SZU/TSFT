/*@
    requires (1 <= (N) && 1 <= (M) && (N) <= 1000000000000 && (M) <= 1000000000000);
    ensures \result >= 0;
    ensures \result <= ((N) + (M) / 2);
    assigns \nothing;
*/
unsigned long long func(unsigned long long N, unsigned long long M)
{
    unsigned long long result = 0;
    //@ assert (1 <= (N) && 1 <= (M) && (N) <= 1000000000000 && (M) <= 1000000000000);
    
    if (N > M / 2)
    {
        result = M / 2;
        //@ assert result >= 0;
    }
    else
    {
        result = N;
        N = 0;
        //@ assert result >= 0;
    }
    
    //@ assert result <= ((N) + (M) / 2);
    return result;
}
