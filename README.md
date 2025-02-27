## instructions
https://amperka.ru/blogs/projects/abot-robot-part-1

## install rpi
- install ubuntu server 20.04 64 bit with imager. set ssh pass and wifi setting before write image
- apt update 
- apt upgrade 
- reboot
- sudo passwd pi (change pass)
- Пароль для root не установлен в Ubuntu по умолчанию, и вход в систему пользователя root отключён. Включим учетную запись root и установим для неё пароль. Затем переключимся на root:
- sudo passwd root
- sudo apt install xubuntu-desktop (select lightdm)
- reboot
- https://wiki.ros.org/noetic/Installation/Ubuntu (install ros desktop full)

## install WiringPi
В терминале на Raspberry Pi вводим:

git clone https://github.com/WiringPi/WiringPi.git
cd WiringPi
git checkout tags/3.0  
./build
Убедимся, что библиотека собралась и установилась правильно:

gpio -v

## install ros packages
sudo apt install ros-noetic-gmapping -y
sudo apt install ros-noetic-joy -y

# set rpi ubuntu swap file
https://www.digitalocean.com/community/tutorials/how-to-add-swap-space-on-ubuntu-18-04-ru 
set 1Gb

sudo fallocate -l 1G /swapfile
sudo chmod 600 /swapfile
sudo mkswap /swapfile
sudo swapon /swapfile
echo '/swapfile none swap sw 0 0' | sudo tee -a /etc/fstab
sudo sysctl vm.swappiness=10

## build
cd ~/ros
catkin_make

## rpi
Пароль для root не установлен в Ubuntu по умолчанию, и вход в систему пользователя root отключён. Включим учетную запись root и установим для неё пароль. Затем переключимся на root:

sudo passwd root

cd ~/ros
su root - for working gpio wiring (need root)
source devel/setup.bash
rosrun abot_driver encoders

rosrun abot_driver dc_motors


su root  - for working gpio wiring (need root)
source devel/setup.bash
roslaunch abot_driver abot_drivers.launch

## comp
rostopic echo /abot/right_wheel/angle
rostopic echo /abot/right_wheel/current_velocity

rqt


