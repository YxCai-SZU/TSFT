#include <stdbool.h>

/*@ predicate is_valid_key(integer k) = 1 <= k && k <= 100; */
/*@ predicate is_valid_x(integer x) = 1 <= x && x <= 100000; */
/*@ predicate func_result(integer k, integer x, bool result) = result == (k * 500 >= x); */

/*@
    requires is_valid_key(k) && is_valid_x(x);
    ensures func_result(k, x, \result);
*/
bool func(int k, int x) {
    bool result;
    //@ assert k * 500 >= x ==> (k * 500 >= x) == 1;
    //@ assert k * 500 < x ==> (k * 500 >= x) == 0;
    result = (k * 500 >= x);
    return result;
}

/*@ predicate map_domain(integer x) = 0 <= x && x <= 100; */
/*@ logic integer map_value(integer x) = x * 2; */

/*@ lemma test_contains_key: 
    \forall integer x; map_domain(x) ==> map_value(x) == x * 2; 
*/

/*@ lemma test_map_new: 
    \forall integer x; map_domain(x) ==> map_value(x) == x * 2 && x <= 100; 
*/

/*@ lemma test_map_insert: 
    \forall integer x; map_domain(x) ==> map_value(x) == x * 2 && x <= 100; 
*/

/*@ lemma test_map_remove: 
    \forall integer x; map_domain(x) ==> map_value(x) == x * 2 && x <= 100; 
*/

int main() {
    return 0;
}
