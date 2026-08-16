#include <stdbool.h>

/*@
    requires 1 <= a && a <= b && b <= c && c <= 100;
    ensures 1 <= c && c <= 100;
*/
void func(int a, int b, int c) {
    // Variable declarations at scope top
    int temp_a = a;
    int temp_b = b;
    int temp_c = c;
    
    //@ assert 1 <= temp_a;
    //@ assert temp_a <= temp_b;
    //@ assert temp_b <= temp_c;
    //@ assert temp_c <= 100;
    //@ assert temp_c >= 1;
}
