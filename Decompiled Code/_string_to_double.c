
double _string_to_double(char **param_1)

{
  ulong uVar1;
  double local_10;
  
  if (param_1 == (char **)0x0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,"Error: Null String object in string_to_double.\n");
    local_10 = 0.0;
  }
  else {
    uVar1 = _string_empty(param_1);
    if ((uVar1 & 1) == 0) {
      local_10 = _strtod(*param_1,(char **)0x0);
    }
    else {
      _fprintf(*(FILE **)PTR____stderrp_10000a038,"Error: Empty string in string_to_double.\n");
      local_10 = 0.0;
    }
  }
  return local_10;
}

