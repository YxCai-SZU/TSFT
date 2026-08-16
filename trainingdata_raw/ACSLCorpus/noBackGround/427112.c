/*@
    requires (1 <= (d) <= 10000 &&
        1 <= (t) <= 10000 &&
        1 <= (s) <= 10000);
    ensures \result == (d <= t * s);
    assigns \nothing;
*/
int func(int d, int t, int s)
{
    int distance;
    int speed;
    int time;
    int result;

    distance = d;
    speed = s;
    time = t;

    //@ assert distance == d;
    //@ assert speed == s;
    //@ assert time == t;

    //@ assert t <= 10000 && s <= 10000;
    //@ assert t * s <= 10000 * 10000;

    result = (distance <= time * speed);
    return result;
}
