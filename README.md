# COP290

This is the repository for OpenCV assignment as part COP290: Design Practices course.  <br /> <br />
## How to run the file
1. clone the repo (or Download Zip file)
2. Open the terminal and give the command: ``` make run ```.
3. If you are using opencv4 and some error occur on running ```make run``` command, run the code with ```make run2``` command.
4. Make sure that the image that you wish to open is present in the same directory of the code.
5. An executable named `video` will be created. Run the executable with the command: ```./video image_name``` where image_name is the name of the image that you wish to open.
6. Enter the name along with the extension like .jpg, .jpeg, .png etc.
7. All the arguments given (if any) after ```./video image_name``` will be ignored.
8. Some machines may ask for permissions to open the display window. Allow the terminal to take control of the machine.

## How to crop the image
1. Once the desired image appears on the screen, you can crop the image using mouse clicks.
2. To get the top view, the points are selected as follows:
    - First point corresponds to the top left corner.
    - Second point corresponds to the top right corner.
    - Third point corresponds to the bottom left corner.
    - Fourth point corresponds to the bottom right corner.


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


