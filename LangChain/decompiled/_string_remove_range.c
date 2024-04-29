
void _string_remove_range(long *param_1,ulong param_2,ulong param_3)

{
  if ((param_1 == (long *)0x0) || (*param_1 == 0)) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,
             "Error: Null String object in string_remove_range.\n");
  }
  else if ((param_2 < param_3) && (param_3 <= (ulong)param_1[1])) {
    ___memmove_chk(*param_1 + param_2,*param_1 + param_3,(param_1[1] - param_3) + 1,
                   0xffffffffffffffff);
    param_1[1] = param_1[1] - (param_3 - param_2);
  }
  else {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,"Error: Invalid range in string_remove_range.\n");
  }
  return;
}

