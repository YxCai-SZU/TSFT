#include <stddef.h>

/*@
    requires (\valid((arr) + (0 .. (len)-1)));
    requires k >= 1 && k <= len;
    assigns \nothing;
    ensures \result == arr[k-1];
*/
int kth_element(int *arr, size_t len, size_t k) {
    // Variable declarations at top of scope
    int result;
    
    //@ assert k-1 < len;
    
    result = arr[k-1];
    return result;
}

int main() {
    return 0;
}
