#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (h) <= 100);
    requires ((h) % 2 == 0);
    ensures \result == (((((a)) + ((b))) * ((h))) / 2);
*/
int func(int a, int b, int h) {
    int sum;
    int result;
    int i;
    int temp_sum;
    
    //@ assert 1 <= (a + b) * h <= 20000;
    
    sum = (a + b) * h;
    result = 0;
    i = 0;
    temp_sum = sum;
    
    /*@
        loop invariant 0 <= temp_sum <= sum;
        loop invariant i <= sum / 2;
        loop invariant temp_sum + 2 * i == sum;
        loop invariant (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (h) <= 100);
        loop invariant ((h) % 2 == 0);
        loop assigns temp_sum, i;
        loop variant temp_sum;
    */
    while (temp_sum >= 2) {
        temp_sum -= 2;
        i += 1;
    }
    
    result = i;
    
    //@ assert result == (((((a)) + ((b))) * ((h))) / 2);
    return result;
}
