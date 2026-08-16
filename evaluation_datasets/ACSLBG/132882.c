/*@
    predicate sorted{L}(int *arr, integer len) =
        \forall integer i; 1 <= i < len ==> arr[i-1] <= arr[i];
*/


int is_sorted(int *arr, int len) {
    int i;
    int result;
    
    i = 1;
    
    
    while (i < len) {
        if (arr[i] < arr[i - 1]) {
            return 0;
        }
        
        i = i + 1;
    }
    
    return 1;
}

int main() {
    return 0;
}
