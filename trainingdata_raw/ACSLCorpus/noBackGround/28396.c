/*@
    requires (1 <= (r) && (r) <= 100);
    ensures \result == (2 * (r) * 3);
    assigns \nothing;
*/
int func(int r)
{
    int pi_approx;
    int circumference;
    
    pi_approx = 3;
    
    //@ assert pi_approx == 3;
    
    circumference = 2 * r * pi_approx;
    
    //@ assert circumference == 2 * r * 3;
    
    return circumference;
}

int main()
{
    return 0;
}
