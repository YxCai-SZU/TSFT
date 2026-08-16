#include <stdbool.h>

/*@ predicate in_range(integer x) = -10 <= x <= 10; */

/*@
    requires \valid(v+(0..len-1));
    requires len > 0;
    requires \forall integer i; 0 <= i < len ==> in_range(v[i]);
    ensures \result == true;
*/
bool process_list(const int* v, int len) {
    int j = 0;
    /*@
        loop invariant 0 <= j <= len;
        loop invariant \forall integer i; 0 <= i < j ==> in_range(v[i]);
        loop assigns j;
    */
    while (j < len) {
        //@ assert in_range(v[j]);
        if (!(-10 <= v[j] && v[j] <= 10)) {
            return false;
        }
        j = j + 1;
    }
    return true;
}

/*@
    requires 1 <= A <= 20;
    requires 1 <= B <= 20;
    ensures \result == A * B;
*/
int func(int A, int B) {
    //@ assert A * B <= 20 * 20;
    return A * B;
}

int main() {
    return 0;
}
