#ifndef anabase_hh
#define anabase_hh

#include <TROOT.h>

class TChain;
class TFile;
class TTree;
class TString;
class TBranch;
class TGraph;
class TH1D;
class TH2D;
class TProfile;

class anabase {

public :
  anabase(TString fileList);
  anabase(TString inFileName, Int_t keyID);
  ~anabase();
  Int_t GetEntry(Long64_t entry);
  Long64_t LoadTree(Long64_t entry);
  void Init(TTree *tree);
  void Loop(TString histOut);
  Bool_t Notify();
  void Show(Long64_t entry = -1);
  Int_t Cut(Long64_t entry);

protected :
  TTree          *fChain;   //!pointer to the analyzed TTree or TChain
  Int_t           fCurrent; //!current Tree number in a TChain
  //Int_t           evt;
  //Int_t           run;
  //Float_t         pValue;
  //...
  //...
  //
  //---------------------------------------------------
  // ADD HERE :
  //Tree name
  //const TString treeName = "arich";
  const TString treeName = "T";
  static const Int_t nChannels = 10;
  Int_t    event;
  Int_t    telescope;
  Float_t  energy;
  Float_t  core_distance_to_telescope;
  Float_t  image_size_amplitude_p_e;
  Int_t    number_of_pixels_in_image;
  Float_t  width_deg;
  Float_t  length_deg;
  Float_t  distance_deg;
  Float_t  miss_deg;
  Float_t  alpha_deg;
  Float_t  Xmax_g_cm_2;
  Float_t  Hmax_m;
  //---------------------------------------------------
  
  // List of branches
  //TBranch        *b_evt;
  //TBranch        *b_run;
  //TBranch        *b_pValue;
  //...
  //...
  //
  //---------------------------------------------------
  // ADD HERE :
  TBranch *b_event;
  TBranch *b_telescope;
  TBranch *b_energy;
  TBranch *b_core_distance_to_telescope;
  TBranch *b_image_size_amplitude_p_e;
  TBranch *b_number_of_pixels_in_image;
  TBranch *b_width_deg;
  TBranch *b_length_deg;
  TBranch *b_distance_deg;
  TBranch *b_miss_deg;
  TBranch *b_alpha_deg;
  TBranch *b_Xmax_g_cm_2;
  TBranch *b_Hmax_m;
  //---------------------------------------------------
  void tGraphInit(TGraph *gr[nChannels], TString grName, TString grTitle);
  void h1D1Init(TH1D *h1D1[nChannels],TString h1name, TString h1Title,
		Int_t Nbin, Float_t Vmin, Float_t Vmax);
  void h2D2Init(TH2D *h2D1[nChannels],TString h2name, TString h2Title,
                Int_t Nbin1, Float_t Vmin1, Float_t Vmax1,
                Int_t Nbin2, Float_t Vmin2, Float_t Vmax2);
  void tProfInit(TProfile *tprof[nChannels],TString prname, TString prTitle,
                 Int_t Nbin, Float_t Vmin, Float_t Vmax);
  double getUnixTimeFromTime(double d_year, double d_month, double d_day, double d_hour, double d_min, double d_sec);  
  //
  void h1_normalize(TH1D *h1,TH1D *h1_n);
  void copyHistogram(TH1D *h1, TH1D *h1_copy, TString h1_name_g, TString h1_title_g, bool ifBinsOnly, double norm);

};

#endif
