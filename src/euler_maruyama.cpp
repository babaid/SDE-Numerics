#include "../include/euler_maruyama.hpp"
#include<iostream>

int main()

{
    auto a = [](double x, double t){ return -0.25*x;};
    auto b  = [](double x, double t){ return 0;};
    std::mt19937 rng(123);
    
    auto out = EulerMaruyama(10.0, 0.0, 0.1, 100, a, b, rng);
    for (auto el: out)
    {
        std::cout << el << std::endl;
    }
    return 0;
}