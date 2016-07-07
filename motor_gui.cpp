// Mainframe macro generated from application: /home/helix/root/bin/root.exe
// By ROOT version 6.06/04 on 2016-06-27 13:34:50

/* motor communication imports */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libserialport.h>
#include <stddef.h>
#include <unistd.h>

/* root graphics imports */
#include <TStyle.h>
#include <TCanvas.h>
#include <TF2.h>
#include <TTimer.h>
#include <TMath.h>

#ifndef ROOT_TGDockableFrame
#include "TGDockableFrame.h"
#endif
#ifndef ROOT_TGMenu
#include "TGMenu.h"
#endif
#ifndef ROOT_TGMdiDecorFrame
#include "TGMdiDecorFrame.h"
#endif
#ifndef ROOT_TG3DLine
#include "TG3DLine.h"
#endif
#ifndef ROOT_TGMdiFrame
#include "TGMdiFrame.h"
#endif
#ifndef ROOT_TGMdiMainFrame
#include "TGMdiMainFrame.h"
#endif
#ifndef ROOT_TGMdiMenu
#include "TGMdiMenu.h"
#endif
#ifndef ROOT_TGColorSelect
#include "TGColorSelect.h"
#endif
#ifndef ROOT_TGListBox
#include "TGListBox.h"
#endif
#ifndef ROOT_TGNumberEntry
#include "TGNumberEntry.h"
#endif
#ifndef ROOT_TGScrollBar
#include "TGScrollBar.h"
#endif
#ifndef ROOT_TGComboBox
#include "TGComboBox.h"
#endif
#ifndef ROOT_TGuiBldHintsEditor
#include "TGuiBldHintsEditor.h"
#endif
#ifndef ROOT_TGuiBldNameFrame
#include "TGuiBldNameFrame.h"
#endif
#ifndef ROOT_TGFrame
#include "TGFrame.h"
#endif
#ifndef ROOT_TGFileDialog
#include "TGFileDialog.h"
#endif
#ifndef ROOT_TGShutter
#include "TGShutter.h"
#endif
#ifndef ROOT_TGButtonGroup
#include "TGButtonGroup.h"
#endif
#ifndef ROOT_TGCanvas
#include "TGCanvas.h"
#endif
#ifndef ROOT_TGFSContainer
#include "TGFSContainer.h"
#endif
#ifndef ROOT_TGuiBldEditor
#include "TGuiBldEditor.h"
#endif
#ifndef ROOT_TGButton
#include "TGButton.h"
#endif
#ifndef ROOT_TGFSComboBox
#include "TGFSComboBox.h"
#endif
#ifndef ROOT_TGLabel
#include "TGLabel.h"
#endif
#ifndef ROOT_TGMsgBox
#include "TGMsgBox.h"
#endif
#ifndef ROOT_TRootGuiBuilder
#include "TRootGuiBuilder.h"
#endif
#ifndef ROOT_TGTab
#include "TGTab.h"
#endif
#ifndef ROOT_TGListView
#include "TGListView.h"
#endif
#ifndef ROOT_TGSplitter
#include "TGSplitter.h"
#endif
#ifndef ROOT_TGStatusBar
#include "TGStatusBar.h"
#endif
#ifndef ROOT_TGListTree
#include "TGListTree.h"
#endif
#ifndef ROOT_TGuiBldGeometryFrame
#include "TGuiBldGeometryFrame.h"
#endif
#ifndef ROOT_TGToolTip
#include "TGToolTip.h"
#endif
#ifndef ROOT_TGToolBar
#include "TGToolBar.h"
#endif
#ifndef ROOT_TGuiBldDragManager
#include "TGuiBldDragManager.h"
#endif

#include "Riostream.h"


/* motor communication preamble */
void setup();
void move_motor(char *vxm_command);
void getports();
void checkerror(int error);
void make_command(int mode);
void getxy(int mode);
int getmode();
void recalibrate();
void convert_to_steps();
void hysteresis();
void success();

/* CUSTOMIZEABLE PRESETS */
int xyrange[2] = {-100000, 100000};
int start_speed = 2500;

/* GLOBAL VARIABLES, DO NOT TOUCH */
int coords[2] = {0,0};
int scroll = 0;
char vxm_command[200];

/* CONSTANTS */
const float d_per_step = .0002500;  /* inches */
const float in_per_cm = .3937;





/* --------------------------------------------------------------
-----------------------------------------------------------------
-----------------------------------------------------------------
----------------------------GRAPHICS-----------------------------
-----------------------------------------------------------------
-------------------------------------------------------------- */

void motor_gui()
{
   // main frame
   TGMainFrame *fMainFrame1965 = new TGMainFrame(gClient->GetRoot(),10,10,kMainFrame | kVerticalFrame);
   fMainFrame1965->SetName("fMainFrame1965");
   fMainFrame1965->SetLayoutBroken(kTRUE);

   // composite frame
   TGCompositeFrame *fMainFrame1000 = new TGCompositeFrame(fMainFrame1965,1091,793,kVerticalFrame);
   fMainFrame1000->SetName("fMainFrame1000");
   fMainFrame1000->SetLayoutBroken(kTRUE);

   // composite frame
   TGCompositeFrame *fMainFrame1543 = new TGCompositeFrame(fMainFrame1000,995,726,kVerticalFrame);
   fMainFrame1543->SetName("fMainFrame1543");
   fMainFrame1543->SetLayoutBroken(kTRUE);

   // composite frame
   TGCompositeFrame *fMainFrame800 = new TGCompositeFrame(fMainFrame1543,983,672,kVerticalFrame);
   fMainFrame800->SetName("fMainFrame800");
   fMainFrame800->SetLayoutBroken(kTRUE);

   // composite frame
   TGCompositeFrame *fMainFrame1428 = new TGCompositeFrame(fMainFrame800,885,595,kVerticalFrame);
   fMainFrame1428->SetName("fMainFrame1428");
   fMainFrame1428->SetLayoutBroken(kTRUE);

   ULong_t ucolor;        // will reflect user color changes
   gClient->GetColorByName("#deba87",ucolor);

   // horizontal frame
   TGHorizontalFrame *fHorizontalFrame680 = new TGHorizontalFrame(fMainFrame1428,336,288,kHorizontalFrame,ucolor);
   fHorizontalFrame680->SetName("fHorizontalFrame680");
   fHorizontalFrame680->SetLayoutBroken(kTRUE);

   gClient->GetColorByName("#000000",ucolor);

   // vertical frame
   TGVerticalFrame *fVerticalFrame757 = new TGVerticalFrame(fHorizontalFrame680,88,64,kVerticalFrame,ucolor);
   fVerticalFrame757->SetName("fVerticalFrame757");
   fVerticalFrame757->SetLayoutBroken(kTRUE);

   gClient->GetColorByName("#ff0000",ucolor);

   // vertical frame
   TGVerticalFrame *fVerticalFrame812 = new TGVerticalFrame(fVerticalFrame757,16,16,kVerticalFrame,ucolor);
   fVerticalFrame812->SetName("fVerticalFrame812");
   fVerticalFrame812->SetLayoutBroken(kTRUE);

   fVerticalFrame757->AddFrame(fVerticalFrame812, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   fVerticalFrame812->MoveResize(32,16,16,16);

   fHorizontalFrame680->AddFrame(fVerticalFrame757, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   fVerticalFrame757->MoveResize(96,80,88,64);

   fMainFrame1428->AddFrame(fHorizontalFrame680, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   fHorizontalFrame680->MoveResize(368,88,336,288);

   TGLabel *fLabel1155 = new TGLabel(fMainFrame1428,"VELMEX MOTOR GUI",TGLabel::GetDefaultGC()(),TGLabel::GetDefaultFontStruct(),kChildFrame,ucolor);
   fLabel1155->SetTextJustify(36);
   fLabel1155->SetMargins(0,0,0,0);
   fLabel1155->SetWrapLength(-1);
   fMainFrame1428->AddFrame(fLabel1155, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   fLabel1155->MoveResize(384,32,256,32);

   TGLabel *fLabel1156 = new TGLabel(fMainFrame1428,"CONTROLS",TGLabel::GetDefaultGC()(),TGLabel::GetDefaultFontStruct(),kChildFrame,ucolor);
   fLabel1156->SetTextJustify(36);
   fLabel1156->SetMargins(0,0,0,0);
   fLabel1156->SetWrapLength(-1);
   fMainFrame1428->AddFrame(fLabel1156, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   fLabel1156->MoveResize(24,32,104,48);

   gClient->GetColorByName("#5954d9",ucolor);
   TGTextButton *fTextButton1157 = new TGTextButton(fMainFrame1428,"ABSOLUTE MOVE",-1,TGTextButton::GetDefaultGC()(),TGTextButton::GetDefaultFontStruct(),kRaisedFrame);
   fTextButton1157->SetTextJustify(36);
   fTextButton1157->SetMargins(0,0,0,0);
   fTextButton1157->SetWrapLength(-1);
   fTextButton1157->Resize(120,25);
   fTextButton1157->ChangeBackground(ucolor);
   fMainFrame1428->AddFrame(fTextButton1157, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   fTextButton1157->MoveResize(16,104,120,25);

   fTextButton1157->Connect("Clicked()", "fMainFrame1428", this, success());

   TGFont *ufont;         // will reflect user font changes
   ufont = gClient->GetFont("-*-helvetica-medium-r-*-*-12-*-*-*-*-*-iso8859-1");

   TGGC   *uGC;           // will reflect user GC changes
   // graphics context changes
   GCValues_t valButton1158;
   valButton1158.fMask = kGCForeground | kGCBackground | kGCFillStyle | kGCFont | kGCGraphicsExposures;
   gClient->GetColorByName("#000000",valButton1158.fForeground);
   gClient->GetColorByName("#e8e8e8",valButton1158.fBackground);
   valButton1158.fFillStyle = kFillSolid;
   valButton1158.fFont = ufont->GetFontHandle();
   valButton1158.fGraphicsExposures = kFALSE;
   uGC = gClient->GetGC(&valButton1158, kTRUE);

   TGTextButton *fTextButton1158 = new TGTextButton(fMainFrame1428,"RELATIVE MOVE",-1,uGC->GetGC(),ufont->GetFontStruct(),kRaisedFrame);
   fTextButton1158->SetTextJustify(36);
   fTextButton1158->SetMargins(0,0,0,0);
   fTextButton1158->SetWrapLength(-1);
   fTextButton1158->Resize(120,25);

   fTextButton1158->ChangeBackground(ucolor);
   fMainFrame1428->AddFrame(fTextButton1158, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   fTextButton1158->MoveResize(16,136,120,25);

   TGTextButton *fTextButton1159 = new TGTextButton(fMainFrame1428,"GO TO (0,0)",-1,TGTextButton::GetDefaultGC()(),TGTextButton::GetDefaultFontStruct(),kRaisedFrame);
   fTextButton1159->SetTextJustify(36);
   fTextButton1159->SetMargins(0,0,0,0);
   fTextButton1159->SetWrapLength(-1);
   fTextButton1159->Resize(120,32);

   fTextButton1159->ChangeBackground(ucolor);
   fMainFrame1428->AddFrame(fTextButton1159, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   fTextButton1159->MoveResize(16,160,120,32);

   TGTextButton *fTextButton1160 = new TGTextButton(fMainFrame1428,"RASTER X",-1,TGTextButton::GetDefaultGC()(),TGTextButton::GetDefaultFontStruct(),kRaisedFrame);
   fTextButton1160->SetTextJustify(36);
   fTextButton1160->SetMargins(0,0,0,0);
   fTextButton1160->SetWrapLength(-1);
   fTextButton1160->Resize(128,32);

   fTextButton1160->ChangeBackground(ucolor);
   fMainFrame1428->AddFrame(fTextButton1160, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   fTextButton1160->MoveResize(8,232,128,32);

   TGTextButton *fTextButton1161 = new TGTextButton(fMainFrame1428,"RASTER Y",-1,TGTextButton::GetDefaultGC()(),TGTextButton::GetDefaultFontStruct(),kRaisedFrame);
   fTextButton1161->SetTextJustify(36);
   fTextButton1161->SetMargins(0,0,0,0);
   fTextButton1161->SetWrapLength(-1);
   fTextButton1161->Resize(128,32);

   fTextButton1161->ChangeBackground(ucolor);
   fMainFrame1428->AddFrame(fTextButton1161, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   fTextButton1161->MoveResize(8,272,128,32);

   TGTextButton *fTextButton1162 = new TGTextButton(fMainFrame1428,"GO TO MIDDLE",-1,TGTextButton::GetDefaultGC()(),TGTextButton::GetDefaultFontStruct(),kRaisedFrame);
   fTextButton1162->SetTextJustify(36);
   fTextButton1162->SetMargins(0,0,0,0);
   fTextButton1162->SetWrapLength(-1);
   fTextButton1162->Resize(128,32);

   fTextButton1162->ChangeBackground(ucolor);
   fMainFrame1428->AddFrame(fTextButton1162, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   fTextButton1162->MoveResize(8,200,128,32);

   gClient->GetColorByName("#85c2a3",ucolor);
   TGLabel *fLabel1164 = new TGLabel(fMainFrame1428,"(X,Y) = ",TGLabel::GetDefaultGC()(),TGLabel::GetDefaultFontStruct(),kChildFrame,ucolor);
   fLabel1164->SetTextJustify(36);
   fLabel1164->SetMargins(0,0,0,0);
   fLabel1164->SetWrapLength(-1);
   fMainFrame1428->AddFrame(fLabel1164, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   fLabel1164->MoveResize(472,488,72,32);

 TGLabel *fCoordinates = new TGLabel(fMainFrame1428,"0,0",TGLabel::GetDefaultGC()(),TGLabel::GetDefaultFontStruct(),kChildFrame,ucolor);
   fCoordinates->SetTextJustify(36);
   fCoordinates->SetMargins(0,0,0,0);
   fCoordinates->SetWrapLength(-1);
   fMainFrame1428->AddFrame(fCoordinates, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   fCoordinates->MoveResize(560,488,50,32);


   TGLabel *fLabel1177 = new TGLabel(fMainFrame1428,"X, Y:",TGLabel::GetDefaultGC()(),TGLabel::GetDefaultFontStruct(),kChildFrame,ucolor);
   fLabel1177->SetTextJustify(36);
   fLabel1177->SetMargins(0,0,0,0);
   fLabel1177->SetWrapLength(-1);
   fMainFrame1428->AddFrame(fLabel1177, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   fLabel1177->MoveResize(176,104,80,24);

   TGLabel *fLabel1184 = new TGLabel(fMainFrame1428,"SPEED:",TGLabel::GetDefaultGC()(),TGLabel::GetDefaultFontStruct(),kChildFrame,ucolor);
   fLabel1184->SetTextJustify(36);
   fLabel1184->SetMargins(0,0,0,0);
   fLabel1184->SetWrapLength(-1);
   fMainFrame1428->AddFrame(fLabel1184, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   fLabel1184->MoveResize(176,128,80,19);

   TGLabel *fLabel1191 = new TGLabel(fMainFrame1428,"RASTER SPACE:",TGLabel::GetDefaultGC()(),TGLabel::GetDefaultFontStruct(),kChildFrame,ucolor);
   fLabel1191->SetTextJustify(36);
   fLabel1191->SetMargins(0,0,0,0);
   fLabel1191->SetWrapLength(-1);
   fMainFrame1428->AddFrame(fLabel1191, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   fLabel1191->MoveResize(152,144,104,32);

   ufont = gClient->GetFont("-*-helvetica-medium-r-*-*-12-*-*-*-*-*-iso8859-1");

   // graphics context changes
   GCValues_t valEntry1494;
   valEntry1494.fMask = kGCForeground | kGCBackground | kGCFillStyle | kGCFont | kGCGraphicsExposures;
   gClient->GetColorByName("#000000",valEntry1494.fForeground);
   gClient->GetColorByName("#e8e8e8",valEntry1494.fBackground);
   valEntry1494.fFillStyle = kFillSolid;
   valEntry1494.fFont = ufont->GetFontHandle();
   valEntry1494.fGraphicsExposures = kFALSE;
   uGC = gClient->GetGC(&valEntry1494, kTRUE);

   gClient->GetColorByName("#d4cf87",ucolor);
   TGTextEntry *fTextEntry1494 = new TGTextEntry(fMainFrame1428, new TGTextBuffer(14),-1,uGC->GetGC(),ufont->GetFontStruct(),kSunkenFrame | kOwnBackground,ucolor);
   fTextEntry1494->SetMaxLength(4096);
   fTextEntry1494->SetAlignment(kTextLeft);
   fTextEntry1494->SetText("0,0");
   fTextEntry1494->Resize(92,fTextEntry1494->GetDefaultHeight());
   fMainFrame1428->AddFrame(fTextEntry1494, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   fTextEntry1494->MoveResize(256,104,92,23);

   ufont = gClient->GetFont("-*-helvetica-medium-r-*-*-12-*-*-*-*-*-iso8859-1");

   // graphics context changes
   GCValues_t valEntry1539;
   valEntry1539.fMask = kGCForeground | kGCBackground | kGCFillStyle | kGCFont | kGCGraphicsExposures;
   gClient->GetColorByName("#000000",valEntry1539.fForeground);
   gClient->GetColorByName("#e8e8e8",valEntry1539.fBackground);
   valEntry1539.fFillStyle = kFillSolid;
   valEntry1539.fFont = ufont->GetFontHandle();
   valEntry1539.fGraphicsExposures = kFALSE;
   uGC = gClient->GetGC(&valEntry1539, kTRUE);

   TGTextEntry *fTextEntry1539 = new TGTextEntry(fMainFrame1428, new TGTextBuffer(14),-1,uGC->GetGC(),ufont->GetFontStruct(),kSunkenFrame | kOwnBackground,ucolor);
   fTextEntry1539->SetMaxLength(4096);
   fTextEntry1539->SetAlignment(kTextLeft);
   fTextEntry1539->SetText("2000");
   fTextEntry1539->Resize(92,fTextEntry1539->GetDefaultHeight());
   fMainFrame1428->AddFrame(fTextEntry1539, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   fTextEntry1539->MoveResize(256,128,92,23);

   ufont = gClient->GetFont("-*-helvetica-medium-r-*-*-12-*-*-*-*-*-iso8859-1");

   // graphics context changes
   GCValues_t valEntry1612;
   valEntry1612.fMask = kGCForeground | kGCBackground | kGCFillStyle | kGCFont | kGCGraphicsExposures;
   gClient->GetColorByName("#000000",valEntry1612.fForeground);
   gClient->GetColorByName("#e8e8e8",valEntry1612.fBackground);
   valEntry1612.fFillStyle = kFillSolid;
   valEntry1612.fFont = ufont->GetFontHandle();
   valEntry1612.fGraphicsExposures = kFALSE;
   uGC = gClient->GetGC(&valEntry1612, kTRUE);

   TGTextEntry *fTextEntry1612 = new TGTextEntry(fMainFrame1428, new TGTextBuffer(14),-1,uGC->GetGC(),ufont->GetFontStruct(),kSunkenFrame | kOwnBackground,ucolor);
   fTextEntry1612->SetMaxLength(4096);
   fTextEntry1612->SetAlignment(kTextLeft);
   fTextEntry1612->SetText("500");
   fTextEntry1612->Resize(92,fTextEntry1612->GetDefaultHeight());
   fMainFrame1428->AddFrame(fTextEntry1612, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   fTextEntry1612->MoveResize(256,152,92,23);

   fMainFrame800->AddFrame(fMainFrame1428, new TGLayoutHints(kLHintsExpandX | kLHintsExpandY));
   fMainFrame1428->MoveResize(0,0,885,595);

   fMainFrame1543->AddFrame(fMainFrame800, new TGLayoutHints(kLHintsExpandX | kLHintsExpandY));
   fMainFrame800->MoveResize(0,0,983,672);

   fMainFrame1000->AddFrame(fMainFrame1543, new TGLayoutHints(kLHintsExpandX | kLHintsExpandY));
   fMainFrame1543->MoveResize(0,0,995,726);

   fMainFrame1965->AddFrame(fMainFrame1000, new TGLayoutHints(kLHintsExpandX | kLHintsExpandY));
   fMainFrame1000->MoveResize(0,0,1091,793);

   fMainFrame1965->SetMWMHints(kMWMDecorAll,
                        kMWMFuncAll,
                        kMWMInputModeless);
   fMainFrame1965->MapSubwindows();

   fMainFrame1965->Resize(fMainFrame1965->GetDefaultSize());
   fMainFrame1965->MapWindow();
   fMainFrame1965->Resize(1166,800);
}  





/* --------------------------------------------------------------
-----------------------------------------------------------------
-----------------------------------------------------------------
----------------------------MOTOR CONTROL------------------------
-----------------------------------------------------------------
-------------------------------------------------------------- */











/* -----------------------------------------
   PORT INFORMATION AND DEBUGGING
   ----------------------------------------- */

/* view available ports */
void getports()
{   
  int i;
  struct sp_port **ports;

  sp_list_ports(&ports);

  for (i = 0; ports[i] != NULL; i++) {
    printf("Found port[%d]: '%s'.\n", i, sp_get_port_name(ports[i]));
    printf("Description:'%s' .\n", sp_get_port_description(ports[i]));
  }
  
  sp_free_port_list(ports);
  return;
}


/* for debugging, e.g. checkerror(sp_blocking_write( --- ) */
void checkerror(int error) {
  if(error == SP_OK) printf("no error \n");
  else if(error == SP_ERR_ARG) printf("invalid arugment\n");
  else if(error == SP_ERR_FAIL) printf("system error\n");
  else if(error == SP_ERR_MEM) printf("mem allocation failure\n");
  else if(error == SP_ERR_SUPP) printf("requested operation not supported\n");
  else printf("unknown error\n");
  return;
}

void success() {
  puts("success");
}
