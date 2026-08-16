#include <stdbool.h>
#include <stddef.h>

/*@
    requires ((s_len) > 0 && \valid((s) + (0 .. (s_len)-1)));
    ensures \result ==> ((s_len)) > 0;
*/
bool func(int *s, size_t s_len)
{
    // Declare all variables at the top
    int v[4];
    size_t v_len = 0;
    int n[2];
    size_t n_len = 0;
    bool result;
    
    // Initialize v with elements
    v[0] = 2; v_len++;
    v[1] = 4; v_len++;
    v[2] = 6; v_len++;
    v[3] = 8; v_len++;
    
    // Split v at index 2
    //@ assert v_len == 4;
    n[0] = v[2];
    n[1] = v[3];
    n_len = 2;
    v_len = 2;
    
    // Verify split results
    //@ assert v[0] == 2 && v[1] == 4;
    //@ assert n[0] == 6 && n[1] == 8;
    
    result = true;
    //@ assert result ==> ((s_len)) > 0;
    return result;
}

int main() {
    return 0;
}
