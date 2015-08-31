/// \file faults.cpp
///
/// File contains the HardFault, MemManage fault, UsageFault, and BusFault fault handlers.
///
/// \author Christian Groeling <ch.groeling@gmail.com>

/// Hard fault interrupt service routine
///
/// A HardFault is an exception that occurs because of an error during exception processing, or because
/// an exception cannot be managed by any other exception mechanism. HardFaults have a fixed priority of -1,
/// meaning they have higher priority than any exception with configurable priority.
///
/// \attention C Linkage is required for interrupt service routines.
///
extern "C" void FAULTS_isrHardFault()
{
    while (1)
    {
    }
}

/// Memory manage fault interrupt service routine
///
/// A MemManage fault is an exception that occurs because of a memory protection related fault. The the fixed memory
/// protection constraints determines this fault, for both instruction and data memory transactions. This fault is always
/// used to abort instruction accesses to Execute Never (XN) memory regions.
///
/// \attention C Linkage is required for interrupt service routines.
///
extern "C" void FAULTS_isrMemManageFault()
{
    while (1)
    {
    }
}

/// Bus fault interrupt service routine
///
/// A BusFault is an exception that occurs because of a memory related fault for an instruction or data memory transaction.
/// This might be from an error detected on a bus in the memory system.
///
/// \attention C Linkage is required for interrupt service routines.
///
extern "C" void FAULTS_isrBusFault()
{
    while (1)
    {
    }
}

/// Usage fault interrupt service routine
///
/// A UsageFault is an exception that occurs because of a fault related to instruction execution. This includes:
/// * an undefined instruction
/// * an illegal unaligned access
/// * invalid state on instruction execution
/// * an error on exception return.
///
/// The following can cause a UsageFault when the core is configured to report them:
/// * an unaligned address on word and halfword memory access
/// * division by zero.
///
/// \attention C Linkage is required for interrupt service routines.
///
extern "C" void FAULTS_isrUsageFault()
{
    while (1)
    {
    }
}

