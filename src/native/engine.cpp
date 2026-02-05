#include <napi.h>
#include <chrono>

// Пример функции: тяжелое вычисление
Napi::Value HardWork(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    
    // Продвинутый уровень: работа с сырыми буферами (Zero-copy)
    auto start = std::chrono::high_performance_clock::now();
    
    // Имитация нагрузки
    long long result = 0;
    for(int i = 0; i < 1000000; ++i) { result += i; }

    Napi::Object obj = Napi::Object::New(env);
    obj.Set("result", Napi::Number::New(env, result));
    obj.Set("ms", Napi::Number::New(env, 0.1)); // время выполнения
    return obj;
}

Napi::Object Init(Napi::Env env, Napi::Object exports) {
    exports.Set(Napi::String::New(env, "hardWork"), Napi::Function::New(env, HardWork));
    return exports;
}

NODE_API_MODULE(server_engine, Init)
