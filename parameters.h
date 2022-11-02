//mesh parameters
#define DIMS 2 // default 2D case, change to 3 for 3D simulation
#define refinementFactor 7  // no of elements are 4^N (N=refinement factor)
#define problemWidth 1.0

// mechanics and solte drag control
#define isMechanics true     // if true mechanics dependent grain growth
#define isSoluteDrag true    // if true GB segregation created drag effect
#define isFiniteStrain true  // if true finite strain mechanics else small strain mechanics

//mechanics and solute drag increment
#define mechanicsStartIncrement 20    // start to apply displacement from this time step onward
#define mechanicsEndIncrement 30   // stop applying displacement
#define dragStartIncrement 40    // start solute evolution (segregation) grains don't evolve this time step pnward
#define dragEndIncrement 500 // solute and grains both evolve from this time step onward

// grain growth parameters
#define N_seed_points 60   // no of grains in the system
#define n_diff_grains 6   // no of order parameters used to identify grains
#define InterfaceEnergyParameter 1.0e-3  // in 3D (if 2D use a smaller value)

// Solute parameters
#define GA 0.0    // free energy of solvent (not used in the code)
#define GB 0.0    // free energy of solute (not used in the code)
#define WA 1.0    // double well potential height without solute (suggested to keep it 1 for reference)
#define WB -0.1   // double well potential height in presence of pure solute; change it for different drag force
#define kappa 5.0e-3 //(not used in this code)
#define n_solute 1  // degrees of freedom for solute per node
#define n_chemical_potential 1 // degrees of freedom for chemical potential per node

//kinetic parameters                                                             
#define TimeStep 5.0e-7 // delta T
#define TotalTime 11000*TimeStep // total
#define Mobility 100.0e2   // order parameter mobility
#define M_alpha 1.0   // solute mobility

//other parameters and variables
#define PI 3.1415
#define outputFileName "solution"
#define Vm 1.0  // molar volume (assumed 1 everwhere in code)
#define wellHeight 1.0 // (assumed 1 in the code)

// elastic modulii
#define alpha1 2000 // E_1 along e1 direction in grain
#define beta1 1000 //E_2 along e2 direction in grain  ; refer to paper for more details

// degree of freedom per node
#define TotalDOF n_diff_grains // total degrees of freedom per node

#if isMechanics
#undef TotalDOF
#define TotalDOF n_diff_grains + DIMS
#endif

#if isSoluteDrag
#undef TotalDOF
#define TotalDOF n_diff_grains + n_solute + n_chemical_potential
#endif

#if (isMechanics && isSoluteDrag)
#undef TotalDOF
#define TotalDOF DIMS + n_diff_grains + n_solute + n_chemical_potential
#endif
