#pragma once
#include <future>
#include <thread>
#include <utility>

/**
 * @brief 
 * 
 * Run the function func on a new thread, passing args. Returns a future for
 * func's execution
 * 
 * @param Ret(*func)(Args...)
 * @param Args...args
 * 
 * @return template <class Ret,class ...Args> std::future<Ret>
 */
template <class Ret,class ...Args>
std::future<Ret> launchParallel(Ret(*func)(Args...),Args...args)
{
    std::future<Ret> res;
    std::packaged_task<Ret(Args...)> task(func);
    res = task.get_future();
    std::thread(
        std::move(task),
        std::ref(
            std::forward<Args...>(args)
        )...
    ).detach();
    return res;
}