#ifndef TriggerHelper_h
#define TriggerHelper_h

/** \class triggerhelper
 *
 *  No description available.
 *
 *  $Date: 2012/06/06 00:27:43 $
 *  $Revision: 1.3 $
 *  \author G. Ortona - LLR
 */


#include "FWCore/Framework/interface/Event.h"
#include "LLRHiggsTauTau/NtupleProducer/interface/triggerMapper.h"

#include <TString.h>
#include <string>
#include <vector>
#include <sstream>
#include <string>
#include <TH1F.h>

using namespace std;

class triggerhelper {
 public:
  triggerhelper(vector<string> HLTPaths);
  triggerhelper(TH1F* hCounter);
  triggerhelper();

  void addTriggerMap(string hlt,vector<string> path1, vector<string> path2, int channel);
  void addTriggerMap(string hlt,vector<string> path1, vector<string> path2, int leg1ID, int leg2ID);
  Long64_t FindTriggerBit(const edm::Event&, const vector<string>, const vector<int>, const edm::Handle<edm::TriggerResults>& triggerResults);
  int FindMETBit(const edm::Event&, edm::EDGetTokenT<edm::TriggerResults> metFilterBitsToken);
  
  int FindTriggerNumber(string triggername,bool istrigger=true); // calls the following according to istrigger
  int FindTriggerNumberMET(string triggername);
  int FindTriggerNumberTrig(string triggername);
  
  bool IsTriggerFired(Long64_t triggerbit, int triggerNumber,bool istrigger=true);
  
  bool IsTriggerFired(Long64_t triggerbit, string triggerName,bool istrigger=true){return IsTriggerFired(triggerbit, FindTriggerNumber(triggerName));}

  int printFiredPaths(Long64_t triggerbit,bool istrigger=true);
  int printFiredPathsMET(Long64_t triggerbit);
  int printFiredPathsTrig(Long64_t triggerbit);


  triggerMapper GetTriggerMap(string trigger);
  triggerMapper GetTriggerMap(int idx);
  int GetNTriggers(){return triggerlist.size();}
  string printTriggerName(int ntrigger);

  ~triggerhelper();

 private:
  //const int nTriggers;
  vector<string> triggerlist;
  vector<triggerMapper> triggerMap;
  static const int nMETs =6;
  string metlist[nMETs];

};
#endif
