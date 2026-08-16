#include <stdbool.h>
void test_new_subrange() {
    int s[5];
    int i;
    
    // Initialize array
    /*@ loop invariant 0 <= i <= 5;
        loop invariant \forall integer j; 0 <= j < i ==> s[j] == 10 * j;
        loop assigns i, s[0..4];
    */
    for (i = 0; i < 5; i++) {
        s[i] = 10 * i;
    }
    
    // Verify subrange
    /*@ assert (0 <= (1) && (1) <= (4) && (4) <= (5)); */
    /*@ assert (((1) <= (1) && (1) < (4)) ? (((&s[0]))[((1))]) : 0) == 10; */
    /*@ assert (((1) <= (2) && (2) < (4)) ? (((&s[0]))[((2))]) : 0) == 20; */
    /*@ assert (((1) <= (3) && (3) < (4)) ? (((&s[0]))[((3))]) : 0) == 30; */
}

void test_subrange_first_last() {
    int s[5] = {10, 20, 30, 40, 50};
    
    /*@ assert (0 <= (1) && (1) <= (4) && (4) <= (5)); */
    /*@ assert (((1) <= (1) && (1) < (4)) ? (((&s[0]))[((1))]) : 0) == 20; */
    /*@ assert (((1) <= (2) && (2) < (4)) ? (((&s[0]))[((2))]) : 0) == 30; */
    /*@ assert (((1) <= (3) && (3) < (4)) ? (((&s[0]))[((3))]) : 0) == 40; */
}
