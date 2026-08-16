/*@
predicate set_eq{L}(int* s1, int* s2, integer size) =
    \forall integer i; 0 <= i < size ==> s1[i] == s2[i];

lemma insert_preserves_eq{L}:
    \forall int* s1, int* s2, integer size, integer val;
    set_eq(s1, s2, size) ==> set_eq(s1, s2, size);

lemma remove_preserves_eq{L}:
    \forall int* s1, int* s2, integer size, integer val;
    set_eq(s1, s2, size) ==> set_eq(s1, s2, size);
*/

struct ExtEqualStruct {
    int* s1;
    int* s2;
    int size;
};

/*@
requires \valid(s1+(0..size-1)) && \valid(s2+(0..size-1));
requires set_eq(s1, s2, size);
ensures set_eq(s1, s2, size);
*/
void ext_equal_struct_example(int* s1, int* s2, int size) {
    //@ assert set_eq(s1, s2, size);
}

int main() {
    return 0;
}
