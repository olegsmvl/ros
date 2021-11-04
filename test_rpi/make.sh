rm -Rf build
mkdir build
g++ app.cpp -lwiringPi -o build/app
./app
