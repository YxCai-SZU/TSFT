#include <stdbool.h>

/*@
    predicate sorted(int *arr, integer len) =
        \forall integer i, j; 0 <= i <= j < len ==> arr[i] <= arr[j];

    predicate no_duplicates(int *arr, integer len) =
        \forall integer i, j; 0 <= i < j < len ==> arr[i] != arr[j];
*/

/*@
    requires \valid_read(v + (0 .. len-1));
    requires sorted(v, len);
    ensures \result == true;
    assigns \nothing;
*/
bool is_sorted_before(int *v, int len)
{
    //@ assert sorted(v, len);
    return true;
}

/*@
    requires \valid_read(v + (0 .. len-1));
    requires no_duplicates(v, len);
    ensures \result == false;
    assigns \nothing;
*/
bool has_duplicates_before(int *v, int len)
{
    //@ assert no_duplicates(v, len);
    return false;
}

/*@
    assigns \nothing;
*/
int main() {
    int v[4];
    v[0] = 1;
    v[1] = 2;
    v[2] = 3;
    v[3] = 4;
    int len = 4;
    
    //@ assert sorted(&v[0], len);
    //@ assert no_duplicates(&v[0], len);
    
    bool sorted_result = is_sorted_before(&v[0], len);
    bool dup_result = has_duplicates_before(&v[0], len);
    
    return 0;
}
