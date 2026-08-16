/*@
    requires -1000 <= x <= 1000;
    ensures \result == x * x * x;
    assigns \nothing;
*/
int cube(int x)
{
    //@ assert -1000 <= x <= 1000;
    //@ assert -1000000 <= x * x <= 1000000;
    //@ assert -1000000000 <= x * x * x <= 1000000000;
    
    int res;
    res = x * x * x;
    return res;
}

int main()
{
    return 0;
}
