/*@
    requires (1 <= (r) && (r) <= 100);
    ensures \result == (6 * (r));
    assigns \nothing;
*/
int func(int r)
{
    int pi_approx;
    int circumference;

    pi_approx = 3;
    circumference = 2 * r * pi_approx;

    //@ assert circumference == 6 * r;

    return circumference;
}
