#ifndef ACCEPTOR_H
#define ACCEPTOR_H

template<typename B, typename C, typename V>
class Acceptor: public B {
public:
    using B::B;
    void accept(V &v) override {v.visit(*static_cast<C*>(this));}
};

#endif
