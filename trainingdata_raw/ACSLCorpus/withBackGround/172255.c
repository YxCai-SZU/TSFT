#include <stdbool.h>
#include <stdint.h>

/*@
    predicate contains_key{L}(int *map, integer key) =
        \exists integer i; 0 <= i < 10 && map[i] == key;
*/

/*@
    requires \valid(map + (0 .. 9));
    requires contains_key(map, 3);
    requires contains_key(map, 6);
    requires contains_key(map, 9);
    ensures \result == true;
    assigns \nothing;
*/
bool func(int *map) {
    //@ assert contains_key(map, 3);
    //@ assert contains_key(map, 6);
    //@ assert contains_key(map, 9);
    return true;
}

/*@
    lemma map_empty_lemma:
        \forall int *map; (\forall integer i; 0 <= i < 10 ==> map[i] == 0) ==> !contains_key(map, 3);
*/

/*@
    requires \valid(m + (0 .. 9));
    assigns m[0 .. 9];
*/
void test_map_remove_key(int *m) {
    int i;
    
    /*@
        loop invariant 0 <= i <= 10;
        loop invariant \forall integer j; 0 <= j < i ==> m[j] == 0;
        loop assigns i, m[0 .. 9];
    */
    for (i = 0; i < 10; i++) {
        m[i] = 0;
    }
    
    //@ assert \forall integer j; 0 <= j < 10 ==> m[j] == 0;
    //@ assert !contains_key(m, 3);
    
    m[0] = 3;
    //@ assert contains_key(m, 3);
    
    m[0] = 0;
    //@ assert \forall integer j; 0 <= j < 10 ==> m[j] == 0;
    //@ assert !contains_key(m, 3);
}
