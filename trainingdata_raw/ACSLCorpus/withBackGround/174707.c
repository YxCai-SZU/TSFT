#include <stdbool.h>

/*@
    predicate sorted(int* arr, integer len) =
        \forall integer i, j; 0 <= i <= j < len ==> arr[i] <= arr[j];

    predicate exists_at(int* arr, integer len, int number) =
        \exists integer i; 0 <= i < len && arr[i] == number;

    predicate not_exists_at(int* arr, integer len, int number) =
        \forall integer i; 0 <= i < len ==> arr[i] != number;

    lemma sorted_preserved:
        \forall int* arr, integer len, integer start, integer end, int number;
        sorted(arr, len) && 0 <= start <= end <= len &&
        (\forall integer i; 0 <= i < start ==> arr[i] < number) &&
        (\forall integer i; end <= i < len ==> arr[i] > number) ==>
        sorted(arr, len);
*/

/*@
    requires \valid_read(arr + (0 .. len-1));
    requires sorted(arr, len);
    requires 0 <= len < 0x80000000;
    ensures \result == true ==> exists_at(arr, len, number);
    ensures \result == false ==> not_exists_at(arr, len, number);
    assigns \nothing;
*/
bool check_present(int* arr, int len, int number)
{
    int start = 0;
    int end = len;

    /*@
        loop invariant 0 <= start <= end <= len;
        loop invariant sorted(arr, len);
        loop invariant \forall integer i; 0 <= i < start ==> arr[i] < number;
        loop invariant \forall integer i; end <= i < len ==> arr[i] > number;
        loop assigns start, end;
        loop variant end - start;
    */
    while (start < end)
    {
        int mid = start + (end - start) / 2;
        
        //@ assert 0 <= mid < len;
        
        if (arr[mid] == number)
        {
            //@ assert exists_at(arr, len, number);
            return true;
        }
        else if (arr[mid] > number)
        {
            end = mid;
            //@ assert \forall integer i; end <= i < len ==> arr[i] > number;
        }
        else
        {
            start = mid + 1;
            //@ assert \forall integer i; 0 <= i < start ==> arr[i] < number;
        }
    }
    
    //@ assert not_exists_at(arr, len, number);
    return false;
}

/*@ assigns \nothing; */
int main()
{
    return 0;
}
