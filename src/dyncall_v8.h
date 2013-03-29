#ifndef _DYNCALL_V8_H
#define _DYNCALL_V8_H

#include <v8.h>

namespace dyncall {

v8::Handle<v8::Value> newCallVM(const v8::Arguments& args);

} // namespace dyncall

#endif  // _DYNCALL_V8_H
