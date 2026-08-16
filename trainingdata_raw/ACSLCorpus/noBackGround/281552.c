/*@
    requires (1 <= (n) <= 100 &&
        0 <= (a) <= (n) * (n));
    ensures \result == ((n) * (n)) - a;
    assigns \nothing;
*/
int func(int n, int a)
{
    int n_squared;
    int max_val;
    int min_val;
    int abs_diff;

    //@ assert ((n) * (n)) <= 10000;
    //@ assert ((n) * (n)) >= a;

    n_squared = n * n;

    if (n_squared > a) {
        max_val = n_squared;
    } else {
        max_val = a;
    }

    if (n_squared < a) {
        min_val = n_squared;
    } else {
        min_val = a;
    }

    abs_diff = max_val - min_val;

    //@ assert abs_diff == ((n) * (n)) - a;

    return abs_diff;
}
