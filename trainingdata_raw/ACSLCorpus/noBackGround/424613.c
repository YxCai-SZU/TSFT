/*@
    requires (1 <= (a) && (a) <= 9);
    ensures \result == a * a * a;
    assigns \nothing;
*/
int f(int a)
{
    // Variable declarations at top
    int res;
    
    //@ assert (1 <= (a) && (a) <= 9);
    //@ assert 1 <= a * a && a * a <= 81;
    //@ assert 1 <= a * a * a && a * a * a <= 729;
    
    res = a * a * a;
    
    //@ assert res == a * a * a;
    return res;
}

int main()
{
    return 0;
}
