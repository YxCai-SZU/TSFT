/*@
    logic integer max_value(integer x, integer y) = (x > y) ? x : y;
    logic integer min_value(integer x, integer y) = (x < y) ? x : y;

    lemma max_value_property:
        \forall integer x, y; max_value(x, y) >= x && max_value(x, y) >= y;

    lemma min_value_property:
        \forall integer x, y; min_value(x, y) <= x && min_value(x, y) <= y;
*/

#include <stdbool.h>

/*@
    requires max_value(100, 200) == 200;
    ensures \result == 0;
*/
int max_value_test() {
    int result = 0;
    //@ assert max_value(100, 200) == 200;
    //@ assert max_value(300, 50) == 300;
    //@ assert max_value(0, 0) == 0;
    return result;
}

/*@
    requires min_value(100, 200) == 100;
    ensures \result == 0;
*/
int min_value_test() {
    int result = 0;
    //@ assert min_value(100, 200) == 100;
    //@ assert min_value(300, 50) == 50;
    //@ assert min_value(0, 0) == 0;
    return result;
}

int main() {
    int test1 = max_value_test();
    int test2 = min_value_test();
    return 0;
}
