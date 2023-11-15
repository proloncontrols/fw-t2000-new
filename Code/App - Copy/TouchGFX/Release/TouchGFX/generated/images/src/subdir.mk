################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../TouchGFX/generated/images/src/BitmapDatabase.cpp \
../TouchGFX/generated/images/src/image_CoolingON.cpp \
../TouchGFX/generated/images/src/image_Humidity.cpp \
../TouchGFX/generated/images/src/image_Outside.cpp \
../TouchGFX/generated/images/src/image_ProLon_Logo_4.cpp \
../TouchGFX/generated/images/src/image_Prolon_40_1.cpp \
../TouchGFX/generated/images/src/image_Setting.cpp \
../TouchGFX/generated/images/src/image_Snowflake.cpp \
../TouchGFX/generated/images/src/image_StandbyMode.cpp 

OBJS += \
./TouchGFX/generated/images/src/BitmapDatabase.o \
./TouchGFX/generated/images/src/image_CoolingON.o \
./TouchGFX/generated/images/src/image_Humidity.o \
./TouchGFX/generated/images/src/image_Outside.o \
./TouchGFX/generated/images/src/image_ProLon_Logo_4.o \
./TouchGFX/generated/images/src/image_Prolon_40_1.o \
./TouchGFX/generated/images/src/image_Setting.o \
./TouchGFX/generated/images/src/image_Snowflake.o \
./TouchGFX/generated/images/src/image_StandbyMode.o 

CPP_DEPS += \
./TouchGFX/generated/images/src/BitmapDatabase.d \
./TouchGFX/generated/images/src/image_CoolingON.d \
./TouchGFX/generated/images/src/image_Humidity.d \
./TouchGFX/generated/images/src/image_Outside.d \
./TouchGFX/generated/images/src/image_ProLon_Logo_4.d \
./TouchGFX/generated/images/src/image_Prolon_40_1.d \
./TouchGFX/generated/images/src/image_Setting.d \
./TouchGFX/generated/images/src/image_Snowflake.d \
./TouchGFX/generated/images/src/image_StandbyMode.d 


# Each subdirectory must supply rules for building sources it contributes
TouchGFX/generated/images/src/%.o TouchGFX/generated/images/src/%.su TouchGFX/generated/images/src/%.cyclo: ../TouchGFX/generated/images/src/%.cpp TouchGFX/generated/images/src/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m7 -std=gnu++14 -g3 -DUSE_HAL_DRIVER -DSTM32H735xx -DPROJECT_APP -DRELEASE -DE2_DEVICE_BR24L04W -c -I../Core/Inc -I../TouchGFX/App -I../TouchGFX/target/generated -I../TouchGFX/target -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/ST/touchgfx/framework/include -I../TouchGFX/generated/fonts/include -I../TouchGFX/generated/gui_generated/include -I../TouchGFX/generated/images/include -I../TouchGFX/generated/texts/include -I../TouchGFX/generated/videos/include -I../TouchGFX/gui/include -I"C:/ProlonDev/Projects/T2000/Firmware/Code/App/Drivers/BSP/STM32H735G-DK" -I"C:/ProlonDev/Projects/T2000/Firmware/Code/App/Drivers/BSP/Components/Common" -I"C:/ProlonDev/Projects/T2000/Firmware/Code/App/Drivers/BSP/Components/ft5336" -I"C:/ProlonDev/Projects/T2000/Firmware/Code/App/Drivers/BSP/Components/mx25lm51245g" -I"C:/ProlonDev/Projects/T2000/Firmware/Code/App/Drivers/BSP/Components/s70kl1281" -I"C:/ProlonDev/Projects/T2000/Firmware/Code/App/Core/Inc/App" -I"C:/ProlonDev/Projects/T2000/Firmware/Code/App/Core/Inc/App/Ext" -I"C:/ProlonDev/Projects/T2000/Firmware/Code/Lib/Inc" -I"C:/ProlonDev/Projects/T2000/Firmware/Code/Common/Inc" -I"C:/ProlonDev/Projects/T2000/Firmware/Code/Common/Inc/TouchGFX" -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -femit-class-debug-always -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-TouchGFX-2f-generated-2f-images-2f-src

clean-TouchGFX-2f-generated-2f-images-2f-src:
	-$(RM) ./TouchGFX/generated/images/src/BitmapDatabase.cyclo ./TouchGFX/generated/images/src/BitmapDatabase.d ./TouchGFX/generated/images/src/BitmapDatabase.o ./TouchGFX/generated/images/src/BitmapDatabase.su ./TouchGFX/generated/images/src/image_CoolingON.cyclo ./TouchGFX/generated/images/src/image_CoolingON.d ./TouchGFX/generated/images/src/image_CoolingON.o ./TouchGFX/generated/images/src/image_CoolingON.su ./TouchGFX/generated/images/src/image_Humidity.cyclo ./TouchGFX/generated/images/src/image_Humidity.d ./TouchGFX/generated/images/src/image_Humidity.o ./TouchGFX/generated/images/src/image_Humidity.su ./TouchGFX/generated/images/src/image_Outside.cyclo ./TouchGFX/generated/images/src/image_Outside.d ./TouchGFX/generated/images/src/image_Outside.o ./TouchGFX/generated/images/src/image_Outside.su ./TouchGFX/generated/images/src/image_ProLon_Logo_4.cyclo ./TouchGFX/generated/images/src/image_ProLon_Logo_4.d ./TouchGFX/generated/images/src/image_ProLon_Logo_4.o ./TouchGFX/generated/images/src/image_ProLon_Logo_4.su ./TouchGFX/generated/images/src/image_Prolon_40_1.cyclo ./TouchGFX/generated/images/src/image_Prolon_40_1.d ./TouchGFX/generated/images/src/image_Prolon_40_1.o ./TouchGFX/generated/images/src/image_Prolon_40_1.su ./TouchGFX/generated/images/src/image_Setting.cyclo ./TouchGFX/generated/images/src/image_Setting.d ./TouchGFX/generated/images/src/image_Setting.o ./TouchGFX/generated/images/src/image_Setting.su ./TouchGFX/generated/images/src/image_Snowflake.cyclo ./TouchGFX/generated/images/src/image_Snowflake.d ./TouchGFX/generated/images/src/image_Snowflake.o ./TouchGFX/generated/images/src/image_Snowflake.su ./TouchGFX/generated/images/src/image_StandbyMode.cyclo ./TouchGFX/generated/images/src/image_StandbyMode.d ./TouchGFX/generated/images/src/image_StandbyMode.o ./TouchGFX/generated/images/src/image_StandbyMode.su

.PHONY: clean-TouchGFX-2f-generated-2f-images-2f-src

