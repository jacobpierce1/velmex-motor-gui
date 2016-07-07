// author: jacob pierce, 2016
#include <TGClient.h>
#include <TGButton.h>
#include <TGFrame.h>
#include <string>
#include <iostream>

#include <stdio.h>
#include <stdlib.h>
#include <libserialport.h>
#include <stddef.h>
#include <unistd.h>
#include <cstdlib>

using namespace std; 

class MyMainFrame : public TGMainFrame {

private:
  TGVerticalFrame *controls;
  TGHorizontalFrame *contents;
  TGLabel *fLabelx, *fLabelY;
  TGTextButton     *fAbsmoveButton, *fRelmoveButton;
  TGTextEntry *fEntryXY;
  TGNumberEntry *fEntrySpeed, *fEntryRaster;

public:
  double xmaxnum = 7108;
  double ymaxnum = 7190; // verified using this program
  TEllipse *circle;
  TText *xylabel;
  MyMainFrame(const TGWindow *p, UInt_t w, UInt_t h);
   virtual ~MyMainFrame();
   // slots
  TCanvas *canvas;
  void Absmove();
  void Relmove();
  void MoveTo00();
  void RasterX();
  void RasterY();
  void Stop();
  void Calibrate();
  void move_motor(char *command);
  void get_motor_position();
  char *commandarray;

/* CONSTANTS */
  const double d_per_step = .0002500;  /* inches */
  const double in_per_cm = .3937;


   ClassDef(MyMainFrame, 0)
};

/* ----------------------------------------------------------------
-------------------------------------------------------------------
---------------------------MOVEMENT FUNCTIONS ---------------------
-------------------------------------------------------------------
---------------------------------------------------------------- */
void MyMainFrame::Absmove()
{
  puts("performing absmove");
  int speed = round(fEntrySpeed->GetNumber());
  string xy = fEntryXY->GetText();
 
  speedstr = to_string(speed);
  string xstr = xy.substr(0,xy.find(" "));
  string ystr = xy.substr(xy.find(" ")+1, xy.length());

  string command = "F,C,S1M" + speedstr + ",S2M" + speedstr + ",IA1M"+ xstr + ",IA2M" + ystr +  ",R";

  char *commandarray = const_cast<char*>(command.c_str());
  cout << commandarray << "\n";
 
  move_motor(commandarray);
  get_motor_position();
}

void MyMainFrame::Relmove()
{
  puts("performing relmove");
  int speed = round(fEntrySpeed->GetNumber());
  string xy = fEntryXY->GetText();
 
  speedstr = to_string(speed);
  string xstr = xy.substr(0,xy.find(" "));
  string ystr = xy.substr(xy.find(" ")+1, xy.length());

  string xmove;
  string ymove;
  if(xstr == '0') xmove = "";
  else xmove = ",I1M" + xstr;
  if(ystr == '0') ymove = "";
  else ymove = ",I2M" + ystr;

  string command;
  command = "E,C,S1M" + speedstr + ",S2M" + speedstr + xmove  + ",I2M" + ymove +  ",R";

  char *commandarray = const_cast<char*>(command.c_str());
  cout << commandarray << "\n";
  move_motor(commandarray);
  get_motor_position();
}

void MyMainFrame::MoveTo00()
{
  puts("moving to (0,0)");
  string command = "E,C,S1M2000,S2M2000,I1M-0,I2M-0,R";
  char *commandarray = const_cast<char*>(command.c_str());
  move_motor(commandarray);
  get_motor_position();
}

void MyMainFrame::RasterX()
{
  puts("performing raster x");

  int sweep_dist = round(fEntryRaster->GetNumber());
  string sweep_dist_str = to_string(sweep_dist);
  int speed = round(fEntrySpeed->GetNumber());
  speedstr = to_string(speed);
  string command = "E,C,S1M" + speedstr + ",S2M" + speedstr;
  
  for(a=1;a*sweep_dist<=3500;a++) {
    command += ",I1M0,I2M" + sweep_dist_str + ",I1M-0,I2M" + sweep_dist_str;
  }
  command += ",I1M0,R";

  char *commandarray = const_cast<char*>(command.c_str());
  cout << commandarray << "\n";
  move_motor(commandarray);
  get_motor_position();
}

void MyMainFrame::RasterY()
{
  puts("performingg raster y");

  int sweep_dist = round(fEntryRaster->GetNumber());
  string sweep_dist_str = to_string(sweep_dist);

  int speed = round(fEntrySpeed->GetNumber());
  speedstr = to_string(speed);
  string command = "E,C,S1M" + speedstr + ",S2M" + speedstr;

  for(a=1;a*sweep_dist<=3500;a++) {
    command += ",I2M0,I1M" + sweep_dist_str + ",I2M-0,I1M" + sweep_dist_str;
  }
  command += ",I2M0,R";

  char *commandarray = const_cast<char*>(command.c_str());
  cout << commandarray << "\n";
  move_motor(commandarray);
  get_motor_position();
}

void MyMainFrame::Calibrate()
{
  puts("calibrating");
  string command = "N";
  char *commandarray = const_cast<char*>(command.c_str());
  move_motor(commandarray);
}

void MyMainFrame::Stop()
{
  puts("stopping");
  string command = "K";
  char *commandarray = const_cast<char*>(command.c_str());
  move_motor(commandarray);
}

/* move the motor according to command */
void MyMainFrame:: move_motor(char *commandarray)
{
  struct sp_port **ports;

  sp_list_ports(&ports); 
  sp_open(ports[0], SP_MODE_WRITE);
 
  sp_blocking_write(ports[0], commandarray, strlen(commandarray)+1, 0);
  sp_drain(ports[0]);

  sp_close(ports[0]);
  sp_free_port_list(ports);
  return;
} 

/* get the x,y coordinates */
void MyMainFrame:: get_motor_position()
{
  int xfinal;
  int yfinal;
  struct sp_port **ports;
  while (true) {
    sp_list_ports(&ports); 
    sp_open(ports[0], SP_MODE_READ_WRITE);
 
    string x = "X";
    string y = "Y";
    char *xarray = const_cast<char*>(x.c_str());
    char *yarray = const_cast<char*>(y.c_str());
    char xcoord[20];
    char ycoord[20];

    sp_blocking_write(ports[0], xarray, strlen(xarray)+1, 0);
    sp_drain(ports[0]);
    sp_blocking_read(ports[0], &xcoord, 20, 100);

    sp_blocking_write(ports[0], yarray, strlen(yarray)+1, 0);
    sp_drain(ports[0]);
    sp_blocking_read(ports[0], &ycoord, 20, 100);

    string xstr;
    string ystr;
    xstr.assign(xcoord,20);
    ystr.assign(ycoord,20);
    int xnum = atoi(xstr.c_str());
    int ynum = atoi(ystr.c_str());

    circle->SetX1(xnum/xmaxnum);
    circle->SetY1(ynum/ymaxnum);
    // string xposition = to_string(round(xnum*d_per_step/in_per_cm * 1000));
    // string yposition = to_string(round(ynum*d_per_step/in_per_cm * 1000));
    string xposition = to_string(xnum);
    string yposition = to_string(ynum);
    string xystring = "(x,y) = (" + xposition + "," + yposition + ")";
    const char *xyarray = xystring.c_str();
    xylabel->SetTitle(xyarray);

    canvas->Modified();
    canvas->Update();


    if(xnum==xfinal && ynum==yfinal) break;
    else xfinal = xnum, yfinal = ynum;

    sp_close(ports[0]);
    sp_free_port_list(ports);
  }
  return;
} 





/* ----------------------------------------------------------------
-------------------------------------------------------------------
-----------------------CONSTRUCTING GUI ---------------------------
-------------------------------------------------------------------
---------------------------------------------------------------- */
MyMainFrame::MyMainFrame(const TGWindow *p, UInt_t w, UInt_t h) :
  TGMainFrame(p, w, h)
{
   // frame and canvas
   TCanvas *canvas = new TCanvas("canvas","canvas",250,250);
   this->canvas = canvas;
   gBenchmark->Start("canvas");
   
   TText *xylabel = new TText(0.5,.035,"x,y =");
   this->xylabel=xylabel;
   xylabel->SetTextAlign(22);
   xylabel->SetTextSize(.07);
   xylabel->Draw();

   TEllipse *circle = new TEllipse(.5, .5, .02, .02);
   this->circle = circle;
   circle->SetFillColor(6);
   circle->Draw();

   TGVerticalFrame *controls = new TGVerticalFrame(this);
   AddFrame(controls, new TGLayoutHints(kLHintsLeft | kLHintsTop, 5, 5, 5, 5));

   //text entry
   fLabelXY = new TGLabel(controls, "Enter x y:");
   controls->AddFrame(fLabelXY, new TGLayoutHints(kLHintsLeft, 5,5,5,5));
   fEntryXY = new TGTextEntry(controls);
   controls->AddFrame(fEntryXY, new TGLayoutHints(kLHintsExpandX, 5,5,5,5));

   fLabelSpeed = new TGLabel(controls, "Enter speed:");
   controls->AddFrame(fLabelSpeed, new TGLayoutHints(kLHintsLeft, 5,5,5,5));
   fEntrySpeed = new TGNumberEntry(controls, 2000);
   controls->AddFrame(fEntrySpeed, new TGLayoutHints(kLHintsExpandX, 5,5,5,5));

   fLabelRaster = new TGLabel(controls, "Enter raster spacing:");
   controls->AddFrame(fLabelRaster, new TGLayoutHints(kLHintsLeft, 5,5,5,5));
   fEntryRaster = new TGNumberEntry(controls, 1000);
   controls->AddFrame(fEntryRaster, new TGLayoutHints(kLHintsExpandX, 5,5,5,5));

   //abs move
   fAbsmoveButton = new TGTextButton(controls, "Absolute move");
   fAbsmoveButton->Connect("Clicked()", "MyMainFrame", this, "Absmove()");
   controls->AddFrame(fAbsmoveButton, new TGLayoutHints(kLHintsExpandX,
						       5,5,5,5));
   // rel move
   fRelmoveButton = new TGTextButton(controls, "Relative move");
   fRelmoveButton->Connect("Clicked()", "MyMainFrame", this, "Relmove()");
   controls->AddFrame(fRelmoveButton, new TGLayoutHints( kLHintsExpandX,
						       5,5,5,5));
   // rel move
   f00Button = new TGTextButton(controls, "Go to (0,0)");
   f00Button->Connect("Clicked()", "MyMainFrame", this, "MoveTo00()");
   controls->AddFrame(f00Button, new TGLayoutHints( kLHintsExpandX,
						       5,5,5,5));
   // raster x
   fRasterXButton = new TGTextButton(controls, "Raster X");
   fRasterXButton->Connect("Clicked()", "MyMainFrame", this, "RasterX()");
   controls->AddFrame(fRasterXButton, new TGLayoutHints( kLHintsExpandX,
						       5,5,5,5));
   // rel move
   fRasterYButton = new TGTextButton(controls, "Raster Y");
   fRasterYButton->Connect("Clicked()", "MyMainFrame", this, "RasterY()");
   controls->AddFrame(fRasterYButton, new TGLayoutHints( kLHintsExpandX,
						       5,5,5,5));
   // stop
   fStopButton = new TGTextButton(controls, "Stop");
   fStopButton->Connect("Clicked()", "MyMainFrame", this, "Stop()");
   controls->AddFrame(fStopButton, new TGLayoutHints( kLHintsExpandX,
						       5,5,5,5));  
   // calibrate
   fCalibrateButton = new TGTextButton(controls, "Calibrate");
   fCalibrateButton->Connect("Clicked()", "MyMainFrame", this, "Calibrate()");
   controls->AddFrame(fCalibrateButton, new TGLayoutHints( kLHintsExpandX,
						       5,5,5,5));
 
   // exit
   fExit = new TGTextButton(controls, "Exit", "gApplication->Terminate(0)");
   controls->AddFrame(fExit, new TGLayoutHints(kLHintsBottom | kLHintsLeft |
                                            kLHintsExpandX, 4, 4, 4, 4));

   SetWindowName("Motor Controller GUI");

   MapSubwindows();
   Resize(GetDefaultSize());
   MapWindow();
}


MyMainFrame::~MyMainFrame()
{
   // Clean up all widgets, frames and layouthints that were used
   controls->Cleanup();
   contents->Cleanup();
   Cleanup();
}


void gui2()
{
   // Popup the GUI...
   new MyMainFrame(gClient->GetRoot(), 350, 80);
}
