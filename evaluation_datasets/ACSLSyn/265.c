#include <stdbool.h>

/* ========== First underlying function (range check with product/sum) ========== */
/*@
    predicate valid_range(integer x) = 1 <= x <= 10000;

    logic integer max_product(integer x, integer y) = x * y;
    logic integer max_sum(integer x, integer y) = x + y;

    lemma product_bound:
        \forall integer a, b;
            valid_range(a) && valid_range(b) ==> max_product(a, b) <= 10000 * 10000;

    lemma sum_bound:
        \forall integer a, b;
            valid_range(a) && valid_range(b) ==> max_sum(a, b) <= 20000;
*/

bool func1(unsigned int a, unsigned int b, unsigned int c, unsigned int d)
{
    //@ assert valid_range(a) && valid_range(b) && valid_range(c) && valid_range(d);
    
    //@ assert a * b <= 10000 * 10000;
    //@ assert b * d <= 10000 * 10000;
    //@ assert c + d <= 20000;
    
    return c <= b * d || a * b <= c + d;
}

/* ========== Second underlying function (closeness check) ========== */
/*@
    predicate are_close(integer x, integer y) =
        x == y || x == y - 1 || x == y + 1 || y == x - 1 || y == x + 1;
*/

bool func2(long x, long y)
{
    bool result = false;
    
    if (x == y || x == y - 1 || x == y + 1 || y == x - 1 || y == x + 1) {
        result = true;
    }
    
    return result;
}

/* ========== Third underlying function (vector validity check) ========== */
/*@ predicate is_valid_vector(int *arr) =
    \valid(arr) && \valid(arr+1) &&
    arr[0] >= 1 && arr[0] <= 100 &&
    arr[1] >= 1 && arr[1] <= 100;
*/

/*@ lemma vector_properties:
    \forall int *arr; is_valid_vector(arr) ==>
    arr[0] >= 1 && arr[0] <= 100 &&
    arr[1] >= 1 && arr[1] <= 100;
*/

bool func3(int *v) {
    int vec[2];
    vec[0] = v[0];
    vec[1] = v[1];
    //@ assert vec[0] >= 1 && vec[0] <= 100;
    //@ assert vec[1] >= 1 && vec[1] <= 100;
    return vec[0] <= vec[1];
}

/* ========== Synthesized high-level function: coordinate alignment check ========== */

/*@
    predicate aligned_state(int *v, unsigned int a, unsigned int b, unsigned int c, unsigned int d, bool result) =
        is_valid_vector(v) && valid_range(a) && valid_range(b) && valid_range(c) && valid_range(d) &&
        (result == (v[0] <= v[1] && ((a == b || a == b - 1 || a == b + 1 || b == a - 1 || b == a + 1) || (c <= b * d || a * b <= c + d))));
*/

bool coordinate_alignment_check(int *v, unsigned int a, unsigned int b, unsigned int c, unsigned int d) {
    bool vec_ok = func3(v);
    bool close_ok = func2((long)a, (long)b);
    bool range_ok = func1(a, b, c, d);
    
    bool result = vec_ok && (close_ok || range_ok);
    
    //@ assert aligned_state(v, a, b, c, d, result);
    
    return result;
}
