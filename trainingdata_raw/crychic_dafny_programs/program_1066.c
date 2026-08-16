// Generated C + ACSL

/*@
    requires arr_len > 0;
    requires \valid_read(arr + (0 .. arr_len-1));
    assigns \nothing;
    ensures \result != 0 ==>
        (\exists integer i, j;
            0 <= i < arr_len && 0 <= j < arr_len && i != j &&
            arr[i] + arr[j] == 2020 &&
            \result == arr[i] * arr[j]);
*/
int FindTwoNumberProduct(int* arr, int arr_len)
{
  int product = 0;
  /*@ assert product >= 0 && product <= 2147483647; */
  int i = 0;
/*@
  loop invariant 0 <= i <= arr_len;
  loop invariant product == 0 ==>
    (\forall integer m, n; 0 <= m < i && 0 <= n < arr_len && m != n ==>
      arr[m] + arr[n] != 2020);
  loop invariant product != 0 ==>
    (\exists integer m, n; 0 <= m < arr_len && 0 <= n < arr_len && m != n &&
      arr[m] + arr[n] == 2020 && product == arr[m] * arr[n]);
  loop assigns i, product;
  loop variant arr_len - i;
*/
  while ((i < arr_len))
    {
      int j = 0;
/*@
  loop invariant 0 <= j <= arr_len;
  loop invariant \at(product, LoopEntry) == 0 ==>
    (\forall integer m, n; 0 <= m < i && 0 <= n < arr_len && m != n ==>
      arr[m] + arr[n] != 2020);
  loop invariant \at(product, LoopEntry) == 0 ==>
    (\forall integer n; 0 <= n < j ==>
      (arr[i] + arr[n] != 2020 || i == n));
  loop invariant \at(product, LoopEntry) != 0 ==> product == \at(product, LoopEntry);
  loop invariant product != 0 ==>
    (\exists integer m, n; 0 <= m < arr_len && 0 <= n < arr_len && m != n &&
      arr[m] + arr[n] == 2020 && product == arr[m] * arr[n]);
  loop assigns j, product;
  loop variant arr_len - j;
*/
      while ((j < arr_len))
        {
          if (((i != j) && ((arr[i] + arr[j]) == 2020)))
          {
            product = (arr[i] * arr[j]);
            return product;
          }
          j = (j + 1);
        }
      i = (i + 1);
    }
  return product;
}

/*@
    requires arr != \null;
    requires arr_len > 0;
    requires \valid_read(arr + (0 .. arr_len-1));
    assigns \nothing;
    ensures \result != 0 ==>
        (\exists integer i, j, k;
            0 <= i < arr_len && 0 <= j < arr_len && 0 <= k < arr_len &&
            i != j && j != k && i != k &&
            arr[i] + arr[j] + arr[k] == 2020 &&
            \result == arr[i] * arr[j] * arr[k]);
*/
int FindThreeNumberProduct(int* arr, int arr_len)
{
  int product = 0;
  /*@ assert product >= 0 && product <= 2147483647; */
  int i = 0;
/*@
  loop invariant 0 <= i <= arr_len;
  loop invariant product == 0 ==>
    (\forall integer m, n, p;
      0 <= m < i && 0 <= n < arr_len && 0 <= p < arr_len &&
      m != n && n != p && m != p ==>
      arr[m] + arr[n] + arr[p] != 2020);
  loop invariant product != 0 ==>
    (\exists integer m, n, p;
      0 <= m < arr_len && 0 <= n < arr_len && 0 <= p < arr_len &&
      m != n && n != p && m != p &&
      arr[m] + arr[n] + arr[p] == 2020 &&
      product == arr[m] * arr[n] * arr[p]);
  loop assigns i, product;
  loop variant arr_len - i;
*/
  while ((i < arr_len))
    {
      int j = 0;
/*@
  loop invariant 0 <= j <= arr_len;
  loop invariant \at(i, LoopEntry) == i;
  loop invariant product == 0 ==>
    (\forall integer m, n, p;
      0 <= m < i && 0 <= n < arr_len && 0 <= p < arr_len &&
      m != n && n != p && m != p ==>
      arr[m] + arr[n] + arr[p] != 2020);
  loop invariant product == 0 ==>
    (\forall integer n, p;
      0 <= n < j && 0 <= p < arr_len &&
      i != n && n != p && i != p ==>
      arr[i] + arr[n] + arr[p] != 2020);
  loop invariant product != 0 ==>
    (\exists integer m, n, p;
      0 <= m < arr_len && 0 <= n < arr_len && 0 <= p < arr_len &&
      m != n && n != p && m != p &&
      arr[m] + arr[n] + arr[p] == 2020 &&
      product == arr[m] * arr[n] * arr[p]);
  loop assigns j, product;
  loop variant arr_len - j;
*/
      while ((j < arr_len))
        {
          int k = 0;
/*@
  loop invariant 0 <= k <= arr_len;
  loop invariant \at(i, LoopEntry) == i;
  loop invariant \at(j, LoopEntry) == j;
  loop invariant product == 0 ==>
    (\forall integer m, n, p;
      0 <= m < i && 0 <= n < arr_len && 0 <= p < arr_len &&
      m != n && n != p && m != p ==>
      arr[m] + arr[n] + arr[p] != 2020);
  loop invariant product == 0 ==>
    (\forall integer n, p;
      0 <= n < j && 0 <= p < arr_len &&
      i != n && n != p && i != p ==>
      arr[i] + arr[n] + arr[p] != 2020);
  loop invariant product == 0 ==>
    (\forall integer p;
      0 <= p < k &&
      i != j && j != p && i != p ==>
      arr[i] + arr[j] + arr[p] != 2020);
  loop invariant product != 0 ==>
    (\exists integer m, n, p;
      0 <= m < arr_len && 0 <= n < arr_len && 0 <= p < arr_len &&
      m != n && n != p && m != p &&
      arr[m] + arr[n] + arr[p] == 2020 &&
      product == arr[m] * arr[n] * arr[p]);
  loop assigns k, product;
  loop variant arr_len - k;
*/
          while ((k < arr_len))
            {
              if (((((i != j) && (j != k)) && (i != k)) && (((arr[i] + arr[j]) + arr[k]) == 2020)))
              {
                product = ((arr[i] * arr[j]) * arr[k]);
                return product;
              }
              k = (k + 1);
            }
          j = (j + 1);
        }
      i = (i + 1);
    }
  return product;
}