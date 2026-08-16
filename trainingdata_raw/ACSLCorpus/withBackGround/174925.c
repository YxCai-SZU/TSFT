/*@
    predicate set_contains{L}(int *s, integer i, integer size) =
        \exists integer idx; 0 <= idx < size && s[idx] == i;

    predicate sets_equal{L}(int *s1, integer size1, int *s2, integer size2) =
        \forall integer i; set_contains(s1, i, size1) <==> set_contains(s2, i, size2);

    lemma sets_ext_equal{L}:
        \forall int *s1, *s2, integer size1, size2;
        sets_equal(s1, size1, s2, size2) ==>
        (\forall integer i; set_contains(s1, i, size1) <==> set_contains(s2, i, size2));
*/

struct Foo {
    int *s;
    int size;
};

/*@
    requires \valid(s1) && \valid(s2);
    requires \valid(s1->s + (0 .. s1->size-1));
    requires \valid(s2->s + (0 .. s2->size-1));
    requires \forall integer i; set_contains(s1->s, i, s1->size) <==> set_contains(s2->s, i, s2->size);
    ensures \result == 1;
*/
int sets_ext_equal(struct Foo *s1, struct Foo *s2) {
    //@ assert \forall integer i; set_contains(s1->s, i, s1->size) <==> set_contains(s2->s, i, s2->size);
    return 1;
}

int main() {
    return 0;
}
