################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../TouchGFX/generated/gui_generated/src/startupscreen_screen/StartupScreenViewBase.cpp 

OBJS += \
./TouchGFX/generated/gui_generated/src/startupscreen_screen/StartupScreenViewBase.o 

CPP_DEPS += \
./TouchGFX/generated/gui_generated/src/startupscreen_screen/StartupScreenViewBase.d 


# Each subdirectory must supply rules for building sources it contributes
TouchGFX/generated/gui_generated/src/startupscreen_screen/%.o TouchGFX/generated/gui_generated/src/startupscreen_screen/%.su TouchGFX/generated/gui_generated/src/startupscreen_screen/%.cyclo: ../TouchGFX/generated/gui_generated/src/startupscreen_screen/%.cpp TouchGFX/generated/gui_generated/src/startupscreen_screen/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m7 -std=gnu++14 -g3 -DUSE_HAL_DRIVER -DSTM32H735xx -DPROJECT_APP -DRELEASE -DDEBUG -c -I../Core/Inc -I../TouchGFX/App -I../TouchGFX/target/generated -I../TouchGFX/target -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/ST/touchgfx/framework/include -I../TouchGFX/generated/fonts/include -I../TouchGFX/generated/gui_generated/include -I../TouchGFX/generated/images/include -I../TouchGFX/generated/texts/include -I../TouchGFX/generated/videos/include -I../TouchGFX/gui/include -I"C:/Repos/Firmware/Projects/fw-t2000-001/App/Drivers/BSP/STM32H735G-DK" -I"C:/Repos/Firmware/Projects/fw-t2000-001/App/Drivers/BSP/Components/Common" -I"C:/Repos/Firmware/Projects/fw-t2000-001/App/Drivers/BSP/Components/ft5336" -I"C:/Repos/Firmware/Projects/fw-t2000-001/App/Drivers/BSP/Components/mx25lm51245g" -I"C:/Repos/Firmware/Projects/fw-t2000-001/App/Drivers/BSP/Components/s70kl1281" -I"C:/Repos/Firmware/Projects/fw-t2000-001/App/Core/Inc/App" -I"C:/Repos/Firmware/Projects/fw-t2000-001/Lib/Inc" -I"C:/Repos/Firmware/Projects/fw-t2000-001/Common/Inc" -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -femit-class-debug-always -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-TouchGFX-2f-generated-2f-gui_generated-2f-src-2f-startupscreen_screen

clean-TouchGFX-2f-generated-2f-gui_generated-2f-src-2f-startupscreen_screen:
	-$(RM) ./TouchGFX/generated/gui_generated/src/startupscreen_screen/StartupScreenViewBase.cyclo ./TouchGFX/generated/gui_generated/src/startupscreen_screen/StartupScreenViewBase.d ./TouchGFX/generated/gui_generated/src/startupscreen_screen/StartupScreenViewBase.o ./TouchGFX/generated/gui_generated/src/startupscreen_screen/StartupScreenViewBase.su

.PHONY: clean-TouchGFX-2f-generated-2f-gui_generated-2f-src-2f-startupscreen_screen
