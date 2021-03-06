# Johnny Five
## Introduction
---
This repo forms the submittal for the final project of ECEP 590 - Software Engineering for Embedded applications offered as part of the Professional Masters Program in Electrical Engineering at the University of Washington.

## Project Goals
---
This project will, using the robot state machine from the [week 8 homework](https://github.com/klavins/ECEP520/tree/master/week_7 "ECEP520 Week 8"), create a more realistic simulation of a security patrol robot.

This will be done using the [ELMA](http://klavinslab.org/elma/ "Elma Main Page") event loop and process manager that was developed during the ECEP 590 Winter class at the University of Washington and the code produced for the [week 8 homework](https://github.com/klavins/ECEP520/tree/master/week_7 "ECEP520 Week 8").

During this project I would like expand on the robot state machine adding more realism to the system.

## Installation
---
```bash
    git clone https://github.com/scotthem/ECEP590_Final.git
    cd ECEP590_Final
    docker run -v $PWD:/source -it klavins/elma:latest bash
    make
    make docs
```

## Execution
---
To run the robot, type
```bash
    server/bin/server &
    bin/robot
```

The robot is autonomous and will run without user interaction. However, should you wish to you can use the following keyboard commands to force state changes:

- **s**: Start
- **i**: Intruder Detected
- **p**: Proximity Warning
- **f**: Found Recharge StationS
- **r**: Reset
- **q**: Quit

Note that only Start (**s**) and Quit (**q**) are displayed on the user interface.

## Testing
---
To run tests, do
```bash
    bin/test
```
Note that during testing simulated time is used.

## Architecture
---
The aim of this project was to implement the state machine shown in the following diagram:

<img src="images/robot.png" width="620"></image>

The state machine and states were created inheriting for the ELMA State and StateMahcine classes. The state machine is driven by events. In order to provide autonomy I created a Battery class that inherits from the ELMA Process class simulated a battery to emit the events related to the battery (low battery, charged etc...). I then created a user interface where I was able to force events using the keyboard. 

After running into some issues regarding the multiple use of the Manager run() method during testing, at the recommendation of Prof. Klavins, implemented a RobotTester class which was another ELMA Process. This RobotTester class provides all of the stimulus not provided by the Battery.

Finally, I added a new State class, RobotPostState, that during the entry method wrote a specified message to a server. The server in turn saves this message along with a timestamp in a log.txt file.

## Results
---
This project did not get off to a particularly good start. Thanks to Amazon Web Services Lambda (and not using JSON in an intuitive way) the start of the project was substantially delayed. The lack of my knowledge of make files proved to be my second stumbling block, taking the better part of two days to get a skeleton code compiled successfully.

However, once these hurdles were overcome I made steady progress until I ran into the limitations of my knowledge of ELMA. Ultimately I was able to get the robot to behave autonomously (see below for example from the UI).

<img src="images/UI.png" width="240"></image>

I was also able (at the last minute) able to implement a server/client that logged interesting events. I had hoped to achieve much more, especially as the week went on and I felt more and more comfortable with ELMA and C++ in general.

## Acknowledgements
---
Thanks to Professor E Klavins (University of Washington) and the ECE 520 Teaching Assistants for patiently answering this noobs questions.

Also to Mike O'Dell for the moral support and mutual commiseration when the homework took way longer than expected!

## References
---
Primary references were the ELMA and related pages located at:

http://klavinslab.org/elma/ and 
http://klavinslab.org/elma_project/

as well as the online C++ references at:

https://en.cppreference.com/w/ and
http://www.cplusplus.com/

# Previous Materials

Below are archives of the project readme information (please forgive the over enthusiasm!)

---
I will create a simulation mode that implements a "simulated time" in order to speed up simulations and testing.

I will model the propulsion (motor) and power systems. This will including  changing in current requirements for different activities (evade , make noise should require more power for example) and a charging ciruit that mirrors a real battery charging cycle.

I will add a monitoring server and onboard client that will broadcast the status and location of the robot.

I will simulate the motion of the robot around its patrol patter and implement a method to change patrol paterns to random, to fixed patrol patterns as defined by the user.

A stretch goal for the maping, patrol routes and power systems implementation of this would be to add the effects of terain, and the addition of obstacles and intruders that would be detected when within a given distance. However, this may be beyond my abilities in the time allotted.

## Milestones

The following milestones will be used to report progress on the project, those not marked "**Stretch**" are considered to be the "complete" project.

[ ] Create directory structure, docker container for the project, complile using robot state machine example from [week 8 homework](https://github.com/klavins/ECEP520/tree/master/week_7 "ECEP520 Week 8").

[ ] Identify a suitable method for implementing a "simulated time" in order to reduce the overall simulation time during testing.

[ ] Simulate the on power systems including realistic battery loading based upon the activity and a charge cycle with a typical recharge curve.

[ ] Allow the patrol robot to report position and status to a remote server at regular intervals as well as during events of interest.

[ ] Create set patrol patterns that can be simulated.

[ ] Create a suitable document set for the code.

[ ] **Stretch** Extend robot and patrol code to react automatically to simulated obstacles and intruders.

[ ] **Stretch** Extend the patrol patterns and power systems to include different terrain.

[ ] **Stretch** Create a simulated user control panel that would allow, for instance, deactivation of alarms, cancelling of patrols, force battery charging, chage patrol route, etc...

[ ] **Huge Stretch** Implement GUI for the user control and status. (Lets face it I have no idea where to start with this so probably won't happen. But hey, a guy has to have aspirations)


## Status Update (3/17/19)

Well, didn't really get too far after spending 2+ days trying to get the AWS stuff working. I have some skeleton code up together and started working on some of the battery process. However ran into some issues with makefiles. Need to go away and do some research on these.


