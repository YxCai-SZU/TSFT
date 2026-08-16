#include <stdbool.h>

typedef struct {
    int* x;
    int x_len;
    bool* y;
    int y_len;
} MyStruct;

/*@
    requires \valid(s1.x + (0 .. s1.x_len-1));
    requires \valid(s2.x + (0 .. s2.x_len-1));
    requires \valid(s1.y + (0 .. s1.y_len-1));
    requires \valid(s2.y + (0 .. s2.y_len-1));
    requires ((s1).x_len == (s2).x_len &&
        (s1).y_len == (s2).y_len &&
        \forall integer i; 0 <= i < (s1).x_len ==> \at((s1).x[i], Here) == \at((s2).x[i], Here) &&
        \forall integer i; 0 <= i < (s1).y_len ==> \at((s1).y[i], Here) == \at((s2).y[i], Here));
    ensures s1.x_len == s2.x_len && s1.y_len == s2.y_len;
*/
void proof_example_func(MyStruct s1, MyStruct s2) {
    //@ assert ((s1).x_len == (s2).x_len &&         (s1).y_len == (s2).y_len &&         \forall integer i; 0 <= i < (s1).x_len ==> \at((s1).x[i], Here) == \at((s2).x[i], Here) &&         \forall integer i; 0 <= i < (s1).y_len ==> \at((s1).y[i], Here) == \at((s2).y[i], Here));
}

/*@
    requires \valid(s1.x + (0 .. s1.x_len-1));
    requires \valid(s2.x + (0 .. s2.x_len-1));
    requires \valid(s1.y + (0 .. s1.y_len-1));
    requires \valid(s2.y + (0 .. s2.y_len-1));
    requires ((s1).x_len == (s2).x_len &&
        (s1).y_len == (s2).y_len &&
        \forall integer i; 0 <= i < (s1).x_len ==> \at((s1).x[i], Here) == \at((s2).x[i], Here) &&
        \forall integer i; 0 <= i < (s1).y_len ==> \at((s1).y[i], Here) == \at((s2).y[i], Here));
    ensures s1.x_len == s2.x_len && s1.y_len == s2.y_len;
*/
void spec_example_func(MyStruct s1, MyStruct s2) {
    //@ assert ((s1).x_len == (s2).x_len &&         (s1).y_len == (s2).y_len &&         \forall integer i; 0 <= i < (s1).x_len ==> \at((s1).x[i], Here) == \at((s2).x[i], Here) &&         \forall integer i; 0 <= i < (s1).y_len ==> \at((s1).y[i], Here) == \at((s2).y[i], Here));
}

int main() {
    return 0;
}
