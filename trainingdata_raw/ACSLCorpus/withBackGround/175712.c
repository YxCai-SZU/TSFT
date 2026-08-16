/*@
predicate is_negative(integer x) = x < 0;

logic integer func(integer x) =
    x < 0 ? x - 2 : x + 1;

lemma oddness_property:
    \forall integer x;
        (x < 0 ==> func(x) < x) &&
        (x >= 0 ==> func(x) > x);
*/

#include <stdbool.h>

/*@
    requires \true;
    ensures \result == (x < 0 ? x - 2 : x + 1);
*/
int func_impl(int x) {
    // Declare before use
    int result;
    
    if (x < 0) {
        result = x - 2;
    } else {
        result = x + 1;
    }
    
    return result;
}

/*@
    requires \true;
    ensures \true;
*/
void test() {
    // Declare before use
    int x1;
    int x2;
    int result1;
    int result2;
    
    x1 = 10;
    //@ assert x1 >= 0;
    result1 = func_impl(x1);
    //@ assert result1 > x1;
    
    x2 = -10;
    //@ assert x2 < 0;
    result2 = func_impl(x2);
    //@ assert result2 < x2;
}

int main() {
    test();
    return 0;
}
