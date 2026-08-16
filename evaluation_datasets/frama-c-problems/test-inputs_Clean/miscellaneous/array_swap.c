void array_swap(int* arr, int n, int n1, int n2) {
    int temp = arr[n1];
    arr[n1] = arr[n2];
    arr[n2] = temp;
}

void test() {
    int arr[] = {1, 2, 3, 4, 5};
    array_swap(arr, 5, 1, 2);
    //@ assert arr[1] == 3 && arr[2] == 2;
}
