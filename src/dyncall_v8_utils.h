#include <v8.h>

// return ThrowException(String::New("..."))

#define GET_NUMBER_ARG(name, args, index) \
  Local<Value> name ## Value = args[index]; \
  if (!name ## Value->IsNumber()) { \
    return v8::ThrowException(v8::Exception::TypeError(String::New( \
      "Invalid value for number argument " #name " at index " #index))); \
  } \
  Local<Number> name ## Number = Local<Number>::Cast(name ## Value); \
  double name = (*name ## Number)->Value();
  
#define GET_STRING_ARG(name, args, index) \
  Local<Value> name = args[index]; \
  if (!name->IsString()) { \
    return v8::ThrowException(v8::Exception::TypeError(String::New( \
      "Invalid value for string argument " #name " at index " #index))); \
  }
  
#define GET_POINTER_ARG(type, name, args, index) \
  GET_STRING_ARG(name ## Pointer, args, index); \
  type *name = (type*)string2ptr(name ## Pointer);
  
#define GET_ASCII_STRING_ARG(name, args, index) \
  GET_STRING_ARG(name ## Value, args, index); \
  String::AsciiValue name ## AsciiValue(name ## Value); \
  const char *name = *name ## AsciiValue;
  
namespace bridjs {
  
void* string2ptr(v8::Local<v8::Value> value);

v8::Handle<v8::Value> ptr2string(void* ptr);

}
