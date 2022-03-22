#! /bin/bash

atf_path=../arm-trusted-firmware
uboot_path=../u-boot-v2022.01
BL31=../arm-trusted-firmware/build/rk3399/release/bl31/bl31.elf

cd $atf_path

CROSS_COMPILE=aarch64-linux-gnu- make PLAT=rk3399 bl31

cd $uboot_path

cp  $BL31 ./

CROSS_COMPILE=aarch64-linux-gnu- make evb-rk3399_defconfig

CROSS_COMPILE=aarch64-linux-gnu- make all

if [ $? -eq 0 ]
then
	echo build_success
else
	echo build_failed
fi





