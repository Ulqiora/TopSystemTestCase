#include "Observable.h"
#include "Observer.h"
void Observable::Notify() {
    for(auto&& [_,function]:observers){
        function();
    }
}
void Observable::RemoveSubscriber(const ObserverPtr& observer) {
    if(!observer && observers.count(observer) > 0)
        return;
    observers.erase(observer);
}
