#include <stdbool.h>
#include <stddef.h>


bool func(size_t n, const int *v) {
    bool ans = false;
    size_t i = 0;
    
    
    while (i < n) {
        //@ assert 0 <= i < n;
        if (v[i] == 1) {
            ans = true;
        }
        i++;
    }
    return ans;
}
