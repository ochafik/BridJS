#include "dynload_v8.h"
#include "dyncall_v8_utils.h"

#include "dynload.h"

using namespace v8;
using namespace bridjs;

Handle<Value> dynload::loadLibrary(const Arguments& args) {
  HandleScope scope;
  GET_ASCII_STRING_ARG(libpath, args, 0);
  DLLib *lib = dlLoadLibrary(libpath);
  return scope.Close(ptr2string(lib));
}

Handle<Value> dynload::freeLibrary(const Arguments& args) {
  HandleScope scope;
  GET_POINTER_ARG(DLLib, lib, args, 0);
  dlFreeLibrary(lib);
  return scope.Close(Undefined());
}

Handle<Value> dynload::findSymbol(const Arguments& args) {
  HandleScope scope;
  GET_POINTER_ARG(DLLib, lib, args, 0);
  GET_ASCII_STRING_ARG(name, args, 1);
  void* symbol = dlFindSymbol(lib, name);
  return scope.Close(ptr2string(symbol));
}

Handle<Value> dynload::symsInit(const Arguments& args) {
  HandleScope scope;
  GET_ASCII_STRING_ARG(libPath, args, 0);
  DLSyms *pSyms = dlSymsInit(libPath);
  return scope.Close(ptr2string(pSyms));
}

Handle<Value> dynload::symsCleanup(const Arguments& args) {
  HandleScope scope;
  GET_POINTER_ARG(DLSyms, pSyms, args, 0);
  dlSymsCleanup(pSyms);
  return scope.Close(Undefined());
}

Handle<Value> dynload::symsCount(const Arguments& args) {
  HandleScope scope;
  GET_POINTER_ARG(DLSyms, pSyms, args, 0);
  int count = dlSymsCount(pSyms);
  return scope.Close(Number::New(count));
}

Handle<Value> dynload::symsName(const Arguments& args) {
  HandleScope scope;
  GET_POINTER_ARG(DLSyms, pSyms, args, 0);
  GET_NUMBER_ARG(index, args, 1);
  const char* name = dlSymsName(pSyms, (int)index);
  return scope.Close(name ? String::New(name) : String::Empty());
}

Handle<Value> dynload::symsNameFromValue(const Arguments& args) {
  HandleScope scope;
  GET_POINTER_ARG(DLSyms, pSyms, args, 0);
  GET_POINTER_ARG(void, value, args, 1);
  const char* name = dlSymsNameFromValue(pSyms, value);
  return scope.Close(String::New(name));
}
