#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

/*@
    requires \valid(m + (0..9));
    ensures (\forall integer i; 0 <= i < 10 ==> (m)[i] == 0);
    assigns m[0..9];
*/
void initialize_map(int *m) {
    int i;
    /*@
        loop invariant 0 <= i <= 10;
        loop invariant \forall integer j; 0 <= j < i ==> m[j] == 0;
        loop assigns i, m[0..9];
        loop variant 10 - i;
    */
    for (i = 0; i < 10; i++) {
        m[i] = 0;
    }
    //@ assert (\forall integer i; 0 <= i < 10 ==> (m)[i] == 0);
}

/*@
    requires \valid(m + (0..9));
    ensures (\forall integer i; 0 <= i < 10 ==> (m)[i] == 0);
    assigns m[0..9];
*/
void test_map(int *m) {
    initialize_map(m);
    //@ assert (\forall integer i; 0 <= i < 10 ==> (m)[i] == 0);
    
    m[3] = 4;
    m[6] = -8;
    
    bool b = (m[3] != 0);
    //@ assert b == true;
    
    int v = m[3];
    //@ assert v == 4;
    
    m[3] = 0;
    //@ assert !(0 <= (3) < 10 && (m)[(3)] != 0);
    //@ assert (0 <= (6) < 10 && (m)[(6)] != 0);
    
    initialize_map(m);
    //@ assert !(0 <= (3) < 10 && (m)[(3)] != 0);
    //@ assert !(0 <= (6) < 10 && (m)[(6)] != 0);
}

/*@
    requires \valid(m + (0..9));
    ensures (\forall integer i; 0 <= i < 10 ==> (m)[i] == 0);
    assigns m[0..9];
*/
void test_map2(int *m) {
    int three;
    int six;
    bool b;
    int v;
    
    initialize_map(m);
    //@ assert (\forall integer i; 0 <= i < 10 ==> (m)[i] == 0);
    
    three = 3;
    six = 6;
    m[three] = 4;
    m[six] = -8;
    
    b = (m[3] != 0);
    //@ assert b == true;
    
    v = m[6];
    //@ assert v == -8;
    
    m[6] = 0;
    //@ assert !(0 <= (six) < 10 && (m)[(six)] != 0);
    //@ assert (0 <= (three) < 10 && (m)[(three)] != 0);
    
    initialize_map(m);
    //@ assert !(0 <= (three) < 10 && (m)[(three)] != 0);
    //@ assert !(0 <= (six) < 10 && (m)[(six)] != 0);
}

int main() {
    int m1[10];
    int m2[10];
    test_map(m1);
    test_map2(m2);
    return 0;
}
