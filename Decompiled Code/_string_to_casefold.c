
void _string_to_casefold(long *param_1)

{
  int iVar1;
  ulong local_18;
  
  if ((param_1 == (long *)0x0) || (*param_1 == 0)) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,
             "Error: Invalid string input in string_to_casefold.\n");
  }
  else {
    for (local_18 = 0; local_18 < (ulong)param_1[1]; local_18 = local_18 + 1) {
      iVar1 = _tolower((int)*(char *)(*param_1 + local_18));
      *(char *)(*param_1 + local_18) = (char)iVar1;
    }
  }
  return;
}

