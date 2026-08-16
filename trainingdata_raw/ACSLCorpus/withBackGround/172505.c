/*@
    predicate valid_range(integer n) = 1 <= n && n <= 10000;
    
    logic integer compute_a(integer n, integer i) = 
        n - i >= 0 ? n - i : 0;
    
    predicate loop_invariant(integer n, integer i, integer a) =
        valid_range(n) &&
        1 <= i && i <= 2019 &&
        (a == 0 || (i > 1 ==> a == n - (i - 1)));
    
    lemma loop_decreases: \forall integer i; 1 <= i && i < 2019 ==> 2019 - i > 0;
*/

/*@
    requires valid_range(n);
    ensures \result == 0 || \result == 1;
    assigns \nothing;
*/
int func(int n)
{
    int a;
    int i;
    
    a = 0;
    i = 1;
    
    /*@
        loop invariant loop_invariant(n, i, a);
        loop invariant 2019 - i >= 0;
        loop assigns a, i;
        loop variant 2019 - i;
    */
    while (i < 2019)
    {
        //@ assert loop_invariant(n, i, a);
        
        if (n - i >= 0)
        {
            a = n - i;
        }
        else
        {
            a = 0;
        }
        
        //@ assert a == compute_a(n, i);
        
        i = i + 1;
        
        //@ assert loop_invariant(n, i, a);
    }
    
    //@ assert loop_invariant(n, i, a);
    
    if (a == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

/*@
    requires valid_range(n);
    ensures \result == 0 || \result == 1;
    assigns \nothing;
*/
int func2(int n)
{
    int a;
    int i;
    
    a = 0;
    i = 1;
    
    /*@
        loop invariant loop_invariant(n, i, a);
        loop invariant 2019 - i >= 0;
        loop assigns a, i;
        loop variant 2019 - i;
    */
    while (i < 2019)
    {
        //@ assert loop_invariant(n, i, a);
        
        if (n - i >= 0)
        {
            a = n - i;
        }
        else
        {
            a = 0;
        }
        
        //@ assert a == compute_a(n, i);
        
        i = i + 1;
        
        //@ assert loop_invariant(n, i, a);
    }
    
    //@ assert loop_invariant(n, i, a);
    
    if (a == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
