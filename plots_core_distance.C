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

Int_t plots_core_distance(){

  //
  TString fileN01 = "./hist_gamma.root";
  TFile *f01 = new TFile(fileN01.Data());
  TH1F *h1_01 = (TH1F*)f01->Get("h1_core_distance_to_telescope_01_normalize");
  TH1F *h1_02 = (TH1F*)f01->Get("h1_core_distance_to_telescope_02_normalize");
  TH1F *h1_03 = (TH1F*)f01->Get("h1_core_distance_to_telescope_03_normalize");
  TH1F *h1_04 = (TH1F*)f01->Get("h1_core_distance_to_telescope_08_normalize");
  TH1F *h1_05 = (TH1F*)f01->Get("h1_core_distance_to_telescope_09_normalize");
  TH1F *h1_06 = (TH1F*)f01->Get("h1_core_distance_to_telescope_10_normalize");
  TH1F *h1_07 = (TH1F*)f01->Get("h1_core_distance_to_telescope_07_normalize");
  TH1F *h1_08 = (TH1F*)f01->Get("h1_core_distance_to_telescope_08_normalize");
  TH1F *h1_09 = (TH1F*)f01->Get("h1_core_distance_to_telescope_09_normalize");
  TH1F *h1_10 = (TH1F*)f01->Get("h1_core_distance_to_telescope_10_normalize");
  TH1F *h1_11 = (TH1F*)f01->Get("h1_core_distance_to_telescope_11_normalize");
  //
  h1_01->Rebin(4);
  h1_02->Rebin(4);
  h1_03->Rebin(4);
  h1_04->Rebin(4);
  h1_05->Rebin(4);
  h1_06->Rebin(4);
  //
  h1_01->SetLineColor(kBlack);
  h1_02->SetLineColor(kRed+2);
  h1_03->SetLineColor(kBlue+2);
  h1_04->SetLineColor(kMagenta+2);
  h1_05->SetLineColor(kViolet+2);
  h1_06->SetLineColor(kGreen+2);
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
  //h1_01->GetXaxis()->SetTitle("n.e.");
  h1_01->SetMinimum(0.0);
  h1_01->SetMaximum(0.01);
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
  leg->AddEntry(h1_01,"E = [5-9] GeV","al");
  leg->AddEntry(h1_02,"E = [10-15] GeV","al");
  leg->AddEntry(h1_03,"E = [16-20] GeV","apl");
  leg->AddEntry(h1_04,"E = [101-200] GeV","al");
  leg->AddEntry(h1_05,"E = [201-400] GeV","al");
  leg->AddEntry(h1_06,"E = [401-600] GeV","al");
  leg->Draw();
  return 0;
}
