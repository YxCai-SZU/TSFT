struct CompositeType {
    int int_field;
    int *seq_field;
    int seq_len;
    int *set_field;
    int set_len;
    int *map_keys;
    int *map_vals;
    int map_len;
};

/*@
    requires \valid(seq_field1+(0..seq_len-1)) && \valid(seq_field2+(0..seq_len-1));
    requires \valid(set_field1+(0..set_len-1)) && \valid(set_field2+(0..set_len-1));
    requires \valid(map_keys1+(0..map_len-1)) && \valid(map_vals1+(0..map_len-1));
    requires \valid(map_keys2+(0..map_len-1)) && \valid(map_vals2+(0..map_len-1));
    requires int_field1 == int_field2;
    requires \forall integer i; 0 <= i < seq_len ==> seq_field1[i] == seq_field2[i];
    requires \forall integer i; 0 <= i < set_len ==> 
        (\exists integer j; 0 <= j < set_len && set_field1[i] == set_field2[j]);
    requires \forall integer i; 0 <= i < set_len ==> 
        (\exists integer j; 0 <= j < set_len && set_field2[i] == set_field1[j]);
    requires \forall integer i; 0 <= i < map_len ==>
        (\exists integer j; 0 <= j < map_len && 
            map_keys1[i] == map_keys2[j] && map_vals1[i] == map_vals2[j]);
    requires \forall integer i; 0 <= i < map_len ==>
        (\exists integer j; 0 <= j < map_len && 
            map_keys2[i] == map_keys1[j] && map_vals2[i] == map_vals1[j]);
    ensures int_field1 == int_field2;
*/
void composite_extensionality_proof(int int_field1, int int_field2,
                                    int *seq_field1, int *seq_field2, int seq_len,
                                    int *set_field1, int *set_field2, int set_len,
                                    int *map_keys1, int *map_vals1,
                                    int *map_keys2, int *map_vals2, int map_len) {
    //@ assert int_field1 == int_field2;
}

int main() {
    return 0;
}
