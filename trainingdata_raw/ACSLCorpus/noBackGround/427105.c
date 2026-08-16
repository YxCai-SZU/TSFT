#include <limits.h>

/*@
    requires (-1000 <= (a) && (a) <= 1000) && (-1000 <= (b) && (b) <= 1000) && (-1000 <= (c) && (c) <= 1000);
    ensures \result == a + b + c;
    assigns \nothing;
*/
int add_three_times(int a, int b, int c) {
    //@ assert (-1000 <= (a) && (a) <= 1000);
    //@ assert (-1000 <= (b) && (b) <= 1000);
    //@ assert (-1000 <= (c) && (c) <= 1000);
    return a + b + c;
}

/*@
    requires (-1000 <= (a) && (a) <= 1000) && (-1000 <= (b) && (b) <= 1000) && (-1000 <= (c) && (c) <= 1000);
    ensures \result == a - b - c;
    assigns \nothing;
*/
int subtract_three_times(int a, int b, int c) {
    //@ assert (-1000 <= (a) && (a) <= 1000);
    //@ assert (-1000 <= (b) && (b) <= 1000);
    //@ assert (-1000 <= (c) && (c) <= 1000);
    return a - b - c;
}

int main() {
    int add_result;
    int subtract_result;
    
    add_result = add_three_times(300, 700, 1000);
    //@ assert add_result == 2000;
    
    subtract_result = subtract_three_times(1000, 300, 700);
    //@ assert subtract_result == 0;
    
    return 0;
}
