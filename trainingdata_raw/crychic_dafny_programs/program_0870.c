// Generated C + ACSL

static int isInitialized = 0;

/*@
    requires isInitialized == 0;
    assigns isInitialized;
    ensures isInitialized == 1;
*/
void Initialize(void)
{
  isInitialized = 1;
  /*@ assert isInitialized >= 0 && isInitialized <= 2147483647; */
}

/*@
    requires arr != \null;
    requires arr_len > 0;
    requires \valid_read(arr + (0 .. arr_len-1));
    assigns \nothing;
    ensures \result >= 0;
*/
int ComputeSomething(int* arr, int arr_len)
{
  int i = 0;
  int sum = 0;
  /*@ assert sum >= 0 && sum <= 2147483647; */
/*@
  loop invariant 0 <= i <= arr_len;
  loop invariant sum >= \at(sum, LoopEntry);
  loop invariant sum >= 0;
  loop invariant \forall integer k; 0 <= k < i ==> (arr[k] > 0 ==> sum >= arr[k]);
  loop assigns i, sum;
  loop variant arr_len - i;
*/
  while ((i < arr_len))
    {
      sum = (sum + (((arr[i] > 0)) ? (arr[i]) : (0)));
      i = (i + 1);
    }
  return sum;
}