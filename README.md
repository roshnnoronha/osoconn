# The Osoconn Project
## Introduction
Osoconn is a free and open source steel connection design application. The objective of the Osoconn Project is to develop a calculation repository of the various types of connection details used in the steel construction industry, and to make them available free of cost for educational purpose.The program can be used as either a web app or downloaded and run as a command line app (CLA). 
## Command Line App
The Osoconn Command Line App (CLA) can be run on the Linux command line. It is a simple utility that provides all the functionality of the Web App along with the convenience of being able to run multiple connections at once.  
###Setup
This setup instructions assumes that the user is using a bash shell. Navigate to the location at which the repository has to be copied to using 
```
$ cd path/to/repository
``` 
Next clone the repository using the following command (ensure git is installed for this step).
```
$ git clone https://github.com/roshnnoronha/osoconn.git
```
Create a `build` directory within the `cla` directory and navigate to this directory.
```
$ mkdir ./osoconn/cla/build
$ cd ./osoconn/cla/build
```
Build the binary file (this step requires `cmake` and `make` to be installed).
```
$ cmake ..
$ make
```
This will create a executable `osoconn` and a folder `data`. These entities are required to run the program and can be copied to any other folder if required.
```
$ cp ./osoconn /path/to/executable/
$ cp -r ./data /path/to/executable/
```
###Testing
To check if program is working we can test it by running it on one of the example input files also available in the repository.
```
$ /path/to/executable/osoconn /path/to/repository/osoconn/cla/examples/SC001/SC001AM10/SC001_1.cin
```
## Web App
The web app is available online at https://osoconn.com. To run the web app on Localhost copy the contents in the `web` folder to the htdocs folder of an Apache server distribution. This is typically located in the `/var/www/html` path for Linux.
```
$ cp -r path/to/repository/osoconn/web/* /var/www/html/ 
```
Build and compile the CLA as instructed in the previous section. Copy the built program to a folder called `bin` in the htdocs folder.
```
$ mkdir /var/www/html/bin
$ cp /path/to/executable/osoconn /var/www/html/bin/
$ cp -r /path/to/executable/data /var/www/html/bin/
```
Start up the server and navigate to `localhost` in the browser to run the app.
