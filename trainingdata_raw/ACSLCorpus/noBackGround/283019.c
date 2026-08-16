/*@
    requires (1 <= (r) && (r) <= 100);
    ensures \result == r * 2 * 3;
    assigns \nothing;
*/
int func(int r)
{
    int pi;
    int circumference;
    
    //@ assert (1 <= (r) && (r) <= 100);
    pi = 3;
    //@ assert 2 * pi <= 200;
    //@ assert ((r) * 2 * (pi) <= 200 * 100);
    circumference = r * 2 * pi;
    return circumference;
}
