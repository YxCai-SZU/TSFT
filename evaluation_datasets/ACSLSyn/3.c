#include <stdbool.h>
#include <stddef.h>

/*@
    predicate a_in_range(integer a) = 1 <= a <= 100;
    predicate b_in_range(integer a, integer b) = 0 <= b <= a;
    predicate result_condition(integer a, integer b, bool result) = 
        result == (a == b);
*/

bool eq_check(unsigned int a, unsigned int b)
{
    bool ans;
    //@ assert a_in_range(a);
    //@ assert b_in_range(a, b);
    
    ans = (a == b);
    
    if (a != b)
    {
        //@ assert a != b;
        ans = false;
        //@ assert ans == false;
    }
    
    //@ assert result_condition(a, b, ans);
    return ans;
}

/*@
    predicate is_valid_n(integer n) = 1 <= n && n <= 1000000000;
    predicate is_valid_m(integer m) = 1 <= m && m <= 1000000000;
    logic integer compute_result(integer n, integer m) =
        n > m ? 2 * m : n + (m - n) / 4;
*/

size_t compute_func(size_t n, size_t m) {
    size_t rem;
    size_t add;
    size_t result;

    if (n > m) {
        //@ assert n > m;
        result = 2 * m;
    } else {
        //@ assert n <= m;
        rem = m - n;
        add = rem / 4;
        result = n + add;
    }
    
    return result;
}

struct Output {
    bool eq;
    size_t comp;
};

/*@
    predicate valid_inputs(integer a, integer b, integer n, integer m) =
        1 <= a <= 100 && 0 <= b <= a && 1 <= n <= 1000000000 && 1 <= m <= 1000000000;
    
    predicate consistent_output(bool eq, size_t comp, integer a, integer b, integer n, integer m) =
        (eq == (a == b)) && (comp == compute_result(n, m));
*/

struct Output process_data(unsigned int a, unsigned int b, size_t n, size_t m) {
    struct Output out;
    
    bool eq_result = eq_check(a, b);
    //@ assert eq_result == (a == b);
    
    size_t comp_result = compute_func(n, m);
    //@ assert comp_result == compute_result(n, m);
    
    out.eq = eq_result;
    out.comp = comp_result;
    
    //@ assert consistent_output(out.eq, out.comp, a, b, n, m);
    
    return out;
}
