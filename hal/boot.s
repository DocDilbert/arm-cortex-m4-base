.syntax unified
.thumb
.section .boot, "xa"
.align 2
.global vectors
vectors: 

    .long stack_top
    .long _Reset              // Reset 
    .long _Hang               // NMI 
    .long _Hang               // Hard Fault
    .long _Hang               // MPU Fault
    .long _Hang               // Bus Fault
    .long _Hang               // Usage Fault
    .long _Hang               // Reserved
    .long _Hang               // Reserved
    .long _Hang               // Reserved
    .long _Hang               // Reserved
    .long _Hang               // SVCall
    .long _Hang               // Debug Monitor
    .long _Hang               // Reserved
    .long _Hang               // PendSV
    .long systick_handler     // SysTick
    .long _Hang               // IRQ000_Handler
    .long _Hang               // IRQ001_Handler
    .long _Hang               // IRQ002_Handler
    .long _Hang               // IRQ003_Handler
    .long _Hang               // IRQ004_Handler
    .long _Hang               // IRQ005_Handler
    .long _Hang               // IRQ006_Handler
    .long _Hang               // IRQ007_Handler
    .long _Hang               // IRQ008_Handler
    .long _Hang               // IRQ009_Handler
    .long _Hang               // IRQ010_Handler
    .long _Hang               // IRQ011_Handler
    .long _Hang               // IRQ012_Handler
    .long _Hang               // IRQ013_Handler
    .long _Hang               // IRQ014_Handler
    .long _Hang               // IRQ015_Handler
    .long _Hang               // IRQ016_Handler
    .long _Hang               // IRQ017_Handler
    .long _Hang               // IRQ018_Handler
    .long _Hang               // IRQ019_Handler
    .long _Hang               // IRQ020_Handler
    .long _Hang               // IRQ021_Handler
    .long _Hang               // IRQ022_Handler
    .long _Hang               // IRQ023_Handler
    .long _Hang               // IRQ024_Handler
    .long _Hang               // IRQ025_Handler
    .long _Hang               // IRQ026_Handler
    .long _Hang               // IRQ027_Handler
    .long _Hang               // IRQ028_Handler
    .long _Hang               // IRQ029_Handler
    .long _Hang               // IRQ030_Handler
    .long _Hang               // IRQ031_Handler
    .long _Hang               // IRQ032_Handler
    .long _Hang               // IRQ033_Handler
    .long _Hang               // IRQ034_Handler
    .long _Hang               // IRQ035_Handler
    .long _Hang               // IRQ036_Handler
    .long _Hang               // IRQ037_Handler
    .long _Hang               // IRQ038_Handler
    .long _Hang               // IRQ039_Handler
    .long _Hang               // IRQ040_Handler
    .long _Hang               // IRQ041_Handler
    .long _Hang               // IRQ042_Handler
    .long _Hang               // IRQ043_Handler
    .long _Hang               // IRQ044_Handler
    .long _Hang               // IRQ045_Handler
    .long _Hang               // IRQ046_Handler
    .long _Hang               // IRQ047_Handler
    .long _Hang               // IRQ048_Handler
    .long _Hang               // IRQ049_Handler
    .long _Hang               // IRQ050_Handler
    .long _Hang               // IRQ051_Handler
    .long _Hang               // IRQ052_Handler
    .long _Hang               // IRQ053_Handler
    .long _Hang               // IRQ054_Handler
    .long _Hang               // IRQ055_Handler
    .long _Hang               // IRQ056_Handler
    .long _Hang               // IRQ057_Handler
    .long _Hang               // IRQ058_Handler
    .long _Hang               // IRQ059_Handler
    .long _Hang               // IRQ060_Handler
    .long _Hang               // IRQ061_Handler
    .long _Hang               // IRQ062_Handler
    .long _Hang               // IRQ063_Handler
    .long _Hang               // IRQ064_Handler
    .long _Hang               // IRQ065_Handler
    .long _Hang               // IRQ066_Handler
    .long _Hang               // IRQ067_Handler
    .long _Hang               // IRQ068_Handler
    .long _Hang               // IRQ069_Handler
    .long _Hang               // IRQ070_Handler
    .long _Hang               // IRQ071_Handler
    .long _Hang               // IRQ072_Handler
    .long _Hang               // IRQ073_Handler
    .long _Hang               // IRQ074_Handler
    .long _Hang               // IRQ075_Handler
    .long _Hang               // IRQ076_Handler
    .long _Hang               // IRQ077_Handler
    .long _Hang               // IRQ078_Handler
    .long _Hang               // IRQ079_Handler
    .long _Hang               // IRQ080_Handler
    .long _Hang               // IRQ081_Handler
    .long _Hang               // IRQ082_Handler
    .long _Hang               // IRQ083_Handler
    .long _Hang               // IRQ084_Handler
    .long _Hang               // IRQ085_Handler
    .long _Hang               // IRQ086_Handler
    .long _Hang               // IRQ087_Handler
    .long _Hang               // IRQ088_Handler
    .long _Hang               // IRQ089_Handler
    .long _Hang               // IRQ090_Handler
    .long _Hang               // IRQ091_Handler
    .long _Hang               // IRQ092_Handler
    .long _Hang               // IRQ093_Handler
    .long _Hang               // IRQ094_Handler
    .long _Hang               // IRQ095_Handler
    .long _Hang               // IRQ096_Handler
    .long _Hang               // IRQ097_Handler
    .long _Hang               // IRQ098_Handler
    .long _Hang               // IRQ099_Handler
    .long _Hang               // IRQ100_Handler
    .long _Hang               // IRQ101_Handler
    .long _Hang               // IRQ102_Handler
    .long _Hang               // IRQ103_Handler
    .long _Hang               // IRQ104_Handler
    .long _Hang               // IRQ105_Handler
    .long _Hang               // IRQ106_Handler
    .long _Hang               // IRQ107_Handler
    .long _Hang               // IRQ108_Handler
    .long _Hang               // IRQ109_Handler
    .long _Hang               // IRQ110_Handler
    .long _Hang               // IRQ111_Handler
    .long _Hang               // IRQ112_Handler
    .long _Hang               // IRQ113_Handler
    .long _Hang               // IRQ114_Handler
    .long _Hang               // IRQ115_Handler
    .long _Hang               // IRQ116_Handler
    .long _Hang               // IRQ117_Handler
    .long _Hang               // IRQ118_Handler
    .long _Hang               // IRQ119_Handler
    .long _Hang               // IRQ120_Handler
    .long _Hang               // IRQ121_Handler
    .long _Hang               // IRQ122_Handler
    .long _Hang               // IRQ123_Handler
    .long _Hang               // IRQ124_Handler
    .long _Hang               // IRQ125_Handler
    .long _Hang               // IRQ126_Handler
    .long _Hang               // IRQ127_Handler

.thumb_func   
_Hang:
    B .
 
.thumb_func 
_Reset:
    NOP
    B _Start 
        
.thumb_func 
.global _Start
_Start: 
    BL init 
    BL main 
    
.thumb_func   
 _SysTick:
    NOP
    

      