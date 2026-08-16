#include <stdbool.h>
/*@
    requires N >= 0;
    requires \valid(X_N + (0..N-1));
    requires (\forall integer i; 0 <= i < (N) ==> (X_N)[i] > 0);
    ensures \result == true <==> (\forall integer x; 0 <= x < (N) ==> 
            ((X_N)[x] % 2 == 0 ==> ((X_N)[x] % 3 == 0 || (X_N)[x] % 5 == 0)));
*/
bool func(int N, int *X_N) {
    int x;
    unsigned int index = 0;
    
    /*@
        loop invariant 0 <= index <= N;
        loop invariant (\forall integer i; 0 <= i < (N) ==> (X_N)[i] > 0);
        loop invariant \forall integer k; 0 <= k < index ==> 
            (X_N[k] % 2 == 0 ==> (X_N[k] % 3 == 0 || X_N[k] % 5 == 0));
        loop assigns index, x;
        loop variant N - index;
    */
    while (index < (unsigned int)N) {
        x = X_N[index];
        bool is_even = false;
        bool is_divisible_by_3 = false;
        bool is_divisible_by_5 = false;
        int temp;
        
        // Check if the number is even
        temp = x;
        /*@
            loop invariant temp >= 0;
            loop invariant temp <= x;
            loop invariant temp % 2 == x % 2;
            loop assigns temp;
            loop variant temp;
        */
        while (temp >= 2) {
            temp -= 2;
        }
        if (temp == 0) {
            is_even = true;
        }
        
        // Check if the number is divisible by 3
        temp = x;
        /*@
            loop invariant temp >= 0;
            loop invariant temp <= x;
            loop invariant temp % 3 == x % 3;
            loop assigns temp;
            loop variant temp;
        */
        while (temp >= 3) {
            temp -= 3;
        }
        if (temp == 0) {
            is_divisible_by_3 = true;
        }
        
        // Check if the number is divisible by 5
        temp = x;
        /*@
            loop invariant temp >= 0;
            loop invariant temp <= x;
            loop invariant temp % 5 == x % 5;
            loop assigns temp;
            loop variant temp;
        */
        while (temp >= 5) {
            temp -= 5;
        }
        if (temp == 0) {
            is_divisible_by_5 = true;
        }
        
        //@ assert is_even == (x % 2 == 0);
        //@ assert is_divisible_by_3 == (x % 3 == 0);
        //@ assert is_divisible_by_5 == (x % 5 == 0);
        
        if (is_even && !(is_divisible_by_3 || is_divisible_by_5)) {
            //@ assert !(\forall integer x; 0 <= x < (N) ==>              ((X_N)[x] % 2 == 0 ==> ((X_N)[x] % 3 == 0 || (X_N)[x] % 5 == 0)));
            return false;
        }
        index++;
    }
    //@ assert (\forall integer x; 0 <= x < (N) ==>              ((X_N)[x] % 2 == 0 ==> ((X_N)[x] % 3 == 0 || (X_N)[x] % 5 == 0)));
    return true;
}
