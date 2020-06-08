#include "taskerconfig.hpp" // for myTasker
#include "stkregisters.hpp" // for STK
#include "rccregisters.hpp" // for RCC

extern "C" 
{
 int __low_level_init(void)   
 {
     RCC::AHB1ENR::GPIOCEN::Enable::Set() ;
     GPIOC::MODERPack<
         GPIOC::MODER::MODER8::Output,
         GPIOC::MODER::MODER9::Output,
         GPIOC::MODER::MODER5::Output
         >::Set() ;

     STK::LOAD::Write(16000000U/1000U - 1U) ;
     STK::VAL::Write(0U);
     STK::CTRLPack<
         STK::CTRL::ENABLE::Enable,
         STK::CTRL::CLKSOURCE::CpuClock,
         STK::CTRL::TICKINT::EnableInterrupt
         >::Set() ;
     return 1 ;
 }
}

int main()
{
 	myTasker::Start() ;
  	return 0;
}
