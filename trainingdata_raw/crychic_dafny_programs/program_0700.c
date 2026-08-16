// Generated C + ACSL

#include <stddef.h>

typedef struct {
    int numValue;
} NumericFeature;

typedef struct {
    NumericFeature nf;
    int Numeric;
} Field;

typedef struct {
    Field age;
} DataPoint;

/*@
    requires data_len > 0;
    requires \valid(data + (0..data_len-1));
    assigns data[0..data_len-1];
    ensures \result == data;
*/
DataPoint* FillMissingValues(DataPoint* data, int data_len, int meanAge)
{
  DataPoint* processed = data;
  int i = 0;
/*@
  loop invariant 0 <= i <= data_len;
  loop invariant \valid(processed + (0..data_len-1));
  loop invariant \valid(data + (0..data_len-1));
  loop assigns i, processed[0..data_len-1];
  loop variant data_len - i;
*/
  while ((i < data_len))
    {
      DataPoint point = processed[i];
      if (point.age.Numeric && (point.age.nf.numValue < 0))
      {
        point.age.nf.numValue = meanAge;
        point.age.Numeric = 1;
      }
      processed[i] = point;
      i = (i + 1);
    }
  return processed;
}

typedef struct {
    double age;
} SplitCriteria;

/*@
    requires trainData_len == trainLabels_len;
    requires trainData_len > 0;
    assigns \nothing;
    ensures \result == 1;
*/
int Train(int trainData_len, int trainLabels_len)
{
  SplitCriteria splitCriteria;
  splitCriteria.age = 30.0;
  int success = 1;
  return success;
}

static SplitCriteria globalSplitCriteria = {30.0};

/*@
    requires \valid(&point);
    assigns \nothing;
    ensures \result == 0 || \result == 1;
*/
int Predict(DataPoint point)
{
  int survived;
  if (point.age.Numeric)
  {
    survived = (point.age.nf.numValue > globalSplitCriteria.age);
  }
  else
  {
    survived = 0;
  }
  return survived;
}