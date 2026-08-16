#include <stdbool.h>

/*@
    requires (1 <= (d) <= 10000 &&
        1 <= (t) <= 10000 &&
        1 <= (s) <= 10000);
    ensures \result == (((s) * (t) >= (d) ? 1 : 0) == 1);
*/
bool func(int d, int t, int s)
{
    int distance;
    int time;
    int speed;
    bool result;

    distance = d;
    time = t;
    speed = s;
    result = (speed * time >= distance);

    //@ assert speed * time <= 10000 * 10000;

    return result;
}

int main()
{
    return 0;
}
