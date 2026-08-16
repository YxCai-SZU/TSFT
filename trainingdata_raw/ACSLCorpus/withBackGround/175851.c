#include <stdbool.h>
#include <stdint.h>

/*@
    predicate is_empty{L}(int *map) =
        \forall integer i; 0 <= i < 10 ==> map[i] == 0;

    predicate contains_key{L}(int *map, integer key) =
        0 <= key < 10 && map[key] != 0;

    lemma insert_preserves_other_keys:
        \forall int *map, integer key, integer value;
        \forall integer i; 0 <= i < 10 && i != key ==>
            (map[i] == 0 ==> map[i] == 0) &&
            (map[i] != 0 ==> map[i] != 0);
*/

/*@
    requires \valid(m + (0..9));
    requires 0 <= k < 10;
    requires is_empty(m);
    ensures contains_key(m, k);
    ensures \forall integer i; 0 <= i < 10 && i != k ==> m[i] == 0;
    assigns m[k];
*/
void map_demosexy(int k, int *m)
{
    //@ assert is_empty(m);
    
    m[k] = 4;
    
    //@ assert contains_key(m, k);
}

/*@
    requires \valid(m + (0..9));
    requires is_empty(m);
    ensures contains_key(m, 3);
    ensures \forall integer i; 0 <= i < 10 && i != 3 ==> m[i] == 0;
    assigns m[3];
*/
void test_map5(int *m)
{
    //@ assert is_empty(m);
    
    map_demosexy(3, m);
    
    //@ assert contains_key(m, 3);
}
