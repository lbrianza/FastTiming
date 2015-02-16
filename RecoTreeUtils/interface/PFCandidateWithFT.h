#ifndef PFCandidateWithFT_H
#define PFCandidateWithFT_H

#include <vector>

#include "TMath.h"

#include "DataFormats/EcalRecHit/interface/EcalRecHit.h"
#include "DataFormats/ParticleFlowCandidate/interface/PFCandidate.h"
#include "DataFormats/ParticleFlowReco/interface/PFRecTrack.h"
#include "DataFormats/ParticleFlowReco/interface/PFCluster.h"
#include "DataFormats/ParticleFlowReco/interface/PFBlock.h"
#include "DataFormats/ParticleFlowReco/interface/PFBlockElement.h"

#include "FastTiming/RecoTreeUtils/interface/Utils.h"

using namespace std;

//****************************************************************************************
class PFCandidateWithFT: public reco::PFCandidate
{
public:
    //---ctors---
    PFCandidateWithFT();
    PFCandidateWithFT(const reco::PFCandidate* PFCand, vector<EcalRecHit>* ecalRecHits,
                      float vxtTime=0);
    //---dtor---
    ~PFCandidateWithFT();
    //---getters---
    inline float GetTime() {return time_;};
    inline const reco::PFCluster* GetPFCluster() {return pfCluster_;};
    inline const reco::PFCandidate* GetPFCandidate() {return pfCand_;};
    pair<float, float> GetRecHitTimeE(DetId id);
    pair<float, float> GetRecHitTimeMaxE() {return GetRecHitTimeE(ecalSeed_);};
    vector<pair<float, float> > GetRecHitsTimeE();
    
private:
    const reco::PFCandidate* pfCand_;
    const reco::PFCluster*   pfCluster_;
    vector<EcalRecHit>       recHitColl_;
    DetId                    ecalSeed_;
    float                    clusterE_;
    float                    maxRecHitE_;
    float                    time_;
    float                    vtxTime_;
};

#endif
