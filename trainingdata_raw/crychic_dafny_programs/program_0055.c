// Generated C + ACSL

/*@ logic integer Sum(int* xs, integer xs_len) =
      (xs_len == 0) ? 0 : Sum(xs, xs_len - 1) + xs[xs_len - 1];
*/

/*@
    requires xs_len >= 0;
    requires \valid_read(xs + (0 .. xs_len - 1));
    decreases xs_len;
    ensures \result == Sum(xs, xs_len);
*/
int Sum(int* xs, int xs_len)
{
  /*@ assert xs_len >= 0; */
  if (xs_len == 0) {
    /*@ assert Sum(xs, 0) == 0; */
    return 0;
  } else {
    /*@ assert xs_len > 0; */
    /*@ assert xs_len - 1 >= 0; */
    /*@ assert xs_len - 1 < xs_len; */
    int prev_sum = Sum(xs, (xs_len - 1));
    /*@ assert prev_sum == Sum(xs, xs_len - 1); */
    int result = prev_sum + xs[(xs_len - 1)];
    /*@ assert result == Sum(xs, xs_len - 1) + xs[xs_len - 1]; */
    /*@ assert result == Sum(xs, xs_len); */
    return result;
  }
}

/*@
    requires xs_len >= 0;
    requires \valid_read(xs + (0 .. xs_len - 1));
    ensures \result == Sum(xs, xs_len);
*/
int SumArray(int* xs, int xs_len)
{
  int s = 0;
  /*@ assert s == 0; */
  /*@ assert Sum(xs, 0) == 0; */
  int i = 0;
/*@
  loop invariant 0 <= i <= xs_len;
  loop invariant s == Sum(xs, i);
  loop assigns i, s;
  loop variant xs_len - i;
*/
  while ((i < xs_len))
    {
      /*@ assert i < xs_len; */
      /*@ assert s == Sum(xs, i); */
      s = (s + xs[i]);
      /*@ assert s == Sum(xs, i) + xs[i]; */
      /*@ assert s == Sum(xs, i + 1); */
      i = (i + 1);
      /*@ assert s == Sum(xs, i); */
    }
  /*@ assert i == xs_len; */
  /*@ assert s == Sum(xs, xs_len); */
  return s;
}