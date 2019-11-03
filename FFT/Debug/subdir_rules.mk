################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
main.obj: ../main.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C6000 Compiler'
	"E:/CCS5/ccsv5/tools/compiler/c6000_7.3.4/bin/cl6x" -mv6200 -g --include_path="E:/CCS5/ccsv5/tools/compiler/c6000_7.3.4/include" --display_error_number --diag_warning=225 --abi=coffabi --preproc_with_compile --preproc_dependency="main.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


