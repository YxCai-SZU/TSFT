/*@
    requires (1 <= (k) && (k) <= 200);
    ensures \result == ((((k)) / 2) * ((((k)) + 1) / 2));
    assigns \nothing;
*/
unsigned long func(unsigned long k)
{
    unsigned long ans;
    unsigned long half_k;
    unsigned long half_k_plus_one;

    half_k = k / 2;
    //@ assert half_k == ((k) / 2);
    
    half_k_plus_one = (k + 1) / 2;
    //@ assert half_k_plus_one == (((k) + 1) / 2);
    
    ans = half_k * half_k_plus_one;
    //@ assert ans == ((((k)) / 2) * ((((k)) + 1) / 2));
    
    return ans;
}
