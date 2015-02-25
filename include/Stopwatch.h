#pragma once

#include <sys/time.h>
#include <stdint.h>

class Stopwatch
{
    struct timeval start_;
    struct timeval stop_;
public:
    Stopwatch() : start_(), stop_(){}
    void start()
    {
        gettimeofday(&start_, NULL);
    }
    void stop()
    {
        gettimeofday(&stop_, NULL);
    }
    
#ifdef __APPLE__
    int64_t elapsed_ms()const  // milliseconds
    {
        //printf("stop:%d start:%d\n",stop_.tv_usec,start_.tv_usec);
        return (stop_.tv_sec - start_.tv_sec)*1000+(stop_.tv_usec - start_.tv_usec)/1000;
    }
    
#endif
#ifdef __linux__
    __int64_t elapsed_ms()const  // milliseconds
    {
        //printf("stop:%d start:%d\n",stop_.tv_usec,start_.tv_usec);
        return (stop_.tv_sec - start_.tv_sec)*1000+(stop_.tv_usec - start_.tv_usec)/1000;
    }
    
#endif
#ifdef _WIN32
    __int64 elapsed_ms()const  // milliseconds
    {
        //printf("stop:%d start:%d\n",stop_.tv_usec,start_.tv_usec);
        return (stop_.tv_sec - start_.tv_sec)*1000+(stop_.tv_usec - start_.tv_usec)/1000;
    }
#endif
    
#ifdef __APPLE__
    double mps(const int64_t numOp)const
    {
        return (double)(numOp)/((stop_.tv_sec - start_.tv_sec)*1000000+(stop_.tv_usec-start_.tv_usec));
    }
#endif
#ifdef __linux__
    double mps(const __int64_t numOp)const
    {
        return (double)(numOp)/((stop_.tv_sec - start_.tv_sec)*1000000+(stop_.tv_usec-start_.tv_usec));
    }
#endif
#ifdef _WIN32
    double mps(const int64_t numOp)const
    {
        return (double)(numOp)/((stop_.tv_sec - start_.tv_sec)*1000000+(stop_.tv_usec-start_.tv_usec));
    }
#endif
    
    
};

