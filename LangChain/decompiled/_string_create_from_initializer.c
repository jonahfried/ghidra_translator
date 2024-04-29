
/* WARNING: Restarted to delay deadcode elimination for space: stack */

void * _string_create_from_initializer
                 (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                 ulong param_9,undefined8 param_10,undefined8 param_11,undefined8 param_12,
                 undefined8 param_13,undefined8 param_14)

{
  char in_AL;
  undefined8 uVar1;
  undefined8 *local_120;
  undefined local_108 [8];
  undefined8 local_100;
  undefined8 local_f8;
  undefined8 local_f0;
  undefined8 local_e8;
  undefined8 local_e0;
  undefined4 local_d8;
  undefined4 local_c8;
  undefined4 local_b8;
  undefined4 local_a8;
  undefined4 local_98;
  undefined4 local_88;
  undefined4 local_78;
  undefined4 local_68;
  ulong local_58;
  undefined8 local_50;
  ulong local_48;
  void *local_40;
  ulong local_38;
  void *local_30;
  uint local_28;
  undefined4 local_24;
  undefined8 *local_20;
  undefined *local_18;
  long local_10;
  
  if (in_AL != '\0') {
    local_d8 = param_1;
    local_c8 = param_2;
    local_b8 = param_3;
    local_a8 = param_4;
    local_98 = param_5;
    local_88 = param_6;
    local_78 = param_7;
    local_68 = param_8;
  }
  local_10 = *(long *)PTR____stack_chk_guard_10000a030;
  local_100 = param_10;
  local_f8 = param_11;
  local_f0 = param_12;
  local_e8 = param_13;
  local_e0 = param_14;
  local_38 = param_9;
  if (param_9 == 0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,
             "Error: count is zero in string_create_from_initializer.\n");
    local_30 = (void *)0x0;
  }
  else {
    local_18 = local_108;
    local_20 = (undefined8 *)&stack0x00000008;
    local_24 = 0x30;
    local_28 = 8;
    local_40 = _malloc((param_9 + 1) * 8);
    if (local_40 == (void *)0x0) {
      _fprintf(*(FILE **)PTR____stderrp_10000a038,
               "Error: Memory allocation failed for strings array in string_create_from_initializer.\n"
              );
      local_30 = (void *)0x0;
    }
    else {
      for (local_48 = 0; local_48 < local_38; local_48 = local_48 + 1) {
        if (local_28 < 0x29) {
          local_120 = (undefined8 *)(local_18 + (int)local_28);
          local_28 = local_28 + 8;
        }
        else {
          local_120 = local_20;
          local_20 = local_20 + 1;
        }
        local_50 = *local_120;
        uVar1 = _string_create(local_50);
        *(undefined8 *)((long)local_40 + local_48 * 8) = uVar1;
        if (*(long *)((long)local_40 + local_48 * 8) == 0) {
          _fprintf(*(FILE **)PTR____stderrp_10000a038,
                   "Error: string_create failed for string: %s in string_create_from_initializer.\n"
                   ,local_50);
          for (local_58 = 0; local_58 < local_48; local_58 = local_58 + 1) {
            _string_deallocate(*(undefined8 *)((long)local_40 + local_58 * 8));
          }
          _free(local_40);
          local_30 = (void *)0x0;
          goto LAB_1000071d2;
        }
      }
      *(undefined8 *)((long)local_40 + local_38 * 8) = 0;
      local_30 = local_40;
    }
  }
LAB_1000071d2:
  if (*(long *)PTR____stack_chk_guard_10000a030 == local_10) {
    return local_30;
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail();
}

