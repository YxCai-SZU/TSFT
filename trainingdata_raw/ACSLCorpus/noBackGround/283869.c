#include <stdbool.h>

/*@
    requires (1 <= (A) <= 100) && (1 <= (B) <= 100);
    ensures \result == ((A) * (B));
    assigns \nothing;
*/
int func(int A, int B) {
    int result;
    int i;
    int arr[3];
    
    //@ assert (1 <= (A) <= 100);
    //@ assert (1 <= (B) <= 100);
    //@ assert ((A) * (B)) <= 10000;
    
    result = A * B;
    
    i = 0;
    /*@
        loop invariant 0 <= i <= 10;
        loop invariant (1 <= (A) <= 100) && (1 <= (B) <= 100);
        loop invariant ((A) * (B)) <= 10000;
        loop assigns i, arr[0..2];
        loop variant 10 - i;
    */
    while (i < 10) {
        //@ assert 0 <= i <= 10;
        
        arr[0] = A * B;
        arr[1] = A * B;
        arr[2] = A * B;
        
        i = i + 1;
    }
    
    //@ assert result == ((A) * (B));
    return result;
}
