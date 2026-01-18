#include<cmath>
#include<random>
#include<functional>
#include<vector>


template<class Drift, class Diffusion>
std::vector<double> EulerMaruyama(double x0, double t0, double dt, double n_steps,  Drift&& a,  Diffusion&& b, std::mt19937& rng)
{
    std::vector<double> x;
    x.resize(n_steps+1);
    
    x[0] = x0;

    std::normal_distribution<double> N(0.0, 1.0);
    
    double dW;
    double t = t0;

    for (size_t i = 0; i<n_steps; i++)
    {
        dW = std::sqrt(dt) * N(rng);
        x[i+1] = x[i] + a(x[i], t)*dt + b(x[i], t)*dW;
        t+=dt;
    }
    return x;
}