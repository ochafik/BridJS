#include <v8.h>
#include <node.h>

#include "dyncall_v8.h"
#include "dyncallback_v8.h"
#include "dynload_v8.h"

using namespace v8;

void init(Handle<Object> target) {
  #define EXPORT_FUNCTION(ns, name) \
    NODE_SET_METHOD(target, #name, ns::name);
  
  EXPORT_FUNCTION(dynload, loadLibrary);
  EXPORT_FUNCTION(dynload, freeLibrary);
  EXPORT_FUNCTION(dynload, findSymbol);
  EXPORT_FUNCTION(dynload, symsInit);
  EXPORT_FUNCTION(dynload, symsCleanup);
  EXPORT_FUNCTION(dynload, symsCount);
  EXPORT_FUNCTION(dynload, symsName);
  EXPORT_FUNCTION(dynload, symsNameFromValue);
  
  EXPORT_FUNCTION(dyncall, newCallVM);
}

NODE_MODULE(bridjs, init);
