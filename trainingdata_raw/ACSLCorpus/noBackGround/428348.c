/*@
requires
    size1 == size2 &&
    \valid(map1_keys + (0 .. size1-1)) &&
    \valid(map1_vals + (0 .. size1-1)) &&
    \valid(map2_keys + (0 .. size2-1)) &&
    \valid(map2_vals + (0 .. size2-1)) &&
    ((size1) == (size2) &&
    \forall integer i; 0 <= i < (size1) ==> (map1_keys)[i] == (map2_keys)[i] && (map1_vals)[i] == (map2_vals)[i]) &&
    (\forall integer k; (\exists integer i; 0 <= i < ((size1)) && ((map1_keys))[i] == (k)) <==> (\exists integer i; 0 <= i < ((size2)) && ((map2_keys))[i] == (k)));
ensures
    \forall integer k;
        (\exists integer i; 0 <= i < (size1) && (map1_keys)[i] == (k)) ==>
        (\exists integer i1, i2;
            0 <= i1 < size1 && 0 <= i2 < size2 &&
            map1_keys[i1] == k && map2_keys[i2] == k &&
            map1_vals[i1] == map2_vals[i2]);
*/
void prove_map_equal(int *map1_keys, int *map1_vals, int size1,
                     int *map2_keys, int *map2_vals, int size2)
{
    //@ assert ((size1) == (size2) &&     \forall integer i; 0 <= i < (size1) ==> (map1_keys)[i] == (map2_keys)[i] && (map1_vals)[i] == (map2_vals)[i]);
}
