int arraySearch(int *a, int x, int n) {
    int p = 0;

    while (p < n) {
        if (a[p] == x) {
            return 1;
        }
        p++;
    }
    return 0;
}

void test() {
    int arr[] = {10, 20, 30, 40, 50};

    int found = arraySearch(arr, 30, 5);
    //@ assert found == 1;

    int not_found = arraySearch(arr, 99, 5);
    //@ assert not_found == 0;
}
