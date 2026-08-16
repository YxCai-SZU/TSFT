#include <stdbool.h>

/*@
    requires (1 <= (r) <= 100);
    ensures \result == (((r) * (2)* (3142)) / (1000));
    assigns \nothing;
*/
int func(int r) {
    int pi_approx = 3142;
    int two = 2;
    int one_thousand = 1000;
    int result = 0;
    int temp = r * two * pi_approx;
    int count = 0;
    
    //@ ghost int initial_temp = temp;
    
    /*@
        loop invariant 1 <= r <= 100;
        loop invariant (3142)== 3142;
        loop invariant (2)== 2;
        loop invariant (1000)== 1000;
        loop invariant temp >= 0;
        loop invariant temp == initial_temp - count * (1000);
        loop invariant count >= 0;
        loop invariant count <= (r * (2)* (3142)) / (1000);
        loop assigns temp, count;
        loop variant temp;
    */
    while (temp >= one_thousand) {
        //@ assert temp >= 1000;
        temp -= one_thousand;
        count += 1;
    }
    
    result = count;
    
    //@ assert result == (r * (2)* (3142)) / (1000);
    return result;
}

int main() {
    return 0;
}
