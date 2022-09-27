#ifndef _FFI_UTILS_H
#define _FFI_UTILS_H

#define CHECK(x, ...)       \
    if (x == NULL) {        \
        return __VA_ARGS__; \
    }
#define CASTOBJ(cpp_type, c_pointer)          static_cast<cpp_type*>(c_pointer->obj)
#define GETOBJ(var_name, cpp_type, c_pointer) cpp_type* var_name = CASTOBJ(cpp_type, c_pointer)

#define TRY(expression, exception) \
    try {                          \
        expression                 \
    } catch (const exception&) { return; }

#endif