#include <stdbool.h>


int func(int *v) {
    int res = 0;
    int a = v[0];
    int b = v[1];
    int c = v[2];

    
    while (a >= 1 && b >= 1 && c >= 1) {
        int a_mod = (a < 0) ? (a - 1) : a;
        int b_mod = (b < 0) ? (b - 1) : b;
        int c_mod = (c < 0) ? (c - 1) : c;
        int min_val;
        
        if (a_mod < b_mod) {
            min_val = (a_mod < c_mod) ? a_mod : c_mod;
        } else {
            min_val = (b_mod < c_mod) ? b_mod : c_mod;
        }
        
        //@ assert min_val >= 0;
        res += min_val;
        a -= min_val;
        b -= min_val;
        c -= min_val;
        //@ assert res <= v[2];
    }
    
    return res;
}

int main() {
    return 0;
}
