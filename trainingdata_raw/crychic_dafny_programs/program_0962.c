// Generated C + ACSL

// skipped function get_totals due to unsupported type

/*@ logic integer sum_logic(int* s, integer len); */

/*@
  requires s_len >= 0;
  requires \valid_read(s + (0 .. s_len - 1));
  decreases s_len;
  assigns \nothing;
*/
int sum(int* s, int s_len)
{
  return ((s_len == 0)) ? (0.0) : ((s[0] + sum(s + 1, s_len - 1)));
}