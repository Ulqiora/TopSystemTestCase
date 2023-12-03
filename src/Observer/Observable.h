#pragma once
#include <memory>
#include <map>
#include <functional>
class Observer;
using ObserverPtr = std::shared_ptr<Observer>;

//template<>
class Observable{
public:
    using SavedFunction = std::function<void()>;

    template<class SavedFunction,class... Args>
    requires    std::is_invocable_v<SavedFunction,Args...> &&
                std::is_same_v<std::invoke_result_t<SavedFunction,Args...>,void>
    void AddSubscriber(ObserverPtr,SavedFunction,Args...);
    void RemoveSubscriber(const ObserverPtr&);
private:
    std::map<ObserverPtr,SavedFunction> observers;
};

void Observable::RemoveSubscriber(const ObserverPtr& observer) {
    if(!observer && observers.count(observer) > 0)
        return;
    observers.erase(observer);
}

template<class SavedFunction, class... Args>
requires std::is_invocable_v<SavedFunction, Args...> &&
         std::is_same_v<std::invoke_result_t<SavedFunction, Args...>, void>
void Observable::AddSubscriber(ObserverPtr observer, SavedFunction func, Args... args) {
    RemoveSubscriber(observer);
    observers[observer] = std::bind(func,std::forward<Args>(args)...);
}
