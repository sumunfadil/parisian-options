#ifndef LUDECOMPOSITIONVISITOR_HPP
#define LUDECOMPOSITIONVISITOR_HPP

#include "FiniteDifferenceMethod.hpp"
#include "ImplicitMethod.hpp"
#include "Visitor.hpp"

// Visitor design pattern

class LUDecompositionVisitor : public Visitor {
    
    public:
    
        Vector visit(ImplicitScheme* method, int i, Vector q) override;
        Vector visit(CNNMethod* method, int i, Vector q) override;
};

#endif /* LUDECOMPOSITIONVISITOR_HPP */
