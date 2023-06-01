//C, C++
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

#include <time.h>

using namespace std;

Int_t plots_profile(){
  //
  TString fileN01 = "./hist_proton.root";
  TFile *f01 = new TFile(fileN01.Data());
  TProfile *h1_01 = (TProfile*)f01->Get("pr_image_size_amplitude_p_e_vs_core_distance_to_telescope_cut_01");
  TProfile *h1_02 = (TProfile*)f01->Get("pr_image_size_amplitude_p_e_vs_core_distance_to_telescope_cut_02");
  TProfile *h1_03 = (TProfile*)f01->Get("pr_image_size_amplitude_p_e_vs_core_distance_to_telescope_cut_03");
  TProfile *h1_04 = (TProfile*)f01->Get("pr_image_size_amplitude_p_e_vs_core_distance_to_telescope_cut_05");
  TProfile *h1_05 = (TProfile*)f01->Get("pr_image_size_amplitude_p_e_vs_core_distance_to_telescope_cut_06");
  TProfile *h1_06 = (TProfile*)f01->Get("pr_image_size_amplitude_p_e_vs_core_distance_to_telescope_cut_07");
  //
  //h1_01->Rebin(10);
  //h1_02->Rebin(10);
  //
  h1_01->SetLineColor(kBlack);
  h1_02->SetLineColor(kRed+2);
  h1_03->SetLineColor(kBlue+2);
  h1_04->SetLineColor(kGreen+2);
  h1_05->SetLineColor(kMagenta+2);
  h1_06->SetLineColor(kViolet+2);
  //  
  h1_01->SetLineWidth(2.0);
  h1_02->SetLineWidth(2.0);
  h1_03->SetLineWidth(2.0);
  h1_04->SetLineWidth(2.0);
  h1_05->SetLineWidth(2.0);
  h1_06->SetLineWidth(2.0);
  //
  TCanvas *c1 = new TCanvas("c1","c1",10,10,600,600);
  gStyle->SetPalette(1);
  gStyle->SetFrameBorderMode(0);
  gROOT->ForceStyle();
  gStyle->SetStatColor(kWhite);
  gStyle->SetOptStat(kFALSE);
  //
  h1_01->SetTitle("");
  h1_01->Draw();
  h1_02->Draw("sames");
  h1_03->Draw("sames");
  h1_04->Draw("sames");
  h1_05->Draw("sames");
  h1_06->Draw("sames");
  h1_01->GetXaxis()->SetTitle("Amplitude a.u.");
  //
  h1_01->SetMinimum(230);
  h1_01->SetMaximum(320.0);
  //
  //h1_01_copy_integral->GetXaxis()->SetRangeUser(0.0,100.0);

  /*
  for(i = 0;i<nChannels;i++){
    h1_Arr[i]->SetLineColor(colorArr[i]);
    h1_Arr[i]->SetLineWidth(3.0);
    if(i == 0){
      h1_Arr[i]->Draw();
      h1_Arr[i]->GetXaxis()->SetTitle("Value, Unit");
      //h1_1->GetXaxis()->SetRangeUser(-0.13,-0.12);
    }
    else
      h1_Arr[i]->Draw("same");
  }
  
  //h1_1->Fit("gaus");
  TString legInfo;
  TLegend *leg = new TLegend(0.6,0.6,0.9,0.9,"","brNDC");
  for(i = 0;i<nChannels;i++){
    legInfo = "ch ";legInfo += i;
    leg->AddEntry(h1_Arr[i], legInfo.Data(), "l");
  }
  leg->Draw();
  */
  /*
  TMultiGraph *mg = new TMultiGraph();
  
  for(i = 0;i<nChannels;i++){
    gr_Arr[i]->SetLineColor(colorArr[i]);
    gr_Arr[i]->SetLineWidth(3.0);
    gr_Arr[i]->SetMarkerColor(colorArr[i]);
    gr_Arr[i]->SetMarkerStyle(markerArr[i]);
    mg->Add(gr_Arr[i]);
  }

  mg->Draw("apl");
  
  mg->GetXaxis()->SetTitle("ValueX, Unit");
  mg->GetYaxis()->SetTitle("ValueY, Unit");
  
  TString legInfo;
  TLegend *leg = new TLegend(0.6,0.6,0.9,0.9,"","brNDC");
  for(i = 0;i<nChannels;i++){
    legInfo = "ch ";legInfo += i;
    leg->AddEntry(gr_Arr[i], legInfo.Data(), "apl");
  }
  leg->Draw();
  */  
  TLegend *leg = new TLegend(0.6,0.6,0.9,0.9,"","brNDC");
  leg->AddEntry(h1_01,"5-9 GeV","al");
  leg->AddEntry(h1_02,"10-15 GeV","al");
  leg->AddEntry(h1_03,"16-20 GeV","al");
  leg->AddEntry(h1_04,"31-50 GeV","al");
  leg->AddEntry(h1_05,"51-70 GeV","al");
  leg->AddEntry(h1_06,"71-100 GeV","al");
  leg->Draw();
  return 0;
}
