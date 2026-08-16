#include <stdbool.h>

/*@
    requires \valid_read(input + (0 .. len-1));
    requires ((len) >= 1 &&
        \forall integer i; 0 <= i < (len) ==> (1 <= (input)[i] && (input)[i] <= 100));
    ensures \result == true <==> (\forall integer i; 0 <= i < (len) ==> ((input)[i] % 2 == 0 || (input)[i] % 6 == 0 || (input)[i] % 10 == 0));
*/
bool func(int *input, int len) {
    int i;
    int a;
    bool is_divisible_by_2;
    bool is_divisible_by_6;
    bool is_divisible_by_10;
    int temp;
    
    i = 0;
    /*@
        loop invariant 0 <= i <= len;
        loop invariant \forall integer j; 0 <= j < i ==> (input[j] % 2 == 0 || input[j] % 6 == 0 || input[j] % 10 == 0);
        loop assigns i, is_divisible_by_2, is_divisible_by_6, is_divisible_by_10, temp, a;
        loop variant len - i;
    */
    while (i < len) {
        a = input[i];
        
        is_divisible_by_2 = false;
        is_divisible_by_6 = false;
        is_divisible_by_10 = false;
        
        temp = a;
        /*@
            loop invariant temp >= 0;
            loop invariant temp <= a;
            loop invariant temp % 2 == a % 2;
            loop assigns temp;
            loop variant temp;
        */
        while (temp >= 2) {
            temp -= 2;
        }
        if (temp == 0) {
            is_divisible_by_2 = true;
        }
        
        temp = a;
        /*@
            loop invariant temp >= 0;
            loop invariant temp <= a;
            loop invariant temp % 6 == a % 6;
            loop assigns temp;
            loop variant temp;
        */
        while (temp >= 6) {
            temp -= 6;
        }
        if (temp == 0) {
            is_divisible_by_6 = true;
        }
        
        temp = a;
        /*@
            loop invariant temp >= 0;
            loop invariant temp <= a;
            loop invariant temp % 10 == a % 10;
            loop assigns temp;
            loop variant temp;
        */
        while (temp >= 10) {
            temp -= 10;
        }
        if (temp == 0) {
            is_divisible_by_10 = true;
        }
        
        if (!(is_divisible_by_2 || is_divisible_by_6 || is_divisible_by_10)) {
            return false;
        }
        i += 1;
    }
    return true;
}
