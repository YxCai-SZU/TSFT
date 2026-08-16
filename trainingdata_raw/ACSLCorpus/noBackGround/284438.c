/*@
    requires 0 <= x && x <= 1;
    ensures \result == 0 || \result == 1;
    assigns \nothing;
*/
int calc_example_3(int x)
{
    //@ assert x == 0 || x == 1;
    return x;
}

int main()
{
    int x;
    x = 0;
    //@ assert x == 0 || x == 1;
    
    x = 1;
    //@ assert x == 0 || x == 1;
    
    return 0;
}
