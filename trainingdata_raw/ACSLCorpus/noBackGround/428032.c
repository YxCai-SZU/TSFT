#include <stdbool.h>
#include <stddef.h>

typedef struct {
    char *name;
    int *data;
    int name_len;
    int data_len;
} NamedMap;

/*@
requires \valid(m1) && \valid(m2);
requires (\valid((m1)) &&
    \valid((m1)->name + (0 .. (m1)->name_len-1)) &&
    (m1)->name_len >= 0 &&
    \valid((m1)->data + (0 .. (m1)->data_len-1)) &&
    (m1)->data_len >= 0) && (\valid((m2)) &&
    \valid((m2)->name + (0 .. (m2)->name_len-1)) &&
    (m2)->name_len >= 0 &&
    \valid((m2)->data + (0 .. (m2)->data_len-1)) &&
    (m2)->data_len >= 0);
requires ((\valid(((m1))) &&
    \valid(((m1))->name + (0 .. ((m1))->name_len-1)) &&
    ((m1))->name_len >= 0 &&
    \valid(((m1))->data + (0 .. ((m1))->data_len-1)) &&
    ((m1))->data_len >= 0) &&
    (\valid(((m2))) &&
    \valid(((m2))->name + (0 .. ((m2))->name_len-1)) &&
    ((m2))->name_len >= 0 &&
    \valid(((m2))->data + (0 .. ((m2))->data_len-1)) &&
    ((m2))->data_len >= 0) &&
    (m1)->name_len == (m2)->name_len &&
    (\forall integer i; 0 <= i < (m1)->name_len ==> (m1)->name[i] == (m2)->name[i]) &&
    (m1)->data_len == (m2)->data_len &&
    (\forall integer j; 0 <= j < (m1)->data_len ==> (m1)->data[j] == (m2)->data[j]));
ensures m1->name_len == m2->name_len && m1->data_len == m2->data_len;
*/
void map_eq(NamedMap *m1, NamedMap *m2) {
    //@ assert ((\valid(((m1))) &&     \valid(((m1))->name + (0 .. ((m1))->name_len-1)) &&     ((m1))->name_len >= 0 &&     \valid(((m1))->data + (0 .. ((m1))->data_len-1)) &&     ((m1))->data_len >= 0) &&     (\valid(((m2))) &&     \valid(((m2))->name + (0 .. ((m2))->name_len-1)) &&     ((m2))->name_len >= 0 &&     \valid(((m2))->data + (0 .. ((m2))->data_len-1)) &&     ((m2))->data_len >= 0) &&     (m1)->name_len == (m2)->name_len &&     (\forall integer i; 0 <= i < (m1)->name_len ==> (m1)->name[i] == (m2)->name[i]) &&     (m1)->data_len == (m2)->data_len &&     (\forall integer j; 0 <= j < (m1)->data_len ==> (m1)->data[j] == (m2)->data[j]));
}

int main() {
    return 0;
}
