> # Todo list
> This is a list of tasks to implement for the library for Parisian options pricing `parisian-options`

## Functionality (TODO)
- Introduce a consistent notation for discretisation schemes e.g. 
- Create a GitHub repository for Parisian options pricing methods e.g. `parisian-options` and make it public
- Use `Doxygen` for documenting classes and function signatures
- Use `UML` diagrams for class hierarchies (helpful in documentation)
- Implement and learn about design patterns
- Initialise rather than assign for the implementation of constructors, as per recommendations
- For `graphviz` and `doxygen`, implement `is a` (inheritence) and `has a` relation (e.g. pointers to class instances as arguments) for classes

## Research papers
- Implement Haber paper with an extra term $\tau$ - Pricing Parisian options using PDE and finite-difference schemes. The PDE method is versatile and can cater for American or other path-dependent specifications (e.g. Asian optionality). For American options, see LCP formulation
- Implement header files for different methods for pricing Parisian options e.g. Laplace, PDE, Monte Carlo and recursions
- Compare different pricing methods for simple instruments e.g. digital options to get $\mathbb{P}(\tau<t)$ and compare with known expressions
- Local volatility and stochastic volatility modelas as well as PIDE implementation for jump models, when dealing with the PDE method for pricing Parisian options.

## Things to learn
- Learn about **stencils** for finite-difference methods e.g. [here](https://en.wikipedia.org/wiki/Stencil_(numerical_analysis)) an how they are used. Try to make a class `stencil` and implement
- About stencils: try to derive a 5-point, 7-point and 9-point stencil for some parabollic PDE and assess their performance and stability
- Abract the stencil into a class
- Experiment with different grids e.g. dyadic
- Comparison between finite-difference schemes e.g. explicit, implicit and Crank-Nicolson and [stalility issues](https://en.wikipedia.org/wiki/Finite_difference_method#:~:text=The%20two%20sources%20of%20error,the%20exact%20quantity%20assuming%20perfect) (look at stability analysis and conditions to have a stable scheme)
- Graphs for error analysis e.g. time discretisation with respect to spacial discretisation
- Oscillations for Gamma of options and the need for [damping](https://en.wikipedia.org/wiki/Crank%E2%80%93Nicolson_method) in finite-difference schemes
- Monte Carlo methods: set up the necessary source and header files 


### Research ideas
- Adapt PDE method to cater for deterministic barrier $b(t)$ and look at its behaviour
- There is a paper about potential issues related to sensitivities of Parisian options (which uses PDEs) and it would be nice to implement this and see for yourself what the issues are. One point to note is that Parisian options behave like barrier when the time is close to $D$ but rare event?

### Files TODO list
- `Option.hpp` 
    - to implement Boundary condition by passing pointer to AssetModel as argument to boundary conditions (Implement AssetModel and IAssetModel)
    - Make variables `private` and implement getters and setters (access functions)
    - Define path-dependent options classes e.g. barrier, Asian, Parisian and American, among others

# References
1. 2006 - Duffy - Finite Difference Methods
2. 2006 - Duffy - Introduction to C++
3. 2009 - Duffy - Monte Carlo Frameworks
4. 2018 - Duffy - Financial Instrument Pricing
5. 2012 - Capinski - Numerical Methods in Finance
6. Joshi Book on design patterns
