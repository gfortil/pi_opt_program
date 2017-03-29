#include <stdio.h>
#include <chrono>
#include <time.h>



static long num_steps = 100000;
double step;

int main()
{
    int i;
    double x, pi, sum = 0.0;
    //double start1, end1 = 0.0;
    //time_t runtime;
    step = 1.0/(double) num_steps;
    
    std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now(); //start time
    for (i = 0; i < num_steps; i++)
    {
        x = (i + 0.5) * step;
        sum += 4.0 / (1.0 + x * x);
    }
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now(); //end time
    
    std::chrono::steady_clock::duration runtime = end - start; //runtime computation
    double conv = std::chrono::duration_cast<std::chrono::nanoseconds>(runtime).count();
    printf("runtime = %f nanoseconds\n", conv);
    
    pi = step * sum;
    printf("pi = %f\n", pi);
    
    return 0;
}
