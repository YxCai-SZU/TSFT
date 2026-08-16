#include <stdbool.h>

/*@
    requires (1 <= (r) && (r) <= 100);
    ensures \result == ((r) * (r));
    assigns \nothing;
*/
int func(int r) {
    int ans;
    
    //@ assert (1 <= (r) && (r) <= 100);
    //@ assert 1 <= ((r) * (r)) && ((r) * (r)) <= 10000;
    
    ans = r * r;
    return ans;
}

/*@
    assigns \nothing;
    ensures \result == 0;
*/
int read_vec() {
    return 0;
}

int main() {
    return 0;
}
