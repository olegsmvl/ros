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

## build
cd ~/ros
catkin_make

## rpi
cd ~/ros
sudo -E su - for working gpio wiring (need sudo)
source devel/setup.bash
rosrun abot_driver encoders

rosrun abot_driver dc_motors


sudo -E su  - for working gpio wiring (need sudo)
source devel/setup.bash
roslaunch abot_driver abot_drivers.launch

## comp
rostopic echo /abot/right_wheel/angle
rostopic echo /abot/right_wheel/current_velocity

rqt


