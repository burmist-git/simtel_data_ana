//my
#include "ana.hh"

//root
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TString.h>
#include <TChain.h>
#include <TFile.h>
#include <TTree.h>
#include <TBranch.h>
#include <TGraph.h>
#include <TH1D.h>
#include <TH2D.h>
#include <TProfile.h>
#include <TRandom3.h>

//C, C++
#include <iostream>
#include <stdlib.h>
#include <assert.h>
#include <fstream>
#include <iomanip>
#include <time.h>
#include <bits/stdc++.h>

using namespace std;

void ana::Loop(TString histOut){
  //Int_t i = 0;
  /////////////////////////////////////////////
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
  TH1D* h1_Xmax_g_cm_2_cut = new TH1D("h1_Xmax_g_cm_2_cut","h1_Xmax_g_cm_2_cut",1000,0.0,2000);
  TH1D* h1_Hmax_m_cut = new TH1D("h1_Hmax_m_cut","h1_Hmax_m_cut",10000,0.0,100000);
  ////////////////
  //
  Double_t dist_cut_bg = 400.0;
  Double_t dist_cut = 150.0;
  //
  TH1D* h1_image_size_amplitude_p_e_signal_01 = new TH1D("h1_image_size_amplitude_p_e_signal_01","h1_image_size_amplitude_p_e_signal_01",10000,0.0,10000);
  TH1D* h1_image_size_amplitude_p_e_background_01 = new TH1D("h1_image_size_amplitude_p_e_background_01","h1_image_size_amplitude_p_e_background_01",10000,0.0,10000);
  TH1D* h1_core_distance_to_telescope_01 = new TH1D("h1_core_distance_to_telescope_01","h1_core_distance_to_telescope_01",1000,0.0,1000);
  //
  TH1D* h1_image_size_amplitude_p_e_signal_02 = new TH1D("h1_image_size_amplitude_p_e_signal_02","h1_image_size_amplitude_p_e_signal_02",10000,0.0,10000);
  TH1D* h1_image_size_amplitude_p_e_background_02 = new TH1D("h1_image_size_amplitude_p_e_background_02","h1_image_size_amplitude_p_e_background_02",10000,0.0,10000);
  TH1D* h1_core_distance_to_telescope_02 = new TH1D("h1_core_distance_to_telescope_02","h1_core_distance_to_telescope_02",1000,0.0,1000);
  //
  TH1D* h1_image_size_amplitude_p_e_signal_03 = new TH1D("h1_image_size_amplitude_p_e_signal_03","h1_image_size_amplitude_p_e_signal_03",10000,0.0,10000);
  TH1D* h1_image_size_amplitude_p_e_background_03 = new TH1D("h1_image_size_amplitude_p_e_background_03","h1_image_size_amplitude_p_e_background_03",10000,0.0,10000);
  TH1D* h1_core_distance_to_telescope_03 = new TH1D("h1_core_distance_to_telescope_03","h1_core_distance_to_telescope_03",1000,0.0,1000);
  //
  TH1D* h1_image_size_amplitude_p_e_signal_04 = new TH1D("h1_image_size_amplitude_p_e_signal_04","h1_image_size_amplitude_p_e_signal_04",10000,0.0,10000);
  TH1D* h1_image_size_amplitude_p_e_background_04 = new TH1D("h1_image_size_amplitude_p_e_background_04","h1_image_size_amplitude_p_e_background_04",10000,0.0,10000);
  TH1D* h1_core_distance_to_telescope_04 = new TH1D("h1_core_distance_to_telescope_04","h1_core_distance_to_telescope_04",1000,0.0,1000);
  //
  TH1D* h1_image_size_amplitude_p_e_signal_05 = new TH1D("h1_image_size_amplitude_p_e_signal_05","h1_image_size_amplitude_p_e_signal_05",10000,0.0,10000);
  TH1D* h1_image_size_amplitude_p_e_background_05 = new TH1D("h1_image_size_amplitude_p_e_background_05","h1_image_size_amplitude_p_e_background_05",10000,0.0,10000);
  TH1D* h1_core_distance_to_telescope_05 = new TH1D("h1_core_distance_to_telescope_05","h1_core_distance_to_telescope_05",1000,0.0,1000);
  //
  TH1D* h1_image_size_amplitude_p_e_signal_06 = new TH1D("h1_image_size_amplitude_p_e_signal_06","h1_image_size_amplitude_p_e_signal_06",10000,0.0,10000);
  TH1D* h1_image_size_amplitude_p_e_background_06 = new TH1D("h1_image_size_amplitude_p_e_background_06","h1_image_size_amplitude_p_e_background_06",10000,0.0,10000);
  TH1D* h1_core_distance_to_telescope_06 = new TH1D("h1_core_distance_to_telescope_06","h1_core_distance_to_telescope_06",1000,0.0,1000);
  //
  TH1D* h1_image_size_amplitude_p_e_signal_07 = new TH1D("h1_image_size_amplitude_p_e_signal_07","h1_image_size_amplitude_p_e_signal_07",10000,0.0,10000);
  TH1D* h1_image_size_amplitude_p_e_background_07 = new TH1D("h1_image_size_amplitude_p_e_background_07","h1_image_size_amplitude_p_e_background_07",10000,0.0,10000);
  TH1D* h1_core_distance_to_telescope_07 = new TH1D("h1_core_distance_to_telescope_07","h1_core_distance_to_telescope_07",1000,0.0,1000);
  //
  TH1D* h1_image_size_amplitude_p_e_signal_08 = new TH1D("h1_image_size_amplitude_p_e_signal_08","h1_image_size_amplitude_p_e_signal_08",10000,0.0,10000);
  TH1D* h1_image_size_amplitude_p_e_background_08 = new TH1D("h1_image_size_amplitude_p_e_background_08","h1_image_size_amplitude_p_e_background_08",10000,0.0,10000);
  TH1D* h1_core_distance_to_telescope_08 = new TH1D("h1_core_distance_to_telescope_08","h1_core_distance_to_telescope_08",1000,0.0,1000);
  //
  TH1D* h1_image_size_amplitude_p_e_signal_09 = new TH1D("h1_image_size_amplitude_p_e_signal_09","h1_image_size_amplitude_p_e_signal_09",10000,0.0,10000);
  TH1D* h1_image_size_amplitude_p_e_background_09 = new TH1D("h1_image_size_amplitude_p_e_background_09","h1_image_size_amplitude_p_e_background_09",10000,0.0,10000);
  TH1D* h1_core_distance_to_telescope_09 = new TH1D("h1_core_distance_to_telescope_09","h1_core_distance_to_telescope_09",1000,0.0,1000);
  //
  TH1D* h1_image_size_amplitude_p_e_signal_10 = new TH1D("h1_image_size_amplitude_p_e_signal_10","h1_image_size_amplitude_p_e_signal_10",10000,0.0,10000);
  TH1D* h1_image_size_amplitude_p_e_background_10 = new TH1D("h1_image_size_amplitude_p_e_background_10","h1_image_size_amplitude_p_e_background_10",10000,0.0,10000);
  TH1D* h1_core_distance_to_telescope_10 = new TH1D("h1_core_distance_to_telescope_10","h1_core_distance_to_telescope_10",1000,0.0,1000);
  //
  TH1D* h1_image_size_amplitude_p_e_signal_11 = new TH1D("h1_image_size_amplitude_p_e_signal_11","h1_image_size_amplitude_p_e_signal_11",10000,0.0,10000);
  TH1D* h1_image_size_amplitude_p_e_background_11 = new TH1D("h1_image_size_amplitude_p_e_background_11","h1_image_size_amplitude_p_e_background_11",10000,0.0,10000);
  TH1D* h1_core_distance_to_telescope_11 = new TH1D("h1_core_distance_to_telescope_11","h1_core_distance_to_telescope_11",1000,0.0,1000);
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
  TProfile *pr_image_size_amplitude_p_e_vs_core_distance_to_telescope_cut
    = new TProfile("pr_image_size_amplitude_p_e_vs_core_distance_to_telescope_cut",
		   "pr_image_size_amplitude_p_e_vs_core_distance_to_telescope_cut", 150,0.0,1500,"");
  //
  TH2D* h2_image_size_amplitude_p_e_vs_core_distance_to_telescope_cut_01
    = new TH2D("h2_image_size_amplitude_p_e_vs_core_distance_to_telescope_cut_01",
	       "h2_image_size_amplitude_p_e_vs_core_distance_to_telescope_cut_01",
	       200,0.0,900,100,0.0,5000);
  TProfile *pr_image_size_amplitude_p_e_vs_core_distance_to_telescope_cut_01
    = new TProfile("pr_image_size_amplitude_p_e_vs_core_distance_to_telescope_cut_01",
		   "pr_image_size_amplitude_p_e_vs_core_distance_to_telescope_cut_01", 150,0.0,1500,"");
  //
  TH2D* h2_image_size_amplitude_p_e_vs_core_distance_to_telescope_cut_02
    = new TH2D("h2_image_size_amplitude_p_e_vs_core_distance_to_telescope_cut_02",
	       "h2_image_size_amplitude_p_e_vs_core_distance_to_telescope_cut_02",
	       200,0.0,900,100,0.0,5000);
  TProfile *pr_image_size_amplitude_p_e_vs_core_distance_to_telescope_cut_02
    = new TProfile("pr_image_size_amplitude_p_e_vs_core_distance_to_telescope_cut_02",
		   "pr_image_size_amplitude_p_e_vs_core_distance_to_telescope_cut_02", 150,0.0,1500,"");
  //
  TH2D* h2_image_size_amplitude_p_e_vs_core_distance_to_telescope_cut_03
    = new TH2D("h2_image_size_amplitude_p_e_vs_core_distance_to_telescope_cut_03",
	       "h2_image_size_amplitude_p_e_vs_core_distance_to_telescope_cut_03",
	       200,0.0,900,100,0.0,5000);
  TProfile *pr_image_size_amplitude_p_e_vs_core_distance_to_telescope_cut_03
    = new TProfile("pr_image_size_amplitude_p_e_vs_core_distance_to_telescope_cut_03",
		   "pr_image_size_amplitude_p_e_vs_core_distance_to_telescope_cut_03", 150,0.0,1500,"");
  //
  TH2D* h2_image_size_amplitude_p_e_vs_core_distance_to_telescope_cut_04
    = new TH2D("h2_image_size_amplitude_p_e_vs_core_distance_to_telescope_cut_04",
	       "h2_image_size_amplitude_p_e_vs_core_distance_to_telescope_cut_04",
	       200,0.0,900,100,0.0,5000);
  TProfile *pr_image_size_amplitude_p_e_vs_core_distance_to_telescope_cut_04
    = new TProfile("pr_image_size_amplitude_p_e_vs_core_distance_to_telescope_cut_04",
		   "pr_image_size_amplitude_p_e_vs_core_distance_to_telescope_cut_04", 150,0.0,1500,"");
  //
  TH2D* h2_image_size_amplitude_p_e_vs_core_distance_to_telescope_cut_05
    = new TH2D("h2_image_size_amplitude_p_e_vs_core_distance_to_telescope_cut_05",
	       "h2_image_size_amplitude_p_e_vs_core_distance_to_telescope_cut_05",
	       200,0.0,900,100,0.0,5000);
  TProfile *pr_image_size_amplitude_p_e_vs_core_distance_to_telescope_cut_05
    = new TProfile("pr_image_size_amplitude_p_e_vs_core_distance_to_telescope_cut_05",
		   "pr_image_size_amplitude_p_e_vs_core_distance_to_telescope_cut_05", 150,0.0,1500,"");
  //
  TH2D* h2_image_size_amplitude_p_e_vs_core_distance_to_telescope_cut_06
    = new TH2D("h2_image_size_amplitude_p_e_vs_core_distance_to_telescope_cut_06",
	       "h2_image_size_amplitude_p_e_vs_core_distance_to_telescope_cut_06",
	       200,0.0,900,100,0.0,5000);
  TProfile *pr_image_size_amplitude_p_e_vs_core_distance_to_telescope_cut_06
    = new TProfile("pr_image_size_amplitude_p_e_vs_core_distance_to_telescope_cut_06",
		   "pr_image_size_amplitude_p_e_vs_core_distance_to_telescope_cut_06", 150,0.0,1500,"");
  //
  TH2D* h2_image_size_amplitude_p_e_vs_core_distance_to_telescope_cut_07
    = new TH2D("h2_image_size_amplitude_p_e_vs_core_distance_to_telescope_cut_07",
	       "h2_image_size_amplitude_p_e_vs_core_distance_to_telescope_cut_07",
	       200,0.0,900,100,0.0,5000);
  TProfile *pr_image_size_amplitude_p_e_vs_core_distance_to_telescope_cut_07
    = new TProfile("pr_image_size_amplitude_p_e_vs_core_distance_to_telescope_cut_07",
		   "pr_image_size_amplitude_p_e_vs_core_distance_to_telescope_cut_07", 150,0.0,1500,"");
  //
  TH2D* h2_image_size_amplitude_p_e_vs_core_distance_to_telescope_cut_08
    = new TH2D("h2_image_size_amplitude_p_e_vs_core_distance_to_telescope_cut_08",
	       "h2_image_size_amplitude_p_e_vs_core_distance_to_telescope_cut_08",
	       200,0.0,900,100,0.0,5000);
  TProfile *pr_image_size_amplitude_p_e_vs_core_distance_to_telescope_cut_08
    = new TProfile("pr_image_size_amplitude_p_e_vs_core_distance_to_telescope_cut_08",
		   "pr_image_size_amplitude_p_e_vs_core_distance_to_telescope_cut_08", 150,0.0,1500,"");
  //
  TH2D* h2_image_size_amplitude_p_e_vs_core_distance_to_telescope_cut_09
    = new TH2D("h2_image_size_amplitude_p_e_vs_core_distance_to_telescope_cut_09",
	       "h2_image_size_amplitude_p_e_vs_core_distance_to_telescope_cut_09",
	       200,0.0,900,100,0.0,5000);
  TProfile *pr_image_size_amplitude_p_e_vs_core_distance_to_telescope_cut_09
    = new TProfile("pr_image_size_amplitude_p_e_vs_core_distance_to_telescope_cut_09",
		   "pr_image_size_amplitude_p_e_vs_core_distance_to_telescope_cut_09", 150,0.0,1500,"");
  //
  TH2D* h2_image_size_amplitude_p_e_vs_core_distance_to_telescope_cut_10
    = new TH2D("h2_image_size_amplitude_p_e_vs_core_distance_to_telescope_cut_10",
	       "h2_image_size_amplitude_p_e_vs_core_distance_to_telescope_cut_10",
	       200,0.0,900,100,0.0,5000);
  TProfile *pr_image_size_amplitude_p_e_vs_core_distance_to_telescope_cut_10
    = new TProfile("pr_image_size_amplitude_p_e_vs_core_distance_to_telescope_cut_10",
		   "pr_image_size_amplitude_p_e_vs_core_distance_to_telescope_cut_10", 150,0.0,1500,"");
  //
  TH2D* h2_image_size_amplitude_p_e_vs_core_distance_to_telescope_cut_11
    = new TH2D("h2_image_size_amplitude_p_e_vs_core_distance_to_telescope_cut_11",
	       "h2_image_size_amplitude_p_e_vs_core_distance_to_telescope_cut_11",
	       200,0.0,900,100,0.0,5000);
  TProfile *pr_image_size_amplitude_p_e_vs_core_distance_to_telescope_cut_11
    = new TProfile("pr_image_size_amplitude_p_e_vs_core_distance_to_telescope_cut_11",
		   "pr_image_size_amplitude_p_e_vs_core_distance_to_telescope_cut_11", 150,0.0,1500,"");
  //
  TH1D* h1_width_deg_cut = new TH1D("h1_width_deg_cut","h1_width_deg_cut",1000,0,10);
  TH1D* h1_length_deg_cut = new TH1D("h1_length_deg_cut","h1_length_deg_cut",1000,0,10);
  /////////////////////////////////////////////
  Long64_t nentries = fChain->GetEntriesFast();
  cout<<"nentries = "<<nentries<<endl;
  Long64_t nbytes = 0, nb = 0;
  for (Long64_t jentry=0; jentry<nentries;jentry++) {
    Long64_t ientry = LoadTree(jentry);
    //
    if(jentry%10000000 == 0)
      cout<<jentry<<endl;
    //
    if (ientry < 0) break;
    nb = fChain->GetEntry(jentry);   nbytes += nb;
    //
    h1_event->Fill(event);
    h1_telescope->Fill(telescope);
    h1_energy->Fill(energy);
    h1_core_distance_to_telescope->Fill(core_distance_to_telescope);
    h1_image_size_amplitude_p_e->Fill(image_size_amplitude_p_e);
    h1_number_of_pixels_in_image->Fill(number_of_pixels_in_image);
    h1_width_deg->Fill(width_deg);
    h1_length_deg->Fill(length_deg);
    h1_distance_deg->Fill(distance_deg);
    h1_miss_deg->Fill(miss_deg);
    h1_alpha_deg->Fill(alpha_deg);
    h1_Xmax_g_cm_2->Fill(Xmax_g_cm_2);
    h1_Hmax_m->Fill(Hmax_m);
    //
    h2_image_size_amplitude_p_e_vs_energy->Fill(energy,image_size_amplitude_p_e);
    //
    if(energy>0.0045 && energy<0.0095){
      //if(energy>0.0300 && energy<0.0600){
      h2_image_size_amplitude_p_e_vs_energy_cut->Fill(energy,image_size_amplitude_p_e);
      h1_width_deg_cut->Fill(width_deg);
      h1_length_deg_cut->Fill(length_deg);
      h2_image_size_amplitude_p_e_vs_core_distance_to_telescope_cut->Fill(core_distance_to_telescope,image_size_amplitude_p_e);
      //
      pr_image_size_amplitude_p_e_vs_core_distance_to_telescope_cut->Fill(core_distance_to_telescope,image_size_amplitude_p_e);
      //
      h1_Xmax_g_cm_2_cut->Fill(Xmax_g_cm_2);
      h1_Hmax_m_cut->Fill(Hmax_m);
    }
    //
    if(energy>0.0045 && energy<0.0095){
      h2_image_size_amplitude_p_e_vs_core_distance_to_telescope_cut_01->Fill(core_distance_to_telescope,image_size_amplitude_p_e);
      pr_image_size_amplitude_p_e_vs_core_distance_to_telescope_cut_01->Fill(core_distance_to_telescope,image_size_amplitude_p_e);
      //
      h1_core_distance_to_telescope_01->Fill(core_distance_to_telescope);
      //
      if(core_distance_to_telescope<dist_cut)
	h1_image_size_amplitude_p_e_signal_01->Fill(image_size_amplitude_p_e);
      if(core_distance_to_telescope>dist_cut_bg && core_distance_to_telescope<(dist_cut_bg+dist_cut))
	h1_image_size_amplitude_p_e_background_01->Fill(image_size_amplitude_p_e);
    }
    //
    if(energy>0.0095 && energy<0.0155){
      h2_image_size_amplitude_p_e_vs_core_distance_to_telescope_cut_02->Fill(core_distance_to_telescope,image_size_amplitude_p_e);
      pr_image_size_amplitude_p_e_vs_core_distance_to_telescope_cut_02->Fill(core_distance_to_telescope,image_size_amplitude_p_e);
      //
      h1_core_distance_to_telescope_02->Fill(core_distance_to_telescope);
      //
      if(core_distance_to_telescope<dist_cut)
	h1_image_size_amplitude_p_e_signal_02->Fill(image_size_amplitude_p_e);
      if(core_distance_to_telescope>dist_cut_bg && core_distance_to_telescope<(dist_cut_bg+dist_cut))
	h1_image_size_amplitude_p_e_background_02->Fill(image_size_amplitude_p_e);
    }
    if(energy>0.0155 && energy<0.0205){
      h2_image_size_amplitude_p_e_vs_core_distance_to_telescope_cut_03->Fill(core_distance_to_telescope,image_size_amplitude_p_e);
      pr_image_size_amplitude_p_e_vs_core_distance_to_telescope_cut_03->Fill(core_distance_to_telescope,image_size_amplitude_p_e);
      //
      h1_core_distance_to_telescope_03->Fill(core_distance_to_telescope);
      //
      if(core_distance_to_telescope<dist_cut)
	h1_image_size_amplitude_p_e_signal_03->Fill(image_size_amplitude_p_e);
      if(core_distance_to_telescope>dist_cut_bg && core_distance_to_telescope<(dist_cut_bg+dist_cut))
	h1_image_size_amplitude_p_e_background_03->Fill(image_size_amplitude_p_e);
    }
    if(energy>0.0205 && energy<0.0305){
      h2_image_size_amplitude_p_e_vs_core_distance_to_telescope_cut_04->Fill(core_distance_to_telescope,image_size_amplitude_p_e);
      pr_image_size_amplitude_p_e_vs_core_distance_to_telescope_cut_04->Fill(core_distance_to_telescope,image_size_amplitude_p_e);
      //
      h1_core_distance_to_telescope_04->Fill(core_distance_to_telescope);
      //
      if(core_distance_to_telescope<dist_cut)
	h1_image_size_amplitude_p_e_signal_04->Fill(image_size_amplitude_p_e);
      if(core_distance_to_telescope>dist_cut_bg && core_distance_to_telescope<(dist_cut_bg+dist_cut))
	h1_image_size_amplitude_p_e_background_04->Fill(image_size_amplitude_p_e);
    }
    if(energy>0.0305 && energy<0.0505){
      h2_image_size_amplitude_p_e_vs_core_distance_to_telescope_cut_05->Fill(core_distance_to_telescope,image_size_amplitude_p_e);
      pr_image_size_amplitude_p_e_vs_core_distance_to_telescope_cut_05->Fill(core_distance_to_telescope,image_size_amplitude_p_e);
      //
      h1_core_distance_to_telescope_05->Fill(core_distance_to_telescope);
      //
      if(core_distance_to_telescope<dist_cut)
	h1_image_size_amplitude_p_e_signal_05->Fill(image_size_amplitude_p_e);
      if(core_distance_to_telescope>dist_cut_bg && core_distance_to_telescope<(dist_cut_bg+dist_cut))
	h1_image_size_amplitude_p_e_background_05->Fill(image_size_amplitude_p_e);
    }
    if(energy>0.0505 && energy<0.0705){
      h2_image_size_amplitude_p_e_vs_core_distance_to_telescope_cut_06->Fill(core_distance_to_telescope,image_size_amplitude_p_e);
      pr_image_size_amplitude_p_e_vs_core_distance_to_telescope_cut_06->Fill(core_distance_to_telescope,image_size_amplitude_p_e);
      //
      h1_core_distance_to_telescope_06->Fill(core_distance_to_telescope);
      //      
      if(core_distance_to_telescope<dist_cut)
	h1_image_size_amplitude_p_e_signal_06->Fill(image_size_amplitude_p_e);
      if(core_distance_to_telescope>dist_cut_bg && core_distance_to_telescope<(dist_cut_bg+dist_cut))
	h1_image_size_amplitude_p_e_background_06->Fill(image_size_amplitude_p_e);
    }
    if(energy>0.0705 && energy<0.1005){
      h2_image_size_amplitude_p_e_vs_core_distance_to_telescope_cut_07->Fill(core_distance_to_telescope,image_size_amplitude_p_e);
      pr_image_size_amplitude_p_e_vs_core_distance_to_telescope_cut_07->Fill(core_distance_to_telescope,image_size_amplitude_p_e);
      //
      h1_core_distance_to_telescope_07->Fill(core_distance_to_telescope);
      //
      if(core_distance_to_telescope<dist_cut)
	h1_image_size_amplitude_p_e_signal_07->Fill(image_size_amplitude_p_e);
      if(core_distance_to_telescope>dist_cut_bg && core_distance_to_telescope<(dist_cut_bg+dist_cut))
	h1_image_size_amplitude_p_e_background_07->Fill(image_size_amplitude_p_e);
    }
    if(energy>0.1005 && energy<0.2005){
      h2_image_size_amplitude_p_e_vs_core_distance_to_telescope_cut_08->Fill(core_distance_to_telescope,image_size_amplitude_p_e);
      pr_image_size_amplitude_p_e_vs_core_distance_to_telescope_cut_08->Fill(core_distance_to_telescope,image_size_amplitude_p_e);
      //
      h1_core_distance_to_telescope_08->Fill(core_distance_to_telescope);
      //      
      if(core_distance_to_telescope<dist_cut)
	h1_image_size_amplitude_p_e_signal_08->Fill(image_size_amplitude_p_e);
      if(core_distance_to_telescope>dist_cut_bg && core_distance_to_telescope<(dist_cut_bg+dist_cut))
	h1_image_size_amplitude_p_e_background_08->Fill(image_size_amplitude_p_e);
    }
    if(energy>0.2005 && energy<0.4005){
      h2_image_size_amplitude_p_e_vs_core_distance_to_telescope_cut_09->Fill(core_distance_to_telescope,image_size_amplitude_p_e);
      pr_image_size_amplitude_p_e_vs_core_distance_to_telescope_cut_09->Fill(core_distance_to_telescope,image_size_amplitude_p_e);
      //
      h1_core_distance_to_telescope_09->Fill(core_distance_to_telescope);
      //
      if(core_distance_to_telescope<dist_cut)
	h1_image_size_amplitude_p_e_signal_09->Fill(image_size_amplitude_p_e);
      if(core_distance_to_telescope>dist_cut_bg && core_distance_to_telescope<(dist_cut_bg+dist_cut))
	h1_image_size_amplitude_p_e_background_09->Fill(image_size_amplitude_p_e);
    }
    if(energy>0.4005 && energy<0.6005){
      h2_image_size_amplitude_p_e_vs_core_distance_to_telescope_cut_10->Fill(core_distance_to_telescope,image_size_amplitude_p_e);
      pr_image_size_amplitude_p_e_vs_core_distance_to_telescope_cut_10->Fill(core_distance_to_telescope,image_size_amplitude_p_e);
      //
      h1_core_distance_to_telescope_10->Fill(core_distance_to_telescope);
      //      
      if(core_distance_to_telescope<dist_cut)
	h1_image_size_amplitude_p_e_signal_10->Fill(image_size_amplitude_p_e);
      if(core_distance_to_telescope>dist_cut_bg && core_distance_to_telescope<(dist_cut_bg+dist_cut))
	h1_image_size_amplitude_p_e_background_10->Fill(image_size_amplitude_p_e);
    }
    if(energy>0.6005 && energy<1.0005){
      h2_image_size_amplitude_p_e_vs_core_distance_to_telescope_cut_11->Fill(core_distance_to_telescope,image_size_amplitude_p_e);
      pr_image_size_amplitude_p_e_vs_core_distance_to_telescope_cut_11->Fill(core_distance_to_telescope,image_size_amplitude_p_e);
      //
      h1_core_distance_to_telescope_11->Fill(core_distance_to_telescope);
      //      
      if(core_distance_to_telescope<dist_cut)
	h1_image_size_amplitude_p_e_signal_11->Fill(image_size_amplitude_p_e);
      if(core_distance_to_telescope>dist_cut_bg && core_distance_to_telescope<(dist_cut_bg+dist_cut))
	h1_image_size_amplitude_p_e_background_11->Fill(image_size_amplitude_p_e);
    }
    //
  }
  ///////
  TH1D* h1_image_size_amplitude_p_e_signal_norm_01 = new TH1D();
  TH1D* h1_image_size_amplitude_p_e_background_norm_01 = new TH1D();
  TH1D* h1_image_size_amplitude_p_e_signal_norm_02 = new TH1D();
  TH1D* h1_image_size_amplitude_p_e_background_norm_02 = new TH1D();
  TH1D* h1_image_size_amplitude_p_e_signal_norm_03 = new TH1D();
  TH1D* h1_image_size_amplitude_p_e_background_norm_03 = new TH1D();
  TH1D* h1_image_size_amplitude_p_e_signal_norm_04 = new TH1D();
  TH1D* h1_image_size_amplitude_p_e_background_norm_04 = new TH1D();
  TH1D* h1_image_size_amplitude_p_e_signal_norm_05 = new TH1D();
  TH1D* h1_image_size_amplitude_p_e_background_norm_05 = new TH1D();
  TH1D* h1_image_size_amplitude_p_e_signal_norm_06 = new TH1D();
  TH1D* h1_image_size_amplitude_p_e_background_norm_06 = new TH1D();
  TH1D* h1_image_size_amplitude_p_e_signal_norm_07 = new TH1D();
  TH1D* h1_image_size_amplitude_p_e_background_norm_07 = new TH1D();
  TH1D* h1_image_size_amplitude_p_e_signal_norm_08 = new TH1D();
  TH1D* h1_image_size_amplitude_p_e_background_norm_08 = new TH1D();
  TH1D* h1_image_size_amplitude_p_e_signal_norm_09 = new TH1D();
  TH1D* h1_image_size_amplitude_p_e_background_norm_09 = new TH1D();
  TH1D* h1_image_size_amplitude_p_e_signal_norm_10 = new TH1D();
  TH1D* h1_image_size_amplitude_p_e_background_norm_10 = new TH1D();
  TH1D* h1_image_size_amplitude_p_e_signal_norm_11 = new TH1D();
  TH1D* h1_image_size_amplitude_p_e_background_norm_11 = new TH1D();
  ///////
  h1_normalize(h1_image_size_amplitude_p_e_signal_01,h1_image_size_amplitude_p_e_signal_norm_01);
  h1_normalize(h1_image_size_amplitude_p_e_background_01,h1_image_size_amplitude_p_e_background_norm_01);
  h1_normalize(h1_image_size_amplitude_p_e_signal_02,h1_image_size_amplitude_p_e_signal_norm_02);
  h1_normalize(h1_image_size_amplitude_p_e_background_02,h1_image_size_amplitude_p_e_background_norm_02);
  h1_normalize(h1_image_size_amplitude_p_e_signal_03,h1_image_size_amplitude_p_e_signal_norm_03);
  h1_normalize(h1_image_size_amplitude_p_e_background_03,h1_image_size_amplitude_p_e_background_norm_03);
  h1_normalize(h1_image_size_amplitude_p_e_signal_04,h1_image_size_amplitude_p_e_signal_norm_04);
  h1_normalize(h1_image_size_amplitude_p_e_background_04,h1_image_size_amplitude_p_e_background_norm_04);
  h1_normalize(h1_image_size_amplitude_p_e_signal_05,h1_image_size_amplitude_p_e_signal_norm_05);
  h1_normalize(h1_image_size_amplitude_p_e_background_05,h1_image_size_amplitude_p_e_background_norm_05);
  h1_normalize(h1_image_size_amplitude_p_e_signal_06,h1_image_size_amplitude_p_e_signal_norm_06);
  h1_normalize(h1_image_size_amplitude_p_e_background_06,h1_image_size_amplitude_p_e_background_norm_06);
  h1_normalize(h1_image_size_amplitude_p_e_signal_07,h1_image_size_amplitude_p_e_signal_norm_07);
  h1_normalize(h1_image_size_amplitude_p_e_background_07,h1_image_size_amplitude_p_e_background_norm_07);
  h1_normalize(h1_image_size_amplitude_p_e_signal_08,h1_image_size_amplitude_p_e_signal_norm_08);
  h1_normalize(h1_image_size_amplitude_p_e_background_08,h1_image_size_amplitude_p_e_background_norm_08);
  h1_normalize(h1_image_size_amplitude_p_e_signal_09,h1_image_size_amplitude_p_e_signal_norm_09);
  h1_normalize(h1_image_size_amplitude_p_e_background_09,h1_image_size_amplitude_p_e_background_norm_09);
  h1_normalize(h1_image_size_amplitude_p_e_signal_10,h1_image_size_amplitude_p_e_signal_norm_10);
  h1_normalize(h1_image_size_amplitude_p_e_background_10,h1_image_size_amplitude_p_e_background_norm_10);
  h1_normalize(h1_image_size_amplitude_p_e_signal_11,h1_image_size_amplitude_p_e_signal_norm_11);
  h1_normalize(h1_image_size_amplitude_p_e_background_11,h1_image_size_amplitude_p_e_background_norm_11);
  /////// 
  TH1D *h1_core_distance_to_telescope_norm_01 = new TH1D();
  TH1D *h1_core_distance_to_telescope_norm_02 = new TH1D();
  TH1D *h1_core_distance_to_telescope_norm_03 = new TH1D();
  TH1D *h1_core_distance_to_telescope_norm_04 = new TH1D();
  TH1D *h1_core_distance_to_telescope_norm_05 = new TH1D();
  TH1D *h1_core_distance_to_telescope_norm_06 = new TH1D();
  TH1D *h1_core_distance_to_telescope_norm_07 = new TH1D();
  TH1D *h1_core_distance_to_telescope_norm_08 = new TH1D();
  TH1D *h1_core_distance_to_telescope_norm_09 = new TH1D();
  TH1D *h1_core_distance_to_telescope_norm_10 = new TH1D();
  TH1D *h1_core_distance_to_telescope_norm_11 = new TH1D();
  //
  h1_normalize(h1_core_distance_to_telescope_01,h1_core_distance_to_telescope_norm_01);
  h1_normalize(h1_core_distance_to_telescope_02,h1_core_distance_to_telescope_norm_02);
  h1_normalize(h1_core_distance_to_telescope_03,h1_core_distance_to_telescope_norm_03);
  h1_normalize(h1_core_distance_to_telescope_04,h1_core_distance_to_telescope_norm_04);
  h1_normalize(h1_core_distance_to_telescope_05,h1_core_distance_to_telescope_norm_05);
  h1_normalize(h1_core_distance_to_telescope_06,h1_core_distance_to_telescope_norm_06);
  h1_normalize(h1_core_distance_to_telescope_07,h1_core_distance_to_telescope_norm_07);
  h1_normalize(h1_core_distance_to_telescope_08,h1_core_distance_to_telescope_norm_08);
  h1_normalize(h1_core_distance_to_telescope_09,h1_core_distance_to_telescope_norm_09);
  h1_normalize(h1_core_distance_to_telescope_10,h1_core_distance_to_telescope_norm_10);
  h1_normalize(h1_core_distance_to_telescope_11,h1_core_distance_to_telescope_norm_11);
  ///////
  TFile* rootFile = new TFile(histOut.Data(), "RECREATE", " Histograms", 1);
  rootFile->cd();
  if (rootFile->IsZombie()){
    cout<<"  ERROR ---> file "<<histOut.Data()<<" is zombi"<<endl;
    assert(0);
  }
  else
    cout<<"  Output Histos file ---> "<<histOut.Data()<<endl;
  ////////////////////////
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
  //
  h2_image_size_amplitude_p_e_vs_energy->Write();
  h2_image_size_amplitude_p_e_vs_energy_cut->Write();
  h2_image_size_amplitude_p_e_vs_core_distance_to_telescope_cut->Write();
  pr_image_size_amplitude_p_e_vs_core_distance_to_telescope_cut->Write();
  //
  h2_image_size_amplitude_p_e_vs_core_distance_to_telescope_cut_01->Write();
  pr_image_size_amplitude_p_e_vs_core_distance_to_telescope_cut_01->Write();
  h2_image_size_amplitude_p_e_vs_core_distance_to_telescope_cut_02->Write();
  pr_image_size_amplitude_p_e_vs_core_distance_to_telescope_cut_02->Write();
  h2_image_size_amplitude_p_e_vs_core_distance_to_telescope_cut_03->Write();
  pr_image_size_amplitude_p_e_vs_core_distance_to_telescope_cut_03->Write();
  h2_image_size_amplitude_p_e_vs_core_distance_to_telescope_cut_04->Write();
  pr_image_size_amplitude_p_e_vs_core_distance_to_telescope_cut_04->Write();
  h2_image_size_amplitude_p_e_vs_core_distance_to_telescope_cut_05->Write();
  pr_image_size_amplitude_p_e_vs_core_distance_to_telescope_cut_05->Write();
  h2_image_size_amplitude_p_e_vs_core_distance_to_telescope_cut_06->Write();
  pr_image_size_amplitude_p_e_vs_core_distance_to_telescope_cut_06->Write();
  h2_image_size_amplitude_p_e_vs_core_distance_to_telescope_cut_07->Write();
  pr_image_size_amplitude_p_e_vs_core_distance_to_telescope_cut_07->Write();
  h2_image_size_amplitude_p_e_vs_core_distance_to_telescope_cut_08->Write();
  pr_image_size_amplitude_p_e_vs_core_distance_to_telescope_cut_08->Write();
  h2_image_size_amplitude_p_e_vs_core_distance_to_telescope_cut_09->Write();
  pr_image_size_amplitude_p_e_vs_core_distance_to_telescope_cut_09->Write();
  h2_image_size_amplitude_p_e_vs_core_distance_to_telescope_cut_10->Write();
  pr_image_size_amplitude_p_e_vs_core_distance_to_telescope_cut_10->Write();
  h2_image_size_amplitude_p_e_vs_core_distance_to_telescope_cut_11->Write();
  pr_image_size_amplitude_p_e_vs_core_distance_to_telescope_cut_11->Write();
  //
  h1_image_size_amplitude_p_e_signal_01->Write();
  h1_image_size_amplitude_p_e_background_01->Write();
  h1_image_size_amplitude_p_e_signal_02->Write();
  h1_image_size_amplitude_p_e_background_02->Write();
  h1_image_size_amplitude_p_e_signal_03->Write();
  h1_image_size_amplitude_p_e_background_03->Write();
  h1_image_size_amplitude_p_e_signal_04->Write();
  h1_image_size_amplitude_p_e_background_04->Write();
  h1_image_size_amplitude_p_e_signal_05->Write();
  h1_image_size_amplitude_p_e_background_05->Write();
  h1_image_size_amplitude_p_e_signal_06->Write();
  h1_image_size_amplitude_p_e_background_06->Write();
  h1_image_size_amplitude_p_e_signal_07->Write();
  h1_image_size_amplitude_p_e_background_07->Write();
  h1_image_size_amplitude_p_e_signal_08->Write();
  h1_image_size_amplitude_p_e_background_08->Write();
  h1_image_size_amplitude_p_e_signal_09->Write();
  h1_image_size_amplitude_p_e_background_09->Write();
  h1_image_size_amplitude_p_e_signal_10->Write();
  h1_image_size_amplitude_p_e_background_10->Write();
  h1_image_size_amplitude_p_e_signal_11->Write();
  h1_image_size_amplitude_p_e_background_11->Write();
  //
  h1_core_distance_to_telescope_01->Write();
  h1_core_distance_to_telescope_02->Write();
  h1_core_distance_to_telescope_03->Write();
  h1_core_distance_to_telescope_04->Write();
  h1_core_distance_to_telescope_05->Write();
  h1_core_distance_to_telescope_06->Write();
  h1_core_distance_to_telescope_07->Write();
  h1_core_distance_to_telescope_08->Write();
  h1_core_distance_to_telescope_09->Write();
  h1_core_distance_to_telescope_10->Write();
  h1_core_distance_to_telescope_11->Write();
  //
  h1_core_distance_to_telescope_norm_01->Write();
  h1_core_distance_to_telescope_norm_02->Write();
  h1_core_distance_to_telescope_norm_03->Write();
  h1_core_distance_to_telescope_norm_04->Write();
  h1_core_distance_to_telescope_norm_05->Write();
  h1_core_distance_to_telescope_norm_06->Write();
  h1_core_distance_to_telescope_norm_07->Write();
  h1_core_distance_to_telescope_norm_08->Write();
  h1_core_distance_to_telescope_norm_09->Write();
  h1_core_distance_to_telescope_norm_10->Write();
  h1_core_distance_to_telescope_norm_11->Write();
  //
  h1_image_size_amplitude_p_e_signal_norm_01->Write();
  h1_image_size_amplitude_p_e_background_norm_01->Write();
  //
  h1_width_deg_cut->Write();
  h1_length_deg_cut->Write();
  h1_Xmax_g_cm_2_cut->Write();
  h1_Hmax_m_cut->Write();
  //
  ////////////////////////
  rootFile->Close();
}
