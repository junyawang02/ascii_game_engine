#ifndef VISITOR_H
#define VISITOR_H

template <typename...>
class Visitor {
	void doVisit();
public:
	void visit() { doVisit(); }
    virtual ~Visitor() {}
};

template <typename T, typename... Ts>
class Visitor<T, Ts...> : public Visitor<Ts...> {
private:
    virtual void doVisit(T *b) { return; }
public:
	using Visitor<Ts...>::visit;
    void visit(T *b) { doVisit(b); }
};

#endif
