#include <stdbool.h>
#include <stddef.h>

struct MyStruct {
    int *x;
    size_t x_len;
    int *y;
    size_t y_len;
};

struct AnotherStruct {
    int *z;
    size_t z_len;
    int *w;
    size_t w_len;
};

struct YetAnotherStruct {
    int *a;
    size_t a_len;
    int *b;
    size_t b_len;
};

/*@
    predicate seq_eq(int *a, int *b, size_t len) =
        \forall size_t i; 0 <= i < len ==> a[i] == b[i];

    predicate MyStruct_eq(struct MyStruct s1, struct MyStruct s2) =
        s1.x_len == s2.x_len &&
        s1.y_len == s2.y_len &&
        seq_eq(s1.x, s2.x, s1.x_len) &&
        seq_eq(s1.y, s2.y, s1.y_len);

    predicate AnotherStruct_eq(struct AnotherStruct s1, struct AnotherStruct s2) =
        s1.z_len == s2.z_len &&
        s1.w_len == s2.w_len &&
        seq_eq(s1.z, s2.z, s1.z_len) &&
        seq_eq(s1.w, s2.w, s1.w_len);

    predicate YetAnotherStruct_eq(struct YetAnotherStruct s1, struct YetAnotherStruct s2) =
        s1.a_len == s2.a_len &&
        s1.b_len == s2.b_len &&
        seq_eq(s1.a, s2.a, s1.a_len) &&
        seq_eq(s1.b, s2.b, s1.b_len);
*/

/*@
    lemma my_struct_equal:
        \forall struct MyStruct s1, s2;
            MyStruct_eq(s1, s2) ==> s1.x_len == s2.x_len;
*/

/*@
    lemma another_struct_equal:
        \forall struct AnotherStruct s1, s2;
            AnotherStruct_eq(s1, s2) ==> s1.z_len == s2.z_len;
*/

/*@
    lemma yet_another_struct_equal:
        \forall struct YetAnotherStruct s1, s2;
            YetAnotherStruct_eq(s1, s2) ==> s1.a_len == s2.a_len;
*/

/*@
    requires MyStruct_eq(my_struct, my_struct2);
    requires AnotherStruct_eq(another_struct, another_struct2);
    requires YetAnotherStruct_eq(yet_another_struct, yet_another_struct2);
    ensures my_struct.x_len == my_struct2.x_len;
    ensures another_struct.z_len == another_struct2.z_len;
    ensures yet_another_struct.a_len == yet_another_struct2.a_len;
*/
void all_structs_equal(
    struct MyStruct my_struct,
    struct AnotherStruct another_struct,
    struct YetAnotherStruct yet_another_struct,
    struct MyStruct my_struct2,
    struct AnotherStruct another_struct2,
    struct YetAnotherStruct yet_another_struct2
) {
    //@ assert my_struct.x_len == my_struct2.x_len;
    //@ assert another_struct.z_len == another_struct2.z_len;
    //@ assert yet_another_struct.a_len == yet_another_struct2.a_len;
}

int main() {
    return 0;
}
