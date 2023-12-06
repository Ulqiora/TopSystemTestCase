#pragma once
#include <memory>
#include <map>
#include <functional>
#include "Observer.h"
class Observable;
using ObserverPtr = std::shared_ptr<Observer>;
using ObservablePtr = std::shared_ptr<Observable>;
//template<>
class Observable{
public:
    using SavedFunction = std::function<void()>;

    template<class FunctionType,class... Args>
    requires    std::is_invocable_v<FunctionType,Args...> &&
                std::is_same_v<std::invoke_result_t<FunctionType,Args...>,void>
    void AddSubscriber(ObserverPtr ,FunctionType,Args...);
    void RemoveSubscriber(const ObserverPtr&);
    void Notify();
    virtual ~Observable()= default;
private:
    std::map<ObserverPtr,SavedFunction> observers;
};
template<class FunctionType, class... Args>
requires std::is_invocable_v<FunctionType, Args...> &&
         std::is_same_v<std::invoke_result_t<FunctionType, Args...>, void>
void Observable::AddSubscriber(ObserverPtr observer, FunctionType func, Args... args) {
    RemoveSubscriber(observer);
    observers[observer] = std::bind(func,std::forward<Args>(args)...);
}

