
"use strict";

let NavTIMEGPS = require('./NavTIMEGPS.js');
let NavATT = require('./NavATT.js');
let CfgUSB = require('./CfgUSB.js');
let CfgRATE = require('./CfgRATE.js');
let MonGNSS = require('./MonGNSS.js');
let CfgRST = require('./CfgRST.js');
let CfgNMEA6 = require('./CfgNMEA6.js');
let NavDOP = require('./NavDOP.js');
let CfgHNR = require('./CfgHNR.js');
let RxmSFRB = require('./RxmSFRB.js');
let NavPVT7 = require('./NavPVT7.js');
let RxmRAW = require('./RxmRAW.js');
let NavSTATUS = require('./NavSTATUS.js');
let CfgNAV5 = require('./CfgNAV5.js');
let NavVELECEF = require('./NavVELECEF.js');
let RxmEPH = require('./RxmEPH.js');
let CfgCFG = require('./CfgCFG.js');
let EsfSTATUS_Sens = require('./EsfSTATUS_Sens.js');
let MonVER = require('./MonVER.js');
let RxmSVSI_SV = require('./RxmSVSI_SV.js');
let AidALM = require('./AidALM.js');
let TimTM2 = require('./TimTM2.js');
let NavSBAS_SV = require('./NavSBAS_SV.js');
let MonHW6 = require('./MonHW6.js');
let RxmRTCM = require('./RxmRTCM.js');
let CfgNMEA7 = require('./CfgNMEA7.js');
let RxmRAW_SV = require('./RxmRAW_SV.js');
let NavSAT = require('./NavSAT.js');
let AidEPH = require('./AidEPH.js');
let CfgSBAS = require('./CfgSBAS.js');
let MgaGAL = require('./MgaGAL.js');
let RxmALM = require('./RxmALM.js');
let CfgMSG = require('./CfgMSG.js');
let MonVER_Extension = require('./MonVER_Extension.js');
let NavPVT = require('./NavPVT.js');
let NavSVINFO = require('./NavSVINFO.js');
let RxmSFRBX = require('./RxmSFRBX.js');
let NavDGPS_SV = require('./NavDGPS_SV.js');
let RxmRAWX = require('./RxmRAWX.js');
let UpdSOS_Ack = require('./UpdSOS_Ack.js');
let Ack = require('./Ack.js');
let NavSBAS = require('./NavSBAS.js');
let NavDGPS = require('./NavDGPS.js');
let HnrPVT = require('./HnrPVT.js');
let CfgTMODE3 = require('./CfgTMODE3.js');
let CfgGNSS_Block = require('./CfgGNSS_Block.js');
let EsfSTATUS = require('./EsfSTATUS.js');
let CfgDGNSS = require('./CfgDGNSS.js');
let CfgPRT = require('./CfgPRT.js');
let NavRELPOSNED = require('./NavRELPOSNED.js');
let AidHUI = require('./AidHUI.js');
let NavCLOCK = require('./NavCLOCK.js');
let CfgDAT = require('./CfgDAT.js');
let EsfRAW_Block = require('./EsfRAW_Block.js');
let NavTIMEUTC = require('./NavTIMEUTC.js');
let EsfINS = require('./EsfINS.js');
let NavVELNED = require('./NavVELNED.js');
let NavPOSLLH = require('./NavPOSLLH.js');
let EsfRAW = require('./EsfRAW.js');
let RxmSVSI = require('./RxmSVSI.js');
let MonHW = require('./MonHW.js');
let NavSVINFO_SV = require('./NavSVINFO_SV.js');
let NavSAT_SV = require('./NavSAT_SV.js');
let UpdSOS = require('./UpdSOS.js');
let NavSOL = require('./NavSOL.js');
let RxmRAWX_Meas = require('./RxmRAWX_Meas.js');
let CfgGNSS = require('./CfgGNSS.js');
let CfgINF_Block = require('./CfgINF_Block.js');
let EsfMEAS = require('./EsfMEAS.js');
let NavRELPOSNED9 = require('./NavRELPOSNED9.js');
let CfgANT = require('./CfgANT.js');
let CfgINF = require('./CfgINF.js');
let CfgNAVX5 = require('./CfgNAVX5.js');
let NavPOSECEF = require('./NavPOSECEF.js');
let NavSVIN = require('./NavSVIN.js');
let Inf = require('./Inf.js');
let CfgNMEA = require('./CfgNMEA.js');

module.exports = {
  NavTIMEGPS: NavTIMEGPS,
  NavATT: NavATT,
  CfgUSB: CfgUSB,
  CfgRATE: CfgRATE,
  MonGNSS: MonGNSS,
  CfgRST: CfgRST,
  CfgNMEA6: CfgNMEA6,
  NavDOP: NavDOP,
  CfgHNR: CfgHNR,
  RxmSFRB: RxmSFRB,
  NavPVT7: NavPVT7,
  RxmRAW: RxmRAW,
  NavSTATUS: NavSTATUS,
  CfgNAV5: CfgNAV5,
  NavVELECEF: NavVELECEF,
  RxmEPH: RxmEPH,
  CfgCFG: CfgCFG,
  EsfSTATUS_Sens: EsfSTATUS_Sens,
  MonVER: MonVER,
  RxmSVSI_SV: RxmSVSI_SV,
  AidALM: AidALM,
  TimTM2: TimTM2,
  NavSBAS_SV: NavSBAS_SV,
  MonHW6: MonHW6,
  RxmRTCM: RxmRTCM,
  CfgNMEA7: CfgNMEA7,
  RxmRAW_SV: RxmRAW_SV,
  NavSAT: NavSAT,
  AidEPH: AidEPH,
  CfgSBAS: CfgSBAS,
  MgaGAL: MgaGAL,
  RxmALM: RxmALM,
  CfgMSG: CfgMSG,
  MonVER_Extension: MonVER_Extension,
  NavPVT: NavPVT,
  NavSVINFO: NavSVINFO,
  RxmSFRBX: RxmSFRBX,
  NavDGPS_SV: NavDGPS_SV,
  RxmRAWX: RxmRAWX,
  UpdSOS_Ack: UpdSOS_Ack,
  Ack: Ack,
  NavSBAS: NavSBAS,
  NavDGPS: NavDGPS,
  HnrPVT: HnrPVT,
  CfgTMODE3: CfgTMODE3,
  CfgGNSS_Block: CfgGNSS_Block,
  EsfSTATUS: EsfSTATUS,
  CfgDGNSS: CfgDGNSS,
  CfgPRT: CfgPRT,
  NavRELPOSNED: NavRELPOSNED,
  AidHUI: AidHUI,
  NavCLOCK: NavCLOCK,
  CfgDAT: CfgDAT,
  EsfRAW_Block: EsfRAW_Block,
  NavTIMEUTC: NavTIMEUTC,
  EsfINS: EsfINS,
  NavVELNED: NavVELNED,
  NavPOSLLH: NavPOSLLH,
  EsfRAW: EsfRAW,
  RxmSVSI: RxmSVSI,
  MonHW: MonHW,
  NavSVINFO_SV: NavSVINFO_SV,
  NavSAT_SV: NavSAT_SV,
  UpdSOS: UpdSOS,
  NavSOL: NavSOL,
  RxmRAWX_Meas: RxmRAWX_Meas,
  CfgGNSS: CfgGNSS,
  CfgINF_Block: CfgINF_Block,
  EsfMEAS: EsfMEAS,
  NavRELPOSNED9: NavRELPOSNED9,
  CfgANT: CfgANT,
  CfgINF: CfgINF,
  CfgNAVX5: CfgNAVX5,
  NavPOSECEF: NavPOSECEF,
  NavSVIN: NavSVIN,
  Inf: Inf,
  CfgNMEA: CfgNMEA,
};
