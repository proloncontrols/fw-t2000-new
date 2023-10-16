################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Drivers/STM32H7xx_HAL_Driver/Src/subdir.mk
-include Core/Startup/subdir.mk
-include Core/Src/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := LoaderM24C32-DFDW6TP
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
LoaderM24C32-DFDW6TP.elf \

MAP_FILES += \
LoaderM24C32-DFDW6TP.map \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
LoaderM24C32-DFDW6TP.list \

OBJCOPY_HEX += \
LoaderM24C32-DFDW6TP.hex \


# All Target
all:
	+@$(MAKE) --no-print-directory main-build && $(MAKE) --no-print-directory post-build

# Main-build Target
main-build: LoaderM24C32-DFDW6TP.elf secondary-outputs

# Tool invocations
LoaderM24C32-DFDW6TP.elf LoaderM24C32-DFDW6TP.map: $(OBJS) $(USER_OBJS) C:\ProlonDev\Projects\T2000\Firmware\Code\LoaderM24C32-DFDW6TP\LoaderM24C32-DFDW6TP.ld makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-gcc -o "LoaderM24C32-DFDW6TP.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m7 -T"C:\ProlonDev\Projects\T2000\Firmware\Code\LoaderM24C32-DFDW6TP\LoaderM24C32-DFDW6TP.ld" --specs=nosys.specs -Wl,-Map="LoaderM24C32-DFDW6TP.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

LoaderM24C32-DFDW6TP.list: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "LoaderM24C32-DFDW6TP.list"
	@echo 'Finished building: $@'
	@echo ' '

LoaderM24C32-DFDW6TP.hex: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objcopy  -O ihex $(EXECUTABLES) "LoaderM24C32-DFDW6TP.hex"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) LoaderM24C32-DFDW6TP.elf LoaderM24C32-DFDW6TP.hex LoaderM24C32-DFDW6TP.list LoaderM24C32-DFDW6TP.map default.size.stdout
	-@echo ' '

post-build:
	"C:\ProlonDev\DevTools\Loader\CopyLoader.bat" "C:\ProlonDev\Projects\T2000\Firmware\Code\LoaderM24C32-DFDW6TP\Debug\LoaderM24C32-DFDW6TP.elf" "C:\Program Files\STMicroelectronics\STM32Cube\STM32CubeProgrammer\bin\ExternalLoader\LoaderM24C32-DFDW6TP.stldr"
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_HEX)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents main-build fail-specified-linker-script-missing warn-no-linker-script-specified post-build

-include ../makefile.targets
