#include <stdbool.h>
#include <stdint.h>

/*@ requires (1 <= (n) <= 100000 && 1 <= (m) <= 100000);
    requires \valid(arr + (0 .. n-1));
    requires \valid(arr2 + (0 .. m-1));
    requires (\forall integer i; 0 <= i < (n) ==> 1 <= (arr)[i] <= 1000000000);
    requires (\forall integer i; 0 <= i < (m) ==> 1 <= (arr2)[i] <= 1000000000);
    ensures 0 <= \result <= m;
    assigns \nothing;
*/
int func(int n, int m, int *arr, int *arr2) {
    int count = 0;
    int i = 0;
    
    /*@ loop invariant 0 <= i <= m;
        loop invariant 0 <= count <= i;
        loop invariant (\forall integer i; 0 <= i < (n) ==> 1 <= (arr)[i] <= 1000000000);
        loop invariant (\forall integer i; 0 <= i < (m) ==> 1 <= (arr2)[i] <= 1000000000);
        loop invariant (1 <= (n) <= 100000 && 1 <= (m) <= 100000);
        loop assigns i, count;
        loop variant m - i;
    */
    while (i < m) {
        int j = 0;
        
        /*@ loop invariant 0 <= j <= n;
            loop invariant 0 <= count <= i;
            loop invariant (\forall integer i; 0 <= i < (n) ==> 1 <= (arr)[i] <= 1000000000);
            loop invariant (\forall integer i; 0 <= i < (m) ==> 1 <= (arr2)[i] <= 1000000000);
            loop invariant (1 <= (n) <= 100000 && 1 <= (m) <= 100000);
            loop assigns j, count;
            loop variant n - j;
        */
        while (j < n) {
            //@ assert 0 <= j < n ==> 1 <= arr[j] <= 1000000000;
            //@ assert 0 <= i < m ==> 1 <= arr2[i] <= 1000000000;
            
            if (arr[j] == arr2[i]) {
                count = count + 1;
                break;
            }
            j += 1;
        }
        i += 1;
    }
    
    //@ assert 0 <= count <= m;
    return count;
}
