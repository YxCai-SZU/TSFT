/*@
    requires (1 <= (n) && (n) <= 9);
    ensures \result == ((n) * (n) * (n));
    assigns \nothing;
*/
int func(int n)
{
    // Variable declarations at top of scope
    int n_mut = n;
    int result;
    
    //@ assert (1 <= (n_mut) && (n_mut) <= 9);
    
    //@ assert 1 <= n_mut * n_mut <= 81;
    //@ assert 1 <= n_mut * n_mut * n_mut <= 729;
    //@ assert 1 <= n_mut * n_mut * n_mut;
    //@ assert n_mut * n_mut * n_mut <= 729;
    
    result = n * n * n;
    
    //@ assert result == ((n) * (n) * (n));
    return result;
}
