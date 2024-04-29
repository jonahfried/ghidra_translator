
void _string_pop_back(long *param_1)

{
  if (param_1 == (long *)0x0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,
             "Error: The String object is NULL in string_pop_back.\n");
  }
  else if (param_1[1] == 0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,
             "Warning: Attempt to pop back from an empty string in string_pop_back.\n");
  }
  else {
    *(undefined *)(*param_1 + param_1[1] + -1) = 0;
    param_1[1] = param_1[1] + -1;
  }
  return;
}

