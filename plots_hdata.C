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

void copyHistogram(TH1F *h1, TH1D *h1_copy, TString h1_name_g, TString h1_title_g, bool ifBinsOnly, double norm);
void getIntegral( TH1D *h1, TH1D *h1_int);

Int_t plots_hdata(){

  //
  TString fileN01 = "../simtel_data/gamma/hdata/np.root";
  TFile *f01 = new TFile(fileN01.Data());
  TH1F *h1_01 = (TH1F*)f01->Get("photo_electrons_per_telescope_n_w");
  TH1D *h1_01_copy=new TH1D();
  TH1D *h1_01_copy_integral=new TH1D();
  TH1D *h1_01_copy_integral_norm=new TH1D();
  //
  TString fileN02 = "../simtel_data/gamma_diffuse/hdata/np.root";
  TFile *f02 = new TFile(fileN02.Data());
  TH1F *h1_02 = (TH1F*)f02->Get("photo_electrons_per_telescope_n_w");
  TH1D *h1_02_copy=new TH1D();
  TH1D *h1_02_copy_integral=new TH1D();
  TH1D *h1_02_copy_integral_norm=new TH1D();
  //
  TString fileN03 = "../simtel_data/electron/hdata/np.root";
  TFile *f03 = new TFile(fileN03.Data());
  TH1F *h1_03 = (TH1F*)f03->Get("photo_electrons_per_telescope_n_w");
  TH1D *h1_03_copy=new TH1D();
  TH1D *h1_03_copy_integral=new TH1D();
  TH1D *h1_03_copy_integral_norm=new TH1D();
  //
  TString fileN04 = "../simtel_data/proton/hdata/np.root";
  TFile *f04 = new TFile(fileN04.Data());
  TH1F *h1_04 = (TH1F*)f04->Get("photo_electrons_per_telescope_n_w");
  TH1D *h1_04_copy=new TH1D();
  TH1D *h1_04_copy_integral=new TH1D();
  TH1D *h1_04_copy_integral_norm=new TH1D();
  //
  copyHistogram(h1_01, h1_01_copy, "photo_electrons_per_telescope_n_w", "photo_electrons_per_telescope_n_w", false, 100000.0);
  copyHistogram(h1_02, h1_02_copy, "photo_electrons_per_telescope_n_w", "photo_electrons_per_telescope_n_w", false, 500000.0);
  copyHistogram(h1_03, h1_03_copy, "photo_electrons_per_telescope_n_w", "photo_electrons_per_telescope_n_w", false, 600000.0);
  copyHistogram(h1_04, h1_04_copy, "photo_electrons_per_telescope_n_w", "photo_electrons_per_telescope_n_w", false, 1000000.0);
  //
  copyHistogram(h1_01, h1_01_copy_integral, "photo_electrons_per_telescope_n_w_integral", "photo_electrons_per_telescope_n_w_integral", true, 1.0);
  copyHistogram(h1_02, h1_02_copy_integral, "photo_electrons_per_telescope_n_w_integral", "photo_electrons_per_telescope_n_w_integral", true, 1.0);
  copyHistogram(h1_03, h1_03_copy_integral, "photo_electrons_per_telescope_n_w_integral", "photo_electrons_per_telescope_n_w_integral", true, 1.0);
  copyHistogram(h1_04, h1_04_copy_integral, "photo_electrons_per_telescope_n_w_integral", "photo_electrons_per_telescope_n_w_integral", true, 1.0);
  //
  copyHistogram(h1_01, h1_01_copy_integral_norm, "photo_electrons_per_telescope_n_w_integral", "photo_electrons_per_telescope_n_w_integral", false, h1_01->Integral(0,h1_01->GetNbinsX()));
  copyHistogram(h1_02, h1_02_copy_integral_norm, "photo_electrons_per_telescope_n_w_integral", "photo_electrons_per_telescope_n_w_integral", false, h1_02->Integral(0,h1_02->GetNbinsX()));
  copyHistogram(h1_03, h1_03_copy_integral_norm, "photo_electrons_per_telescope_n_w_integral", "photo_electrons_per_telescope_n_w_integral", false, h1_03->Integral(0,h1_03->GetNbinsX()));
  copyHistogram(h1_04, h1_04_copy_integral_norm, "photo_electrons_per_telescope_n_w_integral", "photo_electrons_per_telescope_n_w_integral", false, h1_04->Integral(0,h1_04->GetNbinsX()));
  //
  getIntegral(h1_01_copy_integral_norm,h1_01_copy_integral);
  getIntegral(h1_02_copy_integral_norm,h1_02_copy_integral);
  getIntegral(h1_03_copy_integral_norm,h1_03_copy_integral);
  getIntegral(h1_04_copy_integral_norm,h1_04_copy_integral);
  //
  TCanvas *c1 = new TCanvas("c1","c1",10,10,600,600);
  gStyle->SetPalette(1);
  gStyle->SetFrameBorderMode(0);
  gROOT->ForceStyle();
  gStyle->SetStatColor(kWhite);
  gStyle->SetOptStat(kFALSE);

  //h1_01_copy->Rebin(4);
  //h1_02_copy->Rebin(4);
  //h1_03_copy->Rebin(4);
  //h1_04_copy->Rebin(4);
  
  h1_01_copy->SetLineColor(kBlack);
  h1_01_copy->SetLineWidth(2.0);
  h1_02_copy->SetLineColor(kRed);
  h1_02_copy->SetLineWidth(2.0);
  h1_03_copy->SetLineColor(kBlue+2);
  h1_03_copy->SetLineWidth(2.0);
  h1_04_copy->SetLineColor(kGreen+2);
  h1_04_copy->SetLineWidth(2.0);
  //
  h1_01_copy_integral->SetLineColor(kBlack);
  h1_01_copy_integral->SetLineWidth(2.0);
  h1_02_copy_integral->SetLineColor(kRed);
  h1_02_copy_integral->SetLineWidth(2.0);
  h1_03_copy_integral->SetLineColor(kBlue+2);
  h1_03_copy_integral->SetLineWidth(2.0);
  h1_04_copy_integral->SetLineColor(kGreen+2);
  h1_04_copy_integral->SetLineWidth(2.0);
  //
  h1_01_copy_integral->SetTitle("");
  h1_01_copy_integral->Draw();
  h1_02_copy_integral->Draw("sames");
  h1_03_copy_integral->Draw("sames");
  h1_04_copy_integral->Draw("sames");
  h1_01_copy_integral->GetXaxis()->SetTitle("n.e.");
  //h1_01_copy_integral->SetMinimum(1.0e-5);
  h1_01_copy_integral->SetMinimum(0.01);
  //
  h1_01_copy_integral->GetXaxis()->SetRangeUser(0.0,100.0);

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
  leg->AddEntry(h1_01_copy,"gamma","apl");
  leg->AddEntry(h1_02_copy,"gamma diffuse","apl");
  leg->AddEntry(h1_03_copy,"electron","apl");
  leg->AddEntry(h1_04_copy,"proton","apl");
  leg->Draw();
  
  return 0;
}
 
void copyHistogram(TH1F *h1, TH1D *h1_copy, TString h1_name_g, TString h1_title_g, bool ifBinsOnly, double norm){
  TString h1_name = h1_name_g;
  TString h1_title = h1_title_g;
  //
  //G4cout<<"h1_name  "<<h1_name<<G4endl
  //    <<"h1_title "<<h1_title<<G4endl;
  //
  h1_copy->SetName(h1_name.Data());
  h1_copy->SetTitle(h1_title.Data());
  const int n_bins_max = 1000;
  double bins_low_edge[n_bins_max];
  int nBins = h1->GetNbinsX();
  if((nBins+1)>n_bins_max)
    cout<<"ERROR --> (nBins+1)  > n_bins_max"<<endl
        <<"          nBins      = "<<nBins<<endl
        <<"          n_bins_max = "<<n_bins_max<<endl;
  for(int i = 0;i<nBins;i++)
    bins_low_edge[i] = h1->GetBinLowEdge(i+1);
  bins_low_edge[nBins] = h1->GetBinLowEdge(nBins) + h1->GetBinWidth(nBins);
  h1_copy->SetBins(nBins,bins_low_edge);
  if(!ifBinsOnly && norm>0.0){
    for(int i = 1;i<=nBins;i++)
      h1_copy->SetBinContent(i,h1->GetBinContent(i)/norm);

    h1_copy->SetBinContent(nBins+1,h1->GetBinContent(nBins+1)/norm);

  }
}

void getIntegral( TH1D *h1, TH1D *h1_int){
  for(int i = 1;i<=h1->GetNbinsX();i++)
    h1_int->SetBinContent(i,h1->Integral(i-1,h1->GetNbinsX()));
}
