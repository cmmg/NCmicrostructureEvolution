# NCmicrostructureEvolution

### About

NCmicrostructureEvolution is a C++ based code which models grain growth in NC alloys, using phase field methods. Drag effect due to GB segregation, solute precipitation and effects of mechanical loading are also included in it. 'main' branch models GB segregation, and 'precipitation' branch models solute precipitation.

This framework models microstructure evolution in NC alloys with the effects of impurity atoms (solute segregation and solute precipitation), and mechanical loading. Primal fields tht are solved are order parameters, soluteconcentration, chemical potential, displacement. 


### Installation:

NCmicrostructureEvolution code builds on top of the deal.II library.

1) Install CMake, PETSc, Trilinos, SLEPc, p4est, and deal.II (version 9.3.0 recommended)<br>

2) Clone the NCmicrostructureEvolution GitHub repository <br>
```
$ git clone https://github.com/cmmg/NCmicrostructureEvolution.git
$ cd NCmicrostructureEvolution

$ git checkout precipitation // for solute precipitation case
$ cmake .
$ make -j nprocs
  ```
[here nprocs denotes the number of processors]
