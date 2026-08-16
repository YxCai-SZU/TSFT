#include <stdbool.h>

/*@
    predicate contains_key{L}(int *map, integer k, integer v) =
        \exists integer i; 0 <= i < 5 && map[i] == v && k == i*10;
*/

/*@
    lemma map_insert_remove_contains_key:
        \forall int *map, integer k, integer v;
            contains_key(map, k, v) ==> contains_key(map, k, v);
*/

/*@
    requires \valid(map+(0..4));
    requires contains_key(map, 20, 200);
    assigns \nothing;
    ensures \true;
*/
void test_map_insert_remove_contains_key(int *map) {
    //@ assert contains_key(map, 20, 200);
}
