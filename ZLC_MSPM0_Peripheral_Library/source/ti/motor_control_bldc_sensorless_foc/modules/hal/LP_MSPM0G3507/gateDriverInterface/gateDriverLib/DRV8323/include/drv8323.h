/* --COPYRIGHT--,TI
 *MSP Source and Object Code Software License Agreement
 **IMPORTANT - PLEASE CAREFULLY READ THE FOLLOWING LICENSE AGREEMENT, WHICH IS LEGALLY BINDING.  AFTER YOU READ IT, YOU WILL BE ASKED WHETHER YOU ACCEPT AND AGREE TO ITS TERMS.  DO NOT CLICK  "I ACCEPT" UNLESS: (1) YOU WILL USE THE LICENSED MATERIALS FOR YOUR OWN BENEFIT AND PERSONALLY ACCEPT, AGREE TO AND INTEND TO BE BOUND BY THESE TERMS; OR (2) YOU ARE AUTHORIZED TO, AND INTEND TO BE BOUND BY, THESE TERMS ON BEHALF OF YOUR COMPANY.
 **Important - Read carefully: This Source and Object Code Software License Agreement ("Agreement") is a legal agreement between you and Texas Instruments Incorporated ("TI").  In this Agreement "you" means you personally if you will exercise the rights granted for your own benefit, but it means your company (or you on behalf of your company) if you will exercise the rights granted for your company's benefit.  The "Licensed Materials" subject to this Agreement include the software programs and any associated electronic documentation (in each case, in whole or in part) that accompany this Agreement, are set forth in the applicable software manifest and you access "on-line", as well as any updates or upgrades to such software programs or documentation, if any, provided to you at TI's sole discretion.  The Licensed Materials are specifically designed and licensed for use solely and exclusively with MSP microcontroller devices manufactured by or for TI ("TI Devices").  By installing, copying or otherwise using the Licensed Materials you agree to abide by the provisions set forth herein.  This Agreement is displayed for you to read prior to using the Licensed Materials.  If you choose not to accept or agree with these provisions, do not download or install the Licensed Materials.
 **Note Regarding Possible Access to Other Licensed Materials:  The Licensed Materials may be bundled with software and associated electronic documentation, if any, licensed under terms other than the terms of this Agreement (in whole or in part, "Other Licensed Materials"), including, for example Open Source Software and/or TI-owned or third party Proprietary Software licensed under such other terms.  "Open Source Software" means any software licensed under terms requiring that (A) other software ("Proprietary Software") incorporated, combined or distributed with such software or developed using such software: (i) be disclosed or distributed in source code form; or (ii) otherwise be licensed on terms inconsistent with the terms of this Agreement, including but not limited to permitting use of the Proprietary Software on or with devices other than TI Devices, or (B) require the owner of Proprietary Software to license any of its patents to users of the Open Source Software and/or Proprietary Software incorporated, combined or distributed with such Open Source Software or developed using such Open Source Software.
 **If by accepting this Agreement, you gain access to Other Licensed Materials, they will be listed in the applicable software manifest.  Your use of the Other Licensed Materials is subject to the applicable other licensing terms acknowledgements and disclaimers as specified in the applicable software manifest and/or identified or included with the Other Licensed Materials in the software bundle.  For clarification, this Agreement does not limit your rights under, or grant you rights that supersede, the terms of any applicable Other Licensed Materials license agreement.  If any of the Other Licensed Materials is Open Source Software that has been provided to you in object code only under terms that obligate TI to provide to you or show you where you can access the source code versions of such Open Source Software, TI will provide to you, or show you where you can access, such source code if you contact TI at Texas Instruments Incorporated, 12500 TI Boulevard, Mail Station 8638, Dallas, Texas 75243, Attention: Contracts Manager, Embedded Processing.  In the event you choose not to accept or agree with the terms in any applicable Other Licensed Materials license agreement, you must terminate this Agreement.
 **1.    License Grant and Use Restrictions.
 **a.    Licensed Materials License Grant.  Subject to the terms of this Agreement, TI hereby grants to you a limited, non-transferable, non-exclusive, non-assignable, non-sublicensable, fully paid-up and royalty-free license to:
 *            i.    Limited Source Code License:  make copies, prepare derivative works, display internally and use internally the Licensed Materials provided to you in source code for the sole purpose of developing object and executable versions of such Licensed Materials, or any derivative thereof, that execute solely and exclusively on TI Devices, for end use in Licensee Products, and maintaining and supporting such Licensed Materials, or any derivative thereof, and Licensee Products.  For purposes of this Agreement, "Licensee Product" means a product that consists of both hardware, including one or more TI Devices, and software components, including only executable versions of the Licensed Materials that execute solely and exclusively on such TI Devices.
 *            ii.    Object Code Evaluation, Testing and Use License:  make copies, display internally, distribute internally and use internally the Licensed Materials in object code for the sole purposes of evaluating and testing the Licensed Materials and designing and developing Licensee Products, and maintaining and supporting the Licensee Products;
 *            iii.    Demonstration License:  demonstrate to third parties the Licensed Materials executing solely and exclusively on TI Devices as they are used in Licensee Products, provided that such Licensed Materials are demonstrated in object or executable versions only and
 *        iv.    Production and Distribution License:  make, use, import, export and otherwise distribute the Licensed Materials as part of a Licensee Product, provided that such Licensee Products include only embedded executable copies of such Licensed Materials that execute solely and exclusively on TI Devices.
 *    b.    Contractors.  The licenses granted to you hereunder shall include your on-site and off-site contractors (either an individual or entity), while such contractors are performing work for or providing services to you, provided that such contractors have executed work-for-hire agreements with you containing applicable terms and conditions consistent with the terms and conditions set forth in this Agreement and provided further that you shall be liable to TI for any breach by your contractors of this Agreement to the same extent as you would be if you had breached the Agreement yourself.
 *    c.    No Other License.  Nothing in this Agreement shall be construed as a license to any intellectual property rights of TI other than those rights embodied in the Licensed Materials provided to you by TI.  EXCEPT AS PROVIDED HEREIN, NO OTHER LICENSE, EXPRESS OR IMPLIED, BY ESTOPPEL OR OTHERWISE, TO ANY OTHER TI INTELLECTUAL PROPERTY RIGHTS IS GRANTED HEREIN.
 *    d.    Covenant not to Sue.  During the term of this Agreement, you agree not to assert a claim against TI or its licensees that the Licensed Materials infringe your intellectual property rights.
 *    e.    Restrictions.  You shall maintain the source code versions of the Licensed Materials under password control protection and shall not disclose such source code versions of the Licensed Materials, to any person other than your employees and contractors whose job performance requires access.  You shall not use the Licensed Materials with a processing device other than a TI Device, and you agree that any such unauthorized use of the Licensed Materials is a material breach of this Agreement.  You shall not use the Licensed Materials for the purpose of analyzing or proving infringement of any of your patents by either TI or TI's customers.  Except as expressly provided in this Agreement, you shall not copy, publish, disclose, display, provide, transfer or make available the Licensed Materials to any third party and you shall not sublicense, transfer, or assign the Licensed Materials or your rights under this Agreement to any third party.  You shall not mortgage, pledge or encumber the Licensed Materials in any way.  You may use the Licensed Materials with Open Source Software or with software developed using Open Source Software tools provided you do not incorporate, combine or distribute the Licensed Materials in a manner that subjects the Licensed Materials to any license obligations or any other intellectual property related terms of any license governing such Open Source Software.
 *    f.    Termination.  This Agreement is effective on the date the Licensed Materials are delivered to you together with this Agreement and will remain in full force and effect until terminated.  You may terminate this Agreement at any time by written notice to TI.  Without prejudice to any other rights, if you fail to comply with the terms of this Agreement or you are acquired, TI may terminate your right to use the Licensed Materials upon written notice to you.  Upon termination of this Agreement, you will destroy any and all copies of the Licensed Materials in your possession, custody or control and provide to TI a written statement signed by your authorized representative certifying such destruction. Except for Sections 1(a), 1(b) and 1(d), all provisions of this Agreement shall survive termination of this Agreement.
 **2.    Licensed Materials Ownership.  The Licensed Materials are licensed, not sold to you, and can only be used in accordance with the terms of this Agreement.  Subject to the licenses granted to you pursuant to this Agreement, TI and its licensors own and shall continue to own all right, title and interest in and to the Licensed Materials, including all copies thereof.  You agree that all fixes, modifications and improvements to the Licensed Materials conceived of or made by TI that are based, either in whole or in part, on your feedback, suggestions or recommendations are the exclusive property of TI and all right, title and interest in and to such fixes, modifications or improvements to the Licensed Materials will vest solely in TI.  Moreover, you acknowledge and agree that when your independently developed software or hardware components are combined, in whole or in part, with the Licensed Materials, your right to use the combined work that includes the Licensed Materials remains subject to the terms and conditions of this Agreement.
 **3.    Intellectual Property Rights.
 *    a.    The Licensed Materials contain copyrighted material, trade secrets and other proprietary information of TI and its licensors and are protected by copyright laws, international copyright treaties, and trade secret laws, as well as other intellectual property laws.  To protect TI's and its licensors' rights in the Licensed Materials, you agree, except as specifically permitted by statute by a provision that cannot be waived by contract, not to "unlock", decompile, reverse engineer, disassemble or otherwise translate to a human-perceivable form any portions of the Licensed Materials provided to you in object code format only, nor permit any person or entity to do so.  You shall not remove, alter, cover, or obscure any confidentiality, trade secret, trade mark, patent, copyright or other proprietary notice or other identifying marks or designs from any component of the Licensed Materials and you shall reproduce and include in all copies of the Licensed Materials the copyright notice(s) and proprietary legend(s) of TI and its licensors as they appear in the Licensed Materials.  TI reserves all rights not specifically granted under this Agreement.
 *    b.    Certain Licensed Materials may be based on industry recognized standards or software programs published by industry recognized standards bodies and certain third parties may claim to own patents, copyrights, and other intellectual property rights that cover implementation of those standards.  You acknowledge and agree that this Agreement does not convey a license to any such third party patents, copyrights, and other intellectual property rights and that you are solely responsible for any patent, copyright, or other intellectual property right claim that relates to your use or distribution of the Licensed Materials or your use or distribution of your products that include or incorporate the Licensed Materials.  Moreover, you acknowledge that you are responsible for any fees or royalties that may be payable to any third party based on such third party's interests in the Licensed Materials or any intellectual property rights that cover implementation of any industry recognized standard, any software program published by any industry recognized standards bodies or any other proprietary technology.
 **4.    Confidential Information.  You acknowledge and agree that the Licensed Materials contain trade secrets and other confidential information of TI and its licensors.  You agree to use the Licensed Materials solely within the scope of the licenses set forth herein, to maintain the Licensed Materials in strict confidence, to use at least the same procedures and degree of care that you use to prevent disclosure of your own confidential information of like importance but in no instance less than reasonable care, and to prevent disclosure of the Licensed Materials to any third party, except as may be necessary and required in connection with your rights and obligations hereunder; provided, however, that you may not provide the Licensed Materials to any business organization or group within your company or to customers or contractors that design or manufacture semiconductors unless TI gives written consent.  You agree to obtain executed confidentiality agreements with your employees and contractors having access to the Licensed Materials and to diligently take steps to enforce such agreements in this respect.  TI may disclose your contact information to TI's licensors.
 **5.    Warranties and Limitations.  THE LICENSED MATERIALS ARE PROVIDED "AS IS".  FURTHERMORE, YOU ACKNOWLEDGE AND AGREE THAT THE LICENSED MATERIALS HAVE NOT BEEN TESTED OR CERTIFIED BY ANY GOVERNMENT AGENCY OR INDUSTRY REGULATORY ORGANIZATION OR ANY OTHER THIRD PARTY ORGANIZATION.  YOU AGREE THAT PRIOR TO USING, INCORPORATING OR DISTRIBUTING THE LICENSED MATERIALS IN OR WITH ANY COMMERCIAL PRODUCT THAT YOU WILL THOROUGHLY TEST THE PRODUCT AND THE FUNCTIONALITY OF THE LICENSED MATERIALS IN OR WITH THAT PRODUCT AND BE SOLELY RESPONSIBLE FOR ANY PROBLEMS OR FAILURES.
 **TI AND ITS LICENSORS MAKE NO WARRANTY OR REPRESENTATION, EITHER EXPRESS, IMPLIED OR STATUTORY, REGARDING THE LICENSED MATERIALS, INCLUDING BUT NOT LIMITED TO ANY IMPLIED WARRANTIES OF MERCHANTABILITY OR FITNESS FOR A PARTICULAR PURPOSE OR NON-INFRINGEMENT OF ANY THIRD PARTY PATENTS, COPYRIGHTS, TRADE SECRETS OR OTHER INTELLECTUAL PROPERTY RIGHTS.  YOU AGREE TO USE YOUR INDEPENDENT JUDGMENT IN DEVELOPING YOUR PRODUCTS.  NOTHING CONTAINED IN THIS AGREEMENT WILL BE CONSTRUED AS A WARRANTY OR REPRESENTATION BY TI TO MAINTAIN PRODUCTION OF ANY TI SEMICONDUCTOR DEVICE OR OTHER HARDWARE OR SOFTWARE WITH WHICH THE LICENSED MATERIALS MAY BE USED.
 **IN NO EVENT SHALL TI OR ITS LICENSORS, BE LIABLE FOR ANY SPECIAL, INDIRECT, INCIDENTAL, PUNITIVE OR CONSEQUENTIAL DAMAGES, HOWEVER CAUSED, ON ANY THEORY OF LIABILITY, IN CONNECTION WITH OR ARISING OUT OF THIS AGREEMENT OR THE USE OF THE LICENSED MATERIALS REGARDLESS OF WHETHER TI HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.  EXCLUDED DAMAGES INCLUDE, BUT ARE NOT LIMITED TO, COST OF REMOVAL OR REINSTALLATION, OUTSIDE COMPUTER TIME, LABOR COSTS, LOSS OF DATA, LOSS OF GOODWILL, LOSS OF PROFITS, LOSS OF SAVINGS, OR LOSS OF USE OR INTERRUPTION OF BUSINESS.  IN NO EVENT WILL TI'S OR ITS LICENSORS' AGGREGATE LIABILITY UNDER THIS AGREEMENT OR ARISING OUT OF YOUR USE OF THE LICENSED MATERIALS EXCEED FIVE HUNDRED U.S. DOLLARS (US$500).
 *    Because some jurisdictions do not allow the exclusion or limitation of incidental or consequential damages or limitation on how long an implied warranty lasts, the above limitations or exclusions may not apply to you.
 **6.    Indemnification Disclaimer.  YOU ACKNOWLEDGE AND AGREE THAT TI SHALL NOT BE LIABLE FOR AND SHALL NOT DEFEND OR INDEMNIFY YOU AGAINST ANY THIRD PARTY INFRINGEMENT CLAIM THAT RELATES TO OR IS BASED ON YOUR MANUFACTURE, USE, OR DISTRIBUTION OF THE LICENSED MATERIALS OR YOUR MANUFACTURE, USE, OFFER FOR SALE, SALE, IMPORTATION OR DISTRIBUTION OF YOUR PRODUCTS THAT INCLUDE OR INCORPORATE THE LICENSED MATERIALS.
 **7.    No Technical Support.  TI and its licensors are under no obligation to install, maintain or support the Licensed Materials.
 **8.    Notices.  All notices to TI hereunder shall be delivered to Texas Instruments Incorporated, 12500 TI Boulevard, Mail Station 8638, Dallas, Texas 75243, Attention: Contracts Manager - Embedded Processing, with a copy to Texas Instruments Incorporated, 13588 N. Central Expressway, Mail Station 3999, Dallas, Texas 75243, Attention: Law Department - Embedded Processing.  All notices shall be deemed served when received by TI.
 **9.    Export Control.  The Licensed Materials are subject to export control under the U.S. Commerce Department's Export Administration Regulations ("EAR").  Unless prior authorization is obtained from the U.S. Commerce Department, neither you nor your subsidiaries shall export, re-export, or release, directly or indirectly (including, without limitation, by permitting the Licensed Materials to be downloaded), any technology, software, or software source code, received from TI, or export, directly or indirectly, any direct product of such technology, software, or software source code, to any person, destination or country to which the export, re-export, or release of the technology, software, or software source code, or direct product is prohibited by the EAR.  You represent and warrant that you (i) are not located in, or under the control of, a national or resident of Cuba, Iran, North Korea, Sudan and Syria or any other country subject to a U.S. goods embargo; (ii) are not on the U.S. Treasury Department's List of Specially Designated Nationals or the U.S. Commerce Department's Denied Persons List or Entity List; and (iii) will not use the Licensed Materials or transfer the Licensed Materials for use in any military, nuclear, chemical or biological weapons, or missile technology end-uses.  Any software export classification made by TI shall not be construed as a representation or warranty regarding the proper export classification for such software or whether an export license or other documentation is required for the exportation of such software.
 **10.    Governing Law and Severability; Waiver.  This Agreement will be governed by and interpreted in accordance with the laws of the State of Texas, without reference to conflict of laws principles.  If for any reason a court of competent jurisdiction finds any provision of the Agreement to be unenforceable, that provision will be enforced to the maximum extent possible to effectuate the intent of the parties, and the remainder of the Agreement shall continue in full force and effect.  This Agreement shall not be governed by the United Nations Convention on Contracts for the International Sale of Goods, or by the Uniform Computer Information Transactions Act (UCITA).  The parties agree that non-exclusive jurisdiction for any dispute arising out of or relating to this Agreement lies within the courts located in the State of Texas.  Notwithstanding the foregoing, any judgment may be enforced in any United States or foreign court, and either party may seek injunctive relief in any United States or foreign court.  Failure by TI to enforce any provision of this Agreement shall not be deemed a waiver of future enforcement of that or any other provision in this Agreement or any other agreement that may be in place between the parties.
 **11.    PRC Provisions.  If you are located in the People's Republic of China ("PRC") or if the Licensed Materials will be sent to the PRC, the following provisions shall apply:
 *    a.    Registration Requirements.  You shall be solely responsible for performing all acts and obtaining all approvals that may be required in connection with this Agreement by the government of the PRC, including but not limited to registering pursuant to, and otherwise complying with, the PRC Measures on the Administration of Software Products, Management Regulations on Technology Import-Export, and Technology Import and Export Contract Registration Management Rules.  Upon receipt of such approvals from the government authorities, you shall forward evidence of all such approvals to TI for its records.  In the event that you fail to obtain any such approval or registration, you shall be solely responsible for any and all losses, damages or costs resulting therefrom, and shall indemnify TI for all such losses, damages or costs.
 **b.    Governing Language.  This Agreement is written and executed in the English language and shall be authoritative and controlling, whether or not translated into a language other than English to comply with law or for reference purposes.  If a translation of this Agreement is required for any purpose, including but not limited to registration of the Agreement pursuant to any governmental laws, regulations or rules, you shall be solely responsible for creating such translation.
 **12.    Contingencies.    TI shall not be in breach of this Agreement and shall not be liable for any non-performance or delay in performance if such non-performance or delay is due to a force majeure event or other circumstances beyond TI's reasonable control.
 **13.        Entire Agreement.  This is the entire agreement between you and TI and this Agreement supersedes any prior agreement between the parties related to the subject matter of this Agreement.  Notwithstanding the foregoing, any signed and effective software license agreement relating to the subject matter hereof and stating expressly that such agreement shall control regardless of any subsequent click-wrap, shrink-wrap or web-wrap, shall supersede the terms of this Agreement.  No amendment or modification of this Agreement will be effective unless in writing and signed by a duly authorized representative of TI.  You hereby warrant and represent that you have obtained all authorizations and other applicable consents required empowering you to enter into this Agreement.
 * --/COPYRIGHT--*/
/*!****************************************************************************
 *  @file       drv8323.h
 *  @brief      DRV8323 gate driver Module
 *
 * 
 *  @anchor drv8323_h
 *  # Overview
 *
 *  defines APIs for drv8323 gate driver
 *
 *  <hr>
 ******************************************************************************/

#ifndef DRV8323_H
#define DRV8323_H

#include "stdint.h"
#include "main.h"
#include "appInputCtrlInterface.h"


#ifdef __cplusplus
extern "C" {
#endif

#ifdef DRV8323

/*! @brief Defines the address mask */
#define DRV8323_ADDR_MASK                   (0x7800)

/*! @brief Defines the data mask */
#define DRV8323_DATA_MASK                   (0x07FF)

/*! @brief Defines the R/W mask */
#define DRV8323_RW_MASK                     (0x8000)

/*! @brief DRV8323 REG 0 */
#define DRV8323_REG_0                0x00
/*! @brief DRV8323 REG 1 */
#define DRV8323_REG_1                0x01
/*! @brief DRV8323 REG 2 */
#define DRV8323_REG_2                0x02
/*! @brief DRV8323 REG 3 */
#define DRV8323_REG_3                0x03
/*! @brief DRV8323 REG 4 */
#define DRV8323_REG_4                0x04
/*! @brief DRV8323 REG 5 */
#define DRV8323_REG_5                0x05
/*! @brief DRV8323 REG 6 */
#define DRV8323_REG_6                0x06

/*! @brief Defines the Fault type mask */
#define DRV8323_FAULT_TYPE_MASK             (0x07FF)

/*! @brief Defines the location of VDS LC bit in the Status 1 register  */
#define DRV8323_STATUS00_VDS_LC_BITS        (1 << 0)
/*! @brief Defines the location of VDS HC bit in the Status 1 register  */
#define DRV8323_STATUS00_VDS_HC_BITS        (1 << 1)
/*! @brief Defines the location of VDS LB bit in the Status 1 register  */
#define DRV8323_STATUS00_VDS_LB_BITS        (1 << 2)
/*! @brief Defines the location of VDS HB bit in the Status 1 register  */
#define DRV8323_STATUS00_VDS_HB_BITS        (1 << 3)
/*! @brief Defines the location of VDS LA bit in the Status 1 register  */
#define DRV8323_STATUS00_VDS_LA_BITS        (1 << 4)
/*! @brief Defines the location of VDS HA bit in the Status 1 register  */
#define DRV8323_STATUS00_VDS_HA_BITS        (1 << 5)
/*! @brief Defines the location of OTSD (Over temperature shutdown) bit in the Status 1 register  */
#define DRV8323_STATUS00_OTSD_BITS          (1 << 6)
/*! @brief Defines the location of UVLO bit in the Status 1 register  */
#define DRV8323_STATUS00_UVLO_BITS          (1 << 7)
/*! @brief Defines the location of GDF bit in the Status 1 register  */
#define DRV8323_STATUS00_GDF_BITS           (1 << 8)
/*! @brief Defines the location of VDS OCP bit in the Status 1 register  */
#define DRV8323_STATUS00_VDS_OCP_BITS       (1 << 9)
/*! @brief Defines the location of FAULT bit in the Status 1 register */
#define DRV8323_STATUS00_FAULT_BITS         (1 << 10)


/*! @brief Defines the location of the VGS_LC bits in the Status 2 register */
#define DRV8323_STATUS01_VGS_LC_BITS     (1 << 0)

/*! @brief Defines the location of the VGS_HC bits in the Status 2 register */
#define DRV8323_STATUS01_VGS_HC_BITS     (1 << 1)

/*! @brief Defines the location of the VGS_LB bits in the Status 2 register */
#define DRV8323_STATUS01_VGS_LB_BITS     (1 << 2)

/*! @brief Defines the location of the VGS_HB bits in the Status 2 register */
#define DRV8323_STATUS01_VGS_HB_BITS     (1 << 3)

/*! @brief Defines the location of the VGS_LA bits in the Status 2 register */
#define DRV8323_STATUS01_VGS_LA_BITS     (1 << 4)

/*! @brief Defines the location of the VGS_HA bits in the Status 2 register */
#define DRV8323_STATUS01_VGS_HA_BITS     (1 << 5)

/*! @brief Defines the location of the CPUV (charge pump undervoltage) bits in the Status 2 register */
#define DRV8323_STATUS01_CPUV_BITS     (1 << 6)

/*! @brief Defines the location of the OTW bits in the Status 2 register */
#define DRV8323_STATUS01_OTW_BITS     (1 << 7)

/*! @brief Defines the location of the SC_OC bits in the Status 2 register */
#define DRV8323_STATUS01_SC_OC_BITS     (1 << 8)

/*! @brief Defines the location of the SB_OC bits in the Status 2 register */
#define DRV8323_STATUS01_SB_OC_BITS     (1 << 9)

/*! @brief Defines the location of the SA_OC bits in the Status 2 register */
#define DRV8323_STATUS01_SA_OC_BITS     (1 << 10)



/*! @brief Defines the location of the CLR_FLT bits in the Control 2 register */
#define DRV8323_CTRL02_CLR_FLT_BITS       (1 << 0)

/*! @brief Defines the location of the BRAKE bits in the Control 2 register */
#define DRV8323_CTRL02_BRAKE_BITS         (1 << 1)

/*! @brief Defines the location of the COAST bits in the Control 2 register */
#define DRV8323_CTRL02_COAST_BITS         (1 << 2)

/*! @brief Defines the location of the 1PWM_DIR bits in the Control 2 register */
#define DRV8323_CTRL02_PWM1_DIR_BITS       (1 << 3)

/*! @brief Defines the location of the 1PWM_COM bits in the Control 2 register */
#define DRV8323_CTRL02_PWM1_COM_BITS       (1 << 4)

/*! @brief Defines the location of the PWM_MODE bits in the Control 2 register */
#define DRV8323_CTRL02_PWM_MODE_BITS       (3 << 5)

/*! @brief Defines the location of the OTW_REP bits in the Control 2 register */
#define DRV8323_CTRL02_OTW_REP_BITS        (1 << 7)

/*! @brief Defines the location of the DIS_GDF bits in the Control 2 register */
#define DRV8323_CTRL02_DIS_GDF_BITS        (1 << 8)

/*! @brief Defines the location of the DIS_CPUV bits in the Control 2 register */
#define DRV8323_CTRL02_DIS_CPUV_BITS       (1 << 9)

/*! @brief Defines the location of the RESERVED1 bits in the Control 2 register */
#define DRV8323_CTRL02_RESERVED1_BITS       (1 << 10)


/*! @brief Defines the location of the IDRIVEN_HS bits in the Control 3 register */
#define DRV8323_CTRL03_IDRIVEN_HS_BITS      (15 << 0)

/*! @brief Defines the location of the IDRIVEP_HS bits in the Control 3 register */
#define DRV8323_CTRL03_IDRIVEP_HS_BITS      (15 << 4)

/*! @brief Defines the location of the LOCK bits in the Control 3 register */
#define DRV8323_CTRL03_LOCK_BITS            (7 << 8)

/*! @brief Defines the location of the IDRIVEN_LS bits in the Control 4 register */
#define DRV8323_CTRL04_IDRIVEN_LS_BITS      (15 << 0)

/*! @brief Defines the location of the IDRIVEP_LS bits in the Control 4 register */
#define DRV8323_CTRL04_IDRIVEP_LS_BITS      (15 << 4)

/*! @brief Defines the location of the TDRIVE bits in the Control 4 register */
#define DRV8323_CTRL04_TDRIVE_BITS          (3 << 8)

/*! @brief Defines the location of the CBC bits in the Control 4 register */
#define DRV8323_CTRL04_CBC_BITS             (1 << 10)


/*! @brief Defines the location of the VDS_LVL bits in the Control 5 register */
#define DRV8323_CTRL05_VDS_LVL_BITS         (15 << 0)

/*! @brief Defines the location of the OCP_DEG bits in the Control 5 register */
#define DRV8323_CTRL05_OCP_DEG_BITS         (3 << 4)

/*! @brief Defines the location of the OCP_MODE bits in the Control 5 register */
#define DRV8323_CTRL05_OCP_MODE_BITS        (3 << 6)

/*! @brief Defines the location of the DEAD_TIME bits in the Control 5 register */
#define DRV8323_CTRL05_DEAD_TIME_BITS      (3 << 8)

/*! @brief Defines the location of the TRETRY bits in the Control 5 register */
#define DRV8323_CTRL05_TRETRY_BITS         (1 << 10)


/*! @brief Defines the location of the SEN_LVL bits in the Control 6 register */
#define DRV8323_CTRL06_SEN_LVL_BITS         (3 << 0)

/*! @brief Defines the location of the CSA_CAL_C bits in the Control 6 register */
#define DRV8323_CTRL06_CSA_CAL_C_BITS       (1 << 2)

/*! @brief Defines the location of the CSA_CAL_B bits in the Control 6 register */
#define DRV8323_CTRL06_CSA_CAL_B_BITS       (1 << 3)

/*! @brief Defines the location of the CSA_CAL_A bits in the Control 6 register */
#define DRV8323_CTRL06_CSA_CAL_A_BITS       (1 << 4)

/*! @brief Defines the location of the DIS_SEN bits in the Control 6 register */
#define DRV8323_CTRL06_DIS_SEN_BITS         (1 << 5)

/*! @brief Defines the location of the CSA_GAIN bits in the Control 6 register */
#define DRV8323_CTRL06_CSA_GAIN_BITS        (3 << 6)

/*! @brief Defines the location of the LS_REF bits in the Control 6 register */
#define DRV8323_CTRL06_LS_REF_BITS          (1 << 8)

/*! @brief Defines the location of the VREF_DIV bits in the Control 6 register */
#define DRV8323_CTRL06_VREF_DIV_BITS        (1 << 9)

/*! @brief Defines the location of the CSA_FET bits in the Control 6 register */
#define DRV8323_CTRL06_CSA_FET_BITS         (1 << 10)

/*! shift values for HVdie parameters */

/*! @brief DRV8323 OTW REP POS */
#define    DRV8323_OTW_REP_POS      7
/*! @brief DRV8323 DIS GDF POS */
#define    DRV8323_DIS_GDF_POS      8
/*! @brief DRV8323 DIS CPUV POS */
#define    DRV8323_DIS_CPUV_POS     9

/*! @brief DRV8323 IDRIVEN HS POS */
#define    DRV8323_IDRIVEN_HS_POS   0
/*! @brief DRV8323 IDRIVEP HS POS */
#define    DRV8323_IDRIVEP_HS_POS   4

/*! @brief DRV8323 IDRIVEN LS POS */
#define    DRV8323_IDRIVEN_LS_POS   0
/*! @brief DRV8323 IDRIVEP LS POS */
#define    DRV8323_IDRIVEP_LS_POS   4
/*! @brief DRV8323 TDRIVE POS */
#define    DRV8323_TDRIVE_POS       8
/*! @brief DRV8323 CBC POS */
#define    DRV8323_CBC_POS          10

/*! @brief DRV8323 VDS LVL POS */
#define    DRV8323_VDS_LVL_POS      0
/*! @brief DRV8323 OCP DEG POS */
#define    DRV8323_OCP_DEG_POS      4
/*! @brief DRV8323 OCP MODE POS */
#define    DRV8323_OCP_MODE_POS     6
/*! @brief DRV8323 DEAD TIME POS */
#define    DRV8323_DEAD_TIME_POS    8
/*! @brief DRV8323 TRETRY POS */
#define    DRV8323_TRETRY_POS       10

/*! @brief DRV8323 SEN LVL POS */
#define    DRV8323_SEN_LVL_POS      0
/*! @brief DRV8323 DIS SEN POS */
#define    DRV8323_DIS_SEN_POS      5
/*! @brief DRV8323 CSA GAIN POS */
#define    DRV8323_CSA_GAIN_POS     6
/*! @brief DRV8323 LS REF POS */
#define    DRV8323_LS_REF_POS       8
/*! @brief DRV8323 VREF DIV POS */
#define    DRV8323_VREF_DIV_POS     9
/*! @brief DRV8323 CSA FET POS */
#define    DRV8323_CSA_FET_POS      10
/*************************************************************************/

/*! @brief Enumeration for the R/W modes */
typedef enum
{
  /*! Read Mode */
  CtrlMode_Read = 1 << 15,
  /*! Write Mode */
  CtrlMode_Write = 0 << 15
} DRV8323_CtrlMode_e;

/*! @brief Enumeration for the Status 0 register, faults */
typedef enum
{
  /*! VDS overcurrent fault on C low-side MOSFET */
  VDS_LC      = (1 << 0),    
  /*! VDS overcurrent fault on C high-side MOSFET */
  VDS_HC      = (1 << 1),    
  /*! VDS overcurrent fault on B low-side MOSFET */
  VDS_LB      = (1 << 2),    
  /*! VDS overcurrent fault on B high-side MOSFET */
  VDS_HB      = (1 << 3),    
  /*! VDS overcurrent fault on A low-side MOSFET */
  VDS_LA      = (1 << 4),    
  /*! VDS overcurrent fault on A high-side MOSFET */
  VDS_HA      = (1 << 5),    
  /*! Overtemperature shutdown */
  OTSD        = (1 << 6),    
  /*! Undervoltage lockout fault condition */
  UVLO        = (1 << 7),    
  /*! Gate driver fault condition */
  GDF         = (1 << 8),    
  /*! VDS monitor overcurrent fault condition */
  VDS_OCP     = (1 << 9),    
  /*! FAULT type, 0-Warning, 1-Latched */
  FAULT1       = (1 << 10)    
} DRV8323_STATUS00_WarningWatchdog_e;


/*! @brief Enumeration for the Status 1 register, OV/VDS faults */
typedef enum
{
  /*! VGS gate drive fault on C low-side MOSFET */
  VGS_LC      = (1 << 0),    
  /*! VGS gate drive fault on C high-side MOSFET */
  VGS_HC      = (1 << 1),    
  /*! VGS gate drive fault on B low-side MOSFET */
  VGS_LB      = (1 << 2),    
  /*! VGS gate drive fault on B high-side MOSFET */
  VGS_HB      = (1 << 3),    
  /*! VGS gate drive fault on A low-side MOSFET */
  VGS_LA      = (1 << 4),    
  /*! VGS gate drive fault on A high-side MOSFET */
  VGS_HA      = (1 << 5),    
  /*! charge pump undervoltage fault */
  CPUV        = (1 << 6),    
  /*! overtemperature warning */
  OTW         = (1 << 7),    
  /*! overcurrent on phase C */
  SC_OC       = (1 << 8),    
  /*! overcurrent on phase B */
  SB_OC       = (1 << 9),    
  /*! overcurrent on phase A */
  SA_OC       = (1 << 10)    
} DRV8323_STATUS01_OvVdsFaults_e;


/*! @brief Enumeration for the driver PWM mode */
typedef enum 
{
  /*! PWM_MODE = 6 inputs */
  PwmMode_6 = (0 << 5),     
  /*! PWM_MODE = 3 inputs */
  PwmMode_3 = (1 << 5),     
  /*! PWM_MODE = 1 input */
  PwmMode_1 = (2 << 5)      
} DRV8323_CTRL02_PwmMode_e;


/*! @brief Enumeration for the high side gate drive peak source current */
typedef enum 
{
  /*! IDRIVEP_HS = 0.010A */
  ISour_HS_0p010_A = (0 << 4),  
  /*! IDRIVEP_HS = 0.020A */
  ISour_HS_0p020_A = (1 << 4),  
  /*! IDRIVEP_HS = 0.030A */
  ISour_HS_0p030_A = (2 << 4),  
  /*! IDRIVEP_HS = 0.040A */
  ISour_HS_0p040_A = (3 << 4),  
  /*! IDRIVEP_HS = 0.050A */
  ISour_HS_0p050_A = (4 << 4),  
  /*! IDRIVEP_HS = 0.060A */
  ISour_HS_0p060_A = (5 << 4),  
  /*! IDRIVEP_HS = 0.070A */
  ISour_HS_0p070_A = (6 << 4),  
  /*! IDRIVEP_HS = 0.125A */
  ISour_HS_0p125_A = (7 << 4),  
  /*! IDRIVEP_HS = 0.250A */
  ISour_HS_0p250_A = (8 << 4),  
  /*! IDRIVEP_HS = 0.500A */
  ISour_HS_0p500_A = (9 << 4),  
  /*! IDRIVEP_HS = 0.750A */
  ISour_HS_0p750_A = (10 << 4), 
  /*! IDRIVEP_HS = 1.000A */
  ISour_HS_1p000_A = (11 << 4)  
} DRV8323_CTRL03_PeakSourCurHS_e;


/*! @brief Enumeration for the high side gate drive peak sink current */
typedef enum 
{
  /*! IDRIVEN_HS = 0.020A */
  ISink_HS_0p020_A = (0 << 0),  
  /*! IDRIVEN_HS = 0.030A */
  ISink_HS_0p030_A = (1 << 0),  
  /*! IDRIVEN_HS = 0.040A */
  ISink_HS_0p040_A = (2 << 0),  
  /*! IDRIVEN_HS = 0.050A */
  ISink_HS_0p050_A = (3 << 0),  
  /*! IDRIVEN_HS = 0.060A */
  ISink_HS_0p060_A = (4 << 0),  
  /*! IDRIVEN_HS = 0.070A */
  ISink_HS_0p070_A = (5 << 0),  
  /*! IDRIVEN_HS = 0.125A */
  ISink_HS_0p125_A = (6 << 0),  
  /*! IDRIVEN_HS = 0.250A */
  ISink_HS_0p250_A = (7 << 0),  
  /*! IDRIVEN_HS = 0.500A */
  ISink_HS_0p500_A = (8 << 0),  
  /*! IDRIVEN_HS = 0.750A */
  ISink_HS_0p750_A = (9 << 0),  
  /*! IDRIVEN_HS = 1.000A */
  ISink_HS_1p000_A = (10 << 0), 
  /*! IDRIVEN_HS = 1.250A */
  ISink_HS_1p250_A = (11 << 0)  
} DRV8323_CTRL03_PeakSinkCurHS_e;


/*! @brief Enumeration for the high side and low side gate drive peak source time */
typedef enum 
{
  /*! Lock settings */
  Lock_lock     = (6 << 8),     
  /*! Unlock settings */
  Lock_unlock   = (3 << 8)      
} DRV8323_CTRL03_Lock_e;


/*! @brief Enumeration for the high side and low side gate drive peak source time */
typedef enum 
{
   /*! TDRIVEN = 250ns */
  TSour_250_ns  = (0 << 8),    
   /*! TDRIVEN = 500ns */
  TSour_500_ns  = (1 << 8),    
   /*! TDRIVEN = 1000ns */
  TSour_1000_ns = (2 << 8),    
   /*! TDRIVEN = 2000ns */
  TSour_2000_ns = (3 << 8)     
} DRV8323_CTRL04_PeakTime_e;


/*! @brief Enumeration for the low side gate drive peak source current */
typedef enum 
{
  /*! IDRIVEP_LS = 0.010A */
  ISour_LS_0p010_A = (0 << 4),  
  /*! IDRIVEP_LS = 0.020A */
  ISour_LS_0p030_A = (1 << 4),  
  /*! IDRIVEP_LS = 0.030A */
  ISour_LS_0p060_A = (2 << 4),  
  /*! IDRIVEP_LS = 0.040A */
  ISour_LS_0p080_A = (3 << 4),  
  /*! IDRIVEP_LS = 0.050A */
  ISour_LS_0p120_A = (4 << 4),  
  /*! IDRIVEP_LS = 0.060A */
  ISour_LS_0p140_A = (5 << 4),  
  /*! IDRIVEP_LS = 0.070A */
  ISour_LS_0p170_A = (6 << 4),  
  /*! IDRIVEP_LS = 0.125A */
  ISour_LS_0p190_A = (7 << 4),  
  /*! IDRIVEP_LS = 0.250A */
  ISour_LS_0p250_A = (8 << 4),  
  /*! IDRIVEP_LS = 0.500A */
  ISour_LS_0p330_A = (9 << 4),  
  /*! IDRIVEP_LS = 0.750A */
  ISour_LS_0p370_A = (10 << 4), 
  /*! IDRIVEP_LS = 1.000A */
  ISour_LS_0p440_A = (11 << 4),  
  /*! IDRIVEP_LS = 1.000A */
  ISour_LS_0p570_A = (12 << 4),  
  /*! IDRIVEP_LS = 1.000A */
  ISour_LS_0p680_A = (13 << 4),  
  /*! IDRIVEP_LS = 1.000A */
  ISour_LS_0p820_A = (14 << 4), 
  /*! IDRIVEP_LS = 1.000A */ 
  ISour_LS_1p000_A = (15 << 4)
} DRV8323_CTRL04_PeakSourCurLS_e;


/*! @brief Enumeration for the low side gate drive peak sink current */
typedef enum 
{
  /*! IDRIVEN_LS = 0.020A */
  ISink_LS_0p020_A = (0 << 0),  
  /*! IDRIVEN_LS = 0.030A */
  ISink_LS_0p060_A = (1 << 0),  
  /*! IDRIVEN_LS = 0.040A */
  ISink_LS_0p120_A = (2 << 0),  
  /*! IDRIVEN_LS = 0.050A */
  ISink_LS_0p160_A = (3 << 0),  
  /*! IDRIVEN_LS = 0.060A */
  ISink_LS_0p240_A = (4 << 0),  
  /*! IDRIVEN_LS = 0.070A */
  ISink_LS_0p280_A = (5 << 0),  
  /*! IDRIVEN_LS = 0.125A */
  ISink_LS_0p340_A = (6 << 0),  
  /*! IDRIVEN_LS = 0.250A */
  ISink_LS_0p380_A = (7 << 0),  
  /*! IDRIVEN_LS = 0.500A */
  ISink_LS_0p520_A = (8 << 0),  
  /*! IDRIVEN_LS = 0.750A */
  ISink_LS_0p660_A = (9 << 0),  
  /*! IDRIVEN_LS = 1.000A */
  ISink_LS_0p740_A = (10 << 0), 
  /*! IDRIVEN_LS = 1.250A */
  ISink_LS_0p880_A = (11 << 0),  
  /*! IDRIVEN_LS = 1.250A */
  ISink_LS_1p140_A = (12 << 0),  
  /*! IDRIVEN_LS = 1.250A */
  ISink_LS_1p360_A = (13 << 0),  
  /*! IDRIVEN_LS = 1.250A */
  ISink_LS_1p640_A = (14 << 0), 
  /*! IDRIVEN_LS = 1.250A */ 
  ISink_LS_2p000_A = (15 << 0)  
} DRV8323_CTRL04_PeakSinkCurLS_e;


/*! @brief Enumeration for the VDS comparator threshold */
typedef enum 
{
  /*! VDS_LEVEL = 0.060V */
  VDS_Level_0p060_V = (0 << 0),    
  /*! VDS_LEVEL = 0.130V */
  VDS_Level_0p130_V = (1 << 0),    
  /*! VDS_LEVEL = 0.200V */
  VDS_Level_0p200_V = (2 << 0),    
  /*! VDS_LEVEL = 0.260V */
  VDS_Level_0p260_V = (3 << 0),    
  /*! VDS_LEVEL = 0.310V */
  VDS_Level_0p310_V = (4 << 0),    
  /*! VDS_LEVEL = 0.450V */
  VDS_Level_0p450_V = (5 << 0),    
  /*! VDS_LEVEL = 0.530V */
  VDS_Level_0p530_V = (6 << 0),    
  /*! VDS_LEVEL = 0.600V */
  VDS_Level_0p600_V = (7 << 0),    
  /*! VDS_LEVEL = 0.680V */
  VDS_Level_0p680_V = (8 << 0),    
  /*! VDS_LEVEL = 0.750V */
  VDS_Level_0p750_V = (9 << 0),    
  /*! VDS_LEVEL = 0.940V */
  VDS_Level_0p940_V = (10 << 0),   
  /*! VDS_LEVEL = 1.130V */
  VDS_Level_1p130_V = (11 << 0),   
  /*! VDS_LEVEL = 1.300V */
  VDS_Level_1p300_V = (12 << 0),   
  /*! VDS_LEVEL = 1.500V */
  VDS_Level_1p500_V = (13 << 0),   
  /*! VDS_LEVEL = 1.700V */
  VDS_Level_1p700_V = (14 << 0),   
  /*! VDS_LEVEL = 1.880V */
  VDS_Level_1p880_V = (15 << 0)    
} DRV8323_CTRL05_VDSLVL_e;


/*! @brief Enumeration for the OCP/VDS sense deglitch time */
typedef enum 
{
  /*! TVDS = 0us */
  VDSDeg_0_us = (0 << 4),       
  /*! TVDS = 2us */
  VDSDeg_2_us = (1 << 4),       
  /*! TVDS = 4us */
  VDSDeg_4_us = (2 << 4),       
  /*! TVDS = 8us */
  VDSDeg_8_us = (3 << 4)        
} DRV8323_CTRL05_OcpDeg_e;


/*! @brief Enumeration for the OCP report mode */
typedef enum 
{
  /*! OCP_MODE = Latched fault */
  Latched_Shutdown = (0 << 6),  
  /*! OCP_MODE = Automatic Retry */
  Automatic_Retry = (1 << 6),   
  /*! OCP_MODE = Report only */
  Report_Only  = (2 << 6),      
  /*! OCP_MODE = Disabled */
  Disable_OCP = (3 << 6)        
} DRV8323_CTRL05_OcpMode_e;


/*! @brief Enumeration for the driver dead time */
typedef enum 
{
  /*! DEAD_TIME = 50ns */
  DeadTime_50_ns = (0 << 8),    
  /*! DEAD_TIME = 100ns */
  DeadTime_100_ns = (1 << 8),   
  /*! DEAD_TIME = 200ns */
  DeadTime_200_ns = (2 << 8),   
  /*! DEAD_TIME = 400ns */
  DeadTime_400_ns = (3 << 8)    
} DRV8323_CTRL05_DeadTime_e;


/*! @brief Enumeration for the Sense OCP level */
typedef enum 
{
  /*! SEN_LVL = 0.25V */
  SEN_Lvl_Ocp_0p25 = (0 << 0),  
  /*! SEN_LVL = 0.50V */
  SEN_Lvl_Ocp_0p50 = (1 << 0),  
  /*! SEN_LVL = 0.75V */
  SEN_Lvl_Ocp_0p75 = (2 << 0),  
  /*! SEN_LVL = 1.00V */
  SEN_Lvl_Ocp_1p00 = (3 << 0)   
} DRV8323_CTRL06_SENLevel_e;


/*! @brief Enumeration for the gain of shunt amplifier */
typedef enum 
{
  /*! GAIN_CSA = 5V/V */
  Gain_5VpV =  (0 << 6),   
  /*! GAIN_CSA = 10V/V */
  Gain_10VpV = (1 << 6),   
  /*! GAIN_CSA = 20V/V */
  Gain_20VpV = (2 << 6),   
  /*! GAIN_CSA = 40V/V */
  Gain_40VpV = (3 << 6)    
} DRV8323_CTRL06_CSAGain_e;


/*! @brief Enumeration for the register addresses */
typedef enum 
{
  /*! Status Register 0 */
  Address_Status_0  = 0 << 11,   
  /*! Status Register 1 */
  Address_Status_1  = 1 << 11,   
  /*! Control Register 2 */
  Address_Control_2 = 2 << 11,   
  /*! Control Register 3 */
  Address_Control_3 = 3 << 11,   
  /*! Control Register 4 */
  Address_Control_4 = 4 << 11,   
  /*! Control Register 5 */
  Address_Control_5 = 5 << 11,   
  /*! Control Register 6 */
  Address_Control_6 = 6 << 11    
} DRV8323_Address_e;


/*! @brief Object for the DRV8323 STATUS00 register */
typedef struct _DRV_SPI_8323_Stat00_t_
{
  /*! Bits 0 */
  _Bool                  VDS_LC;         
  /*! Bits 1 */
  _Bool                  VDS_HC;         
  /*! Bits 2 */
  _Bool                  VDS_LB;         
  /*! Bits 3 */
  _Bool                  VDS_HB;         
  /*! Bits 4 */
  _Bool                  VDS_LA;         
  /*! Bits 5 */
  _Bool                  VDS_HA;         
  /*! Bits 6 */
  _Bool                  OTSD;           
  /*! Bits 7 */
  _Bool                  UVLO;           
  /*! Bits 8 */
  _Bool                  GDF;            
  /*! Bits 9 */
  _Bool                  VDS_OCP;        
  /*! Bits 10 */
  _Bool                  FAULT;          
}DRV_SPI_8323_Stat00_t_;


/*! @brief Object for the DRV8323 STATUS01 register */
typedef struct _DRV_SPI_8323_Stat01_t_
{
  /*! Bits 0 */
  _Bool                  VGS_LC;         
  /*! Bits 1 */
  _Bool                  VGS_HC;         
  /*! Bits 2 */
  _Bool                  VGS_LB;         
  /*! Bits 3 */
  _Bool                  VGS_HB;         
  /*! Bits 4 */
  _Bool                  VGS_LA;         
  /*! Bits 5 */
  _Bool                  VGS_HA;         
  /*! Bits 6 */
  _Bool                  CPUV;           
  /*! Bits 7 */
  _Bool                  OTW;            
  /*! Bits 8 */
  _Bool                  SC_OC;          
  /*! Bits 9 */
  _Bool                  SB_OC;          
  /*! Bits 10 */
  _Bool                  SA_OC;          
}DRV_SPI_8323_Stat01_t_;


/*! @brief Object for the DRV8323 CTRL02 register */
typedef struct _DRV_SPI_8323_Ctrl02_t_
{
  /*! Bits 0 */
  _Bool                          CLR_FLT;        
  /*! Bits 1 */
  _Bool                          BRAKE;          
  /*! Bits 2 */
  _Bool                          COAST;          
  /*! Bits 3 */
  _Bool                          PWM1_DIR;       
  /*! Bits 4 */
  _Bool                          PWM1_COM;       
  /*! Bits 6-5 */
  DRV8323_CTRL02_PwmMode_e       PWM_MODE;       
  /*! Bits 7 */
  _Bool                          OTW_REP;        
  /*! Bits 8 */
  _Bool                          DIS_GDF;        
  /*! Bits 9 */
  _Bool                          DIS_CPUV;       
  /*! Bits 10 */
  _Bool                          CTRL02_RSV1;    
}DRV_SPI_8323_Ctrl02_t_;


/*! @brief Object for the DRV8323 CTRL03 register */
typedef struct _DRV_SPI_8323_Ctrl03_t_
{
  /*! Bits 3-0 */
  DRV8323_CTRL03_PeakSinkCurHS_e    IDRIVEN_HS;     
  /*! Bits 7-4 */
  DRV8323_CTRL03_PeakSourCurHS_e    IDRIVEP_HS;     
  /*! Bits 10-8 */
  DRV8323_CTRL03_Lock_e             LOCK;           
}DRV_SPI_8323_Ctrl03_t_;


/*! @brief Object for the DRV8323 CTRL04 register */
typedef struct _DRV_SPI_8323_Ctrl04_t_
{
  /*! Bits 3-0 */
  DRV8323_CTRL04_PeakSinkCurLS_e    IDRIVEN_LS;     
  /*! Bits 7-4 */
  DRV8323_CTRL04_PeakSourCurLS_e    IDRIVEP_LS;     
  /*! Bits 9-8 */
  DRV8323_CTRL04_PeakTime_e         TDRIVE;         
  /*! Bits 10 */
  _Bool                             CBC;            
}DRV_SPI_8323_Ctrl04_t_;


/*! @brief Object for the DRV8323 CTRL05 register */
typedef struct _DRV_SPI_8323_Ctrl05_t_
{
  /*! Bits 3-0 */
  DRV8323_CTRL05_VDSLVL_e           VDS_LVL;        
  /*! Bits 5-4 */
  DRV8323_CTRL05_OcpDeg_e           OCP_DEG;        
  /*! Bits 7-6 */
  DRV8323_CTRL05_OcpMode_e          OCP_MODE;       
  /*! Bits 9-8 */
  DRV8323_CTRL05_DeadTime_e         DEAD_TIME;      
  /*! Bits 10 */
  _Bool                             TRETRY;         
}DRV_SPI_8323_Ctrl05_t_;


/*! @brief Object for the DRV8323 CTRL06 register */
typedef struct _DRV_SPI_8323_Ctrl06_t_
{
  /*! Bits 1-0 */
  DRV8323_CTRL06_SENLevel_e     SEN_LVL;        
  /*! Bits 2 */
  _Bool 						CSA_CAL_C;   	
  /*! Bits 3 */
  _Bool 						CSA_CAL_B;   	
  /*! Bits 4 */
  _Bool 						CSA_CAL_A;   	
  /*! Bits 5 */
  _Bool 						DIS_SEN; 	  	
  /*! Bits 7-6 */
  DRV8323_CTRL06_CSAGain_e      CSA_GAIN;       
  /*! Bits 8 */
  _Bool                         LS_REF;	        
  /*! Bits 9 */
  _Bool                         VREF_DIV;       
  /*! Bits 10 */
  _Bool                         CSA_FET;        
}DRV_SPI_8323_Ctrl06_t_;

/*! @brief Object for the DRV8323 registers and commands */
typedef struct _DRV_SPI_8323_Vars_t_
{
  /*! Status reg 1 */
  DRV_SPI_8323_Stat00_t_    Stat_Reg_00;
  /*! Status reg 2 */
  DRV_SPI_8323_Stat01_t_    Stat_Reg_01;
  /*! Ctrl reg 1 */
  DRV_SPI_8323_Ctrl02_t_    Ctrl_Reg_02;
  /*! Ctrl reg 2 */
  DRV_SPI_8323_Ctrl03_t_    Ctrl_Reg_03;
  /*! Ctrl reg 3 */
  DRV_SPI_8323_Ctrl04_t_    Ctrl_Reg_04;
  /*! Ctrl reg 4 */
  DRV_SPI_8323_Ctrl05_t_    Ctrl_Reg_05;
  /*! Ctrl reg 5 */
  DRV_SPI_8323_Ctrl06_t_    Ctrl_Reg_06;
} DRV_SPI_8323_Vars_t;

//! \brief Defines the DRV8323 Word type
//!
typedef  uint16_t    DRV8323_Word_t;

/*! @brief DRV823_CFG1 register */
typedef union
{
    struct DRV8323Cfg1
    {
        uint32_t
        /*! LS Idrive N setting */
        iDriveNLS:          4,
        /*! VDS Level setting */
        vdsLevel:           4,
        /*! OCP Deglitch setting */
        ocpDeg:             2,
        /*! OCP Mode setting */
        ocpMode:            2,
        /*! Dead Time setting */
        deadTime:           2,
        /*! retry Time setting */
        tRetry:             1,
        /*! Sense Level setting */
        senLvl:             2,
        /*! CSA CAL - Ph C Config */
        csaCalC:            1,
        /*! CSA CAL - Ph B Config */
        csaCalB:            1,
        /*! CSA CAL - Ph A Config */
        csaCalA:            1,
        /*! Disable Current Sense Config */
        disSen:             1,
        /*! CSA Gain Config */
        csaGain:            2,
        /*! VDS LS Reference Configuration*/
        lsRef:              1,
        /*! Vref Level Config */
        vrefDiv:            1,
        /*! CSA Pos Ref Config */
        csaFET:             1,
        /*! Reserved */
        reserved1:          5,
        parity:             1;

   }b;
    uint32_t w;
}GATE_DRIVE_8323_CFG1_T;

/*! @brief DRV823_CFG2 register */
typedef union
{
    struct DRV8323Cfg2
    {
        uint32_t
        /*! Gate Driver Clear Fault Bit */
        clrFLT:             1,
        /*! Built In Brake Setting - Masked by Algo */
        brake:              1,
        /*! Built In Coast Setting - Masked by Algo */
        coast:              1,
        /*! Built In PWM Dir Setting - Masked by Algo */
        pwmDir:             1,
        /*! Built In PWM Comm Setting - Masked by Algo */
        pwmComm:            1,
        /*! Built In PWM Mode Setting - Masked by Algo */
        pwmMode:            2,
        /*! Over Temperature warning report */
        repOTW:             1,
        /*! Disable Gate Driver */
        disGDF:             1,
        /*! Disable Charge Pump Under Voltage Fault*/
        disCPUV:            1,
        /*! Reserved */
        reg2Rsvd:           1,
        /*! iDrive N HS Setting */
        iDriveNHS:          4,
        /*! iDrive P HS Setting */
        iDrivePHS:          4,
        /*! Built In Lock Setting - Masked by Algo */
        lock:               3,
        /*! iDrive P LS Setting */
        iDrivePLS:          4,
        /*! TDrive Setting */
        tDrive:             2,
        /*! CBC Fault Setting */
        cbc:                1,
        /*! Reserved */
        reserved:           2,
        parity:             1;
   }b;
    uint32_t w;
}GATE_DRIVE_8323_CFG2_T;

/*/*! @brief Interface Registers to configure Gate Driver DRV8323 */
typedef struct hvDie8323EEPROMInterface
{
    /*! gate driver config 1 */
    GATE_DRIVE_8323_CFG1_T    gateDrvCfg1;
    /*! gate driver config 2 */
    GATE_DRIVE_8323_CFG2_T    gateDrvCfg2;

} HV_DIE_EEPROM_INTERFACE_T;

extern HV_DIE_EEPROM_INTERFACE_T *pGateDriverConfig;

/**
 * @brief     Read fault status from DRV8323
 * @return    Returns fault status
 */
uint32_t drv8323StatusRead(void);

/******************************************************************************/
/*! @brief GD1 REG6 mask */
#define GD1_REG6_MASK         0x07FF8000

/*! @brief GD1 REG6 POS in gate driver register */
#define GD1_REG6_POS       15

/*! @brief REG6 write protect mask */
#define DRV_REG6_WRITE_PROTECT_MASK 0x61C

/******************************************************************************/
/*! @brief GD1 REG5 mask */
#define GD1_REG5_MASK         0x00007FF0

/*! @brief GD1 REG5 POS in gate driver register */
#define GD1_REG5_POS          4

/*! @brief REG5 write protect mask */
#define DRV_REG5_WRITE_PROTECT_MASK 0x00000000

/******************************************************************************/
/*! @brief GD2 REG4 mask */
#define GD2_REG4_MASK               0x1FC00000
/*! @brief GD1 REG4 mask */
#define GD1_REG4_MASK               0x0000000F

/*! @brief GD2 REG4 POS in gate driver register */
#define GD2_REG4_POS             22

/*! @brief GD2 REG4 POS in DRV register */
#define GD2_REG4_DRV_POS         4

/*! @brief GD1 REG4 POS in gate driver register */
#define GD1_REG4_POS             0

/*! @brief REG4 write protect mask */
#define DRV_REG4_WRITE_PROTECT_MASK 0x00000400

/******************************************************************************/
/*! @brief GD2 REG3 mask */
#define GD2_REG3_MASK               0x003FF800

/*! @brief GD2 REG3 POS in gate driver register */
#define GD2_REG3_POS             11

/*! @brief REG3 write protect mask */
#define DRV_REG3_WRITE_PROTECT_MASK 0x00000700

/******************************************************************************/
/*! @brief GD2 REG2 mask */
#define GD2_REG2_MASK         0x000007FF

/*! @brief GD2 REG2 POS in gate driver register */
#define GD2_REG2_POS       0

/*! @brief REG2 write protect mask */
#define DRV_REG2_WRITE_PROTECT_MASK 0x47F

/******************************************************************************/

/******************************************************************************/
/*! @brief Gate driver UVLO fault MASK */
#define GD_UVLO_FAULT_MASK      0x10000000
/*! @brief Gate driver UVLO fault POS */
#define GD_UVLO_FAULT_POS       28U

/*! @brief Gate driver OTSD fault MASK */
#define GD_OTSD_FAULT_MASK      0x08000000
/*! @brief Gate driver OTSD fault POS */
#define GD_OTSD_FAULT_POS       27U

/******************************************************************************/

#endif
#ifdef __cplusplus
}
#endif
#endif /*! DRV8323_H */
