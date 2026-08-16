/*@
    requires (1 <= (a) <= 100);
    ensures ((\result) == (a) * (a) && (a) * (a) <= 10000);
    assigns \nothing;
*/
int func(int a)
{
    // Variable declarations at top of scope
    int result;

    //@ assert 1 <= a && a <= 100;
    //@ assert a * a <= 10000;
    
    result = a * a;
    return result;
}

int main()
{
    // Variable declarations at top of scope
    int a = 50;
    int result;
    
    result = func(a);
    return 0;
}
