//Autogenerated using tree_header.jl -> no longer autogenerated, can update manually
#ifndef COMMONCLASSIFIER_INPUT_TREE
#define COMMONCLASSIFIER_INPUT_TREE

#include <TTree.h>
#include <cmath>
#include <string>

//HEADERGEN_DEFINES

//macros to initialize 1D and 2D (square) arrays
//x is the array, n is the size, y is the initialized value
#define SET_ZERO(x,n,y) for(int i=0;i<n;i++) {x[i]=y;}
#define SET_ZERO_2(x,n,m,y) for(int i=0;i<n;i++) { for(int j=0;j<m;j++) { x[i][j]=y; } }

/*
This is a simple wrapper class for the TTH-specific flat data format.
To use it, one should load the input file in the standard way using
TFile* f = new TFile("ntuple.root");
TTree* _ttree = (TTree*)f->Get("tthNtupleAnalyzer/events");
and then initialize the class using
CommonClassifierInputTree tree(_ttree);
CommonClassifierInputTree contains the C++ variables for all the branches and functions to conveniently set them.
To attach the branches in the read mode (call SetBranchAddress), call
tree.set_branch_addresses();
outside the event loop.
 You can loop over the events in the standard way
 for (unsigned int i=0; i < _ttree->GetEntries(); i++) {
     tree.loop_initialize(); // <-- this makes sure all the branch variables are cleared from the previous entry
     _ttree->GetEntry(i); // <--- loads the branch contents into the branch variables
     for (int njet=0; njet < tree.n__jet; njet++) {
         float x = tree.jet__pt[njet];
         //do something with the jet pt 
     }
*/
class CommonClassifierInputTree {
public:
    CommonClassifierInputTree(TTree* _tree) { tree = _tree; };
    TTree* tree;
   
        // Helper functions for accessing branches
    template <typename T> 
    T get_address(const std::string name) {
        auto* br = tree->GetBranch(name.c_str());
        if (br==0) {
            std::cerr << "ERROR: get_address CommonClassifierInputTree " << "branch " << name << " does not exist" << std::endl;
            throw std::exception();
        }
        auto* p = br->GetAddress();
        return reinterpret_cast<T>(p);
    }
    
    long run;
    long event;
    long lumi;
    int nleps;
    int njets;
    int hypothesis;
    int numcalls;
    float met_pt;
    float met_phi;
    float leps_pt[2];
    float leps_eta[2];
    float leps_phi[2];
    float leps_mass[2];
    float leps_charge[2];
    float jets_pt[10];
    float jets_eta[10];
    float jets_phi[10];
    float jets_mass[10];
    float jets_csv[10];
    float jets_cmva[10];
    int jets_type[10];
    //HEADERGEN_BRANCH_VARIABLES
    //This comment is for automatic header generation, do not remove

    //initializes all branch variables
    void loop_initialize(void) {        
        run = DEF_VAL_LONG;
        event = DEF_VAL_LONG;
        lumi = DEF_VAL_LONG;
        nleps = DEF_VAL_INT;
        njets = DEF_VAL_INT;
        hypothesis = DEF_VAL_INT;
        numcalls = DEF_VAL_INT;
        met_pt = DEF_VAL_FLOAT;
        met_phi = DEF_VAL_FLOAT;
        SET_ZERO(leps_pt, 2, 0);
        SET_ZERO(leps_eta, 2, 0);
        SET_ZERO(leps_phi, 2, 0);
        SET_ZERO(leps_mass, 2, 0);
        SET_ZERO(leps_charge, 2, 0);
        SET_ZERO(jets_pt, 10, 0);
        SET_ZERO(jets_eta, 10, 0);
        SET_ZERO(jets_phi, 10, 0);
        SET_ZERO(jets_mass, 10, 0);
        SET_ZERO(jets_csv, 10, 0);
        SET_ZERO(jets_cmva, 10, 0);
        SET_ZERO(jets_type, 10, 0);
        //HEADERGEN_BRANCH_INITIALIZERS
    }

    //makes branches on a new TTree
    void make_branches(void) {
        tree->Branch("run", &run, "run/L");
        tree->Branch("event", &event, "event/L");
        tree->Branch("lumi", &lumi, "lumi/L");
        tree->Branch("nleps", &nleps, "nleps/I");
        tree->Branch("njets", &njets, "njets/I");
        tree->Branch("hypothesis", &hypothesis, "hypothesis/I");
        tree->Branch("numcalls", &numcalls, "numcalls/I");
        tree->Branch("met_pt", &met_pt, "met_pt/F");
        tree->Branch("met_phi", &met_phi, "met_phi/F");
        tree->Branch("leps_pt", leps_pt, "leps_pt[nleps]/F");
        tree->Branch("leps_eta", leps_eta, "leps_eta[nleps]/F");
        tree->Branch("leps_phi", leps_phi, "leps_phi[nleps]/F");
        tree->Branch("leps_mass", leps_mass, "leps_mass[nleps]/F");
        tree->Branch("leps_charge", leps_charge, "leps_charge[nleps]/F");
        tree->Branch("jets_pt", jets_pt, "jets_pt[njets]/F");
        tree->Branch("jets_eta", jets_eta, "jets_eta[njets]/F");
        tree->Branch("jets_phi", jets_phi, "jets_phi[njets]/F");
        tree->Branch("jets_mass", jets_mass, "jets_mass[njets]/F");
        tree->Branch("jets_csv", jets_csv, "jets_csv[njets]/F");
        tree->Branch("jets_cmva", jets_cmva, "jets_cmva[njets]/F");
        tree->Branch("jets_type", jets_type, "jets_type[njets]/I");
        //HEADERGEN_BRANCH_CREATOR
    }

    //connects the branches of an existing TTree to variables
    //used when loading the file
    void set_branch_addresses(void) {        
        tree->SetBranchAddress("run", &run);
        tree->SetBranchAddress("event", &event);
        tree->SetBranchAddress("lumi", &lumi);
        tree->SetBranchAddress("nleps", &nleps);
        tree->SetBranchAddress("njets", &njets);
        tree->SetBranchAddress("hypothesis", &hypothesis);
        tree->SetBranchAddress("numcalls", &numcalls);
        tree->SetBranchAddress("met_pt", &met_pt);
        tree->SetBranchAddress("met_phi", &met_phi);
        tree->SetBranchAddress("leps_pt", leps_pt);
        tree->SetBranchAddress("leps_eta", leps_eta);
        tree->SetBranchAddress("leps_phi", leps_phi);
        tree->SetBranchAddress("leps_mass", leps_mass);
        tree->SetBranchAddress("leps_charge", leps_charge);
        tree->SetBranchAddress("jets_pt", jets_pt);
        tree->SetBranchAddress("jets_eta", jets_eta);
        tree->SetBranchAddress("jets_phi", jets_phi);
        tree->SetBranchAddress("jets_mass", jets_mass);
        tree->SetBranchAddress("jets_csv", jets_csv);
        tree->SetBranchAddress("jets_cmva", jets_cmva);
        tree->SetBranchAddress("jets_type", jets_type);
        //HEADERGEN_BRANCH_SETADDRESS
    }
};

#endif