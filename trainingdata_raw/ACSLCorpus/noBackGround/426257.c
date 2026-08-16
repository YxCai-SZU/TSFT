#include <stdbool.h>

/*@
    requires \valid(a+(0..1));
    requires (1 <= (a[0]) && (a[0]) <= 12);
    requires (1 <= (a[1]) && (a[1]) <= 31);
    ensures \result >= 0;
    assigns \nothing;
*/
int func(int a[2]) {
    int ans;
    int result;
    
    //@ assert a[0] >= 1 && a[0] <= 12;
    //@ assert a[1] >= 1 && a[1] <= 31;
    
    if (a[0] <= 9) {
        ans = a[0] * 400 + 100;
    } else {
        ans = a[0] * 800 + 100;
    }
    
    //@ assert ans >= 0;
    
    if (a[1] == 1 || a[1] == 3 || a[1] == 5 || a[1] == 7 || 
        a[1] == 8 || a[1] == 10 || a[1] == 12) {
        result = ans + 100;
    } else if (a[1] == 4 || a[1] == 6 || a[1] == 9 || a[1] == 11) {
        result = ans + 50;
    } else {
        result = ans;
    }
    
    //@ assert result >= 0;
    return result;
}
