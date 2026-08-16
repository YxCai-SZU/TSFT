#include <stdint.h>

typedef struct {
    uint32_t base;
    uint32_t height;
} Triangle;

/*@
    predicate is_valid_triangle(Triangle t) =
        t.base <= 1000 && t.height <= 1000;

    logic integer area(Triangle t) =
        (integer)t.base * (integer)t.height / 2;

    lemma area_bounded:
        \forall Triangle t;
        is_valid_triangle(t) ==> area(t) <= (integer)t.base * (integer)t.height / 2;
*/

/*@
    requires base <= 1000 && height <= 1000;
    ensures \result.base == base && \result.height == height;
    ensures area(\result) <= (integer)base * (integer)height / 2;
    assigns \nothing;
*/
Triangle new_triangle(uint32_t base, uint32_t height) {
    Triangle triangle;
    triangle.base = base;
    triangle.height = height;
    
    //@ assert base * height <= 1000 * 1000;
    
    return triangle;
}

int main() {
    return 0;
}
