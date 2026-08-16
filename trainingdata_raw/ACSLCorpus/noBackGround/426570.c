/*@
    requires ((a) > 0 && (a) < 100);
    ensures \result == a * a;
    assigns \nothing;
*/
int func(int a)
{
    // Variable declarations at top of scope
    int res;
    
    //@ assert a > 0;
    //@ assert a < 100;
    //@ assert a * a < 10000;
    
    res = a * a;
    return res;
}

int main()
{
    return 0;
}
