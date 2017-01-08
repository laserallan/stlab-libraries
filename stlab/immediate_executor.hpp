/*-
Copyright 2017 Felix Petriconi
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
*/

/**************************************************************************************************/

#ifndef SLABFUTURE_IMMEDIATE_EXECUTOR_HPP
#define SLABFUTURE_IMMEDIATE_EXECUTOR_HPP

#include <chrono>

namespace stlab
{

struct immediate_executor
{
    template <typename F>
    void operator()(F&& f) {
        std::forward<F>(f)();
    }

    template <typename F>
    void operator()(std::chrono::system_clock::time_point, && f) {
        std::forward<F>(f)();
    }
};

}

#endif //SLABFUTURE_IMMEDIATE_EXECUTOR_HPP
