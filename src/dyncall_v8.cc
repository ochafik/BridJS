#include "dyncall_v8.h"
#include "dyncall_v8_utils.h"

#include "dyncall.h"

using namespace v8;
using namespace bridjs;

Handle<Value> dyncall::newCallVM(const v8::Arguments& args) {
  HandleScope scope;
  GET_NUMBER_ARG(size, args, 0);
  DCCallVM *vm = dcNewCallVM((int)size);
  return scope.Close(ptr2string(vm));
}
