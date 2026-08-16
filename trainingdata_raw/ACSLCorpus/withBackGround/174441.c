#include <stdint.h>

/*@
    predicate valid_input(integer a, integer b, integer c) =
        1 <= a && a <= 9 &&
        1 <= b && b <= 9 &&
        1 <= c && c <= 9;

    logic integer func_result(integer a, integer b, integer c) =
        (a == b && b == c) ? 3 :
        (a == b || a == c || b == c) ? 2 : 1;

    lemma result_bounds:
        \forall integer a, b, c;
        valid_input(a, b, c) ==> 0 <= func_result(a, b, c) <= 3;
*/

/*@
    requires valid_input(a, b, c);
    ensures \result >= 0 && \result <= 3;
    ensures \result == func_result(a, b, c);
    assigns \nothing;
*/
int64_t func(int64_t a, int64_t b, int64_t c)
{
    int64_t ret;
    
    //@ assert valid_input(a, b, c);
    
    if (a == b && b == c) {
        ret = 3;
        //@ assert ret == func_result(a, b, c);
    } else if (a == b || a == c || b == c) {
        ret = 2;
        //@ assert ret == func_result(a, b, c);
    } else {
        ret = 1;
        //@ assert ret == func_result(a, b, c);
    }
    
    //@ assert ret >= 0;
    //@ assert ret <= 3;
    
    return ret;
}

#ifdef TESTING
#include <assert.h>

int main()
{
    // Test cases from original Rust code
    assert(func(1, 1, 1) == 3);
    assert(func(1, 1, 2) == 2);
    assert(func(1, 2, 3) == 1);
    assert(func(5, 5, 5) == 3);
    assert(func(5, 5, 6) == 2);
    assert(func(5, 6, 7) == 1);
    
    return 0;
}
#endif
