/*@
    predicate valid_range(integer r) = 1 <= r && r <= 100;
    logic integer compute_circumference(integer r) = 2 * r * 3;
*/

/*@
    requires valid_range(r);
    ensures \result == compute_circumference(r);
    assigns \nothing;
*/
long func(long r)
{
    long pi = 3;
    long circumference = 0;
    long temp = 0;

    temp = 2 * r * pi;
    circumference = temp;

    //@ assert 2 * r * 3 == 2 * r * pi;
    //@ assert circumference == compute_circumference(r);

    return circumference;
}
