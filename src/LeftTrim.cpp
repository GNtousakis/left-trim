#include <nan.h>
#include <iostream>

using v8::FunctionCallbackInfo;
using v8::Exception;
using v8::Isolate;
using v8::Object;
using v8::String;
using v8::Value;
using v8::Handle;

void LeftTrim(const FunctionCallbackInfo<Value>& args){
  Isolate* isolate = args.GetIsolate();
  
  // Check the number of arguments passed.
  if (args.Length() == 0 || !args[0]->IsString()) {
    // Throw an Error that is passed back to JavaScript
    isolate->ThrowException(Exception::TypeError(
        String::NewFromUtf8(isolate, "You need to pass a string")));
    return;
  }

  if (args[0]->IsString()) {
    String::Utf8Value tmp(args[0]->ToString());
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
    args.GetReturnValue().Set(v8String);
  }

}

void Init(Handle<Object> exports) {
  NODE_SET_METHOD(exports, "LeftTrim", LeftTrim);
}

NODE_MODULE(LeftTrim, Init)
