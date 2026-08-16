// Generated C + ACSL

typedef struct {
    int* years;
    int years_len;
    int** features;
    int* observed;
} DataFrame;

/*@
    requires feature != \null;
    requires feature_len > 0;
    requires \valid_read(feature + (0 .. feature_len-1));
    requires lineColor != \null;
    requires lineColor_len >= 0;
    requires \valid_read(lineColor + (0 .. lineColor_len-1));
    requires df.years_len >= 0;
    requires df.years != \null;
    requires \valid_read(df.years + (0 .. df.years_len-1));
    requires df.observed != \null;
    requires \valid_read(df.observed + (0 .. df.years_len-1));
    assigns \nothing;
    ensures \result == 0;
*/
int* PlotFeatureVsObserved(DataFrame df, char* feature, int feature_len, char* lineColor, int lineColor_len)
{
  int* result = 0;
  int i = 0;
/*@
  loop invariant 0 <= i <= df.years_len;
  loop invariant result == 0;
  loop assigns i, result;
  loop variant df.years_len - i;
*/
  while ((i < df.years_len))
    {
      result = (result + 0);
      i = (i + 1);
    }
  int* plot = result;
  /*@ assert plot == 0; */
  return plot;
}