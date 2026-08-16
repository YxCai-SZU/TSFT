#include <stdbool.h>

struct MyData {
    int *v;
    int len;
};

/*@
    requires \valid(d1) && \valid(d2);
    requires d1->len == d2->len;
    requires \valid(d1->v + (0 .. d1->len-1));
    requires \valid(d2->v + (0 .. d2->len-1));
    requires ((d1)->len == (d2)->len && (\forall integer i; 0 <= i < ((d1)->len) ==> \at(((d1)->v)[i], Here) == \at(((d2)->v)[i], Here)));
    ensures ((d1)->len == (d2)->len && (\forall integer i; 0 <= i < ((d1)->len) ==> \at(((d1)->v)[i], Here) == \at(((d2)->v)[i], Here)));
*/
void test_equality(struct MyData *d1, struct MyData *d2) {
    //@ assert ((d1)->len == (d2)->len && (\forall integer i; 0 <= i < ((d1)->len) ==> \at(((d1)->v)[i], Here) == \at(((d2)->v)[i], Here)));
}

int main() {
    return 0;
}
