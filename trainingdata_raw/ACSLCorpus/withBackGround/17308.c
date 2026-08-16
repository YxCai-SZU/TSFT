/*@
    predicate is_max(integer result, int *arr, integer len) =
        \forall integer i; 0 <= i < len ==> result >= arr[i] &&
        \exists integer i; 0 <= i < len && result == arr[i];
 */

/*@
    logic integer count_divisible(integer a, integer b, integer x) =
        b / x - a / x + (a % x == 0 ? 1 : 0);
 */

/*@
    lemma division_monotonic:
        \forall integer a, b, x;
        0 <= a <= b <= 1000000000000000000 &&
        1 <= x <= 1000000000000000000 ==>
        a / x <= b / x;
 */

/*@
    requires len > 0;
    ensures is_max(\result, arr, len);
 */
int find_max(int *arr, int len) {
    int max;
    int i;
    
    max = arr[0];
    i = 1;
    
    /*@
        loop invariant 1 <= i <= len;
        loop invariant \forall integer j; 0 <= j < i ==> max >= arr[j];
        loop invariant \exists integer j; 0 <= j < i && max == arr[j];
        loop assigns max, i;
        loop variant len - i;
     */
    while (i < len) {
        //@ assert i < len;
        
        if (arr[i] > max) {
            max = arr[i];
        }
        
        i = i + 1;
    }
    
    //@ assert is_max(max, arr, len);
    return max;
}

/*@
    requires 0 <= a <= b <= 1000000000000000000;
    requires 1 <= x <= 1000000000000000000;
    ensures \result <= b / x - a / x + 1;
    ensures \result >= b / x - a / x;
    ensures \result == count_divisible(a, b, x);
 */
unsigned long long func(unsigned long long a, unsigned long long b, unsigned long long x) {
    unsigned long long ans;
    
    //@ assert a / x <= b / x;
    
    ans = b / x - a / x;
    if (a % x == 0) {
        ans = ans + 1;
    }
    
    //@ assert ans == count_divisible(a, b, x);
    //@ assert ans <= b / x - a / x + 1;
    //@ assert ans >= b / x - a / x;
    return ans;
}
