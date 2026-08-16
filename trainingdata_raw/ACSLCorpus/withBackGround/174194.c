#include <stdbool.h>

/*@
    predicate is_valid_range(integer N) = 100 <= N && N <= 999;
    
    logic integer div_100_result(integer N) = N / 100;
    logic integer div_10_mod_result(integer N) = (N / 10) % 10;
    logic integer mod_10_result(integer N) = N % 10;
    
    predicate has_seven(integer N) = 
        div_100_result(N) == 7 || 
        div_10_mod_result(N) == 7 || 
        mod_10_result(N) == 7;
*/

/*@
    requires is_valid_range(N);
    ensures \result == (div_100_result(N) == 7 || div_10_mod_result(N) == 7 || mod_10_result(N) == 7);
*/
bool func(long N) {
    long div_100 = 0;
    long temp_N = N;
    long div_10 = 0;
    bool condition1;
    bool condition2;
    bool condition3;
    bool result;
    
    //@ assert is_valid_range(N);
    
    /*@
        loop invariant 100 <= N && N <= 999;
        loop invariant 0 <= temp_N && temp_N <= N;
        loop invariant temp_N == N - 100 * div_100;
        loop invariant div_100 >= 0;
        loop assigns temp_N, div_100;
    */
    while (temp_N >= 100) {
        temp_N -= 100;
        div_100 += 1;
    }
    
    /*@
        loop invariant 100 <= N && N <= 999;
        loop invariant 0 <= temp_N && temp_N <= N;
        loop invariant temp_N == N - 100 * div_100 - 10 * div_10;
        loop invariant div_100 >= 0;
        loop invariant div_10 >= 0;
        loop assigns temp_N, div_10;
    */
    while (temp_N >= 10) {
        temp_N -= 10;
        div_10 += 1;
    }
    
    condition1 = (div_100 == 7);
    condition2 = (div_10 == 7);
    condition3 = (temp_N == 7);
    
    //@ assert div_100 == div_100_result(N);
    //@ assert div_10 == div_10_mod_result(N);
    //@ assert temp_N == mod_10_result(N);
    
    if (condition1 || condition2 || condition3) {
        result = true;
    } else {
        result = false;
    }
    
    //@ assert result == (div_100_result(N) == 7 || div_10_mod_result(N) == 7 || mod_10_result(N) == 7);
    return result;
}
