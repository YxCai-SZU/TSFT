#include <stdbool.h>
#include <stdint.h>

/*@
    requires \valid(keys + (0 .. 2)) && \valid(values + (0 .. 2));
    requires ((3) == 3 &&
        (keys)[0] == 1 && (values)[0] == 10 &&
        (keys)[1] == 2 && (values)[1] == 20 &&
        (keys)[2] == 3 && (values)[2] == 30);
    ensures ((3) == 3 &&
        (keys)[0] == 1 && (values)[0] == 10 &&
        (keys)[1] == 2 && (values)[1] == 20 &&
        (keys)[2] == 3 && (values)[2] == 30);
*/
void contains_all_keys(unsigned int *keys, uint64_t *values)
{
    //@ assert ((3) == 3 &&         (keys)[0] == 1 && (values)[0] == 10 &&         (keys)[1] == 2 && (values)[1] == 20 &&         (keys)[2] == 3 && (values)[2] == 30);
    
    bool found1 = false;
    uint64_t val1 = 0;
    int i = 0;
    /*@
        loop invariant 0 <= i <= 3;
        loop invariant \forall integer j; 0 <= j < i ==> keys[j] != 1;
        loop assigns i, found1, val1;
    */
    for (i = 0; i < 3; i++) {
        if (keys[i] == 1) {
            found1 = true;
            val1 = values[i];
            break;
        }
    }
    //@ assert found1 == true;
    //@ assert val1 == 10;
    
    bool found2 = false;
    uint64_t val2 = 0;
    i = 0;
    /*@
        loop invariant 0 <= i <= 3;
        loop invariant \forall integer j; 0 <= j < i ==> keys[j] != 2;
        loop assigns i, found2, val2;
    */
    for (i = 0; i < 3; i++) {
        if (keys[i] == 2) {
            found2 = true;
            val2 = values[i];
            break;
        }
    }
    //@ assert found2 == true;
    //@ assert val2 == 20;
    
    bool found3 = false;
    uint64_t val3 = 0;
    i = 0;
    /*@
        loop invariant 0 <= i <= 3;
        loop invariant \forall integer j; 0 <= j < i ==> keys[j] != 3;
        loop assigns i, found3, val3;
    */
    for (i = 0; i < 3; i++) {
        if (keys[i] == 3) {
            found3 = true;
            val3 = values[i];
            break;
        }
    }
    //@ assert found3 == true;
    //@ assert val3 == 30;
}

int main() {
    return 0;
}
