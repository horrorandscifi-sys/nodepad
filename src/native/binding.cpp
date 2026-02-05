#include <napi.h>
#include "async_worker.hpp" // Тебе нужно будет его создать

Napi::Value StartComputation(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    int input = info[0].As<Napi::Number>().Int32Value();
    Napi::Function callback = info[1].As<Napi::Function>();

    // Запускаем асинхронную задачу, чтобы не блокировать сервер
    auto worker = new HeavyTaskWorker(callback, input);
    worker->Queue();
    
    return env.Undefined();
}

Napi::Object Init(Napi::Env env, Napi::Object exports) {
    exports.Set("startComputation", Napi::Function::New(env, StartComputation));
    return exports;
}

NODE_API_MODULE(addon, Init)
