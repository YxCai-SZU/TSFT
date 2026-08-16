/*@
    requires (1 <= (r) <= 100);
    ensures \result == (6 * (r));
    assigns \nothing;
*/
int func(int r)
{
    int pi;
    int circumference;
    
    //@ assert (1 <= (r) <= 100);
    pi = 3;
    
    //@ assert 2 * r * pi <= 200 * 3;
    
    circumference = 2 * r * pi;
    
    //@ assert circumference == 6 * r;
    return circumference;
}
