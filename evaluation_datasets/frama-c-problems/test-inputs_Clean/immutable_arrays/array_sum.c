/*@
    logic integer sumArr(int *a, integer n) = 
        (n <= 0) ? 0 : sumArr(a, n-1) + a[n-1];
*/

int sumArray(int *a, int n) {
  int p = 0, sum = 0;

  while (p < n) {
      sum = sum + a[p];
      p++;
  }
  return sum;
}

void test() {

  int a1[] = {1, 2, 3};
  int s1 = sumArray(a1, 3);

  //@ assert s1 == 6;

  int a2[] = {10};
  int s2 = sumArray(a2, 1);
  //@ assert s2 == 10;

  int a3[] = {-5, 5};
  int s3 = sumArray(a3, 2);
  //@ assert s3 == 0;
}
