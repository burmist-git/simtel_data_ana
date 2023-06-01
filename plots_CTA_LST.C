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

///////////////////////////////////////////////////////////////////////////////////
//*                         (re-centered on new central MST (MST 15) position).  //
//*                                                                              //
//* LSTs:                                                                        //
//*                                                                              //
//*                                                                              //
//TELESCOPE     -70.930E2    -52.070E2   43.00E2   12.50E2   # L-01  (ID=1)      //
//TELESCOPE     -35.270E2     66.140E2   32.00E2   12.50E2   # L-02              //
//TELESCOPE      75.280E2     50.490E2   28.70E2   12.50E2   # L-03              //
//TELESCOPE      30.910E2    -64.540E2   32.00E2   12.50E2   # L-04  (ID=4)      //
//*                                                                              //
//* MAGIC:                                                                       //
//*                                                                              //
//*                                                                              //
//TELESCOPE     -23.540E2    -191.750E2   41.25E2   10.00E2   # MAGIC-01 (ID=5)  //
//TELESCOPE     -94.050E2    -143.770E2   42.42E2   10.00E2   # MAGIC-02 (ID=6)  //
///////////////////////////////////////////////////////////////////////////////////

TRandom3 *rnd = new TRandom3(123124);

void simulate_tel_pos( Double_t x0, Double_t y0, Double_t R, Double_t &x, Double_t &y);
void simulate_frame( Double_t xf, Double_t yf, Double_t lf, TGraph *gr);
//void simulate_( Double_t xf, Double_t yf, Double_t lf, TGraph *gr);

Int_t plots_CTA_LST(){
  //
  Double_t xf = -150;
  Double_t yf = -210;
  Double_t lf =  280;
  //
  Int_t n = 1000;
  //
  TGraph *gr_LST_01 = new TGraph();
  TGraph *gr_LST_02 = new TGraph();
  TGraph *gr_LST_03 = new TGraph();
  TGraph *gr_LST_04 = new TGraph();
  gr_LST_01->SetNameTitle("gr_LST_01","gr_LST_01");
  gr_LST_02->SetNameTitle("gr_LST_02","gr_LST_02");
  gr_LST_03->SetNameTitle("gr_LST_03","gr_LST_03");
  gr_LST_04->SetNameTitle("gr_LST_04","gr_LST_04");
  gr_LST_01->SetMarkerColor(kBlack);
  gr_LST_02->SetMarkerColor(kRed+2);
  gr_LST_03->SetMarkerColor(kBlue+2);
  gr_LST_04->SetMarkerColor(kGreen+2);
  gr_LST_01->SetLineColor(kBlack);
  gr_LST_02->SetLineColor(kRed+2);
  gr_LST_03->SetLineColor(kBlue+2);
  gr_LST_04->SetLineColor(kGreen+2);
  gr_LST_01->SetLineWidth(3.0);
  gr_LST_02->SetLineWidth(3.0);
  gr_LST_03->SetLineWidth(3.0);
  gr_LST_04->SetLineWidth(3.0);
  //
  TGraph *gr_MAG_01 = new TGraph();
  TGraph *gr_MAG_02 = new TGraph();
  gr_MAG_01->SetNameTitle("gr_MAG_01","gr_MAG_01");
  gr_MAG_02->SetNameTitle("gr_MAG_02","gr_MAG_02");
  gr_MAG_01->SetMarkerColor(kMagenta+2);
  gr_MAG_02->SetMarkerColor(kViolet+2);
  gr_MAG_01->SetLineColor(kMagenta+2);
  gr_MAG_02->SetLineColor(kViolet+2);
  gr_MAG_01->SetLineWidth(3.0);
  gr_MAG_02->SetLineWidth(3.0);
  //
  TGraph *gr_frame = new TGraph();
  gr_frame->SetNameTitle("gr_frame","gr_frame");
  simulate_frame( xf, yf, lf, gr_frame);
  //
  Double_t x = 0.0;
  Double_t y = 0.0;
  //L-01
  for(Int_t i = 0;i<n;i++){
    simulate_tel_pos( -70.93, -52.07, 12.5, x, y);
    gr_LST_01->SetPoint(i,x,y);
  }
  //L-02
  for(Int_t i = 0;i<n;i++){
    simulate_tel_pos( -35.270, 66.140, 12.5, x, y);
    gr_LST_02->SetPoint(i,x,y);
  }
  //L-03
  for(Int_t i = 0;i<n;i++){
    simulate_tel_pos( 75.280, 50.490, 12.5, x, y);
    gr_LST_03->SetPoint(i,x,y);
  }
  //L-04
  for(Int_t i = 0;i<n;i++){
    simulate_tel_pos( 30.910, -64.540, 12.5, x, y);
    gr_LST_04->SetPoint(i,x,y);
  }

  //MAGIC-01
  for(Int_t i = 0;i<n;i++){
    simulate_tel_pos( -23.540, -191.750, 10.0, x, y);
    gr_MAG_01->SetPoint(i,x,y);
  }
  //MAGIC-02
  for(Int_t i = 0;i<n;i++){
    simulate_tel_pos(-94.050, -143.770, 10.0, x, y);
    gr_MAG_02->SetPoint(i,x,y);
  }
  
  //h1_1->Rebin(4);
  //h1_1->SetTitle("");

  TCanvas *c1 = new TCanvas("c1","c1",10,10,800,800);
  gStyle->SetPalette(1);
  gStyle->SetFrameBorderMode(0);
  gROOT->ForceStyle();
  gStyle->SetStatColor(kWhite);
  //gStyle->SetOptStat(kFALSE);  
  c1->SetRightMargin(0.01);
  c1->SetLeftMargin(0.08);
  c1->SetTopMargin(0.01);
  c1->SetBottomMargin(0.08);
  
  TMultiGraph *mg = new TMultiGraph();
  mg->Add(gr_LST_01);
  mg->Add(gr_LST_02);
  mg->Add(gr_LST_03);
  mg->Add(gr_LST_04);
  mg->Add(gr_MAG_01);
  mg->Add(gr_MAG_02);
  mg->Add(gr_frame);
  mg->Draw("ap");  
  mg->GetXaxis()->SetTitle("x, m");
  mg->GetYaxis()->SetTitle("y, m");

  TLegend *leg = new TLegend(0.6,0.6,0.9,0.9,"","brNDC");
  leg->AddEntry(gr_LST_01, "LST_01", "l");
  leg->AddEntry(gr_LST_02, "LST_02", "l");
  leg->AddEntry(gr_LST_03, "LST_03", "l");
  leg->AddEntry(gr_LST_04, "LST_04", "l");  
  leg->AddEntry(gr_MAG_01, "MAGIC-01", "l");
  leg->AddEntry(gr_MAG_02, "MAGIC-02", "l");  
  leg->Draw();

  return 0;
}

void simulate_tel_pos( Double_t x0, Double_t y0, Double_t R, Double_t &x, Double_t &y){
  Bool_t flag = false;
  while(!flag){
    x = rnd->Uniform(-R,R);
    y = rnd->Uniform(-R,R);
    if( (x*x + y*y)<=R*R)
      flag=true;
  }
  x=x+x0;
  y=y+y0;
}

void simulate_frame( Double_t xf, Double_t yf, Double_t lf, TGraph *gr){
  gr->SetPoint(0,xf,yf);
  gr->SetPoint(1,xf,yf+lf);
  gr->SetPoint(2,xf+lf,yf+lf);
  gr->SetPoint(3,xf+lf,yf);
}
