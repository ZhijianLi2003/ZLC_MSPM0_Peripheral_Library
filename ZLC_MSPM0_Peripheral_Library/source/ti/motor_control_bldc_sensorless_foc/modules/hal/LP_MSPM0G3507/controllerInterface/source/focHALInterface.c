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
#include "focHALInterface.h"

/* Include the IQmath Library */
#include <ti/iqmath/include/IQmathLib.h>
#include "appDefs.h"
#include "main.h"
#include "gateDriver.h"

/** @brief IQ value of square root of 3 */
#define IQ_SQRT3    _IQ(1.732050807568877)

/** @brief Gain change max limit */
#define IABC_GAIN_CHANGE_MAX_LIMIT      _IQ(3.80)
/** @brief Gain change min limit */
#define IABC_GAIN_CHANGE_MIN_LIMIT      _IQ(0.45)

void HAL_ReadMotorInputs(HAL_MEASURE_MOTOR_INPUTS_T *pMotorInputs)
{
    HAL_MEASURE_CURRENT_T *pCurrent;
    HAL_MEASURE_VOLTAGE_T *pVoltage;

    pVoltage = &(pMotorInputs->voltage);
    pCurrent = &(pMotorInputs->current);

    HAL_GD_ReadDCVBusVoltage(pVoltage);
     switch(pMotorInputs->measureQuantity)
    {
        case MEASURE_PHASE_CURRENT:

            HAL_ReadCurrents(pMotorInputs);

        break;

        case MEASURE_PHASE_VOLTAGE:

            HAL_ReadPhaseVoltages(pMotorInputs);

        break;
    }

    pCurrent->prevMaxDutyPhase = *(pCurrent->pMaxDutyPhase);
}

void HAL_SetPhaseCurrentChannels(HAL_MEASURE_MOTOR_INPUTS_T *pMotorInputs)
{
    pMotorInputs->measureQuantity = MEASURE_PHASE_CURRENT;

    /* Disable Data Sequencer */
   DL_ADC12_disableConversions(FOC_ADC0_INST);
   DL_ADC12_disableConversions(FOC_ADC1_INST);

   HAL_GD_ConfigureCurrentChannels(pMotorInputs->current.currentShunt);

   /* Enable Data Sequencer */
   DL_ADC12_enableConversions(FOC_ADC0_INST);
   DL_ADC12_enableConversions(FOC_ADC1_INST);
}

void HAL_setADCIdxChannel(ADC12_Regs *adc12, DL_ADC12_MEM_IDX idx,
                                                             uint32_t chansel)
{
    adc12->ULLMEM.MEMCTL[idx] &= ~(ADC12_MEMCTL_CHANSEL_MASK);
    adc12->ULLMEM.MEMCTL[idx] |= chansel;
}

void HAL_SetPhaseVoltageChannels(HAL_MEASURE_MOTOR_INPUTS_T *pMotorInputs)
{
    pMotorInputs->measureQuantity = MEASURE_PHASE_VOLTAGE;

    /* Disable Data Sequencer */
     DL_ADC12_disableConversions(FOC_ADC0_INST);
     DL_ADC12_disableConversions(FOC_ADC1_INST);

     HAL_GD_ConfigureVoltageChannels();

     /* Configure Data Sequencer Trigger for current sampling */
     HAL_SetADCSamplingFrequency(pMotorInputs->adcSamplingRatio);

     /* Enable Data Sequencer */
     DL_ADC12_enableConversions(FOC_ADC0_INST);
     DL_ADC12_enableConversions(FOC_ADC1_INST);
}

void HAL_ReadPhaseVoltages(HAL_MEASURE_MOTOR_INPUTS_T *pMotorInputs)
{
    HAL_MEASURE_VOLTAGE_T *pVoltage;

    pVoltage = &(pMotorInputs->voltage);

    HAL_GD_ReadVoltages(pVoltage);

     /* Convert raw voltage values to proper format */
     pVoltage->vabc.a =
             _IQmpy_mathacl(pVoltage->vabcRaw.a,IQ_SQRT3);

     pVoltage->vabc.b =
             _IQmpy_mathacl(pVoltage->vabcRaw.b,IQ_SQRT3) ;

     pVoltage->vabc.c =
             _IQmpy_mathacl(pVoltage->vabcRaw.c,IQ_SQRT3);

}

void HAL_ReadCurrents(HAL_MEASURE_MOTOR_INPUTS_T *pMotorInputs)
{
    HAL_MEASURE_CURRENT_T *pCurrent = &(pMotorInputs->current);

    int32_t temp, ia, ib, ic, iMagSqr;

    CURRENT_SHUNT_TYPES currentShunt = pCurrent->currentShunt;

    MC_ABC_T
        iabc;

    HAL_GD_ReadCurrents(pCurrent);

    if(getMeasureOffsetStatus(pMotorInputs))
    {
#ifndef __CURRENT_SINGLE_SHUNT
        iabc.a =
                (_IQ11toIQ((pCurrent->iabcRaw.a -
                        pCurrent->pOffset->iaOffset)));

        if(pCurrent->currentShunt == CURRENT_THREE_SHUNT_A_BC ||
                pCurrent->currentShunt == CURRENT_TWO_SHUNT_A_B)
        {

            iabc.b =
                    (_IQ11toIQ((pCurrent->iabcRaw.b -
                            pCurrent->pOffset->ibADC1Offset)));
        }
        else
        {

            iabc.b =
                    (_IQ11toIQ((pCurrent->iabcRaw.b -
                            pCurrent->pOffset->ibADC0Offset)));
        }

        iabc.c =
                (_IQ11toIQ((pCurrent->iabcRaw.c -
                        pCurrent->pOffset->icOffset)));

        if(currentShunt == CURRENT_TWO_SHUNT_A_B)
        {
            iabc.c = -(iabc.a + iabc.b);
        }
        else if(currentShunt == CURRENT_TWO_SHUNT_A_C)
        {
            iabc.b = -(iabc.a + iabc.c);
        }
        else if(currentShunt == CURRENT_TWO_SHUNT_B_C)
        {
            iabc.a = -(iabc.c + iabc.b);
        }

#else
        HAL_currentReconstruction(pCurrent, *pCurrent->pPrevPrevSector);
        iabc.a = pCurrent->iabcRaw.a;
        iabc.b = pCurrent->iabcRaw.b;
        iabc.c = pCurrent->iabcRaw.c;
#endif
        ia = iabc.a;
        ib = iabc.b;
        ic = iabc.c;

        temp = _IQmpy_mathacl(ia, ia) + _IQmpy_mathacl(ib, ib)
                + _IQmpy_mathacl(ic, ic);

        iMagSqr = _IQmpy_mathacl(temp, TWO_BY_THREE);

        pCurrent->iabc = iabc;
        pCurrent->iMagSqr = iMagSqr;
    }
}

void HAL_SelectShuntMeasure(HAL_MEASURE_MOTOR_INPUTS_T *pMotorInputs)
{
    HAL_MEASURE_CURRENT_T *pCurrent = &(pMotorInputs->current);

    MC_PHASE_TYPES maxDutyPhase = *(pCurrent->pMaxDutyPhase);

#ifdef CURRENT_THREE_SHUNT_DYNAMIC
    if(maxDutyPhase != pCurrent->prevMaxDutyPhase &&
        pCurrent->flags.b.threeShuntDynamic)
    {
        /* Max duty phase has changed and dynamic update on 3
         * shunt is enabled */
        switch(maxDutyPhase)
        {
            case PHASE_A:
                pCurrent->currentShunt = CURRENT_TWO_SHUNT_B_C;
            break;

            case PHASE_B:
                pCurrent->currentShunt = CURRENT_TWO_SHUNT_A_C;
            break;

            case PHASE_C:
                pCurrent->currentShunt = CURRENT_TWO_SHUNT_A_B;
            break;

            case PHASE_INVALID:
                pCurrent->currentShunt = pCurrent->currentShuntSet;
            break;
        }

        HAL_SetPhaseCurrentChannels(pMotorInputs);
    }
#endif
}

void HAL_EnablePWM(void)
{
    /* sets forced PWM generation to disabled */
    DL_Timer_overrideCCPOut(FOC_PWMA0_INST, DL_TIMER_FORCE_OUT_DISABLED,
                    DL_TIMER_FORCE_CMPL_OUT_DISABLED, FOC_PWMA0_U_IDX);
    DL_Timer_overrideCCPOut(FOC_PWMA0_INST, DL_TIMER_FORCE_OUT_DISABLED,
                    DL_TIMER_FORCE_CMPL_OUT_DISABLED, FOC_PWMA0_V_IDX);
    DL_Timer_overrideCCPOut(FOC_PWMA0_INST, DL_TIMER_FORCE_OUT_DISABLED,
                    DL_TIMER_FORCE_CMPL_OUT_DISABLED, FOC_PWMA0_W_IDX);

    DL_Timer_setCCPOutputDisabledAdv(FOC_PWMA0_INST,(
        DL_TIMER_CCP0_DIS_OUT_ADV_SET_BY_OCTL | 
        DL_TIMER_CCP1_DIS_OUT_ADV_SET_BY_OCTL |
        DL_TIMER_CCP2_DIS_OUT_ADV_SET_BY_OCTL | 
        DL_TIMER_CCP3_DIS_OUT_ADV_SET_BY_OCTL
        ));
}

void HAL_DisablePWM(void)
{
    /* sets the CC outputs low */
    DL_Timer_setCCPOutputDisabledAdv(FOC_PWMA0_INST,(
        DL_TIMER_CCP0_DIS_OUT_ADV_FORCE_LOW | 
        DL_TIMER_CCP1_DIS_OUT_ADV_FORCE_LOW |
        DL_TIMER_CCP2_DIS_OUT_ADV_FORCE_LOW | 
        DL_TIMER_CCP3_DIS_OUT_ADV_FORCE_LOW
        ));

    /* sets forced PWM generation to disabled */
    DL_Timer_overrideCCPOut(FOC_PWMA0_INST, DL_TIMER_FORCE_OUT_DISABLED,
                    DL_TIMER_FORCE_CMPL_OUT_DISABLED, FOC_PWMA0_U_IDX);
    DL_Timer_overrideCCPOut(FOC_PWMA0_INST, DL_TIMER_FORCE_OUT_DISABLED,
                    DL_TIMER_FORCE_CMPL_OUT_DISABLED, FOC_PWMA0_V_IDX);
    DL_Timer_overrideCCPOut(FOC_PWMA0_INST, DL_TIMER_FORCE_OUT_DISABLED,
                    DL_TIMER_FORCE_CMPL_OUT_DISABLED, FOC_PWMA0_W_IDX);

}

void HAL_EnableLowSideBrake(void)
{
    DL_Timer_overrideCCPOut(FOC_PWMA0_INST, DL_TIMER_FORCE_OUT_LOW,
                            DL_TIMER_FORCE_CMPL_OUT_HIGH, FOC_PWMA0_U_IDX);
    DL_Timer_overrideCCPOut(FOC_PWMA0_INST, DL_TIMER_FORCE_OUT_LOW,
                            DL_TIMER_FORCE_CMPL_OUT_HIGH, FOC_PWMA0_V_IDX);
    DL_Timer_overrideCCPOut(FOC_PWMA0_INST, DL_TIMER_FORCE_OUT_LOW,
                            DL_TIMER_FORCE_CMPL_OUT_HIGH, FOC_PWMA0_W_IDX);
}

#ifndef __CURRENT_SINGLE_SHUNT

/**
 * @brief     Set PWM dutycycles for three shunt or two shunts
 * @param[in] pABC      Pointer to dutycycle
 * @param[in] FullDuty   Full dutycycle
 */
__STATIC_INLINE void HAL_UpdateDuty_3S(const MC_ABC_T *pABC, const int32_t FullDuty)
{
    int32_t duty1, duty2, duty3;
    _Bool pwmULow = false,pwmVLow = false,pwmWLow = false;

    /* Full Duty == 100% */
    duty1 = _IQmpy_mathacl(pABC->a, FullDuty);
    duty2 = _IQmpy_mathacl(pABC->b, FullDuty);
    duty3 = _IQmpy_mathacl(pABC->c, FullDuty);

    if(duty1 < DISCONTINUOUS_MIN_DUTY_COUNTS)
    {
        pwmULow = true;
    }
    else
    {
        /* Disable Force PWM for U phase */
        HAL_PWMForceDisable(FOC_PWMA0_U_IDX);

        /* duty divided by 2 for up-down counter mode */
        DL_TimerA_setCaptureCompareValue(
                          FOC_PWMA0_INST, duty1>>1, FOC_PWMA0_U_IDX);
    }

    if(duty2 < DISCONTINUOUS_MIN_DUTY_COUNTS)
    {
        pwmVLow = true;
    }
    else
    {
        /* Disable Force PWM for V phase */
        HAL_PWMForceDisable(FOC_PWMA0_V_IDX);

        /* duty divided by 2 for up-down counter mode */
        DL_TimerA_setCaptureCompareValue(
                          FOC_PWMA0_INST, duty2>>1, FOC_PWMA0_V_IDX);
    }

    if(duty3 < DISCONTINUOUS_MIN_DUTY_COUNTS)
    {
        pwmWLow = true;
    }
    else
    {
        /* Disable Force PWM for W phase */
        HAL_PWMForceDisable(FOC_PWMA0_W_IDX);

        /* duty divided by 2 for up-down counter mode */
        DL_TimerA_setCaptureCompareValue(
                          FOC_PWMA0_INST, duty3>>1, FOC_PWMA0_W_IDX);
    }

    if(pwmULow)
    {
        HAL_PWMForceLow(FOC_PWMA0_U_IDX);
    }

    if(pwmVLow)
    {
        HAL_PWMForceLow(FOC_PWMA0_V_IDX);
    }

    if(pwmWLow)
    {
        HAL_PWMForceLow(FOC_PWMA0_W_IDX);
    }
}
#endif

#ifdef __CURRENT_SINGLE_SHUNT

/**
 * @brief     Set PWM dutycycles for single shunt
 * @param[in] pABC      Pointer to dutycycle
 * @param[in] FullDuty   Full dutycycle
 * @param[in] voltageSector   Voltage sector
 * @param[in] minDelta   minimum PWM delta
 * @param[in] blankingTime   Blanking time
 */
__STATIC_INLINE void HAL_UpdateDuty_1S(const MC_ABC_T *pABC, const int32_t FullDuty,
                                                 MC_SECTOR_TYPES voltageSector,
                                                 int32_t minDelta,
                                                 int32_t blankingTime)
{
    int32_t dutyA, dutyB, dutyC;
    int32_t AcmpA, AcmpB;
    int32_t BcmpA, BcmpB;
    int32_t CcmpA, CcmpB;
    int16_t delta;
    int32_t pwm3cmpA,pwm3cmpB;

    /* Full Duty == 100% */
    dutyA = _IQmpy_mathacl(pABC->a, FullDuty);
    dutyB = _IQmpy_mathacl(pABC->b, FullDuty);
    dutyC = _IQmpy_mathacl(pABC->c, FullDuty);

    AcmpB = (dutyA>>1);
    AcmpA = FullDuty - AcmpB;
    BcmpB = (dutyB>>1);
    BcmpA = FullDuty - BcmpB;
    CcmpB = (dutyC>>1);
    CcmpA = FullDuty - CcmpB;

    switch(voltageSector)
    {
    case SECTOR_1:
            /* Max A, Min C */

            /* Mid Duty Phase Compensation */
            if(BcmpB < minDelta)
            {
                delta = minDelta - BcmpB;
                BcmpA+=delta;
                BcmpB+=delta;
            }
            /* Min Duty Phase Compensation */
            if((BcmpB - CcmpB) < minDelta)
            {
                delta = minDelta - (BcmpB - CcmpB);
                CcmpA-=delta;
                CcmpB-=delta;
            }
            /* Max Duty Phase Compensation */
            if((AcmpB - BcmpB) < minDelta)
            {
                delta = minDelta - (AcmpB - BcmpB);
                AcmpA+=delta;
                AcmpB+=delta;
            }

            /* Max Duty Phase */
            pwm3cmpA = AcmpB;
            /* Mid Duty Phase */
            pwm3cmpB = BcmpB;
            break;
        case SECTOR_2:
            /* Max B, Min C */

            /* Mid Duty Phase Compensation */
            if(AcmpB < minDelta)
            {
                delta = minDelta - AcmpB;
                AcmpA+=delta;
                AcmpB+=delta;
            }
            /* Min Duty Phase Compensation */
            if((AcmpB - CcmpB) < minDelta)
            {
                delta = minDelta - (AcmpB - CcmpB);
                CcmpA-=delta;
                CcmpB-=delta;
            }
            /* Max Duty Phase Compensation */
            if((BcmpB - AcmpB) < minDelta)
            {
                delta = minDelta - (BcmpB - AcmpB);
                BcmpA+=delta;
                BcmpB+=delta;
            }

            /* Max Duty Phase */
            pwm3cmpA = BcmpB;
            /* Mid Duty Phase */
            pwm3cmpB = AcmpB;
            break;
        case SECTOR_3:
            /* Max B, Min A */

            /* Mid Duty Phase Compensation */
            if(CcmpB < minDelta)
            {
                delta = minDelta - CcmpB;
                CcmpA+=delta;
                CcmpB+=delta;
            }
            /* Min Duty Phase Compensation */
            if((CcmpB - AcmpB) < minDelta)
            {
                delta = minDelta - (CcmpB - AcmpB);
                AcmpA-=delta;
                AcmpB-=delta;
            }
            /* Max Duty Phase Compensation */
            if((BcmpB - CcmpB) < minDelta)
            {
                delta = minDelta - (BcmpB - CcmpB);
                BcmpA+=delta;
                BcmpB+=delta;
            }

            /* Max Duty Phase */
            pwm3cmpA = BcmpB;
            /* Mid Duty Phase */
            pwm3cmpB = CcmpB;
            break;
        case SECTOR_4:
            /* Max C, Min A */

            /* Mid Duty Phase Compensation */
            if(BcmpB < minDelta)
            {
                delta = minDelta - BcmpB;
                BcmpA+=delta;
                BcmpB+=delta;
            }
            /* Min Duty Phase Compensation */
            if((BcmpB - AcmpB) < minDelta)
            {
                delta = minDelta - (BcmpB - AcmpB);
                AcmpA-=delta;
                AcmpB-=delta;
            }
            /* Max Duty Phase Compensation */
            if((CcmpB - BcmpB) < minDelta)
            {
                delta = minDelta - (CcmpB - BcmpB);
                CcmpA+=delta;
                CcmpB+=delta;
            }

            /* Max Duty Phase */
            pwm3cmpA = CcmpB;
            /* Mid Duty Phase */
            pwm3cmpB = BcmpB;
            break;
        case SECTOR_5:
            /* Max C, Min B */

            /* Mid Duty Phase Compensation */
            if(AcmpB < minDelta)
            {
                delta = minDelta - AcmpB;
                AcmpA+=delta;
                AcmpB+=delta;
            }
            /* Min Duty Phase Compensation */
            if((AcmpB - BcmpB) < minDelta)
            {
                delta = minDelta - (AcmpB - BcmpB);
                BcmpA-=delta;
                BcmpB-=delta;
            }
            /* Max Duty Phase Compensation */
            if((CcmpB - AcmpB) < minDelta)
            {
                delta = minDelta - (CcmpB - AcmpB);
                CcmpA+=delta;
                CcmpB+=delta;
            }

            /* Max Duty Phase */
            pwm3cmpA = CcmpB;
            /* Mid Duty Phase */
            pwm3cmpB = AcmpB;
            break;
        case SECTOR_6:
            /* Max A, Min B */

            /* Mid Duty Phase Compensation */
            if(CcmpB < minDelta)
            {
                delta = minDelta - CcmpB;
                CcmpA+=delta;
                CcmpB+=delta;
            }
            /* Min Duty Phase Compensation */
            if((CcmpB - BcmpB) < minDelta)
            {
                delta = minDelta - (CcmpB - BcmpB);
                BcmpA-=delta;
                BcmpB-=delta;
            }
            /* Max Duty Phase Compensation */
            if((AcmpB - CcmpB) < minDelta)
            {
                delta = minDelta - (AcmpB - CcmpB);
                AcmpA+=delta;
                AcmpB+=delta;
            }

            /* Max Duty Phase */
            pwm3cmpA = AcmpB;
            /* Mid Duty Phase */
            pwm3cmpB = CcmpB;
            break;
        default:
            pwm3cmpA = 400;
            pwm3cmpB = 200;
            break;
    }

    /* Limit cmpA */
    if(AcmpA >= FullDuty)
    {
        AcmpA = FullDuty - 1;
    }
    if(BcmpA >= FullDuty)
    {
        BcmpA = FullDuty - 1;
    }
    if(CcmpA >= FullDuty)
    {
        CcmpA = FullDuty - 1;
    }

    /* Limit cmpB */
    if(AcmpB <= 0)
    {
        AcmpB = 1;
    }
    if(BcmpB <= 0)
    {
        BcmpB = 1;
    }
    if(CcmpB <= 0)
    {
        CcmpB = 1;
    }

    DL_TimerA_setCaptureCompareValue(
                    FOC_PWMA0_INST, AcmpA, FOC_PWMA0_U_IDX);
    DL_TimerA_setCaptureCompareValue(
                    FOC_PWMA0_INST, AcmpB, FOC_PWMA0_U_B_IDX);

    /* Disable Force PWM for U phase */
    HAL_PWMForceDisable(FOC_PWMA0_U_IDX);
    

    DL_TimerA_setCaptureCompareValue(
                    FOC_PWMA0_INST, BcmpA, FOC_PWMA0_V_IDX);
    DL_TimerA_setCaptureCompareValue(
                    FOC_PWMA0_INST, BcmpB, FOC_PWMA0_V_B_IDX);
                    
    /* Disable Force PWM for V phase */
    HAL_PWMForceDisable(FOC_PWMA0_V_IDX);
    

    DL_TimerA_setCaptureCompareValue(
                    FOC_PWMA0_INST, CcmpA, FOC_PWMA0_W_IDX);
    DL_TimerA_setCaptureCompareValue(
                    FOC_PWMA0_INST, CcmpB, FOC_PWMA0_W_B_IDX);

    /* Disable Force PWM for W phase */
    HAL_PWMForceDisable(FOC_PWMA0_W_IDX);

    pwm3cmpA = pwm3cmpA - blankingTime;
    pwm3cmpB = pwm3cmpB - blankingTime;
    if(pwm3cmpA<=0)
    {
        pwm3cmpA = 1;
    }
    if(pwm3cmpB<=0)
    {
        pwm3cmpB = 1;
    }

    DL_TimerA_setCaptureCompareValue(
                    FOC_TIMA1_INST, pwm3cmpA, FOC_ADC_TRIG_1_IDX);
    DL_TimerA_setCaptureCompareValue(
                    FOC_TIMA1_INST, pwm3cmpB, FOC_ADC_TRIG_0_IDX);

}

#endif

void HAL_UpdateDuty(const MC_ABC_T *pABC, const int32_t FullDuty,
                                                 MC_SECTOR_TYPES voltageSector,
                                                 int32_t minDelta,
                                                 int32_t blankingTime)
{
    #ifdef __CURRENT_SINGLE_SHUNT
        HAL_UpdateDuty_1S( pABC, FullDuty, 
                            voltageSector, minDelta, blankingTime);
    #else
        HAL_UpdateDuty_3S(pABC, FullDuty);

    #endif
}

void HAL_SetPWMFrequency(const int32_t pwmPeriod,
                         const int32_t propagationDelay)
{
    
#ifndef __CURRENT_SINGLE_SHUNT

    uint32_t triggerPoint;

    /* period is divided by 2 for up-down counter mode */
    DL_Timer_setLoadValue(FOC_PWMA0_INST, pwmPeriod >> 1);

    /* Set 3 shunt adc trigger point */
    /* period is divided by 2 for up-down counter mode */
    DL_TimerA_setCaptureCompareValue(
        FOC_PWMA0_INST, ((pwmPeriod >> 1) - _IQabs(propagationDelay)),
        FOC_PWMA0_ADC_TRIG_IDX);

    if(propagationDelay > 0)
    {
        /* Trigger after the Counter Load */
        triggerPoint = FOC_PWMA0_ADC_TRIG_DN_EVENT;
    }
    else if(propagationDelay < 0)
    {
        /* Trigger before the Counter Load */
        triggerPoint = FOC_PWMA0_ADC_TRIG_UP_EVENT;
    }
    else
    {
        /* Trigger at the Counter Load */
        triggerPoint = FOC_PWMA0_ADC_TRIG_LOAD_EVENT;
    }

    /* Generate Trigger for ADC Conversion on PWMA0 at Trigger Point */
    DL_TimerA_enableEvent(FOC_PWMA0_INST, DL_TIMERA_EVENT_ROUTE_1,
                        triggerPoint);
    DL_TimerA_setPublisherChanID(FOC_PWMA0_INST, DL_TIMERA_PUBLISHER_INDEX_0,
                        ADC_PWM_TRIG_CH);

#else
    DL_Timer_setLoadValue(FOC_PWMA0_INST, pwmPeriod);
    DL_Timer_setLoadValue(FOC_TIMA1_INST, pwmPeriod);
#endif
}

void HAL_SetADCSamplingFrequency(const ADC_SAMPLING_RATIO_TYPES samplingRatio)
{
#ifndef __CURRENT_SINGLE_SHUNT
    DL_TimerA_setRepeatCounter(FOC_PWMA0_INST, samplingRatio);
   DL_ADC12_setSubscriberChanID(FOC_ADC0_INST, ADC_PWM_TRIG_CH);
   DL_ADC12_setSubscriberChanID(FOC_ADC1_INST, ADC_PWM_TRIG_CH);
#else
    DL_TimerA_setRepeatCounter(FOC_PWMA0_INST, samplingRatio);
    DL_TimerA_setRepeatCounter(FOC_TIMA1_INST, samplingRatio);
#endif
}

void HAL_SetSystemFrequency(const int32_t systemPeriod)
{
    DL_Timer_setLoadValue(FOC_TIMER_INST, systemPeriod);
}

_Bool HAL_GetPhasesFloatingStatus(const HAL_MEASURE_VOLTAGE_T *pVoltage)
{
    _Bool status, vaMid, vbMid, vcMid;

    MC_ABC_T Vabc = pVoltage->vabcRaw;

    int32_t lowLimit, highLimit;

    lowLimit = _IQmpy_mathacl(pVoltage->vdc, _IQ(MIN_FLOAT_VOLTAGE));
    highLimit = _IQmpy_mathacl(pVoltage->vdc, _IQ(MAX_FLOAT_VOLTAGE));

    vaMid = (Vabc.a >= lowLimit) && (Vabc.a < highLimit);
    vbMid = (Vabc.b >= lowLimit) && (Vabc.b < highLimit);
    vcMid = (Vabc.c >= lowLimit) && (Vabc.c < highLimit);

    if(((vaMid && vbMid) ||
        (vbMid && vcMid) ||
        (vcMid && vaMid)) ||
        (Vabc.a <= lowLimit && Vabc.b <= lowLimit && Vabc.c <= lowLimit) ||
        (Vabc.a >= highLimit && Vabc.b >= highLimit && Vabc.c >= highLimit))

    {
        /* All three phase voltages are either pulled up, down or in between
         * If current flows through phases, at least one phase voltage will be
         * pulled up, other will be pulled down (+ve curr, -ve curr) */
        status = TRUE;
    }
    else
    {
        status = FALSE;
    }

    return status;
}


void HAL_ClearNFault()
{
    DL_GPIO_clearPins(FOC_GPIO_NFAULT_PORT, FOC_GPIO_NFAULT_PIN);
}

void HAL_SetNFault()
{
    DL_GPIO_setPins(FOC_GPIO_NFAULT_PORT, FOC_GPIO_NFAULT_PIN);
}

uint32_t HAL_getRawHVdieFaultStatus(void)
{
    return (DL_Timer_getRawInterruptStatus(FOC_PWMA0_INST,
                                                GPTIMER_CPU_INT_IMASK_F_MASK));
}

uint32_t HAL_getRawFaultStatus(void)
{
    return (DL_Timer_getRawInterruptStatus(FOC_PWMA0_INST,
                                                GPTIMER_CPU_INT_IMASK_F_MASK));
}

void HAL_clearFaultStatus(void)
{
    DL_Timer_clearInterruptStatus(FOC_PWMA0_INST, GPTIMER_CPU_INT_IMASK_F_MASK);
}

void HAL_setGateDriveOffsetCalib(void)
{
    gateDriverOffsetCalibSet();
}

void HAL_resetGateDriveOffsetCalib(void)
{
    gateDriverOffsetCalibReset();
}

void HAL_pwmCountZero(void)
{
    DL_TimerA_setCaptureCompareValue(
                        FOC_PWMA0_INST, 0, FOC_PWMA0_U_IDX);
    DL_TimerA_setCaptureCompareValue(
                        FOC_PWMA0_INST, 0, FOC_PWMA0_V_IDX);
    DL_TimerA_setCaptureCompareValue(
                        FOC_PWMA0_INST, 0, FOC_PWMA0_W_IDX);

    #ifdef __CURRENT_SINGLE_SHUNT
    DL_TimerA_setCaptureCompareValue(
                        FOC_PWMA0_INST, 0, FOC_PWMA0_U_B_IDX);
    DL_TimerA_setCaptureCompareValue(
                        FOC_PWMA0_INST, 0, FOC_PWMA0_V_B_IDX);
    DL_TimerA_setCaptureCompareValue(
                        FOC_PWMA0_INST, 0, FOC_PWMA0_W_B_IDX);

    #endif
}

void HAL_delayMicroSeconds(uint32_t num_us)
{
    if(num_us == 0)
    {
        return;
    }
    DL_Common_delayCycles(num_us*HAL_CYCLES_TO_1_US_DELAY);
}

void HAL_DisableINT(void)
{
    __disable_irq();
}

void HAL_resetPOR(void)
{
    DL_SYSCTL_resetDevice(DL_SYSCTL_RESET_POR);
}

_Bool HAL_getDirPinStatus(void)
{
    return DL_GPIO_readPins(FOC_GPIO_DIR_PORT, FOC_GPIO_DIR_PIN)?
                        HAL_GPIO_HIGH : HAL_GPIO_LOW;
}

_Bool HAL_getBrakePinStatus(void)
{
    return DL_GPIO_readPins(FOC_GPIO_BRAKE_PORT, FOC_GPIO_BRAKE_PIN)?
                        HAL_GPIO_HIGH : HAL_GPIO_LOW;
}

void HAL_setIPDPulseConfig(VOLTAGE_VECTOR vector, uint8_t CompVal)
{
    #ifdef __IPD_ENABLE

    /* setting minimum compare value to 2 */
    if(CompVal <= 2)
    {
        CompVal += 2; 
    }
    CompVal = 127 - CompVal;
    DL_Timer_clearInterruptStatus(FOC_CAPTURE_IPD_INST, 
                                            DL_TIMER_INTERRUPT_CC0_DN_EVENT);
    
    switch(vector)
    {
        case VOLTAGE_VECTOR_AC:
            DL_Timer_setSubscriberChanID(FOC_CAPTURE_IPD_INST,
                                DL_TIMER_SUBSCRIBER_INDEX_0, FOC_COMP_W_PUB_CH);
            DL_COMP_setOutputInterruptEdge(COMP_W_INST, 
                                            DL_COMP_OUTPUT_INT_EDGE_FALLING);
            DL_COMP_setDACCode0(FOC_COMP_W_INST, CompVal);
            DL_COMP_setDACCode0(FOC_COMP_U_INST, 0);
            DL_COMP_setDACCode0(FOC_COMP_V_INST, 0);
            HAL_PWMForceDisable(FOC_PWMA0_V_IDX);
            HAL_PWMForceLow(FOC_PWMA0_W_IDX);
            DL_Timer_setTimerCount(FOC_CAPTURE_IPD_INST,
                                                    FOC_CAPTURE_IPD_LOAD_VALUE);
            HAL_PWMForceHigh(FOC_PWMA0_U_IDX);
            break;
        case VOLTAGE_VECTOR_CA:
            DL_Timer_setSubscriberChanID(FOC_CAPTURE_IPD_INST, 
                            DL_TIMER_SUBSCRIBER_INDEX_0,
                                         FOC_COMP_U_PUB_CH);
            DL_COMP_setOutputInterruptEdge(COMP_U_INST, 
                                            DL_COMP_OUTPUT_INT_EDGE_FALLING);
            DL_COMP_setDACCode0(FOC_COMP_U_INST, CompVal);
            DL_COMP_setDACCode0(FOC_COMP_V_INST, 0);
            DL_COMP_setDACCode0(FOC_COMP_W_INST, 0);
            HAL_PWMForceDisable(FOC_PWMA0_V_IDX);
            HAL_PWMForceLow(FOC_PWMA0_U_IDX);
            DL_Timer_setTimerCount(FOC_CAPTURE_IPD_INST,
                                                    FOC_CAPTURE_IPD_LOAD_VALUE);
            HAL_PWMForceHigh(FOC_PWMA0_W_IDX);
            break;
        case VOLTAGE_VECTOR_BC:
            DL_Timer_setSubscriberChanID(FOC_CAPTURE_IPD_INST, 
                            DL_TIMER_SUBSCRIBER_INDEX_0,
                                         FOC_COMP_W_PUB_CH);
            DL_COMP_setOutputInterruptEdge(COMP_W_INST, 
                                            DL_COMP_OUTPUT_INT_EDGE_FALLING);
            DL_COMP_setDACCode0(FOC_COMP_W_INST, CompVal);
            DL_COMP_setDACCode0(FOC_COMP_V_INST, 0);
            DL_COMP_setDACCode0(FOC_COMP_U_INST, 0);
            HAL_PWMForceDisable(FOC_PWMA0_U_IDX);
            HAL_PWMForceLow(FOC_PWMA0_W_IDX);
            DL_Timer_setTimerCount(FOC_CAPTURE_IPD_INST,
                                                    FOC_CAPTURE_IPD_LOAD_VALUE);
            HAL_PWMForceHigh(FOC_PWMA0_V_IDX);
            break;
        case VOLTAGE_VECTOR_CB:
            DL_Timer_setSubscriberChanID(FOC_CAPTURE_IPD_INST, 
                            DL_TIMER_SUBSCRIBER_INDEX_0,
                                         FOC_COMP_V_PUB_CH);
            DL_COMP_setOutputInterruptEdge(COMP_V_INST, 
                                            DL_COMP_OUTPUT_INT_EDGE_FALLING);
            DL_COMP_setDACCode0(FOC_COMP_V_INST, CompVal);
            DL_COMP_setDACCode0(FOC_COMP_U_INST, 0);
            DL_COMP_setDACCode0(FOC_COMP_W_INST, 0);
            HAL_PWMForceDisable(FOC_PWMA0_U_IDX);
            HAL_PWMForceLow(FOC_PWMA0_V_IDX);
            DL_Timer_setTimerCount(FOC_CAPTURE_IPD_INST,
                                                    FOC_CAPTURE_IPD_LOAD_VALUE);
            HAL_PWMForceHigh(FOC_PWMA0_W_IDX);
            break;
        case VOLTAGE_VECTOR_BA:
            DL_Timer_setSubscriberChanID(FOC_CAPTURE_IPD_INST, 
                            DL_TIMER_SUBSCRIBER_INDEX_0,
                                         FOC_COMP_U_PUB_CH);
            DL_COMP_setOutputInterruptEdge(COMP_U_INST, 
                                            DL_COMP_OUTPUT_INT_EDGE_FALLING);
            DL_COMP_setDACCode0(FOC_COMP_U_INST, CompVal);
            DL_COMP_setDACCode0(FOC_COMP_V_INST, 0);
            DL_COMP_setDACCode0(FOC_COMP_W_INST, 0);
            HAL_PWMForceDisable(FOC_PWMA0_W_IDX);
            HAL_PWMForceLow(FOC_PWMA0_U_IDX);
            DL_Timer_setTimerCount(FOC_CAPTURE_IPD_INST,
                                                    FOC_CAPTURE_IPD_LOAD_VALUE);
            HAL_PWMForceHigh(FOC_PWMA0_V_IDX);
            break;
        case VOLTAGE_VECTOR_AB:
            DL_Timer_setSubscriberChanID(FOC_CAPTURE_IPD_INST, 
                            DL_TIMER_SUBSCRIBER_INDEX_0,
                                         FOC_COMP_V_PUB_CH);
            DL_COMP_setOutputInterruptEdge(COMP_V_INST, 
                                            DL_COMP_OUTPUT_INT_EDGE_FALLING);
            DL_COMP_setDACCode0(FOC_COMP_V_INST, CompVal);
            DL_COMP_setDACCode0(FOC_COMP_U_INST, 0);
            DL_COMP_setDACCode0(FOC_COMP_W_INST, 0);
            HAL_PWMForceDisable(FOC_PWMA0_W_IDX);
            HAL_PWMForceLow(FOC_PWMA0_V_IDX);
            DL_Timer_setTimerCount(FOC_CAPTURE_IPD_INST,
                                                    FOC_CAPTURE_IPD_LOAD_VALUE);
            HAL_PWMForceHigh(FOC_PWMA0_U_IDX);
            break;
        default:
            /* This is expected to be empty */
            break;
    }
    HAL_IPDEnableISR();
    #endif
}

void HAL_IPDT1Action(VOLTAGE_VECTOR vector, uint8_t CompVal, 
                                                    uint8_t fastDecayEnable)
{
    #ifdef __IPD_ENABLE
    /* setting minimum compare value to 1 */
    if(CompVal == 0)
    {
        CompVal = 1; 
    }
    
    if(fastDecayEnable)
    {
        CompVal = 127 + CompVal;
        switch(vector)
        {
            case VOLTAGE_VECTOR_AC:
                DL_Timer_setSubscriberChanID(FOC_CAPTURE_IPD_INST, 
                                DL_TIMER_SUBSCRIBER_INDEX_0, FOC_COMP_U_PUB_CH);
                DL_COMP_setOutputInterruptEdge(COMP_U_INST,
                                            DL_COMP_OUTPUT_INT_EDGE_FALLING);
                DL_COMP_setDACCode0(FOC_COMP_U_INST, CompVal);
                DL_Timer_setTimerCount(FOC_CAPTURE_IPD_INST,
                                                    FOC_CAPTURE_IPD_LOAD_VALUE);
                HAL_PWMForceLow(FOC_PWMA0_U_IDX);
                HAL_PWMForceDisable(FOC_PWMA0_W_IDX);
                break;
            case VOLTAGE_VECTOR_CA:
                DL_Timer_setSubscriberChanID(FOC_CAPTURE_IPD_INST, 
                                DL_TIMER_SUBSCRIBER_INDEX_0, FOC_COMP_W_PUB_CH);
                DL_COMP_setOutputInterruptEdge(COMP_W_INST,
                                            DL_COMP_OUTPUT_INT_EDGE_FALLING);
                DL_COMP_setDACCode0(FOC_COMP_W_INST, CompVal);
                DL_Timer_setTimerCount(FOC_CAPTURE_IPD_INST,
                                                    FOC_CAPTURE_IPD_LOAD_VALUE);
                HAL_PWMForceLow(FOC_PWMA0_W_IDX);
                HAL_PWMForceDisable(FOC_PWMA0_U_IDX);
                break;
            case VOLTAGE_VECTOR_BC:
                DL_Timer_setSubscriberChanID(FOC_CAPTURE_IPD_INST, 
                                DL_TIMER_SUBSCRIBER_INDEX_0, FOC_COMP_V_PUB_CH);
                DL_COMP_setOutputInterruptEdge(COMP_V_INST,
                                            DL_COMP_OUTPUT_INT_EDGE_FALLING);
                DL_COMP_setDACCode0(FOC_COMP_V_INST, CompVal);
                DL_Timer_setTimerCount(FOC_CAPTURE_IPD_INST,
                                                    FOC_CAPTURE_IPD_LOAD_VALUE);
                HAL_PWMForceLow(FOC_PWMA0_V_IDX);
                HAL_PWMForceDisable(FOC_PWMA0_W_IDX);
                break;
            case VOLTAGE_VECTOR_CB:
                DL_Timer_setSubscriberChanID(FOC_CAPTURE_IPD_INST, 
                                DL_TIMER_SUBSCRIBER_INDEX_0, FOC_COMP_W_PUB_CH);
                DL_COMP_setOutputInterruptEdge(COMP_W_INST,
                                            DL_COMP_OUTPUT_INT_EDGE_FALLING);
                DL_COMP_setDACCode0(FOC_COMP_W_INST, CompVal);
                DL_Timer_setTimerCount(FOC_CAPTURE_IPD_INST,
                                                    FOC_CAPTURE_IPD_LOAD_VALUE);
                HAL_PWMForceLow(FOC_PWMA0_W_IDX);
                HAL_PWMForceDisable(FOC_PWMA0_V_IDX);
                break;
            case VOLTAGE_VECTOR_BA:
                DL_Timer_setSubscriberChanID(FOC_CAPTURE_IPD_INST, 
                                DL_TIMER_SUBSCRIBER_INDEX_0, FOC_COMP_V_PUB_CH);
                DL_COMP_setOutputInterruptEdge(COMP_V_INST,
                                            DL_COMP_OUTPUT_INT_EDGE_FALLING);
                DL_COMP_setDACCode0(FOC_COMP_V_INST, CompVal);
                DL_Timer_setTimerCount(FOC_CAPTURE_IPD_INST,
                                                    FOC_CAPTURE_IPD_LOAD_VALUE);
                HAL_PWMForceLow(FOC_PWMA0_V_IDX);
                HAL_PWMForceDisable(FOC_PWMA0_U_IDX);
                break;
            case VOLTAGE_VECTOR_AB:
                DL_Timer_setSubscriberChanID(FOC_CAPTURE_IPD_INST, 
                                DL_TIMER_SUBSCRIBER_INDEX_0,FOC_COMP_U_PUB_CH);
                DL_COMP_setOutputInterruptEdge(COMP_U_INST,
                                            DL_COMP_OUTPUT_INT_EDGE_FALLING);
                DL_COMP_setDACCode0(FOC_COMP_U_INST, CompVal);
                DL_Timer_setTimerCount(FOC_CAPTURE_IPD_INST,
                                                    FOC_CAPTURE_IPD_LOAD_VALUE);
                HAL_PWMForceLow(FOC_PWMA0_U_IDX);
                HAL_PWMForceDisable(FOC_PWMA0_V_IDX);
                break;
            default:
                /* This is expected to be empty */
                break;
        }
    }
    else
    {
        CompVal = 127 - CompVal;
        switch(vector)
        {
            case VOLTAGE_VECTOR_AC:
                DL_COMP_setOutputInterruptEdge(COMP_W_INST,
                                                DL_COMP_OUTPUT_INT_EDGE_RISING);
                DL_COMP_setDACCode0(FOC_COMP_W_INST, CompVal);
                DL_Timer_setTimerCount(FOC_CAPTURE_IPD_INST,
                                                    FOC_CAPTURE_IPD_LOAD_VALUE);
                HAL_PWMForceDisable(FOC_PWMA0_U_IDX);
                break;
            case VOLTAGE_VECTOR_CA:
                DL_COMP_setOutputInterruptEdge(COMP_U_INST,
                                                DL_COMP_OUTPUT_INT_EDGE_RISING);
                DL_COMP_setDACCode0(FOC_COMP_U_INST, CompVal);
                DL_Timer_setTimerCount(FOC_CAPTURE_IPD_INST,
                                                    FOC_CAPTURE_IPD_LOAD_VALUE);
                HAL_PWMForceDisable(FOC_PWMA0_W_IDX);
                break;
            case VOLTAGE_VECTOR_BC:
                DL_COMP_setOutputInterruptEdge(COMP_W_INST,
                                                DL_COMP_OUTPUT_INT_EDGE_RISING);
                DL_COMP_setDACCode0(FOC_COMP_W_INST, CompVal);
                DL_Timer_setTimerCount(FOC_CAPTURE_IPD_INST,
                                                    FOC_CAPTURE_IPD_LOAD_VALUE);
                HAL_PWMForceDisable(FOC_PWMA0_V_IDX);
                break;
            case VOLTAGE_VECTOR_CB:
                DL_COMP_setOutputInterruptEdge(COMP_V_INST,
                                                DL_COMP_OUTPUT_INT_EDGE_RISING);
                DL_COMP_setDACCode0(FOC_COMP_V_INST, CompVal);
                DL_Timer_setTimerCount(FOC_CAPTURE_IPD_INST,
                                                    FOC_CAPTURE_IPD_LOAD_VALUE);
                HAL_PWMForceDisable(FOC_PWMA0_W_IDX);
                break;
            case VOLTAGE_VECTOR_BA:
                DL_COMP_setOutputInterruptEdge(COMP_U_INST,
                                                DL_COMP_OUTPUT_INT_EDGE_RISING);
                DL_COMP_setDACCode0(FOC_COMP_U_INST, CompVal);
                DL_Timer_setTimerCount(FOC_CAPTURE_IPD_INST,
                                                    FOC_CAPTURE_IPD_LOAD_VALUE);
                HAL_PWMForceDisable(FOC_PWMA0_V_IDX);
                break;
            case VOLTAGE_VECTOR_AB:
                DL_COMP_setOutputInterruptEdge(COMP_V_INST,
                                                DL_COMP_OUTPUT_INT_EDGE_RISING);
                DL_COMP_setDACCode0(FOC_COMP_V_INST, CompVal);
                DL_Timer_setTimerCount(FOC_CAPTURE_IPD_INST,
                                                    FOC_CAPTURE_IPD_LOAD_VALUE);
                HAL_PWMForceDisable(FOC_PWMA0_U_IDX);
                break;
            default:
                /* This is expected to be empty */
                break;
        }
    }
    #endif
}

void HAL_IPDEnableISR(void)
{

#ifdef __IPD_ENABLE
    NVIC_EnableIRQ(FOC_CAPTURE_IRQN);
#endif
}

void HAL_IPDDisableISR(void)
{
#ifdef __IPD_ENABLE
    NVIC_DisableIRQ(FOC_CAPTURE_IRQN);
#endif
}

uint16_t HAL_IPDGetTime(void)
{
#ifdef __IPD_ENABLE
    return DL_Timer_getCaptureCompareValue(FOC_CAPTURE_IPD_INST, FOC_CAPTURE_IPD_IDX);
#else
    return 0;
#endif
}

uint16_t HAL_IPDGetLoadVal(void)
{
#ifdef __IPD_ENABLE
    return FOC_CAPTURE_IPD_LOAD_VALUE;
#else
    return 0;
#endif
}

void HAL_IPDCOMPInit(void)
{
    HAL_IPDCOMPDACSetZero();
}

void HAL_IPDCOMPDACSetZero(void)
{
#ifdef __IPD_ENABLE
    DL_COMP_setDACCode0(FOC_COMP_W_INST, 0);
    DL_COMP_setDACCode0(FOC_COMP_U_INST, 0);
    DL_COMP_setDACCode0(FOC_COMP_V_INST, 0);
#endif
}
