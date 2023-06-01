//root
#include "TROOT.h"
#include "TString.h"
#include "TH1D.h"
#include "TH2D.h"
#include "TFile.h"
#include "TRandom3.h"
#include "TGraph.h"
#include "TGraphErrors.h"
#include <TStyle.h>
#include <TString.h>
#include <TCanvas.h>
#include <TTree.h>

//C, C++
#include <iostream>
#include <stdlib.h>
#include <assert.h>
#include <fstream>
#include <iomanip>
#include <time.h>

//#@* Lines starting with '@*' contain the following columns:
//#@*  (1): event
//#@*  (2): telescope
//#@*  (3): energy
//#@*  (4): core distance to telescope
//#@*  (5): image size (amplitude) [p.e.]
//#@*  (6): number of pixels in image
//#@*  (7): width [deg.]
//#@*  (8): length [deg.]
//#@*  (9): distance [deg.]
//#@* (10): miss [deg.]
//#@* (11): alpha [deg.]
//#@* (12): Xmax [g/cm^2]
//#@* (13): Hmax [m]
//@* 107 1  0.042  594.13   226.9 17  0.9237  1.3203  0.4763  0.2695  34.450 128.095 15058.28
//...

struct wfSimConfStr {
  Int_t event;
  Int_t telescope;
  Double_t energy;
  Double_t core_distance_to_telescope;
  Double_t image_size_amplitude_p_e;
  Double_t number_of_pixels_in_image;
  Double_t width_deg;
  Double_t length_deg;
  Double_t distance_deg;
  Double_t miss_deg;
  Double_t alpha_deg;
  Double_t Xmax_g_cm_2;
  Double_t Hmax_m;
};

std::vector<wfSimConfStr> data_vec;

void read_file(TString file_name);
  
int main(int argc, char *argv[]){
  //
  clock_t start, finish;
  start = clock();
  //
  if(argc == 4 && atoi(argv[1]) == 0){
    //
    TString dat_file = argv[2];
    TString outputRootFile = argv[3];
    //outputRootFile  = "./hist_";
    //outputRootFile += dat_file;
    //outputRootFile += ".root";
    //
    std::cout<<std::endl
	     <<"dat_file        "<<dat_file<<std::endl
	     <<"outputRootFile "<<outputRootFile<<std::endl;
    ////////////////
    read_file(dat_file);
    ////////////////
    TH1D* h1_event = new TH1D("h1_event","h1_event",1000,0,100000);
    TH1D* h1_telescope = new TH1D("h1_telescope","h1_telescope",11,-0.5,10.5);
    TH1D* h1_energy = new TH1D("h1_energy","h1_energy",500,0.0,0.1);
    TH1D* h1_core_distance_to_telescope = new TH1D("h1_core_distance_to_telescope","h1_core_distance_to_telescope",1000,0.0,1000);
    TH1D* h1_image_size_amplitude_p_e = new TH1D("h1_image_size_amplitude_p_e","h1_image_size_amplitude_p_e",10000,0.0,10000);
    TH1D* h1_number_of_pixels_in_image = new TH1D("h1_number_of_pixels_in_image","h1_number_of_pixels_in_image",10000,0.0,10000);
    TH1D* h1_width_deg = new TH1D("h1_width_deg","h1_width_deg",1000,0,10);
    TH1D* h1_length_deg = new TH1D("h1_length_deg","h1_length_deg",1000,0,10);
    TH1D* h1_distance_deg = new TH1D("h1_distance_deg","h1_distance_deg",1000,0,10);
    TH1D* h1_miss_deg = new TH1D("h1_miss_deg","h1_miss_deg",1000,0,10);
    TH1D* h1_alpha_deg = new TH1D("h1_alpha_deg","h1_alpha_deg",10000,0,100);
    TH1D* h1_Xmax_g_cm_2 = new TH1D("h1_Xmax_g_cm_2","h1_Xmax_g_cm_2",1000,0.0,2000);
    TH1D* h1_Hmax_m = new TH1D("h1_Hmax_m","h1_Hmax_m",10000,0.0,100000);
    ////////////////
    TH2D* h2_image_size_amplitude_p_e_vs_energy = new TH2D("h2_image_size_amplitude_p_e_vs_energy",
							   "h2_image_size_amplitude_p_e_vs_energy",
							   100,0.0,0.1,200,0.0,2000);
    TH2D* h2_image_size_amplitude_p_e_vs_energy_cut = new TH2D("h2_image_size_amplitude_p_e_vs_energy_cut",
							   "h2_image_size_amplitude_p_e_vs_energy_cut",
							   100,0.0,0.1,200,0.0,2000);
    TH2D* h2_image_size_amplitude_p_e_vs_core_distance_to_telescope_cut = new TH2D("h2_image_size_amplitude_p_e_vs_core_distance_to_telescope_cut",
							   "h2_image_size_amplitude_p_e_vs_core_distance_to_telescope_cut",
							   200,0.0,900,100,0.0,5000);
    //
    TH1D* h1_width_deg_cut = new TH1D("h1_width_deg_cut","h1_width_deg_cut",1000,0,10);
    TH1D* h1_length_deg_cut = new TH1D("h1_length_deg_cut","h1_length_deg_cut",1000,0,10);
    ////////////////
    for(unsigned int i = 0; i < data_vec.size(); i++){
      h1_event->Fill(data_vec.at(i).event);
      h1_telescope->Fill(data_vec.at(i).telescope);
      h1_energy->Fill(data_vec.at(i).energy);
      h1_core_distance_to_telescope->Fill(data_vec.at(i).core_distance_to_telescope);
      h1_image_size_amplitude_p_e->Fill(data_vec.at(i).image_size_amplitude_p_e);
      h1_number_of_pixels_in_image->Fill(data_vec.at(i).number_of_pixels_in_image);
      h1_width_deg->Fill(data_vec.at(i).width_deg);
      h1_length_deg->Fill(data_vec.at(i).length_deg);
      h1_distance_deg->Fill(data_vec.at(i).distance_deg);
      h1_miss_deg->Fill(data_vec.at(i).miss_deg);
      h1_alpha_deg->Fill(data_vec.at(i).alpha_deg);
      h1_Xmax_g_cm_2->Fill(data_vec.at(i).Xmax_g_cm_2);
      h1_Hmax_m->Fill(data_vec.at(i).Hmax_m);
      //
      h2_image_size_amplitude_p_e_vs_energy->Fill(data_vec.at(i).energy,data_vec.at(i).image_size_amplitude_p_e);
      //if(data_vec.at(i).core_distance_to_telescope<20){
      if(data_vec.at(i).energy>0.0045 && data_vec.at(i).energy<0.0095){
	//if(data_vec.at(i).energy>0.0095 && data_vec.at(i).energy<0.0155){
	//if(data_vec.at(i).energy>0.0155 && data_vec.at(i).energy<0.0195){
	//if(data_vec.at(i).energy>0.0195 && data_vec.at(i).energy<0.0245){	
	//if(data_vec.at(i).energy>0.0245 && data_vec.at(i).energy<0.0295){
	//if(data_vec.at(i).energy>0.0295 && data_vec.at(i).energy<0.0395){
	//if(data_vec.at(i).energy>0.0395 && data_vec.at(i).energy<0.0495){
	//if(data_vec.at(i).energy>0.0495 && data_vec.at(i).energy<0.0595){
	//if(data_vec.at(i).energy>0.0595 && data_vec.at(i).energy<0.0795){
	//if(data_vec.at(i).energy>0.0795 && data_vec.at(i).energy<0.0995){
	//if(data_vec.at(i).energy>0.0995 && data_vec.at(i).energy<0.1995){
	//if(data_vec.at(i).energy>0.1995 && data_vec.at(i).energy<0.2995){
	//if(data_vec.at(i).energy>0.2995 && data_vec.at(i).energy<0.4995){
	h2_image_size_amplitude_p_e_vs_energy_cut->Fill(data_vec.at(i).energy,data_vec.at(i).image_size_amplitude_p_e);
	h1_width_deg_cut->Fill(data_vec.at(i).width_deg);
	h1_length_deg_cut->Fill(data_vec.at(i).length_deg);
	h2_image_size_amplitude_p_e_vs_core_distance_to_telescope_cut->Fill(data_vec.at(i).core_distance_to_telescope,data_vec.at(i).image_size_amplitude_p_e);
      }
      //      
    }
    ////////////////
    TFile* rootFile = new TFile(outputRootFile.Data(), "RECREATE", " Histograms", 1);
    rootFile->cd();
    if (rootFile->IsZombie()){
      std::cout<<"  ERROR ---> file "<<outputRootFile.Data()<<" is zombi"<<std::endl;
      assert(0);
    }
    ///////////////
    h1_event->Write();
    h1_telescope->Write();
    h1_energy->Write();
    h1_core_distance_to_telescope->Write();
    h1_image_size_amplitude_p_e->Write();
    h1_number_of_pixels_in_image->Write();
    h1_width_deg->Write();
    h1_length_deg->Write();
    h1_distance_deg->Write();
    h1_miss_deg->Write();
    h1_alpha_deg->Write();
    h1_Xmax_g_cm_2->Write();
    h1_Hmax_m->Write();
    ///
    h2_image_size_amplitude_p_e_vs_energy->Write();
    h2_image_size_amplitude_p_e_vs_energy_cut->Write();
    h2_image_size_amplitude_p_e_vs_core_distance_to_telescope_cut->Write();
    ///
    h1_width_deg_cut->Write();
    h1_length_deg_cut->Write();
    ///
    rootFile->Close();
    std::cout<<"  Output TGrpah file ---> "<<outputRootFile.Data()<<std::endl;
  }
  else if(argc == 6 && atoi(argv[1]) == 1){
    TString path = argv[2];
    TString prefix = argv[3];
    Int_t nfiles = atoi(argv[4]);
    TString outrootfile = argv[5];
    std::cout<<std::endl
	     <<"path   "<<path<<std::endl
	     <<"prefix "<<prefix<<std::endl
    	     <<"nfiles "<<nfiles<<std::endl
	     <<"outrootfile "<<outrootfile<<std::endl;
    ////////////////
    for(Int_t i = 1;i<=nfiles;i++){
      TString dat_file = path;
      dat_file += prefix;
      dat_file += i;
      dat_file += ".log";
      std::cout<<dat_file<<std::endl;
      //data_vec.reserve(100000);
      read_file(dat_file);
    }
    //
    ///////////////////Root file with data/////////////////
    TFile *hfile = new TFile(outrootfile, "RECREATE", "Simtel log data", 1);
    if (hfile->IsZombie()) {
      std::cout<<" ---> ERROR : PROBLEM with the initialization of the output ROOT file : "<<std::endl
	       <<outrootfile
	       <<std::endl;
      assert(0);
    }
    TTree *tree = new TTree("T", "Simtel data");
    hfile->SetCompressionLevel(2);
    tree->SetAutoSave(1000000);  
    // Create new event
    TTree::SetBranchStyle(0);
    ///////////////////////////////////////////////////////
    //
    Int_t event;
    Int_t telescope;
    Float_t energy;
    Float_t core_distance_to_telescope;
    Float_t image_size_amplitude_p_e;
    Int_t number_of_pixels_in_image;
    Float_t width_deg;
    Float_t length_deg;
    Float_t distance_deg;
    Float_t miss_deg;
    Float_t alpha_deg;
    Float_t Xmax_g_cm_2;
    Float_t Hmax_m;
    //
    //Event////////////////////////////////////////////////
    tree->Branch("event",&event, "event/I");
    tree->Branch("telescope",&telescope, "telescope/I");
    tree->Branch("energy",&energy, "energy/F");
    tree->Branch("core_distance_to_telescope",&core_distance_to_telescope, "core_distance_to_telescope/F");
    tree->Branch("image_size_amplitude_p_e",&image_size_amplitude_p_e, "image_size_amplitude_p_e/F");
    tree->Branch("number_of_pixels_in_image",&number_of_pixels_in_image, "number_of_pixels_in_image/I");
    tree->Branch("width_deg",&width_deg, "width_deg/F");
    tree->Branch("length_deg",&length_deg, "length_deg/F");
    tree->Branch("distance_deg",&distance_deg, "distance_deg/F");
    tree->Branch("miss_deg",&miss_deg, "miss_deg/F");
    tree->Branch("alpha_deg",&alpha_deg, "alpha_deg/F");
    tree->Branch("Xmax_g_cm_2",&Xmax_g_cm_2, "Xmax_g_cm_2/F");
    tree->Branch("Hmax_m",&Hmax_m, "Hmax_m/F");
    ///////////////////////////////////////////////////////
    //
    std::cout<<data_vec.size()<<std::endl;
    for(unsigned int i = 0; i < data_vec.size(); i++){
      if(i%1000000 == 0)
	std::cout<<i<<std::endl;
      event = data_vec.at(i).event;
      telescope = data_vec.at(i).telescope;
      energy = data_vec.at(i).energy;
      core_distance_to_telescope = data_vec.at(i).core_distance_to_telescope;
      image_size_amplitude_p_e = data_vec.at(i).image_size_amplitude_p_e;
      number_of_pixels_in_image = data_vec.at(i).number_of_pixels_in_image;
      width_deg = data_vec.at(i).width_deg;
      length_deg = data_vec.at(i).length_deg;
      distance_deg = data_vec.at(i).distance_deg;
      miss_deg = data_vec.at(i).miss_deg;
      alpha_deg = data_vec.at(i).alpha_deg;
      Xmax_g_cm_2 = data_vec.at(i).Xmax_g_cm_2;
      Hmax_m = data_vec.at(i).Hmax_m;
      tree->Fill();
    }
    hfile = tree->GetCurrentFile();
    hfile->Write();
    hfile->Close();
  }
  else{
    std::cout<<"  runID [1] = 0        "<<std::endl
	     <<"        [2] - dat_file "<<std::endl
	     <<"        [3] - outputRootFile "<<std::endl;
    std::cout<<"  runID [1] = 1        "<<std::endl
	     <<"        [2] - path     "<<std::endl
	     <<"        [3] - prefix   "<<std::endl
    	     <<"        [4] - nfiles   "<<std::endl;
  }  //
  finish = clock();
  std::cout<<"-------------------------"<<std::endl
  	   <<"Working time : "<<((finish - start)/CLOCKS_PER_SEC)<<" (sec)"<<std::endl
  	   <<"-------------------------"<<std::endl;
  //
  return 0;
}

void read_file(TString file_name){
  std::ifstream fFile(file_name.Data());
  //
  Int_t event;
  Int_t telescope;
  Double_t energy;
  Double_t core_distance_to_telescope;
  Double_t image_size_amplitude_p_e;
  Double_t number_of_pixels_in_image;
  Double_t width_deg;
  Double_t length_deg;
  Double_t distance_deg;
  Double_t miss_deg;
  Double_t alpha_deg;
  Double_t Xmax_g_cm_2;
  Double_t Hmax_m;
  //
  if(fFile.is_open()){
    std::string mot;
    while(fFile>>mot){
      if(mot == "Hmax")
	break;
    }
    fFile>>mot;
    while(fFile>>
	  mot>>
	  event>>
	  telescope>>
	  energy>>
	  core_distance_to_telescope>>
	  image_size_amplitude_p_e>>
	  number_of_pixels_in_image>>
	  width_deg>>
	  length_deg>>
	  distance_deg>>
	  miss_deg>>
	  alpha_deg>>
	  Xmax_g_cm_2>>
	  Hmax_m){
      wfSimConfStr datastr;
      datastr.event=event;
      datastr.telescope=telescope;
      datastr.energy=energy;
      datastr.core_distance_to_telescope=core_distance_to_telescope;
      datastr.image_size_amplitude_p_e=image_size_amplitude_p_e;
      datastr.number_of_pixels_in_image=number_of_pixels_in_image;
      datastr.width_deg=width_deg;
      datastr.length_deg=length_deg;
      datastr.distance_deg=distance_deg;
      datastr.miss_deg=miss_deg;
      datastr.alpha_deg=alpha_deg;
      datastr.Xmax_g_cm_2=Xmax_g_cm_2;
      datastr.Hmax_m=Hmax_m;
      data_vec.push_back(datastr);
    }
    fFile.close();
  }
}
