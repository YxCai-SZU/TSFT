#include <limits.h>

/*@
    predicate is_i32_valid(integer x) =
        INT_MIN <= x && x <= INT_MAX;

    logic integer minimum(integer a, integer b) =
        a < b ? a : b;

    lemma minimum_lemma_1:
        \forall integer a, b;
        is_i32_valid(a) && is_i32_valid(b) ==>
            minimum(a, b) == a || minimum(a, b) == b;

    lemma minimum_lemma_2:
        \forall integer a, b;
        is_i32_valid(a) && is_i32_valid(b) ==>
            minimum(a, b) <= a && minimum(a, b) <= b;
*/


int minimum(int a, int b)
{
    //@ assert is_i32_valid(a);
    //@ assert is_i32_valid(b);
    
    if (a < b) {
        return a;
    } else {
        return b;
    }
}

int main(void)
{
    return 0;
}
