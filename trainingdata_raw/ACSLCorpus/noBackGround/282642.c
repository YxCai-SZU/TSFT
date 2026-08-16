/*@
    requires (1 <= (d) <= 10000 &&
        1 <= (t) <= 10000 &&
        1 <= (s) <= 10000);
    ensures \result == (s * t >= d);
    assigns \nothing;
*/
int func(int d, int t, int s)
{
    int distance = d;
    int time = t;
    int speed = s;
    int result;

    //@ assert (1 <= (d) <= 10000 &&         1 <= (t) <= 10000 &&         1 <= (s) <= 10000);
    //@ assert 1 <= s * t <= 10000 * 10000;

    result = (speed * time >= distance);
    return result;
}
