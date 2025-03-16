% WRS-3 - Hardware README
% Benoit Rat, J. Gabriel Ramirez E. (Seven Solutions)

### License

All the files in this directory (and its subdirectories) are subject to
 the **CERN OHL v1.x** licence.

~~~~~~~
Copyright CERN 2013.
This documentation describes Open Hardware and is licensed under the
CERN OHL v.1.2.

You may redistribute and modify this documentation under the terms of the
CERN OHL v.1.2. (http://ohwr.org/cernohl). This documentation is distributed
WITHOUT ANY EXPRESS OR IMPLIED WARRANTY, INCLUDING OF
MERCHANTABILITY, SATISFACTORY QUALITY AND FITNESS FOR A
PARTICULAR PURPOSE. Please see the CERN OHL v.1.2 for applicable
conditions
~~~~~~~~~~~~~~~~~


Introduction
=================

The following projects have been developed with Altium 10.x
The White Rabbit Switch is composed of various elements:

* A `SCB`: switch board core
* A Minibackplane
* A Box to enclose everything.

Structure
=================

The organization of the directories is as follow:

* `Docs_PDF`: Generated documentation (Schematics, Manufacturing info, ...)
* `LIBS`: Common components libraries for altium projects. 
* `SCB_SAM9G45`: Files for the Switch board cores
* `mini_backplane_18SFP`: Files for the standard miniBackplane: 18 SFP Ports .
* `mini_backplane_simple`: Simple minibackplane with 6 ports SFP.
* `mini_backplane_test`: minibackplane created to test various PHY in order to create a copper minibackplane.





