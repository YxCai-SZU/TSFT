/*@
    requires (1 <= (n) && (n) <= 100);
    ensures \result == ((n) * 2 * 3);
    assigns \nothing;
*/
int func(int n)
{
    int pi_approx;
    int circumference;

    //@ assert (1 <= (n) && (n) <= 100);
    pi_approx = 3;
    circumference = n * 2 * pi_approx;

    //@ assert n * 2 * pi_approx <= 100 * 2 * 3;
    //@ assert circumference == n * 2 * 3;

    return circumference;
}
