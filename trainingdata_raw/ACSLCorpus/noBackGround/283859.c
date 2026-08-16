#include <stdbool.h>

/*@
    requires (1 <= (a) <= 1000000);
    ensures \result == 0 || \result == 1;
    assigns \nothing;
*/
int func(long long a) {
    long long i;
    long long ans;
    long long temp;
    bool divisible;
    long long temp_ans;
    bool is_even;
    
    i = 1;
    ans = 0;
    
    /*@
        loop invariant (1 <= (a) <= 1000000);
        loop invariant (1 <= (i) <= (a) + 1);
        loop invariant (0 <= (ans) <= (i) - 1);
        loop assigns i, ans, temp, divisible;
        loop variant ((a) + 1 - (i));
    */
    while (i <= a) {
        divisible = false;
        temp = a;
        
        /*@
            loop invariant (1 <= (a) <= 1000000);
            loop invariant (1 <= (i) <= (a) + 1);
            loop invariant (0 <= (temp) <= (a));
            loop assigns temp;
            loop variant ((temp));
        */
        while (temp >= i) {
            temp -= i;
        }
        
        if (temp == 0) {
            divisible = true;
        }
        
        if (divisible) {
            ans += 1;
        }
        
        i += 1;
    }
    
    is_even = false;
    temp_ans = ans;
    
    /*@
        loop invariant (1 <= (a) <= 1000000);
        loop invariant (0 <= (temp_ans) <= (ans));
        loop invariant ((temp_ans) % 2 == (ans) % 2);
        loop assigns temp_ans;
        loop variant ((temp_ans));
    */
    while (temp_ans >= 2) {
        temp_ans -= 2;
    }
    
    if (temp_ans == 0) {
        is_even = true;
    }
    
    if (is_even) {
        return 0;
    } else {
        return 1;
    }
}
