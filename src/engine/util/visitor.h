#ifndef VISITOR_H
#define VISITOR_H

class Entity;

template <typename B, typename...>
class Visitor : public B {
	void doVisit();
public:
    Visitor(Entity *s): B{s} {}
	void visit() { doVisit(); }
    virtual ~Visitor() {}
};

template <typename B, typename T, typename... Ts>
class Visitor<B, T, Ts...> : public Visitor<B, Ts...> {
private:
    virtual void doVisit(T *b) { return; }
public:
    Visitor(Entity *s): Visitor<B, Ts...>{s} {}
	using Visitor<B, Ts...>::visit;
    void visit(T *b) { doVisit(b); }
};

#endif
