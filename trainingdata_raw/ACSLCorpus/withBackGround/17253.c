/*@
predicate map_dom_eq{L}(int *map1, int *map2, integer size) =
    \forall integer i; 0 <= i < size ==> map1[i] == map2[i];

predicate map_sets_eq{L}(int *map1, int *map2, integer size) =
    \forall integer i; 0 <= i < size ==> map1[i] == map2[i];
*/

/*@
lemma map_sets_add_lemma:
    \forall int *map1, *map2, integer size, int k, int x;
    map_dom_eq(map1, map2, size) && map_sets_eq(map1, map2, size) ==>
    map_dom_eq(map1, map2, size) && map_sets_eq(map1, map2, size);

lemma map_sets_remove_lemma:
    \forall int *map1, *map2, integer size, int k, int x;
    map_dom_eq(map1, map2, size) && map_sets_eq(map1, map2, size) ==>
    map_dom_eq(map1, map2, size) && map_sets_eq(map1, map2, size);
*/

int main() {
    int map1[10];
    int map2[10];
    int i;
    
    /*@
    loop invariant 0 <= i <= 10;
    loop invariant \forall integer j; 0 <= j < i ==> map1[j] == map2[j];
    loop assigns i, map1[0..9], map2[0..9];
    */
    for (i = 0; i < 10; i++) {
        map1[i] = i;
        map2[i] = i;
    }
    
    //@ assert map_dom_eq(&map1[0], &map2[0], 10);
    //@ assert map_sets_eq(&map1[0], &map2[0], 10);
    
    return 0;
}
