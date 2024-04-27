
void _string_trim(long param_1)

{
  if (param_1 == 0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,"Error: Null String object in string_trim.\n");
  }
  else {
    _string_trim_left(param_1);
    _string_trim_right(param_1);
  }
  return;
}

