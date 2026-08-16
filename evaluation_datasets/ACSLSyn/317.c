#include <stdbool.h>
#include <limits.h>

/* ========== First code snippet (adapted) ========== */

/*@
    predicate is_equal(integer n, integer m) = n == m;
*/

bool func_equal(unsigned int n, unsigned int m)
{
    bool result;
    //@ assert n == m ==> n == m;
    result = (n == m);
    return result;
}

unsigned int input_number(void)
{
    unsigned int tmp = 0;
    return tmp;
}

struct pair {
    char first;
    unsigned int second;
};

struct pair input(void)
{
    struct pair tmp;
    tmp.first = ' ';
    tmp.second = 0;
    return tmp;
}

/* ========== Second code snippet ========== */

/*@
    predicate is_valid_int(integer x) =
        INT_MIN <= x && x <= INT_MAX;

    logic integer min_int(integer x, integer y) =
        x < y ? x : y;
*/

int min_int(int x, int y)
{
    //@ assert is_valid_int(x) && is_valid_int(y);
    if (x < y) {
        //@ assert min_int(x, y) == x;
        return x;
    } else {
        //@ assert min_int(x, y) == y;
        return y;
    }
}

/*@
    predicate valid_params(integer d, integer t, integer s) =
        1 <= d && d <= 10000 &&
        1 <= t && t <= 10000 &&
        1 <= s && s <= 10000;

    lemma mul_bounds:
        \forall integer t, s;
        valid_params(1, t, s) ==> t * s <= 10000 * 10000;
*/

int func_check(int d, int t, int s)
{
    //@ assert valid_params(d, t, s);
    //@ assert t <= 10000;
    //@ assert s <= 10000;
    //@ assert t * s <= 10000 * 10000;
    return t * s >= d;
}

/* ========== Third code snippet ========== */

/*@
    predicate valid_vector(int *v, integer len) =
        len == 2 &&
        \valid(v + (0 .. 1)) &&
        1 <= v[0] < v[1] <= 100;
*/

bool func_vector(int *v)
{
    int a;
    int b;

    a = v[0];
    b = v[1];

    //@ assert 1 <= a < b <= 100;

    return a != 1 || b != 2;
}

/* ========== Synthesized function: Password Strength Validator ========== */

/*@
    predicate valid_password_strength(int *v, unsigned int n, unsigned int m, int d, int t, int s) =
        valid_vector(v, 2) &&
        is_equal(n, m) &&
        valid_params(d, t, s) &&
        (t * s >= d) &&
        (v[0] != 1 || v[1] != 2);
*/

bool validate_password_strength(int *v, unsigned int n, unsigned int m, int d, int t, int s)
{
    bool equal_check = func_equal(n, m);
    bool threshold_check = func_check(d, t, s);
    bool vector_check = func_vector(v);
    bool result = equal_check && threshold_check && vector_check;

    //@ assert (equal_check == (n == m)) && (threshold_check == (t * s >= d)) && (vector_check == (v[0] != 1 || v[1] != 2));
    //@ assert result == (n == m && t * s >= d && (v[0] != 1 || v[1] != 2));

    return result;
}
