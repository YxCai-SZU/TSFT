#include <stdbool.h>

/*@
    logic integer max_value(integer x, integer y) = (x > y) ? x : y;
    logic integer min_value(integer x, integer y) = (x < y) ? x : y;
    
    lemma test_max_value:
        max_value(100, 200) == 200 &&
        max_value(300, 50) == 300;
    
    lemma test_min_value:
        min_value(100, 200) == 100 &&
        min_value(300, 50) == 50;
    
    lemma max_value_range:
        \forall integer x, y, z;
            0 <= x && x <= y && y <= z ==>
            max_value(x, y) <= z;
    
    lemma min_value_range:
        \forall integer x, y, z;
            0 <= x && x <= y && y <= z ==>
            min_value(x, y) >= 0;
*/

int main() {
    return 0;
}
