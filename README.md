## activate workspace
source devel/setup.sh

## rpi
cd ~/ros
su root
source devel/setup.bash
rosrun abot_driver encoders

rosrun abot_driver dc_motors

su root
source devel/setup.bash
roslaunch abot_driver abot_drivers.launch

## comp
rostopic echo /abot/right_wheel/angle
rostopic echo /abot/right_wheel/current_velocity
