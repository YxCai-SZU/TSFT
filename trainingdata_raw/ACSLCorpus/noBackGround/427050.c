#include <stdbool.h>

/*@
  requires 1 <= n <= 100000;
  requires 1 <= m <= 100000;
  requires \valid(arr + (0..n-1));
  requires \valid(brr + (0..m-1));
  requires (\forall integer i; 0 <= i < (n) ==> 0 <= (arr)[i] <= 1000000000);
  requires (\forall integer j; 0 <= j < (m) ==> 0 <= (brr)[j] <= 1000000000);
  ensures 0 <= \result <= m;
  assigns \nothing;
*/
int func(int n, int m, int *arr, int *brr) {
    int cnt = 0;
    unsigned int j = 0;
    
    //@ assert 1 <= n <= 100000;
    //@ assert 1 <= m <= 100000;
    //@ assert (\forall integer i; 0 <= i < (n) ==> 0 <= (arr)[i] <= 1000000000);
    //@ assert (\forall integer j; 0 <= j < (m) ==> 0 <= (brr)[j] <= 1000000000);
    
    /*@ loop invariant 0 <= j <= m;
        loop invariant 0 <= cnt <= j;
        loop invariant (\forall integer i; 0 <= i < (n) ==> 0 <= (arr)[i] <= 1000000000);
        loop invariant (\forall integer j; 0 <= j < (m) ==> 0 <= (brr)[j] <= 1000000000);
        loop invariant 1 <= n <= 100000;
        loop invariant 1 <= m <= 100000;
        loop assigns j, cnt;
        loop variant m - j;
    */
    while (j < (unsigned int)m) {
        int b = brr[j];
        bool found = false;
        unsigned int i = 0;
        
        /*@ loop invariant 0 <= i <= n;
            loop invariant found == false || found == true;
            loop invariant (\forall integer i; 0 <= i < (n) ==> 0 <= (arr)[i] <= 1000000000);
            loop invariant (\forall integer j; 0 <= j < (m) ==> 0 <= (brr)[j] <= 1000000000);
            loop invariant 1 <= n <= 100000;
            loop invariant 1 <= m <= 100000;
            loop invariant found == true ==> \exists integer k; 0 <= k < i && arr[k] == b;
            loop invariant found == false ==> \forall integer k; 0 <= k < i ==> arr[k] != b;
            loop assigns i, found;
            loop variant n - i;
        */
        while (i < (unsigned int)n) {
            if (arr[i] == b) {
                found = true;
                break;
            }
            i++;
        }
        
        if (found) {
            cnt++;
        }
        j++;
    }
    
    //@ assert 0 <= cnt <= m;
    return cnt;
}
