#include <stdbool.h>

/*@
    requires n > 0 && n <= 100;
    requires \valid(a + (0..n-1));
    requires ((n) > 0 && (n) <= 100 &&
        \forall integer i; 0 <= i < (n) ==> (a)[i] > 0 && (a)[i] <= 1000);
    ensures \result == true <==> 
        (\forall integer i; 0 <= i < n ==> 
            (a[i] % 2 != 0) || (a[i] % 6 == 0) || (a[i] % 10 == 0));
    assigns \nothing;
*/
bool func(unsigned int n, int *a) {
    unsigned int i = 0;
    bool result = true;
    
    /*@
        loop invariant 0 <= i <= n;
        loop invariant (\forall integer j; 0 <= j < (i) ==> 
            ((a)[j] % 2 != 0) || ((a)[j] % 6 == 0) || ((a)[j] % 10 == 0));
        loop invariant result == true <==> (\forall integer j; 0 <= j < (i) ==> 
            ((a)[j] % 2 != 0) || ((a)[j] % 6 == 0) || ((a)[j] % 10 == 0));
        loop invariant ((n) > 0 && (n) <= 100 &&
        \forall integer i; 0 <= i < (n) ==> (a)[i] > 0 && (a)[i] <= 1000);
        loop assigns i, result;
        loop variant n - i;
    */
    while (i < n) {
        int value = a[i];
        bool is_odd = (value % 2 != 0);
        bool is_multiple_of_6 = (value % 6 == 0);
        bool is_multiple_of_10 = (value % 10 == 0);
        
        //@ assert value > 0 && value <= 1000;
        
        if (!(is_odd || is_multiple_of_6 || is_multiple_of_10)) {
            result = false;
            break;
        }
        i++;
    }
    
    return result;
}
