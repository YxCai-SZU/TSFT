#include <stdint.h>

/*@
    predicate valid_inputs(integer a, integer b, integer h) =
        1 <= a && a <= 100 &&
        1 <= b && b <= 100 &&
        1 <= h && h <= 100 &&
        h % 2 == 0;

    logic integer expected_result(integer a, integer b, integer h) =
        (a + b) * h / 2;

    lemma multiplication_bounds:
        \forall integer a, b, h;
        valid_inputs(a, b, h) ==> 1 <= (a + b) * h && (a + b) * h <= 20000;

    lemma division_exact:
        \forall integer a, b, h, res;
        valid_inputs(a, b, h) && res == (a + b) * h / 2 ==> res == expected_result(a, b, h);
*/

uint64_t func(uint64_t a, uint64_t b, uint64_t h)
{
    uint64_t ans;

    //@ assert 1 <= a + b && a + b <= 200;
    //@ assert 1 <= (a + b) * h && (a + b) * h <= 20000;
    
    ans = ((a + b) * h) / 2;
    
    //@ assert ans == (a + b) * h / 2;
    
    return ans;
}

int test() {
    int result;

    result = 10;

    return result;
}

uint64_t process_trapezoid_with_safety_factor(uint64_t a, uint64_t b, uint64_t h) {
    uint64_t area;
    int safety_factor;

    area = func(a, b, h);
    safety_factor = test();

    //@ assert area == expected_result(a, b, h) && safety_factor == 10;

    return area * safety_factor;
}
