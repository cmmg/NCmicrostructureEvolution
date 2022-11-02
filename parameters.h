//mesh parameters
#define DIMS 2 // default 2D, change to 3 for3D simulations
#define refinementFactor 7 // no of elements 4^N N=refinement factor
#define problemWidth 1.0

// mechanics and solte drag control
#define isMechanics false // if true mechancis controlled grain growth
#define isSoluteDrag false //if true solute  precipitation active
#define isFiniteStrain false //if true finite strain mechanics else small strain mechanics

//mechanics and solute drag increment                                                                                
#define mechanicsStartIncrement 20 // start applying displacement
#define mechanicsEndIncrement 30 // stop applying displacement
#define dragStartIncrement 40 // start solute evolution; grains stop evolving
#define dragEndIncrement 1000 // stop solute evolution; grains evolve this time-step onwards

// grain growth parameters
#define N_seed_points 60 // no of grains
#define n_diff_grains 6 // no of order parameters
#define InterfaceEnergyParameter 1.0e-3 // for 3D; use a smaller value for 2D

// Solute parameters
#define WA 1.0 // double well potential height without solute , suggested to keep it 1
#define WB 0.1  // double well potential height with solute; change it for different drag effect
#define kappa 5.0e-3 // interface energy parameter for CahnHilliard equation for solute precipitates
#define n_solute 1 // degrees of freedom for solute per node
#define n_chemical_potential 1 // degrees of freedom for chemical potential per node

//kinetic parameters
#define TimeStep 5.0e-7
#define TotalTime 11000*TimeStep
#define Mobility 100.0e2 // order parameter mobility
#define M_alpha 0.5 // solute mobility

//other parameters and variables
#define PI 3.1415
#define outputFileName "solution"
#define Vm 1.0 // molar volume; code assumes a value of 1 everywhere
#define wellHeight 1.0 // assumed 1 everywhere (no effect on changing this parameter)

// elastic modulii
#define alpha1 2000 // E_1 along e1 direction in grain
#define beta1 1000 // E_2 along e2 direction in grain

// degree of freedom per node 
#define TotalDOF n_diff_grains // degrees of freedom per node without drag and mechanics

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
