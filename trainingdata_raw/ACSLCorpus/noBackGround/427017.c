#include <stdbool.h>

/*@
    requires \valid_read(arr + (0 .. len-1));
    requires ((len) % 2 == 1);
    requires (\forall integer i, j; 0 <= i < j < (len) ==> (arr)[i] <= (arr)[j]);
    ensures \result == true;
*/
bool is_sorted_odd_helper(const int *arr, unsigned int len) {
    //@ assert (\forall integer i, j; 0 <= i < j < (len) ==> (arr)[i] <= (arr)[j]);
    return true;
}

/*@
    requires \valid_read(arr + (0 .. len-1));
    requires ((len) % 2 == 0);
    requires (\forall integer i, j; 0 <= i < j < (len) ==> (arr)[i] <= (arr)[j]);
    ensures \result == true;
*/
bool is_sorted_even_helper(const int *arr, unsigned int len) {
    //@ assert (\forall integer i, j; 0 <= i < j < (len) ==> (arr)[i] <= (arr)[j]);
    return true;
}

int main() {
    int v[4];
    unsigned int len;
    
    v[0] = 1;
    v[1] = 2;
    v[2] = 3;
    v[3] = 4;
    len = 4;
    
    //@ assert ((len) % 2 == 0);
    return 0;
}
