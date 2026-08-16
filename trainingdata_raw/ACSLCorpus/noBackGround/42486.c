/*@
    requires (1 <= (x) && (x) <= 100);
    ensures \result == ((x) * (x));
    assigns \nothing;
*/
int main_with_arg(int x)
{
    // Variable declarations at top
    int ret;
    
    //@ assert x >= 1;
    //@ assert x <= 100;
    //@ assert x * x >= 1;
    //@ assert x * x <= 10000;
    
    ret = x * x;
    
    //@ assert ret == ((x) * (x));
    return ret;
}
