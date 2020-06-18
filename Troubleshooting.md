# Introduce some sapzil guide for Hardware

## Serial Communication Optimization for Ubuntu 18.04

### 시리얼통신 저지연 세팅하기
$ sudo apt install setserial
$ setserial /dev/ttyUSB[0-9] low_latency

### 부팅때 마다 자동으로 저지연 세팅
$ sudo gedit /etc/udev/rules.d/99-ttyUSB.rules

KERNEL=="ttyUSB[0-9]*", MODE="666", RUN+="/bin/setserial /dev/%k low_latency"
라고 쓰고 저장

### dialout 그룹에 추가하여 권한 부여
$ sudo usermod -a -G dialout YOUR_ID

### 재부팅
$ sudo reboot

### 재부팅 후 제대로 되었나 확인

$ setserial /dev/ttyUSB[0-9]
> Flags: low_latency 가 뜨면 성공

$ id
> dialout 이 목록에 있으면 성공
