int arraysearch(int* a, int x, int n) {

  for (int p = 0; p < n; p++) {

    if (x == a[p])
       return 1;

  }
  return 0;
}

void test_present() {
  int arr[3];
  arr[0] = 10; arr[1] = 20; arr[2] = 30;

  //@ assert arr[1] == 20;

  int res = arraysearch(arr, 20, 3);

  //@ assert res == 1;
}

void test_not_present() {
  int arr[3];
  arr[0] = 10; arr[1] = 20; arr[2] = 30;

  //@ assert arr[0] != 99 && arr[1] != 99 && arr[2] != 99;
  //@ assert \forall integer k; 0 <= k < 3 ==> arr[k] != 99;

  int res = arraysearch(arr, 99, 3);

  //@ assert res == 0;
}
