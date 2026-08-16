#include <stdbool.h>

int main() {
    int v[3];
    v[0] = 1;
    v[1] = 3;
    v[2] = 2;
    
    //@ assert !(\forall integer i, j; 0 <= i < j < (3) ==> (&v[0])[i] <= (&v[0])[j] ||       \forall integer i, j; 0 <= i < j < (3) ==> (&v[0])[i] >= (&v[0])[j]);
    return 0;
}

/*@ requires \forall integer i, j; 0 <= i < j < len ==> s[i] <= s[j];
    ensures \result == true;
    assigns \nothing;
*/
bool check_range_sorted(int *s, int len) {
    //@ assert (\forall integer i, j; 0 <= i < j < (len) ==> (s)[i] <= (s)[j]);
    return true;
}

/*@ requires \forall integer i, j; 0 <= i < j < len ==> s[i] >= s[j];
    ensures \result == true;
    assigns \nothing;
*/
bool check_range_descending_sorted(int *s, int len) {
    //@ assert (\forall integer i, j; 0 <= i < j < (len) ==> (s)[i] >= (s)[j]);
    return true;
}
