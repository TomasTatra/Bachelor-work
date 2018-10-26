#ifndef MICROPY_INCLUDED_PY_OBJENUM_H
#define MICROPY_INCLUDED_PY_OBJENUM_H

#include "py/obj.h"

#define MP_DEFINE_CONST_ENUM(enum_name, table_name) \
MP_DEFINE_CONST_DICT(enum_name ## _locals_dict, table_name); \
const mp_obj_type_t enum_name = { \
    { &mp_type_type }, \
    .locals_dict = (mp_obj_dict_t*)&(enum_name ## _locals_dict),\
}

#endif // MICROPY_INCLUDED_PY_OBJENUM_H
