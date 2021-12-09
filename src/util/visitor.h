#ifndef VISITOR_H
#define VISITOR_H

template <typename...>
class Visitor {
public:
    void doVisit();
    virtual ~Visitor() {}
};
template <typename T, typename... Ts>
class Visitor<T, Ts...> : public Visitor<Ts...> {
    using Visitor<Ts...>::doVisit;
    virtual void doVisit(T &b) = 0;
public:
    void visit(T &b) { doVisit(b); }
};

#endif
