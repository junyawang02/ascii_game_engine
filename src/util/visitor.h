#ifndef VISITOR_H
#define VISITOR_H

template <typename...>
class Visitor {
public:
    void visit();
    virtual ~Visitor() {}
};
template <typename T, typename... Ts>
class Visitor<T, Ts...> : public Visitor<Ts...> {
public:
    using Visitor<Ts...>::visit;
    virtual void visit(T &b) = 0;
};

#endif
