//-------------------------------------------------
//
/**  \class DTTrackFinderConfig
 *
 *   L1 DT Track Finder ESProducer
 *
 *
 *
 *   J. Troconiz              UAM Madrid
 */
//
//--------------------------------------------------
#ifndef DTTrackFinderConfig_h
#define DTTrackFinderConfig_h

#include "FWCore/Framework/interface/ModuleFactory.h"
#include "FWCore/Framework/interface/ESProducer.h"

#include "FWCore/Framework/interface/ESHandle.h"

#include "CondFormats/L1TObjects/interface/L1MuDTExtLut.h"
#include "CondFormats/DataRecord/interface/L1MuDTExtLutRcd.h"
#include "CondFormats/L1TObjects/interface/L1MuDTPhiLut.h"
#include "CondFormats/DataRecord/interface/L1MuDTPhiLutRcd.h"
#include "CondFormats/L1TObjects/interface/L1MuDTPtaLut.h"
#include "CondFormats/DataRecord/interface/L1MuDTPtaLutRcd.h"
#include "CondFormats/L1TObjects/interface/L1MuDTEtaPatternLut.h"
#include "CondFormats/DataRecord/interface/L1MuDTEtaPatternLutRcd.h"
#include "CondFormats/L1TObjects/interface/L1MuDTQualPatternLut.h"
#include "CondFormats/DataRecord/interface/L1MuDTQualPatternLutRcd.h"
#include "CondFormats/L1TObjects/interface/L1MuDTTFParameters.h"
#include "CondFormats/DataRecord/interface/L1MuDTTFParametersRcd.h"
#include "CondFormats/L1TObjects/interface/L1MuDTTFMasks.h"
#include "CondFormats/DataRecord/interface/L1MuDTTFMasksRcd.h"

#include <memory>
#include <vector>


class DTTrackFinderConfig : public edm::ESProducer {
 public:

  DTTrackFinderConfig(const edm::ParameterSet&);

  ~DTTrackFinderConfig();
  
  std::unique_ptr<L1MuDTExtLut> produceL1MuDTExtLut(const L1MuDTExtLutRcd&);

  std::unique_ptr<L1MuDTPhiLut> produceL1MuDTPhiLut(const L1MuDTPhiLutRcd&);

  std::unique_ptr<L1MuDTPtaLut> produceL1MuDTPtaLut(const L1MuDTPtaLutRcd&);

  std::unique_ptr<L1MuDTEtaPatternLut> produceL1MuDTEtaPatternLut(const L1MuDTEtaPatternLutRcd&);

  std::unique_ptr<L1MuDTQualPatternLut> produceL1MuDTQualPatternLut(const L1MuDTQualPatternLutRcd&);

  std::unique_ptr<L1MuDTTFParameters> produceL1MuDTTFParameters(const L1MuDTTFParametersRcd&);

  std::unique_ptr<L1MuDTTFMasks> produceL1MuDTTFMasks(const L1MuDTTFMasksRcd&);

 private:

};

#endif
