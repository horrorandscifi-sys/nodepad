#include "processor.hpp"
#include <cmath>

DataProcessor::DataProcessor(Napi::Function& callback, std::vector<double> data)
    : Napi::AsyncWorker(callback), _data(data), _result(0) {}

void DataProcessor::Execute() {
    // Имитация тяжелых вычислений (например, расчет энтропии)
    for (double val : _data) {
        _result += std::sin(val) * std::cos(val);
        std::this_thread::sleep_for(std::chrono::microseconds(10)); 
    }
}

void DataProcessor::OnOK() {
    Napi::HandleScope scope(Env());
    Callback().Call({Env().Null(), Napi::Number::New(Env(), _result)});
}
