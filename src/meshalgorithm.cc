
#include <node.h>
#include "../include/meshalgorithm.h"


namespace Crystal {
namespace geometry {

using namespace v8;

    // Methods are defined here
    void PrintArray(const FunctionCallbackInfo<Value>& args) {
        Isolate* isolate = args.GetIsolate();

        Local<Float32Array> f32a = Local<Float32Array>::Cast(args[0]);
        printf("Float32Array length = %d \n", f32a->Length());
        printf("Float32Array byte length = %d \n", f32a->ByteLength());
        printf("Float32Array byte offset = %d \n", f32a->ByteOffset());

    }

}
}