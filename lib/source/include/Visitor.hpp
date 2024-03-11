#ifndef VISITOR_HPP
#define VISITOR_HPP

#include "Matrix.hpp"
#include "CrankNicolsonMethod.hpp"
#include "ImplicitMethod.hpp"

// Visitor design pattern

class Visitor {
public:
    virtual ~Visitor() {}
    virtual Vector visit(ImplicitScheme* method, int i, Vector q) = 0;
    virtual Vector visit(CNNMethod* method, int i, Vector q) = 0;
};

#endif /* VISITOR_HPP */
