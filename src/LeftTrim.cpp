#include <nan.h>
#include <iostream>

using v8::FunctionCallbackInfo;
using v8::Exception;
using v8::Isolate;
using v8::Object;
using v8::String;
using v8::Value;
using v8::Handle;

NAN_METHOD (LeftTrim) {
  Isolate* isolate = info.GetIsolate();
  
  // Check the number of arguments passed.
  if (info.Length() == 0 || !info[0]->IsString()) {
    // Throw an Error that is passed back to JavaScript
    isolate->ThrowException(Exception::TypeError(
        String::NewFromUtf8(isolate, "You need to pass a string")));
    return;
  }

  if (info[0]->IsString()) {
    String::Utf8Value tmp(info[0]->ToString());
    // Change string to c++ type
    std::string str = std::string(*tmp); 
    std::string str_trim;

    // Trim Left the string
    char * begin;
    int n = 0;
    if(str[n] == ' ') 
    { 
      begin = &str[n]; 
      while(str[++n] == ' '); 
      str_trim = str.substr(n); 
    } 

    // Revert to v8 string and return 
    v8::Local<v8::String> v8String = v8::String::NewFromUtf8(isolate, str_trim.c_str(), v8::String::kNormalString);
    info.GetReturnValue().Set(v8String);
  }

}

NAN_MODULE_INIT(Init)
{
  NAN_EXPORT(target, LeftTrim);
}

NODE_MODULE(LeftTrim, Init)
