/// \file baseinit.h
///
/// File which contains all code related to basic system initialization. The basic
/// system initialization "happens" before the main function is called.
///
/// \author Christian Groeling <ch.groeling@gmail.com>

#ifndef __BASEINIT_H__
#define __BASEINIT_H__

/// \brief This function performs the basic system initialization.
///
/// When a reset is raised (e.g. at startup) this is the first function which gets called.
/// It performs the following tasks:
/// * Copy initial values to the data section in ram.
/// * Initialize the bss ram section with 0.
/// * PLL Configuration
/// * SysTick Configuration
///
/// \ingroup StartSequence
extern void baseinit();

#endif
