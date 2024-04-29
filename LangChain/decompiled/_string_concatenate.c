
void _string_concatenate(long param_1,undefined8 *param_2)

{
  if (param_1 == 0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,
             "Error: Null String object \'str1\' in string_concatenate.\n");
  }
  else if (param_2 == (undefined8 *)0x0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,
             "Error: Null String object \'str2\' in string_concatenate.\n");
  }
  else {
    _string_append(param_1,*param_2);
  }
  return;
}

