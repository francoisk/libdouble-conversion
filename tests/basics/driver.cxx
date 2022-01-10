#include <double-conversion/double-conversion.h>

using namespace double_conversion;

int
main ()
{
  // String to double.
  //
  {
    int n (0);
    StringToDoubleConverter c (
        StringToDoubleConverter::NO_FLAGS, 0, 0, nullptr, nullptr);

    if (c.StringToDouble ("0.123", 5, &n) != 0.123)
      return 1;
  }

  // Double to string.
  //
  {
    char b[32];
    StringBuilder sb (b, sizeof (b));
    DoubleToStringConverter c (
        StringToDoubleConverter::NO_FLAGS, nullptr, nullptr, 'e', -6, 21, 6, 0);

    if (!c.ToShortest (0.123, &sb))
      return 1;
    if (strcmp (sb.Finalize (), "0.123") != 0)
      return 1;
  }

  return 0;
}
