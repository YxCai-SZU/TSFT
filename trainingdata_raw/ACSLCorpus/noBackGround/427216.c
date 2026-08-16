#include <stdbool.h>

/*@
    requires \valid(tuplex) && *tuplex > 0;
    requires \valid(tuplex + (0 .. *tuplex));
    ensures \result == true <==> (\exists integer i; 0 <= i < *tuplex && tuplex[i+1] == value);
    assigns \nothing;
 */
bool check_tuplex(int *tuplex, int value) {
    int len = tuplex[0];
    int i = 0;

    /*@
        loop invariant 0 <= i <= len;
        loop invariant \forall integer j; 0 <= j < i ==> tuplex[j+1] != value;
        loop assigns i;
        loop variant len - i;
     */
    while (i < len) {
        //@ assert \forall integer j; 0 <= j < i ==> tuplex[j+1] != value;
        if (tuplex[i+1] == value) {
            //@ assert 0 <= i < len && tuplex[i+1] == value;
            return true;
        }
        i = i + 1;
    }
    return false;
}

int main() {
    return 0;
}
