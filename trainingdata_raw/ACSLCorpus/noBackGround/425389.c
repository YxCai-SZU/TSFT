#include <limits.h>

/*@
    requires (1 <= (N) <= 1000000);
    ensures \result == ((((N)) / 2) - (((N)) / 10) + (((((N)) / 10)) / 5));
*/
int func(int N) {
    int n_div_2 = 0;
    int temp_n = N;
    int result = 0;
    
    /*@
        loop invariant 0 <= temp_n <= N;
        loop invariant n_div_2 >= 0;
        loop invariant n_div_2 <= ((N) / 2);
        loop invariant temp_n == N - 2 * n_div_2;
        loop assigns temp_n, n_div_2;
        loop variant temp_n;
    */
    while (temp_n >= 2) {
        temp_n -= 2;
        n_div_2 += 1;
    }

    int n_div_10 = 0;
    temp_n = N;
    
    /*@
        loop invariant 0 <= temp_n <= N;
        loop invariant n_div_10 >= 0;
        loop invariant n_div_10 <= ((N) / 10);
        loop invariant temp_n == N - 10 * n_div_10;
        loop assigns temp_n, n_div_10;
        loop variant temp_n;
    */
    while (temp_n >= 10) {
        temp_n -= 10;
        n_div_10 += 1;
    }

    int n_div_10_div_5 = 0;
    temp_n = n_div_10;
    
    /*@
        loop invariant 0 <= temp_n <= n_div_10;
        loop invariant n_div_10_div_5 >= 0;
        loop invariant n_div_10_div_5 <= ((n_div_10) / 5);
        loop invariant temp_n == n_div_10 - 5 * n_div_10_div_5;
        loop assigns temp_n, n_div_10_div_5;
        loop variant temp_n;
    */
    while (temp_n >= 5) {
        temp_n -= 5;
        n_div_10_div_5 += 1;
    }

    //@ assert n_div_2 == ((N) / 2);
    //@ assert n_div_10 == ((N) / 10);
    //@ assert n_div_10_div_5 == ((((N) / 10)) / 5);
    
    result = n_div_2 - n_div_10 + n_div_10_div_5;
    //@ assert result == ((((N)) / 2) - (((N)) / 10) + (((((N)) / 10)) / 5));
    
    return result;
}

int main() {
    return 0;
}
