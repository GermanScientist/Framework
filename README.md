# Framework

Note: This project is currently being reworked from scratch. 
The reworked version of this project will be hosted on a different GitHub account: https://github.com/JackHulspas/VisualizationFramework

The new version will in addition feature unit tests, a better class structure and overall improvement of the code.

# UML class diagram

![image-removebg-preview](https://github.com/GermanScientist/Framework/assets/66174242/df5f2b9d-37c1-4620-a125-90b1454fc026)

# Description project
The framework is able to render a 3D scene in realtime, one of the ways this framework could be used is to create a 3D game.
With the use of this framework, the end-user is able to render and simulate a realtime 3D scene, without requiring any OpenGL knowledge. All the rendering, shadowmapping, and collision, will be provided by the framework.

# Install instructions

This project has two main code directories: "demo" and "myFramework". To run the demo project, follow the following steps:
* Clone (or fork) this repository
* Locate the source directory (Framework/)
* If none exists, create a build directory (mkdir build)
* Inside the terminal, make sure to be in the build directory (cd build)
* If you are located in the build directory using the terminal, execute the cmake file (cmake ..)

Make and Cmake is required to run this project. All other depencies will be managed by Cmake.
If you wish to read the documentation, you must also install DoxyGen as a dependency.

If you wish to create new files in the demo directory, or if you wish to add an entire new directory, you must edit the Cmake file.
