/*@
    requires (1 <= (r) <= 100);
    ensures \result == (2 * (r) * (3));
    assigns \nothing;
*/
int func(int r)
{
    int circumference;
    int temp;
    int pi = 3;

    //@ assert (1 <= (r) <= 100);
    temp = 2 * r * pi;
    circumference = temp;

    //@ assert circumference == (2 * (r) * (3));
    return circumference;
}
