#include <stdbool.h>

/*@
    requires (10 <= (n) && (n) <= 99);
    ensures \result == (n / 10 == 9 || n % 10 == 9);
*/
bool func(int n)
{
    int n_abs;
    int div;
    int temp;
    int mod_res;
    
    //@ assert (10 <= (n) && (n) <= 99);
    
    n_abs = n;
    if (n < 0) {
        n_abs = -n;
    }
    
    //@ assert n < 0 ==> n_abs == -n;
    //@ assert n >= 0 ==> n_abs == n;
    
    div = 0;
    temp = n_abs;
    
    /*@
        loop invariant 10 <= n && n <= 99;
        loop invariant 0 <= div && div <= n_abs / 10;
        loop invariant temp == n_abs - 10 * div;
        loop invariant n < 0 ==> n_abs == -n;
        loop invariant n >= 0 ==> n_abs == n;
        loop assigns temp, div;
        loop variant temp;
    */
    while (temp >= 10) {
        temp -= 10;
        div += 1;
    }
    
    //@ assert div == n_abs / 10;
    
    mod_res = n_abs;
    
    /*@
        loop invariant 10 <= n && n <= 99;
        loop invariant 0 <= mod_res && mod_res <= n_abs;
        loop invariant mod_res == n_abs - 10 * ((n_abs - mod_res) / 10);
        loop invariant n < 0 ==> n_abs == -n;
        loop invariant n >= 0 ==> n_abs == n;
        loop assigns mod_res;
        loop variant mod_res;
    */
    while (mod_res >= 10) {
        mod_res -= 10;
    }
    
    //@ assert mod_res == n_abs % 10;
    
    return div == 9 || mod_res == 9;
}

int main() {
    return 0;
}
