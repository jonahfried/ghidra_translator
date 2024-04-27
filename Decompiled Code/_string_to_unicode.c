
wchar_t * _string_to_unicode(char *param_1)

{
  size_t sVar1;
  wchar_t *local_10;
  
  if (param_1 == (char *)0x0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,
             "Error: Input string is NULL in string_to_unicode.\n");
    local_10 = (wchar_t *)0x0;
  }
  else {
    sVar1 = _mbstowcs((wchar_t *)0x0,param_1,0);
    sVar1 = sVar1 + 1;
    if (sVar1 == 0xffffffffffffffff) {
      _fprintf(*(FILE **)PTR____stderrp_10000a038,"Error: Conversion failed in string_to_unicode.\n"
              );
      local_10 = (wchar_t *)0x0;
    }
    else {
      local_10 = (wchar_t *)_malloc(sVar1 * 4);
      if (local_10 == (wchar_t *)0x0) {
        _fprintf(*(FILE **)PTR____stderrp_10000a038,
                 "Error: Memory allocation failed in string_to_unicode.\n");
        local_10 = (wchar_t *)0x0;
      }
      else {
        _mbstowcs(local_10,param_1,sVar1);
      }
    }
  }
  return local_10;
}

