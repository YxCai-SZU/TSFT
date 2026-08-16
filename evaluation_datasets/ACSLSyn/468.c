#include <stdint.h>
#include <stdbool.h>
#include <limits.h>

/* ========== First code snippet (calc_example functions) ========== */

/*@
    predicate less_than(integer a, integer b) = a < b;
    predicate less_eq(integer a, integer b) = a <= b;
    predicate greater_than(integer a, integer b) = a > b;
    predicate greater_eq(integer a, integer b) = a >= b;

    lemma calc_example_5: \forall integer x, y; x > y ==> x - y > 0;
    lemma calc_example_6: \forall integer a, b, c; a > b && b > c ==> a > c;
    lemma calc_example_7: \forall integer x, y, z; x >= y && y >= z ==> x >= z;
    lemma calc_example_8: \forall integer a, b; a < b ==> a - 1 < b - 1;
    lemma calc_example_9: \forall integer a, b, c; a < b && b < c ==> a < c;
    lemma calc_example_10: \forall integer a, b; a <= b ==> a + 1 <= b + 1;
*/

int calc_example_5_impl(int x, int y) {
    int result;
    result = x - y;
    //@ assert result > 0;
    return result;
}

int calc_example_6_impl(int a, int b, int c) {
    int result;
    result = a - c;
    //@ assert result > 0;
    return result;
}

int calc_example_7_impl(int x, int y, int z) {
    int result;
    result = x - z;
    //@ assert result >= 0;
    return result;
}

int calc_example_8_impl(int a, int b) {
    int result;
    result = (a - 1) - (b - 1);
    //@ assert result < 0;
    return result;
}

int calc_example_9_impl(int a, int b, int c) {
    int result;
    result = a - c;
    //@ assert result < 0;
    return result;
}

int calc_example_10_impl(int a, int b) {
    int result;
    result = (a + 1) - (b + 1);
    //@ assert result <= 0;
    return result;
}

/* ========== Second code snippet (func from uint32_t) ========== */

/*@
    predicate is_valid_input(integer x) = 1 <= x <= 100000;

    logic integer max_ops(integer x) = (x / 11) * 2 + 2;

    lemma ans_non_negative:
        \forall integer x, q, r, ans;
        is_valid_input(x) ==>
        q == x / 11 ==>
        r == x % 11 ==>
        ans == 2 * q + (r > 0 && r <= 6 ? 1 : 0) + (r > 6 ? 2 : 0) - (q > 0 && r > 0 && q * 11 + r == x ? 1 : 0) ==>
        ans >= 0;

    lemma ans_bounded:
        \forall integer x, q, r, ans;
        is_valid_input(x) ==>
        q == x / 11 ==>
        r == x % 11 ==>
        ans == 2 * q + (r > 0 && r <= 6 ? 1 : 0) + (r > 6 ? 2 : 0) - (q > 0 && r > 0 && q * 11 + r == x ? 1 : 0) ==>
        ans <= max_ops(x);
*/

int32_t func_uint32(uint32_t x)
{
    uint32_t q;
    uint32_t r;
    int32_t ans;

    q = x / 11;
    r = x % 11;
    ans = 2 * (int32_t)q;

    //@ assert ans == 2 * (int32_t)q;

    if (r > 0 && r <= 6)
    {
        ans += 1;
        //@ assert ans == 2 * (int32_t)q + 1;
    }
    else if (r > 6)
    {
        ans += 2;
        //@ assert ans == 2 * (int32_t)q + 2;
    }

    //@ assert ans >= 2 * (int32_t)q && ans <= 2 * (int32_t)q + 2;

    if (q > 0 && r > 0 && q * 11 + r == x)
    {
        ans -= 1;
    }

    //@ assert ans >= 0;
    //@ assert ans <= max_ops(x);

    return ans;
}

/* ========== Third code snippet (func from long long) ========== */

/*@
    predicate valid_input(integer a, integer b, integer c) =
        1 <= a && a <= 100 &&
        1 <= b && b <= 100 &&
        1 <= c && c <= 100 &&
        a * b <= INT_MAX &&
        b * c <= INT_MAX &&
        a * c <= INT_MAX &&
        a * b * c <= INT_MAX;

    logic integer product_ab(integer a, integer b) = a * b;
    logic integer product_bc(integer b, integer c) = b * c;
    logic integer product_ca(integer c, integer a) = c * a;

    lemma product_symmetry:
        \forall integer a, b, c;
            product_ab(a,b) == product_bc(b,c) && product_bc(b,c) == product_ca(c,a) ==>
            product_ab(a,b) == product_ca(c,a);
*/

int func_longlong(long long a, long long b, long long c)
{
    long long ab;
    long long bc;
    long long ca;
    int result;

    ab = a * b;
    bc = b * c;
    ca = c * a;

    //@ assert ab == product_ab(a, b);
    //@ assert bc == product_bc(b, c);
    //@ assert ca == product_ca(c, a);

    if (ab == bc && bc == ca)
    {
        result = 1;
    }
    else if (ab == bc || bc == ca || ab == ca)
    {
        result = 2;
    }
    else
    {
        //@ assert ab != bc && bc != ca && ab != ca;
        result = 3;
    }

    //@ assert result >= 1 && result <= 3;
    return result;
}

/* ========== Fourth code snippet (func from bool) ========== */

/*@ predicate is_safe_mult(integer t, integer s) =
      t <= 46340 && s <= 46340;
*/

/*@ lemma mult_bounds:
      \forall integer t, s;
        1 <= t <= 10000 && 1 <= s <= 10000 ==>
        t * s <= 2147395600;
*/

bool func_bool(int d, int t, int s)
{
    int distance;
    bool result;

    //@ assert t <= 10000;
    //@ assert s <= 10000;

    if (t > 46340 && s > 46340) {
        //@ assert t * s >= d;
        return true;
    }

    //@ assert t <= 46340 || s <= 46340;
    //@ assert t * s <= 2147395600;

    distance = t * s;
    result = distance >= d;
    //@ assert result == (t * s >= d);
    return result;
}

/* ========== Synthesized complex function ========== */

int complex_function(uint32_t x, long long a, long long b, long long c, int d, int t, int s)
{
    int32_t ops = func_uint32(x);
    
    int ordering_check = calc_example_6_impl((int)a, (int)b, (int)c);
    
    int category = func_longlong(a, b, c);
    
    bool sufficient = func_bool(d, t, s);
    
    int diff_check = calc_example_5_impl((int)a, (int)b);
    
    int transitive_check = calc_example_7_impl((int)a, (int)b, (int)c);
    
    int strict_check = calc_example_8_impl((int)a, (int)b);
    
    int transitive_strict_check = calc_example_9_impl((int)a, (int)b, (int)c);
    
    int non_strict_check = calc_example_10_impl((int)a, (int)b);
    
    //@ assert category == 1 && ops >= 0 && sufficient == true && ordering_check > 0 && diff_check > 0 && transitive_check >= 0 && strict_check < 0 && transitive_strict_check < 0 && non_strict_check <= 0;
    
    return 1;
}
