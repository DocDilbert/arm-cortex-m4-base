/*******************************************************************************
* Copyright (C) 2013 Spansion LLC. All Rights Reserved.
*
* This software is owned and published by:
* Spansion LLC, 915 DeGuigne Dr. Sunnyvale, CA  94088-3453 ("Spansion").
*
* BY DOWNLOADING, INSTALLING OR USING THIS SOFTWARE, YOU AGREE TO BE BOUND
* BY ALL THE TERMS AND CONDITIONS OF THIS AGREEMENT.
*
* This software contains source code for use with Spansion
* components. This software is licensed by Spansion to be adapted only
* for use in systems utilizing Spansion components. Spansion shall not be
* responsible for misuse or illegal use of this software for devices not
* supported herein.  Spansion is providing this software "AS IS" and will
* not be responsible for issues arising from incorrect user implementation
* of the software.
*
* SPANSION MAKES NO WARRANTY, EXPRESS OR IMPLIED, ARISING BY LAW OR OTHERWISE,
* REGARDING THE SOFTWARE (INCLUDING ANY ACOOMPANYING WRITTEN MATERIALS),
* ITS PERFORMANCE OR SUITABILITY FOR YOUR INTENDED USE, INCLUDING,
* WITHOUT LIMITATION, THE IMPLIED WARRANTY OF MERCHANTABILITY, THE IMPLIED
* WARRANTY OF FITNESS FOR A PARTICULAR PURPOSE OR USE, AND THE IMPLIED
* WARRANTY OF NONINFRINGEMENT.
* SPANSION SHALL HAVE NO LIABILITY (WHETHER IN CONTRACT, WARRANTY, TORT,
* NEGLIGENCE OR OTHERWISE) FOR ANY DAMAGES WHATSOEVER (INCLUDING, WITHOUT
* LIMITATION, DAMAGES FOR LOSS OF BUSINESS PROFITS, BUSINESS INTERRUPTION,
* LOSS OF BUSINESS INFORMATION, OR OTHER PECUNIARY LOSS) ARISING FROM USE OR
* INABILITY TO USE THE SOFTWARE, INCLUDING, WITHOUT LIMITATION, ANY DIRECT,
* INDIRECT, INCIDENTAL, SPECIAL OR CONSEQUENTIAL DAMAGES OR LOSS OF DATA,
* SAVINGS OR PROFITS,
* EVEN IF SPANSION HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
* YOU ASSUME ALL RESPONSIBILITIES FOR SELECTION OF THE SOFTWARE TO ACHIEVE YOUR
* INTENDED RESULTS, AND FOR THE INSTALLATION OF, USE OF, AND RESULTS OBTAINED
* FROM, THE SOFTWARE.
*
* This software may be replicated in part or whole for the licensed use,
* with the restriction that this Disclaimer and Copyright notice must be
* included with each copy of this software, whether used in part or whole,
* at all times.
*/
/******************************************************************************/
/** \file fgpio.h
 **
 ** Headerfile for Fast GPIO functions
 **
 ** History:
 **   - 2014-01-10  1.0  EZh    First version.
 **   - 2015-02-05  1.1  MSc    Moved from PDL to MCU template
 **
 ******************************************************************************/

#ifndef __FGPIO_H__
#define __FGPIO_H__

/******************************************************************************/
/* Include files                                                              */
/******************************************************************************/

/* C binding of definitions if building with C++ compiler */
#ifdef __cplusplus
extern "C"
{
#endif

/**
 ******************************************************************************
 ** \defgroup FGpioGroup Fast GPIO Defintions (Fast GPIO)
 **
 ** Definitions of Fast GPIO and resource pin relocation
 **
 ** \attention
 **            - before using the Fast GPIO output, FGpio_EnableOutput() has
 **              to be called.
 ******************************************************************************/
//@{

/******************************************************************************/
/* \brief Fast GPIO intialization structure                                   */
/******************************************************************************/

typedef struct stc_fgpio1pin_init
{
    boolean_t bOutput;
    boolean_t bInitVal;
    boolean_t bPullup;
} stc_fgpio1pin_init_t;


/**
 ******************************************************************************
 ** \brief GPIO port list
 ******************************************************************************/
typedef enum en_fgpio_port
{
    FGpioPort0 = 0u,   ///< Fast GPIO port 0
    FGpioPort1 = 1u,   ///< Fast GPIO port 1
    FGpioPort2 = 2u,   ///< Fast GPIO port 2
    FGpioPort3 = 3u,   ///< Fast GPIO port 3
    FGpioPort4 = 4u,   ///< Fast GPIO port 4
    FGpioPort5 = 5u,   ///< Fast GPIO port 5
    FGpioPort6 = 6u,   ///< Fast GPIO port 6
    FGpioPort7 = 7u,   ///< Fast GPIO port 7
    FGpioPort8 = 8u,   ///< Fast GPIO port 8
    FGpioPort9 = 9u,   ///< Fast GPIO port 9
    FGpioPortA = 10u,  ///< Fast GPIO port 10
    FGpioPortB = 11u,  ///< Fast GPIO port 11
    FGpioPortC = 12u,  ///< Fast GPIO port 12
    FGpioPortD = 13u,  ///< Fast GPIO port 13
    FGpioPortE = 14u,  ///< Fast GPIO port 14
    FGpioPortF = 15u,  ///< Fast GPIO port 15

}en_fgpio_port_t;

/******************************************************************************/
/* Defines                                                                    */
/******************************************************************************/

#define FGpio_EnableOutput(port, pins)   do {uint32_t addr; \
                                            addr = (uint32_t)&FM_GPIO->FPOER0 + (uint32_t)port*4u; \
                                            *(uint16_t*)(addr) = pins;  \
                                            }while(0);
#define FGpio_DisableOutput(port)        do {uint32_t addr; \
                                            addr = (uint32_t)&FM_GPIO->FPOER0 + (uint32_t)port*4u; \
                                            *(uint16_t*)(addr) = 0x0000u;  \
                                            }while(0);

#define FGpio1pin_InitIn(p,settings)    do{ stc_fgpio1pin_init_t __v__;\
                                         __v__.bPullup=0u;__v__.bInitVal=0u;\
                                         (settings);\
                                         p##_INITIN(__v__); }while(0)

#define FGpio1pin_InitOut(p,settings)   do{ stc_fgpio1pin_init_t __v__;\
                                         __v__.bPullup=0u;__v__.bInitVal=0u;\
                                         (settings);\
                                         p##_INITOUT(__v__); }while(0)

#define FGpio1pin_Init(p,settings)      do{ stc_fgpio1pin_init_t __v__;__v__.bOutput=0u;\
                                         __v__.bPullup=0u;__v__.bInitVal=0u;\
                                         (settings);\
                                         p##_INIT( __v__ ); }while(0)

#define FGpio1pin_InitDirectionInput    (__v__.bOutput=0u)
#define FGpio1pin_InitDirectionOutput   (__v__.bOutput=1u)
#define FGpio1pin_InitPullup(v)         (__v__.bPullup=(v))
#define FGpio1pin_InitVal(v)            (__v__.bInitVal=(v))



#define FGpio1pin_Get(p)	         p##_GET
#define FGpio1pin_Put(p,v)           p##_PUT(v)


/******************************************************************************/
/* Inclusion of GPIO defines of user defined device                           */
/******************************************************************************/

//@} // FGpioGroup

#ifdef __cplusplus
}
#endif

#endif /* __FPIO_H__ */

/******************************************************************************/
/* EOF (not truncated)                                                        */
/******************************************************************************/
