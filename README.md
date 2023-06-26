# BUILD
```bash
cd build 
cmake ..
make
```
# RUN
In main directory:
```bash
./game mapa.txt status.txt rozkazy.txt [t]
```
* mapa.txt - file representing the map
* status.txt - includes information on the quantity of gold and the status of units
* rozkazy.txt - orders to units
* [t] - optional argument, time regime for program execution 
# DOCUMENTATION
## REQUIREMENTS
* doxygen
## GENERATION OF DOCUMENTATION
In the root directory, run:
```bash
doxygen doxyfile.doxy
```
To view the documentation run:
```bash
firefox doc/html/index.html
```
# Tests
The unit tests are located in the tests directory
## REQUIREMENTS
* Google Test
### Installation of the Google tests library
```bash
sudo apt-get install libgtest-dev
cd /usr/src/gtest
sudo cmake CMakeLists.txt
sudo make
sudo cp lib/*.a /usr/lib
```
## RUN
From root directory:
```bash
cd tests
mkdir build
cd build
cmake ..
make 
cd ..
./test_test
```

