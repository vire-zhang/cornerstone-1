#ifndef _TIMER_TASK_HXX_
#define _TIMER_TASK_HXX_

namespace cornerstone {
    template<typename T>
    class timer_task : public delayed_task {
    public:
        typedef std::function<void(T)> executor;

        timer_task(executor& e, T ctx)
            : exec_(e), ctx_(ctx) {}
    protected:
        virtual void exec() __override__ {
            if (exec_) {
                exec_(ctx_);
            }
        }
    private:
        T ctx_;
        executor exec_;
    };
}

#endif //_TIMER_TASK_HXX_