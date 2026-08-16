/*@
  requires 1 <= a <= 100;
  requires 1 <= b <= 100;
  requires a * b <= 9223372036854775807;
  requires a * b >= -9223372036854775808;
  ensures \result == a * b;
*/
long func(long a, long b)
{
    long ans;
    /*@ assert a * b == a * b; */
    ans = a * b;
    return ans;
}
