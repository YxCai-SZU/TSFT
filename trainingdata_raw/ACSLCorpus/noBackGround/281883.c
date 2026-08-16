/*@
    requires (2 <= (x) && (x) <= 1000000);
    ensures \result == 0;
    assigns \nothing;
*/
int func(int x)
{
    //@ assert 2 <= x;
    //@ assert x <= 1000000;
    
    /*@
        loop invariant 2 <= x && x <= 1000000;
        loop assigns \nothing;
    */
    while (0) { }
    
    //@ assert x <= 2000000;
    return 0;
}

int main()
{
    return 0;
}
