#include <stdbool.h>

/*@ requires len_seq >= 0 && len_set >= 0 && len_map >= 0;
    requires \valid(s1_a+(0..len_seq-1)) && \valid(s2_a+(0..len_seq-1));
    requires \valid(s1_b+(0..len_set-1)) && \valid(s2_b+(0..len_set-1));
    requires \valid(s1_c+(0..len_map-1)) && \valid(s2_c+(0..len_map-1));
    requires ((\forall integer i; 0 <= i < ((len_seq)) ==> ((s1_a))[i] == ((s2_a))[i]) &&
      (\forall integer i; 0 <= i < ((len_set)) ==> ((s1_b))[i] == ((s2_b))[i]) &&
      (\forall integer i; 0 <= i < ((len_map)) ==> ((s1_a))[i] == ((s2_a))[i] && ((s1_c))[i] == ((s2_c))[i]));
    ensures (\forall integer i; 0 <= i < (len_seq) ==> (s1_a)[i] == (s2_a)[i]);
    ensures (\forall integer i; 0 <= i < (len_set) ==> (s1_b)[i] == (s2_b)[i]);
    ensures (\forall integer i; 0 <= i < (len_map) ==> (s1_a)[i] == (s2_a)[i] && (s1_c)[i] == (s2_c)[i]);
    ensures \true;
*/
void assert_struct_equality(int *s1_a, int *s1_b, int *s1_c,
                            int *s2_a, int *s2_b, int *s2_c,
                            int len_seq, int len_set, int len_map)
{
    //@ assert ((\forall integer i; 0 <= i < ((len_seq)) ==> ((s1_a))[i] == ((s2_a))[i]) &&       (\forall integer i; 0 <= i < ((len_set)) ==> ((s1_b))[i] == ((s2_b))[i]) &&       (\forall integer i; 0 <= i < ((len_map)) ==> ((s1_a))[i] == ((s2_a))[i] && ((s1_c))[i] == ((s2_c))[i]));
    //@ assert (\forall integer i; 0 <= i < (len_seq) ==> (s1_a)[i] == (s2_a)[i]);
    //@ assert (\forall integer i; 0 <= i < (len_set) ==> (s1_b)[i] == (s2_b)[i]);
    //@ assert (\forall integer i; 0 <= i < (len_map) ==> (s1_a)[i] == (s2_a)[i] && (s1_c)[i] == (s2_c)[i]);
    //@ assert \true;
}

int main() {
    return 0;
}
