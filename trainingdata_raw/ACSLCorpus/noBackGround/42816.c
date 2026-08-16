#include <stdbool.h>

/*@ requires (1 <= (a) <= 3) && (1 <= (b) <= 3) && ((a) != (b));
    ensures ((\result) + (a) + (b) == 6 && ((\result) == 1 || (\result) == 2 || (\result) == 3));
    assigns \nothing;
*/
int func(int a, int b) {
    // Variable declarations at top
    int result;
    
    //@ assert 1 <= 6 - a - b <= 3;
    result = 6 - a - b;
    
    //@ assert ((result) + (a) + (b) == 6 && ((result) == 1 || (result) == 2 || (result) == 3));
    return result;
}

int main() {
    return 0;
}
