# COP290

This is the repository for OpenCV assignment as part COP290: Design Practices course.  <br /> <br />
## How to run the file
1. clone the repo (or Download Zip file)
2. Open the terminal and give the command: ``` make run ```.
3. Make sure that the image that you wish to open is present in the same directory of the code.
4. An executable named `video` will be created. Run the executable with the command: ```./video image_name``` where image_name is the name of the image that you wish to open (along with the extension like .jpg, .jpeg, .png etc.)
5. All the arguments given (if any) after ```./video image_name``` will be ignored.
6. Some machines may ask for permissions to open the display windoe. Allow the terminal to take control of the machine.


## To do list(For the reference of developers):

- [x] Reading the file

  - Opening the image reader in displaying window. 
  - Done by Deepanshu Rohilla



- [x] Getting coordinates of click

  - Taking four coordinates of the screen to crop the image.
  - Done by Prashant Mishra


- [x] Function to crop the image and save cropped image in the same folder.

  - Taking coordinates as function inputs and writing out the cropped image in the same folder.
  - Done by Prashant Mishra

- [x] Makefile and README 
  - Giving the section of "How to run the code" in README and making the makefile.
  - Enabling argument passing from the command line.
  - Done by Deepanshu Rohilla


