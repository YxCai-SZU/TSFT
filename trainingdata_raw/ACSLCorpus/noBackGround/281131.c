/*@
    requires (1 <= (r) && (r) <= 100);
    ensures \result == (2 * 3 * (r));
    assigns \nothing;
*/
int func(int r)
{
    int pi = 3;
    int circumference;
    
    //@ assert pi == 3;
    //@ assert (1 <= (r) && (r) <= 100);
    
    circumference = 2 * pi * r;
    
    //@ assert circumference == 2 * 3 * r;
    
    return circumference;
}

int main()
{
    return 0;
}
