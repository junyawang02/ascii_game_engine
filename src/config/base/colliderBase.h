#ifndef COLLIDERBASE_H
#define COLLIDERBASE_H

#include "../../engine/util/visitor.h"
#include "colliderImpl.h"
#include <memory>

using std::make_unique;
using std::unique_ptr;

template <typename T, typename... Ts>
class ColliderBase: public Visitor<T, Ts...> {
private:
    unique_ptr<ColliderImpl> cimpl;
protected:
    ColliderImpl *getImpl() { return cimpl.get(); }
public:
    ColliderBase(Entity *s): cimpl{make_unique<ColliderImpl>(s)} {}
};

#endif
