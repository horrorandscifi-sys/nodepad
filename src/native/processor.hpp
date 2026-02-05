#pragma once
#include <napi.h>
#include <vector>
#include <thread>

class DataProcessor : public Napi::AsyncWorker {
public:
    DataProcessor(Napi::Function& callback, std::vector<double> data);
    void Execute() override; // Тут будет тяжелая математика
    void OnOK() override;    // Возврат в JS
private:
    std::vector<double> _data;
    double _result;
};
