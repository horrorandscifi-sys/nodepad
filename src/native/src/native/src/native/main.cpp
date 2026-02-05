#include <napi.h>
#include "processor.hpp"

Napi::Value StartProcessing(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::Array input = info[0].As<Napi::Array>();
    Napi::Function callback = info[1].As<Napi::Function>();

    std::vector<double> data;
    for (uint32_t i = 0; i < input.Length(); i++) {
        data.push_back(input.Get(i).As<Napi::Number>().DoubleValue());
    }

    DataProcessor* worker = new DataProcessor(callback, data);
    worker->Queue();
    return env.Undefined();
}

Napi::Object Init(Napi::Env env, Napi::Object exports) {
    exports.Set("process", Napi::Function::New(env, StartProcessing));
    return exports;
}

NODE_API_MODULE(high_load_engine, Init)
