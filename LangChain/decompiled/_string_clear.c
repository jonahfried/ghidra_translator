
void _string_clear(long *param_1)

{
  if ((param_1 != (long *)0x0) && (param_1[1] = 0, *param_1 != 0)) {
    *(undefined *)*param_1 = 0;
  }
  _fprintf(*(FILE **)PTR____stderrp_10000a038,
           "Info : String object is null no need to clear in string_clear.\n");
  return;
}

