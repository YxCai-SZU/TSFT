/*@
    predicate is_non_empty{L}(int *arr, integer len) = len > 0;
    predicate has_at_least_ten{L}(int *arr, integer len) = len >= 10;
*/

/*@
    requires \valid_read(arr + (0..len-1));
    requires is_non_empty(arr, len);
    ensures \result == (len >= 10 ? 1 : 0);
    assigns \nothing;
*/
int is_at_least_ten_elements(int *arr, int len) {
    //@ assert is_non_empty(arr, len);
    return (len >= 10) ? 1 : 0;
}

/*@
    requires \valid_read(lst + (0..len-1));
    requires is_non_empty(lst, len);
    ensures \result == (len >= 10 ? 1 : 0);
    assigns \nothing;
*/
int is_at_least_ten_elements_in_list(int *lst, int len) {
    //@ assert is_non_empty(lst, len);
    return (len >= 10) ? 1 : 0;
}

/*@
    logic integer triangle_number(integer n) = n * (n + 1) / 2;
    
    lemma triangle_lemma:
        \forall integer i; 1 <= i <= 100 ==>
            triangle_number(i-1) + i == triangle_number(i);
*/

/*@
    requires 1 <= a <= 100;
    ensures \result == triangle_number(a);
    assigns \nothing;
*/
int func(int a) {
    int sum = 0;
    int i = 1;
    
    /*@
        loop invariant 1 <= i <= a + 1;
        loop invariant sum == triangle_number(i-1);
        loop assigns sum, i;
        loop variant a - i + 1;
    */
    while (i <= a) {
        //@ assert sum + i == triangle_number(i);
        sum += i;
        i += 1;
    }
    return sum;
}
