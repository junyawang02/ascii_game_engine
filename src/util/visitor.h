#ifndef VISITOR_H
#define VISITOR_H

#include "../entity/entity.h"

template <typename...>
class Visitor : public Collider {
public:
    void collide();
    virtual ~Visitor() {}
};
template <typename T, typename... Ts>
class Visitor<T, Ts...> : public Visitor<Ts...> {
public:
    using Visitor<Ts...>::collide;
    virtual void collide(T &b) = 0;
};

#endif
