Double_t get_alpha(Double_t R, Double_t H, Double_t hh, Double_t theta_deg);

Int_t alpha(){
  //
  TGraph *gr_alpha = new TGraph();
  gr_alpha->SetMarkerStyle(20);
  gr_alpha->SetMarkerColor(kBlack);
  //
  Double_t hh = 20;    //m
  Double_t theta = 20; //deg
  Double_t R = 200;    //m
  //
  Int_t nn = 1000;
  //
  Double_t H;
  Double_t alpha;
  //
  Double_t H_min = 100;   //m
  Double_t H_max = 20000; //m
  //
  for(Int_t i = 0;i<nn;i++){
    H = H_min + (H_max - H_min)/(nn-1)*i;
    alpha=get_alpha(R,H,hh,theta);
    gr_alpha->SetPoint(i,H,alpha);
  }
  //
  TCanvas *c1 = new TCanvas("c1","c1",10,10,1000,1000);
  gStyle->SetPalette(1);
  gStyle->SetFrameBorderMode(0);
  gROOT->ForceStyle();
  gStyle->SetStatColor(kWhite);
  gStyle->SetOptStat(kFALSE);
  gPad->SetGridx();
  gPad->SetGridy();
  //
  c1->SetRightMargin(0.01);
  c1->SetLeftMargin(0.05);
  c1->SetTopMargin(0.01);
  c1->SetBottomMargin(0.05);
  //
  gr_alpha->Draw("APL");
  //
  return 0;
}

Double_t get_alpha(Double_t R, Double_t H, Double_t hh, Double_t theta_deg){
  Double_t theta = theta_deg*TMath::Pi()/180.0;
  Double_t l = (H-hh)/TMath::Sin(theta);
  Double_t LL = l+R/TMath::Tan(theta);
  return TMath::ATan(R/LL)/TMath::Pi()*180.0; 
}
