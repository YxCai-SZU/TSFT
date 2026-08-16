#include <stdbool.h>

/*@ requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    requires 1 <= c <= 100;
    ensures \result == (a + b + c == 180);
*/
bool func(unsigned int a, unsigned int b, unsigned int c) {
    bool valid = true;
    unsigned int sum = a + b + c;
    
    //@ assert sum == a + b + c;
    
    if (sum != 180) {
        valid = false;
    }
    
    //@ assert valid == (a + b + c == 180);
    return valid;
}

void test_vec_to_seq_operations(void) {
    int v[5];
    v[0] = 1;
    v[1] = 3;
    v[2] = 5;
    v[3] = 7;
    v[4] = 9;
    
    //@ assert v[0] == 1 && v[1] == 3;
    //@ assert v[2] == 5 && v[3] == 7;
    //@ assert v[4] == 9;
    
    //@ assert ((5) >= 3 && (&v[0])[0] < (&v[0])[1] && (&v[0])[1] < (&v[0])[2]);
    //@ assert (\exists integer i, j; 0 <= i < j < (5) && (&v[0])[i] % 2 == 1 && (&v[0])[j] % 2 == 1);
}
