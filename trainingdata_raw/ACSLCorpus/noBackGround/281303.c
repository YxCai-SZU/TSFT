/*@
    requires (0 <= (n) && (n) <= 1);
    ensures \result == (((n) == 0) ? 1 : 0);
    assigns \nothing;
*/
int func(int n)
{
    int ary[2];
    int res;
    
    ary[0] = 1;
    ary[1] = 0;
    
    //@ assert n == 0 || n == 1;
    
    //@ assert n == 0 ==> ary[0] == 1;
    //@ assert n == 1 ==> ary[1] == 0;
    
    res = ary[n];
    
    //@ assert res == (((n) == 0) ? 1 : 0);
    
    return res;
}
